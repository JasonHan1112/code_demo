#ifndef __LIST_H__
#define __LIST_H__

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

/**
 * list_head - a struct that inserted into a struct to  make a double link list
 * @next:    the pointer to the next head.
 * @prev:    the pointer to the previous head.
 *
 */
struct list_head {
	struct list_head *next, *prev;
};

/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)


/**
 * INIT_LIST_HEAD - initial a list head :next point to self, prev point to self
 * @list:         the pointer to a struct list_head
 *
 */
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}
/**
 * LIST_HEAD - initial a list head equels to INIT_LIST_HEAD
 * @name:    a struct list_head
 *
 */
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)


/**
 * __list_add - add a list head to a list
 * @new:      a pointer to list_head
 * @prev:     a pointer to the previous node of the new list head 
 * @next:     a pointer to the next node of the new one
 * 
 */
static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/**
 * list_add_next - add a list head to a list after a exist head
 * @new:          a pointer to list_head
 * @head:         a pointer to the previous node of the new one
 * 
 * tips: all the head must exist
 */
static inline void list_add_next(struct list_head *new,
			      struct list_head *head)
{
	__list_add(new, head, head->next);
}

/**
 * list_add_prev - add a list head to a list before a exist head
 * @new:          a pointer to list_head
 * @head:         a pointer to the next node of the new one
 * 
 * tips: all the head must exist
 */
static inline void list_add_prev(struct list_head *new,
			      struct list_head *head)
{
	__list_add(new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 * 
 * delete nodes between prev & next
 */
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

/*
 * delete next node.
 * 
 * tips:all the head must exist
 */
static inline void list_del_next(struct list_head *head)
{
	__list_del(head, head->next->next);
}

/*
 * delete prev node.
 * 
 * tips:all the head must exist
 */
static inline void list_del_prev(struct list_head *head)
{
	__list_del(head->prev->prev, head);
}



#endif