/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <string.h>

/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
char determine_orientation(double ax, double ay, double az, double tolerance);
int close_to(double value, double point, double tolerance) {
    return fabs(point - value) <= tolerance;
}
double mag(double ax, double ay, double az);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
   int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
    int top = 0, bot = 0, left = 0, right = 0, front = 0, back = 0;
    double tolerance = 0.9; // Experiment with this value
    char prev_orientation = 'M';  // 'M' for MOVING



    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
         /*printf ("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);*/

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */
        
        char current_orientation = determine_orientation(ax, ay, az, tolerance);

        if (current_orientation != prev_orientation) {
            printf("%c\n", current_orientation);
            prev_orientation = current_orientation;
        }
        if (b1 == 1) {
            break;
        }

    }

    return 0;
}

/* Put your functions here */
/*Function to calculate the magnitude of acceleration*/
double mag (double ax, double ay, double az) {
    return sqrt(ax * ax + ay * ay + az * az);
}
/* Function to determine orientation */
char determine_orientation(double ax, double ay, double az, double tolerance) {
    int top = 0, bot = 0, left = 0, right = 0, front = 0, back = 0;
    /*char determine_orientation(double ax, double ay, double az, double tolerance) {*/
    if (close_to(mag(ax, ay, az), 1.0, tolerance)) {
        printf("TOP\n");
    }
    if (close_to(mag(ax, ay, az), 0.0, tolerance)) {
        printf("BOT\n");
    }
    if (close_to(ax, 1.0, tolerance) && close_to(ay, 0.0, tolerance) && close_to(az, 0.0, tolerance)) {
        printf("RIGHT\n");
    }
    if (close_to(ax, -1.0, tolerance) && close_to(ay, 0.0, tolerance) && close_to(az, 0.0, tolerance)) {
        printf("LEFT\n");
    }
    if (close_to(ax, 0.0, tolerance) && close_to(ay, 0.0, tolerance) && close_to(az, -1.0, tolerance)) {
        printf("FRONT\n");
    }
    if (close_to(ax, 0.0, tolerance) && close_to(ay, 0.0, tolerance) && close_to(az, 1.0, tolerance)) {
        printf("BACK\n");
    }

    return 'M';
}
  
