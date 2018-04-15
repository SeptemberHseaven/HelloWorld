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
	//划分两个数组
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
/*此程序的逻辑 
	ConstructCore(int *start,int* end,int *strat2,int *end2，节点);{
			if(空  或者只剩一个){
		        最终执行接上一个节点 
	                    }
		构建*start为value的节点
		连接到上个节点r 
		检索in数组，分成两份，lstart，lend   rstart，rend
		检索pre数组，分成两份 lstart2，lend2  rstart2，rend2
		左子树：constructCore(lstart,lend,rstart,rend，节点r的左边) ;
		右子树：constructCore(lastar2,...............，节点r右边);
	}
	
	最后返回当时调用时那个参数节点就行。 
	*/
