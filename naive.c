#include "points_segments.h"

void naive_method(int ** segments, int * points, int s, int p, int * counts){
	for (int i = 0; i < p; i ++){
		int count = 0;
		for (int j = 0; j < s; j ++){
			if (points[i] <= segments[j][1] && points[i] >= segments[j][0]){
				count ++;
			}
		}
		counts[i] = count;
	}
}
