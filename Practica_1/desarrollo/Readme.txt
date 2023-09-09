


Name: Rohit Nambiar

Answer each of the questions below to the best of your
ability.  If you didn't complete the part of the assignment
relevant to a particular question, just say so.
-----------------------------------------------

Briefly describe how you modified the basic heap organization (as
presented in class ans in section 5.9 of Aho/Ullman) to support
the specifications for this assignment -- in particular how was
the idea of an ID incorporated.  

I had to make two structs with one being the node struct and the
other being the priority queue. In the priority queue struct, I 
had to make an array of nodes to store the ID and Priority. The
priority queue also contains an integer array that stores the 
location of each ID in the node array in ID index.

-----------------------------------------------
How did your modifications above affect your implementation of
pq_insert (vs. the standard implementation of insert)?

By adding an array of nodes in my priority queue, I could insert
a new element in my queue in constant time. All though, moving
the new element to its sorted place would take log n runtime.



-----------------------------------------------
How did your modifications above affect your implementation of
pq_delete_top (vs. the standard implementation of delete_max)?

Accessing the first node in the array of nodes can be done in constant
time, however sorting the remaining nodes will take log n runtime.



-----------------------------------------------
Explain how your implementation of bst_change_priority worked,
why it is correct and why it achieves the runtime requirement.

The integer array (posArray) gives me the position of the ID
that needs to be modified in constant time. Once the priority is
changed, I compare the new priority with the old one and move it up
or down, depending on whether the queue is a min heap or a max heap.
This takes log n runtime.



-----------------------------------------------
How did your implementation enable O(1) runtime for pq_get_priority?

Using the integer array (posArray), I can find the node in the node array
in constant time if I know the ID. Which then allows me to access the priority
of that node. 





