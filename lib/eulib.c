#include "eulib.h"

//int ops
bool isFactor(int index, int num)
{
    return num%index == 0;
}

bool isPrime(int num)
{
    int i = sqrt(num);
    
    if(num == 1) return false;

    while(i>0)
    {
        if(isFactor(i, num))
            break;
        i--;
    }
    return i==1;
}

bool isSquare(int num)
{
    int midpt = sqrt(num);
    return isFactor(midpt,num);
}

int nextTri(int index, int curTri)
{
    return index+curTri;
}

int numDivisors(int num)
{
    int i, numdivs, midpt;
    
    numdivs = 0;
    midpt = sqrt(num);
    for(i=1; i<=midpt; i++)
        if (isFactor(i, num))
            numdivs++;
    numdivs *= 2;
    if(isFactor(midpt,num))
        numdivs--;
    return numdivs;
}

int numPrimes(int max)
{
    int i, j, maxj, count;
    int bound = (max/log(max))*(1 + 1.2762/log(max));
    int primes[bound];
    
    // insert 2 into primes[]
    primes[0] = 2;
    count = 1;

    i = 3;
    while(i<max)
    {
        j = 0;
        maxj = sqrt(i);
        
        //is prime[j] a factor of i
        while(j<count)
        {
            if (primes[j] > maxj)
            {
                j = count;
                break;
            }
            if(isFactor(primes[j],i))
            {
                break;
            }
            j++;
        }
        if(j==count)
        {
            primes[count] = i;
            count++;
        }
        i += 2;
     }
    return count;
}

int triWithDivs(int target)
{
    int index, curtri, numdivs;
    
    index=1;
    curtri=0;
    while(numdivs <= target)
    {
        curtri = nextTri(index++, curtri);
        numdivs = numDivisors(curtri);
    }
    return curtri;
}

//buffer ops
int expBuf(int* buf, int x, int y)
{
    int i, carry;
    
}

int prodFrom(char* buf, int head, int tail)
{
    int i, sum;
    
    sum = 1;
    for(i=head; i<=tail; i++)
    {
        sum *= (buf[i] - '0');
    }
    return sum;
}

//combinatorics
long long int choose(int n, int k)
{
    int i;

    if(k==0) return 1;
    else if(n==0) return 0;

    if(k > n-k)
    {
        k = n-k;
    }
    const int nn = n;
    const int kk = k;

    //allocate n ROWS, for n choose k
    long long int** nchoose = (long long int**)calloc(nn+1, sizeof(long long int*));

    //allocate i+1 COLS on each Row, for n choose k
    for(i=0; i<nn+1; i++)
    {
        nchoose[i] = (long long int*)calloc(i+1, sizeof(long long int));
    }

    k = 0;
    nchoose[0][0] = 1;
    
    // set initial values
    for(n=1; n<nn; n++)
    {
        nchoose[n][0] = 1;
        nchoose[n][1] = n;
        nchoose[n][n-1] = n;
        nchoose[n][n] = 1;

    }
    
    for(n=4; n<=nn; n++)
    {

        for(k=2; k<=n/2; k++)
        {

            nchoose[n][k] = nchoose[n-1][k-1] + nchoose[n-1][k];
            nchoose[n][n-k] = nchoose[n][k];

        }
    }
    
/*
n k:0   1   2   3   4   5   6   7   8
0   1
1   1   1
2   1   2   1
3   1   3   3   1
4   1   4   6   4   1
5   1   5   10  10  5   1
6   1   6   15  20  15  6   1
7   1   7   21  35. 35. 21  7   1
8   1   8   28  56  70. 56  28  8   1

*/    

//    printf("n: %d, k: %d n!=", n, k, factorial(n)); fflush(stdout);
//    nchoosek = factorial(n)/(factorial(k)*factorial(n-k));

    return nchoose[nn][kk];
}

