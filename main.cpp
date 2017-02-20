/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin Faucher, Alexia Nebrao
 *
 * Created on February 19, 2017, 8:21 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <time.h> 



using namespace std;

/*
 * 
 */
int order1(int x, int y);

int main() {
    srand(time(NULL));
    int i;
    cout << "Hello World!\n";
    i = (rand()%51)+1;
    cout << i;
    
    

}
/*
int order1(int x, int y) {
    if (x > y) {
        int tmp = x;
        x = y;
        y = tmp;
        //make it call by pointer
        //return false;
    }
    else{
        return true;
    }
}
*/

