#include<iostream>
using namespace std;

struct BinaryNode{
	int value;
	BinaryNode* left;
	BinaryNode* right;
	
};
void ConstructCore(int *start,int *end,int *strat2,int *end2,BinaryNode* root);
int main(int argc,char* argv[]){
	int a[]={1,2,4,7,3,5,6,8};
	int b[]={4,7,2,1,5,3,8,6};
	int *x=a;int *xx=&a[7];
	int *y=b;int *yy=&b[7];
	BinaryNode* root =NULL;
	ConstructCore(x,xx,y,yy,root);
//	cout<<*x<<endl;
	return 0;
}
void ConstructCore(int *start,int *end,int *strat2,int *end2,BinaryNode* root){
	if(start==end){
		BinaryNode *node = new BinaryNode();
		node->value=*start;
		node->left=NULL;
		node->right=NULL;
		root=node;
		return;
	} 

	BinaryNode *node=new BinaryNode();
	node->value=*start;
	node->left=NULL;
	node->right=NULL;
	root=node;
	//������������
	int *i=strat2;
	int count =0;
	while(*i!=*start){
		i++;
		count++;
	} ;
	if(count>0)
	ConstructCore(start+1,start+count,strat2,i-1,node->left) ;
	if(((end-start-1)-count)>0)
	ConstructCore(start+count+1,end,i+1,end2,node->right) ;

   
}
/*�˳�����߼� 
	ConstructCore(int *start,int* end,int *strat2,int *end2���ڵ�);{
			if(��  ����ֻʣһ��){
		        ����ִ�н���һ���ڵ� 
	                    }
		����*startΪvalue�Ľڵ�
		���ӵ��ϸ��ڵ�r 
		����in���飬�ֳ����ݣ�lstart��lend   rstart��rend
		����pre���飬�ֳ����� lstart2��lend2  rstart2��rend2
		��������constructCore(lstart,lend,rstart,rend���ڵ�r�����) ;
		��������constructCore(lastar2,...............���ڵ�r�ұ�);
	}
	
	��󷵻ص�ʱ����ʱ�Ǹ������ڵ���С� 
	*/
