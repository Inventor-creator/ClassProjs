#include <stdio.h>

int main() {
    int n, steps = 0;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Count comparison
        steps++;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // shift
            j--;
            steps++;             // count each shift/comparison
        }

        arr[j + 1] = key;
        steps++; // count insertion
    }

    printf("%d\n", steps);
    return 0;
}
