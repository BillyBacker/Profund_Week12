#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int* A, int* B) {
	int B0 = *A;
	int B1 = *B;
	*A = B1;
	*B = B0;
}

struct Matrix
{
	int Mat[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
	void transpose() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i < j) {
					swap(&Mat[i][j], &Mat[j][i]);
				}
			}
		}
	}
	int* operator[](int i) {
		return Mat[i];
	}
	void operator=(int In[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Mat[i][j] = In[i][j];
			}
		}
	}
	void Print() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%d ", Mat[i][j]);
			}
			printf("\n");
		}
	}
};

int main() {
	Matrix A;
	int In[3][3] = {{1,2,3},
		 {4,5,6},
		 {7,8,9}};
	printf("Enter 3x3 Matrix : \n");
	for (int i = 0; i < 3; i++) {
		scanf("%d %d %d", &In[i][0], &In[i][1], &In[i][2]);
	}
	A = In;
	A.transpose();
	printf("\n");
	printf("Transposed Matrix : \n");
	A.Print();

	return 0;
}