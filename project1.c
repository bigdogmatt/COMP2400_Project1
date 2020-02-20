/*******************************
 *
 *  Project Name: Project 1: Check the Mathematics
 *  Description: A set of functions that returns different sequences
 *  File names: project1.c
 *  Date: 01/31/2020
 *  Authors: Matt Kleman, Bryce Hessler
 *
 *******************************/

# include <stdio.h>

int lazyCaterer();
int prime();
int fib();
int collatz();
int happy();

int main()
/*
This main function calls all the sequence methods
below it and formats the output accordingly
*/
{
    printf("Lazy Caterer's Sequence:\n");
    lazyCaterer();
    printf("\n");
    printf("Prime Numbers:\n");
    prime();
    printf("\n");
    printf("Fibonacci Sequence:\n");
    fib();
    printf("\n");
    printf("Collatz Stopping Times:\n");
    collatz();
    printf("\n");
    printf("Happy Numbers:\n");
    happy();
}

int lazyCaterer()
/*
This function prints out the first 50 elements in
the lazy caterer's sequence.
*/
{
  int n; //variable to keep track of the current value
  int pieces; //variable to store the number of pieces
  for(n = 0; n < 50; n++)
  /*
  calculates and prints all the lazy caterer values from
  n = 0 to n = 50.
  */
  {
    pieces = ((n*n) + n + 2)/2; //equation for number of pieces
    if(n == 0)
    {
      printf("%d", pieces);
    }
    else
    {
      printf(" %d", pieces);
    }

  }
  printf("\n");
  return 0;
}

int prime()
/*
This function prints out the first 50 prime numbers.
*/
{
  int i = 2; //variable to keep track of current value
  int j; //variable for for loop
  int counter = 1; //variable to keep track of the number of primes so far
  int prime; //variable to break out of for loop if i is not prime

  while(counter <= 50)
  /*
  while loop that continues to run until counter is greater than
  or equal to 50.
  */
  {
    prime = 1; //assume the current value is prime
    for(j = 2; j < i; j++)
    /*
    for loop that mods each value by all the numbers
    from 2 up to itself (not including)
    */
    {
      if(i%j == 0)
      //if the current value mod j is 0 then the value is not prime
      {
        prime = 0; //set prime to 0
		break; //break out of for loop
      }
    }
    if(prime == 1)
    /*
    if prime is 1 after the for loop terminates then
    we made it through all the values without i%j equaling
    0 which means the number is prime. Add one to counter
    and print the prime number.
    */
    {
      if(counter == 1)
      {
        printf("%d", i);
        counter++;
      }
      else
      {
        printf(" %d", i);
        counter++;
      }
    }
    i++; //move to next value
  }
  printf("\n");
  return 0;
}

int fib()
/*
This function prints out the first 50 elements in
the Fibonacci sequence.
*/
{
  long long x0 = 1; //initialize the first two numbers in the sequence
  long long x1 = 1;
  long long x; //variable to store the next value
  int i; //variable for the for loop
  printf("%lld", x0); //print the first two values
  printf(" %lld", x1);
  for(i = 2; i < 50; i++)
  /*
  loop that runs from 2 to 50 (not including) becuase
  we already printed the first to fib values
  */
  {
    x = x0 + x1; //get the next number
    x0 = x1; //set the first number equal to the second
    x1 = x; //set the second number equal to the new value
    printf(" %lld", x); //print the new value
  }
  printf("\n");
  return 0;
}

int collatz()
/*
This function prints out the amount of steps in the
Collatz sequence for the first 50 numbers (1-50).
*/
{
  int i, counter, num; //initalize variable to use below

  for(i = 1; i <= 50; i++)
  /*
  for loop that runs from 1 to 50 (inclusive) that keeps
  track of the number of steps in the Collatz sequence from
  1 to 50 (inclusive).
  */
  {
    counter = 0; //number of steps
    num = i; //current value
    while(num != 1)
    /*
    while loop that continues to run until we reach 1
    which is the end of the sequence.
    */
    {
      if(num%2 == 0)
      //if the number is even then we divide by 2
      {
        num = num/2;
      }
      else
      //if odd, multiply by 3 and add 1
      {
        num = (num*3) + 1;
      }
      counter++;
      //increase the counter becuase a step happens every iteration
    }
    //print out the number of steps
    if(i == 1)
    {
      printf("%d", counter);
    }
    else
    {
      printf(" %d", counter);
    }
  }
  printf("\n");
  return 0;
}

int happy()
/*
This function prints out the first 50 happy numbers.
*/
{
  int num = 1; //current number starting at 1
  int counter = 0; //keep track of the number if happy numbers
  int total = 0; //variable for use below (adding all the digits)
  int temp; //temperary variable

  while(counter < 50)
  /*
  while loop that runs while counter is less than
  50. Digits for each number are squared and added
  up until they total value (stored in temp) is
  equal to 1 or 4. If 1, then the initial number is
  a happy number. If 4, then the number is unhappy.
  */
  {
    temp = num; //variable to store the manipulated value
    while(temp != 4 && temp != 1)
    {
      total = 0;
      while(temp != 0)
      /*
      squares each digit of the current value and adds
      then together.
      */
      {
        total += ((temp % 10) * (temp % 10));
        temp = temp / 10;
      }
      temp = total;
    }
    if(temp == 1)
    /*
    if the value of temp at the end is 1 then
    the initial value is happy and we print it
    out and add one to the counter.
    */
    {
      if(counter == 0)
      {
        printf("%d", num);
        counter++;
      }
      else
      {
        printf(" %d", num);
        counter++;
      }
    }
    num++; //move to the next value
  }
  printf("\n");
  return 0;
}
