#include <iostream>

using namespace std;
template<typename T>
struct elem
{
    T data;
    elem * link;
};
template<typename T>
class LQueue
{
    elem<T> * front,*rear;
    bool isemprty()
    {
        return rear==NULL;
    }
public:
LQueue()
{
    front=rear=NULL;
}
void push (const T& x)
{    elem <T> *p=new elem<T>;
p->data=x;
p->link=NULL;
if(rear)
{
    rear->link=p;
    rear=p;
}
else
{
    front=p;
    rear=p;
}

}
T pop()
{
    if(!isemprty())
    {
      T x;
        if(front==rear)
        {
            front =rear=NULL;
        }
        else
        {elem<T> * p=front ;

        front =p->link;
        x=p->data;

        delete p;
        return x;


        }

    }
    else
    {


        cerr<<"queue is empty"<<endl;
        return T();

        }
}
void erase()
{
    while(!isemprty())
    {
        pop();
    }
}
void copy(const LQueue <T>& other)
{
    rear=NULL;
    elem <T>* p=other.front;
   while(p!=NULL)
   {
       push(p->data);
       p=p->link;
   }
}



LQueue(const LQueue<T> & other)
{
    copy(other);

}
LQueue & operator=(const LQueue<T> & other)
{
    if(this!=& other)
    {
        erase();
        copy(other);
    }
    return * this;
}
~LQueue()
{
    erase();
}
void print ()const
{
    elem <T> *p=front;
    while(p!=NULL)
    {
        cout <<p->data<<" ";
        p=p->link;
    }
}
};

int main()
{
LQueue<int> q1;
q1.push(2);
q1.push(3);
q1.push(5);
q1.pop();

LQueue<int > q2=q1;
q2.print();


    return 0;
}
