typedef struct dlnode
{
    int info;
    struct dlnode *rlink;
    struct dlnode *llink;
}dlnode;

typedef dlnode *DLNODE;
static int dlcount = 0;
DLNODE head;

void dldrawstring(float x, float y, char *string);
DLNODE dlgetnode();
void dldisp();
DLNODE dldisplay(DLNODE head);
DLNODE insertfront(DLNODE head, int item);
DLNODE insertrear(DLNODE head, int item);
DLNODE insertleft(DLNODE head, int ele);
DLNODE insertright(DLNODE head, int ele);
DLNODE deletfront(DLNODE head);
DLNODE deletrear(DLNODE head);
DLNODE del(DLNODE head, int ele);
void renderscenedl();
void dlinit();
void dlmenu(int option);












