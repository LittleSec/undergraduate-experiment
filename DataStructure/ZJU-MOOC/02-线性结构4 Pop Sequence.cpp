#include<iostream>
#include<stack>

using namespace std;

int M, N, K;

/*
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/

bool isPopSeq(int a[]){
    int n = 1, i = 0, j;
    stack<int>s;
    s.push(n++);

    while(i < N){
        if(s.size() == M && s.top() != a[i])
            return false;
        if(s.size() != 0 && a[i] == s.top()){
            s.pop();
            i++;
        }
        else
            s.push(n++);
    }
    if(s.empty() == true)
        return true;
}

int main(){
    cin >> M >> N >> K;

    int a[K][N];
    for(int i = 0; i < K; i++){
        int j = 0;
        while(j < N)
            cin >> a[i][j++];
    }

    for(int i = 0; i < K; i++){
        if(isPopSeq(a[i]) == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
