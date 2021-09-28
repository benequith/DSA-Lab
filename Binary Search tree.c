#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};


struct node *insert(struct node *head, int data)
{
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	if(head==NULL)
	{
		head=ptr;
		head->left = NULL;
		head->right = NULL;
	}
	else
	{
		parentptr = NULL;	nodeptr = head;
		while(nodeptr != NULL)
		{
			parentptr = nodeptr;
			if(data < nodeptr->data)
				nodeptr = nodeptr->left;
			else
				nodeptr = nodeptr->right;
		}

        if(data < parentptr->data)
                    parentptr->left = ptr;
                else
                    parentptr->right = ptr;
    }
	return head;
}

struct node *findMax(struct node *head){
    if (head->right == NULL || head == NULL)
          return head;
    else
          return findMax(head->right);
}



struct node *deletetree(struct node *head, int data)
{
	struct node *ptr;
	if(head==NULL)
		printf("\n%d is not present", data);
	else if(data < head->data)
		 head->left =  deletetree(head->left, data);
	else if(data > head->data)
		 head->right = deletetree(head->right, data);
	else
	{
		if(head->left && head->right)
		{
			ptr = findMax(head->left);
			head->data = ptr->data;
			 head->left = deletetree(head->left, ptr->data);
		}
    else
		{
			ptr = head;
			if(head->left==NULL && head->right==NULL)
			{
				 free(ptr);
				 head= NULL;
			}
			else if(head->left!=NULL)
			{
					struct node* temp=head->left;
 					free(head);
                    return temp;
			}
			else
			{
					struct node* temp= head->right;
					free(head);
					return temp;
			}
		}
	}
	return head;
}


struct node *search(struct node * head, int data)
{
    if(head == NULL){
            printf("\nThe key does not exists");
            return head;
        }
    else if (head->data == data)
          return head;
    else
          if (data < head->data)
              return search(head->left, data);
          else
              return search(head->right, data);
}



void inorder(struct node *head)
{
    if(head==NULL)
    {
        printf("\nThe binary tree is empty");
        return;
    }
    if(head->left!= NULL)
        inorder(head->left);
    printf("%d -> ", head->data);
    if (head->right!= NULL)
        inorder(head->right);
}


void preorder(struct node *head)
{
    if (head== NULL)
    {
       printf("\nThe binary tree is empty");
        return;
    }
    printf("%d -> ",head->data);
    if (head->left != NULL)
        preorder(head->left);
    if (head->right!= NULL)
        preorder(head->right);
}


void postorder(struct node *head)
{
    if (head== NULL)
    {
       printf("\nThe binary tree is empty");
        return;
    }
    if (head->left != NULL)
        postorder(head->left);
    if (head->right != NULL)
        postorder(head->right);
    printf("%d -> ", head->data);
}

int main()
{
    int ch,data;
    struct node *head=NULL, *temp=NULL;
    do
    {
        printf("\nMode of operation:\n1. Insert an element into tree\n2. Delete an element from the tree\n3. Search an element \n4.Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("\nEnter the value you want to insert:");
                    scanf("%d",&data);
                    head =insert(head,data);
                    break;
            case 2: printf("\nEnter the value you want to delete:");
                    scanf("%d",&data);
                    if(head==NULL)
                        printf("\nThe tree is empty. Create tree first");
                    else
                        head= deletetree(head,data);
                    break;
            case 3: printf("\nEnter the value you want to search:");
                    scanf("%d",&data);
                    if(head==NULL)
                        printf("\nThe tree is empty");
                    else{
                        temp=search(head,data);
                        if(temp->data==data)
                            printf("The data is found");
                        else
                            printf("The data is not found");
                    }

                    break;
            case 4: inorder(head);
                    break;
            case 5: preorder(head);
                    break;
            case 6: postorder(head);
                    break;
            case 7: free(head);
                    exit(0);
                    break;

            default:printf("Wrong choice, Please enter correct choice");
                    break;
        }
    } while(1);


    return 0;
}
