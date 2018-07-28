//  我用的two pointers的方法
/*
1044 Shopping in Mars (25)（25 分）提问

Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M\$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M\$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M\$15. We may have 3 options:
1. Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).\
Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).\
Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).\
Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.
If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10^5^), the total number of diamonds on the chain, and M (<=10^8^), the amount that the customer has to pay. Then the next line contains N positive numbers D~1~ ... D~N~ (D~i~<=10^3^ for all i=1, ..., N) which are the values of the diamonds. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print "i-j" in a line for each pair of i <= j such that D~i~ + ... + D~j~ = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.
If there is no solution, output "i-j" for pairs of i <= j such that D~i~ + ... + D~j~ > M with (D~i~ + ... + D~j~ - M) minimized. Again all the solutions must be printed in increasing order of i.
It is guaranteed that the total value of diamonds is sufficient to pay the given amount.
Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
Sample Output 1:
1-5
4-6
7-8
11-11
Sample Input 2:
5 13
2 4 5 7 9
Sample Output 2:
2-4
4-5
*/
#include<stdio.h>
#include<malloc.h>

int main()
{
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  int* a = (int*)malloc(sizeof(int)*n);
  int* sum = (int*)malloc(sizeof(int)*(n+1));
  sum[0] = 0;
  for(i=0; i<n; i++){//用sum可以方便的求序列片段之和
    scanf("%d", a+i);
    sum[i+1] = sum[i] + a[i];
  }
  int min = 1<<30;
  for(i=0, j=1; j<=n;){//找到最小的需要付的钱
    if(sum[j]-sum[i]<m)
      j++;
    else{
      if(min>sum[j]-sum[i])
         min = sum[j]-sum[i];
      i++;
    }
  }
  for(i=0, j=1; j<=n;){//再遍历一遍，若等于min就输出
    if(sum[j]-sum[i]<min)
      j++;
    else if(sum[j]-sum[i] == min)
      printf("%d-%d\n", (i++)+1, j++);//不要忘了i++, j++
    else
      i++;
  }
}
