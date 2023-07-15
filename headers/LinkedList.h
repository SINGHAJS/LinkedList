/***************************************************
 * @file LinkedList.h
 * @author Ajit Singh
 * @date 2022-08-04
 ***************************************************/

#include "../headers/ListItem.h";

#ifndef null 0
#define null 0
#endif

void printList(ListItem *head, char[]);
int insert_last(ListItem *, ListItem *);
int remove_item(ListItem *, ListItem *);
int insert_after(ListItem *, ListItem *, int);
