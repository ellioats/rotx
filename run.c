// Elliot Currie
// Tuesday, May 21. 2024

#include "rotx.h"
#include <stdbool.h>

#define CAPITAL_UPPER_BOUND 90
#define CAPITAL_LOWER_BOUND 65
#define LC_UPPER_BOUND 122
#define LC_LOWER_BOUND 97

void menu();
void devInfo();
void refine(char * input, char ** output);


int main() {

    // for entering phrase
    char str_input[15];
    char * refined_arr;

    // for rot num
    int rot_num;
    char rot_input[10];
    char * rot_overflow;

    // for menu navigation
    char option[2];
    char * overflow = NULL;
    int choice;

    // returned arr
    char * ret_arr;

    puts("welcome to the ROT-X Encryption Tool...");
    puts("This tool allows you to specify the rotation count...");
    puts("Please note that the input does not accept any non-alphabetic characters. Any Capitalized letters will be converted to lowercase.");
    puts("please refer to the following menu for your next steps...");

    menu();

    while(choice != 3) {

        fgets(option, 2, stdin);
        choice = (int) strtod(option, &overflow);
        getchar();
        switch(choice) {
            case 1: 
                do {
                    printf("Please enter a ROT number (between 1-25): ");
                    fgets(rot_input, 10, stdin);
                    rot_num = strtol(rot_input, &rot_overflow, 10);
                    // printf("rot num = %i\n", rot_num);
                } while(!(rot_num > 0 && rot_num < 26));



                bool y = true;
                do {

                    
                    printf("Please enter your phrase (no more than 15 characters, please): ");
                    fgets(str_input, 15, stdin);

                    // printf("DEBUG: you entered: %s\n", str_input);

                    refine(&str_input[0], &refined_arr);

                    // checks for invalid characters
                    for (int x = 0; x < strlen(refined_arr); x++) {
                        if ((int)(refined_arr[x]) <= CAPITAL_LOWER_BOUND || (int)(refined_arr[x]) >= CAPITAL_UPPER_BOUND && (int)(refined_arr[x]) <= LC_LOWER_BOUND || (int)(refined_arr[x]) >= LC_UPPER_BOUND) {
                            y = true;
                        } else {
                            y = false;
                        }
                    }

                } while(y);

                // check for capital letters
                for (int z = 0; z < strlen(refined_arr); z++) {
                    // letter is upper case
                    if ((int)(refined_arr[z]) >= CAPITAL_LOWER_BOUND && (int)(refined_arr[z]) <= CAPITAL_UPPER_BOUND) {
                        // printf("letter %c selected...\n", refined_arr[z]);
                        refined_arr[z] = refined_arr[z] + 32; 
                    }
                }

                puts("DEBUG: refine method finished");

                rotate(&refined_arr[0], &ret_arr, rot_num);

                
                break;
            case 2:
                devInfo();
                break;

        }
        puts("");
        if (!(choice == 3))
            menu();
        
        
    }
    
    free(ret_arr);

    // program exits
    return 0;
}

void refine(char * input, char ** output) {
    *output = (char *) (malloc(sizeof((strlen(input) + 1))));
    // printf("DEBUG: strlen of input = %i\n", strlen(input));

    int outputCounter = 0;

    for (int x = 0; x < strlen(input); x++) {
        // printf("DEBUG: ITR COUNT: %i\n", x);
        // printf("output counter: %i\n", outputCounter);

        if (input[x] == '\n' || input[x] == '\0' || input[x] == ' ') {
            // printf("DEBUG: escape sequence found, continuing...\n");
            continue;
        }
        
        (*output)[outputCounter] = input[x];
        // printf("value of %c appended to output arr...\n", input[x]);
        outputCounter++;
    }
}

void menu() {
    puts("1 - Enter a new phrase");
    puts("2 - Developer Info");
    puts("3 - Exit");
}

void devInfo() {
    puts("\nDeveloped by Elliot Currie");
    puts("Date of Development: Tuesday, May 21. 2024");
    puts("Contact: emwcurrie@gmail.com");
}