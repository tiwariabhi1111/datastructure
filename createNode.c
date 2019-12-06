#include<stdio.h> 
#include<stdlib.h> 
 int search =113,rflag=0,flag=0,start=0;
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 
 
int maxDepth(struct node* node) 
{ 
if (node==NULL){ 
	return 0;}
 else
{  
 	int lDepth = maxDepth(node->left); 
	int rDepth = maxDepth(node->right); 
  
 	if (lDepth > rDepth){  
		return(lDepth+1); }
	else {    
	    return(rDepth+1);} 
} 
} 

struct node *root;
struct node *location[100];int count=0,point=0;
 
 //create a new node 
 
struct node* newNode(int data) 
{  int flag=0;
	if(start==0)
	{
	  	root = (struct node*)malloc(sizeof(struct node)); 
	  	root->data=data;
	  	root->left=NULL;
	  	root->right=NULL;
	  	location[count]=root;
        start=1;
}
else{
    if(location[point]->left==NULL)
    {
        struct node *m=(struct node*)malloc(sizeof(struct node));
        m->data=data;
        m->left=NULL;
        m->right=NULL;
        location[point]->left=m;
        count++;
        location[count]=m;
        printf("node:%d element :%d ",location[point]->data,data);

     
    }
    else
    {
        if(location[point]->right==NULL)
        {
            struct node *m=(struct node*)malloc(sizeof(struct node));
        m->data=data;
        m->left=NULL;
        m->right=NULL;
        count++;
        location[count]=m;
        location[point]->right=m;
        printf("and :%d\n",data);
        
        point++;
            
        }
    }
    
    
}

	
	 
} 
	
int main() 
{
    int n,i,data;
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
	     scanf("%d",&data);
	     newNode(data);
	 }
	
	printf("\nHeight of tree is %d", maxDepth(root)); 
	
	getchar(); 
	return 0; 
} 

