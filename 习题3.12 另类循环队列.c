/*如果用一个循环数组表示队列，并且只设队列头指针Front，不设尾指针Rear，
而是另设Count记录队列中元素个数。请编写算法实现队列的入队和出队操作。*/
#include<stdio.h>
#include<stdbool.h>
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
    ElementType* Data;  /* 存储元素的数组   */
    Position Front;     /* 队列的头指针     */
    int Count;          /* 队列中元素个数   */
    int MaxSize;        /* 队列最大容量     */
};
typedef PtrToQNode Queue;

/*判断队列是否已满*/
bool IsFull(Queue Q) {
    if (Q->Count == Q->MaxSize)
        return true;
    else return false;
}

/*判断队列是否为空*/
bool IsEmpty(Queue Q) {
    if (Q->Count == 0)
        return true;
    else return false;
}

/*向队列中添加元素*/
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
    /*删除元素后的头结点的位置*/
    Q->Front = (Q->Front +1) / Q->MaxSize;
    Q->Count--;
    return X;
}




int mian() {

	return 0;
}