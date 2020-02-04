struct node
{
    int data;
    node *next;
}*head;

int length(node *head)
{
    if(head)
        return  1 + length(head->next);
}
