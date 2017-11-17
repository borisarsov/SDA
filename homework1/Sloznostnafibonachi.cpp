#include <iostream>

using namespace std;
int fib(int x)
{
if(x==1 ||x==2)
{
    return 1;
}
else
    return fib(x-1)+fib(x-2); //O(n^2)
}
int Fibn(int n)
{
    int F[n];
    F[0]=1;
    F[1]=1;
    for(int i=2;i<=n;i++)
    {
        F[i]=F[i-1]+F[i-2];//O(n)
    }

    return F[n-1];


}

int main()
{

    return 0;
}
