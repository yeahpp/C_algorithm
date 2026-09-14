#include "double_linked_list.h"

void init_HT(nodeDLL** head, nodeDLL** tail) // main에서 선언한 head와 tail값 자체가 바껴야하기 때문에, 이중포인터로 받은 것
{
    *head = (nodeDLL*)calloc(1, sizeof(nodeDLL));
    if (*head == NULL)
        exit(0);
    *tail = (nodeDLL*)calloc(1, sizeof(nodeDLL));
    if (*tail == NULL) {
        free(*head);
        exit(0);
    }

    (*head)->next = *tail;
    (*tail)->prev = *head;

    (*head)->prev = *tail;
    (*tail)->next = *head; // 원형
}

nodeDLL* Create_nodeDLL(data* data)
{
    nodeDLL* newnode = NULL;
    newnode = (nodeDLL*)calloc(1, sizeof(nodeDLL));
    if (newnode != NULL) {
        newnode->data = *data;
    }
    return newnode;
}
void Between_nodeDLL(nodeDLL* A, nodeDLL* B, nodeDLL* newnode)
{
    A->next = newnode;
    newnode->next = B;
    newnode->prev = A;
    B->prev = newnode;
    return;
}

void Append_nodeDLL(nodeDLL* tail, nodeDLL* newnode)
{
    Between_nodeDLL(tail->prev, tail, newnode);

    // newnode->next = tail;
    // newnode->prev = tail->prev;
    // tail->prev->next = newnode;
    // tail -> prev = newnode;
    return;
}

void InsertAfter(nodeDLL* head, nodeDLL* newnode)
{
    Between_nodeDLL(head, head->next, newnode);

    // newnode-> next = head->next;
    // newnode->prev = head;
    // head->next->prev = newnode;
    // head->next = newnode;
    return;
}

void Print_nodeDLL(nodeDLL* head)
{
    nodeDLL* curr = head->next;
    nodeDLL* tail = head->prev;

    for (; curr != tail; curr = curr->next) {
        printf("%d %d \n", curr->data.id, curr->data.score);
    }
}

void Free_nodeDLL(nodeDLL* head)
{
    nodeDLL* curr = head->next;
    while (curr != head) {
        nodeDLL* nextnode = curr->next;
        free(curr);
        curr = nextnode;
    }
}
int main()
{
    nodeDLL* head = NULL;
    nodeDLL* tail = NULL;
    init_HT(&head, &tail);

    data data = {0};
    int n;
    (void)freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        nodeDLL* newnode = NULL;
        scanf("%d %d", &data.id, &data.score);
        newnode = Create_nodeDLL(&data);
        if (newnode == NULL) {
            Free_nodeDLL(head);
            head = NULL;
            exit(0);
        }
        Append_nodeDLL(tail, newnode); // 새 노드를 맨 뒤에 꽃음 :head -> next는 맨 처음에 삽입한 값임
        // InsertAfter(head, newnode); // 새 노드를 맨 앞에 꽃음 : head -> next는 맨 마지막에 삽입한 값임
    }
    Print_nodeDLL(head);
}
