// 큐를 연결리스트로 구현
// 큐의 구조는 FIFO 이기 때문에, 단순한 단일 연결리스트로 구현 가능
// 동적할당 한번 (큐 자체는 스택으로 , 실제 데이터들은 동적할당으로 newnode 만들기)
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeQ {
    int r;
    int c;
    struct nodeQ* next;
} nodeQ;

typedef struct queue_t {

    nodeQ* front;
    nodeQ* rear;

} queue_t;

void init(queue_t* q)
{
    nodeQ* dummy = malloc(sizeof(nodeQ)); // 더미를 따로 만들기
    if (dummy == NULL)
        exit(1);

    dummy->next = NULL;
    dummy->r = 0;
    dummy->c = 0;
    q->front = dummy; // front는 항상 더미 헤드를 가리킨다.
    q->rear = dummy;
}

int Enqueue(queue_t* q)
{
    int a, b;
    nodeQ* newnode = calloc(1, sizeof(nodeQ));
    if (newnode == NULL) {
        return 0;
    }
    // 오버플로우가 일어날 수 있는 상황이 있나..?
    scanf("%d %d", &a, &b);
    newnode->r = a;
    newnode->c = b;

    q->rear->next = newnode;
    q->rear = newnode;
    return 1;
}
int Dequeue(queue_t* q, nodeQ* del)
{
    // 삭제할게 없는데 삭제하려고 할때 underflow
    if (q->front->next == NULL)
        return 0;
    nodeQ* old = q->front->next;

    *del = *old; // main에서 가져온 del 값 자체를 바꾸려고 함

    if (q->rear == old) // 삭제하려는 값이 마지막 노드였을 때
        q->rear = q->front;

    q->front->next = old->next;
    free(old);

    return 1;
}

void PrintQ(queue_t* q)
{
    nodeQ* curr = q->front->next;
    while (curr != NULL) {
        printf("%d %d\n", curr->r, curr->c);
        curr = curr->next;
    }
}

void Destroy(queue_t* q)
{
    nodeQ* curr = q->front;
    while (curr != NULL) {
        nodeQ* nodeNext = curr->next;
        free(curr);
        curr = nodeNext;
    }
    q->front = NULL;
    q->rear = NULL;
}
int main()
{
    queue_t queue;
    init(&queue);
    while (1) {
        int input;
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
            nodeQ del;
            int c = Dequeue(&queue, &del);
            if (c == 0) {
                printf("underflow\n");
            } else {
                printf("%d %d 가 삭제 되었습니다.\n ", del.r, del.c);
            }
            break;
        }

        case 3:
            PrintQ(&queue);
            break;
        case -1:
            Destroy(&queue);
            return 0;

        default:
            break;
        }
    }

    return 0;
}
