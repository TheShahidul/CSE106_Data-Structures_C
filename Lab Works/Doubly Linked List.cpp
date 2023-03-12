#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node

{
	int data;
	struct Node *previous, *next;

} *head=NULL;

void insertatbeginning(int value) {
	struct Node *newNode;
	newNode = (struct Node*)malloc (sizeof(struct Node));
	newNode -> data = value;
	newNode -> previous = NULL;
	newNode -> next = NULL;
	if(head==NULL)

	{
		newNode->next=NULL;
		head=newNode;
	}

	else {
		newNode->next = head;
		head=newNode;
	}

	printf("\n insertion success");

}

void insertAtEnd(int value) {
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;

	if (head==NULL) {
		newNode->	previous=NULL;
		head=newNode;

	}

	else {
		struct Node *temp=head;
		while (temp->next!=NULL)
			temp = temp -> next;
		temp->next=newNode;
		newNode->previous=temp;
	}
	printf("\n insertion success");

}

void deleteBeginning() {
	if(head==NULL)
		printf("list is empty. delete not possible.");
	else {
		struct Node *temp=head;
		if (temp->previous==temp->next) {
			head=NULL;
			free(temp);

		} else {
			head=temp->next	;
			head->previous=NULL;
			free(temp);
		}

		printf("Deletion success");
	}
}

void display() {
	if (head==NULL)
		printf("list is empty");
	else {
		struct Node *temp=head;
		printf("list elements are\n");
		printf("NULL <---");
		while(temp->next!=NULL) {
			printf("%d ===", temp->data);
			temp=temp->next;

		}
		printf("%d --->NULL", temp->data);

	}
}


int main() {
	int choice1, choice2, value;
	while(1) {
start:
		printf("\n----Menu----");
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n\nenter your choice\n");
		scanf("%d", &choice1);
		switch(choice1) {
			case 1:
				printf("\nenter the value to insert\n");
				scanf("%d", &value);
				while(1) {
					printf("\nselect from the options\n");
					printf("1.at beginning\n2.at end\n3.cancel\n\nenter your choice\n");
					scanf("%d",&choice2);
					switch(choice2) {
						case 1:
							insertatbeginning(value);
							break;
						case 2:
							insertAtEnd(value);
							break;

						default:
							printf("\nPlease select correct insertion option!!\n");

					}

					goto start;

				}

				break;
			case 2:
				while(1) {
					printf("\nselect from following beginning options\n");
					printf("1. at being\n2.cancel\n3.enter choice\n");
					scanf("%d", &choice2);

					switch(choice2) {
						case 1:
							deleteBeginning();
							break;

						default:
							printf("\npls select correct delete option");
					}
					goto start;
				}
				break;



			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;

			default:
				printf("\npls select correct option");

		}
	}
	return 0;
}