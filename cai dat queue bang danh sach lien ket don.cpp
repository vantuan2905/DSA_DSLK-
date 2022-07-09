#include<bits/stdc++.h>
using namespace std;
struct kiu{
	int data;
	kiu* next;
};
typedef kiu* qu;
qu makenode(int x){
	qu t=new kiu();
	t->data=x;
	t->next=NULL;
	return t;
}
int size(qu a){
	int cnt=0;
	while(a!=NULL){
		cnt++;a=a->next;
	}
	return cnt;
}
void push(qu &a,int x){
	qu t=makenode(x);
	if(a==NULL) a=t;
	else{
		t->next=a;
		a=t;
	}
}
void pop(qu &a){
	qu truoc=NULL,sau=a;
	while(sau->next!=NULL){
		truoc=sau;sau=sau->next;
	}
	if(truoc==NULL) a=NULL;
	else{
		truoc->next=NULL;
	}
}
int front(qu a){
	while(a->next!=NULL) a=a->next;
	return a->data;
}
main(){
	int n;int a;
	cin>>n;qu h=NULL;
	for(int i=0;i<n;i++){
		cin>>a;
		push(h,a);
	}
	cout<<size(h)<<endl;
	while(size(h)){
		cout<<front(h)<<" ";
		pop(h);
	}
}
