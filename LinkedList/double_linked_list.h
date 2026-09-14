#include <stdio.h>
#include <stdlib.h>


typedef struct data_t{
    int id;
    int score;
}data;


typedef struct nodeDLL_t{
    data data;
    struct nodeDLL_t* next;
    struct nodeDLL_t* prev;
}nodeDLL;
