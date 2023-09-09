# Priority-Queue-Implementation
A priority queue implementation that I wrote for a school project.

/**
* General description:  priority queue which stores pairs
*   <id, priority>.  Top of queue is determined by priority
*   (min or max depending on configuration).
*
*   There can be only one (or zero) entry for a particular id.
*
*   Capacity is fixed on creation.
*
*   IDs are integers in the range [0..N-1] where N is the capacity
*   of the priority queue set on creation.  Any values outside this
*   range are not valid IDs.


It contains the following functions:
pq_create, pq_free, pq_insert, change_priority, pq_remove_by_id, pq_get_priority, pq_delete_top, pq_capacity, pq_size, pq_contains, percolate_up, percolate_down
  
This project taught me how to efficiently code under runtime restrictions. It made me consider how I could achieve the lowest possible runtime before I started coding. 

I have also included a test file that tests these functions under a small set of inputs. 
