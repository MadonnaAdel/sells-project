#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct product product;
typedef struct category category;
typedef struct superMarket superMarket;

//my struct for this project
struct product{
    char proName[30];
    float price;
    int qountity;
};

struct category{
    char catName[20];
    product products[20];
    int proCount;
};

struct superMarket {
    category categoreys[20];
    int catCount;
};




//initial function
void initial( superMarket *s){
    s->catCount=2;

    for (int i = 0;i < 2 ;i++)
    {
      s->categoreys[i].proCount =2;
    }
     strcpy( s->categoreys[0].catName , "Clothes");

     strcpy( s->categoreys[0].products[0].proName , "blouse");
             s->categoreys[0].products[0].price =20 ;
             s->categoreys[0].products[0].qountity =20 ;

     strcpy( s->categoreys[0].products[1].proName , "Pants");
             s->categoreys[0].products[1].price =20 ;
             s->categoreys[0].products[1].qountity =20 ;



     strcpy( s->categoreys[1].catName , "shoes");

     strcpy( s->categoreys[1].products[0].proName , "boot");
             s->categoreys[1].products[0].price =20 ;
             s->categoreys[1].products[0].qountity =20 ;

     strcpy( s->categoreys[1].products[1].proName , "half boot");
             s->categoreys[1].products[1].price =20 ;
             s->categoreys[1].products[1].qountity =20 ;

 }


//display function to display our data
 void displayProduct (superMarket *s){

        for(int i =0 ;i<s->catCount ;i++)
            {
                printf("Category Name: %s \n", s->categoreys[i].catName);

                for(int j=0 ; j < s->categoreys[i].proCount ;j++ )
                    {
                    printf("\n \t Product Name: %s    Product Price: %.2f   Product Qountity: %d ", s->categoreys[i].products[j].proName,
                    s->categoreys[i].products[j].price,s->categoreys[i].products[j].qountity);
                    }
                    printf("\n\n\n");
          }
 }


//add funstion to add new category and check on the name of category
void addCategory(superMarket *s){

        char Name[10];
        char yORn;

        printf("plz enter name of new category: \n");
        scanf("%s", Name);

        int findIndex= -1;

        for (int i = 0; i < s->catCount; i++) {

            if (strcmp(s->categoreys[i].catName, Name) == 0)
            {
                findIndex = i;
                break;
            }
        }

        if (findIndex == -1)
            {

                strcpy(s->categoreys[s->catCount].catName, Name);
                s->categoreys[s->catCount].proCount=0;
                s->catCount++;

                printf("Category is added.\n");
            }
        else{

            printf("\n\nThis name is taken. Please enter another category name.\n\n");

            }

            printf("do you wont add anther category? plz answer with(y/n) \n");
            scanf("%s", &yORn);

                    while(yORn == 'y')
                    {
                       printf("plz enter name of new category: \n");
                        scanf("%s", Name);

                        int findIndex= -1;

                        for (int i = 0; i < s->catCount; i++) {

                            if (strcmp(s->categoreys[i].catName, Name) == 0)
                            {
                                findIndex = i;
                                break;
                            }
                        }

                        if (findIndex == -1)
                            {

                                strcpy(s->categoreys[s->catCount].catName, Name);
                                s->categoreys[s->catCount].proCount=0;
                                s->catCount++;

                                printf("Category is added.\n");

                            }
                            else
                            {

                               printf("\n\nThis name is taken. Please enter another category name.\n\n");

                            }
                              printf("do you wont add anther category? plz answer with(y/n) \n");
                                scanf("%s", &yORn);
                    }
 }


//remove function to remove category from our program
void removeCategory(superMarket *s){

    char name[10];
    printf("enter name category you wanted remove\n");
    scanf("%s", name);

    int findIndex = -1;
    for(int i = 0; i< s->catCount ; i++){

       if(strcmp(s->categoreys[i].catName,name)==0){
        findIndex = i;
        break;
       }
    if(findIndex != -1)
        {

        for(int i = findIndex; i<s->catCount ;i++)
            {

            s->categoreys[i]= s->categoreys[i+1];
            s->catCount--;
            printf("category is removed\n");
           }
        }
    }
}


