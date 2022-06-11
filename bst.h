static int a = 400;//Coordinates for the placement of traversal blocks
static int b = 70;//Coordinates for the placement of traversal blocks




struct node
{
    int data;
    int x;
    int y;
    int px;
    int py;
    struct node *left;
    struct node *right;
};


typedef struct node *bst;  //In this node we have extra x ,y,px,py variable for storing cordinates of current and parent node.



bst inorderSuccessor(bst temp, bst *par);
void display_string(char s[], float x, float y, float z);
void draw_node(int item, int centre_x, int centre_y, bool write_value);
void draw_arrow(int par_x, int par_y, int node_x, int node_y, bool color);
void draw_tree(bst temp);
void draw_treep(bst temp);
void draw_treei(bst temp);
void draw_treeo(bst temp);
void preorder(bst temp);
void inorder(bst temp);
void postorder(bst temp);
void display();
bst insert(int item);
bst removeNode(int item);
void init();
void bst_menu(int choice);
