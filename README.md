# Advanced Data Structures and Algorithms Lab
### Aditya University — Department of AI & ML

> 9 lab programs covering hashing, trees, heaps, sorting, greedy, dynamic programming, backtracking, and branch & bound — implemented in C.

--- GitHub repo

## https://github.com/anjiduda77-afk

```
advanced-data-structures-and-algorithms/
├── hash_collision.c
├── avl_tree.c
├── heap.c
├── merge_sort.c
├── dijkstra.c
├── knapsack_dp.c
├── floyd_warshall.c
├── nqueens.c
├── tsp_branch_bound.c
└── README.md
```

---

## 📋 Table of Contents

| # | Experiment | File | Technique |
|---|-----------|------|-----------|
| 1 | [Hash Collision Resolution](#1-hash-collision-resolution) | [hash_collision.c](./hash_collision.c) | Hashing |
| 2 | [AVL Tree Operations](#2-avl-tree-operations) | [avl_tree.c](./avl_tree.c) | Self-Balancing BST |
| 3 | [Heap Operations](#3-heap-operations-max--min) | [heap.c](./heap.c) | Heap Data Structure |
| 4 | [Merge Sort](#4-merge-sort) | [merge_sort.c](./merge_sort.c) | Divide & Conquer |
| 5 | [Dijkstra's Algorithm](#5-dijkstras-algorithm--single-source-shortest-path) | [dijkstra.c](./dijkstra.c) | Greedy |
| 6 | [0/1 Knapsack](#6-01-knapsack-problem) | [knapsack_dp.c](./knapsack_dp.c) | Dynamic Programming |
| 7 | [Floyd-Warshall](#7-floyd-warshall--all-pairs-shortest-path) | [floyd_warshall.c](./floyd_warshall.c) | Dynamic Programming |
| 8 | [N-Queens Problem](#8-n-queens-problem) | [nqueens.c](./nqueens.c) | Backtracking |
| 9 | [Travelling Salesperson](#9-travelling-salesperson-problem-tsp) | [tsp_branch_bound.c](./tsp_branch_bound.c) | Branch & Bound |

---

## Experiments

---

### 1. Hash Collision Resolution

**File:** [hash_collision.c](./hash_collision.c)

**Aim:** Demonstrate four strategies to handle key collisions in a hash table of size 10.

**Techniques Covered:**

- **Linear Probing** — On collision, probe the next slot sequentially until an empty slot is found.
- **Quadratic Probing** — On collision, probe slots at quadratic intervals (i², 2i², 3i²...) to reduce clustering.
- **Double Hashing** — On collision, use a second hash function `7 - (key % 7)` to compute the step size, making probe sequences unique per key.
- **Separate Chaining** — Each slot holds a linked list; colliding keys are simply appended to the list at that index.

**Pseudocode — Linear Probing Insert:**
```
function insertLinear(key):
    index = key mod SIZE
    i = 0
    while table[index] is occupied AND i < SIZE:
        index = (index + 1) mod SIZE
        i++
    if i == SIZE → print "Table full"
    else → table[index] = key
```

**Key Concept:** All four methods avoid overwriting existing keys. Chaining never runs out of space (dynamic memory); open addressing methods (linear, quadratic, double hashing) are limited to table size.

---

### 2. AVL Tree Operations

**File:** [avl_tree.c](./avl_tree.c)

**Aim:** Implement a self-balancing Binary Search Tree that maintains height balance after every insert and delete.

**Operations:** Insert, Delete, Search, Inorder Traversal

**Balance Factor** = height(left subtree) − height(right subtree)
A node is balanced if its balance factor is −1, 0, or +1.

**Four Rotation Cases:**

| Case | Condition | Fix |
|------|-----------|-----|
| LL | balance > 1, new key < left child | Right rotate |
| RR | balance < -1, new key > right child | Left rotate |
| LR | balance > 1, new key > left child | Left rotate left child → Right rotate |
| RL | balance < -1, new key < right child | Right rotate right child → Left rotate |

**Pseudocode — Insert:**
```
function insert(node, key):
    if node is NULL → return newNode(key)
    if key < node.key → node.left = insert(node.left, key)
    if key > node.key → node.right = insert(node.right, key)

    update node.height
    balance = height(left) - height(right)

    if LL case → rightRotate(node)
    if RR case → leftRotate(node)
    if LR case → leftRotate(node.left), rightRotate(node)
    if RL case → rightRotate(node.right), leftRotate(node)

    return node
```

**Key Concept:** AVL trees guarantee O(log n) search, insert, and delete by keeping height balanced at all times.

---

### 3. Heap Operations (Max & Min)

**File:** [heap.c](./heap.c)

**Aim:** Implement both Max Heap and Min Heap using an array, supporting insert and delete-root operations.

**Heap Property:**
- **Max Heap:** Parent ≥ Children. Root is always the largest element.
- **Min Heap:** Parent ≤ Children. Root is always the smallest element.

**Pseudocode — Insert (Min Heap):**
```
function insert(value):
    place value at end of array (size++)
    i = size
    while i > 1 AND value < parent(i):
        swap value with parent
        i = parent index
```

**Pseudocode — Delete Root:**
```
function deleteRoot():
    save last element as 'last'
    remove last element (size--)
    place 'last' at root
    heapify down:
        while child exists:
            pick smaller child (min heap) or larger child (max heap)
            if last fits here → break
            else swap down and continue
```

**Key Concept:** Heaps are complete binary trees stored as arrays. Parent of index i is at i/2; children are at 2i and 2i+1.

---

### 4. Merge Sort

**File:** [merge_sort.c](./merge_sort.c)

**Aim:** Sort an array using the Divide and Conquer strategy.

**Approach:**
1. Divide the array into two halves at the midpoint.
2. Recursively sort each half.
3. Merge the two sorted halves back into one sorted array.

**Pseudocode:**
```
function mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) / 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid+1, right)
        merge(arr, left, mid, right)

function merge(arr, left, mid, right):
    copy left half and right half into temp arrays
    compare element by element
    place smaller element back into arr
    copy remaining elements if any
```

**Complexity:**
| Case | Time | Space |
|------|------|-------|
| Best | O(n log n) | O(n) |
| Worst | O(n log n) | O(n) |

**Key Concept:** Unlike Quick Sort, Merge Sort always runs in O(n log n) regardless of input order. Trade-off is O(n) extra space for temp arrays.

---

### 5. Dijkstra's Algorithm — Single Source Shortest Path

**File:** [dijkstra.c](./dijkstra.c)

**Aim:** Find the shortest distance from a source vertex to all other vertices in a weighted graph using a greedy approach.

**Approach:**
1. Set distance of source to 0, all others to infinity.
2. Greedily pick the unvisited vertex with the minimum distance.
3. Relax all its neighbors — update their distance if a shorter path is found through this vertex.
4. Repeat until all vertices are visited.

**Pseudocode:**
```
function dijkstra(graph, src):
    dist[src] = 0; dist[all others] = INF
    visited[all] = false

    repeat n-1 times:
        u = unvisited vertex with minimum dist
        mark u as visited
        for each neighbor v of u:
            if dist[u] + edge(u,v) < dist[v]:
                dist[v] = dist[u] + edge(u,v)

    print dist[]
```

**Key Concept:** Greedy choice at each step — always extend the shortest known path. Does NOT work with negative edge weights.

---

### 6. 0/1 Knapsack Problem

**File:** [knapsack_dp.c](./knapsack_dp.c)

**Aim:** Maximize the total value of items placed in a knapsack with a fixed weight capacity. Each item can either be included (1) or excluded (0).

**DP Table Definition:**
`dp[i][j]` = maximum value using first `i` items with capacity `j`

**Recurrence:**
```
if weight[i] <= j:
    dp[i][j] = max(value[i] + dp[i-1][j - weight[i]],  dp[i-1][j])
else:
    dp[i][j] = dp[i-1][j]
```

**Pseudocode:**
```
for i from 0 to n:
    for j from 0 to W:
        if i == 0 or j == 0 → dp[i][j] = 0
        else if weight[i] <= j:
            dp[i][j] = max(val[i] + dp[i-1][j - wt[i]], dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j]

answer = dp[n][W]
```

**Complexity:** O(n × W) time and space.

**Key Concept:** Unlike the fractional knapsack (greedy), 0/1 knapsack requires DP because items cannot be split.

---

### 7. Floyd-Warshall — All Pairs Shortest Path

**File:** [floyd_warshall.c](./floyd_warshall.c)

**Aim:** Find shortest paths between every pair of vertices in a weighted directed graph.

**Approach:**
- For each intermediate vertex `k`, check if routing through `k` gives a shorter path between every pair `(i, j)`.

**Pseudocode:**
```
initialize matrix = copy of adjacency matrix

for k from 0 to n:
    for i from 0 to n:
        for j from 0 to n:
            if matrix[i][k] + matrix[k][j] < matrix[i][j]:
                matrix[i][j] = matrix[i][k] + matrix[k][j]
```

**Complexity:** O(n³) time, O(n²) space.

**Key Concept:** Dijkstra finds shortest path from one source. Floyd-Warshall finds all pairs in one pass — but works even with negative edges (not negative cycles).

---

### 8. N-Queens Problem

**File:** [nqueens.c](./nqueens.c)

**Aim:** Place N queens on an N×N chessboard such that no two queens attack each other (no shared row, column, or diagonal).

**Approach — Backtracking:**
1. Place a queen column by column (left to right).
2. For each row in the current column, check if placing a queen is safe.
3. If safe, place and recurse to the next column.
4. If no safe row is found, backtrack — remove the queen and try the next row.

**Pseudocode:**
```
function solveNQ(col):
    if col >= N → solution found, return true

    for each row i from 0 to N:
        if isSafe(i, col):
            place queen at board[i][col]
            if solveNQ(col + 1) → return true
            remove queen (backtrack) → board[i][col] = 0

    return false  ← no valid placement found

function isSafe(row, col):
    check all cells to the left on same row → no queen
    check upper-left diagonal → no queen
    check lower-left diagonal → no queen
```

**Key Concept:** Backtracking prunes branches early — as soon as a placement violates constraints, it backtracks without exploring deeper.

---

### 9. Travelling Salesperson Problem (TSP)

**File:** [tsp_branch_bound.c](./tsp_branch_bound.c)

**Aim:** Find the minimum cost tour that visits all cities exactly once and returns to the starting city.

**Approach — Branch and Bound:**
1. Start from city 0, explore all unvisited cities recursively.
2. Accumulate cost as cities are visited.
3. When all cities are visited, add the return cost to city 0.
4. Track and update the global minimum cost whenever a complete tour is found.
5. Backtrack — unmark visited cities after exploring each branch.

**Pseudocode:**
```
function tsp(city, count, costSoFar):
    if count == N AND path back to 0 exists:
        totalCost = costSoFar + cost[city][0]
        if totalCost < minCost → minCost = totalCost
        return

    for each city i not yet visited:
        if edge exists from city to i:
            mark i as visited
            tsp(i, count + 1, costSoFar + cost[city][i])
            unmark i (backtrack)
```

**Complexity:** O(n!) worst case (all permutations).

**Key Concept:** Branch and bound prunes paths whose cost already exceeds the current best solution — this avoids exploring all n! permutations in practice.

---

## How to Compile & Run

```bash
# Compile any program
gcc filename.c -o output

# Run
./output
```

> All programs are written in standard C (C99). Compile with `gcc` or any C compiler.

---

## Tech Stack
![C](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)
![GCC](https://img.shields.io/badge/Compiler-GCC-orange?style=flat-square)
![Lab](https://img.shields.io/badge/Type-Lab%20Programs-green?style=flat-square)

---

*Aditya University — B.Tech AI & ML — Advanced Data Structures & Algorithms Lab*
