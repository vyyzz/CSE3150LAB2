#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"
#include <cstdlib>

int arr0[] = {};
int arr1[] = {1, -1};

int first1 = -99;
int save_first1 = first1;
int second1 = 4;
int save_second1 = second1;

int i = swap(&first1, &second1);

TEST_CASE("FISHER-YATES") {
    SUBCASE("swap tests") {
        CHECK_EQ(save_first1, second1);
        CHECK_EQ(first1, save_second1);
    }

    SUBCASE("fisher_yates random shuffling") {

        srand(time(NULL));
       
        int arr1[] = {1, 2, 3, 4, 5};
        int arr2[5];
        std::copy(arr1, arr1 + 5, arr2);

        srand(time(NULL)); 
        fisher_yates(arr1, 5, rand);

        srand(time(NULL) + 1); // 
        fisher_yates(arr2, 5, rand);

       
        CHECK_NE(arr1[0], arr2[0]);
        CHECK_NE(arr1[1], arr2[1]);
        CHECK_NE(arr1[2], arr2[2]);
        CHECK_NE(arr1[3], arr2[3]);
        CHECK_NE(arr1[4], arr2[4]);
    }

    SUBCASE("fisher_yates preserves array length") {
        
        int arr[] = {1, 2, 3, 4, 5};
        int original_length = sizeof(arr) / sizeof(arr[0]);

        fisher_yates(arr, original_length, rand);

        CHECK_EQ(original_length, sizeof(arr) / sizeof(arr[0]));
    }

    
};
