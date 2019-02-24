#include "points_segments.h"

void swap(int* a, int* b){ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}

int partition (int arr[], int arr2[], int low, int high){ 
	int pivot = arr[high];   
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++){ 
    		if (arr[j] <= pivot){
			i ++; 
        		swap(&arr[i], &arr[j]);
			swap(&arr2[i], &arr2[j]);
		} 
    	} 
   	swap(&arr[i + 1], &arr[high]); 
	swap(&arr2[i + 1], &arr2[high]);
    	return (i + 1); 
}

void quickSort(int arr[], int arr2[], int low, int high) {
        if (low < high){
                int pi = partition(arr, arr2, low, high);
                quickSort(arr, arr2, low, pi - 1);
                quickSort(arr, arr2, pi + 1, high);
        }
}


void quick_method(int ** segments, int * points, int s, int p, int * counts){
	int sorted[2 * s + p];
	int* index = malloc(sizeof(int)*(2*s+p));
	int count = 0;
	for(int i = 0; i < s; i ++){
		sorted[count] = segments[i][0];
		index[count] = i;
		count++;
		sorted[count] = segments[i][1];
		index[count] = i;
		count++;
	}
	for(int i = 0; i < p; i++) {
		sorted[count] = points[i];
		index[count] = i+2*s;
		count++;
	}
	//print_array(index, 2 * s + p);
	quickSort(sorted, index, 0, 2 * s + p - 1);
	//print_array(sorted, 2 * s + p);
	//print_array(index, 2 * s + p);

	int occur[s];
	for (int i = 0; i<s; i++) {
		occur[i] = 0;
	}
	int num = 0;
	for (int i = 0; i < 2*s+p; i++) {
		if (index[i] < 2*s) {
			occur[index[i]]++;
			if (occur[index[i]] == 1) {
				num++;
			}
			if (occur[index[i]] == 2) {
				num--;
			}
		}	
		else {
			counts[index[i] - 2*s] = num;
		}
	}

	//print_array(counts, p);
	free(index);
}
