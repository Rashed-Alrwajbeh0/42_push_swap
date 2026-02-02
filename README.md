*This activity has been created as part of the 42 curriculum by klafi, ralrawaj*
# Description
push_swap is a program in C which calculates and displays on the standard output the smallest program, made of Push swap language operations, that sorts the integers received as arguments.


## Rules

- You have two stacks named a and b.
- At the beginning:
  + The stack a contains a random amount of negative and/or positive numbers without
any duplicate.
  + The stack b is empty

- The goal is to sort in ascending order numbers into stack a. The following operations should be used exclusively to order the stack such that the smallest number is at the top:

  - **sa (swap a):** 
    - Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.

  - **sb (swap b):**
    * Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.

  - **ss :**
    * sa and sb at the same time.

  - **pa (push a):**
    * Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

  - **pb (push b):**
    * Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

  - **ra (rotate a):**
    * Shift up all elements of stack a by one. The first element becomes the last one.

  - **rb (rotate b):**
    * Shift up all elements of stack b by one. The first element becomes the last one.

  - **rr :**
    * ra and rb at the same time.

  - **rra (reverse rotate a):**
    * Shift down all elements of stack a by one. The last element becomes the first one.

  - **rrb (reverse rotate b):**
    * Shift down all elements of stack b by one. The last element becomes the first one.
  - **rrr :**
    * rra and rrb at the same time.

## Complexity model and operation constraints
- C algorithms analyze the input and generate the appropriate sequence of the operations:
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.
- The output of the strategy is the sequence of these operations that sorts the stack.
- When the program states a complexity class, it must reflect the cost measured in number of Push_swap operations generated, not the theoretical complexity of a classical array-based algorithm.

## Disorder metric

Disorder is a number between 0 and 1 that tells how far your initial stack a is
from being sorted.

If the numbers are already in the right order, the disorder is 0. If they are in the worst possible order, the disorder is 1. Anything in between means the stack is partly sorted, but still messy.

To calculate it, you can think of looking at all the possible pairs of numbers in the stack.

Each time a bigger number appears before a smaller one, that pair counts as a mistake.

The more mistakes you have, the closer the disorder is to 1.
# Instructions
Makefile creates a program named push_swap that takes as arguments:
- The stack a formatted as a list of integers (the first argument is the top of the
stack).
- An optional strategy selector:
  + --simple Forces the use of your O(n2) algorithm.
  + --medium Forces the use of your O(n√n) algorithm.
  + --complex Forces the use of your O(n log n) algorithm.
  + --adaptive Forces the use of your adaptive algorithm based on disorder. This is the default behavior if no selector is given.
- To create the executable file just type 
```bash
make 
```
- All of the conventional Makefile rules do exist like (all, re, clean, fclean).
- The strategy selection must work for all valid inputs. Any selector flag should work
regardless of input size or disorder.
- If no parameters are specified, the program must not display anything and give the prompt
back.
- In case of error, it must display "Error" followed by a \n on the standard error. Errors
include, for example: arguments that are not integers, integers outside the valid range, or
duplicate values.

- The benchmark mode (--bench) must display, after sorting:
  + The computed disorder (% with two decimals).
  + The name of the strategy used and its theoretical complexity class.
  + The total number of operations.
  + The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
The benchmark output must be sent to stderr and only appear when the flag is present.
# Used startegies and algorithms
1. Simple algorithm (O(n<sup>2</sup>))
    - Selection Sort 
2. Medium algorithm (O(n√n)):
   - Chunk Sort with sliding window technique.
3. Complex algorithm (O(n log n)):
   - Radix Sort, where every number is converted to an index, and then converted to binary.
4. Custom adaptive algorithm:
   - An adaptive strategy that selects
different internal methods depending on the measured disorder. The program respects the following complexity targets per regime (in the Push_swap
operation model):
     + Low disorder: if disorder < 0.2, the chosen method must run in O(n<sup>2</sup>) time.
     + Medium disorder: if 0.2 ≤ disorder < 0.5, the chosen method must run in O(n√n)
time.
     + High disorder: if disorder ≥ 0.5, the chosen method must run in O(n log n) time.
# Resources
- Peer-learning
- Youtube
- AI; it was used for mere explanation of some of the required subject, **No code was written by the AI**.

# Examples
```bash
./push_swap --simple 5 4 3 2 1
```
The result would be:
```
rra
pb
rra
pb
sa
rra
pa
pa
```
<hr>

```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 1> operations.txt 2> bench.txt; cat bench.txt
```
The result would be:
```
[bench] disorder: 47.74%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 5054
[bench] sa:  0  sb:  0  ss: 0  pa: 500  pb: 500
[bench] ra:  1327  rb:  1397  rr: 0  rra: 0  rrb: 1330  rrr: 0
```

<hr>

```bash
./push_swap --adaptive 0 one 2 3
```
The result would be:
```
Error
```

<hr>

```bash
./push_swap --simple 3 2 3
```
The result would be:
```
Error
```
# Contributions
## klafi
- Designed the Doubly Circular Linked List data structre used to build the stacks.
- Made the bench mode.
- Created an initial working prototype of the selection sort algorithm which was modified later by *ralrawaj*.
- Coded all stack operations (ra, sa, etc.).
## ralrawaj
- Created the Chunk and Radix Algorithms and doubled Selection Sort Algorithm's performance.
- Error handling.