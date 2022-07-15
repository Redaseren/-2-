/*双端队列（deque，即double-ended queue的缩写）是一种具有队列和栈性质的数据结构，
即可以（也只能）在线性表的两端进行插入和删除。若以顺序存储方式实现双端队列，
请编写例程实现下列操作：
Push(X,D)：将元素X插入到双端队列D的头；
Pop(D)：删除双端队列D的头元素，并返回；
Inject(X,D)：将元素X插入到双端队列D的尾部；
Eject(D)：删除双端队列D的尾部元素，并返回。*/

#include<stdio.h>
#include<stdbool.h>
#define ElementType int
#define ERROR - 1

typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
    ElementType* Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque;

/*判断队列是否为空*/
bool IsEmpty(Deque D) {
    if (D->Front==D->Rear) return true;
    else return false;
}

/*判断队列是否已满*/
bool IsFull(Deque D) {
    if ((D->Rear + 2) % D->MaxSize == D->Front) return true;
    else return false;
}

/*将元素X插入到双端队列D的头*/
bool Push(ElementType X, Deque D) {
    if (IsFull(D)) return false;
    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    D->Data[D->Front] = X;
    return true;
}

/*删除双端队列D的头元素，并返回*/
ElementType Pop(Deque D) {
    if (IsEmpty(D))
        return ERROR;
    ElementType date = D->Data[D->Front];
    D->Front = (D->Front + 1) % D->MaxSize;
    return date;
}

/*将元素X插入到双端队列D的尾部*/
bool Inject(ElementType X, Deque D) {
    if (IsFull(D)) return true;
    D->Rear = (D->Rear + 1) % D->MaxSize;
    D->Data[D->Rear] = X;
    return true;
}

/*删除双端队列D的尾部元素*/
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