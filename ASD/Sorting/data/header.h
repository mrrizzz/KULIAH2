#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ARRAY_SIZE 100000

void inputData();
double select_sorting_method();
int select_order();


void insertion();
void selection();
void bubble();
void shell();
void merge_rekursif(int, int, int);
void merge(int, int, int, int);
void quick(int, int, int);
int quick_partition(int, int, int);


double operation_time(void (*func)());
void backup(int new[], int origin[], int n);
void printOutput();
void swap(int *a, int *b);
void generate(int data[], int n);
void merge_rekursif_wrapper();
void quick_wrapper();

extern int data[ARRAY_SIZE];
extern int hasil[ARRAY_SIZE];

#endif