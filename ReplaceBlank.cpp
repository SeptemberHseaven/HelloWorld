//��ƪ����  �������� 
#include <iostream>
using namespace std;
void ReplaceBlank(char string[],int length);
// 
int main (int argc,char *argv[]){
    char string[30] = "s k d f";
    int i=0;
    ReplaceBlank(string,30);
   // while(string[i]!='/0')
//C++�����ʽ 
	cout<<string<<endl;
	return 0;
} 
void ReplaceBlank(char string[],int length){
	if(string == NULL||length<=0)
	return;
	int ori=0;//�ַ�����ʵ�ʳ���
	int num=0;//�ַ����пո�����
	int i=0;
	while(string[i]!='\0'){
		++ori;
		if(string[i]==' ')
		  ++num;
		++i;  
	} 
	int newLength = ori+2*num;
	if(newLength>length)
	  return;
	int indexO=ori;
	int indexN=newLength;
	while(indexO>=0&&indexN>=indexO)
	{
		if(string[indexO]==' ')
		   {
		   	string[indexN--]='0';
		   	string[indexN--]='2';
		   	string[indexN--]='%';
		   }
		 else{
		 	 string[indexN--]=string[indexO];  
		 }
		 --indexO;
		
	}
   
	return;
}
