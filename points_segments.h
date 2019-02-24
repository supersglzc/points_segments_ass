#ifndef POINTS_SEGMENTS_H
#define POINTS_SEGMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *arr, int size);
void print_array_2D(int **arr, int rows, int cols);
void naive_method(int ** segments, int * points, int s, int p, int * counts);
void quick_method(int ** segments, int * points, int s, int p, int * counts);
void swap(int * a, int * b);
void quickSort(int arr[], int arr2[], int low, int high);
int partition(int arr[], int arr2[], int low, int high);
#endif
