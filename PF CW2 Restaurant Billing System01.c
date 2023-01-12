/*
DIPLOMA IN SOFTWARE ENGINEERING-20.2 PF-CW2 GROUP MEMBERS

CODSE202F-001 - K. H. P. SENALANKARA
CODSE202F-008 - K. A. N. D. KUMARASINGHE
CODSE202F-040 - K. H. N. L. FERNANDO
CODSE202F-051 - T. M. LAKSHAN MADURANGA WEERASINGHE
CODSE202F-053 - M. G. I. N. RUPASINGHE
*/



#include<stdio.h>
#include<string.h> //The string.h header defines one variable type, one macro, and various functions for manipulating arrays of characters

float price[22] = {200.00 , 180.00 , 170.00 , 150.00 , 230.00 , 250.00 , 300.00 , 330.00 , 350.00 , 280.00 , 280.00 , 320.00 , 450.00 , 220.00 , 250.00 , 280.00 , 80.00 , 90.00 , 90.00 , 100.00 , 100.00 , 100.00};

void main() //main function
{
    char res = 'y';
    while (res=='y' || res == 'Y')
    {
        menu();
        order();
        discountf();
        printf("%72s\n","---------------------------------------------------------");
        printf("%54s\n","THANK YOU COME AGAIN!");
        printf("%72s\n\n","---------------------------------------------------------");
        printf("\nDo you Want to Continue(y/n) ?");
        scanf("%s",&res);
        if(res=='n' || res == 'N')
        {
            break;
        }
        system("cls");

    }



}


void menu() //This functions is for selecting the items from the menu list.
{
    printf("%75s\n","----------------------------------------------------------------------");
    printf("%53s\n","WELCOME TO TASTY FOODS");
    printf("%75s\n\n","----------------------------------------------------------------------");
    printf("%43s\n","MENU");
    printf("%75s\n\n","----------------------------------------------------------------------");
    printf("%30s","FOOD TYPES\t\t\t\t\t\tPRICE\n\n");
    printf("\t\20Rice & Curry\n");
    printf("\t\t1.Rice & Curry with Chicken\t\t\tRs.200.00\n");
    printf("\t\t2.Rice & Curry with Fish\t\t\tRs.180.00\n");
    printf("\t\t3.Rice & Curry with Egg\t\t\t\tRs.170.00\n");
    printf("\t\t4.Rice & Curry (Veg)\t\t\t\tRs.150.00\n");
    printf("%75s\n","----------------------------------------------------------------------");
    printf("\t\20Fried Rice\n");
    printf("\t\t5.Vegetable Fried Rice\t\t\t\tRs.230.00\n");
    printf("\t\t6.Egg Fried Rice\t\t\t\tRs.250.00\n");
    printf("\t\t7.Chicken Fried Rice\t\t\t\tRs.300.00\n");
    printf("\t\t8.Sea Food Fried Rice\t\t\t\tRs.330.00\n");
    printf("\t\t9.Pork Fried rice\t\t\t\tRs.350.00\n");
    printf("%75s\n","----------------------------------------------------------------------");
    printf("\t\20Kottu (Dinner Only)\n");
    printf("\t\t10.Egg Kottu\t\t\t\t\tRs.280.00\n");
    printf("\t\t11.String Hopper Kottu\t\t\t\tRs.280.00\n");
    printf("\t\t12.Chicken Kottu\t\t\t\tRs.320.00\n");
    printf("\t\t13.Cheese Kottu\t\t\t\t\tRs.450.00\n");
    printf("%75s\n","----------------------------------------------------------------------");
    printf("\t\20Noodles\n");
    printf("\t\t14.Vegetable Noodles\t\t\t\tRs.220.00\n");
    printf("\t\t15.Egg Noodles\t\t\t\t\tRs.250.00\n");
    printf("\t\t16.Chicken Noodles\t\t\t\tRs.280.00\n");
    printf("%75s\n","----------------------------------------------------------------------");
    printf("\t\20Soft Drinks\n");
    printf("\t\t17.Fanta 400ml\t\t\t\t\tRs.80.00\n");
    printf("\t\t18.Sprite 400ml\t\t\t\t\tRs.90.00\n");
    printf("\t\t19.7up 400ml\t\t\t\t\tRs.90.00\n");
    printf("\t\t20.Coca-Cola 400ml\t\t\t\tRs.100.00\n");
    printf("\t\t21.Pepsi 500ml\t\t\t\t\tRs.100.00\n");
    printf("\t\t22.EGB 500ml\t\t\t\t\tRs.100.00\n");
    printf("%75s\n","----------------------------------------------------------------------");
    printf("%75s\n","----------------------------------------------------------------------");
    printf("\n   **** 5%% off for bills over Rs.2000 and 10%% off for bills over Rs.4000 ****\n ");
    printf("%75s\n","----------------------------------------------------------------------");


}
float total = 0.0,discount,final_bill,Paid_Amount,balance; //globally declared

