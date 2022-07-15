/*�����һ��ѭ�������ʾ���У�����ֻ�����ͷָ��Front������βָ��Rear��
��������Count��¼������Ԫ�ظ��������д�㷨ʵ�ֶ��е���Ӻͳ��Ӳ�����*/
#include<stdio.h>
#include<stdbool.h>
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
    ElementType* Data;  /* �洢Ԫ�ص�����   */
    Position Front;     /* ���е�ͷָ��     */
    int Count;          /* ������Ԫ�ظ���   */
    int MaxSize;        /* �����������     */
};
typedef PtrToQNode Queue;

/*�ж϶����Ƿ�����*/
bool IsFull(Queue Q) {
    if (Q->Count == Q->MaxSize)
        return true;
    else return false;
}

/*�ж϶����Ƿ�Ϊ��*/
bool IsEmpty(Queue Q) {
    if (Q->Count == 0)
        return true;
    else return false;
}

/*����������Ԫ��*/
bool AddQ(Queue Q, ElementType X)
{
    if (IsFull(Q)) {
        printf("Queue Full");
        return false;
    }

    int rear = (Q->Front + Q->Count) % (Q->MaxSize);
    Q->Data[++rear] = X;
    Q->Count++;
    return true;
}


ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q)) {
        printf("Queue Empty");
        return ERROR;
    }

    ElementType X = Q->Data[Q->Front];
    /*ɾ��Ԫ�غ��ͷ����λ��*/
    Q->Front = (Q->Front +1) / Q->MaxSize;
    Q->Count--;
    return X;
}




int mian() {

	return 0;
}