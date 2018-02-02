#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> b[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; 
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main() {
    float a[1000];
    int i, n;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Elements: ");
    for(i = 0; i < n; i++) {
        scanf("%f",&a[i]);
    }
    bucketSort(a, n);
    for(i = 0; i < n; i++)
        printf("%f ",a[i]);
    printf("\n");
}