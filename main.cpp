
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <time.h> 
#include <string>
#include <typeinfo>
#include <sstream>
using namespace std;

int smallestElm(int numArray[], size_t length, int &smallest, int &index);

bool swap1(int *x, int *y);
bool swap2(int &x, int &y);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
int leastElement(int a[], int n, int smallest, int index);
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
    smallestElm(n, length, smallest, index);

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

int smallestElm(int numArray[], size_t length, int &smallest, int &index) {
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
//Adjust variables to be pass by reference

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
/*I'm still playing around with this code.  It's close I think.
 I need to run some better test cases on it though.
 * 
 * bool isPal(int n[], int start, int end);

int main() {
  int n[] = {-2, -1, -3};
  int start = 0;
  int end = 2;
  
  cout << isPal(n, start, end) << endl;
  return 0;
}
bool isPal(int n[], int start, int end)
{
    if (start >= end)   
        return true;
    if (n[start] != n[end])
        return false;
    return isPal(n, ++start, --end);   
}
 */
//Problem 13

//I'm mostly sure this is working...mostly

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
    string test = "10010"; //test is an example of what a numeric string what look like here
    int x = 100 + (std::rand() % (10000 - 100 + 1));
    double f = 23.43;
    string String = static_cast<ostringstream*> (&(ostringstream() << x))->str();
    cout << String << "hello" << endl;

    cout << typeid (x).name() << endl; //just used to verify type change

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
