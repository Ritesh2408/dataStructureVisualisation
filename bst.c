#include <stdbool.h>
#include <stddef.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdbool.h>
#include "bst.h"

struct node *root = NULL;
char not_found[] = "Item Not found";
int root_centre_x = 700; // Coordinates of root
int root_centre_y = 565; // Coordinates of root
int node_width = 35;     // Width of root

bst inorderSuccessor(bst temp, bst *par) // To get minimun node from right for deletion
{
    if (temp->left == NULL)
        return temp;
    *par = temp;
    return inorderSuccessor(temp->left, par);
}

void display_string(char s[], float x, float y, float z) // This function is used to display string in a given coordinate
{
    glRasterPos3f(x, y, z);
    for (int i = 0; s[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    glFlush();
}

void draw_node(int item, int centre_x, int centre_y, bool write_value) // This function is used to display node and its value string in a given coordinate
{
    char data_string[10];
    glBegin(GL_POLYGON);
    glVertex2f(centre_x + node_width + 15, centre_y + node_width);
    glVertex2f(centre_x - node_width - 15, centre_y + node_width);
    glVertex2f(centre_x - node_width - 15, centre_y - node_width);
    glVertex2f(centre_x + node_width + 15, centre_y - node_width);
    glEnd();
    if (write_value)
    {
        to_string(data_string, item);
        glColor3f(1.0, 1.0, 1.0);
        display_string(data_string, centre_x - node_width + 15, centre_y - 5, 0);
    }
}

void draw_arrow(int par_x, int par_y, int node_x, int node_y, bool color) // This function is used to draw lines between the nodes
{
    if (color)
        glColor3f(1.0, 0.0, 0.0);
    else
        glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(par_x, par_y - node_width);
    glVertex2f(node_x, node_y + node_width);
    glEnd();
}

void draw_tree(bst temp) // This function is used to draw the current tree after every funtion or changes.
{
    if (temp != NULL)
    {
        glColor3f(0.196078, 0.196078, 0.8);
        draw_node(temp->data, temp->x, temp->y, true);
        if (temp->px != -1)
        {
            draw_arrow(temp->px, temp->py, temp->x, temp->y, true);
        }
        draw_tree(temp->left);
        draw_tree(temp->right);
    }
}

void draw_treep(bst temp) // This function is used to draw the preorder traversal of tree
{
    if (temp != NULL)
    {

        delay();
        delay();
        glColor3f(1.0, 0.0, 1.0);
        draw_node(temp->data, temp->x, temp->y, true);
        delay();
        delay();
        draw_treep(temp->left);
        delay();
        delay();
        draw_treep(temp->right);
        delay();
        delay();
    }
}

void draw_treei(bst temp) // This function is used to draw the inorder traversal of tree
{
    if (temp != NULL)
    {

        delay();
        delay();
        draw_treei(temp->left);
        delay();
        delay();
        glColor3f(1.0, 0.0, 1.0);
        draw_node(temp->data, temp->x, temp->y, true);
        delay();
        delay();
        draw_treei(temp->right);
        delay();
        delay();
    }
}

void draw_treepo(bst temp) // This function is used to draw the postorder traversal of tree
{
    if (temp != NULL)
    {

        delay();
        delay();
        draw_treepo(temp->left);
        delay();
        delay();
        draw_treepo(temp->right);
        delay();
        delay();
        glColor3f(1.0, 0.0, 1.0);
        draw_node(temp->data, temp->x, temp->y, true);
        delay();
        delay();
    }
}

void preorder(bst temp) // This function is used to draw the preorder traversal of tree in an array form
{

    if (temp != NULL)
    {
        glColor3f(0.196078, 0.196078, 0.8);
        a += 100;
        delay();
        draw_node(temp->data, a, b, true);
        delay();
        preorder(temp->left);
        delay();
        preorder(temp->right);
        delay();
    }
}

void inorder(bst temp) // This function is used to draw the inorder traversal of tree in an array form
{

    if (temp != NULL)
    {

        delay();
        inorder(temp->left);
        delay();
        a += 100;
        glColor3f(0.196078, 0.196078, 0.8);
        draw_node(temp->data, a, b, true);
        delay();
        inorder(temp->right);
        delay();
    }
}

void postorder(bst temp) // This function is used to draw the postorder traversal of tree in an array form
{

    if (temp != NULL)
    {

        delay();
        postorder(temp->left);
        delay();
        postorder(temp->right);
        delay();
        glColor3f(0.196078, 0.196078, 0.8);
        a += 100;
        draw_node(temp->data, a, b, true);
        delay();
    }
}

void display() // This is the display callback function
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    display_string("BINARY SEARCH TREE", 580, 730, 0);
    display_string("-------------------", 580, 700, 0);
    draw_tree(root);
    glFlush();
}

bst insert(int item) // This function is used to insert and calculate the coordinates of the node.
{
    int num_of_node = 1;
    int node_x = root_centre_x, node_y = root_centre_y;
    int par_x, par_y;
    bst temp, par = NULL, new_node;
    if (root == NULL)
    {
        root = (bst)malloc(sizeof(struct node));
        if (root == NULL)
        {
            glColor3f(1.0, 0.0, 0.0);
            return NULL;
        }
        root->data = item;
        root->left = root->right = NULL;
        glColor3f(0.196078, 0.196078, 0.8);
        root->x = node_x;
        root->y = node_y;
        root->px = -1;
        root->py = -1;
        draw_node(item, node_x, node_y, true);
        return root;
    }
    temp = root;
    while (temp != NULL)
    {
        num_of_node *= 2;
        par_x = node_x;
        par_y = node_y;
        node_y = node_y - 100;
        par = temp;

        if (item < temp->data)
        {
            temp = temp->left;
            node_x -= root_centre_x / num_of_node;
        }
        else
        {
            temp = temp->right;
            node_x = node_x + root_centre_x / num_of_node;
        }
    }
    new_node = (bst)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("there is an error in creating node\n");
        return NULL;
    }
    new_node->data = item;
    new_node->x = node_x;
    new_node->y = node_y;
    new_node->left = new_node->right = NULL;
    if (item < par->data)
        par->left = new_node;
    else
        par->right = new_node;
    new_node->px = par_x;
    new_node->py = par_y;
    glColor3f(0.196078, 0.196078, 0.8);
    draw_node(item, node_x, node_y, true);
    draw_arrow(par_x, par_y, node_x, node_y, true);
    glColor3f(1.0, 0.0, 0.0);
    display_string(not_found, 20, 600, 0);
    glFlush();
    display();
    return root;
}

