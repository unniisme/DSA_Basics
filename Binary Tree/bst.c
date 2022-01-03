#include <stdio.h>
#include <stdlib.h>

//Binary tree node with pointer to left and right elements as well as parent.
typedef struct node
{
    int item;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

node* ROOT = NULL;

//Search function that returns the node with the given item, returns NULL if that node doesn't exist
node* Search(node* curr, int item)
{
    if(curr == NULL)
    {
        return curr;
    }

    if(curr->item == item)
    {
        return curr;
    }

    if(curr->item < item)
    {
        return Search(curr->right, item);
    }

    else
    {
        return Search(curr->left, item);
    }

    return NULL;
}

//Recursive function to perform insertion
int BinaryTreeInsertion(node* curr, node* add)
{
    if (curr == NULL)
    {
        return 1;
    }

    //If the item to be inserted is greater than a node item, call recursion on the right subtree of that node. If the right subtree doesn't exist, append the item as in that node.
    if (curr->item < add->item)
    {
        if(curr->right == NULL)
        {
            curr->right = add;
            add->parent = curr;
            return 0;
        }

        return BinaryTreeInsertion(curr->right, add);
    }

    //Same case for left subtree
    else
    {
        if(curr->left == NULL)
        {
            curr->left = add;
            add->parent = curr;
            return 0;
        }

        return BinaryTreeInsertion(curr->left, add);
    }
    return 0;
}

//Wrap function to insert node
int Insert(int item)
{
    node* add = (node*)malloc(sizeof(node));
    if(add == NULL)
    {
        return 1;
    }

    add->item = item;
    add->left = NULL;
    add->right = NULL;
    add->parent = NULL;

    if (ROOT == NULL)
    {
        ROOT = add;
        return 0;
    }

    return BinaryTreeInsertion(ROOT, add);

}

//Function for Inorder traversal
void InorderTraversal(node* curr)
{
    if (curr == NULL)
    {
        return;
    }

    InorderTraversal(curr->left);
    printf("%d\n",curr->item);
    InorderTraversal(curr->right);
    return;
}

//Function for Preorder traversal
void PreorderTraversal(node* curr)
{
    if (curr == NULL)
    {
        return;
    }

    printf("%d\n", curr->item);
    PreorderTraversal(curr->left);
    PreorderTraversal(curr->right);
    return;
}

//Function for Postorder traversal
void PostorderTraversal(node* curr)
{
    if (curr == NULL)
    {
        return;
    }

    PostorderTraversal(curr->left);
    PostorderTraversal(curr->right);
    printf("%d\n", curr->item);
    return;
}

//Function to return the predecessor
node* Predecessor(node* target)
{
    if(target == NULL)
    {
        return target;
    }

    node* curr;

    //If the left subtree is present, navigate to it and then to each right subtree of it    
    if(target->left != NULL)
    {
        curr = target->left;

        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr;
    }

    //If left subtree is not present, navigate to parent until the current node is the right subtree of the parent
    else
    {
        curr = target;
        while (curr->parent != NULL)
        {
            if(curr->parent->right == curr)
            {
                return curr->parent;
            }
            curr = curr->parent;
        }     
    }
    return NULL;
}

//Wrap function to print predecessor
void PrintPredecessor(int item)
{
    node* target = Search(ROOT, item);
    if (target == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    node* pred = Predecessor(target);

    if (pred == NULL)
    {
        printf("No predecessor\n");
        return;
    } 

    printf("%d\n", pred->item);
    return;
}

//Function to find successor.
//Identical to Predecessor, simple mirrored
node* Successor(node* target)
{
    if(target == NULL)
    {
        return target;
    }

    node* curr;
    
    if(target->right != NULL)
    {
        curr = target->right;

        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    else
    {
        curr = target;
        while (curr->parent != NULL)
        {
            if(curr->parent->left == curr)
            {
                return curr->parent;
            }
            curr = curr->parent;
        }     
    }
    return NULL;
}

//Successor wrap function
void PrintSuccessor(int item)
{
    node* target = Search(ROOT, item);
    if (target == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    node* succ = Successor(target);

    if (succ == NULL)
    {
        printf("No successor\n");
        return;
    } 

    printf("%d\n", succ->item);
    return;
}

void PrintSearch(int item)
{
    node* result = Search(ROOT, item);
    if (result == NULL)
    {
        printf("Not Found\n");
        return;
    }
    printf("Found\n");
    return;
}


int main()
{
    int input, errorcode;
    while (1)
    {
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                scanf("%d", &input);
                errorcode = Insert(input);
                if(errorcode)
                {
                    printf("Insertion Fail\n");
                }
                break;
            case 2:
                scanf("%d", &input);
                PrintSearch(input);
                break;
            case 3:
                InorderTraversal(ROOT);
                break;
            case 4:
                PreorderTraversal(ROOT);
                break;
            case 5:
                PostorderTraversal(ROOT);
                break;
            case 6:
                scanf("%d", &input);
                PrintPredecessor(input);
                break;
            case 7:
                scanf("%d", &input);
                PrintSuccessor(input);
                break;
            default:
                exit(0);
        }
    }

    return 0;

}