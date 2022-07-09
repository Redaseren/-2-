/*本题要求实现一个函数，计算下列简单交错幂级数的部分和*/
#include<stdio.h>
int getSign(int n) {
	if (n % 2 == 0)
		return -1;
	else return 1;
}

/*非递归算法*/
double fn1(double x, int n) {
	double result = 0;
	int sign=getSign(n); /*记录符号*/
	for (int i = 0; i < n; i++) {
		result = x * result + sign;
		sign *= -1;
	}
	return x*result;
}

/*递归算法*/
double fn2(double x, int n) {
	if (n = 1) return 0;
	return x * (fn2(x, n - 1)+getSign(n));
}

int main() {
	return 0;
}