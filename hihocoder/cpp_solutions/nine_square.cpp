/*
题目1 : 九宫
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi最近在教邻居家的小朋友小学奥数，而最近正好讲述到了三阶幻方这个部分，三阶幻方指的是将1~9不重复的填入一个3*3的矩阵当中，使得每一行、每一列和每一条对角线的和都是相同的。

三阶幻方又被称作九宫格，在小学奥数里有一句非常有名的口诀：“二四为肩，六八为足，左三右七，戴九履一，五居其中”，通过这样的一句口诀就能够非常完美的构造出一个九宫格来。

pic1.png

有意思的是，所有的三阶幻方，都可以通过这样一个九宫格进行若干镜像和旋转操作之后得到。现在小Hi准备将一个三阶幻方（不一定是上图中的那个）中的一些数组抹掉，交给邻居家的小朋友来进行还原，并且希望她能够判断出究竟是不是只有一组解。

而你呢，也被小Hi交付了同样的任务，但是不同的是，你需要写一个程序~

输入
输入仅包含单组测试数据。

每组测试数据为一个3*3的矩阵，其中为0的部分表示被小Hi抹去的部分。

对于100%的数据，满足给出的矩阵至少能还原出一组可行的三阶幻方。

输出
如果仅能还原出一组可行的三阶幻方，则将其输出，否则输出“Too Many”（不包含引号）。

样例输入
0 7 2
0 5 0
0 3 0
样例输出
6 7 2
1 5 9
8 3 4
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int ha[10],ans[10],a[10],flag;
bool use[10];
bool chk(){
	for (int i=0;i<3;i++){
		if (ans[i*3+1]+ans[i*3+2]+ans[i*3+3]!=15) return false;
	}
	for (int i=1;i<=3;i++){
		if (ans[i]+ans[i+3]+ans[i+6]!=15) return false;
	}
	if (ans[1]+ans[5]+ans[9]!=15) return false;
	if (ans[3]+ans[5]+ans[7]!=15) return false;
	return true;
}
void dfs(int cur){
	if (cur>=10){
		if (chk()){
			for (int i=1;i<=9;i++){
				ha[i]=ans[i];
			}
			flag++;
		}
		else {
		    return;
		}
	}
	if (a[cur]){
		ans[cur]=a[cur];
		dfs(cur+1);
	}
	else {
		for (int i=1;i<=9;i++){
			if (!use[i]){
				ans[cur]=i;
				use[i]=1;
				dfs(cur+1);
				use[i]=0;
			}
		}
	}
}
int main(){
	for (int i=1;i<=9;i++){
		scanf("%d",&a[i]);
		use[a[i]]=1;
	}
	dfs(1);
	if (flag==1){
		for (int i=1;i<=9;i++){
			printf("%d",ha[i]);
			if (i==9) continue;
			else if (i % 3==0) printf("\n");
			else printf(" ");
		}
	}
	else {
		printf("Too Many");
	}
}
