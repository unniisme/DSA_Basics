#include <stdio.h>
#include <stdlib.h>

//Node for expression tree
typedef struct treeNode
{
    char item;
    struct treeNode* right;
    struct treeNode* left;
} tnode;

//Node for Stack
typedef struct stackNode
{
    tnode* leaf;
    struct stackNode *below;
} snode;

snode *STACK = NULL;
tnode *ROOT = NULL;

//Function to return if the stack is empty
int isEmpty()
{
    return STACK==NULL;
}

//Function to return if a given character is a letter
int isLetter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A') && (c<= 'Z'));
}

//Directly Push an expression tree into the stack
void StackDirectPush(tnode* leaf, int *errorcode)
{
    snode *add = (snode*) malloc(sizeof(snode));
    add->leaf = leaf;

    if (isEmpty())
    {
        STACK = add;
        *errorcode = 0;
        return;        
    }

    add->below = STACK;
    STACK = add;
    *errorcode = 0;
    return;
}

//Push a character into the stack by making an unlinked expression tree
void StackPush(int item, int *errorcode)
{
    tnode *leaf = (tnode*) malloc(sizeof(tnode));
    if (leaf == NULL)
    {
        *errorcode = 1;
        return;
    }
    leaf -> item = item;
    leaf -> left = NULL;
    leaf -> right = NULL;

    StackDirectPush(leaf, errorcode);
    return;
}

//Pop last expression tree from stack
tnode* StackPop(int *errorcode)
{
    //If array is empty, set errorcode value
    if(isEmpty())
    {
        *errorcode = 1;
        return 0;        
    }

    snode*temp = STACK;
    STACK = STACK->below;
    tnode* item = temp->leaf; 
    free(temp);
    *errorcode = 0;
    return item;           
}

//Pop the last 3 elements of the stack, make an expression tree out of them and push it back into the stack
int GrowExpressionTree()
{
    int error;

    tnode* root = StackPop(&error);
    if (error)
    {
        return 1;
    }

    tnode* right = StackPop(&error);
    if (error)
    {
        return 1;
    }

    tnode* left = StackPop(&error);
    if (error)
    {
        return 1;
    }

    root -> right = right;
    root -> left = left;

    ROOT = root;

    StackDirectPush(ROOT, &error);
    return error;
}

//Function to take input letter by letter
void LetterInput()
{
    char c;
    int errorcode;
    
    scanf("%c", &c);

    if (c == '\n')
    {
        return;
    }

    //Push that character into the stac
    StackPush(c, &errorcode);

    //if not a letter, make it a node in the expression tree
    if (!isLetter(c))
    {
        GrowExpressionTree();
    }

    return LetterInput();
}

//Function for inorder traversal of the expression tree, with added brackets
void InorderTraverse(tnode* root)
{
    if (root == NULL)
    {
        return;
    }

    if(!isLetter(root -> item))
    {
        printf("(");
    }

    InorderTraverse(root->left);
    printf("%c", root -> item);
    InorderTraverse(root->right);


    if(!isLetter(root -> item))
    {
        printf(")");
    }

    return;
}

//Function for Preorder traversal of the expression tree
void PreorderTraverse(tnode* root)
{
    if (root == NULL)
    {
        return;
    }


    printf("%c", root -> item);
    PreorderTraverse(root->left);
    PreorderTraverse(root->right);

    return;
}

int main()
{
    LetterInput();
    InorderTraverse(ROOT);
    printf("\n");
    PreorderTraverse(ROOT);
    printf("\n");

    return 0;
}
