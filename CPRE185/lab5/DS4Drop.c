#include <stdio.h>
#include <math.h>

// Function to calculate magnitude of acceleration
double mag(double ax, double ay, double az) {
    return sqrt(ax * ax + ay * ay + az * az);
}

// Function to check if value is close to the target within a given tolerance
int close_to(double value, double target, double tolerance) {
    return fabs(value - target) <= tolerance;
}

int main(void) {
    char firstName[] = "YourFirstName";
    char lastName[] = "YourLastName";
    char netID[] = "YourNetID";

    printf("%s %s\n%s\n", firstName, lastName, netID);
    printf("Ok, I'm now receiving data.\n");

    // Constants for controlling output frequency
    const int waitingPeriod = 10; // Number of input lines to wait for one period
    const int exclamationFrequency = 5; // Number of periods between exclamation marks

    // Variables for accelerometer data
    double ax, ay, az;
    double distance = 0; // Distance fallen in meters
    double time = 0; // Time taken to fall in seconds

    // Loop to read data and detect free fall
    int inputCount = 0;
    while (1) {
        // Read accelerometer data (replace these lines with actual data reading)
        scanf("%lf %lf %lf", &ax, &ay, &az);

        // Detect free fall based on accelerometer data
        if (close_to(mag(ax, ay, az), 9.8, 0.1)) {
            distance = 0.5 * 9.8 * time * time; // Calculate distance fallen
            printf("Help me! I'm falling!!!!!!!!!!!!!\n");

            // Output exclamation mark after a certain number of periods
            if (inputCount % (waitingPeriod * exclamationFrequency) == 0) {
                printf("!\n");
            }

            // Wait for the next period of waiting
            if (inputCount % waitingPeriod == 0) {
                printf("."); // Output period after a certain number of input lines
            }

            time += 0.1; // Assuming data is received every 0.1 seconds
        } else {
            // Not in free fall, reset time and distance
            time = 0;
            distance = 0;
            printf("I'm Waiting ..............\n");
        }

        inputCount++;

        // Add conditions to break the loop based on your requirements (e.g., pressing a button)
    }

    return 0;
}
