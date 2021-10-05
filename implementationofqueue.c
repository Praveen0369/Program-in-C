#include <stdio.h>
 #include <stdlib.h>
 struct cnode {
 int data;
 struct cnode *next;
 };
 struct cnode *head = NULL;
 struct cnode * createNode(int data) 
  {
    struct cnode *newnode;
    newnode = (struct cnode *)malloc(sizeof (struct cnode));
    newnode->data = data;
    newnode->next = NULL;
 }
 void enqueue(int data){
     struct cnode*newnode,*temp;
     int tempData;
 if (!head) {
 head = createNode(data);
 head->next = head;
 }
 else{
     newnode = createNode(data);
 temp = head->next;
 head->next = newnode;
 newnode->next = temp;
 tempData = newnode->data;
 newnode->data = head->data;
 head->data = tempData;
 head = newnode;
 }
 }
  void dequeue() {
 struct cnode *temp;
 int tmpdata;
 if (!head) {
 printf("Circular Queue is empty\n");
 return;
 }
 if (head->next == head) {
 free(head);
 head = NULL;
 return;
 }
temp = head->next;
 head->data = temp->data;
 head->next = temp->next;
 free(temp);
 }
 void display() {
 struct cnode *temp = head;
 if (!head) {
 printf("Circular Queue is empty\n");
 return;
 }
 printf("%-3d", head->data);
 temp = temp->next;
 while (temp != head) {
     printf("%-3d", temp->data);
 temp = temp->next;
 }
 printf("\n");
 return;
 }
 int main() {
 int data, ch;
 while (1) {
 printf("1. Enqueue\t2.Dequeue\n");
 printf("3. Display\t4.Exit\n");
 printf("Please enter your choice:");
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 printf("Enter the data to insert:");
 scanf("%d", &data);
 enqueue(data);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 exit(0);
 default:
 printf("Please enter correct option\n");
 break;
 }
 }
 return 0;
 }
