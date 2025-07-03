#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void AtFirst(struct node **head, int data)
{
    struct node *temp = createnode(data);
    temp->next = *head;
    *head = temp;
}
void AtLast(struct node *head, int data)
{
    struct node *newnode = createnode(data);
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void AtNth(struct node **head, int data)
{
    struct node *temp = *head;
    struct node *newnode = createnode(data);
    int position;
    printf("Enter the position of nth place: ");
    scanf("%d", &position);
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("The position doesn't exist. ");
            break;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void DeleteFirst(struct node **head)
{
    if (*head == NULL)
    {
        printf("Void deletion. The list is empty. ");
        exit(1);
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void DeleteNth(struct node **head)
{
    int pos;
    printf("Enter position to delete node: ");
    scanf("%d", &pos);
    struct node *temp1 = *head;
    for (int i = 1; i < (pos - 1); i++)
    {
        temp1 = temp1->next;
    }
    printf("The deleted data is:%d \n", temp1->data);
    struct node *temp = temp1;
    temp = temp->next;
    temp1->next = temp->next;
    free(temp);
}
void DeleteLast(struct node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
void Search(struct node **head, int search)
{
    if (*head == NULL)
    {
        printf("The list is empty. \n\n");
        return;
    }
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
    return;
}
void display(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}
int main()
{
    int choice;
    int data;
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
            printf("Enter data: ");
            scanf("%d", &data);
            AtFirst(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            AtNth(&head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            AtLast(head, data);
            break;
        case 4:
            DeleteFirst(&head);
            break;
        case 5:
            DeleteNth(&head);
            break;
        case 6:
            DeleteLast(&head);
            break;
        case 7:
            printf("Enter data to be searched: ");
            scanf("%d", &data);
            Search(&head, data);
            break;
        case 8:
            display(&head);
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid Input\n");
            break;
        }
    } while (1);
    return 0;
}
