# Vector-tests-with-sorting-algorithms

**Abstract**

This work aims to compare and analyze the performance of six sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Quick Sort, and Merge Sort.

**Observation**
* If the code doesn't work for vectors larger than 1000 elements, adjust the MergeSort range. Please read the comment provided.

**Introduction**

Sorting is a fundamental operation in computer science, with various applications. The goal of a sorting algorithm is to organize a set of data in ascending or descending order.

**Sorting Algorithms:**

**Bubble Sort:**

* The simplest and most intuitive method.
* Compares adjacent elements and swaps them if they are in reverse order.
* Complexity: O(n²) in the worst case and O(n) in the best case.

**Selection Sort:**

* Divides the array into sorted and unsorted parts.
* Finds the smallest element in the unsorted part and places it at the beginning of the sorted part.
* Complexity: O(n²) in all cases.

**Insertion Sort:**

* Inserts each element of the unsorted list into the correct position in the sorted list.
* Efficient if the list is already partially sorted.
* Complexity: O(n²) in the worst case and O(n) in the best case.

**Shell Sort:**

* Combines Insertion Sort with dividing the list into subgroups.
* Improves the performance of Insertion Sort on larger lists.
* Complexity: O(n log n) on average, but depends on the gap sequence used.

**Quick Sort:**

* Divides the list into sublists using a pivot.
* Sorts the sublists recursively.
* Complexity: O(n log n) on average and O(n²) in the worst case.

**Merge Sort:**

* Divides the list in half until each sublist has only one element.
* Combines the sorted sublists recursively.
* Complexity: O(n log n) in all cases.

**Objectives:**

* Implement the six sorting algorithms.
* Compare the running time of each algorithm for different list sizes.
* Analyze the efficiency of each algorithm in different scenarios.
* Identify the most suitable algorithm for each type of situation.

**Summarized Introduction:**

This work presents a comparative analysis of six sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Quick Sort, and Merge Sort. We discuss the implementation of each algorithm, its computational complexity, and its performance in different scenarios. The aim is to identify the most suitable algorithm for each type of situation, considering the size of the list, the type of data, and the need for efficiency.

**Next Steps:**

* Implement the sorting algorithms.
* Collect data on the running time of each algorithm.
* Analyze the data and identify the most efficient algorithm in each case.
* Write a final report with the research results.

**Target Audience:**

* Beginners in computer science.
* Students learning about sorting algorithms.
* Anyone interested in understanding the basics of sorting algorithms.
