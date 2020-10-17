# include<graphics.h>
# include<stdio.h>
# include<conio.h>
# include<dos.h>

void main()
{
int gd=DETECT,gm,x,y,i;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
for(i=1;i<400;i++)
{
setcolor(BLACK);
circle(101+i,250,28);       //first tire
circle(100+i,250,28);
circle(100+i,250,5);
circle(301+i,250,28);       //second tire
circle(300+i,250,28);
circle(300+i,250,5);
circle(160+i,250,10);     //chain
circle(160+i,250,5);
line(130+i,175,140+i,175);  //seat

line(0,278,1000,278);
  setcolor(RED);
line(101+i,250,150+i,250);  //chain line
line(160+i,240,135+i,175);  //seat line
line(101+i,250,145+i,200);  //seat line connecting tire
setcolor(GREEN) ;
line(301+i,250,280+i,170);  //handle line
setcolor(RED);
line(280+i,170,280+i,150);   //handle joining straight line
line(280+i,150,260+i,130);
line(260+i,130,270+i,120);
line(280+i,150,300+i,170);
line(300+i,170,310+i,160);
line(280+i,170,140+i,185);
line(170+i,250,282+i,175);

delay(10);
clrscr();
 }
getch();
closegraph();
}
