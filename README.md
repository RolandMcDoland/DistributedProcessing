# DistributedProcessing
A series of small assignments in C using MPI for Linux-based operating systems, which are a part of an university course.
## Contents
### Lab1 
Contains a very simple program made to familiarize with MPI. Every process receives an integer increments it and sends to the next one. 
### Lab2
Uses multiple processes to speed up the bubble sort algorithm. 
* **mysort.c**- the actual code
* **liczbydoposortowania**- numbers that are going to be sorted (how many numbers will be sorted is set in the code)
### Lab3
An algorithm for cracking encrypted passwords by brute force. Not a great mrthod but that's not the point. 
* **seq.c**- everything happens sequentially
* **crack.c**- using multiple processes to speed up the algorithm, by making each have the first letter set by the root 
## Technologies
* **MPI**
