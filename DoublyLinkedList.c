#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = (NULL);
    return newnode;
}
void AtFirst(struct node **head, int data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        newnode->prev = NULL;
        (*head)->prev = newnode;
        *head = newnode;
    }
}
void AtNth(struct node **head, int data)
{
    struct node *newnode = createnode(data);
    struct node *temp = *head;
    int pos;
    printf("Enter position to insert a node: ");
    scanf("%d", &pos);
    for (int i = 1; i < (pos - 1); i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}
void AtLast(struct node **head, int data)
{
    struct node *temp = *head;
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        *head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }
}
void DeleteFirst(struct node **head)
{
    struct node *temp = *head;
    if ((*head) == NULL)
    {
        printf("The link doesn't exist. \n\n");
    }
    else
    {
        *head = temp->next;
        free(temp);
    }
}
void DeleteAtLast(struct node **head)
{
    if (*head == NULL)
    {
        printf("The link doesn't exist. \n\n");
        return;
    }
    struct node *temp = *head;
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}
void DeleteAtNth(struct node **head)
{
    struct node *temp = *head;
    int pos;
    printf("Enter the position of data to delete: ");
    scanf("%d", &pos);
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void Search(struct node **head, int search)
{
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        if (temp->data == search)
        {
            printf("The searched data is found. \n\n");
            return;
        }
        temp = temp->next;
    }
    printf("The searched data is not found. \n\n");
}
void display(struct node **head)
{
    struct node *temp = *head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
    }
    while (temp != NULL)
    {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}
int main()
{
    int choice, data;
    struct node *head = NULL;
    do
    {
        printf("1. Insert at first \n");
        printf("2. Insert at Nth \n");
        printf("3. Insert at last \n");
        printf("4. Delete at first \n");
        printf("5. Delete at Nth \n");
        printf("6. Delete at last \n");
        printf("7.Search element in linked list \n");
        printf("8. Display Linked List \n");
        printf("9. Exit \n\n");
        printf("Enter choice:: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtFirst(&head, data);
            break;
        case 2:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtNth(&head, data);
            break;
        case 3:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtLast(&head, data);
            break;
        case 4:
            DeleteFirst(&head);
            break;
        case 5:
            DeleteAtNth(&head);
            break;
        case 6:
            DeleteAtLast(&head);
            break;
        case 7:
            printf("Enter the data to be searched: ");
            scanf("%d", &data);
            Search(&head, data);
            break;
        case 8:
            display(&head);
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid case.");
            break;
        }
    } while (1);
    return 0;
}