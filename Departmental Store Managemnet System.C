#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

union REGS i,o;

FILE *fptr,*fp, *fb, *ftemp1, *ftemp2, *ftemp3 , *fstr, *fsprd;
char brandName[20],productName[30],productType[20],a[100],code[50],subtype[30];
char checkcode[30],hold[30];
int price,qty,uqty,cprice;
int biscook=0,sop=0,deter=0,froz=0,tpaste=0,tbrush=0,dairy=0,nutri=0,instfood=0,cook=0,bottle=0,oth=0,tin=0,choc=0,spice=0;
int dent,pfoods,frozen,soap,det,uten,croc;
int tos=-1;
int globalcount,tot;



typedef struct node
{
   int price;
   struct node* next;
}node;

node *start,*end,*q,*p,*newrec;

void push(int ele)
{
    newrec=(node*)malloc(sizeof(node));
    newrec->price=ele;
    newrec->next=NULL;
    if(start==NULL)
    {
	start=newrec;
	end=newrec;
	tos++;
	return;
    }

    newrec->next=start;
    start=newrec;
    tos++;

}

node* pop()
{
   p=start;
   start=start->next;
   p->next=NULL;
   tos--;
   return p;
}

//queue using linked list

typedef struct node1
{
    char code[30];
    int quanty;
    struct node1* next;
}node1;

node1 *start1,*end1,*r,*s,*newrec1;

void enqueue1(char z[],int q)
{
    newrec1=(node1*)malloc(sizeof(node1));
    strcpy(newrec1->code,z);
    newrec1->quanty=q;
    newrec1->next=NULL;
    if(start1==NULL)
    {
	start1=newrec1;
	end1=newrec1;
	return;
    }

    end1->next=newrec1;
    end1=newrec1;
}

node1* dequeue1()
{
    r=start1;
    start1=start1->next;
    strcpy(checkcode,r->code);
    r->next=NULL;
    return r;
}

//queue2 using linked list

typedef struct node2
{
    char code[30];
    int quanty;
    struct node2* next;
}node2;

node2 *start2,*end2,*r1,*s1,*newrec2;

void enqueue2(char z[30],int q)
{
    newrec2=(node2*)malloc(sizeof(node2));
    strcpy(newrec2->code,z);
    newrec2->quanty=q;
    newrec2->next=NULL;
    if(start2==NULL)
    {
	start2=newrec2;
	end2=newrec2;
	return;
    }

    end2->next=newrec2;
    end2=newrec2;
}

int dequeue2()
{
    r1=start2;
    start2=start2->next;
    strcpy(checkcode,r1->code);
    r1->next=NULL;
    return r1->quanty;
}



/*
void initialize()
{
    int cnt;

    fptr=fopen("productdetails.txt","a");
    fseek(fptr,0,SEEK_SET);
    if(ftell(fptr)==EOF)
    {
	soap=0;det=0;pfoods=0;frozen=0;dent=0,uten=0,croc=0;
	fclose(fptr);
    }
    else
    {
	fscanf(fp,"%d %d %d %d %d %d %d",&soap,&det,&pfoods,&frozen,&dent,&croc,&uten);
	fclose(fp);
	fclose(fptr);
    }

} */

void countstock()
{
    dent=0,pfoods=0,frozen=0,soap=0,det=0,uten=0,croc=0;
    fptr=fopen("productdetails.txt","r");
  //    fp=fopen("count.txt","w");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
    if(strcmp(productType,"soap")==0)
    {
	soap=soap+qty;
    }
     if(strcmp(productType,"detergent")==0)
    {
	det=det+qty;
    }
     if(strcmp(productType,"packagedfoods")==0)
    {
	pfoods=pfoods+qty;
    }
     if(strcmp(productType,"frozenfoods")==0)
    {
	frozen=frozen+qty;
    }
     if(strcmp(productType,"dentalcare")==0)
    {
	dent=dent+qty;
    }
    if(strcmp(productType,"utensils")==0)
    {
	uten=uten+qty;
    }
    if(strcmp(productType,"crockery")==0)
    {
	croc=croc+qty;
    }
    }
   // fprintf(fp,"%d %d %d %d %d %d %d",soap,det,pfoods,frozen,dent,croc,uten);
    fclose(fptr);
}

void displaybycount()
{
   // fp=fopen("count.txt","r");
   // fscanf(fp,"%d %d %d %d %d %d %d",&soap,&det,&pfoods,&frozen,&dent,&croc,&uten);
    printf("SOAP= %d UNITS \nDETERGENTS= %d UNITS\nPACKAGED FOODS= %d UNITS\nFROZENFOODS = %d UNITS\nDENTALCARE PRODUCTS= %d UNITS\n",soap,det,pfoods,frozen,dent);
    printf("UTENSILS = %d UNITS\nCROCKERY = %d UNITS\n",uten,croc);
  //  fclose(fp);

}

