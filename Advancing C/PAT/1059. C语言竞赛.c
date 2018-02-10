//这道题没什么难度，就是用空间换时间，将参赛者ID作为数组下标，对应位置存选手排名
/*
1059. C语言竞赛(20)

C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2. 其他人将得到巧克力。

给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。

输入格式：
输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。
接下来给出一个正整数K以及K个需要查询的ID。
输出格式：
对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、
或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。
如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。

输入样例：
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/
#include<stdio.h>
#include<math.h>
int isPrime(int a)
{
	int i, b=sqrt(a);
	for(i=2; i<=b; i++)
		if(a%i==0)
			return 0;
	return 1;
}
int main()
{
	int N;
	scanf("%d", &N);
	int i, a[10000]={0}, x;
	for(i=0; i<N; i++){
		scanf("%d", &x);
		a[x] = i+1;
	}
	int K;
	scanf("%d", &K);
	for(i=0; i<K; i++){
		scanf("%d", &x);
		printf("%04d: ", x);//以前做过一道PAT的题用到过%0md
		if(a[x]==0)
			puts("Are you kidding?");
		else if(a[x]==-1)
			puts("Checked");
		else{
			if(a[x]==1)
				puts("Mystery Award");
			else if(isPrime(a[x]))
				puts("Minion");
			else
				puts("Chocolate");
			a[x] = -1;
		}
	}
}
