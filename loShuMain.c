#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int magic (int arr[3][3], int rows, int columns) {
    // Row T sum initialization
    int sum = 0;
    int checkSum = 0;

    for (int i = 0; i < columns; i++) {
        sum += arr[0][i]; // Hard-coded because I know the length will always be 3.
        
    }
    //printf("row T ok \n");
    // Row M check
    for (int i = 0; i < columns; i++) {
        checkSum += arr[1][i];
        
    }
    

    if (checkSum != sum) {
        return -1; // -1 will indicate a false value for the magic function.
    }
    //printf("row M ok \n");

    // Row B check
    checkSum = 0;
    for (int i = 0; i < columns; i++) {
        checkSum += arr[2][i];
    }

    if (checkSum != sum) {
        return -1; 
    }
    //printf("row B ok \n");
    // Column L check
    checkSum = 0;
    for (int i = 0; i < rows; i++) {
        checkSum += arr[i][0];
    }

    if (checkSum != sum) {
        return -1; 
    }
    //printf("col L ok \n");
    // Column M check
    checkSum = 0;
    for (int i = 0; i < rows; i++) {
        checkSum += arr[i][1];
    }

    if (checkSum != sum) {
        return -1; 
    }
    //printf("col M ok \n");
    // Column R check
    checkSum = 0;
    for (int i = 0; i < rows; i++) {
        checkSum += arr[i][2];
    }

    if (checkSum != sum) {
        return -1; 
    }
    //printf("col R ok \n");
    // Diagonal TL to BR check
    checkSum = 0;
    for (int i = 0; i < columns; i++) {
        checkSum += arr[i][i];
        //printf("%d", checkSum);
    }

    if (checkSum != sum) {
        return -1; 
    }
    //printf("diag L to R ok \n");
    // Diagonal BL to TR check
    checkSum = 0;
    //printf("%d", checkSum);
    for (int i = 0; i < columns; i++) {
        checkSum += arr[2 - i][i];
        //printf("%d", checkSum);
    }

    if (checkSum != sum) {
        return -1; 
    }
    //printf("diag R to L ok \n");

    return 0;
}


int dupeCheck (int arr[3][3], int value) {

    for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                
                if (value == arr[i][j]) {
                    //printf("%d = %d.\n", value, arr[i][j]);
                    return -1; // if there's a dupe
                }

                //printf("%d != %d!\n", value, arr[i][j]);
            }
            //printf("\n");
            
    }

    return 0; // If there's no dupe
}

int main (void) {
    // Initialize square 2D array
    int square[3][3];
    int otherSquare[3][3];
    int s;
    int os;
    int attempts = 0;

    srand(time(0));
    const int MAX = 9;
    const int MIN = 1;

    square[0][0] = 4, square[0][1] = 9, square[0][2] = 2,
    square[1][0] = 3, square[1][1] = 5, square[1][2] = 7,
    square[2][0] = 8, square[2][1] = 1, square[2][2] = 6,

    
    s = magic(square, 3, 3);

    if (s == 0) {
        printf("This square is a magic square!!!!1!1!11\n");
    } else {
        printf("This square is NOT a magic square !!1\n");
    }

    while (os != 0) {
        attempts++;

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                // generate a random number
                int r = rand() % (MAX - MIN + 1) + MIN;

                // check if r already appears in the array

                if (dupeCheck(otherSquare, r) == 0) {
                    otherSquare[i][j] = r;
                    //printf("Passed Dupe Test: %d\n", otherSquare[i][j]);
                    
                } else {
                    while (dupeCheck(otherSquare, r) != 0) {
                        r = rand() % (MAX - MIN + 1) + MIN;
                        //printf("%d", r);
                    }

                    otherSquare[i][j] = r;
                    //printf("Passed Dupe Test, Post-Dupe Hell: %d\n", otherSquare[i][j]);
                }
                //printf("%d\n", otherSquare[i][j]);
            }
            
        }
        /*
        printf("Loop Over! Results:\n");

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                
                printf("%d ", otherSquare[i][j]);
                
            }
             printf("\n");
            
        }
        */
        os = magic(otherSquare, 3, 3);
        
        // clear array if it is not a magic square
        if (os != 0) {
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    otherSquare[m][n] = 0;

                }
            }
        }
        
        
    }
    printf("RANDOM MAGICAL SQUARE:\n");
    printf("Attempts: %d\n", attempts);
        
    for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                
                printf("%d ", otherSquare[i][j]);
                
            }
             printf("\n");
            
        }


    return 0;
}

