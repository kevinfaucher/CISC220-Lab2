/* 
 * File:   main.cpp
 * Author: Kevin Faucher, Alexia Nebrao
 *
 * Created on February 20, 2017
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <time.h> 
#include <string>
#include <typeinfo>
#include <sstream>
using namespace std;

int MinFind(int numArray[], size_t length, int &smallest, int &index);

bool swap1(int *x, int *y);
bool swap2(int &x, int &y);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
int leastElement(int a[], int size, int &minE, int &index, int cindex);
int sum_array(int *arr, int size);
int min_array(int a[], int length);
void sortarr(int arr[], int size);
bool palindref(int arr[], int size, int x, int &fourth);
void finalpalin(int arr[], int size, int &x, int &y);
int pointerArr(int *pointer);
int fillarr(int &length);
void matrix(int arr[], int length, int *pointer, int &reference);

int main() {
    srand(time(NULL));
    //Problem 1
    int s1 = 6;
    int s2 = 2;
    swap1(&s1, &s2);
    //Problem 2
    swap2(s1, s2);
    //Problem 3
    int size = 20;
    int arrfil[size];
    fillArray(arrfil, size);
    //Problem 4
    printArray(arrfil, size);
    //Problem 5
    int n[] = {-2, -1, -3};
    int length = 3;
    int smallest = -1;
    int index = -1;
    MinFind(n, length, smallest, index);
    //Problem 6



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

//Problem 3

void fillArray(int arr[], int size) {
    arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}//fillarray


//Problem 4

void printArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        cout << arr[i];
        cout << ", ";
    }
    cout << arr[size - 1];

    cout << endl;
}

//Problem 5

int MinFind(int numArray[], size_t length, int &smallest, int &index) {
    smallest = numArray[0];
    int sizeArr = (int) length;
    for (int i = 1; i < sizeArr; i++) {
        if (numArray[i] < smallest) {
            smallest = numArray[i];
            index = i;
        }

    }
    return index, smallest;
}

//Problem 6

int leastElement(int a[], int size, int &min, int &index, int curind) {
    if (curind >= (size - 1)) {
        cout << "The smallest element in the array is " << min << " at index " << index << endl;
    }
    if (a[index] > a[curind]) {
        min = a[curind];
        index = curind;
    }
    leastElement(a, size, min, index, curind + 1);
}

//Problem 7a

int sum_array(int *arr, int size) {
    int sum = arr[size - 1];
    if (size - 1 > 0) {
        sum = sum + sum_array(&arr[0], size - 1);
    } // if, end condition.
    return sum;
}

int findMin(int *arr, int size) {
    int y = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < y) {
            y = arr[i];
        }
    }
    return y;
}
//Problem 7b

int min_array(int a[], int length) {
    int x = rand() % 5 + 3;
    int minsum = 10000;
    int index = 0;
    for (int i = 0; i <= length - x; i++) {
        //cout<<i<<endl;
        sum_array(&a[i], x);
        if (sum_array(&a[i], x) <= minsum) {
            minsum = sum_array(&a[i], x);
            index = i;
        }
    }
    cout << index << endl;
    return index;
}

//Problem 8

void sortarr(int arr[], int size) {
    if (size <= 2) {
        return;
    }
    int min = 0;
    int mindex = 0;
    MinFind(arr, size, min, mindex);
    if (min < arr[0]) {
        arr[mindex] = arr[0];
        swap2(arr[0], min);
    }
    //ArrayPrint(a,size);
    int *newarr = &arr[1];
    sortarr(newarr, size - 1);

}
//Problem 9

/*
This is what a function call looks like for this

   int n[] = {3, 5, 9, 4, 8, 2, 8, 4, 7, 10}; //just a sample array for testing
   int length = 5;
   pali(n+3,length);
   Index position is n + wherever you want to start
   length is the remaing size of the array from that point
   
 */
bool pali(int a[], int size) {
    int pos = 0;
    int i = 0;
    while (pos == 0 && i < size) {
        if (a[i] == a[size - i - 1]) {
            pos = 0;
            i++;
        } else {
            pos = 1;
        }
    }
    if (pos == 0)
        return true;
    else
        return false;
}

//Problem 10

bool isPal(int a[], int length) {
    if (a[0] != a[length - 1]) {
        return false;
    }
    if (length == 0) {
        return true;
    }
    isPal(&a[1], length - 2);

}
//Problem 11

bool palindref(int arr[], int size, int x, int &fourth) {
    int i = 0;
    while (i <= (size - x)) {
        if (pali(&arr[i], size)) {
            fourth = i;
            return true;
        }
        i++;
    }
    return false;
}

//Problem 12

void finalpalin(int arr[], int size, int &x, int &y) {
    int i = size;
    while (i > 0) {
        if (palindref(&arr[0], size, i, x)) {
            y = i;
            return;
        }
        i--;
    }
}

//Problem 13

int pointerArr(int *pointer) {

    int randNum;
    *pointer = 8 + (rand() % (int) (33 - 8 + 1));
    //possible alternative: *pointer = 8 + (rand() % (int) 26);
    int arr [*pointer];
    for (int i = 0; i < *pointer; i++) {
        int r = rand() % 50;
        arr[i] = r;
    }//

    /*
     this loop here is temporary and used for testing purposes 
     * Delete it before submitting
     */
    for (int i = 0; i < *pointer; i++) {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
    return 0;

}

//Problem 14



//Problem 14, almost there
//I think its working
//There's still some stuff in there that I'm playing with for testing

int fillarr(int &length) {
    int arr[length];
    int x = 100 + (std::rand() % (10000 - 100 + 1));
    string String = static_cast<ostringstream*> (&(ostringstream() << x))->str();
    length = String.length();
    int size = (int) length;
    for (unsigned int i = 0; i < String.size(); i++) {
        char c = String[i];
        cout << c << endl;
        arr[int(i)] = c - '0';

    }
    return *arr;
}
//Problem 15



//Problem 17

void matrix(int arr[], int length, int *pointer, int &reference) {
    int accu = 0;
    int accu2 = 0;
    int splitter = rand() % 20;
    for (int i = 0; i < length; i++) {
        if (i != splitter) {
            accu++;
        }
    }
    int arr1[accu];
    for (int i = 0; i < length; i++) {
        if (i != splitter) {
            arr1[i] = i;
        }

    }

    for (int i = 0; i < length; i++) {
        if (i == splitter) {
            accu2++;
        }
    }
    int arr2[accu2];
    for (int i = 0; i < length; i++) {
        if (i == splitter) {
            arr2[i] = i;
        }
        int *array2d[2];
        array2d[0] = arr1;
        array2d[1] = arr2;
    }
}
