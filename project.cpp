#include "graphics.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int windowx=1024,windowy=700;
int mode=1;
int p=510,q=640,r=35,point=0,bull;
int g_o=0;
char ch;
struct score
{
    char name[100];
    int number;
} list[6];

void newname()
{
    int i;
    char temp;
    readimagefile("newname.jpg",0,0,windowx,windowy);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    setbkcolor(getpixel(370,617));
    setcolor(BLACK);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    setfillstyle(SOLID_FILL,getpixel(370,617));
    for(i=0;;)
    {
        temp = getch();
        if(temp=='\r')
            break;
        list[4].name[i++] = temp;
        list[4].name[i]=0;
        puts(list[4].name);
        bar(370,617,370+textwidth(list[4].name),637);
        outtextxy(370,617,list[4].name);
    }
    list[4].name[i] = 0;
    list[4].number = point;

    int j;
    struct score temporary;
    for(i=0; i<5; i++)
    {
        for(j=0; j<4; j++)
        {
            if(list[j].number<list[j+1].number)
            {
                temporary = list[j];
                list[j] = list[j+1];
                list[j+1] = temporary;
            }
        }
    }
    FILE *fp = fopen("name.txt","w");
    for(i=0; i<5; i++)
    {
        fprintf(fp,"%s %d\n",list[i].name,list[i].number);
    }
    fclose(fp);
}
void leaderboard()
{
    char name[100];
    FILE *fp;
    fp = fopen("name.txt","r");
    int i;

    for(i=0; i<5; i++)
        fscanf(fp,"%s %d",list[i].name,&list[i].number);
    fclose(fp);
    rewind(stdin);
    if(point>list[4].number)
    {
        newname();
    }
    setbkcolor(COLOR(216,208,195));
    setcolor(COLOR(128,64,64));
    readimagefile("lead.jpg",0,0,windowx,windowy);
    int h=90;
    settextjustify(LEFT_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    for(i=0; i<5; i++)
    {
        sprintf(name,"%s %d\n",list[i].name,list[i].number);
        setbkcolor(getpixel(600,260+h));
        outtextxy(422,260+h*i,name);
    }
}
int main()

{
    int pp,qq,i;

    initwindow(1024,700,"Space Invaders");
    readimagefile("start.jpg",0,0,1024,700);
    settextstyle(8, HORIZ_DIR, 4);
        outtextxy(380,600," press any key to continue..... ");
        getch();
        cleardevice();
        readimagefile("loading.jpg",0,0,1024,700);
        outtextxy(580,600," Loading.        ");
        delay(400);
        outtextxy(580,600," Loading..       ");
        delay(400);
        outtextxy(580,600," Loading...      ");
        delay(400);
        outtextxy(580,600," Loading....     ");
        delay(400);
        outtextxy(580,600," Loading.....    ");
        delay(400);
        outtextxy(580,600," Loading......   ");
        delay(600);

    while(1)
    {
      readimagefile("menu.jpg",0,0,1024,700);
      int x,y;

        clearmouseclick(WM_LBUTTONDOWN);
        while(!ismouseclick(WM_LBUTTONDOWN));
        getmouseclick(WM_LBUTTONDOWN,x,y);


        if(x>=27 && y>= 559 && x<=205 && y<=620)
        {
            readimagefile("o1.jpg",0,0,1024,700);
            delay(50);
            readimagefile("menu.jpg",0,0,1024,700);
            delay(100);
            initwindow(1024, 700);
            putpixel(1024, 700, BLACK);
            //readimagefile("back.jpg",0,0,1024,700);
            readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);  //p=510,q=640    // 514,605
            while (1)
            {

                if(kbhit)
                    ch=getch();

                {
                    if(ch==75)
                    {
                        cleardevice();
                        //readimagefile("back.jpg",0,0,1024,700);
                        p=p-10;
                        readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);
                    }
                    if (ch==32)
                    {
                        pp=p;
                        qq=q;

                        while(1)
                        {
                            if (qq<=420)
                                qq=qq-45;

                            if (qq<=10)
                                break;

                            //readimagefile("back.jpg",0,0,1024,700);
                            readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);
                            readimagefile("bullet.jpg",pp+4,qq-45,pp+6,qq-35);
                            readimagefile("bullet.jpg",pp-8,qq-29,pp-6,qq-19);
                            readimagefile("bullet.jpg",pp+15,qq-29,pp+13,qq-19);
                            qq=qq-25;
                            delay(40);
                            cleardevice();
                            readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);
                        }
                    }
                }

                if(ch==77)
                {
                    cleardevice();
                    //readimagefile("back.jpg",0,0,1024,700);
                    p=p+10;
                    readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);
                }
                if(ch==80)
                {
                    cleardevice();
                    //readimagefile("back.jpg",0,0,1024,700);
                    q=q+10;
                    readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);
                }
                if(ch==72)
                {
                    cleardevice();
                    //readimagefile("back.jpg",0,0,1024,700);
                    q=q-10;
                    readimagefile("Fl.jpg",p-40,q-40,p+50,q+60);

                }

            }

        }


//leaderboard   (255,562) (444,623)
//instruction   (495,557)  (707, 623)
// quit        (752, 561)   (952  620)




        else if(x>=255 && y>= 562 && x<=444 && y<=623)
        {
            readimagefile("o2.jpg",0,0,1024,700);
            delay(50);
            readimagefile("menu.jpg",0,0,1024,700);
            delay(100);
            readimagefile("leaderboard.jpg",0,0,1024,700);
            point=0;
            leaderboard();
            getch();
            mode=0;
            cleardevice();
        }
        else if(x>=495 && y>= 557 && x<=707 && y<=623)
        {
            readimagefile("o3.jpg",0,0,1024,700);
            delay(50);
            readimagefile("menu.jpg",0,0,1024,700);
            delay(100);
            readimagefile("instruction.jpg",0,0,1024,700);

        }
        else if(x<=950 && y>= 560 && x>=752 && y<=660)
        {
            readimagefile("o4.jpg",0,0,1024,700);
            delay(50);
            readimagefile("menu.jpg",0,0,1024,700);
            delay(100);
            readimagefile("gameover.jpg",0,0,1024,700);
            delay(2000);
            readimagefile("leaderboard.jpg",0,0,1024,700);
            leaderboard();
            delay(4000);
            return 0;
        }

    }

}
