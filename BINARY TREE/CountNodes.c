#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *Makenode(int a)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void PreOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}

void InOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        InOrderTraversal(t->left);
        printf("%d ", t->data);
        InOrderTraversal(t->right);
    }
}

void PostOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
        printf("%d ", t->data);
    }
}

void CreateNode(struct node** p){
    int choice,x;
    struct node* t;
    printf("whether left of %d exit?(0/1)\n",(*p)->data);
    scanf("%d",&choice);
    if(choice==1){ 
        printf("left Node  data \n"); 
        scanf("%d",&x);
        t= Makenode(x);
        (*p)->left=t;
        CreateNode(&t);
    }

    printf("whether right of %d exit?(0/1)\n",(*p)->data);
    scanf("%d",&choice);
    if(choice==1){  
        printf("Right Node  data");
        scanf("%d",&x);
        t= Makenode(x);
       
        (*p)->right=t;
         CreateNode(&t);
    }
    
}

int CountNodes(struct node** t){
    struct node* p;
    if((*t)==NULL){
        return 0;
    }
    else{
        return 1+CountNodes(&(*t)->left)+CountNodes(&(*t)->right);
    }
    
}

int main()
{
    struct node *root = NULL;
    int x;
    scanf("%d",&x);
    root=Makenode(x);

    CreateNode(&root);

    PreOrderTraversal(root);
    printf("\n");
    InOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
    printf("\n");
    printf("Total Number of nodes in Binary Tress %d\n",CountNodes(&root));

    return 0;
}