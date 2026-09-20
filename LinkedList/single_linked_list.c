// 단일 연결 리스트

#include <stdio.h>
#include <stdlib.h>

//      init()         → 리스트(head) 생성

//     Create_SLL()    → 새로운 노드 생성
//     Append_SLL()    → 생성된 노드를 리스트에 연결 (뒤에서 삽입)

//     Delete_SLL()    → 마지막 노드 삭제 (뒤에서 삭제)
//     Print_SLL()     → 리스트 출력

//     destroy_SLL()   → 리스트 전체 메모리 해제

typedef struct SLL {
    int data;
    struct SLL* next;
} SLL;

void init(SLL** head)
{
    (*head) = malloc(sizeof(SLL));
    if (*head == NULL)
        exit(1);
    (*head)->data = 0;
    (*head)->next = NULL;
}

SLL* Create_SLL()
{
    int a;
    scanf("%d", &a);
    SLL* newnode = malloc(sizeof(SLL));
    if (newnode == NULL)
        exit(1);
    newnode->data = a;
    newnode->next = NULL;
    return newnode;
}

void Append_SLL(SLL* head, SLL* newnode)
{
    SLL* curr = head;
    for (; curr->next != NULL; curr = curr->next)
        ;
    curr->next = newnode;
}

void Delete_SLL(SLL* head)
{
    if (head->next == NULL)
        return; // head가 아무것도 연결하고 있지 않을 때
    SLL* curr = head;
    for (; curr->next->next != NULL; curr = curr->next)
        ;
    SLL* del = curr->next;
    free(del);
    curr->next = NULL;
}

void Print_SLL(SLL* head)
{
    SLL* curr = head->next;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void destroy_SLL(SLL** head)
{
    SLL* curr = (*head)->next;
    while (curr != NULL) {
        SLL* nextNode = curr->next;
        free(curr);

        curr = nextNode;
    }
    free(*head);
    (*head) = NULL;
}
int main()
{
    int input;
    SLL* head = NULL;
    init(&head);
    while (1) {
        printf("1.삽입 2.삭제 3.출력\n");
        scanf("%d", &input);
        switch (input) {
        case 1: {
            SLL* newnode = Create_SLL();
            Append_SLL(head, newnode);
            break;
        }
        case 2:
            Delete_SLL(head);
            break;
        case 3:
            Print_SLL(head);
            break;
        case -1:
            destroy_SLL(&head);
            return 0;
        default:
            break;
        }
    }

    return 0;
}
