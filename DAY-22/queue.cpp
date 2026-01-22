#include <iostream>
#include <queue>
using namespace std;

int pop(queue<int>&q)
{
    if(q.empty())  return -1;
    int f=q.front();
    q.pop();
    return f;
}
int getSize(queue<int>&q)
{
    return q.size();
}
int last(queue<int>&q)
{
    if(q.empty())  return -1;
    return q.back();
}
int front(queue<int>&q)
{
    if(q.empty())  return -1;
    return q.front();
}
int main() 
{ 
    queue <int> q; 
    q.push(10); 
    q.push(20);
    q.push(30);
   
    cout<<"\nThe poped element is "<< pop(q);
    cout<<"\nthe size of the queue is "<<getSize(q);
   cout<<"\nthe last element is "<<last(q);
   cout<<"\nThe first element is "<<front(q);
  
    return 0; 
} 