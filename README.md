# Assignment 8 
## Objectives

To gain an understanding of memory allocation.

### Part 1
1. Write a program `sort.c` that dynamically allocates an array of integers. The size of the array (the number of integers, not the byte size) should be read from the user using scanf(). You may assume that the user will input a positive integer. The elements of the array should be filled using the rand() function. After filling the array with random numbers, your program should then make a copy of the array, and sort the new array in ascending order. Then make a second copy of the original array and sort it in descending order. Finally your program should print out all three arrays. All three arrays should be allocated using malloc() library function.   

### Part 2

In a text file `assignment7.txt`, answer the following questions:

Consider the following program, arg.c, shown with line numbers:
```C
1 #include <stdio.h>
2 #include <string.h>
3 #include <stdlib.h>
4
5 int main(int argc, char **argv)
6 {
7   if (argc != 3) {
8     printf("usage: %s <arg1> <arg2>\n", argv[0]);
9     return 1;
10  }
11
12  char *a = *++argv;
13  char *b = *++argv;
14  char c[2] = { 0, 0 };
15  char *p;
16  char *q;
17
18  for (p = a; *p; p++) {
19     if (’a’ <= *p && *p <= ’z’)
20        *c = *p + ’A’ - ’a’;
21     else
22        *c = *p;
23    printf("%s", c);
24  }
25
26  p = (char *)malloc(strlen(a) + strlen(b) + 1);
27  strcpy(p, a);
28  q = p + strlen(a);
29  while ((*q++ = *b++) != 0)
30  ;
31  printf("%s\n", p);
32  p = NULL;
33  return 0;
34 }
```

It is compiled, linked and run with two command line arguments as follows:
```
$ gcc -g -Wall arg.c
$ ./a.out abc 123
```
Answer the following questions:

1. What is the output? Assume that the malloc() call was successful. If you think that the program contains bugs (other than memory leaks) that can make the program crash (ex. segmentation fault), write "CAN CRASH" and then write the most likely output if the program happens to run without crashing.

2. If the program is run using valgrind, how many bytes will valgrind report as "definitely lost"? You can write 0 if you think there is no memory leak that valgrind will consider "definitely lost". Please make sure to write the number of BYTES.

3. Identify the line numbers that contains memory errors other than memory leaks (invalid access, for example.) If you think that there is no memory error other than possible memory leaks, write NONE. You don’t have to identify the nature of the memory errors. Just line numbers.

4. Modify the program to fix ALL memory errors, including memory leaks. Write only the lines that need to be fixed. Write the line number and the line of code that will replace that line. If you think there is nothing to fix, write "NO CHANGE". The program can be memory error free by modifying 0 to 3 lines of code. Please do not modify more than 3 lines of code.


### Submission Guidelines
Please include your name and a description in a comment at the top of your code files. Please also include your name at the top of your assignment7.txt file.

All files must be submitted via GitHub by 10:00am 7/12.
