struct node{
    int data;
    struct node *next;
};

void SortedInsert(struct node**, int);
int DeleteNode(struct node**, int);
struct node *FindItem(struct node*, int);
int PrintList(struct node*);

