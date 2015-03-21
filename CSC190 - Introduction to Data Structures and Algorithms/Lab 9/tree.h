struct treeNode
{
	int data;
	struct treeNode *right, *left;
};

void Insert(struct treeNode**, int);
int DeleteNode(struct treeNode**, int);
struct treeNode *FindItem(struct treeNode*, int);
struct treeNode *FindParent(struct treeNode*, int);
int PrintPreOrder(struct treeNode*);
int PrintInOrder(struct treeNode*);
int PrintPostOrder(struct treeNode*);
int traverseTree(struct treeNode *, int);
