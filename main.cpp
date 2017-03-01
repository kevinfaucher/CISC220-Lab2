
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <time.h> 



using namespace std;

int smallestElm(int numArray[], size_t length, int &smallest, int &index);

bool swap1(int *x, int *y);
bool swap2(int &x, int &y);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
int leastElement(int a[], int n, int smallest, int index);
int pointerArr(int *pointer);

int main() {
    srand(time(NULL));
    int x;
    int y;

    /*
     //TODO Organize these variables--cause its kinda crazy right now
    x = (rand() % 51) + 1;
    y = (rand() % 51) + 1;
    cout << x << endl;
    cout << y << endl;
    cout << swap1(&x, &y) << endl;
    cout << swap2(x, y) << endl;
     */
    /*
    int n[] = {-2, -1, -3};
    //int s = -1;
    //int index = -1;
    int s1 = -1;
    int index1 = -1;
    int length = 3;
    //size_t length = 3;
    leastElement(n, length, s1, index1);
    //cout << smallestElm(n, length, s, index) << +" test" << endl;
    //cout << "smallest element = " << s << endl;
     
    int fArray [20];
    int size = 20;
    fillArray(fArray, size);
     */
    int pointed = -1;
    pointerArr(&pointed);
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

//Problem 3

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int r = rand() % 100;
        arr[i] = r;
    }//for
}//fillarray


//Problem 4

void printArray(int arr[], int size)//Question 6b
{
    for (int i = 0; i < size; i++) {
        cout << arr[size] << endl;
    }
}


//Problem 5

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
/*
 I'm working on problem 14.  This code is pretty unorthodox, but I originally
 * programmed it in python because I find it easier to work out that way.  
 * As of now it can iterate over a string and fill an array with each digit of
 * the string
 *
 * Just need to put it in its own function and implement the random number part
 * 
 * int main() {
  int arr[5];
	string test = "10010";
  for(unsigned int i = 0; i<test.length(); i++) {
    char c = test[i]; 
    cout << c << endl;
    arr[int(i)] = atoi(&c);

}
for (int i = 5 - 1; i >= 0; i--) 
    cout << arr[i];
	return 0;
}

 
 */