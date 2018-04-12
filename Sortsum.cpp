#include <iostream> 
using namespace std;
void Sortsum(int a[],int b[]);
int main(int argc,char *argv[]){
	int a[20]={1,2,3,4,5,6};
	int b[10]={7,8,9,10,11,12};
	
	Sortsum(a,b);
	for(int i=0;i<12;i++)
	cout<<a[i]<<endl;
	return 0;
}
void Sortsum(int a[],int b[]){
	int length =11;
	int lengtha=5;
	int lengthb=5;
	while(lengthb>=0||lengtha>=0){
		if(lengtha<0)
		  {
		  	 a[length]=b[lengthb];
	  	     lengthb--;
	  	      length--;
		  	  continue;
		  }
		  if(lengthb<0)
		  {
		  	 a[length]=a[lengtha];
	  	     lengtha--;
		  	 length--;
		  	 continue;
		  }
      if(a[lengtha]>b[lengthb]){
      		    	 a[length]=a[lengtha];
                     lengtha--;
	  }
	   else
	        {
			  a[length]=b[lengthb];
	  	      lengthb--;
		  }
		  length--;
}
} 
