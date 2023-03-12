#include<stdio.h>
#include<string.h>
struct node {
	int data;
	struct node* next;
};
struct node *head=NULL;
struct node* temp;
int main() {
	int ch;
	do {

		printf("\n1.Insert form Begening\n2.insert from end\n3.display\n");
		printf("\nenter your choice:");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				beginsert();
				break;
			case 2:
				endinsert();
				break;
			case 3:
				display();
				break;

		}
	} while(1);
}
void beginsert() {
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) {
		printf("\nOverflow");
	} else {
		printf("\nEnter the data:");
		scanf("%d",&newnode->data);
		if(head==NULL) {
			head=newnode;
			newnode->next=NULL;
		} else {
			newnode->next=head;
			head=newnode;
		}
	}
	printf("\ninserted\n");
}
void endinsert() {
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) {
		printf("\noverflow");
	} else {
		printf("\nEnter the data:");
		scanf("%d",&newnode->data);
		if(head==NULL) {
			head=newnode;
			newnode->next=NULL;
		} else {
			temp=head;
			while(temp->next!=NULL) {
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=NULL;

		}
	}
	printf("\ninserted");

}
void display() {
	temp = head;
	printf("\nThe values are : ");
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp=temp->next;
	}

}