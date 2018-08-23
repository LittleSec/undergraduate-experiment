#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdexcept>
#include<cassert>
#include"Shape.h"
#include"Rectangle.h"
#include"RightTriangle.h"
#include"Circle.h"
#include"Square.h"
#include"Array.h"
using namespace std;

bool operator > (Shape& Shape1, Shape& Shape2){
    if(Shape1.getCircumference() > Shape2.getCircumference())
        return true;
    else
        return false;
}

//辅助函数：交换x和y的值
template <class T>
void mySwap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

//用选择法对数组a的n个元素进行排序
//template <class T>
void selectionSort( Array<Shape*> &a, int n ) {
	for (int i = 0; i < n - 1; i++) {
		int leastIndex = i;	//最小元素之下标初值设为i
		for (int j = i + 1; j < n; j++)	//在元素a[i + 1]..a[n - 1]中逐个比较显出最小值
			if (*(a[j]) > *(a[leastIndex]))	//smallIndex始终记录当前找到的最小值的下标
				leastIndex = j;
		mySwap(a[i], a[leastIndex]);	//将这一趟找到的最小元素与a[i]交换
	}
}

class FileNotFoundException: public logic_error{
    public:
        FileNotFoundException(const string& what_arg):logic_error (what_arg){};
};

void func()throw(FileNotFoundException){
    cout << "Throw FileNotFoundException in func()" << endl;
    throw FileNotFoundException("exception thrown by func()");
}

int main(){
    int j = 0;
    Array<Shape*>s(10);
    char n1[]="1.Circle   radius=3,  price:4.0 ";
    char n2[]="2.Rectangle  length=3, width=3, price:2.0 ";
    char n3[]="3.RightTriangle  leg1=3, leg2=3, price:3.5 ";
    char n4[]="4.Square  side=3,  price:1.5 ";

    ofstream file("Shapes.txt");
	file << n1 << n2 << n3 << n4;
    file.close();

    ifstream file5("Shapes.txt");
	try{
        if(file5==NULL)
            func();
	}catch(logic_error &e){
        cout << "Caught an exception:" << e.what() << endl;
	}

    s[0] = new Circle(3.0);
    s[1] = new Rectangle(3.0, 3.0);
    s[2] = new RightTriangle(3.0, 3.0);
    s[3] = new Square(3.0);

    selectionSort(s, 4);
    for(j = 0; j < 4; j++)
        s[j]->print();

    cout<<endl;

    ofstream file1("Circle.dat",ios_base ::out|ios_base::binary);
    file1.write(n1,sizeof(n1));
    file1.close();

    ifstream file11("Circle.dat",ios_base ::in|ios_base::binary);
    file11.read(n1,sizeof(n1));
    cout<<n1<<endl;
    file11.close();


    ofstream file2("Rectangle.dat",ios_base ::out|ios_base::binary);
    file2.write(n2,sizeof(n2));
    file2.close();

    ifstream file22("Rectangle.dat",ios_base ::in|ios_base::binary);
    file22.read(n2,sizeof(n2));
    file22.close();
    cout<<"2.Rectangle  length=3, width=3, price:2.0 "<<endl;


    ofstream file3("RightTriangle.dat",ios_base ::out|ios_base::binary);
    file3.write(n3,sizeof(n3));
    file3.close();

    ifstream file33("RightTriangle.dat",ios_base ::in|ios_base::binary);
    file33.read(n3,sizeof(n3));
    file33.close();
    cout<<"3.RightTriangle  leg1=3, leg2=3, price:3.5 "<<endl;


    ofstream file4("Square.dat",ios_base ::out|ios_base::binary);
    file4.write(/*reinterpret_cast<char *>(&*/n4,sizeof(n4));
    file4.close();

    ifstream file44("Square.dat",ios_base ::in|ios_base::binary);
    file44.read(/*reinterpret_cast<char*>(&*/n4,sizeof(n4));
    file44.close();
    cout<<"4.Square  side=3,  price:1.5 "<<endl;

    return 0;
}
