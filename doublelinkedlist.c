#include<stdbool.h>
#include<stddef.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdbool.h>
#include "doublelinkedlist.h"


void dldrawstring(float x, float y, char *string)
{
    char *c;

    glRasterPos2f(x, y);
    for(c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}


DLNODE dlgetnode()
{
    DLNODE temp;
    temp = (DLNODE)malloc(sizeof(struct dlnode));
    if(temp == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    return temp;
}


void dldisp()
{

    glColor3f(1.0, 1.0, 1.0);
    char c[] = "List is Empty";
    glRasterPos2f(820.0, 200.0);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);


    glFlush();
}


DLNODE dldisplay(DLNODE head)
{

    DLNODE temp;
    int i = 0, k, j = 0;
    temp = head->rlink;
    glClearColor(0.752941, 0.752941, 0.752941, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    dldrawstring(680.0, 360.0, "DOUBLY LINKED LIST");
    dldrawstring(680.0, 330.0, "------------------");


    if(temp == head)
    {

        dldisp();
        return head;

    }

    int data ;
    while(temp != head)
    {
        for(k = 0; k < dlcount; k++)
        {
            GLfloat x1 = 100, x2 = 150, x3 = 350, x4 = 400, x5 = 500, x6 = 480, x7 = 20, x9 = 0;
            data = temp->info;



            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POLYGON);
            glVertex2i(x2 + k * 400, 200);
            glVertex2i(x2 + k * 400, 225);
            glVertex2i(x3 + k * 400, 225);
            glVertex2i(x3 + k * 400, 200);
            glEnd();

            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex2i(x3 + k * 400, 225);
            glVertex2i(x3 + k * 400, 200);
            glVertex2i(x4 + k * 400, 200);
            glVertex2i(x4 + k * 400, 225);
            glEnd();
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex2i(x1 + k * 400, 225);
            glVertex2i(x1 + k * 400, 200);
            glVertex2i(x2 + k * 400, 200);
            glVertex2i(x2 + k * 400, 225);
            glEnd();
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2i(x1 + k * 400, 207);
            glVertex2i(x9 + k * 400, 207);
            glVertex2i(x9 + k * 400, 207);
            glVertex2i(x7 + k * 400, 202);
            glVertex2i(x9 + k * 400, 207);
            glVertex2i(x7 + k * 400, 210);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2i(x4 + k * 400, 215);
            glVertex2i(x5 + k * 400, 215);
            glVertex2i(x5 + k * 400, 215);
            glVertex2i(x6 + k * 400, 210);
            glVertex2i(x5 + k * 400, 215);
            glVertex2i(x6 + k * 400, 219);
            glEnd();

            glColor3f(0.0, 0.0, 0.0);
            char data_string[10];
            to_string(data_string, data);
            int x8 = 225;
            glColor3f(1.0, 1.0, 1.0);
            dldrawstring(x8 + k * 400, 210, data_string);
            temp = temp->rlink;

            glFlush();
        }
    }

    return head;
}


DLNODE insertfront(DLNODE head, int item)
{
    DLNODE temp, cur;
    temp = dlgetnode();
    temp->info = item;
    cur = head->rlink;
    head->rlink = temp;
    temp->llink = head;
    temp->rlink = cur;
    cur->llink = temp;
    return head;

}


DLNODE insertrear(DLNODE head, int item)
{
    DLNODE temp, cur;
    temp = dlgetnode();
    temp->info = item;
    cur = head->llink;
    head->llink = temp;
    temp->rlink = head;
    temp->llink = cur;
    cur->rlink = temp;
    return head;
}


DLNODE insertleft(DLNODE head, int ele)
{
    int item;
    DLNODE temp, cur, pre;
    if(head->rlink == head)
    {
        printf("List is empty :- \n");
        dlcount--;
        return head;
    }
    cur = head->rlink;
    while(cur != head)
    {
        if(cur->info == ele)
            break;
        cur = cur->rlink;
    }
    if(cur == head)
    {
        printf("%d Element not found\n", ele);
        dlcount--;
        return head;
    }
    printf("Enter element to be inserted :- \n");
    scanf("%d", &item);
    pre = cur->llink;
    temp = dlgetnode();
    temp->info = item;
    temp->llink = pre;
    temp->rlink = cur;
    cur->llink = temp;
    pre->rlink = temp;
    return head;

}


DLNODE insertright(DLNODE head, int ele)
{
    int item;
    glClear(GL_COLOR_BUFFER_BIT);
    DLNODE temp, cur, next;
    if(head->rlink == head)
    {
        printf("List is empty\n");
        dlcount--;
        return head;
    }
    cur = head->rlink;
    while(cur != head)
    {
        if(cur->info == ele)
        {
            printf("Enter element to be inserted :- \n");
            scanf("%d", &item);
            next = cur->rlink;
            temp = dlgetnode();
            temp->info = item;
            temp->llink = cur;
            temp->rlink = next;
            cur->rlink = temp;
            next->llink = temp;
            return head;
        }
        cur = cur->rlink;
    }
    printf("%d Element not found\n", ele);
    dlcount--;
    return head;
}


DLNODE deletfront(DLNODE head)
{
    DLNODE cur, next;
    if(head->rlink == head)
    {
        printf("List is empty\n");
        dlcount++;
        return head;
    }
    cur = head->rlink;
    next = cur->rlink;
    head->rlink = next;
    next->llink = head;
    printf("Node to be deleted is = %d\n", cur->info);
    free(cur);
    return head;
}


DLNODE deletrear(DLNODE head)
{
    DLNODE cur, prev;
    if(head->llink == head)
    {
        printf("List is empty\n");
        dlcount++;
        return head;
    }
    cur = head->llink;
    prev = cur->llink;
    head->llink = prev;
    prev->rlink = head;
    printf("Node to b deleted is = %d\n", cur->info);
    free(cur);
    return head;
}


DLNODE del(DLNODE head, int ele)
{
    DLNODE cur, next, pre;
    glClear(GL_COLOR_BUFFER_BIT);
    if(head->rlink == head)
    {
        printf("List is empty\n");
        dlcount++;
        return head;
    }
    cur = head->rlink;
    while(cur != head)
    {
        if(cur->info == ele)
            break;
        cur = cur->rlink;
    }
    if(cur == head)
    {
        printf("%d Element not found\n", ele);
        dlcount++;
        return head;
    }
    pre = cur->llink;
    next = cur->rlink;
    printf("%d Element found and deleted\n", ele);
    pre->rlink = next;
    next->llink = pre;
    free(cur);
    return head;

}


void renderscenedl()
{
    glClear(GL_COLOR_BUFFER_BIT);



    dldisplay(head);

    glFlush();

}


void dlinit()
{
    glClearColor(0.752941, 0.752941, 0.752941, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(0.8);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 2000.0, 0.0, 400.0);
}


void dlmenu(int option)
{
    int ele;
    switch(option)
    {
    case 1:

        printf("Enter item to be inserted :- \n");
        scanf("%d", &ele);
        head = insertfront(head, ele);
        dlcount++;
        dldisplay(head);
        glColor3f(1.0,0.0,0.0);
        dldrawstring(200.0, 130.0, "NEW NODE INSERTED AT FRONT(0th index)");
        break;
    case 2:
        printf("Enter item to be inserted :- \n");
        scanf("%d", &ele);
        head = insertrear(head, ele);
        dlcount++;
        dldisplay(head);
        glColor3f(1.0,0.0,0.0);
        dldrawstring(200.0, 130.0, "NEW NODE INSERTED AT BACK");
        break;
    // case 3:
    //     printf("Enter item to be inserted :- \n");
    //     scanf("%d", &ele);
    //     head = insertleft(head, ele);
    //     dlcount++;
    //     dldisplay(head);
    //     break;
    // case 4:
    //     printf("Enter item to be inserted :- \n");
    //     scanf("%d", &ele);
    //     head = insertright(head, ele);
    //     dlcount++;
    //     dldisplay(head);
    //     break;
    case 5:
        head = deletfront(head);
        dlcount--;
        dldisplay(head);
        glColor3f(1.0,0.0,0.0);
        dldrawstring(200.0, 130.0, "NODE DELETED FROM FRONT(0th index)");
        break;
    case 6:
        head = deletrear(head);
        dlcount--;
        dldisplay(head);
        glColor3f(1.0,0.0,0.0);
        dldrawstring(200.0, 130.0, "NODE DELETED FROM BACK");
        break;
    case  7:
        printf("Enter key :- \n");
        scanf("%d", &ele);
        dlcount--;
        head = del(head, ele);
        dldisplay(head);
        glColor3f(1.0,0.0,0.0);
        dldrawstring(200.0, 130.0, "NODE DELETED");
        break;
    case 8:
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
        glutLeaveMainLoop();
    }
}











