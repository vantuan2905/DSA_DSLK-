#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* node;
int size(node a){
	int cnt=0;
	while(a!=NULL){
		cnt++;
		a=a->next;
	}
	return cnt;
}
node makenode(int x){
	node tmp=new Node();
	tmp->data=x;
	tmp->next=NULL;
	return tmp;
}
void insertFirst(node &a,int x){
	node tmp=makenode(x);
	if(a==NULL) a=tmp;
	else{
		tmp->next=a;
		a=tmp;
	}
}
void insertLast(node &a,int x){
	node tmp=makenode(x);
	if(a==NULL) a=tmp;
	node p=a;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=tmp;
}
void insertMiddle(node &a,int x,int pos){
	int n=size(a);
	if(pos<=0||pos>n+1) return;
	if(pos==1) insertFirst(a,x);
	else{
		if(pos==n+1) insertLast(a,x);
		else{
			node p=a;
			for(int i=1;i<pos-1;i++) p=p->next;
			node t=makenode(x);
			t->next=p->next;
			p->next=t;
		}
	}
}
void deleteFirst(node &a){
	if(a==NULL) return;
	a=a->next;
}
void deleteLast(node &a){
	node truoc=NULL,sau=a;
	if(a==NULL) return;
	while(sau->next!=NULL){
		truoc=sau;
		sau=sau->next;
	}
	if(truoc==NULL) a=NULL;
	truoc->next=NULL;
}
void deleteMiddle(node &a,int pos){
	int n=size(a);
	if(pos<=0||pos>n) return;
	
	node truoc=NULL,sau=a;
	for(int i=1;i<pos;i++){
		truoc=sau;
		sau=sau->next;
	}
	if(truoc==NULL) deleteLast(a);
	truoc->next=sau->next;
}
void select_sort(node &a){
	node p=a;
	for(p;p->next!=NULL;p=p->next){
		node min=p;
		for(node q=p->next;q!=NULL;q=q->next){
			if(q->data<min->data){
				min=q;
			}
		}
		int t=p->data;p->data=min->data;min->data=t;
	}
	return;
}
void in(node a){
	cout<<"----------------------------\n";
	while(a!=NULL){
		cout<<a->data<<" ";
		a=a->next;
	}
	cout<<endl<<"----------------------------------\n";
}
main(){
	node head=NULL;
	while(1){
		cout<<"1.chen phan tu o dau\n";
		cout<<"2.chen phan tu cuoi\n";
		cout<<"3.chen phan tu o giua\n";
		cout<<"4.xoa phan tu o dau\n";
		cout<<"5.xoa phan tu o cuoi\n";
		cout<<"6.chen phan tu o giua\n";
		cout<<"7.sap xep phan tu \n";
		cout<<"8.in \n";
		cout<<"9.thoat\n";
		int n;
		cin>>n;
		if(n==9) break;
		if(n==1){
			int x;
			cin>>x;
			insertFirst(head,x);
		}
		if(n==2){
			int x;
			cin>>x;
			insertLast(head,x);
		}
		if(n==3){
			int x,vt;
			cin>>x>>vt;
			insertMiddle(head,x,vt);
		}
		if(n==4){
			deleteFirst(head);
		}
		if(n==5){
			deleteLast(head);
		}
		if(n==6){
			int x;
			cin>>x;
			deleteMiddle(head,x);
		}
		if(n==7) select_sort(head);
		if(n==8) in(head);
	}
}
