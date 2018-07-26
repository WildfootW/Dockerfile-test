/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1 = malloc(36*sizeof(int));  // allocates enough for an array of 4 int
    int *q1 = malloc(sizeof(int));
    int *p2 = malloc(sizeof(int[36])); // same, naming the type directly
    int *q2 = malloc(sizeof(int));
    int *p3 = malloc(36*sizeof *p3);   // same, without repeating the type name
    int *q3 = malloc(sizeof(int));
    free(p1);
    free(p2);
    free(p3);
    return 0;
}

