#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node * create(int data)
{
	struct node *new;
	new = (struct node *) malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}
struct node * createTree(struct node *root)
{
	int n, x;
	struct node *new, *temp, *prev=NULL;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	while(n--)
	{
		printf("Enter the element : ");
		scanf("%d", &x);
		new = create(x);

		if(root==NULL)
		{
			root=new;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			prev=temp;
			if(temp->data < new->data)
				temp=temp->right;
			else
				temp=temp->left;
		}
		if(prev->data < new->data)
			prev->right=new;
		else
			prev->left=new;
		
	}
	return root;
}
void inOrder(struct node *root)
{
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}
void preOrder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(struct node *root)
{
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}
void search(struct node *root, int key)
{
	struct node *temp = root;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->data == key)
			{
				flag=1;
				return;
			}
		else if(temp->data < key)
			temp=temp->right;
		else 
			temp=temp->left;
	}
	if(flag)
		printf("FOUND!\n");
	else
		printf("NOT FOUND!\n");

}
int main()
{
	struct node *root;
	root=NULL;
	int i, x, key;
	while(1)
	{
		printf("BST Operations\n");
		printf("1.create\n2.inorder\n3.preorder\n4.postorder\n5.exit\n");
		printf("Enter your choice : ");
		scanf("%d", &i);
		switch(i)
		{
			case 1 : root = createTree(root);
					 break;
			case 2 : inOrder(root);
					 break;
			case 3 : preOrder(root);
					 break;
			case 4 : postOrder(root);
					 break;
			case 5 : printf("Enter the element to search : ");
					 scanf("%d", &key);
					 search(root, key);
				     break;
			case 6 : return 0;
		}
	}	
}