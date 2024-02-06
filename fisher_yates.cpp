#include <iostream>
#include <cstdlib>

#include "fisher_yates.h"

void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
    return 0;
}

void fisher_yates(int array[], const int length, int (*random_fcn)()) {
    for (int i = 0; i < length - 1; i++) {
        int rnd_location = random_fcn() % (length - i);
        swap(&array[i], &array[rnd_location + i]);
    }
}

int prefix_sum(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}

#include <iostream>

bool non_neg_prefix_sum(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
        if (sum < 0) {
            return false;  
        }
    }
    return true;  
}

bool non_pos_prefix_sum(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
        if (sum > 0) {
            return false;  
        }
    }
    return true;  
}