void displaybycategory()
{
    fptr=fopen("productdetails.txt","r");
    printf("\nSOAPS IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	strlwr(productType);
	if(strcmp(productType,"soap")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
    fseek(fptr,0,SEEK_SET);
    printf("\nDETERGENTS IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	 strlwr(productType);
	if(strcmp(productType,"detergent")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
     fseek(fptr,0,SEEK_SET);
    printf("\nPACKAGED FOODS IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	strlwr(productType);
	if(strcmp(productType,"packagedfoods")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
    fseek(fptr,0,SEEK_SET);
    printf("\nFROZEN FOODS IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	strlwr(productType);
	if(strcmp(productType,"frozenfoods")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
     fseek(fptr,0,SEEK_SET);
    printf("\nDENTAL CARE PRODUCTS IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	strlwr(productType);
	if(strcmp(productType,"dentalcare")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
    fseek(fptr,0,SEEK_SET);
    printf("\nUTENSILS IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	strlwr(productType);
	if(strcmp(productType,"utensils")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
    fseek(fptr,0,SEEK_SET);
    printf("\nCROCKERY IN STOCK:\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	strlwr(productType);
	if(strcmp(productType,"crockery")==0)
	{
	    printf("%s %s\n",brandName,productName);
	}
    }
    fclose(fptr);

}

void insertProductDetails()
{

    char ch,tempr[100];
    int f,pt,pst,n,i;
    int gd = DETECT, gm;

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(30,30,610,450);
	setfillstyle(SOLID_FILL,BLUE);
	bar(31,31,609,449);
	outtextxy(50,40,"INSTRUCTIONS: ");
     //	outtextxy(50,55,"1.USE UNDERSCORE '_'INSTEAD OF SPACE IN ALL PRODUCT ENTRIES");
	outtextxy(50,70,"*.CHOOSE BETWEEN THE FOLLOWING PRODUCT TYPES AND SUBTYPES : ");
	outtextxy(50,85,"(SUBTYPES ARE WRITTEN WITHIN THE BRACKETS '( )')");
	outtextxy(50,100,"* SOAPS");
	outtextxy(50,115,"* DETERGENT");
	outtextxy(50,130,"* PACKAGEDFOODS ( NUTRITIONALDRINKS, INSTANTFOODS , CHOCOLATES,");
	outtextxy(50,145,"                  BISCSANDCOOKIES  , SPICES)");
	outtextxy(50,160,"* FROZENFOODS   ( FROZENPACKS , DAIRY_PRODUCTS)");
	outtextxy(50,175,"* CROCKERY      (BOTTLES ,  OTHERS)");
	outtextxy(50,190,"* DENTALCARE    (TOOTHPASTE, TOOTHBRUSHES)");
	outtextxy(50,205,"* UTENSILS      (COOKWARE, STORAGE_TINS)");
	outtextxy(50,220," ");
	outtextxy(50,235,"ENTER CORRECT CHOICE AS PER THE ABOVE GIVEN TYPES AND SUBTYPES");
	outtextxy(50,250,"SELECT CORRECT NO. CORRESPONDING TO YOUR CHOICE");
	outtextxy(50,265,"ENTER BRAND NAME, PRODUCT NAME, PRICE AND QUANTITY PROPERLY");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(50,350,"PRESS ANY KEY TO CONTINUE ");
	getch();
	closegraph();





    fptr=fopen("productdetails.txt","a"); //OPENING THE FILE
    printf("\n\nYOU HAVE CHOSEN TO ENTER PRODUCT DETAILS\n");
    while(1)
    {
       gets(a);
       printf("ENTER BRAND NAME: ");
       gets(brandName);
       n=strlen(brandName);
       strcpy(tempr,brandName);
       for(i=0;i<n;i++)
       {
	  if(tempr[i]==' ')
	   {
		tempr[i]='_';
	   }
       }
       strcpy(brandName,tempr);
       printf("ENTER PRODUCT NAME: ");
       gets(productName);
       n=strlen(productName);
       strcpy(tempr,productName);
       for(i=0;i<n;i++)
       {
	  if(tempr[i]==' ')
	   {
		tempr[i]='_';
	   }
       }
       strcpy(productName,tempr);
       strcpy(hold,productName);
       strrev(hold);
       strcpy(code,hold);
       printf("\nMAKE SELECTION FROM FOLLOWING TYPES AND SUBTYPES\n");
       printf("1.SOAP        2.DETERGENTS  3.FROZEN FOODS  4.PACKAGED FOODS \n");
       printf("5.DENTALCARE  6.CROCKERY    7.UTENSILS \n");
   ptyp:    printf("ENTER PRODUCT TYPE: ");
       scanf("%d",&pt);

		switch(pt)
		{
			case 1: strcpy(productType,"soap");
				strcpy(subtype,"soaps");
				break;

			case 2: strcpy(productType,"detegent");
				strcpy(subtype,"detergent");
				break;
			case 3: strcpy(productType,"frozenfoods");
			    ff:	printf("\n1.DAIRY PRODUCTS  2.FROZENPACKS");
				printf("\nENTER SUBTYPE CHOICE: ");
				scanf("%d",&pst);
				switch(pst)
				{
					case 1 :strcpy(subtype,"dairyproducts");
						break;
					case 2: strcpy(subtype,"frozenpacks");
						break;
					default:printf("\nPLEASE ENTER VALID CHOICE!");
						goto ff;
				}
				break;
			case 4: strcpy(productType,"packagedfoods");
			    pff:printf("\n1.NUTRITIONAL DRINKS 2.BISCS AND COOKIES 3.INSTANTFOODS\n");
				printf("4.CHOCOLATES  5.SPICES \n");
				printf("ENTER SUBTYPE CHOICE: ");
				scanf("%d",&pst);
				switch(pst)
				{
				      case 1: strcpy(subtype,"nutritionaldrinks");
					      break;
				      case 2: strcpy(subtype,"biscsandcookies");
					      break;
				      case 3: strcpy(subtype,"instantfoods");
					      break;
				      case 4: strcpy(subtype,"chocolates");
					      break;
				      case 5: strcpy(subtype,"spices");
					      break;
				      default: printf("\nPLEASE ENTER VALID CHOICE");
					       goto pff;
				}
				break;
			case 5: strcpy(productType,"dentalcare");
			   dntl:printf("\n1. TOOTHPASTE  2.TOOTHBRUSHES  ");
				printf("\nENTER SUBTYPE CHOICE: ");
				scanf("%d",&pst);
				switch(pst)
				{
					case 1: strcpy(subtype,"toothpaste");
						break;
					case 2: strcpy(subtype,"toothbrushes");
						break;
				       default: printf("\nPLEASE ENTER VALID CHOICE");
						goto dntl;
				}
				break;
			case 6: strcpy(productType,"crockery");
			  crck: printf("\n1.BOTTLES  2.OTHERS \n");
				printf("ENTER SUBTYPE CHOICE: ");
				scanf("%d",&pst);
				switch(pst)
				{
					case 1: strcpy(subtype,"bottles");
						break;
					case 2: strcpy(subtype,"others");
						break;
				       default: printf("\nPLEASE ENTER VALID CHOICE");
						goto crck;

				}
				break;
			case 7: strcpy(productType,"utensils");
			     utns: printf("\n1.COOKWARE  2.STORAGE TINS");
				   printf("\nENTER SUBTYPE CHOICE: ");
				   scanf("%d",&pst);
				   switch(pst)
				   {
					case 1:strcpy(subtype,"cookware");
					       break;

					case 2: strcpy(subtype,"storagetins");
						break;
					default: printf("\nPLEASE ENTER VALID CHOICE");
						 goto utns;
				   }


				break;
		       default: printf("\nPLEASE ENTER VALID CHOICE");
				goto ptyp;
		}



       printf("ENTER SELLING PRICE(IN Rs):");
       scanf("%d",&price);
       printf("ENTER COST PRICE(IN Rs):");
       scanf("%d",&cprice);
       printf("ENTER QUANTITY:");
       scanf("%d",&qty);

   //    countstock(productType,qty);

       //ENTERING DETAILS INTO THE FILE
       fprintf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
       gets(a);
       printf("\nDO YOU WANT TO CONTINUE Y/N: ");

       scanf("%c",&ch);
       if(ch=='y'||ch=='Y')
       continue;
       else
       break;
    }
    fclose(fptr);
}





void displayProductDetails()
{
    int gd = DETECT ,gm,i=0,t=0,flag=0,j=0;
    char a[200];
    initgraph(&gd,&gm,"c://turboc3//bgi");
 grph:   rectangle(1,30,640,450);
	 setfillstyle(SOLID_FILL,BLUE);
	 bar(2,31,639,449);
    line(230,30,230,450);
    line(456,30,456,450);
    line(500,30,500,450);
    line(538,30,538,450);
    line(2,63,640,63);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(30,455,"PRESS ANY KEY TO CONTINUE");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtextxy(40,40,"PRODUCT NAME             PRODUCT TYPE AND SUBTYPE   PRICE QTY   CODE");
    outtextxy(40,50,"                                                    (INR)           ");
    fptr=fopen("productdetails.txt","r");
   // printf("THE PRODUCTS IN STOCK ARE AS FOLLOWS\n");
  //  printf("PRODUCT NAME      TYPE       PRICE    QUANTITY\n");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
      //	printf("%s %s %s %s %d %d %s \n",brandName,productName,productType,subtype,price,qty,code);
		if(flag==1)
		{
		  j++;
		  if(j<=t)
		  {
			 continue;
		  }
		  else
		  {
			flag = 0;
		  }

		}
		sprintf(a,"%s_%s",brandName,productName);
		outtextxy(4,65+i,a);
	   //	sprintf(a,"%s",productName);
	   //	outtextxy(75,65+i,a);
		sprintf(a,"%s",productType);
		outtextxy(232,65+i,a);
		sprintf(a,"%s",subtype);
		outtextxy(340,65+i,a);
		sprintf(a,"%d",price);
		outtextxy(458,65+i,a);
		sprintf(a,"%d",qty);
		outtextxy(502,65+i,a);
		sprintf(a,"%s",code);
		outtextxy(539,65+i,a);
		i=i+10;
		t++;
		if(t%35==0)
		{
		   getch();
		   flag=1;
		   i=0;
		   cleardevice();
		   if(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)==EOF)
		   {
			 closegraph();
			 printf("\nPRESS ENTER\n");
			 break;
		   }
		   else
		   {
		    fclose(fptr);
		    goto grph;
		   }
		}

    }
    fclose(fptr);
    getch();
    closegraph();


}

void generatebill()
{
       char procode[30],tempr[30],ch;
       int gd = DETECT , gm,i=0,n;
       char a[100],temprry[50];
       int quantity,proprice,total,ele1,ele2,ele3,flag=1,ustr,costpr;
       node *n1,*n2,*n3;
       fb=fopen("bills.txt","w");

       while(1)
       {
       gets(a);
   w:
       printf("ENTER PRODUCT NAME: ");
       gets(procode);
       n=strlen(procode);
       strcpy(temprry,procode);
       for(i=0;i<n;i++)
       {
	  if(temprry[i]==' ')
	   {
		temprry[i]='_';
	   }
       }
       strcpy(procode,temprry);
       strrev(procode);

  w1:  printf("ENTER QUANTITY: ");
       scanf("%d",&quantity);
       strcpy(tempr,procode);
       strrev(tempr);

	      ustr=superqtystr(tempr);
	      if(quantity>ustr)
	      {
		printf("\nYOU DON'T HAVE THAT MUCH STOCK IN STORE\n");
		printf("\nPLEASE ENTER CORRECT QUANTITY\n");
		goto w1;
	      }

     //	enqueue1(procode,quantity);
	enqueue2(procode,quantity);
	 fstr=fopen("storedetails.txt","r");
	 fsprd = fopen("soldprods.txt","a");
       //ENTERING DETAILS INTO THE FILE

       gets(a);

       while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
	{
	    if(strcmp(procode,code)==0)
	    {
	      proprice=price*quantity;
	      costpr = cprice*quantity;
	    //  printf("\n%d\n",proprice);
	      fprintf(fb,"%s %s %d %d\n",brandName,productName,quantity,proprice);
	      fprintf(fsprd,"%s %s %d %d %d\n",brandName,productName,quantity,proprice,costpr);
	      push(proprice);
	      if(tos==1)
	      {
		  n1=pop();
		  n2=pop();
		  ele1=n1->price;
		  ele2=n2->price;
		  ele3=ele1+ele2;
		  push(ele3);
	      }
	      flag=0;
	      break;

	    }

	}

	if(flag==1)
	{
	    printf("\nPLEASE ENTER VALID CODE !!\n");
	    goto w;
	}

       fclose(fstr);
       fclose(fsprd);
       printf("\nDO YOU WANT TO CONTINUE Y/N: ");

       scanf("%c",&ch);
       if(ch=='y'||ch=='Y')
       continue;
       else
       break;
      }

     fclose(fb);

     initgraph(&gd,&gm,"c:\\turboc3\\bgi");
     rectangle(60,60,580,420);
     setfillstyle(SOLID_FILL,BLUE);
     bar(61,61,579,419);
     line(420,60,420,420);
     line(500,60,500,420);
     line(60,400,580,400);
     line(60,90,580,90);
     settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
     outtextxy(30,30,"YOUR BILL IS AS FOLLOWS");
     outtextxy(60,430,"PRESS ANY KEY TO CONTINUE");
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(70,70,"       PRODUCT NAME                            QTY       PRICE  ");
     outtextxy(70,80,"                                              (INR)  ");
     fb=fopen("bills.txt","r");
     while(fscanf(fb,"%s %s %d %d\n",brandName,productName,&quantity,&proprice)!=EOF)
     {
      //	printf("%s %s %d %d\n",brandName,productName,quantity,proprice);
		sprintf(a,"%s",brandName);
		outtextxy(65,100+i,a);
		sprintf(a,"%s",productName);
		outtextxy(195,100+i,a);
		sprintf(a,"%d",quantity);
		outtextxy(430,100+i,a);
		sprintf(a,"%d",proprice);
		outtextxy(510,100+i,a);
		i=i+10;
     }
     n1=pop();
     total=n1->price;
     sprintf(a,"TOTAL PRICE = %d",total);
     outtextxy(63,405,a);
     fclose(fb);
     getch();
     closegraph();

}

void refreshsoldprods()
{
  fsprd = fopen("soldprods.txt","w");
  fclose(fsprd);
  return;
}

void updateproductdetails()
{
    node1* u;
    char holdnm[30];
    int temp,c=0,f=-1,c1=0,k=0;

  /*  fstr=fopen("storedetails.txt","r");
    while(fscanf(fstr,"%s %s %s %s %s %d\n",brandName,productName,productType,code,subtype,&price)!=EOF)
     {
	 c1++;
	 if(c1==1)
	 {
    xx:      strcpy(holdnm,code);
	     k++;
	     continue;
	 }
	 if(strcmp(holdnm,code)==0)
	 {
	    k++;
	    continue;
	 }

	 enqueue1(holdnm,k);
	 k=0;
	 goto xx;

     }
     enqueue1(holdnm,k);
     fclose(fstr);*/

    while(start1!=NULL)
    {
	c=0;f=-1;
	u=dequeue1();
	printf("\ncode = %s\n",checkcode);
	printf("\nqty = %d\n",u->quanty);
	fptr=fopen("productdetails.txt","r");
	ftemp1=fopen("temp1.txt","w");
	ftemp2=fopen("temp2.txt","w");
	ftemp3=fopen("temp3.txt","w");
	 while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
       {

	   if(strcmp(checkcode,code)==0)
	  {
	      if((u->quanty)<qty)
	     {
		 if(c>=1)
		 {
		  fprintf(ftemp3,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
		  continue;
		 }
		 if(f>=0)
		 {
		     fprintf(ftemp3,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
		     continue;
		 }

		 temp=u->quanty;
		 qty=qty-temp;
		 fprintf(ftemp1,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
		 c++;
		 continue;
	     }

	      if((u->quanty)>qty)
	     {
		 u->quanty=u->quanty-qty;
	     }
	     if((u->quanty)==qty)
	     {
		 f++;
		 if(f>=1||c>=1)
		 {
		    fprintf(ftemp3,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
		 }
	     }

	  }

       }

       fclose(ftemp1);
       fclose(ftemp3);
       fclose(fptr);

       fptr=fopen("productdetails.txt","r");
       while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
       {

	   if(strcmp(checkcode,code)!=0)
	  {
	      fprintf(ftemp2,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
	  }

       }

	fclose(ftemp2);
	fclose(fptr);

	fptr=fopen("productdetails.txt","w");
	ftemp1=fopen("temp1.txt","r");
	ftemp2=fopen("temp2.txt","r");
	ftemp3=fopen("temp3.txt","r");


    while(fscanf(ftemp1,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
	{
	      fprintf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
	}

    fclose(ftemp1);

    while(fscanf(ftemp2,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
      fprintf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
    }

    fclose(ftemp2);

    while(fscanf(ftemp3,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
      fprintf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,price,qty,cprice);
    }
    fclose(fptr);


    fclose(ftemp3);
 }





}


/*void employee()
{
  FILE *femp;
  int gd = DETECT , gm ;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");

  femp=fopen("employee.txt",a);

  printf("\n  */



/*void updateproductdetails()
{
    node1* nd;
    int temp,c=0,f=-1,c1=0,k=0;



     char holdnm[30];
  while(fscanf(fstr,"%s %s %s %s %s %d\n",brandName,productName,productType,code,subtype,&price)!=EOF)
  {
    c1++;
    if(c1==1)
    {
    xl: strcpy(holdnm,code);
	k++;
	continue;
    }
    if(strcmp(holdnm,code)==0)
    {
      k++;
      continue;
    }

    enqueue1(holdnm,k);
    k=0;
    goto xl;
  }
  enqueue1(holdnm,k);

    fclose(fstr);

    while(start1!=NULL)
    {
	nd=dequeue1();
       printf("\nname = %s\n",nd->code);
      printf("\nqnty = %s\n",nd->quanty);


	fptr=fopen("productdetails.txt","r");
	ftemp1=fopen("temp1.txt","w");
	ftemp2=fopen("temp2.txt","w");
	ftemp3=fopen("temp3.txt","w");
	 while(fscanf(fptr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&qty)!=EOF)
       {

	   if(strcmp(checkcode,code)==0)
	  {
	      if((nd->quanty)<qty)
	     {
		 if(c>=1)
		 {
		  fprintf(ftemp3,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
		  continue;
		 }
		 if(f>=0)
		 {
		     fprintf(ftemp3,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
		     continue;
		 }

		 temp=nd->quanty;
		 qty=qty-temp;
		 fprintf(ftemp1,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
		 c++;
		 continue;
	     }

	      if((nd->quanty)>qty)
	     {
		 nd->quanty=nd->quanty-qty;
	     }
	     if((nd->quanty)==qty)
	     {
		 f++;
		 if(f>=1||c>=1)
		 {
		    fprintf(ftemp3,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
		 }
	     }

	  }

       }

       fclose(ftemp1);
       fclose(ftemp3);
       fclose(fptr);

       fptr=fopen("productdetails.txt","r");
       while(fscanf(fptr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&qty)!=EOF)
       {

	   if(strcmp(checkcode,code)!=0)
	  {
	      fprintf(ftemp2,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
	  }

       }

	fclose(ftemp2);
	fclose(fptr);

	fptr=fopen("productdetails.txt","w");
	ftemp1=fopen("temp1.txt","r");
	ftemp2=fopen("temp2.txt","r");
	ftemp3=fopen("temp3.txt","r");


    while(fscanf(ftemp1,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&qty)!=EOF)
	{
	      fprintf(fptr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
	}

    fclose(ftemp1);

    while(fscanf(ftemp2,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&qty)!=EOF)
    {
      fprintf(fptr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
    }

    fclose(ftemp2);

    while(fscanf(ftemp3,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&qty)!=EOF)
    {
      fprintf(fptr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,qty);
    }
    fclose(fptr);


    fclose(ftemp3);
    }





} */

void storefill()
{
    int c,i;
    char brand[30],proname[30],hl[30];
    char ch;
    int proqty,tmp;

    while(1)
    {

    gets(a);
    printf("\nENTER DETAILS OF PRODUCTS WHICH YOU WANT TO ENTER: \n");
    printf("ENTER BRAND NAME: ");
    gets(brand);
    printf("\nENTER PRODUCT NAME: ");
    gets(proname);
    strcpy(hl,proname);
    for(i=0;i<strlen(hl);i++)
    {
	if(hl[i]==' ')
	{
		hl[i]='_';
	}
    }
    strcpy(proname,hl);
    printf("\nENTER QUANTITY: ");
    scanf("%d",&proqty);
    tmp=proqty;
    uqty=superqty(proname);
   /* i=isfstrempty();
    if(i==1)
    goto m;
    c=isqtyavail(proname,proqty); */

    if(proqty>uqty||uqty==0)
    {
    printf("\nYOU DONT HAVE THAT / THAT MUCH STOCK\n");
    break;
    }
    fptr=fopen("productdetails.txt","r");
    fstr=fopen("storedetails.txt","a");

    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	if(strcmp(proname,productName)==0)
	{
       /*	    if(i==1&&proqty>uqty)
	    {
		printf("\nYOU DONT HAVE THAT MUCH STOCK\n");
		goto l;
	    } */
	    if(proqty<=qty)
	    {
		for(i=0;i<proqty;i++)
		{
		    fprintf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,cprice);
		}
		proqty=0;
	    }

	  if(proqty>qty)
	  {
	    for(i=0;i<qty;i++)
	    {
	       fprintf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,cprice);
	    }
	    proqty=proqty-qty;
	  }
	}
	if(proqty==0)
	break;
    }

       fclose(fptr);
       fclose(fstr);
       strrev(proname);
       enqueue1(proname,tmp);
       gets(a);
       printf("\nDO YOU WANT TO CONTINUE Y/N: ");

       scanf("%c",&ch);
       if(ch=='y'||ch=='Y')
       continue;
       else
       break;
  }
}

void viewstoredetails()
{
    fstr=fopen("storedetails.txt","r");
    printf("THE PRODUCTS IN STORE ARE AS FOLLOWS\n");
    printf("PRODUCT NAME    TYPE    PRICE  QUANTITY\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	printf("%s   %s   %s   %d  %s  %d\n",brandName,productName,productType,price,code,cprice);
    }
    fclose(fstr);
}

void countstore()
{
    biscook=0,sop=0,deter=0,froz=0,tpaste=0,tbrush=0,dairy=0,nutri=0,instfood=0,cook=0,bottle=0,oth=0,tin=0,choc=0,spice=0;
    fstr=fopen("storedetails.txt","r");
     while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	 strlwr(subtype);
	if(strcmp(subtype,"soaps")==0)
	{
	    sop++;
	    continue;
	}
	if(strcmp(subtype,"detergent")==0)
	{
	    deter++;
	    continue;
	}
	if(strcmp(subtype,"biscsandcookies")==0)
	{
	    biscook++;
	    continue;
	}
	if(strcmp(subtype,"nutritionaldrinks")==0)
	{
	    nutri++;
	    continue;
	}
	if(strcmp(subtype,"toothpaste")==0)
	{
	    tpaste++;
	    continue;
	}
	if(strcmp(subtype,"toothbrush")==0)
	{
	    tbrush++;
	    continue;
	}
	if(strcmp(subtype,"frozenpacks")==0)
	{
	    froz++;
	}
	if(strcmp(subtype,"dairyproducts")==0)
	{
	    dairy++;
	}
	if(strcmp(subtype,"instantfoods")==0)
	{
	    instfood++;
	}
	if(strcmp(subtype,"spices")==0)
	{
	    spice++;
	}
	if(strcmp(subtype,"chocolates")==0)
	{
	    choc++;
	}
	if(strcmp(subtype,"cookware")==0)
	{
	    cook++;
	}
	if(strcmp(subtype,"storagetins")==0)
	{
	    tin++;
	}
	if(strcmp(subtype,"bottles")==0)
	{
	    bottle++;
	}
	if(strcmp(subtype,"others")==0)
	{
	    oth++;
	}
    }

    fclose(fstr);
    printf("\nSOAPS = %d\nDETERGENTS = %d\nTOOTHPASTE = %d\n",sop,deter,tpaste);
    printf("BISCUITS = %d\nTOOTHBRUSHES = %d\nDAIRY PRODUCTS = %d\n",biscook,tbrush,dairy);
    printf("FROZENPACKS = %d\nNUTRITIONAL DRINKS = %d\nINSTANTFOODS = %d",froz,nutri,instfood);
    printf("CHOCOLATES = %d\nSPICES = %d\n",choc,spice);
    printf("COOKWARE = %d\nSTORAGE TINS = %d\nBOTTLES = %d\nOTHERS = %d\n",cook,tin,bottle,oth);
}


void updatestoredetails()
{
    int ele,c=0;

    while(start2!=NULL)
    {
	c = 0;
	fstr=fopen("storedetails.txt","r");
	ftemp1=fopen("temp1.txt","w");
	ele=dequeue2();
	while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
	{
	    if(strcmp(checkcode,code)==0)
	    {
		c++;
		if(c<=ele)
		continue;
		else
		fprintf(ftemp1,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,cprice);
	    }
	    if(strcmp(checkcode,code)!=0)
	    {
		fprintf(ftemp1,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,cprice);
	    }
	}
	fclose(fstr);
	fclose(ftemp1);

       ftemp1=fopen("temp1.txt","r");
       fstr=fopen("storedetails.txt","w");

       while(fscanf(ftemp1,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
	  {
	     fprintf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,price,cprice);
	  }

	   fclose(fstr);
	   fclose(ftemp1);
    }




}

/*int isqtyavail(char prodname[30],int no)
{
    int x=0,e=0,y;
    fptr=fopen("productdetails.txt","r");
    while(fscanf(fptr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&qty)!=EOF)
    {
	if(strcmp(prodname,productName)==0)
	{
	    x=x+qty;
	}
    }
    fclose(fptr);

    fstr=fopen("storedetails.txt","r");
    while(fscanf(fstr,"%s %s %s %s %s %d\n",brandName,productName,productType,code,subtype,&price)!=EOF)
    {
	if(strcmp(prodname,productName)==0)
	{
	    e++;
	}
    }
    fclose(fstr);

    y=x-e;
    if(no>y)
    return 0;
    else
    return 1;
} */

int superqty(char prodctname[30])
{
    int x=0;
    fptr=fopen("productdetails.txt","r");
    while(fscanf(fptr,"%s %s %s %s %s %d %d %d\n",brandName,productName,productType,code,subtype,&price,&qty,&cprice)!=EOF)
    {
	if(strcmp(prodctname,productName)==0)
	{
	    x=x+qty;
	}
    }
    fclose(fptr);
    return x;
}

int superqtystr(char prodctnam[30])
{
    int x=0;
    fstr=fopen("storedetails.txt","r");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	if(strcmp(prodctnam,productName)==0)
	{
	    x++;
	}
    }
    fclose(fstr);
    return x;
}

int isfstrempty()
{
    int c;
    fstr=fopen("storedetails.txt","r");
    if(fstr==NULL)
    {
	return 1;
    }
    else
    return 0;
}

void refreshproductdetails()
{
    fptr=fopen("productdetails.txt","w");
    soap=0,det=0,pfoods=0,frozen=0,dent=0,uten=0,croc=0;
    fp=fopen("count.txt","w");
    fprintf(fp,"%d %d %d %d %d %d %d",soap,det,pfoods,frozen,dent,croc,uten);
    fclose(fp);
    fclose(fptr);
}

void refreshstoredetails()
{
    fstr=fopen("storedetails.txt","w");
    fclose(fstr);
}


void getempdetails()
{
  FILE *femp;
  char empname[30],contact[10],dob[20],med[30];
  char ch;
  int salary,i;
 // long int id = 100000;
  femp = fopen("empdet.txt","a");
  printf("\n YOU HAVE CHOSEN TO ENTER NEW EMPLOYEE RECORD\n ENTER FOLLOWING EMPLOYEE DETAILS\n\n");
  while(1)
  {
	fflush(stdin);
	printf("\nENTER EMPLOYEE NAME: ");
	gets(empname);
	strcpy(med,empname);
	for(i=0;i<strlen(med);i++)
	{
	  if(med[i]==' ')
	  {
		med[i]='_';
	  }
	}

	strcpy(empname,med);
	printf("\nENTER EMPLOYEE CONTACT NO.: ");
	gets(contact);
	printf("\nENTER EMPLOYEE DESIGNATION: ");
	gets(dob);
	strcpy(med,dob);
	for(i=0;i<strlen(med);i++)
	{
	  if(med[i]==' ')
	  {
		med[i]='_';
	  }
	}

	strcpy(dob,med);
	printf("\nENTER EMPLOYEE SALARY: ");
	scanf("%d",&salary);


	fprintf(femp,"%s %s %s %d\n",empname,contact,dob,salary);
	fflush(stdin);

 empch:	printf("\n\nDO YOU WANT TO ADD MORE EMPLOYEES?? (Y/N) : ");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y')
	continue;
	else if(ch=='n'||ch=='N')
	break;
	else
	{
		printf("\nPLEASE ENTER VALID CHOICE!!\n");
		goto empch;
	}
   }


   fclose(femp);
   printf("\n\nEMPLOYEE RECORDS HAVE BEEN SUCCESFULLY ENTERED AND STORED\n");
   printf("PRESS ENTER TO GO BACK TO PREV. SCREEN\n");
   getch();



}


void showempdetails()
{
   FILE *femp;
   char emname[30],cont[10],dob[20],a[100];
   int sal,gd = DETECT, gm, i=0;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   setfillstyle(SOLID_FILL,BLUE);
   femp = fopen("empdet.txt","r");
   while(fscanf(femp,"%s %s %s %d\n",emname,cont,dob,&sal)!=EOF)
   {
       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
       rectangle(20,20+i,350,20+i+70);
       bar(21,21+i,349,20+i+69);
       sprintf(a,"EMPLOYEE NAME: %s",emname);
       outtextxy(30,20+i+10,a);
       sprintf(a,"EMPLOYEE CONTACT NO.: %s",cont);
       outtextxy(30,20+i+20,a);
       sprintf(a,"EMLOYEE DESIGNATION: %s",dob);
       outtextxy(30,20+i+30,a);
       sprintf(a,"EMPLOYEE SALARY: %d",sal);
       outtextxy(30,20+i+40,a);
       i = i+100;
       if(i==400)
       {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(20,400,"PRESS ANY KEY TO VIEW FURTHER LIST");
		getch();
		cleardevice();
		i = 0;
       }
   }

   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(20,400,"PRESS ANY KEY TO GO BACK TO PREV. SCREEN");
   getch();
   fclose(femp);
   cleardevice();
   closegraph();




}


void delempdetails()
{
  FILE *femp,*emp;
  char ename[30],med[30],cont[11],desg[20],empname[30];
  int sal,n,i;
  fflush(stdin);
  printf("\nYOU HAVE CHOSED TO DELETE EMPLOYEE NAME");
  printf("\n\nENTER EMPLOYEE NAME TO BE REMOVED:");
  printf("\nEMPLOYEE NAME: ");
  gets(ename);
 // printf("\n name = %s",ename);
  strcpy(med,ename);
  n = strlen(med);
  for(i=0;i<n;i++)
  {
     if(med[i]==' ')
     {
	med[i]='_';
     }
  }

  strcpy(ename,med);
//  printf("\n name = %s",ename);
  emp = fopen("tempor.txt","w");
  femp = fopen("empdet.txt","r");
  while(fscanf(femp,"%s %s %s %d",empname,cont,desg,&sal)!=EOF)
  {
	if(strcmp(ename,empname)==0)
	{
	   continue;
	}
	else
	{
	   fprintf(emp,"%s %s %s %d",empname,cont,desg,sal);
	}
  }
  fclose(femp);
  fclose(emp);

  emp = fopen("tempor.txt","r");
  femp = fopen("empdet.txt","w");

  while(fscanf(emp,"%s %s %s %d",empname,cont,desg,&sal)!=EOF)
  {
      fprintf(femp,"%s %s %s %d",empname,cont,desg,sal);
  }

  printf("\n RECORD HAS BEEN DELETED SUCCESSFULLY");
  printf("\n PRESS ANY KEY TO GO BACK TO PREV. SCREEN");

  fclose(femp);
  fclose(emp);
}

void delgodprod()
{
  FILE *godw,*tempy;
  char brandnm1[50],hld[50],prodname1[50],prodtype1[30],prodsub[30],code1[50],prodname2[50];
  int i,n,price1,cpr,qty1,qty2;
  fflush(stdin);
  printf("\nYOU HAVE CHOOSED TO DELETE PRODUCTS FROM GODOWN");
  printf("\n\nENTER THE NAME OF THE PRODUCT AND ITS QUANTITY TO BE DELETED");
  printf("\nENTER PRODUCT NAME: ");
  gets(prodname1);
  strcpy(hld,prodname1);
  for(i=0;i<strlen(hld);i++)
  {
    if(hld[i]==' ')
    {
	hld[i] = '_';
    }
  }

  strcpy(prodname1,hld);
  printf("\neENTER PRODUCT QUANTITY: ");
  scanf("%d",&cpr);
  godw = fopen("productdetails.txt","r");
  tempy = fopen("tempnry.txt","w");
  while(fscanf(godw,"%s %s %s %s %s %d %d %d\n",brandnm1,prodname2,prodtype1,prodsub,code1,&price1,&qty1,&cprice)!=EOF)
  {
       if(strcmp(prodname1,prodname2)==0)
       {
		if(cpr>qty1)
		{
			cpr = cpr - qty1;
			continue;
		}
		if(cpr<qty1)
		{
			qty2 = qty1 - cpr;
			cpr = 0;
			fprintf(tempy,"%s %s %s %s %s %d %d %d\n",brandnm1,prodname2,prodtype1,prodsub,code1,price1,qty2,cprice);
			continue;
		}
		if(cpr == qty1 || cpr==0 )
		{
			cpr = 0;
			continue;
		}
       }
       else
       {
		fprintf(tempy,"%s %s %s %s %s %d %d %d\n",brandnm1,prodname2,prodtype1,prodsub,code1,price1,qty1,cprice);
       }
  }

  fclose(godw);
  fclose(tempy);

  godw = fopen("productdetails.txt","w");
  tempy = fopen("tempnry.txt","r");

  while(fscanf(tempy,"%s %s %s %s %s %d %d %d\n",brandnm1,prodname2,prodtype1,prodsub,code1,&price1,&qty1,&cprice)!=EOF)
  {
     fprintf(godw,"%s %s %s %s %s %d %d %d\n",brandnm1,prodname2,prodtype1,prodsub,code1,price1,qty1,cprice);
  }

  fclose(godw);
  fclose(tempy);

}

void showsoldprods()
{
	int qty3,sprice,cprice3;
	printf("\nTHE SOLD PRODUCTS ARE\n\n");
	fsprd = fopen("soldprods.txt","r");
	while(fscanf(fsprd,"%s %s %d %d %d\n",brandName,productName,&qty3,&sprice,&cprice3)!=EOF)
	{
	     printf("productname = %s %s qty = %d selling price = %d costprice = %d\n",brandName,productName,qty3,sprice,cprice3);
	}
	fclose(fsprd);
	printf("\n\nPRESS ANY KEY TO GO BACK");
}

void calcprofit()
{
	FILE *fprof;
	int qty4,sprice1,cprice2;
	char chh;
	long profit = 0;
	fprof = fopen("profit.txt","w");
	fsprd = fopen("soldprods.txt","r");
	while(fscanf(fsprd,"%s %s %d %d %d\n",brandName,productName,&qty4,&sprice1,&cprice2)!=EOF)
	{
	    profit = (long)(profit + (sprice1 - cprice2));

	}

	fprintf(fprof,"%ld",profit);
	fclose(fprof);
	fclose(fsprd);
	printf("\n PROFIT TILL NOW : %ld \n",profit);
	return;

}

void accountingdet()
{
   long totexp=0,totinc=0;
   int qty5,sprice2,cprice3;
   printf("\n\nTHE ACCOUNTING DETAILS ARE AS FOLLOWS:");
   fsprd =  fopen("soldprods.txt","r");

   while(fscanf(fsprd,"%s %s %d %d %d\n",brandName,productName,&qty5,&sprice2,&cprice3)!=EOF)
   {
      totexp =(long)(totexp + cprice3);
      totinc =(long)(totinc + sprice2);

   }

   fclose(fsprd);

   printf("\n TOTAL EXPENSE (TILL DATE) = Rs %ld \n",totexp);
   printf("\n TOTAL INCOME (TILL DATE) = Rs %ld \n",totinc);

}





void segbycategory()
{

    char holdname[30];
    int k=0,f=0,fg=0;
    fstr=fopen("storedetails.txt","r");
    printf("\nSOAPS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"soaps")==0)
	{

	    f++;
	    if(f==1)
	    {
     p1:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"soaps")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p1;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nDETERGENTS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"detergent")==0)
	{

	    f++;
	    if(f==1)
	    {
     p2:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"detergent")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p2;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nDAIRY PRODUCTS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"dairyproducts")==0)
	{

	    f++;
	    if(f==1)
	    {
     p3:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"dairyproducts")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p3;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nFROZENPACKS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"frozenpacks")==0)
	{

	    f++;
	    if(f==1)
	    {
     p4:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"frozenpacks")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p4;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nNUTRITIONAL DRINKS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"nutritionaldrinks")==0)
	{

	    f++;
	    if(f==1)
	    {
     p5:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"nutritionaldrinks")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p5;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nBISCUITS AND COOKIES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"biscsandcookies")==0)
	{

	    f++;
	    if(f==1)
	    {
     p6:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"biscsandcookies")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p6;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nINSTANT FOODS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"instantfoods")==0)
	{

	    f++;
	    if(f==1)
	    {
     p7:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"instantfoods")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p7;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nTOOTHBRUSHES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"toothbrush")==0)
	{

	    f++;
	    if(f==1)
	    {
     p8:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"toothbrush")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p8;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

     printf("\nTOOTHPASTE IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"toothpaste")==0)
	{

	    f++;
	    if(f==1)
	    {
     p9:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"toothpaste")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p9;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

    printf("\nCOOKWARE IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"cookware")==0)
	{

	    f++;
	    if(f==1)
	    {
     p10:     printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"cookware")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p10;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

    printf("\nSTORAGETINS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"storagetins")==0)
	{

	    f++;
	    if(f==1)
	    {
     p11:     printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"storagetins")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p11;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

    printf("\nBOTTLES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"bottles")==0)
	{

	    f++;
	    if(f==1)
	    {
     p12:     printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"bottles")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p12;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);
    f=k=0;

    printf("\nOTHER CROCKERY IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"others")==0)
	{

	    f++;
	    if(f==1)
	    {
     p13:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"others")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto p13;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fseek(fstr,0,SEEK_SET);



    fclose(fstr);
}

void secsoap()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nSOAPS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"soaps")==0)
	{

	    f++;
	    if(f==1)
	    {
     q1:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"soaps")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q1;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secdetergent()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nSOAPS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"detergent")==0)
	{

	    f++;
	    if(f==1)
	    {
     q2:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"detergent")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q2;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secnutri()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nNUTRITIONAL DRINKS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"nutrtionaldrinks")==0)
	{

	    f++;
	    if(f==1)
	    {
     q3:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"nutritionaldrinks")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q3;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secbiscook()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nBISCUITS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"biscsandcookies")==0)
	{

	    f++;
	    if(f==1)
	    {
     q4:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"biscsandcookies")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q4;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secinstfoods()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nINSTANT FOODS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"instantfoods")==0)
	{

	    f++;
	    if(f==1)
	    {
     q5:      printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"instantfoods")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q5;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}


void secthpaste()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nTOOTHPASTE IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"toothpaste")==0)
	{

	    f++;
	    if(f==1)
	    {
     q6:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"toothpaste")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q6;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secthbrush()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nTOOTHBRUSH IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"toothbrush")==0)
	{

	    f++;
	    if(f==1)
	    {
     q7:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"toothbrush")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q7;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void seccookware()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nCOOKWARE IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"cookware")==0)
	{

	    f++;
	    if(f==1)
	    {
     q8:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"cookware")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q8;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}
void secstrtin()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nSTORAGE TINS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"storagetins")==0)
	{

	    f++;
	    if(f==1)
	    {
     q9:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"storagetins")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q9;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secbottle()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nBOTTLES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"bottles")==0)
	{

	    f++;
	    if(f==1)
	    {
     q10:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"bottles")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q10;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secothers()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nOTHER CROCKERIES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"others")==0)
	{

	    f++;
	    if(f==1)
	    {
     q11:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"others")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q11;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secchocol()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nCHOCOLATES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"chocolates")==0)
	{

	    f++;
	    if(f==1)
	    {
     q12:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"chocolates")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q12;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secdairy()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nDAIRY PRODUCTS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"dairy")==0)
	{

	    f++;
	    if(f==1)
	    {
     q13:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"dairy")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q13;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secfrozpacks()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nFROZENPACKS IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"frozenpacks")==0)
	{

	    f++;
	    if(f==1)
	    {
     q14:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"frozenpacks")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q14;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

void secspices()
{
    char holdname[30];
    int k=0,f=0,fg=0;
    clrscr();
    fstr=fopen("storedetails.txt","r");
    printf("\nSPICES IN STOCK:\n");
    while(fscanf(fstr,"%s %s %s %s %s %d %d\n",brandName,productName,productType,code,subtype,&price,&cprice)!=EOF)
    {
	strlwr(subtype);
	if(strcmp(subtype,"spices")==0)
	{

	    f++;
	    if(f==1)
	    {
     q15:       printf("%s %s",brandName,productName);
	      k++;
	      strcpy(holdname,productName);
	    }
	    if(f>1)
	    {
		if(fg==1)
		{
		    fg=0;
		    continue;
		}
		if(strcmp(holdname,productName)==0)
		{
		    k++;
		    continue;
		}

		else
		{
		    if(strcmp(subtype,"spices")!=0)
		    {

			continue;
		    }

		    printf("  %d\n",k);
		    k=0;
		    fg=1;
		    goto q15;
		}

	    }


	}
    }
    printf("  %d\n",k);
    fclose(fstr);
}

int initmouse()
{
	i.x.ax = 0;
	int86(0X33, &i, &o);
	return( o.x.ax );
}

void showmouseptr()
{
	i.x.ax = 1;
	int86(0X33, &i, &o);
}


void getmousepos(int *button, int *x, int *y)
{
	i.x.ax = 3;
	int86(0X33, &i, &o);

	*button = o.x.bx;
	*x = o.x.cx;
	*y = o.x.dx;
}

void main()
{
	int status, gd = DETECT, gm, button,button1,button2, x, y, z,p ,q, r;
	int choice, c,n=1,button3,button4,button5,button6,button7,button8;
	char array[50];


	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


	while(!kbhit())
	{
	     for(n=1;n<=14;n++)
	    {
		setfillstyle(SOLID_FILL, n);

		rectangle(30,100,630,300);

		floodfill(100,150,WHITE);

		delay(300);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,2) ;
		outtextxy(45, 160, "DEPARTMENTAL STORE MANAGEMENT SYSTEM");
		outtextxy(260,200,"(DSMSYS)");
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		outtextxy(215,250,"Press ENTER to Continue");
	     }
	}

	getch();
	cleardevice();
	closegraph();

     //	initialize();
   b:	countstore();
       //	getch();
	clrscr();

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setfillstyle(HATCH_FILL,DARKGRAY);
	rectangle(0,0,640,480);
	bar(1,1,639,479);
	setfillstyle(SOLID_FILL,DARKGRAY);
	rectangle(49,49,601,401);
	rectangle(50,50,600,400);
	bar(51,51,599,399);
	rectangle(570,0,600,40);
	setfillstyle(SOLID_FILL,RED);
	bar(571,1,599,39);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(575,10,"X");
	outtextxy(280,15,"DSMSYS");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setfillstyle(SOLID_FILL,BLACK);
	bar(100,375,150,401);
	outtextxy(105,385,"ENTRY");
	bar(500,375,550,401);
	outtextxy(510,385,"EXIT");
	outtextxy(285,385,"STORE  MAP");

       //	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(169,299,241,351);
	rectangle(170,300,240,350);
	bar(171,301,239,349);
	outtextxy(175,320,"BILLDESK");
	outtextxy(205,330,"1");
	rectangle(289,299,361,351);
	rectangle(290,300,360,350);
	bar(291,301,359,349);
	outtextxy(295,320,"BILLDESK");
	outtextxy(325,330,"2");
	rectangle(409,299,481,351);
	rectangle(410,300,480,350);
	bar(411,301,479,349);
	outtextxy(415,320,"BILLDESK");
	outtextxy(445,330,"3");

	setfillstyle(SOLID_FILL,BLUE);
	rectangle(150,50,500,100);
	rectangle(151,51,325,99);
	bar(152,52,324,98);
	outtextxy(185,72,"DAIRY PRODUCTS");
	rectangle(325,51,499,99);
	bar(326,52,498,98);
	outtextxy(365,72,"FROZEN FOODS");//
	rectangle(51,124,131,276);
	rectangle(50,125,130,175);
	bar(51,126,129,174);
	outtextxy(60,142,"NUTRI");
	outtextxy(60,152,"DRINKS");
	rectangle(50,175,130,225);
	bar(51,176,129,224);
	outtextxy(60,189,"BISCUITS");
	outtextxy(60,198,"AND");
	outtextxy(60,208,"CAKES");
	rectangle(50,225,130,275);
	bar(51,226,129,274);
	outtextxy(60,240,"INSTANT");
	outtextxy(60,250,"FOOD");//
	rectangle(519,124,599,276);
	rectangle(520,125,600,175);
	bar(521,126,599,174);
	outtextxy(530,142,"CHOCOLAT");
	outtextxy(555,152,"ES");
	rectangle(520,175,600,225);
	bar(521,176,600,224);
	outtextxy(530,192,"STORAGE");
	outtextxy(530,202,"TINS");
	rectangle(520,225,600,275);
	bar(521,226,600,274);
	outtextxy(530,245,"COOKWARE");//
	rectangle(184,124,306,276);
	rectangle(185,125,245,200);
	bar(186,126,244,199);
	outtextxy(195,155,"TOOTH");
	outtextxy(195,165,"BRUSH");
	rectangle(185,200,245,275);
	bar(186,201,244,274);
	outtextxy(195,230,"TOOTH");
	outtextxy(195,240,"PASTE");
	rectangle(245,125,305,275);
	bar(246,126,304,274);
	outtextxy(252,195,"SPICES");//
	rectangle(344,124,466,276);
	rectangle(345,125,405,200);
	bar(346,126,404,199);
	outtextxy(355,162,"SOAPS");
	rectangle(345,200,405,275);
	bar(346,201,404,274);
	outtextxy(355,230,"DETER");
	outtextxy(355,240,"GENTS");
	rectangle(405,125,465,225);
	bar(406,126,464,224);
	outtextxy(410,170,"CROCKE");
	outtextxy(425,180,"RY");
	rectangle(405,225,465,275);
	bar(406,226,464,274);
	outtextxy(409,245,"BOTTLES");//

	setfillstyle(SOLID_FILL,BROWN);
      //	rectangle(550,50,600,100);
      //rectangle(551,51,599,99);
       //	bar(552,52,598,98);
      //	outtextxy(560,72,"EXIT");
	rectangle(50,420,150,470);
	rectangle(51,421,149,469);
	bar(52,422,148,468);
	outtextxy(77,445,"GODOWN");
	rectangle(270,420,370,470);
	rectangle(271,421,369,469);
	bar(272,422,368,468);
	outtextxy(284,445,"FILLSTORE");
	rectangle(490,420,590,470);
	rectangle(491,421,589,469);
	bar(492,422,588,468);
	outtextxy(502,445,"ADVANCED");
	////

	if(spice<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(246,126,304,274);
	   outtextxy(252,195,"SPICES");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(246,126,304,274);
	   outtextxy(252,195,"SPICES");
	 }//

	 if(nutri<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(51,126,129,174);
	   outtextxy(60,142,"NUTRI");
	   outtextxy(60,152,"DRINKS");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(51,126,129,174);
	   outtextxy(60,142,"NUTRI");
	   outtextxy(60,152,"DRINKS");
	 }

	 if(biscook<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(51,176,129,224);
	   outtextxy(60,189,"BISCUITS");
	   outtextxy(60,198,"AND");
	   outtextxy(60,208,"CAKES");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(51,176,129,224);
	   outtextxy(60,189,"BISCUITS");
	   outtextxy(60,198,"AND");
	   outtextxy(60,208,"CAKES");
	 }

	 if(instfood<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(51,226,129,274);
	   outtextxy(60,240,"INSTANT");
	   outtextxy(60,250,"FOOD");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(51,226,129,274);
	   outtextxy(60,240,"INSTANT");
	   outtextxy(60,250,"FOOD");
	 }

	 if(dairy<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(152,52,324,98);
	   outtextxy(185,72,"DAIRY PRODUCTS");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(152,52,324,98);
	   outtextxy(185,72,"DAIRY PRODUCTS");
	 }

	 if(froz<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(326,52,498,98);
	   outtextxy(365,72,"FROZEN FOODS");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(326,52,498,98);
	   outtextxy(365,72,"FROZEN FOODS");
	 }

	 if(tbrush<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(186,126,244,199);
	   outtextxy(195,155,"TOOTH");
	   outtextxy(195,165,"BRUSH");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(186,126,244,199);
	   outtextxy(195,155,"TOOTH");
	   outtextxy(195,165,"BRUSH");
	 }

	 if(tpaste<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(186,201,244,274);
	   outtextxy(195,230,"TOOTH");
	   outtextxy(195,240,"PASTE");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(186,201,244,274);
	   outtextxy(195,230,"TOOTH");
	   outtextxy(195,240,"PASTE");
	 }

	 if(sop<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(346,126,404,199);
	   outtextxy(355,162,"SOAPS");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(346,126,404,199);
	   outtextxy(355,162,"SOAPS");
	 }
	 ////
	  if(deter<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(346,201,404,274);
	   outtextxy(355,230,"DETER");
	   outtextxy(355,240,"GENTS");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(346,201,404,274);
	   outtextxy(355,230,"DETER");
	   outtextxy(355,240,"GENTS");
	 }

	   if(cook<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(521,226,600,274);
	   outtextxy(530,245,"COOKWARE");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(521,226,600,274);
	   outtextxy(530,245,"COOKWARE");
	 }

	  if(bottle<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(406,226,464,274);
	   outtextxy(409,245,"BOTTLES");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(406,226,464,274);
	   outtextxy(409,245,"BOTTLES");
	 }

	  if(oth<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(406,126,464,224);
	   outtextxy(410,170,"CROCKE");
	   outtextxy(425,180,"RY");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(406,126,464,224);
	   outtextxy(410,170,"CROCKE");
	   outtextxy(425,180,"RY");
	 }

	  if( tin<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(521,176,600,224);
	   outtextxy(530,192,"STORAGE");
	   outtextxy(530,202,"TINS");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(521,176,600,224);
	   outtextxy(530,192,"STORAGE");
	   outtextxy(530,202,"TINS");
	 }

	  if( choc<20)
	 {
	   setfillstyle(SOLID_FILL,RED);
	   bar(521,126,599,174);
	   outtextxy(530,142,"CHOCOLAT");
	   outtextxy(555,152,"ES");
	 }
	else
	 {
	   setfillstyle(SOLID_FILL,GREEN);
	   bar(521,126,599,174);
	   outtextxy(530,142,"CHOCOLAT");
	   outtextxy(555,152,"ES");
	 }

	settextstyle(DEFAULT_FONT,0,2);
	status = initmouse();

	if( status == 0 )
	  printf("Mouse support not available.\n");
	else
	{
	  showmouseptr();

	  getmousepos(&button,&x,&y);

	  while(!kbhit())
	  {
		getmousepos(&button,&x,&y);

		p = x;
		q = y;

		if( button == 1 )
		{

		   button = -1;
		   cleardevice();
		   goto a;

		}
		delay(100);
	  }
	}

       a :  while(button == -1)
	    {

      if((p>571 && p<599) && (q>0 && q<40))
	{
	    char ch1;
	    cleardevice();
	    closegraph();
	    printf("\nARE YOU SURE (Y/N) : ");
	    scanf("%c",&ch1);
	    if(ch1 =='y' || ch1 =='Y')
	    return;
	    else
	    goto b;

	 }
	       if((p>151&&p<325) && (q>51&&q<99))
		{
			closegraph();
			secdairy();
			button=2;
			if(getch())
			  {
			  goto b;
			  }
		}
		else if((p>325&&p<499) && (q>51&&q<99))
		     {
			closegraph();
			secfrozpacks();
			button=2;
			if(getch())
			 {
			 goto b;
			 }
		     }
		     else if((p>50&&p<130) && (q>125&&q<175))
			  {
			      closegraph();
			      secnutri();
			      button=2;
			      if(getch())
			      {
				 goto b;
			      }
			  }
			  else if((p>50&&p<130) && (q>175&&q<225))
			       {
				   closegraph();
				   secbiscook();
				   button=2;
				   if(getch())
				   {
				      goto b;
				   }
			       }
			       else if((p>50&&p<130) && (q>225&&q<275))
				    {
				       closegraph();
				       secinstfoods();
				       button=2;
				       if(getch())
				       {
					  goto b;
				       }
				    }
				    else if((p>520&&p<600) && (q>125&&q<175))
					 {
					     closegraph();
					     secchocol();
					     button=2;
					     if(getch())
					     {
						goto b;
					     }
					 }
					 else if((p>520&&p<600) && (q>175&&q<225))
					      {
						  closegraph();
						  secstrtin();
						  button=2;
						  if(getch())
						  {
						     goto b;
						  }
					      }
					      else if((p>520&&p<600) && (q>225&&q<275))
						   {
						       closegraph();
						       seccookware();
						       button=2;
						       if(getch())
						       {
							  goto b;
						       }
						   }
						   else if((p>185&&p<245) && (q>125&&q<200))
							{
							   closegraph();
							   secthbrush();
							   button=2;
							   if(getch())
							   {
							      goto b;
							   }
							}
							else if((p>185&&p<245) && (q>200&&q<275))
							     {
								 closegraph();
								 secthpaste();
								 button=2;
								 if(getch())
								 {
								    goto b;
								 }
							     }
							     else if((p>345&&p<405) && (q>125&&q<200))
								  {
								     closegraph();
								     secsoap();
								     button=2;
								     if(getch())
								     {
									goto b;
								     }
								  }
								  else if((p>345&&p<405) && (q>200&&q<275))
								       {
									   closegraph();
									   secdetergent();
									   button=2;
									   if(getch())
									   {
									      goto b;
									   }
								       }
								       else if((p>405&&p<465) && (q>125&&q<225))
									    {
									       closegraph();
									       secothers();
									       button=2;
									       if(getch())
									       {
										  goto b;
									       }
									    }
									    else if((p>405&&p<465) && (q>225&&q<275))
										 {
										    closegraph();
										    secbottle();
										    button=2;
										    if(getch())
										    {
										       goto b;
										    }
										 }

										 else if((p>245&&p<305) && (q>125&&q<275))
										      {
											 closegraph();
											 secspices();
											 button=2;
											 if(getch())
											 {
											    goto b;
											 }
										      }
										      else if((p>51&&p<149) && (q>421&&q<469))
											   {

											      /* closegraph();
*/
ab:button=2;
  setfillstyle(SOLID_FILL,GREEN);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(250,50,"GODOWN");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  rectangle(100,100,550,150);
  bar(101,101,549,149);
  outtextxy(110,120,"ENTER STOCK DETAILS");
  setfillstyle(SOLID_FILL,BLUE);
  rectangle(100,170,550,220);
  bar(101,171,549,219);
  outtextxy(110,190,"VIEW STOCK & QUANTITIES");
  setfillstyle(SOLID_FILL,CYAN);
  rectangle(100,240,550,290);
  bar(101,241,549,289);
  outtextxy(110,260,"DELETE STOCK");
  setfillstyle(SOLID_FILL,MAGENTA);
  rectangle(100,310,550,360);
  bar(101,311,549,359);
  outtextxy(110,330,"REFRESH PRODUCT LIST");
  setfillstyle(SOLID_FILL,BROWN);
  rectangle(100,380,550,430);
  bar(101,381,549,429);
  outtextxy(110,400,"BACK TO HOME SCREEN");

   showmouseptr();

   getmousepos(&button1,&x,&y);
   delay(100);
   while(!kbhit())
	  {
		getmousepos(&button1,&x,&y);

		p = x;
		q = y;

		if( button1 == 1 )
		{

		   button = -1;
		   cleardevice();
		   goto as;

		}
		delay(100);
	  }

 as: if((p>101 && q>101) && (p<549 && q<149))
  {
    cleardevice();
    closegraph();
    insertProductDetails();
    clrscr();
    printf("\n\nTHE PRODUCTS HAVE BEEN SUCCESSFULLY ADDED TO THE GODOWN");
    printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto ab;
  }

 else if((p>101 && q>171) && (p<549 && q<219))
  {
    cleardevice();
    closegraph();
    displayProductDetails();
    countstock();
    printf("\n\nPRESS ENTER TO VIEW PRODUCT QUANTITIES\n\n");
    getch();
    displaybycount();
    printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto ab;
  }

  else if((p>101 && q>241) && (p<549 && q<289))
  {
    cleardevice();
    closegraph();
   // displaybycategory();
    delgodprod();
    printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto ab;
  }

  else if((p>101 && q>311) && (p<549 && q<359))
  {
    cleardevice();
    closegraph();
    refreshproductdetails();
    printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto ab;
  }

  else if((p>101 && q>381) && (p<549 && q<429))
  {
    cleardevice();
    closegraph();
    goto b;
  }
  else
  {
   goto ab;
  }

/*	       while(1)
		     {
		o:   printf("\n\nYOU HAVE CHOSEN GODOWN\n");
		     printf("WHAT DO YOU WANT TO DO:\n");
		     printf("1-ENTER STOCK DETAILS    ");
		     printf("2-VIEW STOCK DETAILS     ");
		     printf("3-VIEW STOCK QUANTITIES   ");
		     printf("4-VIEW CATEGORIZED LIST OF STOCK\n");
		     printf("5-REFRESH STOCK DETAILS  ");
		     printf("6-BACK TO HOME SCREEN\n");
		     printf("ENTER YOUR CHOICE: ");
		     scanf("%d",&choice);
		     if(choice==6)
			goto b;
		     switch(choice)
		     {
			 case 1: {
				    insertProductDetails();
				    clrscr();

				 }break;
			 case 2: {
				    displayProductDetails();
				 }break;
			 case 3:{
				    displaybycount();
				}break;
			 case 4:{
				    displaybycategory();
				}break;
			 case 5: refreshproductdetails();
				 break;
			 default:{
				   printf("\nPLEASE ENTER CORRECT CHOICE   AGAIN\n");
				   goto o;
				 }
		       }
		    }

		    /*if(getch())
		    {
		      goto b;
		    }*/
	      }
	      else if((p>271&&p<369) && (q>421&&q<469))
		   {

		    cleardevice();
ax:		    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		    outtextxy(220,50,"STOREFILL");
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    setfillstyle(SOLID_FILL,GREEN);
		    rectangle(100,100,550,150);
		    bar(101,101,549,149);
		    outtextxy(110,120,"ENTER PRODUCTFILL DETAILS");
		    setfillstyle(SOLID_FILL,LIGHTRED);
		    rectangle(100,180,550,230);
		    bar(101,181,549,229);
		    outtextxy(110,200,"REFRESH STORE DETAILS");
		    setfillstyle(SOLID_FILL,BROWN);
		    rectangle(100,260,550,310);
		    bar(101,261,549,309);
		    outtextxy(110,280,"BACK TO HOME SCREEN");

		     showmouseptr();
		     getmousepos(&button2,&x,&y);
		     delay(100);
		     while(!kbhit())
		      {
			getmousepos(&button2,&x,&y);

			p = x;
			q = y;

			if( button2 == 1 )
			{

			   button = -1;
			   cleardevice();
			   goto ai;

			}
			delay(100);
		      }

		  ai:  if((p>101 && q>101) && (p<549 && q<149))
		      {
		       cleardevice();
		       closegraph();
		       storefill();



		       printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
		       getch();
		       updateproductdetails();
		       getch();
		       countstore();
		       getch();
		       clrscr();
		       initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		       goto ax;
		      }

		      else if((p>101 && q>181) && (p<549 && q<229))
		      {
			cleardevice();
			closegraph();
			refreshstoredetails();
			printf("\nLIST HAS BEEN REFRESHED SUCCESSFULLY\n");
			printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
			getch();
			initgraph(&gd,&gm,"c:\\turboc3\\bgi");
			goto ax;
		      }

		       else if((p>101 && q>261) && (p<549 && q<309))
		      {
		       cleardevice();
		       printf("\n\nPRESS ENTER TO GO BACK TO STOREFILL\n");
		       goto b;
		      }
		      else
		      {
		       goto ax;
		      }

		  /*     closegraph();

		       while(1)
		     {
		d:   printf("\n\nYOU HAVE CHOSEN STORE\n");
		     printf("WHAT DO YOU WANT TO DO:\n");
		     printf("1-FILL STORE DETAILS    ");
		     printf("2-REFRESH STORE DETAILS\n");
		     printf("3-BACK TO HOME SCREEN\n");
		     printf("ENTER YOUR CHOICE: ");
		     scanf("%d",&choice);
		     if(choice==3)
			goto b;
		     switch(choice)
		     {
			 case 1: storefill();
				 countstore();
				 clrscr();
				 break;

			 case 2: refreshstoredetails();
				 break;
		     }
		   }

		   /*if(getch())
		   {
		     goto b;
		   }*/
		 }
		 else if((p>170&&p<240) && (q>300&&q<350))
		      {

		    cleardevice();
ad:		    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		    outtextxy(220,50,"BILLDESK-1");
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    setfillstyle(SOLID_FILL,GREEN);
		    rectangle(100,100,550,150);
		    bar(101,101,549,149);
		    outtextxy(110,120,"GENERATE BILL");
		    setfillstyle(SOLID_FILL,LIGHTRED);
		    rectangle(100,180,550,230);
		    bar(101,181,549,229);
		    outtextxy(110,200,"BACK TO HOME SCREEN");


		     showmouseptr();
		     getmousepos(&button3,&x,&y);
		     delay(100);
		     while(!kbhit())
		      {
			getmousepos(&button3,&x,&y);

			p = x;
			q = y;

			if( button3 == 1 )
			{

			   button = -1;
			   cleardevice();
			   goto ag;

			}
			delay(100);
		      }

		  ag:  if((p>101 && q>101) && (p<549 && q<149))
		      {
		       cleardevice();
		       closegraph();
		       generatebill();
		   //    updateproductdetails();
		       updatestoredetails();
		       printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
		       getch();
		       initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		       goto ad;
		      }

		      else if((p>101 && q>181) && (p<549 && q<229))
		      {
			cleardevice();
			closegraph();
			goto b;
		      }
		      else
		      {
		       goto ad;
		      }



		  /*	 closegraph();

		     printf("WELCOME TO BILL DESK:\n");
		     while(1)
		     {
	f:            printf("SELECT YOUR CHOICE : \n");
		      printf("1-GENERATE BILL     ");

		      printf("2-BACK TO HOME SCREEN\n");
		      printf("ENTER YOUR CHOICE: ");
		      scanf("%d",&choice);
		     if(choice==2)
			goto b;
		      switch(choice)
		      {
			 case 1: {
				    generatebill();
				    updateproductdetails();
				    updatestoredetails();

				 }break;

			 default:printf("INVALID CHOICE!PLEASE TRY AGAIN \n");
				 goto f;
		      }
		     }

		  /* if(getch())
		   {
		      goto b;
		   }*/
		  }

		  else if((p>491 && p<589) && (q>421 && q<469))
		  {
       adv:	   button=2;
		   setfillstyle(SOLID_FILL,GREEN);
		   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		   outtextxy(240,50,"ADVANCED");
		   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		   rectangle(100,100,550,150);
		   bar(101,101,549,149);
		   outtextxy(110,120,"PIE CHART");
		   setfillstyle(SOLID_FILL,BLUE);
		   rectangle(100,170,550,220);
		   bar(101,171,549,219);
		   outtextxy(110,190,"EMPLOYEE DETAILS");
		   setfillstyle(SOLID_FILL,CYAN);
		   rectangle(100,240,550,290);
		   bar(101,241,549,289);
		   outtextxy(110,260,"ACCOUNTS");
		   setfillstyle(SOLID_FILL,MAGENTA);
		   rectangle(100,310,550,360);
		   bar(101,311,549,359);
		   outtextxy(110,330,"SHOW SOLD PRODUCTS");
		   setfillstyle(SOLID_FILL,BROWN);
		   rectangle(100,380,550,430);
		   bar(101,381,549,429);
		   outtextxy(110,400,"BACK TO HOME SCREEN");

		   showmouseptr();

	   getmousepos(&button6,&x,&y);
	   delay(100);
	   while(!kbhit())
	  {
		getmousepos(&button6,&x,&y);

		p = x;
		q = y;

		if( button6 == 1 )
		{

		   button = -1;
		   cleardevice();
		   goto adv1;

		}
		delay(100);
	  }

 adv1: if((p>101 && q>101) && (p<549 && q<149))
  {
    int x,y,t,v;
    float s;
    cleardevice();
    closegraph();
    countstock();
    x=getmaxx()/2;
    y=getmaxy()/2;
    tot = dent + pfoods + frozen + soap + det + uten + croc;
    printf("%d %d %d %d %d %d %d",pfoods,frozen,dent,det,soap,croc,uten);
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    circle(x,y,100);
    setfillstyle(SOLID_FILL,RED);
    s= (float)dent/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,0,v,100,100);
    t=v;
    if(t==360)
    goto pc1;
    setfillstyle(SOLID_FILL,YELLOW);
    s= (float)pfoods/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,t,v+t,100,100);
    t=v+t;
    if(t==360)
    goto pc1;
    setfillstyle(SOLID_FILL,BLUE);
    s= (float)frozen/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,t,v+t,100,100);
    t=v+t;
    if(t==360)
    goto pc1;
    setfillstyle(SOLID_FILL,GREEN);
    s= (float)soap/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,t,v+t,100,100);
    t=v+t;
    if(t==360)
    goto pc1;
    setfillstyle(SOLID_FILL,BROWN);
    s= (float)det/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,t,v+t,100,100);
    t=v+t;
    if(t==360)
    goto pc1;
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    s= (float)uten/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,t,v+t,100,100);
    t=v+t;
    if(t==360)
    goto pc1;
    setfillstyle(SOLID_FILL,CYAN);
    s= (float)croc/tot;
    s = s*360;
    v = (int)s;
    sector(x,y,t,v+t,100,100);
    t=v+t;

