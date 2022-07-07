#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* node;
node makenode(int x){
	node t=new Node();
	t->data=x;
	t->next=NULL;
	return t;
}
void back(node &a,int x){
	node p=a,t=makenode(x);
	if(a==NULL){ a=t;return;}
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=t;
}
main(){
	int n;map<int,int> ok;
	node head=NULL;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		back(head,a);
	}
	node tmp=head;head=NULL;
	for(int i=0;i<n;i++,tmp=tmp->next){
		if(ok[tmp->data]==0){
			back(head,tmp->data);ok[tmp->data]=1;
		}
	}
	for(head;head!=NULL;head=head->next){
		cout<<head->data<<" ";
	}
}
