#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isStack = true, isQueue = true, isPQ = true;
        for(int i = 0; i < n; i++){
            int type, x;
            cin >> type >> x;
            if(type == 1){
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else{
                if(s.empty() || s.top() != x) isStack = false;
                if(q.empty() || q.front() != x) isQueue = false;
                if(pq.empty() || pq.top() != x) isPQ = false;
                if(!s.empty()) s.pop();
                if(!q.empty()) q.pop();
                if(!pq.empty()) pq.pop();
            }
        }
        if(isStack && !isQueue && !isPQ) cout << "stack" << endl;
        else if(!isStack && isQueue && !isPQ) cout << "queue" << endl;
        else if(!isStack && !isQueue && isPQ) cout << "priority queue" << endl;
        else if(!isStack && !isQueue && !isPQ) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }
}
