#include<iostream>
using namespace std;
class Smallcat{
	public:
		Smallcat(double w);//声明构造函数
		static void display(Smallcat & w);//静态成员函数 
		static void totaldisp(); //静态成员函数
	private:
	    double weight;//数据成员，表示一只小猫打的重量
		static double totalweight;//静态数据成员，累计小猫的重量
		static double totalnumber;//静态数据成员，累计小猫的只数
		 
}; 
Smallcat::Smallcat(double w)//定义构造函数 
{
	weight = w;
	totalweight+=w;//累计小猫的重量 
	totalnumber++;//累加小猫的只数 
}
void Smallcat::display(Smallcat & w)//定义静态成员函数，将对象的引用，作为参数显示每只小猫的重量 
{

	cout<<"这只小猫的重量是："<<w.weight<<"千克\n";
	 
} 
void Smallcat::totaldisp()//定义静态成员函数，显示这是小猫的只数和总重量
{
cout<<totalnumber<<"只小猫的总重量是："; 
cout<<totalweight<<"千克"<<endl; 
 } 
 double Smallcat::totalweight=0;
 double Smallcat::totalnumber=0;//静态数据成员初始化 
 int main()
 {
 	
 	Smallcat w1(5),w2(6),w3(4);
 	Smallcat::display(w1);//调用静态成员函数，显示小猫的重量 
 	Smallcat::display(w2);
 	Smallcat::display(w3);
 	Smallcat::totaldisp();
 	return 0;
 }
