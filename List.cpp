#include <iostream>
#include <stack> 
using namespace std;
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
};
void AddToTail(ListNode** pHead,int value);
void RemoveNode(ListNode** pHead,int value);

int main(int argc,char* argv[]){
	
	int b=5;
	int *a=&b;
	cout<<a<<endl;
	cout<<*a<<endl;
	
	return 0;
}

void AddToTail(ListNode** pHead,int value){
	
	ListNode* pNew=new ListNode();
	pNew->m_nValue=value;
	pNew->m_pNext=NULL;
	if(*pHead==NULL){
		*pHead=pNew;
	}
	else
	{
		ListNode *head =*pHead;
		while(head->m_pNext!=NULL){
			head=head->m_pNext;
		}
		head->m_pNext=pNew; 
	 } 
	
}
void RemoveNode(ListNode** pHead,int value){
	if(pHead==NULL||*pHead==NULL){
		return;
	}
	ListNode* pToBeDeleted=NULL;
	if((*pHead)->m_nValue==value){
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->m_pNext;
		 
	}
	else{
		ListNode *pNode=*pHead;
		while(pNode->m_pNext!=NULL&&pNode->m_pNext->m_nValue!=value)
		pNode=pNode->m_pNext;
		if(pNode->m_pNext!=NULL&&pNode->m_pNext->m_nValue==value){
		 pToBeDeleted=pNode->m_pNext;
		 pNode->m_pNext=pNode->m_pNext->m_pNext; 
	}
	
}
     if(pToBeDeleted!=NULL){
     	delete pToBeDeleted;
     	pToBeDeleted =NULL;
	 }
}
void PrintListReversingly_Iteratively(ListNode* pHead){
	stack<ListNode*> nodes;
	ListNode* pNode=pHead;
	while(pNode!=NULL){
		nodes.push(pNode);
		pNode=pNode->m_pNext;
		
	}
	while(!nodes.empty()){
		pNode=nodes.top();
		printf("%d\t",pNode->m_nValue);
		nodes.pop();
	}
}
void PrintListReversinglu_Iteratively2(ListNode* pHead){
	if(pHead==NULL)
	return;
	if(pHead->m_pNext!=NULL)
	PrintListReversinglu_Iteratively2(pHead->m_pNext);
	printf("%d\t",pHead->m_nValue);
	}


