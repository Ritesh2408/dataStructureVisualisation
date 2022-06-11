#include<stdbool.h>
#include<stddef.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdbool.h>
#include "linkedlist.h"

static int count = 0, flag = 1;
int succ = 1, succ1 = 1, ins_succ = 1;
int choice, item, key;
float color[4][3] = {{1.0, 1.0, 1.0}, {0.8, 0.0, 0.0,}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}};


void drawstring(float x, float y, char *string, int col)
{
    char *c;
    glColor3fv(color[col]);
    glRasterPos2f(x, y);
    for(c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}



void llinit()
{
    glClearColor(0.752941, 0.752941, 0.752941, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);
}


void disp()
{
    glColor3f(0.5, 0.4, 0.7);
    drawstring(220.0, 370.0, "Empty list", 0);
    glColor3f(1.0f, 1.0f, 1.0f);

    glFlush();
}


void lldisplay()
{
    int i = 0, j = 0, k = 0, data;
    LNODE temp;
    glClearColor(0.752941, 0.752941, 0.752941, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
    drawstring(200.0, 420.0, "-------------------", 1);
    if(first == NULL)
    {

        disp();
        return;
    }

    temp = first;
    while(temp != NULL)
    {
        for(k = 0; k < count; k++)
        {
            GLfloat x1 = 50, x2 = 80, x3 = 110, y1 = 200, y2 = 225, y3 = 250,
                    x4 = 95, y4 = 225, x5 = 160, y5 = 210, y6 = 240, x6 = 180;

            if(temp->link == NULL)
            {
                glColor3f(0.196078, 0.196078, 0.8);
                glBegin(GL_POLYGON);
                glVertex2i(x1 + k * 130, y1);
                glVertex2i(x1 + k * 130, y3);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x2 + k * 130, y1);
                glEnd();


            }
            else
            {
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINES);
                glVertex2i(x4 - 30 + k * 130, y4);
                glVertex2i(x6 + k * 130, y4);
                glEnd();
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINES);
                glVertex2i(x5 + k * 130, y6);
                glVertex2i(x6 + k * 130, y4);
                glVertex2i(x6 + k * 130, y4);
                glVertex2i(x5 + k * 130, y5);
                glEnd();
                glColor3f(0.196078, 0.196078, 0.8);
                glBegin(GL_POLYGON);
                glVertex2i(x1 + k * 130, y1);
                glVertex2i(x1 + k * 130, y3);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x2 + k * 130, y1);
                glEnd();

            }
            data = temp->info;

            temp = temp->link;
            char data_string[10];
            to_string(data_string, data);
            glColor3f(1.0, 1.0, 1.0);
            drawstring(60.0 + k * 130, 225.0, data_string, 0);

            glFlush();
        }
    }
}


LNODE getnode()
{
    LNODE x;
    x = (LNODE *)malloc(sizeof(LNODE));
    if(x == NULL)
    {
        printf("Insufficient memory \n");
        exit(0);
    }
    return x;
}


LNODE  insert_front(int item, LNODE first)
{
    LNODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}


LNODE insert_rear(int item, LNODE first)
{
    LNODE temp;
    LNODE cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
        return temp;
    cur = first;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}


LNODE delete_front(LNODE first)
{
    LNODE temp;
    if(first == NULL)
    {
        printf("List is empty cannot delete\n");
        disp();
        count++;
        succ = 0;
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("Item deleted = %d \n", first->info);
    free(first);
    return temp;
}


LNODE delete_rear(LNODE first)
{
    LNODE cur, prev;
    if(first == NULL)
    {
        printf("List is empty cannot delete \n");
        disp();
        count++;
        succ = 0;
        return first;
    }
    if(first->link == NULL)
    {
        printf("Item to be deleted is %d \n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Item deleted is %d \n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}


LNODE delete_specified(LNODE first)
{
    LNODE prev, cur;
    if(first == NULL)
    {
        printf("List is empty\n");
        disp();
        count++;
        succ = 0;
        return NULL;
    }
    printf("Enter the key :- ");
    scanf("%d", &key);
    if(key == first->info)
    {
        cur = first;
        first = first->link;
        free(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    while(cur != NULL)
    {
        if(key == cur->info)
            break;
        prev = cur;
        cur = cur->link;
    }
    if(cur == NULL)
    {
        printf("Search is unsuccessful\n");
        count++;
        succ1 = 0;
        succ = 0;
        return first;
    }
    prev->link = cur->link;
    free(cur);
    return first;
}


void llmenu(int choice)
{
    switch(choice)
    {
    case 1:
        printf("Enter the item to be inserted :- ");
        scanf("%d", &item);
        first = insert_front(item, first);
        count++;
        lldisplay();
        drawstring(200.0, 130.0, "NEW NODE INSERTED AT FRONT(0th index)", 2);
        break;
    case 2:
        printf("Enter the item to be inserted :- ");
        scanf("%d", &item);
        first = insert_rear(item, first);
        count++;
        lldisplay();
        drawstring(200.0, 130.0, "NEW NODE INSERTED AT BACK", 2);
        break;

    case 3:
        succ = 1;
        first = delete_front(first);
        count--;
        lldisplay();
        if(succ)
        drawstring(200.0, 130.0, "NODE DELETED FROM FRONT (0th index)", 2);
        break;
    case 4:
        succ = 1;
        first = delete_rear(first);
        count--;
        lldisplay();
        if(succ)
            drawstring(200.0, 130.0, "NODE DELETED FROM BACK", 2);
        break;
    case 5:
        succ = succ1 = 1;
        first = delete_specified(first);
        count--;
        lldisplay();
        if(succ)
            drawstring(200.0, 130.0, "NODE DELETED", 2);
        if(!succ1)
            drawstring(200.0, 130.0, "KEY NODE DOESN'T EXIST", 2);
        break;
    case 6:
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
        glutLeaveMainLoop();
    }
}


void renderscene()
{
    glClear(GL_COLOR_BUFFER_BIT);


    lldisplay();

    glFlush();
}
