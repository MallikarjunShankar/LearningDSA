# C Programming Roadmap --- Memory, Structures & Algorithms

*(Revised: fewer, larger, project-style problems. Each one grows out of
the previous. No data structure names are used unless unavoidable ---
the scenario should make the structure obvious without stating it.)*

## Part A --- Pointers, Memory, and Building Blocks

### 1. Mapping a Variable's Life in Memory

Write a program that declares several variables, prints their values and
addresses, then creates pointers to each and modifies the variables
indirectly through those pointers. Extend the same program with a
pointer to a pointer, and confirm that changing a value through the
outermost pointer is visible at every level. The program must not use
any array --- only individual variables and pointers to them.

### 2. A Block of Memory Whose Size Isn't Known in Advance

Write a program that asks the user how many numbers they want to store,
without ever using a fixed-size array. Allocate exactly enough memory
for that many numbers, fill it, and print it. Then extend the same
program so it can grow the block later if the user wants to add more
numbers, and shrink it if the user wants to remove some --- without
losing any of the values already stored. No fixed-size array is allowed
anywhere in this program.

### 3. A Grid Built Entirely at Runtime

Extend your memory-allocation skills to build a two-dimensional grid of
numbers where neither the number of rows nor the number of columns is
known until the program runs, and no fixed-size array is used anywhere.
Fill the grid from user input and print it. Then extend the same program
to accept two such grids and compute their product, rejecting the
operation cleanly if their sizes are incompatible. Every block of memory
you allocate must be released before the program ends, and none should
be released more than once.

### 4. Records That Only Know Each Other's Address

Design a record that stores some data and the address of another record
of the same kind. Write a program that creates several such records one
at a time, entirely through dynamic allocation, and links each one to
the next as it is created. The program should be able to start from the
very first record and, using only the stored addresses, reach every
other record that was created --- without keeping a separate list or
array of their addresses anywhere.

## Part B --- Searching and Sorting

### 5. A Growing Collection with a Lookup Feature

