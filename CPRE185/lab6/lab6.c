// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);
// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);



// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);
// Function to print character 'use' num times to the screen

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);
 
int main() {
    double g_x, g_y, g_z;
    int time, Button_T, Button_X, Button_S, Button_C;
    int last_press = 0; // Initialize last_press variable
    int mode = 0; // Initialize mode variable (0 for ROLL, 1 for PITCH)

    int switch_mode = 0; // Variable to track mode switch
    int stop = 0; // Variable to track program stop

    do {
        read_line(&g_x, &g_y, &g_z, &time, &Button_T, &Button_C, &Button_X, &Button_S);

        if (Button_T == 1 && last_press != 1) {
            switch_mode = 1 - switch_mode; // Toggle mode between ROLL and PITCH
        }

        if (Button_S == 1 && last_press != 1) {
            stop = 1; // Set stop flag to 1 when square button is pressed
        }

        if (!stop) {
            // Calculate roll and pitch based on the selected mode
            double roll_rad = asin(fmin(1.0, fmax(-1.0, -1 * g_x)));
            double pitch_rad = asin(fmin(1.0, fmax(-1.0, g_y)));
            
            int scaled_value = scaleRadsForScreen(switch_mode == 0 ? roll_rad : pitch_rad);

            print_chars(scaled_value, switch_mode == 0 ? 'r' : 'l');
            graph_line(scaled_value);
            fflush(stdout);
        }

        last_press = Button_T;

    } while (!stop);

    return 0;
}
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_C, int* Button_X, int* Button_S) {
    return scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_y, g_z, Button_T, Button_C, Button_X, Button_S);
}

double roll(double x_mag){
    if (x_mag > 1){
        return asin(1);
    } else if (x_mag < -1){
        return asin(-1);
    } else {
        return asin(x_mag);
    }
}

double pitch(double y_mag){
    if (y_mag > 1){
        return asin(1);
    } else if (y_mag < -1){
        return asin(-1);
    } else {
        return asin(y_mag);
    }
}

int scaleRadsForScreen(double rad) {
    const int MAX_OUTPUT = 39;
    const int MIN_OUTPUT = -39;

    if (rad <= -PI / 2) {
        return MIN_OUTPUT;
    } else if (rad >= PI / 2) {
        return MAX_OUTPUT;
    } else {
        return (int)((rad - (-PI / 2)) * (MAX_OUTPUT - MIN_OUTPUT) / PI + MIN_OUTPUT);
    }
}

void print_chars(int num, char use) {
    int i;
    int mid = 40; // Middle point of the screen

    // Handle the case when num is out of range
    if (num < -39) {
        num = -39;
    } else if (num > 39) {
        num = 39;
    }

    // Print spaces up to the middle point
    for (i = 0; i < mid; ++i) {
        printf(" ");
    }

    // Print 'r' characters on the right side if num is positive (right or forward tilt)
    if ((use == 'r' && num > 0) || (use == 'f' && num == 0)) {
        for (i = 0; i < num; ++i) {
            printf("r");
        }
    }
    // Print 'l' characters on the left side if num is negative (left or backward tilt)
    else if ((use == 'l' && num < 0) || (use == 'b' && num == 0)) {
        for (i = 0; i > num; --i) {
            printf("l");
        }
    }

    printf("\n");
}

void graph_line(int number) {
    int i;
    int mid = 40; // Middle point of the screen

    // Handle the case when number is out of range
    if (number < -39) {
        number = -39;
    } else if (number > 39) {
        number = 39;
    }

    // Prepare the bar characters
    char barChars[81];

    // Fill the bar characters with spaces
    for (i = 0; i < 80; ++i) {
        barChars[i] = ' ';
    }

    // Fill 'r' characters on the right side if number is positive (right or forward tilt)
    if (number > 0) {
        for (i = mid; i < mid + number; ++i) {
            barChars[i] = 'r';
        }
    }
    // Fill 'l' characters on the left side if number is negative (left or backward tilt)
    else if (number < 0) {
        for (i = mid; i > mid + number; --i) {
            barChars[i] = 'l';
        }
    }
    // If the value is 0 or not enough to justify printing a character, output '0' at column 40
    else {
        barChars[mid] = '0';
    }

    // Null-terminate the string
    barChars[80] = '\0';

    // Print the bar
    printf("%s\n", barChars);
}
