
struct llnode
{
    int info;
    struct llnode *link;
};

typedef struct llnode *LNODE;
static LNODE first = NULL;


void drawstring(float x, float y, char *string, int col);
void llinit();
void disp();
void lldisplay();
LNODE getnode();
LNODE  insert_front(int item, LNODE first);
LNODE insert_rear(int item, LNODE first);
LNODE delete_front(LNODE first);
LNODE delete_rear(LNODE first);
LNODE delete_specified(LNODE first);
void llmenu(int choice);
void renderscene();






