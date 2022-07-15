/*给定一个顺序存储的线性表，请设计一个函数删除所有值大于min而且小于
max的元素。删除后表中剩余元素保持顺序存储，并且相对位置不能改变。*/
#include<stdio.h>
#define MAXSIZE 60
typedef int ElementType;


typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

/*更简单的方法，记录不被删除的部分即可*/
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

/*找到值大于X的第一个位置*/
int FindP(List L,ElementType X,int start){
    int i;
    for ( i = start; i <=L->Last; i++) {
        if (X < L->Data[i]) break;
    }
    return i;
}

/*找到值小于X元素的第一个位置*/
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
    int rear = FindPMax(L, maxD, start);/*找到大于maxD元素的位置*/
    if (start > L->Last) {/*不用删除元素*/
        return L;
    }
    if (rear > L->Last) {/*元素全部小于maxD*/
        L->Last = start - 1;
        return L;
    }

    /*存在元素既大于minD，又小于maxD*/
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