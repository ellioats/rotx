// Elliot Currie
// Tuesday, May 21. 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LEN 26

void rotate(char * user_arr, char **ret_ptr, int rot);
void testPrint(char * arr);
int alphabetCount(char c, int rot);

char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


void rotate(char * user_arr, char **ret_ptr, int rot) {

    printf("output using ROT-%i\n", rot);

    // test
    testPrint(user_arr);
    printf(" -> ");

    *ret_ptr = (char *) (malloc(sizeof((strlen(user_arr)))));

    
    // main "game loop"
    for (int x = 0; x < strlen(user_arr); x++) {
        printf("position %i of ret arr set to %c\n", x, alphabet[alphabetCount(user_arr[x], rot)]);
        (*ret_ptr)[x] = alphabet[alphabetCount(user_arr[x], rot)];
    }

    // printing output array
    testPrint(*ret_ptr);

    puts("");
}

int alphabetCount(char c, int rot) {
    int x, ret;

    // finding index of letter in alphabet
    for (x = 0; x < strlen(alphabet); x++) {
        if (c == (char) (alphabet[x])) {
            printf("Index of letter %c is %i\n", c, x);
            break;
        }
            
    }
    
    ret = x + rot;

    if (ret > 25 && ret != 26) {
        ret = ret % ALPHABET_LEN;
    } 

    printf("\t\tRet Value: %i\n", ret);

    return ret;
}

// a debug function, used to print an array
void testPrint(char * arr) {
    // printf("DEBUG: strlen(arr): %i\n", strlen(arr));
    for (int x = 0; x < strlen(arr); x++) {

        printf("'%c' ", arr[x]);
    
    }
    // puts("");
}