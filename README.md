# Parallel-Programming-Assignment-1-

Overview
This repository contains the solutions for the Parallel Programming Assignment 1, where we explore parallelization techniques and performance metrics for different problems. The main objectives of this assignment include:

Analyzing the performance of parallel programs through speedup and efficiency.
Developing performance models for different parallel summing algorithms.
Running the STREAM benchmark to measure performance with varying numbers of OpenMP threads.
Implementing a parallel program to estimate the value of π using Pthreads and OpenMP, and analyzing the parallel speedup and efficiency.

# Problem Breakdown

## Problem 1: Performance Analysis of Parallel Programs

   Part (a): A program to find the speedups and efficiencies of a parallelized program with varying problem sizes (n) and number of threads (p).

  Part (b): A theoretical analysis of parallel efficiency when parallelization overhead grows slower or faster than the sequential execution time.
  
## Problem 2: Performance Model for Parallel Summing

Part (a): Deriving execution time formulas for valid parallel versions of the sum operation, considering overhead, barrier, mutex, and extra work for thread 0.
Part (b): A model for determining when parallelization is profitable based on the execution time for Version 3.

## Problem 3: STREAM Benchmark

Measuring the performance of the STREAM benchmark (copy, scale, add, and triad) using varying numbers of OpenMP threads (1, 2, 4, 8, 16). Performance data are collected on the provided virtual machine.

## Problem 4: Estimating π using Pthreads and OpenMP

Part 1: Implementing a parallel program to estimate π using Pthreads. Performance metrics (speedup and efficiency) are collected, and the program is run for various numbers of threads (1, 2, 4, 8, 16).
Part 2: Rewriting the program using OpenMP, and repeating the analysis for speedup and efficiency.
