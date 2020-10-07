#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<graphics.h>
#include<_mingw.h>
void showMessage(char *message)
{
    setbkcolor(GREEN);
    setcolor(YELLOW);
    settextstyle(1,0,3);
    outtextxy(500,400,message);
    settextstyle(1,0,3);
    outtextxy(500,430,"press any key to continue");
    getch();
}

void drawUnclear(int left,int top)
{
    int right=left+40,bottom=top+40;
   setcolor(WHITE);
   rectangle(left,top,right,bottom);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(left+1,top+1,WHITE);
   setcolor(LIGHTGRAY);
   rectangle(left+6,top+6,right-6,bottom-6);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(left+7,top+7,LIGHTGRAY);
   setcolor(WHITE);
   rectangle(left+10,top+10,right-10,bottom-10);
   setfillstyle(SOLID_FILL,WHITE);
   floodfill(left+20,top+20,WHITE);
}
void drawemptySquare(int left , int top)
{
    int right=left+40,bottom=top+40;
   setcolor(WHITE);
   rectangle(left,top,right,bottom);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(left+20,top+20,WHITE);
   setcolor(LIGHTGRAY);
   rectangle(left+6,top+6,right-6,bottom-6);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(left+20,top+20,LIGHTGRAY );
}
void drawbomb(int left , int top)
{
  int right = left+40,bottom=top+40;
   int gd=DETECT,gm;
   int points[]={left+18,top+16,left+18,top+10,left+23,top+10,left+23,top+16,left+19,top+16};
   int points2[]={left+21,top+10,left+22,top+05,left+30,top+07,left+21,top+110};
   setcolor(WHITE);
   rectangle(left,top,right,bottom);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(left+20,top+20,WHITE);
   rectangle(left+3,top+3,right-3,bottom-3);
   setfillstyle(SOLID_FILL,RED);
   floodfill(left+20,top+20,WHITE);
   setcolor(BLACK);
   drawpoly(4, points);
   drawpoly(3, points2);
   setcolor(LIGHTRED);
   circle(left+20,top+25,1);
   circle(left+20,top+25,2);
   circle(left+20,top+25,3);
   circle(left+20,top+25,4);
   setcolor(RED);
   circle(left+20,top+25,5);
   circle(left+20,top+25,6);
   setcolor(BROWN);;
   circle(left+20,top+25,7);
   circle(left+20,top+25,8);
   setcolor(BLACK);
   circle(left+20,top+25,9);
   circle(left+20,top+25,10);
}
void drawflag(int left,int top)
{
    int right=left+40,bottom=top+40;
    int gd=DETECT,gm,points[]={left+19,top+20,left+10,top +13,left+19,top+07,left +19,top+20};
    setcolor(WHITE);
   rectangle(left,top,right,bottom);
   setfillstyle(SOLID_FILL,7);
   floodfill(left+1,top+1,WHITE);
   setcolor(DARKGRAY);
   rectangle(left+1,top+1,right-1,bottom-1);
   setcolor(BLACK);
   rectangle(left+10,top+34,right-10,bottom-3);
   rectangle(left+19,top+7,right-19,bottom-6);
   setcolor(BLACK);
   drawpoly(3, points);
   setfillstyle(SOLID_FILL,RED);
   fillpoly(3,points);
}
void drawnumberedSquare(int left,int top,int num)
{
    int right=left+40,bottom=top+40;
    int gd=DETECT,gm;
   setcolor(WHITE);
   rectangle(left,top,right,bottom);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(left+20,top+20,WHITE);
   setcolor(LIGHTGRAY);
   rectangle(left+6,top+6,right-6,bottom-6);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(left+20,top+20,LIGHTGRAY );
   settextstyle(2,0,7);
   setbkcolor(LIGHTGRAY);
   int color = num-48 ;
   if(color==3)
   {
       color=14;
   }else;
   if(color==7)
   {
       color=9;
   }else;
   if(color==8)
   {
       color=12;
   }else;
   char s = (char) num;
   setcolor(color);
   outtextxy(left+13,top+10,&s);
}
int valid_input( int x , int y , int length , char r_or_f )
{
    int valid;
    if( (x>0 && x<length+1) && ( (y>0 && y<length+1) ) && (r_or_f == 114 || r_or_f == 63) )
    {
        valid = 1;
    }else
    valid = 0;
    if(x<1 || x>length)
    {
        char c[100]="entered x not in range !!";
        showMessage(c);
    }else;
    if(y<1 || y>length)
    {
        char c[100]="entered y not in range !! ";
        showMessage(c);
    }else;
    if (r_or_f != 114 && r_or_f != 63)
    {
        char c[100]="please enter (r) or (?)!!";
        showMessage(c);
    }else;
    return valid;
}
int winChecker( int arr[17][17] , int length , int n )
{
    int i , j , count = 0 , win ;
    for (  i = 1 ; i < length+1 ; i++ )
    {
        for ( j = 1 ; j < length+1 ; j++ )
        {
            if(arr[i][j]==63 || arr[i][j]==79)
            {
                count++;
            }
        }
    }
    if(count == n)
    {
        win = 1;
    }else win = 0;
    return win ;
}
void clearing(int  field[2][17][17] , int x , int y ,int length )
{
    if( field[1][x][y] == 79 )
    {
        if(( field[0][x][y]>0 && field[0][x][y]<9 ) || x==0 || y==0 || y==length+1 || x==length+1 )
        {
            if( field[0][x][y]>0 && field[0][x][y]<9 && field[1][x][y]==79 )
            {
                field[1][x][y] = 48 + field[0][x][y];
            }else;
        }else
        {
            if( field[1][x][y]==79 )
            {
                field[1][x][y] = 32;
            }else;
            clearing(field,x+1,y,length);
            clearing(field,x-1,y,length);
            clearing(field,x,y+1,length);
            clearing(field,x,y-1,length);
            clearing(field,x+1,y+1,length);
            clearing(field,x-1,y-1,length);
            clearing(field,x+1,y-1,length);
            clearing(field,x-1,y+1,length);
        }
    }
}
int drawMenu()
{
    setbkcolor(LIGHTBLUE);
    cleardevice();
    setcolor(BLUE);
    rectangle(500,300,1000,600);
    setfillstyle(1,3);
    floodfill(501,401,BLUE);
    settextstyle(1,0,2);
    setcolor(BLACK);
    setbkcolor(3);
    char a[]="1. 5*5 with 10 bombs";
    char b[]="2. 10*10 with 30 bombs";
    char c[]="3. 15*15 with 80 bombs";
    char d[]="4. 15*15 with 100 bombs";
    outtextxy(520,320,a);
    outtextxy(520,380,b);
    outtextxy(520,440,c);
    outtextxy(520,500,d);
    return getch();
}

