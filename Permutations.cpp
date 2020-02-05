#include<bits/stdc++.h>
using namespace std;
#define max1 200005
#define sz1 10001
#define mod 1000000007
#define moda 421412341324321ll
#define inf 1e18
#define ll long long int
#define debug(x) cout<<#x<<" "<<x<<endl
typedef pair<ll,ll> pr;
#define rte cout<<"Correct";exit(0);
int main(int argv,char** agrc)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fstream cin;
  cin.open(aargc[0],ios::in);//created a object read file data
  vector<string> ans;
  vector<string> in1;
  while(!cin.eof())// loop is running until we reach end of file
  {
    string ch,ch1;
    getline(cin,ch);// used to read one line at a time
    stringstream s(ch);
    string temp;
    while(getline(s,ch1,','))// used to seprate characters in single line
    {
      temp.push_back(ch1[0]);
    }
    in1.push_back(temp);
  }
  ll n=in1.size();
  queue<string> q;
  for(ll i=0;i<in1.size();i++)
  {
    if(i==0)
    {
      for(ll j=0;j<in1[i].size();j++) // intialize queue with first character of each permutation
      {
        string ch;
        ch.push_back(in1[i][j]);
        q.push(ch);
      }
    }
    else
    {
      queue<string> q1;
      while(!q.empty())
      {
        string f=q.front();
        for(ll j=0;j<in1[i].size();j++) // using the permutation which we have already created we are generating new permutation
        {
          f.push_back(in1[i][j]);// adding next element to previously generated queue
          q1.push(f);
          f.pop_back();// moving back to previous state so that we can create another permutation with that string
        }
        q.pop();
      }
      q=q1; // copying content of new queue because now we have generated new permutations
    }
  }
  while(!q.empty()) // printing all genrated permutations
  {
    cout<<q.front();
    if(q.size()>1)
    {
      cout<<", ";
    }
    q.pop();
  }
} 