struct smartArray{
    unsigned int size;
    int *a;
};

struct smartArray* createSmartArray(unsigned int);
void destroySmartArray(struct smartArray**);

int setPosition(struct smartArray*, int, unsigned int);
int readPosition(struct smartArray*, int*, unsigned int);

int insertPosition(struct smartArray*, int, unsigned int);
int deletePosition(struct smartArray*, unsigned int);

void printSmartArray(struct smartArray*);
int getSmartArraySize(struct smartArray*);
