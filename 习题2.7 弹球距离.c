/*设有一个球从高度为h米的地方落下，碰到地面后又弹到高度为原来p倍的位置，
然后又落下，再弹起，再落下…。请编写函数求初始高度为h的球下落后到基本
停下来（高度小于给定阈值TOL）时在空中所经过的路程总和。*/
#include<stdio.h>
#define TOL 0.01

double dist(double h, double p) {

	double total = h;
	h *= p;
	while (h-TOL>0) {
		total += 2 * h;
		h = p * h;
	}
	return total;
}



int main() {

	return 0;
}