/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __QUEUE_H
#define __QUEUE_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef struct queue {
    struct queue* next;
    struct queue* prev;
} queue;

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
#define _QUEUE_INIT(head)                       (head)->next = ((head)->prev = head)
#define _QUEUE_FIRST(head)                      ((head)->next)
#define _QUEUE_NEXT(element)                    ((element)->next)
#define _QUEUE_LAST(head)                       ((head)->prev)
#define _QUEUE_EMPTY(head)                      ((head)->next == (head))

#define _QUEUE_MOVE(newhead, oldhead)                                                               \
                                                if ( (oldhead)->next == (oldhead) )                 \
                                                {                                                   \
		                                            (newhead)->next = (newhead)->prev = (newhead);  \
	                                            }                                                   \
	                                            else                                                \
                                                {                                                   \
		                                            (newhead)->next = (oldhead)->next;              \
		                                            (newhead)->prev = (oldhead)->prev;              \
		                                            (newhead)->next->prev = (newhead);              \
		                                            (newhead)->prev->next = (newhead);              \
	                                            }                                                   \
	                                            (oldhead)->next = (oldhead)->prev = (oldhead)

#define _ENQUEUE_TAIL(listhead, element)        enqueue(element, (listhead)->prev)
#define _ENQUEUE_HEAD(listhead, element)        enqueue(element, listhead)
#define _ENQUEUE_AFTER(predecessor, element)    enqueue(element, predecessor)

#define _QUEUE_FOR_EACH(listhead, element, tmp) for ((element) = QUEUE_FIRST(listhead);             \
		                                            (tmp) = QUEUE_NEXT(element),                    \
		                                            (element) != (listhead);                        \
		                                            (element) = (tmp))
/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/


#endif /* XXX */
