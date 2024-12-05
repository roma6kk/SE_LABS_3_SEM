#include<iostream>
extern "C" {
	int _stdcall getmin(int* ddArr, int len) {
		int min = ddArr[0];
		for (int i = 0; i < len; i++) {
			if (min > ddArr[i]) min = ddArr[i];
		}
		return min;
	}
	int _stdcall getmax(int* ddArr, int len) {
		int max = 0;
		for (int i = 0; i < len; i++) {
			if (max < ddArr[i]) max = ddArr[i];
		}
		return max;
	}
}