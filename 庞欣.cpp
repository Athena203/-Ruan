#include<iostream>
#include<iomanip>
using namespace std;
struct Student{
	int number;
	char name[3];
	float score1;
	float score2;
	float sum;
	float ave;
};
int main(){
	Student temp;
	Student array[3];
	cout<<"����3λѧ����ѧ��--����--Ӣ��ɼ�--�����ɼ���"<<endl;
	for(int i=0;i<3;i++){
		cin>>array[i].number>>array[i].name>>array[i].score1>>array[i].score2;
		array[i].sum=array[i].score1+array[i].score2;
		array[i].ave=array[i].sum/2;
	}
	cout<<"ѧ��"<<setw(12)<<"����"<<setw(12)<<"�ܳɼ�"<<setw(12)<<"ƽ����"<<endl;
	for(int j=0;j<2;j++)
		for(int i=0;i<2-j;i++)
			if(array[i].sum<array[i+1].sum)
			{
				temp=array[i];
				array[i]=array[i+1];
				array[i+1]=temp;
			}
	for(int i=0;i<3;i++)
		cout<<array[i].number<<setw(12)<<array[i].name<<setw(12)<<array[i].sum<<setw(12)<<array[i].ave<<endl;
	return 0;
}
