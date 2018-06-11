#include <stdio.h>
#include <stdlib.h>

int doEverything(int length, int width, int add) {
	int i, j;
	int *arr[length];
	for (i = 0; i < length; i++) {
		arr[i] = (int*)malloc(width * sizeof(int));
	}
	printf("Array before you add: \n");
	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			int random = rand() % 50 + 1;
			arr[i][j] = random;
			printf("%d ", arr[i][j]);
		}
		printf(" \n");
	}
	printf("Array after you add: \n");
	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			arr[i][j] = arr[i][j] + add;
			printf("%d ", arr[i][j]);
		}
		printf(" \n");
	}

	for(i = 0; i <length; i++) {
		free(arr[i]);
	}
	//sfree(arr);
	return 0;
}

// void addFun(int** arr, int length, int width, int add) {
// 	int i, j;


	int main() {
		int length, width, add;
		srand((unsigned)time(NULL));
		printf("Enter length: ");
		scanf("%d", &length);
		printf("Enter width: ");
		scanf("%d", &width);
		printf("Enter how much you want to add: \n");
		scanf("%d", &add);

		doEverything(length, width, add);
		// addFun(arr, length, width, add);
		return 0;
	}