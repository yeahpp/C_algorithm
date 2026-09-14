#include <stdio.h>

// 선형 재귀(Linear Recursion)의 호출·복귀 흐름과 출력 패턴
// -> 즉 재귀 호출을 한번만 함



// 1. 베이스 조건은 1 or 0 으로 수렴해야함,
// 2. 분해 => 자기 자신을 부를 때 f(n-1)
// 3. 조합 
// 리턴을 하면 f(n)을 불러던 곳으로 가서 거기서 해당 함수가 끝날 때 까지 작동 후 return 



// 하나씩 출력하는 곳에서 N의 역할은 경우의 수, 가지 수
int N = 5;
void func1(int L)
{
    printf("%d ",L);
    if(L>=N) return;
    func1(L+1);
}


void func2 (int L)
{
    printf("%d ",N-L+1);
    if(L>=N) return;
    func2(L+1);
}

void func3(int L)
{
    if(L>N) return;
    printf("%d ",L);
    func3(L+1);
    printf("%d ",L);
}

void func4(int L)
{
    if(L>N) return;
    printf("%d ",L);
    func4(L+1);
    printf("%d ", N-L+1);

}

void func5(int L)
{
    printf("%d ", L);
    if(L>=N) return;
    func5(L+1);
    printf("%d ",L);

}

void func6(int L)
{
    if (L > N) return;
    for(int i=1; i<=L; ++i){
         printf("*");
    }
    printf("\n");
    func6(L+1);
}


void stars(int L)
{
    for(int i=0; i<L; ++i){
         printf("*");
    }
     printf("\n");
}


void func7(int L)
{
    if (L > N) return;
    stars(L);
    func7(L+1);
}

int main()
{

    func1(1); // 1 2 3 4 5 
    printf("\n"); 
    func2(1); // 5 4 3 2 1 
    printf("\n");
    func3(1); // 1 2 3 4 5 5 4 3 2 1 
    printf("\n");
    func4(1); // 1 2 3 4 5 1 2 3 4 5 
    printf("\n");
    func5(1); // 1 2 3 4 5 4 3 2 1 
    printf("\n");
    func6(1); //삼각형
    printf("\n"); 
    func7(1);



    return 0;
}