//add product
void addProduct(superMarket *S){

    char catName[30];
    char pName[30];
    int p,q;
    int categoryIndex = -1;
    int proIndex=-1;
    char yORn;

    printf("Enter name of category that you wont add product \n");
    scanf("%s",catName);

    for(int i=0; i<S->catCount ; i++)
    {

       if(strcmp(S->categoreys[i].catName, catName)==0)
          {
              categoryIndex=i;
              break;
          }
    }

   if(categoryIndex!=-1)
    {

        printf("Enter name of product \n");
        scanf("%s",pName);

            for(int i=0; i<S->categoreys[categoryIndex].proCount ; i++)
            {

               if(strcmp(S->categoreys[categoryIndex].products[i].proName, pName)==0)
              {
                  proIndex=i;
                  break;
              }
           }
       if(proIndex!= -1)
       {
          printf("(%s) there is alledy be here \n",pName);
       }
       else
       {
            if(S->categoreys[categoryIndex].proCount < 30)
                    {
                        printf("Enter price of price \n");
                        scanf("%d",&p);


                          printf("Enter price of qountity \n");
                          scanf("%d",&q);

                       strcpy(S->categoreys[ categoryIndex].products[S->categoreys[ categoryIndex].proCount].proName , pName);
                       S->categoreys[categoryIndex].products[S->categoreys[categoryIndex].proCount].price=p;
                       S->categoreys[categoryIndex].products[S->categoreys[categoryIndex].proCount].qountity=q;
                       S->categoreys[categoryIndex].proCount++;
                    }

              printf("your added this success\n");


     }
    }
     else
          {
              printf("(%s) there is not be here \n",catName);

          }




            printf("do you wont add anther category? plz answer with(y/n) \n");
             yORn=getche();

                    while(yORn == 'y'){
                        printf("\n Enter name of category that you wont add product \n");
                        scanf("%s",catName);

                        for(int i=0; i<S->catCount ; i++)
                        {

                           if(strcmp(S->categoreys[i].catName, catName)==0)
                              {
                                  categoryIndex=i;
                                  break;
                              }
                        }

                       if(categoryIndex!=-1)
                        {

                            printf("Enter name of product \n");
                            scanf("%s",pName);

                                for(int i=0; i<S->categoreys[categoryIndex].proCount ; i++)
                                {

                                   if(strcmp(S->categoreys[categoryIndex].products[i].proName, pName)==0)
                                  {
                                      proIndex=i;
                                      break;
                                  }
                               }
                           if(proIndex!= -1)
                           {
                              printf("(%s) there is alledy be here \n",pName);
                           }
                           else
                           {
                                if(S->categoreys[categoryIndex].proCount < 30)
                                        {
                                            printf("Enter price of price \n");
                                            scanf("%d",&p);


                                              printf("Enter price of qountity \n");
                                              scanf("%d",&q);

                                           strcpy(S->categoreys[ categoryIndex].products[S->categoreys[ categoryIndex].proCount].proName , pName);
                                           S->categoreys[categoryIndex].products[S->categoreys[categoryIndex].proCount].price=p;
                                           S->categoreys[categoryIndex].products[S->categoreys[categoryIndex].proCount].qountity=q;
                                           S->categoreys[categoryIndex].proCount++;
                                        }

                                  printf("your added this success\n");


                         }
                        }
                         else
                              {
                                  printf("(%s) there is not be here \n",catName);

                              }
                                printf("do you wont add anther product? plz answer with(y/n) \n");
                                scanf("%s", &yORn);

                    }
}



//remove product
void removeProduct(superMarket *s){

    char Name[10];

    printf("enter name of category you wont remove from it product \n");
    scanf("%s",Name);

    int catIndex= -1;

    for(int i=0; i< s->catCount ;i++)
    {
        if(strcmp(s->categoreys[i].catName,Name)==0)
        {
            catIndex= i;
            break;
        }
    }

     char pName[10];

    printf("enter name of product you wont delet it \n");
    scanf("%s",pName);

    int proIndex= -1;

    if(catIndex != -1){
        for(int i=0 ; i< s->categoreys[catIndex].proCount; i++){
            if(strcmp(s->categoreys[catIndex].products[i].proName,pName)==0){
                proIndex = i;
                break;
            }
        }
    }

    if(proIndex != -1){
        for(int i = proIndex; i<s->categoreys[catIndex].proCount;i++){

            s->categoreys[catIndex].products[i]=s->categoreys[catIndex].products[i+1];
            s->categoreys[catIndex].proCount --;
        }
    }
}


//move product from category to another category

void moveProduct(superMarket *s){

    if(s->catCount > 1){

        char sourName[10];
        int sourIndex= -1 ;

        printf("enter name of category you wont move product from it \n");
        scanf("%s",sourName);

        for(int i=0 ; i<s->catCount; i++)
        {

            if(strcmp(s->categoreys[i].catName,sourName)==0)
            {
                sourIndex=i;
                break;
            }
        }

       int proIndex = -1;

       char pName[10];

        printf("enter name of product you wont move it \n");
        scanf("%s",pName);

        for(int i = 0 ; i< s->categoreys[sourIndex].proCount; i++)
        {

            if(strcmp(s->categoreys[sourIndex].products[i].proName,pName)==0)
            {
                proIndex=i;
                break;
            }
        }

           int desIndex = -1;
           char desName[10];

         printf("enter name of destination category you wont move product to it \n");
        scanf("%s",desName);

        for(int i = 0 ; i< s->catCount; i++)
        {

            if(strcmp(s->categoreys[i].catName,desName)==0)
            {
                desIndex=i;
                break;
            }
        }

        int desProductIndex =-1;

        if (desIndex != -1)
        {

             for(int i=0 ; i< s->categoreys[desIndex].proCount; i++)
            {

                if(strcmp(s->categoreys[desIndex].products[i].proName,pName)==0)
                {
                    desProductIndex = i;
                    break;
                }
            }
        }
        if(desProductIndex == -1)
        {
            s->categoreys[desIndex].products[s->categoreys[desIndex].proCount]=
            s->categoreys[sourIndex].products[proIndex];
            s->categoreys[desIndex].proCount++;

            for(int i = proIndex ; i< s->categoreys[sourIndex].proCount-1 ;i++ )
            {
                s->categoreys[sourIndex].products[i]=
                s->categoreys[sourIndex].products[i+1];

            }
                s->categoreys[sourIndex].proCount --;
                printf("\nmove the %s from %s to %s accepted ",pName,sourName,desName);
        }
    }
}


