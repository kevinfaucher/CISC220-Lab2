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
#include <sstream>
using namespace std;

int MinFind(int numArray[], size_t length, int &smallest, int &index);

bool swap1(int *x, int *y);
bool swap2(int &x, int &y);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void MinRec(int a[], int size, int &min, int &index, int curind);
int sum_array(int *arr, int size);
int min_array(int a[], int length);
void sortarr(int arr[], int size);
bool palindref(int arr[], int size, int x, int &fourth);
bool pali(int a[], int size);
bool isPal(int a[], int length);
void finalpalin(int arr[], int size, int &x, int &y);
int findMin(int *arr, int size);
int pointerArr(int *pointer);
int fillarr(int &length);
void matrix(int arr[], int length, int *pointer, int &reference);
int modArr(int arr[], int *length);

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
    cout << "\nProblem-------------------------- 4" << endl;
    printArray(arrfil, size);

    //Problem 5
    cout << "\nProblem-------------------------- 5" << endl;
    int a1[3] = {2, -2, 3};
    int smallest = 0;
    int index = 0;
    MinFind(arrfil, size, smallest, index);

    //Problem 6
    cout << "\nProblem-------------------------- 6" << endl;
    int min = 0;
    int minIndex = 0;
    MinRec(arrfil, size, min, minIndex, 1);

    //Problem 7
    sum_array(&arrfil[3], 5);

    //Problem 7b
    findMin(arrfil, size);

    //Problem 8
    cout << "\nProblem-------------------------- 8" << endl;
    sortarr(arrfil, size);

    //Problem 9
    int n[] = {3, 5, 9, 4, 8, 2, 8, 4, 7, 10}; //just a sample array 
    int length = 5;
    cout << "\nProblem-------------------------- 9" << endl;
    cout << pali(n + 3, length) << endl;
    //Problem 10
    cout << "\nProblem-------------------------- 10" << endl;
    cout << isPal(n + 3, length) << endl;

    //Problem 11
    cout << "\nProblem-------------------------- 11" << endl;
    int b[] = {2, 6, 3, 3, 7, 7, 3, 3, 6, 2};
    int length1 = 10;
    int palint = 0;
    palindref(&b[0], length1, 2, palint);
    cout << endl << palint;

    //Problem 12
    cout << "\nProblem-------------------------- 12" << endl;
    int x = 0;
    int y = 0;
    finalpalin(b, length1, x, y);

    //Problem 13
    int pointed = -1;
    pointerArr(&pointed);

    //Problem 14
    cout << "\nProblem-------------------------- 14" << endl;
    cout << "Testing the result array" << endl;
    int length2 = 0;
    fillarr(length2);

    //Problem 15
    cout << "\nProblem-------------------------- 15" << endl;
    int size3 = 50;
    int arr3 [50];

    for (int i = 0; i < size3; i++) {
        int r1 = rand() % 50;
        arr3[i] = r1;
    }
    modArr(arr3, &size3);
   


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
    cout << "The smallest value in this array is " << smallest << " which can be found at index " << index << endl;
    return index, smallest;
}

//Problem 6

void MinRec(int a[], int size, int &min, int &index, int currentIndex) {
    if (currentIndex >= (size - 1)) {
        cout << "The smallest value in this array is " << min << " which can be found at index " << index << endl;
        return;
    }
    if (a[index] > a[currentIndex]) {
        min = a[currentIndex];
        index = currentIndex;
    }
    MinRec(a, size, min, index, currentIndex + 1);
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

        return cout << " It is a palindrome " + true;
    else
        return cout << " It is not a palindrome" + false;
}

//Problem 10

bool isPal(int a[], int length) {
    if (a[0] != a[length - 1]) {
        return cout << "It is a palindrome " + false;
    }
    if (length == 0) {
        return cout << "It is a palindrome " + true;
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
    int arr [*pointer];
    for (int i = 0; i < *pointer; i++) {
        int r = rand() % 50;
        arr[i] = r;
    }
    return *arr;

}

//Problem 14

int fillarr(int &length) {
    int arr[length];
    int x = 100 + (std::rand() % (10000 - 100 + 1));
    string String = static_cast<ostringstream*> (&(ostringstream() << x))->str();
    length = String.length();
    int size = (int) length;
    for (unsigned int i = 0; i < String.size(); i++) {
        char c = String[i];
        arr[int(i)] = c - '0';

    }
    //printing the array for testing
    for (int i = length - 1; i >= 0; i--)
        cout << arr[i];
    return *arr;
}
//Problem 15

int modArr(int arr[], int *length) {
    int count = 0;
    for (int i = 0; i < *length; i++) {
        if (arr[i] == (i > 10 and i < 40)) {
            for (int j = i; j < (*length - 1); j++) {
                arr[j] = arr[j + 1];
            }
            count++;
            break;
        }
        return *arr;
    }
}


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
