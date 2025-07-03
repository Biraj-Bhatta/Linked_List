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
void AtFirst(struct node **tail, int data)
{
    struct node *temp = createnode(data);
    if (*tail == NULL)
    {
        *tail = temp;
        (*tail)->next = *tail;
    }
    else
    {
        temp->next = (*tail)->next;
        (*tail)->next = temp;
    }
}
void AtLast(struct node **tail, int data)
{
    struct node *temp = createnode(data);
    if (*tail == NULL)
    {
        *tail = temp;
        temp->next = *tail;
    }
    else
    {
        temp->next = (*tail)->next;
        (*tail)->next = temp;
        *tail = temp;
    }
}
void AtNth(struct node **tail, int data)
{
    int pos;
    printf("Enter position to insert node: ");
    scanf("%d", &pos);
    struct node *newnode = createnode(data);
    struct node *temp = (*tail)->next;
    for (int i = 1; i < (pos - 1); i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void DeleteFirst(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is empty.\n\n");
    }
    else
    {
        struct node *temp = (*tail)->next;
        (*tail)->next = temp->next;
        free(temp);
    }
}
void DeleteLast(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    struct node *temp = (*tail)->next;
    if (temp == *tail)
    {
        free(temp);
        *tail = NULL;
        return;
    }
    while (temp->next != *tail)
    {
        temp = temp->next;
    }
    struct node *Lastnode = *tail;
    temp->next = (*tail)->next;
    free(Lastnode);
    *tail = temp;
}
void DeleteNth(struct node **tail)
{
    int pos;
    struct node *temp = (*tail)->next;
    if (*tail == NULL)
    {
        printf("The list is empty. \n\n");
        return;
    }
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        if (temp == *tail)
        {
            free(temp);
            *tail = NULL;
        }
        else
        {
            (*tail)->next = temp->next;
            free(temp);
        }
        printf("The node at position %d is removed.\n\n", pos);
        return;
    }
    for (int i = 1; i < (pos - 1); i++)
    {
        temp = temp->next;
    }
    struct node *temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
}
void Search(struct node **tail, int search)
{
    struct node *temp = (*tail)->next;
    do
    {
        if (temp->data == search)
        {
            printf("The searched data is found.\n\n");
            return;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != *tail);
    printf("The searched data is not found.\n\n");
}
void display(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    struct node *temp = (*tail)->next;
    do
    {
        printf("%d ---> ", temp->data);
        temp = temp->next;
    } while (temp != (*tail)->next);
    printf("Beigning \n\n");
}
int main()
{
    int data, choice;
    struct node *tail = NULL;
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
            AtFirst(&tail, data);
            break;
        case 2:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtNth(&tail, data);
            break;
        case 3:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtLast(&tail, data);
            break;
        case 4:
            DeleteFirst(&tail);
            break;
        case 5:
            DeleteNth(&tail);
            break;
        case 6:
            DeleteLast(&tail);
            break;
        case 7:
            printf("Enter data to be searched: ");
            scanf("%d", &data);
            Search(&tail, data);
            break;
        case 8:
            display(&tail);
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid Choice.\n\n ");
            break;
        }
    } while (1);
    return 0;
}