pc1:    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(150,30,"PIE CHART (GODOWN)");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtextxy(20,380,"PRESS ANY KEY TO GO BACK");
    rectangle(430,300,450,320);
    setfillstyle(SOLID_FILL,RED);
    bar(431,301,449,319);
    outtextxy(470,305,"DENTALCARE");
    rectangle(430,325,450,345);
    setfillstyle(SOLID_FILL,YELLOW);
    bar(431,326,449,344);
    outtextxy(470,330,"PACKAGED FOODS");
    rectangle(430,350,450,370);
    setfillstyle(SOLID_FILL,BLUE);
    bar(431,351,449,369);
    outtextxy(470,355,"FROZEN FOODS");
    rectangle(430,375,450,395);
    setfillstyle(SOLID_FILL,GREEN);
    bar(431,376,449,394);
    outtextxy(470,380,"SOAPS");
    rectangle(430,400,450,420);
    setfillstyle(SOLID_FILL,BROWN);
    bar(431,401,449,419);
    outtextxy(470,405,"DETERGENTS");
    rectangle(430,425,450,445);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(431,426,449,444);
    outtextxy(470,430,"UTENSILS");
    rectangle(430,450,450,470);
    setfillstyle(SOLID_FILL,CYAN);
    bar(431,451,449,469);
    outtextxy(470,455,"CROCKERY");
    getch();
    cleardevice();
    goto adv;
  }

 else if((p>101 && q>171) && (p<549 && q<219))
  {
empy:    cleardevice();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(150,20,"EMPLOYEE DETAILS");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setfillstyle(SOLID_FILL,RED);
    rectangle(50,100,550,150);
    bar(51,101,549,149);
    outtextxy(60,110,"ADD EMPLOYEE");
    setfillstyle(SOLID_FILL,BROWN);
    rectangle(50,190,550,240);
    bar(51,191,549,239);
    outtextxy(60,200,"REMOVE EMPLOYEE");
    setfillstyle(SOLID_FILL,MAGENTA);
    rectangle(50,280,550,330);
    bar(51,281,549,329);
    outtextxy(60,300,"EMPLOYEE ID");
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(50,370,550,420);
    bar(51,371,549,419);
    outtextxy(60,380,"BACK TO PREV. SCREEN");

	   showmouseptr();
	   getmousepos(&button7,&x,&y);
	   delay(100);
	   while(!kbhit())
	  {
		getmousepos(&button7,&x,&y);

		p = x;
		q = y;

		if( button7 == 1 )
		{

		   button = -1;
		   cleardevice();
		   goto empl;

		}
		delay(100);
	  }

empl:  if((p>51 && p<549) && (q>101 && q<149))
       {
		cleardevice();
		closegraph();
		getempdetails();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		goto empy;
       }

       else if((p>51 && p<549) && (q>191 && q<239))
       {
		cleardevice();
		closegraph();
		delempdetails();
		getch();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		goto empy;
       }

       else if((p>51 && p<549) && (q>281 && q<329))
       {
		cleardevice();
		closegraph();
		showempdetails();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		goto empy;
       }

       else if((p>51 && p<549) && (q>371 && q<419))
       {
		cleardevice();
		goto adv;
       }
       else
       {
		goto empy;
       }


    getch();
    cleardevice();

  //  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto adv;
  }

  else if((p>101 && q>241) && (p<549 && q<289))
  {

    cleardevice();
  //  closegraph();
   // settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
acc1:settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(200,20,"ACCOUNTS");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setfillstyle(SOLID_FILL,RED);
    rectangle(50,100,550,150);
    bar(51,101,549,149);
    outtextxy(60,110,"ACCOUNTING DETAILS");
    setfillstyle(SOLID_FILL,BROWN);
    rectangle(50,190,550,240);
    bar(51,191,549,239);
    outtextxy(60,200,"VIEW PROFIT");
    setfillstyle(SOLID_FILL,MAGENTA);
    rectangle(50,280,550,330);
    bar(51,281,549,329);
    outtextxy(60,300,"MANAGE EMP. SALARY");
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(50,370,550,420);
    bar(51,371,549,419);
    outtextxy(60,380,"BACK TO PREV. SCREEN");

	   showmouseptr();
	   getmousepos(&button8,&x,&y);
	   delay(100);
	   while(!kbhit())
	  {
		getmousepos(&button8,&x,&y);

		p = x;
		q = y;

		if( button8 == 1 )
		{

		   button = -1;
		   cleardevice();
		   goto acco;

		}
		delay(100);
	  }

acco:  if((p>51 && p<549) && (q>101 && q<149))
       {
		cleardevice();
		closegraph();
		accountingdet();
		printf("\n PRESS ANY KEY TO GO BACK TO PREVIOUS SCREEN");
		getch();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		goto acc1;
       }

       else if((p>51 && p<549) && (q>191 && q<239))
       {
		cleardevice();
		closegraph();
		calcprofit();
		printf("\nPRESS ANY KEY TO GO BACK");
		getch();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		goto acc1;
       }

       else if((p>51 && p<549) && (q>281 && q<329))
       {
		cleardevice();
		closegraph();
	      //	showsoldprods();
		getch();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		goto acc1;
       }

       else if((p>51 && p<549) && (q>371 && q<419))
       {
		cleardevice();
		goto adv;
       }
       else
       {
		goto acc1;
       }



    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto adv;
  }

  else if((p>101 && q>311) && (p<549 && q<359))
  {
    cleardevice();
    closegraph();
    showsoldprods();
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    goto adv;
  }

  else if((p>101 && q>381) && (p<549 && q<429))
  {
    cleardevice();
    closegraph();
    goto b;
  }
  else
  {
   goto adv;
  }

 }


		  else if((p>290&&p<360) && (q>300&&q<350))
		       {

		    cleardevice();
ad1:                button = 2;
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		    outtextxy(220,50,"BILLDESK-2");
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    setfillstyle(SOLID_FILL,GREEN);
		    rectangle(100,100,550,150);
		    bar(101,101,549,149);
		    outtextxy(110,120,"GENERATE BILL");
		    setfillstyle(SOLID_FILL,LIGHTRED);
		    rectangle(100,180,550,230);
		    bar(101,181,549,229);
		    outtextxy(110,200,"BACK TO HOME SCREEN");


		     showmouseptr();
		     getmousepos(&button4,&x,&y);
		     delay(100);
		     while(!kbhit())
		      {
			getmousepos(&button4,&x,&y);

			p = x;
			q = y;

			if( button4 == 1 )
			{

			   button = -1;
			   cleardevice();
			   goto ag1;

			}
			delay(100);
		      }

		  ag1:  if((p>101 && q>101) && (p<549 && q<149))
		      {
		       cleardevice();
		       closegraph();
		       generatebill();
		    //   updateproductdetails();
		       updatestoredetails();
		       printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
		       getch();
		       initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		       goto ad1;
		      }

		      else if((p>101 && q>181) && (p<549 && q<229))
		      {
			cleardevice();
			closegraph();
			goto b;
		      }
		      else
		      {
		       goto ad1;
		      }

			 /* closegraph();

			  printf("WELCOME TO BILL DESK:\n");
		     while(1)
		     {
	j:            printf("SELECT YOUR CHOICE : \n");
		      printf("1-GENERATE BILL     ");

		      printf("2-BACK TO HOME SCREEN\n");
		      printf("ENTER YOUR CHOICE: ");
		      scanf("%d",&choice);
		     if(choice==2)
			goto b;
		      switch(choice)
		      {
			 case 1: {
				    generatebill();
				    updateproductdetails();
				    updatestoredetails();

				 }break;

			 default:printf("INVALID CHOICE!PLEASE TRY AGAIN \n");
				 goto j;
		      }
		     }

		   /*if(getch())
		   {
		      goto b;
		   }*/
		  }
		       else if((p>410&&p<480) && (q>300&&q<350))
			    {

		    cleardevice();
ad2:		    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		    outtextxy(220,50,"BILLDESK-3");
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    setfillstyle(SOLID_FILL,GREEN);
		    rectangle(100,100,550,150);
		    bar(101,101,549,149);
		    outtextxy(110,120,"GENERATE BILL");
		    setfillstyle(SOLID_FILL,LIGHTRED);
		    rectangle(100,180,550,230);
		    bar(101,181,549,229);
		    outtextxy(110,200,"BACK TO HOME SCREEN");


		     showmouseptr();
		     getmousepos(&button5,&x,&y);
		     delay(100);
		     while(!kbhit())
		      {
			getmousepos(&button5,&x,&y);

			p = x;
			q = y;

			if( button5 == 1 )
			{

			   button = -1;
			   cleardevice();
			   goto ag2;

			}
			delay(100);
		      }

		  ag2:  if((p>101 && q>101) && (p<549 && q<149))
		      {
		       cleardevice();
		       closegraph();
		       generatebill();
		   //    updateproductdetails();
		       updatestoredetails();
		       printf("\n\nPRESS ENTER TO GO BACK TO PREVIOUS SCREEN\n");
		       getch();
		       initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		       goto ad2;
		      }

		      else if((p>101 && q>181) && (p<549 && q<229))
		      {
			cleardevice();
			closegraph();
			goto b;
		      }
		      else
		      {
		       goto ad2;
		      }

			/*       closegraph();

			       printf("WELCOME TO BILL DESK:\n");
		     while(1)
		     {
	k:            printf("SELECT YOUR CHOICE : \n");
		      printf("1-GENERATE BILL     ");

		      printf("2-BACK TO HOME SCREEN\n");
		      printf("ENTER YOUR CHOICE: ");
		      scanf("%d",&choice);
		     if(choice==2)
			goto b;
		      switch(choice)
		      {
			 case 1: {
				    generatebill();
				    updateproductdetails();
				    updatestoredetails();

				 }break;

			 default:printf("INVALID CHOICE!PLEASE TRY AGAIN \n");
				 goto k;
		      }
		     }

		   /*if(getch())
		   {
		      goto b;
		   }*/
		  }
			    else if((p>551&&p<599) && (q>51&&q<99))
				 {
				    cleardevice();
				    closegraph();
				    return ;
				 }


				 else
				 {
				    goto b;
				 }

  }


  getch();
  return;
 }

