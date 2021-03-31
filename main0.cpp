#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;
#define N (1024) // размерность матрицы

void matrixSum (float* first, float* second, float* result) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i * N + j] = first[i * N + j] + second[i * N + j];
}

void matrixSub (float* first, float* second, float* result) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i * N + j] = first[i * N + j] - second[i * N + j];
}

void matrixMult(float* first, float* second, float* result) { //????
    float sum = 0;
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j)
                sum += first[i * N + k] * second[k * N + j];
}

void matrixFill(float* I) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            I[i * N + j] = (i == j);
}
void matrixEmpty(float* A){
    for(int i = 0; i<N; ++i)
        for(int j = 0; j<N; ++j)
            A[i * N + j] = 0;
}

float* iterativeMethod(float* matrix, float* x1, float* b){
    float epsilon;
    int n;
    auto* y = (float*)calloc(N, sizeof(float));
    auto* x2 = (float*)calloc(N, sizeof(float));
    auto* sumUV = (float*)calloc(N, sizeof(float)); //keep prev
    auto* tau = (float*)calloc(N, sizeof(float));
    auto* temp = (float*)calloc(N, sizeof(float));
    while(...<epsilon){
        matrixMult(matrix, x1, temp); //A*x
        matrixSub(temp, b, y); // y = Ax - b
        for(int i = 0; i<n-1; i++){
            matrixSum()
        }
        x2 = 

    }
}

int main()
{
    auto* A = (float*)calloc(N * N, sizeof(float)); // original matrix
    float* Inv;
    auto* x = (float*)calloc(N, sizeof(float));
    auto* b = (float*)calloc(N, sizeof(float));
    matrixFill(A);
    matrixEmpty(x);
    iteratveMethod();

/*
for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j)
        std::cout << Inv[i * N + j] << ' ';
    std::cout << std::endl;
}
*/
    free(A);
    free(x);
    free(b);
    return 0;
}
