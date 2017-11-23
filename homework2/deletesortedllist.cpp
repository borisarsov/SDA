#include <iostream>

using namespace std;
template<class T>
struct elem_link
{
    T data;
    elem_link<T>* link;
};
template <class T>
class LList
{
    elem_link <T> * start,*end,*current;
    void copylist(const LList & );
    void deletelist ();
public :

    LList();
    LList(const LList & other);
    LList & operator=(const LList & other);
    ~LList()
    {
        deletelist();
    }
    void DeleteSortedLinkedList()
    {
        elem_link<T> * p=start;
        elem_link<T> * q;
        T x;
        while(p)
        {
            q=p->link;

            while(q)
            {
                if(q->data==p->data)
                {
                    deleteelem(p);
                }


                q=q->link;
            }
            p=p->link;

        }


    }

    bool empty()const;
    void iterstart(elem_link<T>*p)
    {
        if(p)
        {
            current=p;
        }
        else
            current=start;
    }
    elem_link<T> * iter()
    {
        elem_link<T>*p=current;
       if(current)
       {
           current=current->link;
       }
       return p;
    }
    void toEnd(const T&);
    void insertAfter(elem_link<T> *p,const T&x);
    void insertBefore(elem_link<T>*p,const T &x);
    void deleteAfter(elem_link<T>*p,const T&x);
    void deleteelem(elem_link<T>*p);
    void deleteBefor(elem_link<T>*p,const T&x);
    void print();
    int  length();
    void concat(const LList & other);

};
template<typename T>
LList<T>::LList()
{
    start=end=NULL;
}
template<typename T>
LList<T>& LList<T>::operator=(const LList<T>& other)
{
    if(this!=&other)
    {
        deletelist();
        copy(other);

    }
    return *this;

}
template<typename T>
void LList<T> ::copylist(const LList<T> & other)
{
    start=end =current=NULL;
    elem_link<T>*p=other.start;
    while(p)
    {
        toEnd(p->link);
        p=p->link;

    }

}
template<typename T>
void LList<T>::deletelist()
{
    elem_link<T>*p;
    while(start)
    {
        p=start;
        start=start->link;
        delete p;
    }
    end=NULL;
}
template<typename T>
void LList<T>::toEnd(const T&x)
{
elem_link<T>*q=end;
end=new elem_link<T>;
end->data =x;
end->link=NULL;
if(q)
{
    q->link=end;
}
else
{
    start=end;
}
}
template<typename T>
void LList<T>::insertAfter(elem_link<T>*p,const T &x)
{
    elem_link<T>* q=new elem_link<T>;
    q->data=x;
    q->link=p->link;
    if(p==end)
    {
        end=q;
    }

        p->link=q;



}
template<typename T>
void LList<T>:: insertBefore(elem_link<T>*p,const T &x)
{
    elem_link<T> * q=new elem_link<T>;
   *q=*p;
   if(p==end)
   {
       end=q;
   }
   else
   {
       p->link=q;
       p->data=x;
   }

}
template<typename T>
 void LList<T>:: deleteAfter(elem_link<T>*p,const T&x)
 {
     if(p->link)
     {


     elem_link<T> *q=p->link;
//    x= q->data;
    p->link=q->link;
    if(q==end)
    {
        end=p;
        delete q;
    }
    else
    {
        delete q;
    }


     }

 }
 template <typename T>
 void LList<T> ::deleteelem(elem_link<T>*p)
 {
 if(p==start)
 {

     if(start==end)
     {
         start=end =NULL;

     }
     else
     start=p->link;

     delete p;

 }
else
{
    elem_link <T> * q=start;
    while(q!=p)
    {
        q=q->link;
    }
T x;
    deleteAfter(q,x);
}

 }

 template<typename T>
  void LList<T>::deleteBefor(elem_link<T>*p,const T&x)
  {
if(p==start)
{
    cerr<<"therre is not element to delete"<<endl;
}
else
{
    elem_link<T>*q=start;
    while(q!=p)
    {
        q=q->link;
    }
    deleteelem(q,x);

}
  }
template<typename T>
  void LList<T>:: print()
  {
      elem_link<T>*p=start;
      while(p!=NULL)
      {
          cout <<p->data<<" ";
          p=p->link;
      }
      cout <<endl;
  }
  template<typename T>
 int  LList<T>:: length()
  {
      int n=0;
      elem_link<T>*p=start;
      while(p!=NULL)
      {
          n++;
          p=p->link;
      }
     return n;
  }
  template<typename T>
  void LList<T>::concat(const LList & other)
  {
      elem_link<T> * p=other.start;
      while(p!=NULL)
      {
          toEnd(p->data);
          p=p->link;
      }
  }


int main()
{

LList<int > x;
x.toEnd(1);
x.toEnd(1);
x.toEnd(3);
x.toEnd(3);
x.toEnd(5);
x.toEnd(6);
x.print();
x.DeleteSortedLinkedList();
x.print();

    return 0;
}