bst removeNode(int item) // This is the deletion funtion of the code.
{
    bool found = false;
    int num_of_nodes = 1;
    int node_x = root_centre_x, node_y = root_centre_y;
    int par_x, par_y;
    bst temp = root, par = root, new_node;
    if (root == NULL)
    {
        glColor3f(1.0, 0.0, 0.0);
        display_string(not_found, 20, 600, 0);
        return root;
    }
    while (temp != NULL)
    {
        if (item == temp->data)
        {
            found = true;
            if (temp == root)
            {
                if (temp->left == NULL && temp->right == NULL)
                {
                    root = NULL;
                    free(temp);
                }
                if (temp->left != NULL && temp->right != NULL)
                {
                    par = temp;
                    bst min_node = inorderSuccessor(temp->right, &par);
                    temp->data = min_node->data;
                    temp = min_node;
                    item = min_node->data;
                    continue;
                }
                if (temp->left != NULL)
                {
                    root = temp->left;
                    free(temp);
                }
                if (temp->right != NULL)
                {
                    root = temp->right;
                    free(temp);
                }
            }
            else if (temp->left == NULL && temp->right == NULL)
            {
                if (par->left == temp)
                    par->left = NULL;
                else
                    par->right = NULL;
                free(temp);
            }
            else if (temp->left != NULL && temp->right != NULL)
            {
                par = temp;
                bst min_node = inorderSuccessor(temp->right, &par);
                temp->data = min_node->data;
                temp = min_node;
                item = min_node->data;
                continue;
            }
            else
            {
                if (temp->left != NULL)
                    (par->left == temp) ? (par->left = temp->left) : (par->right = temp->left);
                else
                    (par->left == temp) ? (par->left = temp->right) : (par->right = temp->right);
                free(temp);
            }
            break;
        }
        par = temp;
        if (item < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (!found)
    {
        glColor3f(1.0, 0.0, 0.0);
        display_string(not_found, 20, 600, 0);
    }
    else
        display();
}

void init()
{
    glClearColor(0.752941, 0.752941, 0.752941, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1500, 0.0, 800);
}

void bst_menu(int choice) // This is the right click menu function
{
    int item;
    switch (choice)
    {
    case 1:
        printf("\nEnter the item to be Inserted\n");
        glColor3f(1.0, 0.0, 0.0);
        display_string("1. While inserting smaller element gets attached to left and Greater element gets attached to right of root.", 20, 660, 0);
        scanf("%d", &item);
        insert(item);
        glFlush();
        break;
    case 2:
        printf("\nEnter the item to be Deleted\n");
        scanf("%d", &item);
        removeNode(item);
        glFlush();
        break;
    case 3:
        display();
        glColor3f(1.0, 0.0, 0.0);
        display_string("2. Preorder Traversal : Root --> Left --> Right", 20, 660, 0);
        glColor3f(1.0, 0.0, 0.0);
        display_string("Preorder Traversal", 50, 70, 0);
        printf("\nPreorder Traversal\n");
        draw_treep(root);
        delay();
        preorder(root);
        a = 400;
        glFlush();
        break;
    case 4:
        display();
        glColor3f(1.0, 0.0, 0.0);
        display_string("4. Inorder Traversal : Left --> Root --> Right", 20, 660, 0);
        printf("\nInorder Traversal\n");
        glColor3f(1.0, 0.0, 0.0);
        display_string("Inorder Traversal", 50, 70, 0);
        draw_treei(root);
        delay();
        inorder(root);
        a = 400;
        glFlush();
        break;
    case 5:
        display();
        glColor3f(1.0, 0.0, 0.0);
        display_string("3. Postorder Traversal : Left --> Right --> Root", 20, 660, 0);
        printf("\nPostorder Traversal\n");
        glColor3f(1.0, 0.0, 0.0);
        display_string("Postorder Traversal", 50, 70, 0);
        draw_treepo(root);
        delay();
        postorder(root);
        a = 400;
        glFlush();
        break;

    case 6:
        root = NULL;
        display();
        break;
    case 7:
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
        glutLeaveMainLoop();
    }
}