int factorial(int n)
{
    int i;
    int fact = 1;

    if(n <= 0) return 1;
    
    for(i=1; i<n; i++)
    {
        fact *= i;
        printf("i: %d, fact: %d\n", i, fact); fflush(stdout);
    }
    return fact;
}



//Collatz ops
long long int evenCollatz(long long int num)
{
    return num/2;
}

int maxCollatz(int* collatz, int max)
{
    int terms, maxi;
    long long int i, j;
    maxi = 0;
    collatz[0] = 0;
    collatz[1] = 1;
    i = 1;
    
    while(i<max)
    {
        i++;
        terms = 1;
        j = i;
                
        //printf("%lld", i);
        while(j>1)
        {
            if(isEvenL(j))
            {
                j = evenCollatz(j);
            }
            else
            {
                j = oddCollatz(j);
            }
            //printf("->%lld", j);
            terms++;
            if(j<i) break;
        }
        collatz[i] = terms + collatz[j];
        //if (i%1000 == 0)
        //printf("\ncollatze[%d] %d", i, collatz[i]);

        if(collatz[i] > collatz[maxi])
        {
            maxi = i;
        }

        //printf("\n");
    }
    return maxi;
}

long long int oddCollatz(long long int num)
{
return 3*num+1;
}

//IO ops
int fillBufferDigits(char* buf, char* infile)
{
    int i, rc;
    FILE* fp = fopen(infile, "rb");

    if(fp == NULL)
    {
        perror("Failed to open \"problem8.txt\"");
        return EXIT_FAILURE;
    }
    
    for(i=0; (rc =getc(fp)) != EOF; i++)
    {
        if(rc == '\n' || rc==' ' || rc=='\t')
            i--;
        else buf[i] = rc;
    }

    fclose(fp);
    return 0;
}
int fillGridDigits(int** grid, char* infile, int cols)
{  
    int i, rc;
    FILE* fp = fopen(infile, "rb");

    if (fp == NULL) {
        perror("Failed to open file \"problem11.txt\"");
        return EXIT_FAILURE;
    }

    for(i=0; (rc =getc(fp)) != EOF; i++)
    {
        if(rc == '\n' || rc==' ' || rc=='\t')
            i--;
        else grid[i/cols][i%cols] = rc - '0';
        
    }

    fclose(fp);
    return 0;
}

int fillGridInts(int** grid, char* infile, int cols)
{  
    int i, rc;
    FILE* fp = fopen(infile, "rb");
    if (fp == NULL) {
        perror("Failed to open file \"problem11.txt\"");
        return EXIT_FAILURE;
    }
    
    for (i = 0; (fscanf(fp, "%d", &rc)) != EOF; i++)
    {
        grid[i/cols][i%cols] = rc;
    }

    fclose(fp);
    return 0;
}


//long long int ops
bool isEvenL(long long int num)
{
    return num%2 == 0;
}

int isFactorL(long long int i, long long int num)
{
    return num%i == 0;
}

int isPrimeL(long long int num)
{
    long long int i = sqrt(num);
    
    if(num == 1) return false;

    while(i>0)
    {
        if (isFactorL(i, num))
            break;
        i--;  
    }
    return i==1;
}

long long int squareSums(int max)
{
    int i;
    long long int curSquare=0;
    
    for(i=1; i<=max; i++){
        curSquare += i;
    }
    return curSquare*curSquare;
}

long long int sumPrimes(int max)
{
    int i, j, maxj, count;
    int bound = (max/log(max))*(1 + 1.2762/log(max));
    long long int sum;
    int primes[bound];
    
    // insert 2 into primes[]
    primes[0] = 2;
    sum = 2;
    count = 1;

    i = 3;
    while(i<max)
    {
        j = 0;
        maxj = sqrt(i);
        
        //is prime[j] a factor of i
        while(j<count)
        {
            if (primes[j] > maxj)
            {
                j = count;
                break;
            }
            if(isFactor(primes[j],i))
            {
                break;
            }
            j++;
        }
        if(j==count)
        {
            primes[count] = i;
            sum += i;
            count++;
        }
        i += 2;
     }
    
    return sum;
}

