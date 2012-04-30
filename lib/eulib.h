#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

//#define ROWS 20
//#define COLS 20

//int ops
bool isFactor(int index, int num);
bool isPrime(int num);
bool isSquare(int num);
int nextTri(int index, int curTri);
int numDivisors(int num);
int numPrimes(int max);
int triWithDivs(int target);

//buffer ops
//int fillBuffer(char* buf, char* infile);
int prodFrom(char* buf, int head, int tail);
int expBuf(int* buf, int x, int y);

//Collatz ops
int maxCollatz(int* collatz, int max);
long long int evenCollatz(long long int num);
long long int oddCollatz(long long int num);

//combinatorics
long long int choose(int n, int k);
int factorial(int n);

//IO ops
int fillBufferDigits(char* buf, char* infile);
int fillGridDigits(int** grid, char* infile, int cols);
int fillGridInts(int** grid, char* infile, int cols);

//long long int ops
bool isEvenL(long long int num);
int isFactorL(long long int index, long long int num);
int isPrimeL(long long int index);
long long int squareSums(int max);
long long int sumPrimes(int max);
long long int sumSquares(int max);


//matrix ops
//int fillGrid(int** grid, char* infile, int rows, int cols);
int maxProd(int ** grid, int rows, int cols, int num);
int prodDagUp(int** pos, int r, int c, int num);
int prodForward(int** pos, int r, int c, int num);
int prodDagDown(int** pos, int r, int c, int num);
int prodDown(int** pos, int r, int c, int num);
int sumDigits(int** grid, int* sum, int rows, int cols, int digits);
int sumDown(int** pos, int r, int c, int num);

//print ops
void printBufDigits(int *buf, int begin, int end);
void printGridDigits(int** pos, int rows, int cols);
void printGridInts(int** pos, int rows, int cols);

//Pythagorean Triplet ops
bool checkSumSquare(int a, int b, int c);
bool checkSum(int a, int b, int c, int sum);
int calcProd(int a, int b, int c);

//string ops
bool isPalindrome(char* pal);
char* reverse(char* pal);


