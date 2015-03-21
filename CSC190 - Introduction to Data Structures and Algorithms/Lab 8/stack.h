struct stackNode{
    float data;
    struct stackNode *next;
};

int Push(struct stackNode**, float);
int Pop(struct stackNode**, float*);
int Peek(struct stackNode*, float*);
int PrintStack(struct stackNode*);

