/*
    stack -> LIFO (Last in First out) discipline
    Queue -> FIFO (First in First out) discipline 

    Queue ADT
    Data:
    In order to create a Queue, we need two pointers, one pointing to the insertion end, to gain knowledge about the address where the new element will be inserted to. And the other pointer pointing to the deletion end, which holds the address of the element which will be deleted first. Along with that, we need the storage to hold the element itself.
    1. storage
    2. Insertion End
    3. Deletion End
    Methods:
    Here are some of the basic methods we would want to have in queues:
    1. enqueue(): to insert an element in a queue.
    2. dequeue(): to remove an element from the queue
    3. firstVal(): to return the value which is at the first position.
    4. lastVal(): to return the value which is at the last position.
    5. peek(position): to return the element at some specific position.
    6. isEmpty()/isFull(): to determine whether the queue is empty Or full, which helps us carry out efficient enqueue and dequeue operations.
    Queue can be implemented in various ways:
    1. using Array
    2. using linked list
    3. using stack
*/