#include<iostream>
using namespace std;

//累加寻找根，属于数字根函数的子函数
int find_root(int n){
	int digital[10];
	int i,j,sum=0;

	for(i=0;n!=0;i++,n/=10)
		digital[i]=n%10;
	for(j=0;j<i;j++)
		sum=sum+digital[j];

	return sum;
}

//确定数字根
int sure_root(int m){
	while(m>=10)
		m=find_root(m);
	return m;
}

//寻找数字根分别为1~9时情况并打印出来
void specific_number(int a[9][9]){
    int n,i,j;
    char specific_a[9][9];
    for(n=1;n<=9;n++){          //数字根的范围是1~9
        cout<<"When the digital root is "<<n<<", the shape as follow:"<<endl;
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                if(a[i][j]==n)
                    specific_a[i][j]='*';
                else
                    specific_a[i][j]=' ';
        for(i=0;i<9;i++){
            for(j=0;j<9;j++)
                cout<<specific_a[i][j]<<" ";
            cout<<endl;
        }
    cout<<endl;
    }

}

int main(){
    int nul_table[9][9],root_table[9][9];
    int i,j;

    //9*9乘法表初始化
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            nul_table[i][j]=(i+1)*(j+1);

    //原始数字根表格的初始化和打印
    cout<<"The Vedic square as follow:"<<endl;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            root_table[i][j]=sure_root(nul_table[i][j]);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
            cout<<root_table[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;
    specific_number(root_table);

    return 0;
}