/*void main()
{
   int ch,choice;
   char c;
   clrscr();


   printf("------------------------WELCOME TO DSMSYS---------------------\n");
    initialize();
   while(1)
   {

      printf("choose ur section:\n");
      printf("1-:GODOWN    ");
      printf("2-:STORE     ");
      printf("3-:BILL DESK    ");
      printf("4-SHUTDOWN\n");
      printf("ENTER YOUR CHOICE: ");
      scanf("%d",&ch);
      if(ch==4)
      break;
      switch(ch)
      {
	  case 1:
		 {
		     while(1)
		     {
		o:   printf("\n\nYOU HAVE CHOSEN GODOWN\n");
		     printf("WHAT DO YOU WANT TO DO:\n");
		     printf("1-ENTER STOCK DETAILS    ");
		     printf("2-VIEW STOCK DETAILS     ");
		     printf("3-VIEW STOCK QUANTITIES   ");
		     printf("4-VIEW CATEGORIZED LIST OF STOCK\n");
		     printf("5-REFRESH STOCK DETAILS  ");
		     printf("6-BACK TO HOME SCREEN\n");
		     printf("ENTER YOUR CHOICE: ");
		     scanf("%d",&choice);
		     gets(a);
		     printf("\nARE YOU SURE?? Y/N : ");
		     scanf("%c",&c);
		     if(c=='Y'||c=='y')
		     goto c;
		     else
		     goto g;
		c:   if(choice==6)
		     break;
		     switch(choice)
		     {
			 case 1: {
				    insertProductDetails();
				    clrscr();

				 }break;
			 case 2: {
				    displayProductDetails();
				 }break;
			 case 3:{
				    displaybycount();
				}break;
			 case 4:{
				    displaybycategory();
				}break;
			 case 5: refreshproductdetails();
				 break;
			 default:{
				   printf("\nPLEASE ENTER CORRECT CHOICE AGAIN\n");
				   goto a;
			 }
		     }
		    }break;


	    case 2: while(1)
		     {
		a:   printf("\n\nYOU HAVE CHOSEN STORE\n");
		     printf("WHAT DO YOU WANT TO DO:\n");
		     printf("1-FILL STORE DETAILS    ");
		     printf("2- VIEW STORE DETAILS    ");
		     printf("3-VIEW STOCK QUANTITIES   ");
		     printf("4-VIEW CATEGORIZED LIST OF STOCK  ");
		     printf("5-REFRESH STORE DETAILS\n");
		     printf("6-BACK TO HOME SCREEN\n");
		     printf("ENTER YOUR CHOICE: ");
		     scanf("%d",&choice);
		     gets(a);
		     printf("\nARE YOU SURE?? Y/N : ");
		     scanf("%c",&c);
		     if(c=='Y'||c=='y')
		     goto b;
		     else
		     goto a;
		b:   if(choice==6)
		     break;
		     switch(choice)
		     {
			 case 1: storefill();
				 clrscr();
				 break;
			 case 2: viewstoredetails();
				 break;

			 case 3: countstore();
				 break;

			 case 4: segbycategory();
				 break;
			 case 5: refreshstoredetails();
				 break;
		     }
		     }
		     break;


	    case 3:   printf("WELCOME TO BILL DESK:\n");
		     while(1)
		     {
	r:            printf("SELECT YOUR CHOICE : \n");
		      printf("1-GENERATE BILL     ");

		      printf("2-BACK TO HOME SCREEN\n");
		      printf("ENTER YOUR CHOICE: ");
		      scanf("%d",&choice);
		      gets(a);
		      printf("\nARE YOU SURE?? Y/N : ");
		      scanf("%c",&c);
		      if(c=='Y'||c=='y')
		      goto g;
		      else
		      goto r;
	g:            if(choice==2)
		      break;
		      switch(choice)
		      {
			 case 1: {
				    generatebill();
				    updateproductdetails();
				    updatestoredetails();

				 }break;

			 default:printf("INVALID CHOICE!PLEASE TRY AGAIN \n");
				 goto r;
		      }
		     }

      }
   }
   }

}


  */

