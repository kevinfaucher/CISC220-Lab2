
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <time.h> 



using namespace std;

int smallestElm(int numArray[], size_t length, int &smallest, int &index);

bool swap1(int *x, int *y);
bool swap2(int &x, int &y);
int leastElement(int a[], int n, int smallest, int index);

int main() {
    srand(time(NULL));
    int x;
    int y;

    /*
     
    x = (rand() % 51) + 1;
    y = (rand() % 51) + 1;
    cout << x << endl;
    cout << y << endl;
    cout << swap1(&x, &y) << endl;
    cout << swap2(x, y) << endl;
     */
    int n[] = {-2, -1, -3};
    int s = -1;
    int index = -1;
    int s1 = -1;
    int index1 = -1;
    size_t length = 3;
    leastElement(n,length,s1,index1);
    cout << smallestElm(n, length, s, index) << +" test" << endl;
    cout << "smallest element = " << s << endl;
    return 0;



}
//Problem 1

bool swap1(int *x, int *y) {
    if (x > y) {
        int swap;
        swap = *x;
        *x = *y;
        *y = swap;
        return false;
        //return false;
    } else {
        return true;
    }
}



//Problem 2

bool swap2(int &x, int &y) {
    if (x > y) {
        int swap;
        swap = x;
        x = y;
        y = swap;
        return false;
        //return false;
    } else {
        return true;
    }
}

//Problem 5

/*
 (6 pts) Write a function that takes as an input parameter an array of integers, a length parameter (an int),
and two more int parameters that will be modified using pass by reference. When the function is called
the third and fourth parameters are initialized to -1 (before the function call). The function should locate
the smallest value in the array, modifying the third parameter to be the smallest value and the fourth to
be the index location of the smallest value. Make sure you print these values after you’ve returned from
the function.
 */

int smallestElm(int numArray[], size_t length, int &smallest, int &index) {
    smallest = numArray[0];
    for (int i = 1; i < length; i++) {
        if (numArray[i] < smallest) {
            smallest = numArray[i];
            index = i;
        }

    }
    return smallest, index;
}

int leastElement(int a[], int n, int smallest, int index) {
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 0;
    }
    int k = 1 + leastElement(a + 1, n - 1, smallest, index);
    if (a[0] < a[k]) {
        return 0;
    } else {
        smallest = a[k];
        index = k;
        return smallest, k;
    }
}
