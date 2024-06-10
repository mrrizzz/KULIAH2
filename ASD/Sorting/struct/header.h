#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

typedef struct siswa
{
  int no;
  char nama[50];
  int nilai;
} siswa;

void inputData_struct();
void select_sorting_method();
int select_order();
int select_sort_by();
void insertion();
void selection();
void bubble();
void shell();
void quicksort(int left, int right, int order, int sort_by);
void quick_wrapper();
int partition(int left, int right, int order, int sort_by);

void printOutput();
void menu_searching();
void sequential_search(int, int);
void binary_search(int, int);
void swap(siswa *a, siswa *b);

extern int *pdata[ARRAY_SIZE];
extern siswa data_siswa[ARRAY_SIZE];

#endif