void order() //take customer order
{
     int ItemCode[22],Quantity[22],i=0,inpt=0; //i=increment inpt=increment
     char response = 'y';


               while(response == 'y' || response == 'Y')
               {
                              printf("\n\n\t\20 Please Enter your food selection: ");
                              scanf("%d",&ItemCode[i]);

							  if(ItemCode[i]<1 || ItemCode[i]>22)
							  {
								  printf("\n\n\t\20 Sorry Invalid Food Item Code  \nagain! ");
								  continue;
							  }
                              printf("\t\20 Please Enter Quantity: ");
                              scanf("%d",&Quantity[i]);

                              total=total+ Quantity[i] * price[ItemCode[i]-1]; //subtracting 1 for getting the real value from the array

                              i=i+1;
                              inpt=inpt+1;
                              printf("\n\n\tWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);
                              if (response == 'n' || response == 'N')
                              {
                                  system("cls");
                              }

               }

               printf("%72s\n","---------------------------------------------------------");
               printf("%48s\n","TOTAL BILL");
               printf("%72s\n\n","---------------------------------------------------------");
               printf("\t\tItem Code\t\t\tQuantity\n");

               for(i=0; i<inpt ; i++)
               {
                 printf("\t\t    %d \t\t\t\t  %d\n\n ",ItemCode[i],Quantity[i]);

               }

               printf("\t\t\20 Sub Total:\t\t\t   ");
               printf("\t\t%.2f\n",total);

}
void discountf() //calculating discount bill amount according to the sub bill
{
    if (total>=2000.00 && total<4000.00)
    {
        discount=total*5/100;
        printf("\t\t\20 Discount:\t\t\t ");
        printf("\t\t %.2f",discount);
    }
    else if(total>=4000.00)
    {
       discount=total*10/100;
       printf("\t\t\20 Discount:\t\t\t ");
       printf("\t\t %.2f",discount);
    }
    else
    {
           printf("\t\t\20 Discount:\t\t\t  ");
           printf("\t\t  %.2f\n",00.00);
    }
    bill_cal();
}
void bill_cal() //calculating final bill
{
   final_bill=total-discount;
   printf("\n\t\t\20 Total Due:\t\t\t");
   printf("\t\t%.2f",final_bill);

   printf("\n\n \t\tCustomer Paid Amount: ");
   scanf("%f",&Paid_Amount);
   if(Paid_Amount<final_bill)
   {
       while(Paid_Amount<final_bill){
            printf("\t\t Insufficient Funds");
            printf("\n\n \t\tEnter Amount Again: ");
            scanf("%f",&Paid_Amount);
       }
   }
   balance=Paid_Amount-final_bill;

   printf("\t\t\20 Balance:\t\t\t");
   printf("\t\t %.2f\n",balance);

}

/*
DIPLOMA IN SOFTWARE ENGINEERING-20.2 PF-CW2 GROUP MEMBERS

CODSE202F-001 - K. H. P. SENALANKARA
CODSE202F-008 - K. A. N. D. KUMARASINGHE
CODSE202F-040 - K. H. N. L. FERNANDO
CODSE202F-051 - T. M. LAKSHAN MADURANGA WEERASINGHE
CODSE202F-053 - M. G. I. N. RUPASINGHE
*/

