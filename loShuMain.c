#include <stdio.h>
//#include <stdlib.h>

int magic (int arr[3][3], int rows, int columns) {
    // Row T sum initialization
    int sum = 0;
    int checkSum = 0;

    for (int i = 0; i < columns; i++) {
        sum += arr[0][i]; // Hard-coded because I know the length will always be 3.
        
    }
    printf("row T ok \n");
    // Row M check
    for (int i = 0; i < columns; i++) {
        checkSum += arr[1][i];
        
    }
    

    if (checkSum != sum) {
        return -1; // -1 will indicate a false value for the magic function.
    }
    printf("row M ok \n");

    // Row B check
    checkSum = 0;
    for (int i = 0; i < columns; i++) {
        checkSum += arr[2][i];
    }

    if (checkSum != sum) {
        return -1; 
    }
    printf("row B ok \n");
    // Column L check
    checkSum = 0;
    for (int i = 0; i < rows; i++) {
        checkSum += arr[i][0];
    }

    if (checkSum != sum) {
        return -1; 
    }
    printf("col L ok \n");
    // Column M check
    checkSum = 0;
    for (int i = 0; i < rows; i++) {
        checkSum += arr[i][1];
    }

    if (checkSum != sum) {
        return -1; 
    }
    printf("col M ok \n");
    // Column R check
    checkSum = 0;
    for (int i = 0; i < rows; i++) {
        checkSum += arr[i][2];
    }

    if (checkSum != sum) {
        return -1; 
    }
    printf("col R ok \n");
    // Diagonal L to R check
    checkSum = 0;
    for (int i = 0; i < columns; i++) {
        checkSum += arr[i][i];
        //printf("%d", checkSum);
    }

    if (checkSum != sum) {
        return -1; 
    }
    printf("diag L to R ok \n");
    // Diagonal R to L check
    checkSum = 0;
    //printf("%d", checkSum);
    for (int i = 0; i < columns; i++) {
        checkSum += arr[2 - i][2 - i];
        //printf("%d", checkSum);
    }

    if (checkSum != sum) {
        return -1; 
    }
    printf("diag R to L ok \n");

    return 0;
}

int main (void) {
    // Initialize square 2D array
    int square[3][3];
    int fart;

    square[0][0] = 4, square[0][1] = 9, square[0][2] = 2,
    square[1][0] = 3, square[1][1] = 5, square[1][2] = 7,
    square[2][0] = 8, square[2][1] = 1, square[2][2] = 6,

    
    fart = magic(square, 3, 3);

    if (fart == 0) {
        printf("This square is a magic square!!!!1!1!11\n");
    } else {
        printf("This square is NOT a magic square !!1\n");
    }

    return 0;
}

