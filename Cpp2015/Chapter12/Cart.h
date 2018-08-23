#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED
#include<iostream>
#include<string>
#include<cassert>
#include"Commodity.h"
using namespace std;

class Commodity;

template <class T>
class Cart {                                 // 购物车模板类
public:
    Cart(int N);
    void addItem(T*);                   // 添加一定数量的商品到购物车
    void checkout();                  // 对购物车中的商品进行结算
    void outputInvoice()const;              // 将商品信息输出到显示器
    ~Cart(){delete []space;}
//  void outputFile(...)                   // 将商品信息输出到invoice.txt文本文件 （附加题）
private:
    int N;
    T **space;
    int numCom;
    double money;
};

template <class T>
Cart<T>::Cart(int N){
	space = new T*[N];
	for (int i = 0; i < N; i++)
		space[i] = NULL;
	money = 0;
	this->N = N;
	numCom = 0;
}

template <class T>
void Cart<T>::addItem(T* item){
	for (int i = 0; i < N; i++){
		if(space[i] == NULL){
			space[i] = item ;
			numCom++ ;
			break;
		}
	}
}

template <class T>
void Cart<T>::checkout(){
    for (int i =0; i < N; i++)
        money = money + space[i]->getFinalPrice();
    cout<<"You should pay "<<money<<" yuan!"<<endl;
    money = 0;
}

template <class T>
void Cart<T>::outputInvoice() const{
    for (int i =0; i < N; i++)
        space[i]->showInfo();
}

#endif // CART_H_INCLUDED
