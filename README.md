# Dictionary ADT

The file **Dictionary.cpp** has implementation of the **Dictionary** Data Structure with help of **Binary Search Tree (BST)**.

## Files In The Repository

1. Dictionary.cpp
2. Dictionary.h
3. DictionaryTest.cpp
4. Order.cpp
5. README.md
6. Makefile

# Make commands
```
$ make clean
```
This command will make the repository clean by deleting the object file and executable file of **DictionaryTest.cpp**, **Order.cpp**, and **Dictionary.cpp**.


```
$ make
```

This command will just compile other C files and make the executable and object file for **DictionaryTest.cpp** and **Order.cpp**.

# Running the program

```
$ make
```
1. This command will just compile and make the executable and object file for **DictionaryTest.cpp** and **Order.cpp**.

```
$ ./DictionaryTest
```

2. This command will run the DictionaryTest file and show the output of Dictionary ADT functions.

```
$ ./Order <infile> <outfile>
```

3. This command will run Shuffle.cpp and it takes **2** arguments i.e. positive input file and an output file.


# Memory Leak Check

1. Run the make command

```
$ make
```

2. Run the following command to check the memory leaks in DictionaryTest file.

```
$ make checkTest
```

3. Run the following command to check the memory leaks in Order File.

```
$ make checkOrder
```

# Other Commands

1. To clean the **.txt** files.

```
$ make cleanText
```

2. To clean the **backup** directory.

```
$ make cleandir
```
