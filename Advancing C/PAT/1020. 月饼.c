//复习了用qsort对结构体排序，是对单价排序
//题目没有明确说明，但库存和总售价是浮点型，用int型会有两个小测试点过不了
/*
1020. 月饼 (25)

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。
现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。
如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
*/
#include<stdio.h>
#include<stdlib.h>

struct yuebing{
	double a, b;//a为库存，b为总售价，刚开始以为是int型，有两个小测试点过不了
	float c;
}*str;
int cmp(void const *x, void const *y)
{
	return (*(struct yuebing*)y).c > (*(struct yuebing*)x).c ;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	str = (struct yuebing*)malloc(n*sizeof(struct yuebing));
	int i;
	for(i=0; i<n; i++){
		scanf("%lf", &str[i].a);
	}
	for(i=0; i<n; i++){
		scanf("%lf", &str[i].b);
		str[i].c = (double)str[i].b/str[i].a;
	}
	qsort(str, n, sizeof(str[0]), cmp);
	float sum = 0;
	for(i=0; m>=str[i].a; i++){
		sum += str[i].b;
		m -= str[i].a;
	}
	sum += (double)m/str[i].a*str[i].b;// * / % 都是左结合
	printf("%.2f", sum);
	return 0;
}
