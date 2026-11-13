#include <Stdio.h>

void PrintArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }printf("\n");
}

void SelectionSort(int *A, int n){
    int temp, indexMin;
    for(int i = 0; i < n-1; i++){
        indexMin = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[indexMin]){
                indexMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexMin];
        A[indexMin] = temp;  
    }
}
int main(){

    int A[] = {12, 43, 9, 0, 78};
    int n = 5;

    PrintArray(A, n);
    SelectionSort(A, n);
    PrintArray(A, n);

    return 0;
}