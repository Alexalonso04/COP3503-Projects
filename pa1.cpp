#include <iostream>
#include <string.h>
#include <stdio.h>
#include <tgmath.h>

using namespace std;
//Initializing Functions
void printArray(int** square, int size);
int** magicSquare(int size);
int** newArray(int size);
int** rotate(int** square, int size);
void checkSum(int** square, int size);
int checkInput();
int** flipArray(int** square, int size);

int main() {
  int n = checkInput();

  //1st Iteration: Create base magic square
  printf("Magic Square #1 is: \n");
  int** square = magicSquare(n);
  printArray(square, n);
  checkSum(square, n);

  //2nd Iteration: Rotate magic square 90 degrees
  printf("Magic Square #2 is: \n");
  int** square1 = newArray(n);
  square1 = rotate(square,n);
  printArray(square1, n);
  checkSum(square1, n);

  //3rd Iteration: Rotate magic square 90 degrees
  printf("Magic Square #3 is: \n");
  int** square2 = newArray(n);
  square2 = rotate(square1,n);
  printArray(square2, n);
  checkSum(square2, n);

  //4th Iteration: Rotate magic square 90 degrees
  printf("Magic Square #4 is: \n");
  int** square3 = newArray(n);
  square3 = rotate(square2, n);
  printArray(square3, n);
  checkSum(square3, n);

  //5th Iteration: Flip the array along a vertical axis
  printf("Magic Square #5 is: \n");
  int** square4 = newArray(n);
  square4 = flipArray(square3,n);
  printArray(square4,n);
  checkSum(square4, n);

  return 0;
  }

//**************************************
//Functions
//**************************************

//Creating the magic square
int** magicSquare(int size){
  int** square = new int*[size];
  for (int i = 0; i < size; i++) {
        square[i] = new int[size];
      }

    int row = 0, col = (size/2);
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
  printf("\n");
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
    printf("%3d",rowSum);
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
    printf("%3d",colSum);
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

    printf("Checking the sums of every diagonal: %3d%3d", diaSum1, diaSum2);
    printf("\n");
    printf("\n");
}

//Checking for correct input
int checkInput() {
  int input = 0;
  std::cout << "Enter the size of the magic square: " << std::endl;
  std::cin >> input;
  while((input % 2) == 0 || (input < 3 || input > 15)) {
    if (input == 0){
      std::cout <<"Invalid Input. Please enter a non-zero" <<std::endl;
      std::cin >> input;
    } else if (input < 3 || input > 15) {
      std::cout <<"Invalid Input. Please enter a number between 3 and 15." <<std::endl;
      std::cin >> input;
    } else if (input % 2 == 0) {
      std::cout <<"Invalid Input. Please enter an odd number." <<std::endl;
      std::cin >> input;
    }
  }
  return input;
}

//Flipping array over a vertical axis
int** flipArray(int** square, int size){
  int** flipedArray = newArray(size);
  for (int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      flipedArray[i][j] = square[(size - 1) - i][j];
    }
  }
  return flipedArray;
}
