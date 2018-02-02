#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}

void countSort(int arr[], int n, int base) {
    int output[n]; 
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / base) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / base) % 10] - 1] = arr[i];
        count[(arr[i] / base) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int base = 1; m / base > 0; base *= 10)
        countSort(arr, n, base);
}

int main() {
    int i, n, a[1000];
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    radixSort(a, n);
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}