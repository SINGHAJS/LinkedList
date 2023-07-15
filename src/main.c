/***************************************************
 * @file main.c
 * @author Ajit Singh
 * @date 2022-08-04
 ***************************************************/

#include <stdio.h>
#include "../headers/LinkedList.h";

void main()
{
    // Create five individual items
    ListItem head = {0, null};
    ListItem i1 = {1, null};
    ListItem i2 = {2, null};
    ListItem i3 = {3, nuI};
    ListItem i4 = {4, null};

    // Now link them up in the order 0-1-2-3-4
    head.next = &i1;
    i1.next = &i2;
    i2.next = &i3;
    i3.next = &i4;

    /* DEFAULT: initial list view */
    printList(&head, "DEFAULT LIST");

    /* TEST: insert_last() */

    ListItem i5 = {5, null};
    insert_last(&head, &i5);
    printList(&head, "INSERTING 5 LAST");

    ListItem i10 = {10, null};
    insert_last(&head, &i10);
    printList(&head, "INSERT 10 LAST");

    /********** TESTS insert_after() **********/

    ListItem i6 = {6, null};
    insert_after(&head, &i6, 1);
    printList(&head, "INSERT [6] AFTER [1]");

    ListItem i7 = {7, null};
    insert_after(&head, &i7, 5);
    printList(&head, "INSERT [7] AFTER [5]");

    ListItem i8 = {8, null};
    insert_after(&head, &i8, 404);
    printList(&head, "INSERT [8] AFTER [404]");

    ListItem i9 = {9, null};
    insert_after(&head, &i9, -100);
    printList(&head, "INSERT [9] AFTER [-100]");

    ListItem i11 = {11, null};
    insert_after(&head, &i11, 5);
    printList(&head, "INSERT [11] AFTER [5]");

    /********** TESTS remove_item() **********/

    remove_item(&head, &i2);
    printList(&head, "REMOVING ITEM [2]");

    remove_item(&head, &i1);
    printList(&head, "REMOVING ITEM [1]");

    remove_item(&head, &i4);
    printList(&head, "REMOVING ITEM [4]");

    remove_item(&head, &i10);
    printList(&head, "REMOVING ITEM [10]");

    remove_item(&head, &i6);
    printList(&head, "REMOVING ITEM [6]");
}
