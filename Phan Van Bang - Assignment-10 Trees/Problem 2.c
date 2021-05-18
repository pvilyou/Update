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

static int dem=0;
int demNode(node *node){
    if(node != NULL)
    {
        demNode(node->left);
        dem++;
        demNode(node->right);
    }
    return dem;
}
 
int leafCount(node* node){
  	if(node == NULL)       
    	return 0;
  	if(node->left == NULL && node->right==NULL)      
    	return 1;            
  	else 
    	return leafCount(node->left)+leafCount(node->right);      
}

int height(node* node){
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


int main()
{	
	node *root;
	root=create();
	printf("\nNumber of nodes:\n");
	printf("%d",demNode(root));
	printf("\n");
	printf("\nNumber of leaves:\n");
	printf("%d",leafCount(root));
	printf("\n");
	printf("\nHeight of the tree:\n");
	printf("%d",height(root));
	printf("\n");
	
	return 0;
}
