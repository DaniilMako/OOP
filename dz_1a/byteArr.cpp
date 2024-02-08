#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdint.h>

typedef unsigned int bitword;
bitword bytes[625001]; //2*10^7 / 32 = 625000

void bitsetZero(bitword* arr, int num) {  // обнуляет массив
	for (int i = 0; i <= num / 32; i++) {
		arr[i] = 0;
	}
}

int bitsetGet(const bitword* arr, int idx) {  // достает бит по индексу
	int move = idx % 32;
	idx = idx / 32;
	int h = (arr[idx] >> move) & 1;
	return h;
}

void bitsetSet(bitword* arr, int idx, int newval) {
	int move = idx % 32;
	idx = idx / 32;
	if (newval == 0 && (arr[idx] >> move & 1)) {
		arr[idx] -= (1 << move);
	}
	else {
		arr[idx] |= (newval << move);
	}
}

int bitsetAny(const bitword* arr, int left, int right) {  // переприсваивает значение
	for (int i = left; i < right; i++) {
		int idx = i / 32;
		int move = i % 32;
		int h = (arr[idx] >> move) & 1;
		if (arr[idx] == 0) {
			i = (idx + 1) * 32 - 1;
		}
		else {
			if (h == 0) {
				continue;
			}
			else {
				if (h == 1) {
					return 1;
				}
			}
		}

	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, num, idx, left, right, newval;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int op;
		scanf("%d", &op);
		switch (op)
		{
		case 0:
			scanf("%d", &num);
			bitsetZero(bytes, num);
			break;
		case 1:
			scanf("%d", &idx);
			printf("%d\n", bitsetGet(bytes, idx));
			break;
		case 2:
			scanf("%d", &idx);
			scanf("%d", &newval);
			bitsetSet(bytes, idx, newval);
			break;
		case 3:
			scanf("%d", &left);
			scanf("%d", &right);
			if (bitsetAny(bytes, left, right) == 1) {
				printf("some\n");
			}
			else {
				printf("none\n");
			}
			break;
		}
	}
}