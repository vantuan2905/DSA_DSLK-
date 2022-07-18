#include<iostream>
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
		a=create(x);return;
	}
	if(a->d<x) them(a->r,x);
	if(a->d>x) them(a->l,x);
}
void del(node* &a,int x){
	if(a==NULL) return;
	if(a->d>x) del(a->l,x);
	else{
		if(a->d<x) del(a->r,x);
		else{
			if(a->l==NULL) a=a->r;
			else{
				if(a->r==NULL)  a=a->l;
				else{
					node* X=a;
					while(X->l!=NULL) X=X->l;
					a->d=X->d;
					X=X->r;					
				}
			}
		}
	}
}
void in(node* a){
	if(a!=NULL){
		cout<<a->d<<" ";
		in(a->l);
		in(a->r);
	}
}
main(){
	int t;
	int n,xx;
	node * a=NULL;cin>>n;
	for(int i=1;i<=n;i++){ cin>>xx;them(a,xx);}
	while(t--||1){
		cout<<"1.xoa node\n";
		int vt;
		cin>>vt;
		del(a,vt);
		if(vt==-1){ in(a);cout<<endl;}
	}
}
