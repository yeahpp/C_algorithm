// 배열을 이용한 원형 큐 만들기
// queue[SIZE] 를 만들고

// 삽입(Enqueue)
//   q[rear]에 데이터를 저장하고
//   rear = (rear + 1) % SIZE 로 이동

// 삭제(Dequeue)
//   q[front]의 데이터를 논리적으로 삭제하고
//   front = (front + 1) % SIZE 로 이동

// Empty : front == rear
// Full  : (rear + 1) % SIZE == front

// Full과 Empty를 구분하기 위해 배열의 한 칸은 항상 비워둔다.
// 따라서 SIZE가 6이면 실제 저장 가능한 데이터는 최대 5개이다.

// Queue q
// ┌─────────────────────────┐
// │ data[SIZE]              │
// │ [][][][][]              │
// │                         │
// │ front = 0               │
// │ rear = 0                │
// └─────────────────────────┘

#include <stdio.h>
#define SIZE 6 // 실제 사용은 5

typedef struct data_t {
    int a;
    int b;

} data_t;

typedef struct nodeQ {
    data_t data[SIZE];
    int front;
    int rear;
} nodeQ;

int Enqueue(nodeQ* q)
{
    int a, b;

    if ((q->rear + 1) % SIZE == q->front)
        return 0;
    scanf("%d %d", &a, &b);

    q->data[q->rear] = (data_t){a, b};
    q->rear = (q->rear + 1) % SIZE;

    return 1;
}

int Dequeue(nodeQ* q, data_t* del)
{

    if (q->rear == q->front)
        return 0;
    *del = q->data[q->front];

    q->front = (q->front + 1) % SIZE;
    return 1;
}

void PrintQ(nodeQ* q)
{
    int i = q->front;

    while (i != q->rear) {
        printf("%d %d\n", q->data[i].a, q->data[i].b);
        i = (i + 1) % SIZE;
    }
}
int main()
{
    nodeQ queue = {0};
    while (1) {
        int input;
        // int size = 5;
        printf("1. 삽입 2. 삭제 3. 출력\n");
        scanf("%d", &input);

        switch (input) {
        case 1: {
            int c = Enqueue(&queue);
            if (c == 0)
                printf("Overflow\n");
            break;
        }
        case 2: {
            data_t del;
            int c = Dequeue(&queue, &del);
            if (c == 0) {
                printf("underflow\n");
            } else {
                printf("%d %d 가 삭제 되었습니다.\n ", del.a, del.b);
            }
            break;
        }

        case 3:
            PrintQ(&queue);
            break;
        case -1:
            return 0;

        default:
            break;
        }
    }

    return 0;
}
