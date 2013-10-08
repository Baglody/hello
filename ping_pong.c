#include<stdio.h>
#include<stdlib.h>
#include<disp.h>

////////////////////// lm3s_disp_print ("asdas",longer_side,shoter_side,level);
int draw_tables(int i,int loc_i,int loc_r,int flag)
{
int temp_i=i;
int temp_r=loc_r;
	lm3s_disp_print(" ",1,--temp_i,10);
	//if (loc_i <10)
	//	printf("%d %d %d \n",loc_i,loc_r,i);
	if (loc_i ==1 & ~(loc_r <=i+5 & loc_r >=i-5)) {lm3s_disp_print("you lose",20,20,10);return 1;}
        lm3s_disp_print("|",1,i,10);
        lm3s_disp_print(" ",120,--temp_r,10);        
        lm3s_disp_print("|",120,loc_r,10);
	return 0;
}

void ping (int *flag,int *i,int *r, int *pattern)
{
        if (*flag==1){
		lm3s_disp_print(" ",*i,*r,10);
		if (*pattern ==0)
	                lm3s_disp_print("*",++(*i),++(*r),10);
		else if (*pattern ==1)
	                lm3s_disp_print("*",++(*i),(*r),10);
		else if (*pattern ==2)
	                lm3s_disp_print("*",++(*i),--(*r),10);
		if ( *r >= 90) *flag=0; 
		if (*r <= 2) *flag=0; 
		if(*i ==120) {*flag=2; *pattern=rand()%3;}
		//printf("%d %d %d in flag=1\n",*pattern,*r,*i);
	}
        else if (*flag==0){
		lm3s_disp_print(" ",*i,*r,10);
		if (*pattern ==0)
	                lm3s_disp_print("*",++(*i),--(*r),10);
		else if (*pattern ==1)
			lm3s_disp_print("*",++(*i),(*r),10);
		else if (*pattern ==2)
			lm3s_disp_print("*",++(*i),++(*r),10);
		if (*r >= 90) *pattern =0;
		if (*r <= 2) {*pattern=2;}
		if(*i ==120) {*flag=2; *pattern=rand()%3;}
		
	}
}

void pong (int *flag,int *i,int *r, int *pattern)
{
        if (*flag==2){
		lm3s_disp_print(" ",*i,*r,10);
		if (*pattern ==0)
                	lm3s_disp_print("*",--(*i),++(*r),10);
		else if (*pattern ==1)
                	lm3s_disp_print("*",--(*i),(*r),10);
		else if (*pattern ==2)
			lm3s_disp_print("*",--(*i),--(*r),10);
		if (*r >= 90) *flag=3;
		if (*r <=3) {*flag=3;}
		if(*i==1) {*flag=1;*pattern=rand()%3;}
		
	}
        else if (*flag ==3){
		lm3s_disp_print(" ",*i,*r,10);
		if (*pattern ==0)
	                lm3s_disp_print("*",--(*i),--(*r),10);
		else if (*pattern ==1)
	                lm3s_disp_print("*",--(*i),(*r),10);
		else if (*pattern ==2)
			lm3s_disp_print("*",--(*i),++(*r),10);
		if (*r >= 90) *pattern=0;
		if (*r <=3) {*pattern=2;}
		if(*i==1) {*flag=1;*pattern=rand()%3;}
		
	}
}


int main()
{

lm3s_disp_init(1000000);
lm3s_disp_on();
int i=10;
int t_2=3 ; int t_1=3;
/*int r=30;
for(i=0;i<128;i++)
{

        lm3s_disp_clear();
        lm3s_disp_print("*",i,r++,10);
        if (r==115)r=30;
        if(t_1>77)t_1=3;
        //if(t_2>77)t_2=3;
        draw_tables(t_1++,r);
}*/
//int temp=rand() %2;
int r=0;
int flag=1;
int check_lose;
int pattern=rand()%3;
while(1)
{
        //lm3s_disp_clear();
        if (flag ==1 | flag==0 )
                ping(&flag, &i,&r,&pattern);
        if (flag ==2 | flag==3 )
	pong(&flag, &i,&r,&pattern);
		//lm3s_disp_print("0",i++,r++,10);
	 //else
                //pong(flag, &i,&r);
        //if(r==95)flag=0;
        //else if(r==5 & flag ==0 ){flag=1;break;}
        //if(i==120) pinging=0;

        //draw_tables(t_1,i,r,flag);
	if (draw_tables(r,i,r,flag))
	{
		lm3s_disp_clear();
		lm3s_disp_print("You Lose",20,20,10);
		break;
	}

	//if ( i <1 | i>= 128) break;
}
//lm3s_disp_off();
return 0;
}


