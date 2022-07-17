#include<bits/stdc++.h>
using namespace std;
struct node{
	int d;
	node* l,*r;
};
node* create(int x){
	node* t=new node();
	t->d=x;
	t->l=t->r=NULL;
	return t;
}
void them(node* &a,int x){
	if(a==NULL){
		node* t=create(x);
		a=t;
		return ;
	}else{
		if(a->d>x) them(a->l,x);
		else if(a->d<x) them(a->r,x);
	}	
}
void in(node* a){
	if(a==NULL) return;
	cout<<a->d<<" ";
	in(a->l);
	in(a->r);
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;node* t=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			them(t,x);
		}
		in(t);
		cout<<endl;
	}
}
