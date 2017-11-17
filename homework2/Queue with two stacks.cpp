#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class QUE
{
    stack<int > helpstack,queuestack;
    public:

        void helptoque()
        {
            while(!helpstack.empty())
            {
                queuestack.push(helpstack.top());
                helpstack.pop();
            }
        }
        void quetohelp()
        {

            while(!queuestack.empty())
            {
                helpstack.push(queuestack.top());
                queuestack.pop();
            }
        }
        int top()
        {
            helptoque();
            return queuestack.top();
        }
        void Enqueue(int x)
        {

        quetohelp();
        helpstack.push(x);

        }
        void Dequeue()
        {
            helptoque();
            queuestack.pop();
        }
        void print()
        {
            helptoque();
            while(!queuestack.empty())
            {
                cout <<queuestack.top()<<" " ;
                queuestack.pop();
            }
        }
};

int main()
{
QUE s;

int n;
cin>>n;
int help,help1;
vector<int> top;
for(int i=0;i<n;i++)
{cin>>help;
if(help==1)
{
    cin>>help1;
    s.Enqueue(help1);
}
else if(help==2)
{
    s.Dequeue();
}
else  if(help==3)
{
    top.push_back(s.top());

}



}
for(int i=0;i<top.size();i++)
{
    cout <<top[i] << " ";
}
    return 0;
}
