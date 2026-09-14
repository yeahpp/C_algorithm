#include "single_linked_list.h"


nodeSLL * Create_nodeSLL(data* data) //newnode 생성후 데이터가 저장됨
{
    nodeSLL* newnode = NULL;
    newnode = (nodeSLL*)calloc(1,sizeof(nodeSLL));
    if(newnode != NULL){
         newnode->data = *data;
    }
    return newnode;
   
}

void Append_nodeSLL(nodeSLL* head, nodeSLL* newnode) //head부터 시작해서, curr->next가 NULL인 곳까지 찾고 거기서 이어서 
{
    nodeSLL * curr = head;
    for(; curr->next != NULL; curr = curr->next);
    curr->next = newnode;
    return;
}

void Print_nodeSLL(nodeSLL *head)
{
    nodeSLL * curr = head;
    for(; curr !=NULL; curr = curr->next){ // curr->next !=NULL 이 아니라는 점
        printf("%d %d\n", curr->data.id, curr->data.score);
    }
    return;
}

void Free_nodeSLL(nodeSLL * head)
{
    // if(head == NULL) return;
    // Free_nodeSLL(head->next);
    // free(head);
    nodeSLL * curr = head; //head 부터 free해야하기 때문에 head->next 가 아님
    while (curr!=NULL)
    {
        nodeSLL * next = curr->next;
        free(curr);
        curr = next;
    }
    
    free(head);

    
}

int main()
{
    nodeSLL* head = (nodeSLL*)calloc(1,sizeof(nodeSLL));
    if(head == NULL) exit(0);

    data data = {0};
    int n;
    (void)freopen("data.txt","r",stdin);
    (void)scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        nodeSLL* newnode = NULL;
        (void)scanf("%d %d", &data.id, &data.score);
        newnode = Create_nodeSLL(&data);

        if(newnode==NULL)
        {
            Free_nodeSLL(head);
            head = NULL;
            exit(0);
        }
        Append_nodeSLL(head,newnode);
    }
    Print_nodeSLL(head->next);

   // Free_nodeSLL(head);
   // head = NULL;
    return 0;
}           