long long int sumSquares(int max)
{
    int i;
    long long int curSum=0;
    
    for(i=1; i<=max; i++){
        curSum += i*i;
    }
    return curSum;
}


//matrix ops
int prodDagUp(int** pos, int r, int c, int num)
{
    int i;
    int prod = 1;
    
    for(i=0; i<num; i++)
        prod *= pos[r-i][c+i];
    return prod;
}

int prodForward(int** pos, int r, int c, int num)
{
    int i;
    int prod = 1;
    
    for(i=0; i<num; i++)
        prod *= pos[r][c+i];    
    return prod;
}

int prodDagDown(int** pos, int r, int c, int num)
{
    int i;
    int prod = 1;
    
    for(i=0; i<num; i++)
        prod *= pos[r+i][c+i];    
    return prod;
}

int prodDown(int** pos, int r, int c, int num)
{
    int i;
    int prod = 1;
    
    for(i=0; i<num; i++)
        prod *= pos[r+i][c];    
    return prod;
}

int maxProd(int ** grid, int rows, int cols, int num)
{
    int row, col, rbegin, rend, cend, curprod, maxprod;
    
    rbegin = num-2;
    rend = rows-num+1;
    cend = cols-num+1;
    
    maxprod = 0;    
    for(row=0; row<rows; row++)
    {
        for(col=0; col<cols; col++)
        {
            if(row>rbegin && col < cend)
            {
                if( (curprod = prodDagUp(grid, row, col, num)) > maxprod)
                    maxprod = curprod;
            }
            if(col < cend)
            {
                if( (curprod = prodForward(grid, row, col, num)) > maxprod)
                    maxprod = curprod;
            }
            if(row<rend && col < cend)
            {
                if( (curprod = prodDagDown(grid, row, col, num)) > maxprod)
                    maxprod = curprod;
            }
            if(row<rend)
            {
                if( (curprod = prodDown(grid, row, col, num)) > maxprod)
                    maxprod = curprod;
            }
        }
    }
    return maxprod;
}
int sumDigits(int** grid, int* sum, int rows, int cols, int digits)
{
    int r,c, digit, carry, cbegin, cend, rend;
    
    digit = digits-1;
    carry = 0;
    cend = cols-1;
    cbegin = cend-digits;
    
    for(c=cend; c>cbegin; c--)
    {
        carry += sumDown(grid, 0, c, rows);
        sum[digit--] = carry%10;
        carry /= 10;
    }
    
    return carry;
}
int sumDown(int** pos, int r, int c, int num)
{
    int i;
    int prod = 0;
    
    for(i=0; i<num; i++)
        prod += pos[r+i][c];    
    return prod;
}


//print ops
void printBufDigits(int* buf, int begin, int end)
{
    int i;
    
    for(i=begin; i<end; i++)
    {
        printf("%d", buf[i]);
    }
    printf("\n");
}
void printGridDigits(int** pos, int rows, int cols)
{
    int r,c;
    
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            printf("%d", pos[r][c]);
        }
        printf("\n");
    }
}
void printGridInts(int** pos, int rows, int cols)
{
    int r,c;
    
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            if(pos[r][c]<10)
                printf("%d  ", pos[r][c]);
            else
                printf("%d ", pos[r][c]);
        }
        printf("\n");
    }
}

//Pythagorean Triplet ops
bool checkSumSquare(int a, int b, int c)
{
    return a*a+b*b == c*c;
}

bool checkSum(int a, int b, int c, int sum)
{
    return a+b+c == sum;
}

int calcProd(int a, int b, int c)
{
    return a*b*c;
}

//string ops
bool isPalindrome(char* pal)
{
    int len = strlen(pal)-1;
    char revpal[len+1];
    int i = 0;
    
    while(i <= len)
        revpal[i] = pal[len-i++];
    return strcmp(pal,revpal) == 0;
}


