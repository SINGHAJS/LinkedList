/***************************************************
 * @file ListItem.h
 * @author Ajit Singh
 * @date 2022-08-04
 ***************************************************/

typedef struct
{
    int item_num;
    struct ListItem *next;
} ListItem;