void drawField(int len,int arr[17][17],int left,int top,char* x , char* y,char* r,int mode,char* repeat,int bomb)
{
    setbkcolor(LIGHTBLUE);
    cleardevice();
    int gd=DETECT,gm;
    int right=left+40,bottom=top+40;
    char numbers[15][3]= {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"};
    setcolor(YELLOW);
    settextstyle(6,0,1);
    setbkcolor(LIGHTBLUE);
    outtextxy(340,10,"**HINT : first enter row\n");
    outtextxy(340,30,"then column");
    outtextxy(340,50,"then press r for revealing the square");
    outtextxy(340,70,"and ? to flag the square");
    int i , j;
    for(i=1;i<len+1;i++)
    {
        settextstyle(2,0,7);
        setcolor(BLUE);
        setbkcolor(LIGHTBLUE);
        outtextxy((left+((i-1)*40)+11),top-22,numbers[i-1]);
    }

    for(i=1;i<len+1;i++)
    {
        settextstyle(2,0,7);
        setcolor(BLUE);
        setbkcolor(LIGHTBLUE);
        outtextxy((left-20),top+((i-1)*40)+11,numbers[i-1]);
    }
    int l =left;
    for(i=1;i<len+1;i++)
    {
        for(j=1;j<len+1;j++)
        {
            if(arr[i][j]==79)
            {
                drawUnclear(l,top);
                l=l+40;
            }else;
            if(arr[i][j]==63)
            {
                drawflag(l,top);
                l=l+40;
            }else;
            if(arr[i][j]==42)
            {
                drawbomb(l,top);
                l=l+40;
            }else;
            if(arr[i][j]==32)
            {
                drawemptySquare(l,top);
                l=l+40;
            }else;
            if((arr[i][j]>=49) && (arr[i][j]<=56))
            {
                int num = arr[i][j];
                drawnumberedSquare(l,top,num);
                l=l+40;
            }else;
        }
        l=left;
        top=top+40;
    }

    if(mode)
    {   char msg[128];
        sprintf(msg, "bombs left :      %d", bomb);
        setbkcolor(LIGHTBLUE);
        setcolor(CYAN);
        settextstyle(1,0,2);
        outtextxy(410,(len*40)+125, msg);
        *x=getch();
        *y=getch();
        *r=getch();
    }else
    {
        setcolor(YELLOW);
        settextstyle(1,0,3);
        setbkcolor(BLUE);
        outtextxy(415,115,"do you want to play again?");
        outtextxy(480,145,"         Y  or  N ? ");
        setbkcolor(GREEN);
        setcolor(RED);
        settextstyle(1,0,4);
        setbkcolor(GREEN);
        outtextxy(600,300,"GAME OVER !");
        *repeat=getch();
    }
}
int main()
{
    char repeat;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int repeat_game = 1;
    while (repeat_game)
    {
        char mode;
        int fieldLength , numOfBombs , tabs , selection = 0;
        int field[2][17][17];
        while(!selection)
        {
            mode =drawMenu();
            switch ( mode )
            {
                    case '1' :
                    {
                        numOfBombs = 10 ;
                        fieldLength = 5 ;
                        tabs = 7 ;
                        selection = 1 ;
                    }break;
                    case '2' :
                    {
                        numOfBombs = 30 ;
                        fieldLength = 10;
                        tabs = 6 ;
                        selection = 1 ;
                    }break;
                    case '3' :
                    {
                        numOfBombs = 80 ;
                        fieldLength = 15 ;
                        tabs = 5 ;
                        selection = 1 ;
                    }break;
                    case '4' :
                    {
                        numOfBombs = 100 ;
                        fieldLength = 15 ;
                        tabs = 5 ;
                        selection = 1 ;
                    }break;
                    default :
                    {
                        char c[100]="invalid input.choose between fields";
                        showMessage(c);
                    }
            }
        }
            int i , j ;
            for(i = 0 ; i < fieldLength +2 ; i++ )
            {
                for (j = 0 ; j < fieldLength +2 ; j++ )
                {
                    field[1][i][j] = 79 ;
                    field[0][i][j] = 0 ;
                }
            }
            //kashtan bbomb ha
            int k = 0 ;
            srand( time(NULL) );
            while(k<numOfBombs)
            {
                int i , j ;
                i = 1 + rand() % (fieldLength ) ;
                j = 1 + rand() % (fieldLength ) ;
                if ( field[0][i][j] == 0 )
                {
                    //locating bombs if you cant win :) uncomment next line
                    //printf("%d %d\n",i,j);
                    field[0][i][j] = 42 ;
                    k++;
                }
            }
            //shomare gozari khaneh ha
            k = 0;
            for( i = 1 ; i < fieldLength +1 ; i++ )
        {
            for( j = 1 ; j < fieldLength +1 ; j++ )
            {
                if( field[0][i][j] != 42 )
                {
                    int a , b ,k = 0 ;
                    for( a = i-1 ; a <= i+1 ; a++ )
                    {
                        for( b = j-1 ; b <= j+1 ; b++ )
                        {
                            if ( !(i==a && j==b) && ( field[0][a][b] == 42 ) )
                            {
                                k++ ;
                            }
                        }
                    }
                    field[0][i][j] = k ;
                    k = 0;
                }
            }
        }
    //game starts . . .
    int bombHit = 0 ;
    int win_or_loose;
    char R_or_F;
    int bombNum = numOfBombs;
    int x , y ;
    char xx,yy;
    while ( bombHit == 0 )
    {
        int validInput =1;
        while ( validInput )
        {
            setbkcolor(GREEN);
            cleardevice();
            settextstyle(1,0,1);
            drawField(fieldLength,field[1],410,110,&xx,&yy,&R_or_F,1,&repeat,bombNum);
            x=((int)xx)-96;
            y=((int)yy)-96;
            validInput = !valid_input(x,y,fieldLength,R_or_F);
        }
        if ( R_or_F == 114 )
        {
            if ( field[0][x][y] != 42 && field[0][x][y]==0 )
            {
                clearing(field,x,y,fieldLength);
                if(field[1][x][y]==63)
                {
                    bombNum++;
                }
            }
            else
                {
                    if( field[0][x][y]<9 && field[0][x][y]>0 )
                    {
                        field[1][x][y]= 48 + field[0][x][y];
                        if(field[1][x][y]==63)
                        {
                            bombNum++;
                        }
                    }else
                    {
                        bombHit = 1;
                        win_or_loose = 0 ;
                        int i , j ;
                        for( i = 0 ; i < fieldLength+1 ; i++ )
                        {
                            for( j = 0 ; j < fieldLength+1 ; j++ )
                            {
                                if(field[0][i][j] == 42)
                                {
                                    field[1][i][j] = 42 ;
                                }
                            }
                        }
                        drawField(fieldLength,field[1],410,110,&xx,&yy,&R_or_F,0,&repeat,bombNum);
                    }
                }
        }else
        {
            if( R_or_F == 63 )
            {
                if(field[1][x][y]==63)
                {
                    field[1][x][y]=79;
                     bombNum+=1;
                }else;
                if(field[1][x][y]==79)
                {
                    field[1][x][y]=63;
                     bombNum-=1;
                }else;
                if(field[1][x][y]>=1 && field[1][x][y]<=8)
                {
                    char aaa[40]= "this square cant be flagged";
                    showMessage(aaa);
                }else;
            }
        }
        if( winChecker(field[1],fieldLength,numOfBombs ) )
                {
                    win_or_loose = 1 ;
                    bombHit = 1 ;
                }else;
    }
    if(win_or_loose)
    {
        setbkcolor(GREEN);
        setcolor(YELLOW);
        settextstyle(1,0,6);
        setbkcolor(GREEN);
        outtextxy(400,200,"YOU WON !!!");
        settextstyle(1,0,3);
        outtextxy(415,115,"do you want to play again?");
        outtextxy(480,145,"         Y  or  N ? ");
        repeat=getch();

    }else;
    if(repeat == 89 || repeat == 121)
    {
        repeat_game = 1;
    }else
    {
        repeat_game = 0;
    }

    }
    setbkcolor(GREEN);
    cleardevice();
    settextstyle(1,0,5);
    outtextxy(115,135,"******* THANKS FOR PLAYING ! ********");
    getch();
}
