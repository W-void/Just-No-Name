/*
1024 Palindromic Number (25)（25 分）

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a 
palindromic number. All single digit numbers are palindromic numbers.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed 
and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a 
palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 
484.
Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 10^10^) is the initial numer 
and K (<= 100) is the maximum number of steps. The numbers are separated by a space.
Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number 
is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the 
number obtained at the Kth step and K instead.
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
#include<stdio.h>
#include<string.h>

char a[110], b[110] = {0}, c[110] = {0};
void reverse()
{
    int i, len = strlen(a);
    for(i=0; i<len; i++)
        b[len-1-i] = a[i];
    b[len] = 0;
}
void add()
{
    int i, tmp, carry = 0, len = strlen(a);
    for(i=len-1; i>=0; i--){
        tmp = b[i] + a[i] - 2*'0' + carry;
        c[i] = tmp % 10 + '0';
        carry = tmp / 10;
    }
    if(carry){
        for(i=len; i>0; i--)
            c[i] = c[i-1];
        c[0] = '1';
    }
    
    strcpy(a, c);
}
int judge()
{
  int len = strlen(a), i;
  for(i=0; i<len/2; i++)    if(a[i]!=a[len-1-i])
      return 0;
  return 1;
}
int main()
{
    int k, i;
    scanf("%s%d", a, &k);
    for(i=0; i<=k; i++){
        if(judge() || i==k){
            puts(a);
            printf("%d", i);
            return 0;
        }
        reverse();
        add();
    }
  
}
