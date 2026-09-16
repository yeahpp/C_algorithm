// 원형 큐의 작동 원리는
// 1) front = rear = 0
// 2) 데이터 삽입 시 rear + 1 후 삽입
// 3) 데이터 삭제 시 front + 1 => front 위치는 더미(논리적으로 삭제된 값)
// 4) rear == front -> 공백
// 5) (q->rear + 1 ) % q->size == front => 꽉참
// 6) %size를 하는 이유는 인덱스 번호가 계속 돌기 때문에 마지막 인덱스는 다시 0으로 돌아와야함

#include <stdio.h>
#include <stdlib.h>

typedef struct data_t {
    int r;
    int c;
} data_t;

typedef struct nodeQ_t {
    data_t* data;
    int front;
    int rear;
    int size;
} nodeQ;

void init(nodeQ** queue, int s)
{
    ++s;
    (*queue) = (nodeQ*)malloc(sizeof(nodeQ) + sizeof(data_t) * s);
    if ((*queue) == NULL)
        exit(1);
    (*queue)->data = (data_t*)(*queue + 1);
    (*queue)->front = 0;
    (*queue)->rear = 0;
    (*queue)->size = s;
}

int Enque(nodeQ* queue, data_t* data)
{
    if ((queue->rear + 1) % queue->size == queue->front)
        return 0; // 조건 1) 꽉차있으면 안됨
    queue->rear = (queue->rear + 1) % queue->size;
    queue->data[queue->rear] = *data;
    return 1;
}

int Delqueue(nodeQ* queue, data_t* delnode)
{
    if (queue->front == queue->rear) // 조건 1) 공백이면 안됨
        return 0;
    queue->front = (queue->front + 1) % queue->size; // 먼저 front 이동 그리고 front가 있는 값 삭제 즉 front가 더미가 되는것임
    *delnode = *(queue->data + queue->front);
    // queue->data[queue->front];

    return 1;
}

void PrintQ(nodeQ* q)
{
    int count = (q->rear - q->front + q->size) % q->size;
    for (int k = 1; k <= count; ++k) {
        int i = (q->front + k) % q->size;
        printf("%d %d\n", q->data[i].c, q->data[i].r);
    }
}

int main()
{

    nodeQ* queue = NULL;
    int s, n; // 배열 개수, 명령개수
    char cmd;
    data_t data = {0};

    (void)freopen("qdata.txt", "r", stdin);
    scanf("%d %d", &s, &n);
    init(&queue, s);
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &cmd);
        if (cmd == 'P') {
            scanf("%d %d", &(data.c), &(data.r));
            if (Enque(queue, &data) == 0) {
                printf("Overflow\n");
                exit(1);
            }
        } else { // 삭제

            data_t delnode;
            if (Delqueue(queue, &delnode) == 0) {
                printf("underflow\n");
                exit(1);
            }

            printf("%d %d 삭제했습니다. \n", delnode.c, delnode.r);
        }
    }

    PrintQ(queue);
    free(queue);
    return 0;
}
