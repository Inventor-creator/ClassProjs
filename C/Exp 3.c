#include <stdio.h>

int main() {

    printf("16014224088 Arya Patil\n");

    // int num, originalNum, reversedNum = 0, remainder;


    // printf("Enter a number: ");
    // scanf("%d", &num);


    // originalNum = num;


    // while (num != 0)
    //     {
    //     remainder = num % 10;  // Get the last digitzz
    //     reversedNum = reversedNum * 10 + remainder;  // Builds the rev number
    //     num /= 10;  // Removed the last digit
    //      }


    // if (originalNum == reversedNum)
    //     {
    //     printf("%d is a palindrome.\n", originalNum);
    // }
    // else
    // {
    //     printf("%d is not a palindrome.\n", originalNum);
    // }


    //Q2

    // int n, firstTerm = 0, secondTerm = 1, nextTerm, sum = 0;


    // printf("Enter the number of terms: ");
    // scanf("%d", &n);


    // if (n <= 0) {
    //     printf("Please enter a positive integer greater than 0.\n");
    //     return 1; // Exit the program if invalid input
    // }


    // int count = 1;
    // do {
    //     if (count == 1)
    //         {
    //         nextTerm = firstTerm;
    //     } else if (count == 2)
    //     {
    //         nextTerm = secondTerm;
    //     } else
    //     {
    //         nextTerm = firstTerm + secondTerm;
    //          firstTerm = secondTerm;
    //         secondTerm = nextTerm;
    //     }

    //     sum += nextTerm; // Add the current term to sum
    //     count++; // Increment the counter

    // } while (count <= n); // Continue until n term


    // printf("Sum of Fibonacci series up to %d terms is: %d\n", n, sum);


    //Q3




    // int rows, i, j, k, space;


    // printf("Enter the number of rows: ");
    // scanf("%d", &rows);

    // if (rows <= 0) {
    //     printf("Please enter a positive integer.\n");
    //     return 1;
    // }

    // printf("\nTriangle Pattern:\n");


    // for (i = 1; i <= rows; i++) {

    //     space = rows - i;
    //     for (k = 0; k < space; k++) {
    //         printf("  ");
    //     }


    //     for (j = 1; j <= 2 * i - 1; j++) {
    //         printf("* ");
    //     }

    //     printf("\n");
    // }





    //postlabs

    //Q1

    // int n;
    // double sum = 0.0;


    // printf("Enter the number of terms (n): ");
    // scanf("%d", &n);


    // if (n <= 0) {
    //     printf("Please enter a positive integer.\n");
    //     return 1;
    // }

    // printf("Harmonic Series up to %d terms:\n", n);


    // for (int i = 1; i <= n; i++) {
    //     printf("1/%d", i);
    //     sum += 1.0 / i;
    //     if (i < n) {
    //         printf(" + ");
    //     }
    // }
    // printf("\nSum of the harmonic series up to %d terms: %.6f\n", n, sum);

    //Q2

    // int n, sum = 0;


    // printf("Enter the number of terms (n): ");
    // scanf("%d", &n);


    // if (n <= 0) {
    //     printf("Please enter a positive integer.\n");
    //     return 1;
    // }

    // printf("Square Natural Numbers up to %d terms:\n", n);


    // for (int i = 1; i <= n; i++) {
    //     int square = i * i;
    //     printf("%d ", square);
    //     sum += square;
    // }


    // printf("\nSum of the square natural numbers up to %d terms: %d\n", n, sum);





    return 0;
}
