//scanf("%s")后一定要getchar()!!!
/*
1067. 试密码(20)

当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。

输入格式：
输入在第一行给出一个密码（长度不超过20的、不包含空格、Tab、回车的非空字符串）和一个正整数N（<= 10），分别是正确的密码和系统允许尝试的次数。
随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个#字符时，输入结束，并且这一行不是用户的输入。
输出格式：
对用户的每个输入，如果是正确的密码且尝试次数不超过N，则在一行中输出“Welcome in”，并结束程序；如果是错误的，
则在一行中按格式输出“Wrong password: 用户输入的错误密码”；当错误尝试达到N次时，再输出一行“Account locked”，并结束程序。

输入样例1：
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#
输出样例1：
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
输入样例2：
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
输出样例2：
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char c1[30], c2[100], c3[]="#";
	int N;
	scanf("%s%d", c1, &N);
	getchar();//这个getchar害了我半天！
	while(N--){
		gets(c2); //c2一定要开大一点
		if(strcmp(c2, c3)==0) break;
		else if(strcmp(c2, c1)==0){
			printf("Welcome in\n");
			break;
		}
		else
			printf("Wrong password: %s\n", c2);
	}
	if(N==-1)
		printf("Account locked\n");
}
