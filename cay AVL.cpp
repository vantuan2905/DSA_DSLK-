#include<bits/stdc++.h>
using namespace std;
struct node{
	int key;
	node* l,*r;
	int height;
};
node* create(int x){
	node* t=new node();
	t->key=x;
	t->l=t->r=NULL;
	t->height=1;
	return t;
}
int height(node* x){
	if(x==NULL) return 0;
	return x->height;
}
node* rotatel(node* a){
	node* b=a->r;
	a->r=b->l;
	b->l=a;
	a->height=max(height(a->l),height(a->r))+1;
	b->height=max(height(b->l),height(b->r))+1;
	return b;
}
node* rotater(node* a){
	node* b=a->l;
	a->l=b->r;
	b->r=a;
	a->height=max(height(a->l),height(a->r))+1;
	b->height=max(height(b->l),height(b->r))+1;
	return b;
}
int getbal(node* a){
	if(a==NULL) return 0;
	return height(a->l)-height(a->r);
}
node* insert(node* a,int key){
	if(a==NULL){ return create(key);}
	else{
		if(a->key<key){ a->r=insert(a->r,key);}else
		if(a->key>key) a->l=insert(a->l,key);else return a;
	}
	a->height=max(height(a->l),height(a->r))+1;
	int balance=getbal(a);
	if(balance>1&&a->l->key>key){
		return rotater(a);
	}
	if(balance>1&&a->l->key<key){
		a->l=rotatel(a->l);
		return rotater(a);
	}
	if(balance<-1&&a->r->key<key){
		return rotatel(a);
	}
	if(balance<-1&&a->r->key>key){
		a->r=rotater(a->r);
		return rotatel(a);
	}
	return a;
}
void preorder(node* x){
	if(x==NULL) return;
	cout<<x->key<<" ";
	preorder(x->l);preorder(x->r);
}
main(){
	int t;
	cin>>t;
	while(t--){
	int n,x;cin>>n;node* a=NULL;
	for(int i=0;i<n;i++){ cin>>x;a=insert(a,x);}
	cout<<a->key<<endl;}
//	cout<<"hoan thanh\n";
}
