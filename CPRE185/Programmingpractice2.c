#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array of random numbers
void generate_random_numbers(int *arr, int size) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % 100; // Generates random numbers between 0 and 99
    }
}

// Function to sort the array in ascending order using bubble sort algorithm
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap arr[j] and arr[j + 1]
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

// Function to calculate the sum of elements in the array
int calculate_sum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(arr + i);
    }
    return sum;
}

// Function to calculate the average of elements in the array
float calculate_average(int *arr, int size) {
    int sum = calculate_sum(arr, size);
    return (float)sum / size;
}

// Function to find the maximum value in the array
int find_maximum(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

// Function to find the minimum value in the array
int find_minimum(int *arr, int size) {
    int min = *arr;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }
    return min;
}

// Main method
int main() {
    const int size = 10; // Size of the array
    int numbers[size]; // Array to store random numbers
    
    // Generate random numbers using pointers and display the original array
    generate_random_numbers(numbers, size);
    printf("Original Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(numbers + i));
    }
    printf("\n");
    
    // Sort the array using pointers
    bubble_sort(numbers, size);
    
    // Calculate and display the sum and average of the elements
    int sum = calculate_sum(numbers, size);
    float average = calculate_average(numbers, size);
    printf("Sum of Elements: %d\n", sum);
    printf("Average of Elements: %.2f\n", average);
    
    // Find and display the maximum and minimum values
    int maximum = find_maximum(numbers, size);
    int minimum = find_minimum(numbers, size);
    printf("Maximum Value: %d\n", maximum);
    printf("Minimum Value: %d\n", minimum);
    
    return 0;
}