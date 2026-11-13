#include <stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsertionSort(int *A, int n){
    int j, key;
    // NO OF PASSES
    for(int i = 1; i <= n-1; i++){
        key = A[i];
        j = i-1;
        // NO OF EACH PASSES
        while(j >= 0 && A[i] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;

    printArray(A, n);
    InsertionSort(A, n);
    printArray(A, n);

    return 0;
}