#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array(int arr[], int len);
int swap(int* first, int* second);
void fisher_yates(int array[], const int length, int (*random_fcn)());
bool non_pos_prefix_sum(int arr[], int length);
bool non_neg_prefix_sum(int arr[], int length);
#endif // _FISHER_YATES_H_
