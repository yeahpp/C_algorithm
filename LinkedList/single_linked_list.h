#include <stdio.h>
#include <stdlib.h>


typedef struct data_t{
    int id;
    int score;
}data;


typedef struct nodeSLL_t{
    data data;
    struct nodeSLL_t* next;
}nodeSLL;
