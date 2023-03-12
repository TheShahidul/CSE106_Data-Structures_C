#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
	
}

struct node* newnode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if(node==NULL)
	{
		return newnode(key);
	}
	if (node->data>key)
	node->left=insert(node->left,key);
	else if(node->data<key)
	node->right=insert(node->right,key);
	
	return node;
}

void inorder(struct node* root){
(root != NULL) {
inorder(root—>left);
printf("%d \n", root->data);
inorder(root->right);
}
}

void postorder(struct node* root){
if (root != NULL) {
inorder(root—>left);
inorder(root—>right);
printf("%d \n", root->data);
}
}

void preorder(struct node* root){
if (root != NULL) {
printf("%d \n", root->data);
inorder(root—>left);
inorder(root->right);
}
}

int main()
struct node* root=NULL;
root=insert(root,50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);

int ch;
printf("How you want to print the Binary-Tree?\n");
printf("\n1. In-order");
printf("\n2. Pre-order");
printf("\n3. Post-order");
printf("\nEnter your choice:");
scanf("%d",&ch);

switch(ch)
{
	case 1: inorder(root); break;
	case 2: preorder(root); break;
	case 3: postorder(root); break;
}

return 0;

}