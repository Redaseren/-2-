/*����Ҫ��ʵ��һ���������������м򵥽����ݼ����Ĳ��ֺ�*/
#include<stdio.h>
int getSign(int n) {
	if (n % 2 == 0)
		return -1;
	else return 1;
}

/*�ǵݹ��㷨*/
double fn1(double x, int n) {
	double result = 0;
	int sign=getSign(n); /*��¼����*/
	for (int i = 0; i < n; i++) {
		result = x * result + sign;
		sign *= -1;
	}
	return x*result;
}

/*�ݹ��㷨*/
double fn2(double x, int n) {
	if (n = 1) return 0;
	return x * (fn2(x, n - 1)+getSign(n));
}

int main() {
	return 0;
}