//sale product function
void saleProduct(superMarket *s){

    float totalPrice=0;
    char pName[10];
    char cName[10];
    int qountitiy;
    float price;
    int catIndex;

    printf("enter the category name that you wont sale from it\n");
    scanf("%s",cName);

    for(int i =0 ; i< s->catCount ; i++)
    {
        if(strcmp(s->categoreys[i].catName,cName)==0)
        {
            catIndex = i;
            break;
        }
    }

    int proIndex=-1;

    if(catIndex != -1)
    {
        printf("enter name of product wont to sale it \n");
        scanf("%s",pName);

        for(int i =0 ; i< s->categoreys[catIndex].proCount ; i++)
        {
            if(strcmp(s->categoreys[catIndex].products[i].proName,pName)==0)
            {
                proIndex=i;
                break;
            }
        }
    }

    if(s->categoreys[catIndex].products[proIndex].qountity>0)
    {
        printf("enter qountitiy of product you wont sale it\n");

        do
        {
            if(scanf("%d", &qountitiy) == 1 && qountitiy > 0)
               {
                    break;
               }
               else
               {
                    printf("ERORR.\n");
               }

        }while(1);

       if(qountitiy <= s->categoreys[catIndex].products[proIndex].qountity)
       {
            s->categoreys[catIndex].products[proIndex].qountity -= qountitiy;
            totalPrice+=qountitiy*s->categoreys[catIndex].products[proIndex].price;


       }else
       {
       printf("error");
       }
    }


printf(" \n\nyou sale the %s from category %s his qountity %d with total price is %2.f \n\n",pName,cName,qountitiy,totalPrice);
getchar();
}


int main()
{


     superMarket market;
    initial(&market);


    int selectedOption = 0;

    char menu[8][60] =
    {
        "Display market ",
        "Add Categorys",
        "Remove Categorys",
        "Add Products",
        "Remove Products",
        "Move Products",
        "Sell Products",
        "    Exit",
    };
    while (1)
    {
        system("cls");

         gotoxy(5, 1);
        printf("shopping \n");
        gotoxy(5, 2);
        printf(".--------------------------------------.");

        for (int i = 0; i < 8; i++)
        {

            gotoxy(2, 4 +i);

            if (selectedOption == i)
            {


                printf(">>%s <<", menu[i]);


            }
            else
            {


                printf("   %s", menu[i]);


            }

        }


        char key = _getch();
        system("cls");


        switch (key)
        {
        case 72:

            if (selectedOption <= 0)
            {
                selectedOption = 7;
            }
            else
            {
                selectedOption--;
            }

            break;

        case 80:

            if (selectedOption >= 7)
            {
                selectedOption = 0;
            }
            else
            {
                selectedOption++;
            }

            break;

        case 13:
            switch (selectedOption)
            {
            case 0:

                printf("OUR CATEGORIES & PRODUCTS: \n");

                displayProduct(&market);
                _getch();

                break;

            case 1:

                printf(" ADD CATEGORY:  ");


                displayProduct(&market);
                printf("\n\n");

                addCategory(&market);

                break;

            case 2:

                printf("REMOVE A CATEGORY: \n");

                displayProduct(&market);
                printf("\n\n");
                removeCategory(&market);


                break;

            case 3:

                printf(" ADD A NEW PRODUCT: \n");

                displayProduct(&market);
                printf("\n\n");
                addProduct(&market);
                break;

            case 4:
                printf("REMOVE A PRODUCT: \n");

                displayProduct(&market);
                printf("\n\n");
                removeProduct(&market);
                break;

            case 5:

                printf("MOVE A PRODUCT: \n");

                displayProduct(&market);
                printf("\n\n");
                moveProduct(&market);
                break;
            case 6:


                printf("SELL A PRODUCT: \n");

                displayProduct(&market);
                printf("\n\n");

                saleProduct(&market);
                getchar();
                break;

            case 7:

                return 0;
                break;
            }

            break;
        case 27:
            system("cls");
            return 0;
            break;



        }
    }

    return 0;
}


void gotoxy(short x, short y)
{
    COORD coord ={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

