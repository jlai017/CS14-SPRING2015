#ifndef LAB3_H
#define LAB3_H
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> Entry;
void preCoPrime(int m, int n, int k)
{
    if(m + n < k)
    {
        cout << m << ' ' << n << endl;
        preCoPrime(2*m - n, m, k);
        preCoPrime(2*m + n, m, k);
        preCoPrime(m + 2*n, n, k);
    }
    else
        return;
}
void printPre(int k)
{
    cout << "pre-order" << endl;
    preCoPrime(2, 1, k);
    preCoPrime(3, 1, k);
}
void postCoPrime(int m, int n, int k)
{
    if(m + n < k)
    {
        postCoPrime(2*m - n, m, k);
        postCoPrime(2*m + n, m, k);
        postCoPrime(m + 2*n, n, k);
        cout << m << ' ' << n << endl;
    }
    else
        return;
}
void printPost(int k)
{
    cout << "post-order" << endl;
    postCoPrime(2, 1, k);
    postCoPrime(3, 1, k);
}
struct compare 
{
    bool operator()(Entry a, Entry b) const
    {
        return a > b;
    }
};
void orderCoPrime(int m, int n, int k, priority_queue<Entry, vector<Entry>, compare> &a)
{
    if(m + n < k)
    {
        Entry one(m, n);
        a.push(one);
        orderCoPrime(2*m - n, m, k, a);
        orderCoPrime(2*m + n, m, k, a);
        orderCoPrime(m + 2*n, n, k, a);
    }
    else
        return;
}
void orderCoPrimePrint(int k)
{
     priority_queue<Entry, vector<Entry>, compare> a;
     orderCoPrime(2, 1, k, a);
     orderCoPrime(3, 1, k, a);
     
     cout << "sorted" << endl;
     for(unsigned i = 0; i < a.size(); i++)
     {
         cout << a.top().first << ' ' << a.top().second << endl;
         a.pop();
     }
}


#endif