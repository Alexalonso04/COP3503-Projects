/*
//Name: Alejandro Alonso
//UFID: 3635-5787
//Assignment 1: Magic Square Project
//Date: 09/25/2017
*/

#include <iostream>
#include <string.h>
#include <tgmath.h>

#include "pa1.h"
using namespace std;

//Initializing Functions

int main() {
  int n = checkInput();

  //1st Iteration: Create base magic square
  cout << "Magic Square #1 is: \n" << endl;
  int** square = magicSquare(n);
  printArray(square, n);
  checkSum(square, n);

  //2nd Iteration: Rotate magic square 90 degrees
  cout << "Magic Square #2 is: \n" << endl;
  int** square1 = newArray(n);
  square1 = rotate(square,n);
  printArray(square1, n);
  checkSum(square1, n);

  //3rd Iteration: Rotate magic square 90 degrees
  cout << "Magic Square #3 is: \n" << endl;
  int** square2 = newArray(n);
  square2 = rotate(square1,n);
  printArray(square2, n);
  checkSum(square2, n);

  //4th Iteration: Rotate magic square 90 degrees
  cout << "Magic Square #4 is: \n" << endl;
  int** square3 = newArray(n);
  square3 = rotate(square2, n);
  printArray(square3, n);
  checkSum(square3, n);

  //5th Iteration: Flip the array along a vertical axis
  cout << "Magic Square #5 is: \n" << endl;
  int** square4 = newArray(n);
  square4 = flipArray(square3,n);
  printArray(square4,n);
  checkSum(square4, n);

  return 0;
  }
