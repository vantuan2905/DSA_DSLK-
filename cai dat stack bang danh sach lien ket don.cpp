#include<bits/stdc++.h>
using namespace std;
struct stac{
	int data;
	stac* next;
};
typedef stac* st;
st make(int x){
	st t=new stac();
	t->data=x;
	t->next=NULL;
	return t;
}
int empty(st a){
	return a==NULL;
}
int size(st a){
	int cnt=0;
	while(a!=NULL){ 
		cnt++;a=a->next;
	}
	return cnt;
}
void push(st &a,int x){
	st t=make(x);
	if(a==NULL){ a=t;return;}
	t->next=a;
	a=t;
}
void pop(st &a){
	a=a->next;
}
int top(st a){
	return a->data;
}
main(){
	st h=NULL;
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		push(h,a);
	}
	cout<<size(h)<<endl;
	while(size(h)){//cout<<size(h);
		cout<<top(h)<<" ";pop(h);
		
	}
}