Write a program that stores a set of numbers, entered one at a time
until the user chooses to stop, using memory that grows to fit however
many numbers are entered. Add a feature that lets the user look for a
value by checking the numbers one at a time from the start, reporting
where it was found (or that it wasn't). Then add a second lookup mode
that only works correctly if the numbers are kept in increasing order,
and that narrows down where the value could be instead of checking every
number. Let the user compare how many checks each mode takes to find the
same value.

### 6. Putting a Growing Collection in Order

Extend the same collection from the previous problem with two
independent ways of rearranging its contents into increasing order ---
one that repeatedly looks at neighboring pairs and fixes any that are
out of order, and one that grows a correctly-ordered section one number
at a time by placing each new number where it belongs. After each pass
or placement, print the current state of the collection so the process
is visible. Test both methods on data that is already sorted, data that
is in reverse order, and data containing repeated values.

## Part C --- A Chain of Records (Project 1)

### 7. Starting the Chain

Design a record that stores a value and the address of the next record
of the same kind. Write a program that lets the user keep adding new
records to the end of a growing chain, one at a time, for as long as
they want --- the total number of records is never fixed in advance. The
program must remember only the address of the very first record; every
other record must be reachable by following addresses from there. Add
the ability to print every value in the chain in the order they were
added, and to add new records at the very front of the chain as well as
the end.

### 8. Placing a Record Anywhere in the Chain

Extend your chain program so a new record can be placed immediately
after any existing record the user chooses, not just at the front or
back. After the operation, every record that existed before must still
be reachable, and the newly added record must be fully connected into
the chain. Consider what should happen if the user asks to insert after
a record that doesn't exist, or asks to insert into an empty chain.

### 9. Removing Records Without Breaking the Chain

Extend the same program so any single record --- the first one, the last
one, or one somewhere in the middle --- can be removed on request, while
every remaining record stays reachable from the first one and the memory
used by the removed record is properly released. The program should
behave sensibly if the user tries to remove from an empty chain, or asks
to remove a record that isn't there.

### 10. Looking Things Up and Changing Them

Extend the program with the ability to look for a specific value
anywhere in the chain and report whether --- and where --- it was found,
and with the ability to change the stored value of a record once it has
been located, without disturbing how the chain is connected. Also add a
way to report, at any moment, how many records currently exist in the
chain, based only on what's actually reachable rather than a count kept
separately.

### 11. Turning the Chain Around

Extend the program with an operation that reverses the direction of the
entire chain --- so that following addresses from what used to be the
last record now leads all the way back to what used to be the first ---
without creating any new records and without using a second chain as
temporary storage. Confirm the reversal is correct by printing the chain
both before and after.

### 12. Finding the Center and Detecting a Broken Chain

Extend the program with a feature that reports the record sitting in the
middle of the chain, arrived at in a single pass through the chain
rather than by first counting everything and then walking again.
Separately, add a diagnostic feature that can detect whether a bug has
caused some record's address to accidentally point back to an earlier
record instead of forward, turning the chain into a loop with no true
end. Deliberately create such a broken chain to test the diagnostic,
then test it again on a normal, well-formed chain.

### 13. Combining Two Chains

Given two chains that are each already arranged in increasing order and
were built using your existing program, write an operation that merges
them into a single chain that is still in increasing order, reusing the
existing records rather than creating new ones. Separately, write an
operation that produces a completely independent duplicate of a chain,
such that changing a record in the duplicate has no effect whatsoever on
the original.

### 14. Capstone --- Contact Book

Using everything from this section, build a contact book that keeps
contacts in a chain sorted by name, and stays running in a loop
accepting commands until the user chooses to exit. It must support
adding a new contact in its correct sorted position, removing a contact
by name, updating a contact's phone number, searching by name, listing
everyone in order, and reporting the total number of contacts --- all
without ever using a fixed-size array, and with memory usage that grows
only as contacts are actually added.

## Part D --- Records That Know Their Neighbor in Both Directions (Project 2)

### 15. Building a Two-Way Chain

Design a record that stores a value along with the addresses of both the
record before it and the record after it. Write a program that lets the
user build a growing chain of such records by adding to the front or the
back, and that can print the entire chain both starting from the front
and going forward, and starting from the back and going backward,
confirming both directions agree on the same sequence of values.

### 16. Inserting and Removing in a Two-Way Chain

Extend the two-way chain with the ability to insert a new record
immediately before or after any chosen existing record, and to remove
any chosen record --- the front one, the back one, or one in the middle
--- making sure that both directions of every connection near the change
are correctly updated. Handle a chain that becomes empty after a
removal, and a removal request for a record that isn't there.

### 17. Searching, Updating, and Reversing the Two-Way Chain

Extend the program with the ability to search for a value, update a
record once found, count how many records exist, and reverse the entire
chain in place so that following it forward now produces what used to be
the backward order. Verify every operation works correctly regardless of
which direction you choose to traverse.

### 18. Capstone --- Browser History

Using the two-way chain, build a program that simulates a browser's page
history: visiting a new page adds it after the current position and
discards any "forward" pages that existed beyond it, a "back" command
moves to the previous page without deleting anything, and a "forward"
command moves ahead again if possible. The program should run in a loop
accepting visit/back/forward/exit commands, and should clean up all
memory correctly when the session ends.

## Part E --- A Chain With No Beginning or End (Project 3)

### 19. Closing the Chain Into a Loop

Take your single-direction record design and build a chain where the
last record's address field points back to the very first record instead
of to nothing. Write a way to print every record exactly once despite
there being no natural stopping point, and add the ability to insert and
remove records at the front, back, and an arbitrary position while
making sure the loop-closing connection is always correctly maintained
afterward.

### 20. A Two-Way Chain With No Beginning or End

Combine the closed-loop idea with the two-way record design, so that
every record has working connections in both directions and there is no
record that counts as a true head or tail --- moving forward or backward
from any record eventually revisits every other record. Support
insertion and removal at any chosen position, keeping every connection
consistent.

### 21. Capstone --- Elimination Game

Using a closed loop of records representing people standing in a circle,
simulate a process where, starting from a chosen person, every k-th
person is removed from the circle in turn until only one person remains.
The starting position, the group size, and the elimination interval
should all be configurable by the user at runtime. Report the order in
which people are eliminated and identify who is left standing at the
end.

## Part F --- Restricted-Access Collections (built twice, on purpose)

### 22. A Collection That Only Grows and Shrinks From One End

Build a collection, backed by a single block of memory whose size is
fixed when the program starts, that only allows adding a new item to one
particular end and only allows removing the most recently added item ---
no other position may be touched. Support checking what the most recent
item is without removing it, and correctly detect and report when an
addition is attempted with no room left, or a removal is attempted on an
empty collection. Then, without changing the collection's external
behavior, rebuild the exact same restriction using individually
allocated, linked records instead of a block of memory, so the
collection's size is no longer fixed at all.

### 23. A Collection That Adds at One End and Removes from the Other

Build a collection, again backed by a single fixed-size block of memory,
where new items are only ever added at one end and only ever removed
from the opposite end, and reused space is correctly recognized so the
collection doesn't falsely report itself as full after a mix of
additions and removals. Then rebuild the same restriction using
individually allocated, linked records, removing the size limitation
entirely.

### 24. Capstone --- Undo/Redo for a Simple Text Editor

Build a program that simulates a text editor holding a single line of
text, where every edit command (insert a character, delete a character)
is remembered in a way that lets the user undo the most recent change,
and redo a change that was just undone --- but only until a new edit is
made, at which point redoing should no longer be possible. The program
should run in a loop accepting edit/undo/redo/exit commands and print
the current text after every command.

## Part G --- Matrices That Are Mostly Empty

### 25. Storing Only What Matters

Write a program that takes a large grid of numbers, most of which are
zero, and converts it into a compact form that records only the non-zero
values along with their positions --- nothing else. Write a function
that can reconstruct and print the full original grid from this compact
form, treating every unrecorded position as zero. Report what fraction
of the original grid's memory the compact form actually needed.

### 26. The Same Idea, Built as a Chain

Rebuild the previous representation using individually allocated, linked
records instead of a single compact block, where each record stores one
non-zero value and its position, kept in order by position as records
are added. Write a function that reconstructs and prints the full grid
from this chain, and confirm it produces the same result as the
array-based version on the same input.

### 27. Combining Two Sparse Grids

Given two large, mostly-empty grids of the same dimensions, each already
stored in your compact array-based form, produce their sum in the same
compact form --- containing only the positions where the result is
actually non-zero, even if both inputs had a non-zero value there. Then
solve the same problem again using the chain-based representation from
the previous question, traversing both chains together by position
rather than converting back to a full grid.

### 28. Capstone --- Sparse Matrix Calculator

Combine everything from this section into a single program that reads
two large, mostly-empty grids from user input, stores each using
whichever compact representation you prefer, supports computing their
sum and their product, and prints the results by reconstructing the full
grid only at the very end --- never storing a full grid at any
intermediate step.

## Final Capstone

### 29. A Simulated Memory Manager

Simulate, on top of one single large block of memory that you allocate
once at the start of the program, your own miniature allocator: a
request for a chunk of a given size should be satisfied by finding and
marking off a free region within that block, and a release should return
the region to the pool of free space, merging it with adjacent free
regions where possible. The program should run in a loop accepting
allocate/release/status commands, print a visual map of which regions
are currently free or in use, and correctly refuse a request that cannot
be satisfied by any available free region, however the free space is
currently split up.
