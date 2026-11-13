#include <Stdio.h>

void PrintArray(int *A, int n){
    for(int i = 0; i < n ; i++){
        printf("%d ", A[i]);
    }printf("\n");
}

void QuickSort(int *A, int n){
    for(int i = 0; i < n; i++){
         
    }

}
int main(){

    int A[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int n = 10;

    PrintArray(A, n);
    QuickSort(A, n);
    PrintArray(A, n);

    return 0;
}