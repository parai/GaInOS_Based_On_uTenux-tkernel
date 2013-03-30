/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2008 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.00
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2008/02/25.
 *
 *----------------------------------------------------------------------
 */

/*
 *	@(#)queue.h (sys)
 *
 *	Queuing operation
 */

#ifndef	__SYS_QUEUE_H__
#define __SYS_QUEUE_H__

#include <basic.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Double-link queue (ring)
 */
typedef struct queue {
	struct queue	*next;
	struct queue	*prev;
} QUEUE;
/*
 * Queue initialization 
 */
#ifdef __GNUC__ 
Inline void QueInit( QUEUE *que )
{
	que->next = (struct queue *)que;
	que->prev = (struct queue *)que;
}
#else
#define QueInit(__que)                              \
do                                                  \
{                                                   \
     (__que)->next = (struct queue *)(__que);       \
     (__que)->prev = (struct queue *)(__que);       \
}while(0);
#endif
/*
 * TRUE if the queue is empty 
 */
#ifdef __GNUC__ 
Inline BOOL isQueEmpty( QUEUE *que )
{
	return ( que->next == que )? TRUE: FALSE;
}
#else
#define isQueEmpty(__que)   ((BOOL)(( (__que)->next == (__que) )? TRUE: FALSE))
#endif
/*
 * Insert in queue 
 *	Inserts entry directly prior to que 
 */
#ifdef __GNUC__  
Inline void QueInsert( QUEUE *entry, QUEUE *que )
{
	entry->prev = (struct queue*) que->prev;
	entry->next = que;
	que->prev->next = entry;
	que->prev = entry;
}
#else
#define QueInsert(__entry,__que)                                        \
do                                                                      \
{                                                                       \
	(__entry)->prev = (struct queue*) (__que)->prev;                    \
	(__entry)->next = (__que);                                          \
	(__que)->prev->next = (__entry);                                    \
	(__que)->prev = (__entry);                                          \
}while(0)	
#endif

/*
 * Delete from queue 
 *	Deletes entry from queue 
 *	No action is performed if entry is empty. 
 */
#ifdef __GNUC__ 
Inline void QueRemove( QUEUE *entry )
{
	if ( entry->next != entry ) {
		entry->prev->next = (struct queue*) entry->next;
		entry->next->prev = (struct queue*) entry->prev;
	}
}
#else
#define QueRemove(__entry)                                          \
do                                                                  \
{                                                                   \
     	if ( (__entry)->next != (__entry) ) {                       \
		(__entry)->prev->next = (struct queue*) (__entry)->next;    \
		(__entry)->next->prev = (struct queue*) (__entry)->prev;    \
	}                                                               \
}while(0)
#endif
/*
 * Remove top entry 
 *	Deletes the entry directly after que from the queue,
 *	and returns the deleted entry.
 *	Returns NULL if que is empty.
 */
#ifdef __GNUC__
Inline QUEUE* QueRemoveNext( QUEUE *que )
{
	QUEUE	*entry;

	if ( que->next == que ) {
		return NULL;
	}

	entry = que->next;
	que->next = (struct queue*)entry->next;
	entry->next->prev = que;

	return entry;
}
#else
IMPORT QUEUE* QueRemoveNext( QUEUE *que );
#endif
#ifdef __cplusplus
}
#endif
#endif /* __SYS_QUEUE_H__ */
