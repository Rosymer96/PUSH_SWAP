*This project has been created as part of the 42 curriculum by albben-a, rosvela.*

# push_swap

## Description

**push_swap** is an algorithmic project from the 42 curriculum whose goal is to sort a list of integers using a restricted set of stack operations.

The program receives a sequence of integers as input and must output the **shortest possible sequence of operations** needed to sort them in ascending order.

The challenge lies in sorting numbers using only **two stacks (`a` and `b`) and a limited set of operations**. Instead of directly sorting the numbers, the program generates a sequence of valid push_swap instructions that will produce the sorted stack.

To achieve good performance, several sorting strategies with different algorithmic complexities are implemented, and the program can select the most appropriate one depending on the input.

---

# Instructions

## Compilation

Compile the project using the Makefile:

```bash
make
```

This will generate the executable:

```
push_swap
```

The project is compiled using the following flags:

```
-Wall -Wextra -Werror
```

To compile the bonus program (`checker`):

```bash
make bonus
```

---

## Usage

The program receives a list of integers representing **stack a**.

Example:

```bash
./push_swap 2 1 3 6 5 8
```

Output:

```
ra
pb
rra
pb
...
```

Each line represents an operation applied to the stacks.

---

## Verifying with checker

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Expected output:

```
OK
```

---

# Allowed Operations

| Operation | Description |
|--------|-------------|
| sa | swap the first two elements of stack a |
| sb | swap the first two elements of stack b |
| ss | sa and sb simultaneously |
| pa | push the first element of b onto a |
| pb | push the first element of a onto b |
| ra | rotate stack a |
| rb | rotate stack b |
| rr | ra and rb simultaneously |
| rra | reverse rotate stack a |
| rrb | reverse rotate stack b |
| rrr | rra and rrb simultaneously |

---

# Algorithm Strategies

The project implements several algorithms with different complexity classes.

| Strategy | Complexity | Description |
|--------|--------|-------------|
| Simple | O(n²) | Minimum extraction algorithm |
| Medium | O(n√n) | K-sort using chunk partitioning |
| Complex | O(n log n) | Greedy insertion based on LIS |
| Adaptive | depends | Selects the best algorithm based on disorder |

---

# Disorder Index

Before choosing a strategy, the program computes a **disorder index** that measures how far the input is from being sorted.

The index is calculated by counting all pairs of numbers where the order is incorrect.

If `a[i] > a[j]` for `i < j`, it counts as a mistake.

```
disorder = mistakes / total_pairs
```

The result is a value between **0 and 1**:

| Value | Meaning |
|------|------|
| 0 | Already sorted |
| close to 0 | Almost sorted |
| around 0.5 | Partially disordered |
| close to 1 | Completely random |

This metric allows the program to select the most efficient sorting strategy.

---

# Algorithms Implementation

## Simple Algorithm — Minimum Extraction (O(n²))

The simple strategy repeatedly extracts the smallest element.

Steps:

1. Find the minimum value in stack `a`
2. Rotate `a` until it reaches the top
3. Push it to stack `b`
4. Repeat until all elements are moved
5. Push everything back to `a`

This approach is easy to implement but inefficient for large inputs.

---

## Medium Algorithm — K-Sort (O(n√n))

The medium strategy uses **K-sort**, which distributes elements into ranges.

The chunk constant is defined as:

```
k = n / 20 + 7
```

(or approximately √n)

Steps:

1. Push elements from `a` to `b` depending on their rank range
2. Elements are grouped into ranges inside `b`
3. The largest elements are pushed back to `a` in sorted order

This reduces the number of rotations compared to simpler methods.

---

## Complex Algorithm — Greedy with LIS (O(n log n))

The complex strategy is based on the **Longest Increasing Subsequence (LIS)**.

Steps:

1. Compute the LIS of the input
2. Keep LIS elements in stack `a`
3. Push the remaining elements to stack `b`
4. Reinsert elements from `b` into the optimal position in `a`

The reinsertion uses a **greedy cost calculation** to minimize operations.

This algorithm performs significantly better for large inputs.

---

## Adaptive Algorithm

The adaptive strategy selects which algorithm to use depending on:

- **input size**
- **disorder index**

Example decision logic:

| Disorder | Strategy |
|--------|--------|
| < 0.2 | Near-sorted strategy |
| 0.2 – 0.5 | Medium algorithm |
| ≥ 0.5 | Complex algorithm |

This allows the program to adapt to different input distributions and maintain good performance.

---

# Program Flags

The program supports several flags to force a specific algorithm.

| Flag | Description |
|-----|-------------|
| `--simple` | Forces the O(n²) algorithm |
| `--medium` | Forces the O(n√n) algorithm |
| `--complex` | Forces the O(n log n) algorithm |
| `--adaptive` | Automatic selection (default) |
| `--bench` | Displays benchmark statistics |

---

# Benchmark Mode

When the `--bench` flag is used, the program outputs additional information to **stderr**:

- disorder index
- selected algorithm
- theoretical complexity
- total number of operations
- count of each operation

Example:

```
[bench] disorder: 0.40
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0 rrb: 5 rrr: 5
```

---

# Bonus — Checker Program

The bonus part of the project includes an additional program called **checker**.

The checker verifies whether the sequence of operations generated by `push_swap` correctly sorts the stack.

It receives the initial stack as arguments and reads operations from **standard input**.

If the final result is valid:

```
OK
```

Otherwise:

```
KO
```

If an invalid instruction is detected:

```
Error
```

Example:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Expected output:

```
OK
```

---

# Team & Project Management

## Roles

### albben-a

Responsible for:

- algorithm strategy selection
- adaptive algorithm
- medium algorithm implementation
- bonus implementation (checker)

### rosvela

Responsible for:

- input parsing and validation
- simple algorithm implementation
- complex algorithm implementation
- benchmark mode

### Shared Responsibilities

Both contributors worked on:

- Git repository management
- merges and integration
- debugging and testing
- code review
- Norminette compliance

---

## Planning & Evolution

### Anticipated Planning

At the beginning of the project, we divided the work according to the main components:

- input parsing
- algorithm design
- benchmarking and testing

Each member focused on different algorithms while maintaining a shared understanding of the overall architecture.

### Evolution

During development we frequently reviewed each other's work and adjusted implementations to improve consistency and performance.

---

## Retrospective

### What worked well

Dividing the work by algorithmic strategies allowed both contributors to work in parallel while keeping a coherent architecture.

Regular testing and benchmarking helped us validate the correctness and efficiency of each algorithm.

### What could be improved

Integration between different algorithm strategies required additional adjustments.  
Defining stricter interfaces earlier could simplify integration in future projects.

---

# Resources

### Documentation

- 42 push_swap subject
- Algorithm complexity references
- Stack data structure documentation
- Linux manual pages

---

### Use of Artificial Intelligence

Artificial Intelligence was used to:

- design additional test cases
- review algorithm complexity reasoning
- assist with documentation writing

AI was **not used to generate the core implementation of the algorithms**. All code was written, reviewed, and tested by the project authors to ensure full understanding of the implementation and compliance with the learning objectives of the 42 curriculum.