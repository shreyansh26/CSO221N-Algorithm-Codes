#include<stdio.h>
 
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)     {
        
        if (arr[j] <= pivot) {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int i, n, a[1000];
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    quickSort(a, 0, n-1);
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}