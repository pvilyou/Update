#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;
 
node *create()
{
	node *p;
	int x;
	printf("Nhap gia tri (break: -1): ");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(node*)malloc(sizeof(node));
	p->data=x;
	
	printf("Nhap gia tri ben trai cua %d:\n",x);
	p->left=create();
 
	printf("Nhap gia tri ben phai cua %d:\n",x);
	p->right=create();
	
	return p;
}
 
void inOrder(node* node)
{
    if (node == NULL)
        return;
 
    inOrder(node->left);
 
    printf("%d ", node->data);
 
    inOrder(node->right);
}

void preOrder(node *node)		
{
	if(node!=NULL)
	{
		printf("%d ",node->data);		
		preOrder(node->left);		
		preOrder(node->right);		
	}
	
}

void postOrder(node* node)
{
    if (node == NULL)
        return;
 
    postOrder(node->left);
 
    postOrder(node->right);
 
    printf("%d ", node->data);
}
 
int height(node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void levelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
int main()
{	
	node *root;
	root=create();
	printf("\nIn-order:\n");
	inOrder(root);
	printf("\n");
	printf("\nPre-order:\n");
	preOrder(root);
	printf("\n");
	printf("\nPost-order:\n");
	postOrder(root);
	printf("\n");
	printf("\nLevel-order:\n");
	levelOrder(root);
	printf("\n");
	return 0;
}
