#include <stdio.h>
#include <stdlib.h> // malloc, free, srand 함수 사용
#include <time.h> // 랜덤한 수를 행렬에 저장하기 위해 time 함수 사용

void printMatrix(int **matrix, int row, int col); // A와 B 행렬을 출력하는 함수
int **addMatrix(int **A, int **B, int row, int col); // A와 B 행렬을 더하는 함수
int **subtractMatrix(int **A, int **B, int row, int col); // A와 B 행렬을 빼는 함수
int **transposeMatrix(int **A, int row, int col); // A의 전치행렬 T를 구하는 함수
int **multiplyMatrix(int **A, int **B, int rowA, int colA, int rowB, int colB); // A와 B 행렬을 곱하는 함수
void freeMatrix(int **matrix, int row); // 할당했던 메모리를 해제하는 함수

int main() 
{
    printf("소프트웨어학과 2021041002 오원석\n");
    int row, col;
    printf("행렬의 행, 열 입력: ");
    scanf("%d %d", &row, &col);
    
     // 행렬 A와 B를 동적 메모리 할당
    int **A = (int **)malloc(row * sizeof(int *)); // row 만큼 A 행렬 동적 메모리 할당
    int **B = (int **)malloc(row * sizeof(int *)); // row 만큼 B 행렬 동적 메모리 할당
    for (int i = 0; i < row; i++) 
    {
        A[i] = (int *)malloc(col * sizeof(int)); // A 행렬의 행과 열의 크기만큼 동적 메모리 할당
        B[i] = (int *)malloc(col * sizeof(int)); // B 행렬의 행과 열의 크기만큼 동적 메모리 할당
    }

    // 행렬에 srand, time 함수를 사용하여 랜덤한 수를 생성하여 저장
    srand(time(NULL)); // srand 함수와 time 함수를 사용하여 랜덤한 수를 생성
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            A[i][j] = rand() % 31; // 0부터 30까지의 랜덤한 수를 저장
            B[i][j] = rand() % 31; // 0부터 30까지의 랜덤한 수를 저장
        }
    }

    printf("===A행렬 주소,값===\n%p %p %d\n",&A,&(*A),**A);
    printf("===B행렬 주소,값===\n%p %p %d\n",&B,&(*B),**B);

    // 행렬 A와 B를 출력
    printf("------------A 행렬------------\n");
    printMatrix(A, row, col);
    printf("------------B 행렬------------\n");
    printMatrix(B, row, col);

    // 행렬 A와 B를 더한 후 출력
    int **C = addMatrix(A, B, row, col); // A와 B 행렬을 더하는 함수 addMatrix 호출
    printMatrix(C, row, col); // addMatrix 함수에서 반환된 행렬 C를 출력
    freeMatrix(C, row); // addMatrix 함수에서 할당한 메모리 해제

    // ㅎ행렬 A와 B를 뺀 후 출력
    int **D = subtractMatrix(A, B, row, col); // A와 B 행렬을 빼는 함수 subtractMatrix 호출
    printMatrix(D, row, col); // subtractMatrix 함수에서 반환된 행렬 D를 출력
    freeMatrix(D, row); // subtractMatrix 함수에서 할당한 메모리 해제

    // 행렬 A의 전치행렬을 계산 후 출력
    int **E = transposeMatrix(A, row, col); // A의 전치행렬을 구하는 함수 transposeMatrix 호출
    printMatrix(E, col, row);  // transposeMatrix 함수에서 반환된 행렬 E를 출력
    freeMatrix(E, col);  // transposeMatrix 함수에서 할당한 메모리 해제

    // 행렬 A * B를 계산 후 출력
    int **F = multiplyMatrix(A, B, row, col, row, col); // A와 B 행렬을 곱하는 함수 multiplyMatrix 호출
    printMatrix(F, row, col); // multiplyMatrix 함수에서 반환된 행렬 F를 출력
    freeMatrix(F, row); // multiplyMatrix 함수에서 할당한 메모리 해제

    freeMatrix(A, row); // A 행렬의 동적 메모리 해제
    freeMatrix(B, row); // B 행렬의 동적 메모리 해제

    return 0;
}

 // A와 B 행렬을 출력하는 함수
void printMatrix(int **matrix, int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** addMatrix(int** A, int** B, int row, int col) 
{
    int** C = (int**)malloc(row * sizeof(int*)); // 할당된 메모리를 저장할 C 행렬을 동적 메모리 할당
    for (int i = 0; i < row; i++) 
    {
        C[i] = (int*)malloc(col * sizeof(int)); // C 행렬의 행과 열의 크기만큼 동적 메모리 할당
    }

    // 행렬 A+B를 계산하여 C 행렬에 저장
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            C[i][j] = A[i][j] + B[i][j]; 
        }
    }
    printf("---------add matrix---------\n");
    return C;
}

int** subtractMatrix(int **A, int **B, int row, int col) 
{
    int **D = (int **)malloc(row * sizeof(int *)); // 할당된 메모리를 저장할 D 행렬을 동적 메모리 할당
    for (int i = 0; i < row; i++) 
    {
        D[i] = (int *)malloc(col * sizeof(int)); // D 행렬의 행과 열의 크기만큼 동적 메모리 할당
    }

    // 행렬 A-B를 계산하여 D 행렬에 저장
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            D[i][j] = A[i][j] - B[i][j];
        }
    }
    printf("---------subtract matrix---------\n");
    return D;
}

int** transposeMatrix(int **A, int row, int col) 
{
    int **E = (int **)malloc(col * sizeof(int *)); // 할당된 메모리를 저장할 E 행렬을 동적 메모리 할당
    for (int i = 0; i < col; i++) 
    {
        E[i] = (int *)malloc(row * sizeof(int)); // E 행렬의 행과 열의 크기만큼 동적 메모리 할당
    }

    // A의 전치행렬을 E 행렬에 저장(A의 행과 열을 바꾸어 저장)
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            E[j][i] = A[i][j];
        }
    }
    printf("---------transpose matrix---------\n");
    return E;
}

int** multiplyMatrix(int **A, int **B, int rowA, int colA, int rowB, int colB) 
{

    int **F = (int **)malloc(rowA * sizeof(int *)); // 할당된 메모리를 저장할 F 행렬을 동적 메모리 할당
    for (int i = 0; i < rowA; i++) 
    {
        F[i] = (int *)malloc(colB * sizeof(int)); // F 행렬의 행과 열의 크기만큼 동적 메모리 할당
    }

    // 행렬 A와 B를 곱하여 F 행렬에 저장
    for (int i = 0; i < rowA; i++) 
    {
        for (int j = 0; j < colB; j++) 
        {
            F[i][j] = 0;
            for (int k = 0; k < colA; k++) 
            {
                F[i][j] += A[i][k] * B[k][j]; // A의 row과 B의 col을 곱하여 F 행렬에 저장
            }
        }
    }
    printf("---------multiply matrix---------\n");
    return F;
}


void freeMatrix(int **matrix, int row) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]); // 행렬의 row에 할당된 메모리 해제
    }
    free(matrix); // 행렬의 메모리 해제
}