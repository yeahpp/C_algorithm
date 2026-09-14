#include <stdio.h>


int N;
int arr[10];
int used[10];

void print_arr(int *arr)
{
    for(int i=1; i<=N; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void fun1(int L)
{
    if(N<L) {print_arr(arr); return;}
    
    for(int i=1; i<=N; ++i)
    {
        arr[L]=i-1;
        fun1(L+1);
    }
}

void fun2(int L)
{
    if(N<L) {print_arr(arr); return;}
    
    for(int i=1; i<=3; ++i)
    {
        arr[L]=i;
        fun2(L+1);
    }
}
void fun3(int L)
{
    if(N<L){
        print_arr(arr);
        return;
    }

    for(int i=1; i<=3; ++i)
    {
        if(used[i]==1) continue;
        arr[L]=i;
        used[i]=1;
        fun3(L+1);
        used[i]=0;
        
    }
}

void func4(int L, int sum)
{
    if(sum>10) return;

    if(L>N) {
        if(sum == 10) print_arr(arr);
        return;
        }
    for(int i=1; i<=6; ++i)
    {
        arr[L] = i;
        
        func4(L+1, i+sum);
    }
}

void func5(int L,int K)
{
    if(N<L)
    {
        print_arr(arr); return;
    }

    for(int i=K; i<6; i++){

        arr[L] = i+1;
        func5(L+1, i+1);
    }
}
int main()
{   
    N=3;
    
    fun1(1);
    printf("\n");
    fun2(1);
    printf("\n");
    fun3(1);
    printf("\n");
    func4(1,0);
    printf("\n");
    func5(1,0);

}