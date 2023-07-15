/***************************************************
 * @file LinkedList.c
 * @author Ajit Singh
 * @date 2022-08-04
 ***************************************************/

#include <stdio.h>
#include "../headers/LinkedList.h";

/**
 *  << HELPER FUNCTION >>
 *
 * @brief Given a head node and a text of characters, this function
 * will iterate over the list and display them. This function will
 * also use the text param given to display title.
 *
 * @param head
 * @param text
 */
void printList(ListItem *head, char text[])
{

    printf("\n#%s\n", text);
    ListItem *pointer = head;

    while (pointer != null)
    {
        printf("%d-", pointer->item_num);
        pointer = pointer->next;
    }
    printf("\n");
}

/**
 * @brief Given a head node and an item node, then this function
 * will iterate to the end of the list and insert the node at the
 * end.
 *
 * @param head
 * @param item
 * @return int
 */
int insert_last(ListItem *head, ListItem *item)
{

    // Declaration
    ListItem *currentNode = head;

    // Iterate over the list
    while (currentNode != null)
    {
        // if the current node's next value is null
        if (currentNode->next == null)
        {
            // then the new node is added here
            currentNode->next = item;
            currentNode = currentNode->next;
            return 1;
        }

        // Update node's position
        currentNode = currentNode->next;
    }
    return 0;
}

/**
 * @brief Given a head node, node to be inserted and a n (value of an existing node),
 * then this function looks for that node. Once the node has been found, the node to be
 * inserted is added after the n given node.
 *
 * @param list_head
 * @param insertItem
 * @param n
 * @return int
 */
int insert_after(ListItem *list_head, ListItem *insertItem, int n)
{

    // Declaration
    ListItem *current_node = list_head;

    // Iterate while the current node is not null
    while (current_node != null)
    {
        // If the node's next value is null (end of list) and there has been no match
        // with any the n value given, then display error message and return 0
        if (current_node->next == null && current_node->item_num != n)
        {
            printf("\n[ITEM %d NOT FOUND]\n", n);
            return 0;
        }

        // If the value (item_num) of the node is equal to n
        // then do the referencing and return 1
        if (current_node->item_num == n)
        {
            // The links of nodes are being updated
            insertItem->next = current_node->next;
            current_node->next = insertItem;
            return 1;
        }

        // Update node's position
        current_node = current_node->next;
    }

    return 0;
}

/**
 * @brief Given a head node and a node to be inserted, this function will
 * find the given node and remove it if and only if it exists. If the node
 * does not exist, it will return 0 and an error message.
 *
 * @param list_head
 * @param insertItem
 * @return int
 */
int remove_item(ListItem *list_head, ListItem *insertItem)
{

    // Declaration
    ListItem *current_node = list_head;
    ListItem *tracker_node = list_head->next;

    // Match for head of root
    if (list_head->item_num == insertItem->item_num)
    {
        current_node->next = tracker_node->next;
        return 1;
    }

    // Iterate of the nodes
    while (tracker_node != null)
    {
        // If the tracker node (1 step ahead of current node) is equal
        // to the given node
        if (tracker_node->item_num == insertItem->item_num)
        {
            // the given node is removed
            current_node->next = tracker_node->next;
            return 1;
        }

        // If the tracker node has reached the end (null) and did not match
        // with any of the nodes in the list, then 0 is returned and an error message
        // is displayed
        if (tracker_node->next == null && tracker_node->item_num != insertItem->item_num)
        {
            printf("\n[ITEM %d NOT FOUND]\n", insertItem->item_num);
            return 0;
        }

        // Update nodes position
        tracker_node = tracker_node->next;
        current_node = current_node->next;
    }

    return 0;
}
