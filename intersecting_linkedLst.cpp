#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//kumar.venkatraman@oracle.com

 
/*
class LinkedList {
public:
    int data;
    LinkedList* next;
};
*/

typedef struct NODE {

    int data;
    NODE* next;
}LinkedList;



//typedef struct Node LinkedList;


LinkedList * GetNode(int a);
void PrintNode(LinkedList* Head);

LinkedList * Append(LinkedList* head,LinkedList* node);

LinkedList * DeleteLlastNode(LinkedList* head);
LinkedList * FindIntersectingNode(LinkedList* Head1,LinkedList* head2);
                     
// To execute C++, please define "int main()"
int main() {
  
  
    // Addition of new nodes
    LinkedList* head1=GetNode(3);
    Append(head1,GetNode(7));
   
    LinkedList* head2=GetNode(99);
    Append(head2,GetNode(1));
  
   //common list
   LinkedList* head3=GetNode(8);
   Append(head3,GetNode(10));
   
  
   Append(head1,head3);
   Append(head2,head3);
  
   PrintNode(head1);
  
    PrintNode(head2);
  
  
LinkedList *node=NULL;
node  = FindIntersectingNode(head1,head2);
if (node)
{  cout<<"\nIntersecting Node :"<<node->data<<endl;

}
  else
{  cout<<"\nno. Intersecting Node "<<endl;
}

  return 0;
}


LinkedList* DeleteLlastNode(LinkedList* head){
   LinkedList* t=head;
   LinkedList* prev=NULL;
  
   while(t->next){
     prev=t;
   t=t->next;
   }
  cout <<endl;
  delete(t);
  prev->next=NULL;
  return head;
}


void PrintNode(LinkedList* head){
   LinkedList* t=head;
   while(t){
     cout<<t->data <<" ";
   t=t->next;
   }
  cout <<endl;
}

LinkedList * GetNode(int a){
  LinkedList*   newNode = new LinkedList;
  newNode->data=a;
  newNode->next=NULL;
  
  return newNode;
}


LinkedList * Append(LinkedList* head,LinkedList* node){
 LinkedList* t=head;
 while(t->next){
   t=t->next;
   }
  t->next=node;
  
  return head;
}



LinkedList * FindIntersectingNode(LinkedList* head1,LinkedList* head2)
{
  LinkedList* temp1;
  LinkedList* temp2;
  temp1=head1;
  temp2=head2;
  set<LinkedList*> s;
  while(temp1)
  {
  
     
    s.insert(temp1);
    temp1=temp1->next;  
  }
  
  while(temp2)
  {
       
    if(s.find(temp2) != s.end()){
      return temp2;
    }
    temp2=temp2->next;
      
  }
  return NULL;
  
  }

