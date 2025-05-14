#include <bits/stdc++.h>

using namespace std;

long long solve(int n)
{
     priority_queue<long long, vector<long long>, greater<long long>> pq;
     unordered_set<long long> seen;

     pq.push(1);
     seen.insert(1);

     long long curr = 1;

     for (int i = 0; i < n; ++i)
     {
          curr = pq.top();
          pq.pop();

          for (int factor : {2, 3, 5})
          {
               long long next = curr * factor;
               if (!seen.count(next))
               {
                    pq.push(next);
                    seen.insert(next);
               }
          }
     }

     return curr;
}

int main()
{
     int n;
     cin >> n;
     cout << solve(n);
     return 0;
}