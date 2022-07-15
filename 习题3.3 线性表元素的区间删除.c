/*����һ��˳��洢�����Ա������һ������ɾ������ֵ����min����С��
max��Ԫ�ء�ɾ�������ʣ��Ԫ�ر���˳��洢���������λ�ò��ܸı䡣*/
#include<stdio.h>
#define MAXSIZE 60
typedef int ElementType;


typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

/*���򵥵ķ�������¼����ɾ���Ĳ��ּ���*/
List Delete(List L, ElementType minD, ElementType maxD) {
    int num = 0, i;
    for (i = 0; i <= L->Last; i++) {
        if (L->Data[i] <= minD || L->Data[i] >= maxD) {
            L->Data[num++] = L->Data[i];
        }
    }
    L->Last = num - 1;
    return L;
}

/*�ҵ�ֵ����X�ĵ�һ��λ��*/
int FindP(List L,ElementType X,int start){
    int i;
    for ( i = start; i <=L->Last; i++) {
        if (X < L->Data[i]) break;
    }
    return i;
}

/*�ҵ�ֵС��XԪ�صĵ�һ��λ��*/
int FindPMax(List L, ElementType X, int start) {
    int i;
    for (i = start; i < L->Last; i++) {
        if (X <= L->Data[i]) break;
    }
    return i;
}


List Delete(List L, ElementType minD, ElementType maxD) {
    if (!L || L->Last < 0||minD<=maxD)
        return L;
    int start = FindP(L, minD,0);
    if (start == -1) return L;
    int rear = FindPMax(L, maxD, start);/*�ҵ�����maxDԪ�ص�λ��*/
    if (start > L->Last) {/*����ɾ��Ԫ��*/
        return L;
    }
    if (rear > L->Last) {/*Ԫ��ȫ��С��maxD*/
        L->Last = start - 1;
        return L;
    }

    /*����Ԫ�ؼȴ���minD����С��maxD*/
    int num = rear - start;
    for (int i = rear; i <= L->Last; i++) {
        L->Data[i - num] = L->Data[i];
    }
    L->Last -= num;
    return L;
}



int main() {

	return 0;
}