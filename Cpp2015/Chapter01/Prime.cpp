#include<iostream>
#include<cmath>
using namespace std;

bool Prime(int n){
    int i,sqrtn;
	bool prime=true;

	sqrtn=sqrt(n);
	for(i=2;i<=sqrtn;i++){
		prime=n%i;
		if(!prime){
			cout<<n<<" isn't a prime."<<endl;
			break;
		}
	}

    return prime;
}

int main(){
	int n;
	bool judge;

	cout<<"Please input n(n>=2):";
	cin>>n;

	judge=Prime(n);

	if(judge)
		cout<<n<<" is a prime."<<endl;

    return 0;
}
