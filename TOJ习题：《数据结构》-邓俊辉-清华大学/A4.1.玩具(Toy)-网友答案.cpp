#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
const int maxn=40321;//���ڴ�������1~8������չ�����������Ϊ8!����40320��
const int fac[8]={1,1,2,6,24,120,720,5040};//����չ�����õ���0~7�Ľ׳�
int ans[maxn]={0};//�洢���׶εĲ���
bool mark[maxn]={0};//��־����������ȷ��״̬�Ƿ���ʹ�
struct Node
{
    int a[8];
    int val;
}s,u,v;//�洢ÿ��״̬�Ľṹ�壬val�������濵��չ���Ĺ�ϣֵ��a[]�����洢״̬
void swap(int &a,int &b)//��������
{
	int temp;
	temp=a;
	a=b;
	b=temp;
 }
int contor(Node &t)//����չ������ÿ��״̬����Ψһ�Ĺ�ϣֵ
{
	int tmp,num=0;
	for(int i=0;i<8;i++)
	{
		tmp=0;
		for(int j=i+1;j<8;j++)
		{
			if(t.a[j]<t.a[i])
				tmp++;
		 }
		num+=tmp*fac[7-i];
	 }
	return num;
 }
void FA(Node &t)// A����,�����н���
{
	for(int i=0;i<4;i++)
        swap(t.a[i],t.a[7-i]);
 }
void FB(Node &t) //B������ÿ��ѭ������һλ����ΪԤ�����Ǵ�12345678������״̬������B����������
{
	int temp=t.a[0];
    for(int i=1;i<=3;i++)
        t.a[i-1]=t.a[i];
    t.a[3]=temp;
    temp=t.a[7];
    for(int i=7;i>4;i--)
        t.a[i]=t.a[i-1];
    t.a[4]=temp;
 }
void FC(Node &t)//C�������м���С����ʱ��תһ����ΪԤ�����Ǵ�12345678������״̬������C����������
{
	int temp=t.a[1];
    t.a[1]=t.a[2];t.a[2]=t.a[5];t.a[5]=t.a[6];
    t.a[6]=temp;
 }
class Queue//���У����Խ��й����������
{
private:
	int size;
	int front;
	int rear;
	Node *base;
public:
	Queue(int init=40321);
	bool empty();
	bool push(Node e);
	bool pop();
	Node getfront();
 };
Queue::Queue(int init)//��ʼ��
{
	size=init;
	base=(Node *)malloc(sizeof(Node)*size);
	front=rear=0;
 }
bool Queue::empty()//�ж϶����Ƿ�Ϊ��
{
	if(front==rear)
		return true;
	else
		return false;
 }
bool Queue::push(Node e)//Ԫ�ؽ������
{
	if((rear+1)%size==front)
	{
		return false;
	 }
	else
	{
		base[rear]=e;
		rear=(rear+1)%size;
		return true;
	 }
 }
bool Queue::pop()//Ԫ�س�����
{
	if(front==rear)
	{
		return false;
	 }
	front=(front+1)%size;
	return true;
 }
Node Queue ::getfront()//��ö����ײ�Ԫ��
{
	return base[front];
 }
void bfs()//���������������Ԥ����
{
	for(int i=0;i<8;i++)//��123458678������״̬
	{
		u.a[i]=i+1;
	 }
	 u.val=contor(u);//��ÿ���չ����ϣֵ
	 Queue que;
	 que.push(u);//��״̬�������
	 mark[u.val]=1;//���ʹ���
	 while(!que.empty())//���в�Ϊ��
	 {
		  u=que.getfront();
		  que.pop();//ÿ�ν�����Ԫ��ȡ��,�ж��������ֱ任״̬�Ƿ��Ѿ����ʹ�,���޷�����������,�����䲽����Ϊ���ײ�����һ��
		  for(int i=0;i<3;i++)
		  {
			  v=u;
			  if(i==0)
			  {
				  FA(v);//���·�ת
				  v.val=contor(v);//����չ��
				  if(mark[v.val]==0)//δ���ʹ�
				  {
					  mark[v.val]=1;//��־Ϊ���ʹ�
					  ans[v.val]=ans[u.val]+1;//�����䲽����Ϊ���ײ�����һ
					  que.push(v);//�������
				   }
			   }
			  else if(i==1)
			  {
				  FB(v);//ѭ����λ
				  v.val=contor(v);
				  if(mark[v.val]==0)
				  {
					  mark[v.val]=1;
					  ans[v.val]=ans[u.val]+1;
					  que.push(v);
				   }
			   }
			  else
			  {
				  FC(v);//�в���Ԫ����ʱ����ת
				  v.val=contor(v);
				  if(mark[v.val]==0)
				  {
					  mark[v.val]=1;
					  ans[v.val]=ans[u.val]+1;
					  que.push(v);
				   }
			   }
		   }
	  }
 }
int main()
{
	bfs();//Ԥ����
	int N,*as;//�洢������ÿ��״̬�Ĳ��������
	scanf("%d",&N);//����ӵ����߸���
	as=(int *)malloc(sizeof(int)*N);
    for(int ii=0;ii<N;ii++)
	{
		for(int j=0;j<8;j++)//����״̬
		{
			scanf("%d",&s.a[j]);
		 }
		as[ii]=ans[contor(s)];//���ز�������
    }
	for(int k=0;k<N;k++)//���
	{
		printf("%d\n",as[k]);
	}
	return 0;
}

