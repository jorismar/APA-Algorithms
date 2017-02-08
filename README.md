# Analysis and Design of Algorithms

This repository is used for the publication of the activities developed in the discipline of Analysis and Design of Algorithms. Below is a list of the activities available here and the method of executing them.

###Sorting 01
Go to [sorting-algorithms/C/](https://github.com/jorismar/APA-Algorithms/tree/master/sorting-algorithms/C) and in a Terminal tape:

To compile
```
$ make
```
To run a single sort algorithm to a testN (N = number)
```
$ make test ARGS="[-s|-i|-m|-q|-h]" TEST="testN"
```
To run all sort algorithms to a testN (N = number)
```
$ make test-all TEST="testN"
```
###Sorting 02
Go to [sorting-algorithms/C/](https://github.com/jorismar/APA-Algorithms/tree/master/sorting-algorithms/C) or 
[sorting-algorithms/Java/](https://github.com/jorismar/APA-Algorithms/tree/master/sorting-algorithms/Java) and:

Edit the Makefile and sets **INSTANCES_FOLDER** path. Then type:

To compile
```
$ make
```
To run all sorting algorithms to process all instances of benchmark analysis:
```
$ make run-instances
```

### Sorting 03

Working...
