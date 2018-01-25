#include<stdlib.h>
#include<stdio.h>


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int min(int x, int y) { return (x<y)? x :y; }
 

void mergeSort(int arr[], int n) {
   int cur;
   int left_start; 

   for (cur=1; cur<=n-1; cur = 2*cur) {
       for (left_start=0; left_start<n-1; left_start += 2*cur) {

          int mid = left_start + cur - 1;
 
          int right_end = min(left_start + 2*cur - 1, n-1);
          merge(arr, left_start, mid, right_end);
       }
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
    mergeSort(a,n);
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
