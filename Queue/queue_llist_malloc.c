// rear+1을 하고 데이터 넣기
// 창훈씨가 만든 리스트를 이용한 큐 코드 수정하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#if 1
typedef struct _nodeQ {
    int r;
    int c;
    struct _nodeQ* next;
} nodeQ;

typedef struct _queue_t {
    nodeQ* front;
    nodeQ* rear;

} queue_t;

void init_Q(queue_t** queue)
{
    *queue = (queue_t*)malloc(sizeof(queue_t));
    if (*queue == NULL)
        exit(1);
    // 더미노드 생성
    nodeQ* dummy = (nodeQ*)malloc(sizeof(nodeQ));
    if (dummy == NULL) {
        free(*queue);
        exit(1);
    }
    dummy->next = NULL;
    (*queue)->front = dummy;
    (*queue)->rear = dummy;

    return;
}

int Enqueue(queue_t* q, nodeQ newdata)
{
    nodeQ* node = (nodeQ*)malloc(sizeof(nodeQ));
    if (node == NULL) {
        printf("Overflow!\n");
        return 0;
    }
    node->r = newdata.r;
    node->c = newdata.c;
    node->next = NULL;

    q->rear->next = node;
    q->rear = node;

    return 1;
}

int Dequeue(queue_t* q, nodeQ** old)
{
    if (q->front->next == NULL) {
        printf("Underflow!\n");
        return 0;
    }
    *old = q->front->next; // q->front 는 더미니까
    q->front->next = (*old)->next;

    // 마지막 노드를 삭제한 거라면
    if (q->rear == *old)
        q->rear = q->front; // rear과 front는 더미를 가리킨다

    return 1;
}

void printQ(queue_t* q)
{
    int i = 0;
    for (nodeQ* p = q->front->next; p != NULL; p = p->next) {
        printf("%d : %d %d\n", i++, p->r, p->c);
    }
}

void free_Q(queue_t** q)
{
    nodeQ* p = (*q)->front;
    while (p != NULL) {
        nodeQ* next = p->next;
        free(p);
        p = next;
    }
    free(*q);
    (*q) = NULL;
}

int main(void)
{
    queue_t* queue = NULL;
    // nodeQ* dummy = NULL;
    char cmd;
    int n, s;
    int r, c;
    int i;

    (void)freopen("qdata.txt", "r", stdin);
    (void)scanf("%d %d", &s, &n);
    init_Q(&queue);

    for (i = 0; i < n; ++i) {
        (void)scanf(" %c", &cmd);
        if (cmd == 'P') {
            (void)scanf("%d %d", &r, &c);
            if (!Enqueue(queue, (nodeQ){r, c, NULL}))
                break; //(nodeQ) { r, c, NULL }
        } else {
            nodeQ* old;
            if (Dequeue(queue, &old) == 0) { // 리턴안하려고 주소보냄
                printf("underflow\n");
                exit(1);
            }
            free(old);
        }
    }
    printQ(queue);
    free_Q(&queue);
    return 0;
}

#endif
