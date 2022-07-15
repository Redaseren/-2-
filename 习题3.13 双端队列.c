/*˫�˶��У�deque����double-ended queue����д����һ�־��ж��к�ջ���ʵ����ݽṹ��
�����ԣ�Ҳֻ�ܣ������Ա�����˽��в����ɾ��������˳��洢��ʽʵ��˫�˶��У�
���д����ʵ�����в�����
Push(X,D)����Ԫ��X���뵽˫�˶���D��ͷ��
Pop(D)��ɾ��˫�˶���D��ͷԪ�أ������أ�
Inject(X,D)����Ԫ��X���뵽˫�˶���D��β����
Eject(D)��ɾ��˫�˶���D��β��Ԫ�أ������ء�*/

#include<stdio.h>
#include<stdbool.h>
#define ElementType int
#define ERROR - 1

typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
    ElementType* Data;      /* �洢Ԫ�ص�����   */
    Position Front, Rear;   /* ���е�ͷ��βָ�� */
    int MaxSize;            /* �����������     */
};
typedef PtrToQNode Deque;

/*�ж϶����Ƿ�Ϊ��*/
bool IsEmpty(Deque D) {
    if (D->Front==D->Rear) return true;
    else return false;
}

/*�ж϶����Ƿ�����*/
bool IsFull(Deque D) {
    if ((D->Rear + 2) % D->MaxSize == D->Front) return true;
    else return false;
}

/*��Ԫ��X���뵽˫�˶���D��ͷ*/
bool Push(ElementType X, Deque D) {
    if (IsFull(D)) return false;
    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    D->Data[D->Front] = X;
    return true;
}

/*ɾ��˫�˶���D��ͷԪ�أ�������*/
ElementType Pop(Deque D) {
    if (IsEmpty(D))
        return ERROR;
    ElementType date = D->Data[D->Front];
    D->Front = (D->Front + 1) % D->MaxSize;
    return date;
}

/*��Ԫ��X���뵽˫�˶���D��β��*/
bool Inject(ElementType X, Deque D) {
    if (IsFull(D)) return true;
    D->Rear = (D->Rear + 1) % D->MaxSize;
    D->Data[D->Rear] = X;
    return true;
}

/*ɾ��˫�˶���D��β��Ԫ��*/
ElementType Eject(Deque D) {
    if (IsEmpty(D)) return ERROR;
    ElementType X = D->Data[D->Rear];
    D->Data[D->Rear] = ERROR;
    D->Rear = (D->Rear - 1 + D->MaxSize) % D->MaxSize;
    return X;
}


int main() {
	return 0;
}