/*����һ����Ӹ߶�Ϊh�׵ĵط����£�����������ֵ����߶�Ϊԭ��p����λ�ã�
Ȼ�������£��ٵ��������¡������д�������ʼ�߶�Ϊh��������󵽻���
ͣ�������߶�С�ڸ�����ֵTOL��ʱ�ڿ�����������·���ܺ͡�*/
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