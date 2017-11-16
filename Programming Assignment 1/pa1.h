
#ifndef pa1
#define pa1
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

//Creating the magic square
int** magicSquare(int size) {
    int** square = new int*[size];
    for (int i = 0; i < size; i++) {
          square[i] = new int[size];
        }
  
      int row = 0;
      int col = (size/2);
      for (int i = 1; i <= (size * size); i++) {
          square[row][col] = i;
          row--;
          col++;
          if ((row >= 0 && col >= 0 && row < size && col < size && square[row][col] != 0) ||
              (row < 0 && col == size)) {
              row += 2;
              col--;
          }
  
          if (row < 0) {
              row = size-1;
          }
  
          if (col == size) {
              col = 0;
          }
      }
    return square;
  }
  
  //Creating a 2D Array
  int** newArray(int size){
    int** square = new int*[size];
    for (int i = 0; i < size; i++) {
          square[i] = new int[size];
      }
    return square;
 }
  
  //Printing Array
  void printArray(int** square, int size){
    for(int i = 0; i < size;i++) {
        for(int j = 0; j < size; j++)
            printf("%3d ", square[i][j]);
        printf("\n");
      }
    }
  
  
    //Rotating Array 90 degrees
  int** rotate(int** square, int size) {
    int** rotatedSquare = newArray(size);
    for (int j = 0; j < size; j++) {
      for (int i = 0; i < size; i++) {
        rotatedSquare[i][j] = square[j][(size-1)-i];
      }
    }
    return rotatedSquare;
    }
  
  //Checking for sums of rows, columns and diagonals
  void checkSum(int** square, int size){
    printf("\n");
    //Checking sum of rows
    printf("Checking the sums of every row:      ");
    int rowSum = 0;
    for (int j = 0; j < size; j++){
      int previous = 0;
      for (int i = 0; i < size; i++){
        previous = previous + square[i][j];
        rowSum = previous;
      }
      printf("%3d ",rowSum);
    }
    printf("\n");
  
    //Checking sum of columns
    printf("Checking the sums of every column:   ");
    int colSum = 0;
    for (int i = 0; i < size; i++) {
      int previous = 0;
      for (int j = 0; j< size; j++){
        previous = previous + square[i][j];
        colSum = previous;
      }
      printf("%3d ",colSum);
    }
    printf("\n");
  
    //Checking sum of diagonals
    int diaSum1 = 0; //Diagonal from the right
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++){
        if (j == i){
          diaSum1 = diaSum1 + square [i][j];
        }
      }
    }
    int diaSum2 = 0; //Diagonal from the left
    for (int i = size - 1; i >= 0; i-- ){
      for (int j = size - 1; j >= 0; j--){
        if (j == i){
          diaSum2 = diaSum2 + square [i][j];
        }
      }
    }
  
      printf("Checking the sums of every diagonal: %3d %3d", diaSum1, diaSum2);
      printf("\n");
      printf("\n");
  }
  
  //Checking for correct input
  int checkInput() {
    long input = 0;
    cout << "Enter the size of the magic square: " << endl;
    cin.clear();
    cin >> input;
    while(input % 2 == 0 || (input < 3 || input > 15)) {
      if (input == 0){
        cout << "Invalid Input. Please enter a non-zero" << endl;
        cin.clear();
        cin >> input;
      } else if (input < 3 || input > 15) {
        cout <<"Invalid Input. Please enter a number between 3 and 15." << endl;
        cin.clear();
        cin >> input;
      } else if (input % 2 == 0) {
        cout <<"Invalid Input. Please enter an odd number." <<endl;
        cin.clear();
        cin >> input;
      }
    }
    return input;
  }
  
  //Flipping array over a horizontal axis
  int** flipArray(int** square, int size){
    int** flipedArray = newArray(size);
    for (int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        flipedArray[i][j] = square[(size - 1) - i][j];
      }
    }
    return flipedArray;
  }
  
  #endif // pa1