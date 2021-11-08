/**Saiful Islam Sagor**/
/**Reg.No:2017331033**/
#include <graphics.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int window_W = 800, window_h=600;

typedef pair<int,int>pii;


pii convertpixel(int x,int y)
{
    x +=window_W/2;
    y = -y;
    y +=window_h/2;
    return make_pair(x,y);
}

void drawPixel(int x,int y,int col)
{
    pii p = convertpixel(x,y);
    putpixel(p.first,p.second,col);
}

void drawAxis()
{
    for(int i=0; i<window_W; i++)
    {
        //delay(5);
        putpixel(i,window_h/2,YELLOW);
    }

    for(int i=0; i<window_h; i++)
    {
        //delay(5);
        putpixel(window_W/2,i,YELLOW);
    }
}

void drawCircle(int xc, int yc, int x, int y)
{
    drawPixel(xc+x, yc+y, WHITE);
    drawPixel(xc-x, yc+y, WHITE);
    drawPixel(xc+x, yc-y, WHITE);
    drawPixel(xc-x, yc-y, WHITE);
    drawPixel(xc+y, yc+x, WHITE);
    drawPixel(xc-y, yc+x, WHITE);
    drawPixel(xc+y, yc-x, WHITE);
    drawPixel(xc-y, yc-x, WHITE);
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {


        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
//        delay(50);
    }
    getchar();
}

void boundaryfill(int x,int y,int f_color,int b_color)
{
    if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
    {
        putpixel(x,y,f_color);
        boundaryfill(x+1,y,f_color,b_color);
        boundaryfill(x,y+1,f_color,b_color);
        boundaryfill(x-1,y,f_color,b_color);
        boundaryfill(x,y-1,f_color,b_color);
    }
}

int main( )
{
    int height =GetSystemMetrics(SM_CYSCREEN);
    int width = GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height,"",-100,-100 );


    int xc,yc,r,k;
    printf("Enter the value of xc and yc  And r: ");
    scanf("%d %d %d",&xc,&yc,&r);
    pii p = make_pair(xc,yc);
    circleBres(xc,yc,r);
//    pii p1 = convertpixel(xc,yc);
//    int x =p1.first;
//    int y =p1.second;
//    boundaryfill(x,y,4,WHITE);
    while(true)
    {
        cleardevice();
//        drawAxis();
        circleBres(xc,yc,r);
        if(GetAsyncKeyState(VK_RIGHT))
            xc+=10;
        else if(GetAsyncKeyState(VK_LEFT))
            xc-=10;
        else if(GetAsyncKeyState(VK_UP))
            yc+=10;
        else if(GetAsyncKeyState(VK_DOWN))
            yc-=10;
        else if(GetAsyncKeyState(VK_RBUTTON))
        {
            pii p1 = convertpixel(xc,yc);
            int x =p1.first;
            int y =p1.second;
            boundaryfill(x,y,4,15);
        }
//        else if(GetAsyncKeyState(VK_RETURN))
//            break;
        delay(100);


    }


    getch();
    closegraph();

    return 0;
}






