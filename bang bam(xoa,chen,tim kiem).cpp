#include<bits/stdc++.h>
using namespace std;
#define m 11
struct node{
	int data;
	node* next;
};
void in(node* h[]);
int hash(int key){
	return key%m;
}
node* createnode(int key){
	node* t=new node();
	t->data=key;
	t->next=NULL;
	return t;
}
void init_hash(node* hash_table[]){
	for(int i=0;i<m;i++) hash_table[i]=NULL;	
}
void insert(node* hash_table[],int key){
	int ind=hash(key);node* t=createnode(key);
	if(hash_table[ind]==NULL){
		hash_table[ind]=t;
	}
	else{
		node* truoc=NULL,*sau=hash_table[ind];
		while(sau!=NULL&&sau->data<key){
			truoc=sau;
			sau=sau->next;
		}
		if(truoc==NULL){
			t->next=sau;
			sau=t;return;
		}
		truoc->next=t;
		t->next=sau;
	}
	//in(hash_table);
}
int search(node* head[],int key){
	for(int i=0;i<m;i++){
		if(head[i]==NULL){
			continue;
		}
		node* t=head[i];
		//cout<<t->data;
		while(t!=NULL){
			//cout<<t->data<<" ";
			if(t->data==key) return 1;
			t=t->next;
		}
	//	cout<<endl;
	}
	return 0;
}
void in(node* head[]){
	for(int i=0;i<m;i++){
		cout<<i<<": ";
		node* t=head[i];
		while(t!=NULL){
			cout<<t->data<<" ";t=t->next;
		}
		cout<<endl;
	}
}
void del(node* head[],int key){
	if(search(head,key)){
		int ind=hash(key);
		node* truoc=NULL,*sau=head[ind];
		while(sau->next!=NULL&&sau->data!=key){
			truoc=sau;
			sau=sau->next;
		}
		if(truoc==NULL){
			head[ind]=sau->next;
			return;
		}
		truoc->next=sau->next;return;
	}
}
main(){
	node* h[m];
	init_hash(h);
	insert(h,10);
	insert(h,11);
	insert(h,33);
	insert(h,22);
	insert(h,20);//cout<<endl<<"  "<<"lan 1";
	insert(h,32);//cout<<endl<<"  "<<"lan 2";
	insert(h,54);
	in(h);
	del(h,10);
	in(h);
	cout<<endl;
	del(h,20);del(h,11);del(h,22);del(h,33);
	in(h);
	int x;
	cin>>x;
}
