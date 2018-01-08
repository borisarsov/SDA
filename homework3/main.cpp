#include <iostream>

using namespace std;
template<typename T>
struct node
{
    T data;
    node<T> * left;
    node<T> * right;
};
template<typename T>
class tree
{
    node<T>* root;
    void copy(node<T> *& pos,node<T> * const & r)
    {
        pos=NULL;
        if(r)
        {
            pos->data=r->data;
            copy(pos->left,r->left);
            copy(pos->right,r->right);
        }
    }
    void copyTree(const tree<T> & other)
    {
        copy(root,other.root);
    }
    void DeleteTree(node<T> * & pos)const
    {
        if(pos)
        {
            DeleteTree(pos->left);
            DeleteTree(pos->right);
            delete pos;
            pos=NULL;
        }
    }
    void pr(const node<T> *p)const
    {
        if(p)
        {

            cout <<p->data<<" ";
              pr(p->left);
            pr(p->right);
        }

    }
    void CreateTree(node<T> *&pos)const
    {
        T x;char c;
        cout <<"root:";
        cin>>x;
        pos=new node<T> ;
        pos->data=x;
        pos->left=NULL;
        pos->right=NULL;
        cout <<"Left tree of "<<x <<" y/n?";
        cin>>c;
        if(c=='y')
        {
            CreateTree(pos->left);
        }
        cout <<"Right tree of " << x <<" y/n";
        cin>>c;
        if(c=='y')
        {
            CreateTree(pos->right);
        }
    }

public:
    void create()
    {
        CreateTree(root);
    }
    void print()const
    {
        pr(root);
        cout <<endl;
    }
    void creatre3(const T & x,const tree<T> & l,const tree <T> & r)
    {
        if(root)
        {
            DeleteTree(root);
        }
        root=new node<T>;
        root->data=x;
        copy(root->left,l);
        copy(root->right,r);

    }
    tree()
    {
        root=NULL;
    }
    tree(const tree<T> & other)
    {
        copyTree(other);
    }
    tree& operator=(const tree<T> & other)
    {
        if(this!=&other)
        {
            DeleteTree(root);
            copyTree(other);
        }
        return * this;

    }
    ~tree()
    {
        DeleteTree(root);
    }
    bool empty()const
    {
        return root==NULL;
    }
    node<T> * getRoot()const
    {
        return root;
    }
    T rootTree()const
    {
        return root->data;
    }
    tree<T> lefttree()const
    {
        tree<T> t;
        copy(t.root,root->left);
        return t;
    }
    tree<T> righttree()const
    {
        tree<T> t;
        copy(t.root,root->right);
        return t;
    }

int height(node<T> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return 1+max(height(root->left),height(root->right));
    }
}

};

int main()
{
    tree<int >t;
    t.create();
   cout <<t.height(t.getRoot())-1;
    return 0;
}
