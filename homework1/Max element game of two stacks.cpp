#include <iostream>

using namespace std;
template<typename T>
struct elem
{
    T data;
  elem<T>* link;
};
template<typename T>
class Stek
{
elem<T>* start;
bool isempty()const
{
    return start==NULL;
}
public:
    Stek()
    {
start=NULL;

    }


void push(T  x)
{
    elem <T>* p=new elem<T>;
    p->data=x;
    p->link=start;
    start=p;
}


T pop()
{if(!isempty())
{
    elem<T> * p=new elem<T>;
    T x;
    x=p->data;
    start=start->link;
    delete p;
    return x;




}
    else
    {
        cerr<<"stek is empty"<<endl;
        return T();
    }

}

void copy(elem<T> * other)
{


   if(other==NULL)
   {
       return;
   }

       copy(other->link);
       push(other->data);

}
Stek ( Stek <T> & other)
{
    start=NULL;
    copy(other.start);



}
void erase()
{
while(!isempty())
{
    pop();
}
}
Stek & operator=(const Stek <T> & other)
{
    if(this!=& other)
    {
        erase();
        copy(other);


    }
    return * this;

}

void print()
{
    elem<T>*p=start;
    while(p!=NULL)
    {
        cout <<p->data<<" ";
        p=p->link;
    }
    cout <<endl;
}
~Stek()
{
    erase();
}
void maxelement()
{
    int x;
    cin >>x;
    int n;
    int pu;
   int max=-999;
   Stek <int> st2;


    for(int i=0;i<x;i++)
    {
        cin>>n;
       if(n==1 )
        {
            cin>>pu;
            push(pu);
            if(pu>max)
            {
                max=pu;
            }
        }
        else if(n==2)
        {
            pop();
            if(start==NULL)
            {
                max=-999;
            }
        }
        else if(n==3)
        {
            if(start==NULL)
            {
                cout <<"prazen";
            }
            else
            {
                st2.push(max);
            }

        }




    }
     st2.print();
}
T top()
{
    if(!isempty())
    {
        return start->data;
    }
}
};


int main()
{

Stek<int>st1;
//st1.maxelement();
Stek <unsigned int > s1,s2;
int n,m,x,broinaigrite;
cin>>broinaigrite;
for(int z=0;z<broinaigrite;z++)
{


cin>>n>>m>>x;
unsigned int a,b;
for(int i=0;i<n;i++)
{ cin>>a;
s1.push(a);

}
for(int j=0;j<m;j++)
{

    cin>>b;
    s2.push(b);

}
int sum=0,br=0;
while(sum<x)
{
    if(s1.top()<s2.top())
    {


        sum+=s1.top();

         s1.pop();
         br++;



    }
    else
        if(s1.top()>s2.top())
    {


        sum+=s2.top();

              s2.pop();
                 br++;



    }

}
cout <<br-1;
}


  return 0;
}
