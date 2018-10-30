#include<stdio.h>
#include <string.h>
#include<windows.h>
#include<time.h>

struct order
{
    char name[50];
} p[10000];

struct node
{
    int order_no,order_code,quantity;
    struct node *next;
};
struct node *start = NULL,*serial_no[100],*abcd=NULL,*output=NULL,*x,*q,*r,*s,*new_start=NULL,*temp=NULL,*prin=NULL;

void welcome(void);
int Manager_Login();
void Food_items();
void Total_Sell();
void Change_item_cost();
int linearSearch();
void Customer_Order();
void insert(int order1,int code,int qu);
void total_coustomer();
void Sorted_list(void);
void QuickSort(int p,int r);
int partition(int p,int r);
void staff_slip_Card();
void time_and_date();
void total_print(void);
int Cooker_Login(void);
int  cheack_item(int code);
void coinChanging(int pay,int total);
void check_order(void);
void Staff_Login(void);

int a[10] = {150,180,110,160,120,140,80,60,100,30};
int total_food[100];
int food_code[10]= {1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
int token_numb[1000];
int indibidualSell[1000];
int order_customer[1000];
int count_food[10];
int customer_serial_no = 0;
int order_count = 0,total_income = 0,served_count = 0,closed=0,tNumb=101,senumb=0,n1,total_cost=0,k,order=0,qu=0,code=0,node_no=0,l=0;
int Arr[20],total_print_j=0,total_amount=0,served=0,runningServe=0,count=0;;
int taka[]= {1000,500,100,50,20,10,5,2,1};
int served_order[100],running_order[1],pending_order[100],total_order[100];

int main(void)
{

    int n,m,closed=0;
    welcome();
    for( ; ; )
    {
        system ("COLOR 1F");
        printf("\n1. Manager LogIn.\n");
        printf("2. Customer Order.\n");
        printf("3. Staff LogIn.\n");
        printf("4. Cooker.\n");
        printf("5. Exit.\n");
        printf("\nPlease Choose form The Login Option: ");
        scanf("%d",&n);
first:
        switch(n)
        {
        case 1:
            system ("COLOR B1");
            printf("\n~~~~~~~~~~~~~~~~~~~~\"You LogIn Manager Site\"~~~~~~~~~~~~~~~~~~~~\n");
            closed = Manager_Login();
            break;
        case 2:
            system ("COLOR 7C");
            printf("\n~~~~~~~~~~~~~~~~~~~~\"You LogIn Customer Site\"~~~~~~~~~~~~~~~~~~~~\n\n");
            Customer_Order();
            break;
         case 3:
             system ("COLOR 8F");
             printf("\n~~~~~~~~~~~~~~~~~~~~\"You LogIn Staff Site\"~~~~~~~~~~~~~~~~~~~~\n\n");
             Staff_Login();
             break;
         case 4:
             system ("COLOR 8F");
             printf("\n~~~~~~~~~~~~~~~~~~~~\"You LogIn cooker Site\"~~~~~~~~~~~~~~~~~~~~\n\n");
             Cooker_Login();
             break;
         case 5:
             closed=1;
             break;
        default:
            printf("\nInvalid  Option. Please Enter from the above option: ");
            scanf("%d",&n);
            goto first;
        }
        if(closed == 1)
        {
            system ("COLOR 9D");
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            printf("\t\t\t\tThis project is submitted by Team \"DIU_71\"\n\n");

            printf("\t\t\t\t \tThanks will come again \t\t\t\n");
            return 0;
        }
    }
}

void welcome(void)
{
    int r;
    for(r=0; r<60; r++)
    {
        printf("__");
        Sleep(20);
    }
    Sleep(150);
    printf("\t\t\t     *     *   * * * *   *       * * * *   * * * *   *      *   * * * *\n");
    Sleep(150);
    printf("\t\t\t     *     *   *         *       *     *   *     *   * *  * *   *\n");
    Sleep(150);
    printf("\t\t\t     *  *  *   * * *     *       *   * *   *     *   *  *   *   * * *\n");
    Sleep(150);
    printf("\t\t\t     * * * *   *         *       *         *     *   *      *   *\n");
    Sleep(150);
    printf("\t\t\t     *     *   * * * *   * * *   * * * *   * * * *   *      *   * * * *\n");
    Sleep(150);
    printf("\n");
    Sleep(150);
    printf("\t\t\t                         * * * * *   * * * *\n");
    Sleep(150);
    printf("\t\t\t                             *       *     *\n");
    Sleep(150);
    printf("\t\t\t                             *       *     *\n");
    Sleep(150);
    printf("\t\t\t                             *       *     *\n");
    Sleep(150);
    printf("\t\t\t                             *       * * * *\n\n");
    Sleep(150);
    printf("\t\t\t                         *******   *    *   *****\n");
    Sleep(150);
    printf("\t\t\t                         *     *   *    *   *   *\n");
    Sleep(150);
    printf("\t\t\t                         *     *   *    *   *****\n");
    Sleep(150);
    printf("\t\t\t                         *     *   *    *   *  * \n");
    Sleep(150);
    printf("\t\t\t                         *******   ******   *   *\n\n");
    Sleep(150);
    printf("\t\t\t  * * *  * * *  * * *  * * * *   *      *    *  * * *     *      *   *  * * * *\n");
    Sleep(150);
    printf("\t\t\t  *   *  *      *         *     * *     *    *  *   *    * *     **  *     *  \n");
    Sleep(150);
    printf("\t\t\t  * * *  * * *  * * *     *    * * *    *    *  * * *   * * *    * * *     *  \n");
    Sleep(150);
    printf("\t\t\t  *  *   *          *     *   *     *   *    *  *  *   *     *   *  **     *  \n");
    Sleep(150);
    printf("\t\t\t  *   *  * * *  * * *     *  *       *  ******  *   * *       *  *   *     *  \n");
    Sleep(150);
    printf("\n");
    for(r=0; r<60; r++)
    {
        printf("__");
        Sleep(20);
    }
}


int Manager_Login()
{
    int n,m,i;
    for( ; ; )
    {
        printf("\n1. Display.\n");
        printf("2. Total Sale.\n");
        printf("3. Change you item price.\n");
        printf("4. Exit Manager site.\n");
        printf("5. Program Closed.\n");
        printf("\nPlease Choose your Option: ");
        scanf("%d",&n);
first:
        switch(n)
        {
        case 1:
            Food_items();
            break;
        case 2:
            printf("-------------------------------------------------------------------------\n");
            printf("|                               Total Sell                              |\n");
            printf("-------------------------------------------------------------------------\n\n");
            for(i=0;; i++)
            {
                if(token_numb[i]==0)
                {
                    break;
                }
                printf("Token Number is %d\n",token_numb[i]);
                printf("-------------------------------------------------------------------------\n");
                printf("|    Food Code   |    Food Name    |     Quantity     |      Taka       |\n");
                printf("-------------------------------------------------------------------------\n");
                total_print();
                printf("-------------------------------------------------------------------------\n\n");
                total_print_j++;
            }
            Total_Sell();
            total_print_j=0;
            break;
        case 3:
            Change_item_cost();
            Food_items();
            break;
        case 4:
            return 0;
        case 5:
            return 1;
        default:
            printf("\nInvalid  Option. Please Enter code: ");
            scanf("%d",&n);
            goto first;
        }
    }
}

void Food_items()
{
    printf("\n\t\t\t\tSAS Food Court MENU\t\t\t\t\n\n");
    printf("Item Code  |    Description        |  Price(tk)\t|    Available  |\n");
    printf("_________________________________________________________________\n\n");
    printf("  1001.\t   |\tChicken Pizza\t   |\t%d\t|\t%d\t|\n",a[0],total_food[0]);
    printf("  1002.\t   |\tBurger\t\t   |\t%d\t|\t%d\t|\n",a[1],total_food[1]);
    printf("  1003.\t   |\tGrilled Chicken\t   |\t%d\t|\t%d\t|\n",a[2],total_food[2]);
    printf("  1004.\t   |\tFried Chicken\t   |\t%d\t|\t%d\t|\n",a[3],total_food[3]);
    printf("  1005.\t   |\tNoodles\t\t   |\t%d\t|\t%d\t|\n",a[4],total_food[4]);
    printf("  1006.\t   |\tPasta\t\t   |\t%d\t|\t\%d\t|\n",a[5],total_food[5]);
    printf("  1007.\t   |\tOreo Shake\t   |\t%d\t|\t%d\t|\n",a[6],total_food[6]);
    printf("  1008.\t   |\tCold Coffee\t   |\t%d\t|\t%d\t|\n",a[7],total_food[7]);
    printf("  1009.\t   |\tCappuccino\t   |\t%d\t|\t%d\t|\n",a[8],total_food[8]);
    printf("  1010.\t   |\tCoke\t\t   |\t%d\t|\t%d\t|\n",a[9],total_food[9]);
    printf("_________________________________________________________________\n\n");
}

void Total_Sell()
{
    printf("\nToday Total Sell is %d.\n",total_amount);
}

void Change_item_cost()
{
    int code,size,qu,x;
    Food_items();
label:
    printf ("\nPlease Enter item code: ");
    code=linearSearch();
    switch(code)
    {
    case 1001:
        printf ("\nEnter the new price for Chicken Pizza: \n");
        scanf ("%d",&size);
        a[0]=size;
        break;
    case 1002:
        printf ("\nEnter the new price for Burger: \n");
        scanf ("%d",&size);
        a[1]=size;
        break;
    case 1003:
        printf ("\nEnter the new price for Grilled Chicken: \n");
        scanf ("%d",&size);
        a[2]=size;
        break;
    case 1004:
        printf ("\nEnter the new price for Fried Chicken: \n");
        scanf ("%d",&size);
        a[3]=size;
        break;
    case 1005:
        printf ("\nEnter the new price for Noodles: \n");
        scanf ("%d",&size);
        a[4]=size;
        break;
    case 1006:
        printf ("\nEnter the new price for Pasta: \n");
        scanf ("%d",&size);
        a[5]=size;
        break;
    case 1007:
        printf ("\nEnter the new price for Oreo Shake: \n");
        scanf ("%d",&size);
        a[6]=size;
        break;
    case 1008:
        printf ("\nEnter the new price for Cold Coffee: \n");
        scanf ("%d",&size);
        a[7]=size;
        break;
    case 1009:
        printf ("\nEnter the new price for Cappuccino: \n");
        scanf ("%d",&size);
        a[8]=size;
        break;
    case 1010:
        printf ("\nEnter the new price for Coke: \n");
        scanf ("%d",&size);
        a[9]=size;
        break;
    default :
        printf ("\nInvalid  Option.\n");
        goto label;
    }
}

int linearSearch()
{
    int i,r;
    scanf("%d",&n1);
    for(i=0; i<10; i++)
    {
        if(food_code[i]==n1)
        {
            r=food_code[i];
            return r;
        }
    }

    return -1;
}

void Customer_Order()
{
    int size,x,tf,stf=0,z,ak,pay=0;
    total_cost=0;
    qu=0;
    Food_items();
    printf ("\nPlease enter your name: ");
    scanf("%s",p[order_count].name);
    for( ; ; )
    {
        printf ("\nPlease Enter item code: ");
label:
        code=linearSearch();
        ak=cheack_item(code);
        if(ak==1)
        {
        }
        else if(ak==0)
        {
            printf("\nPlease wait a momment!! Not Available!!\n");
            printf ("\nDo you want to order anything else?\n1. Yes\n2. No\n");
lebel2:
            scanf ("%d",&z);
            if(z<0||2<z)
            {
                printf("\nInvalid  Option. Please Enter from the above option: ");
                goto lebel2;
            }
            if(z == 1)
            {
                continue;
            }
            break;
        }
        order_customer[order]=code;
        switch(code)
        {
        case 1001:
            printf ("\nChicken Pizza:\n");
pizza:
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 150*qu;
            insert(order,code,qu);
            //count_food_order();
            //count_food[order]=qu;
            total_food[0]-=qu;
            break;
        case 1002:
            printf ("Burger:\n");
burger:

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 180*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[1]-=qu;
            break;
        case 1003:
            printf ("Grilled Chicken:\n");
Grilled:

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost +=110*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[2]-=qu;
            break;
        case 1004:
            printf ("Fried Chicken:\n");
chicken:

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 160*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[3]-=qu;
            break;
        case 1005:
            printf ("Noodles:\n");
Noodles:

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 120*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[4]-=qu;
            break;
        case 1006:
            printf ("Pasta:\n");
Pasta:

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 140*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[5]-=qu;
            break;
        case 1007:
            printf ("Oreo Shake: 250mg\n");
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 80*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[6]-=qu;
            break;
        case 1008:
            printf ("Cold Coffee: 250mg\n");
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 60*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[7]-=qu;
            break;
        case 1009:
            printf ("Cappuccino:\n");
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 100*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[8]-=qu;
            break;
        case 1010:
            printf ("Coke:\n");
Coke:

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            total_cost += 30*qu;
            insert(order,code,qu);
            //count_food[order]=qu;
            total_food[9]-=qu;
            break;
        default :
            printf ("Invalid  Option. Please Enter code: ");
            goto label;
        }
        total_amount+=total_cost;
        printf ("\nDo you want to order anything else?\n1. Yes\n2. No\n");
lebel1:
        scanf("%d",&x);
        if(x<0||2<x)
        {
            printf("\nInvalid  Option. Please Enter from the above option: ");
            goto lebel1;
        }
        if (x == 1)
        {
            Food_items();
            order++;
            continue;
        }
        node_no=order+1;
        Sorted_list();
        staff_slip_Card();
        serial_no[customer_serial_no] = start;

        printf("please Pay First!!\n");
        printf("Enter here amount of money:");
        scanf("%d",&pay);
        coinChanging(pay,total_cost);

        start=NULL;
        customer_serial_no++;
        order=0;
        break;
    }
}

void insert(int order1,int code,int qu)
{
    struct node *new_node,*xyz;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->order_no = order1;
    new_node->order_code = code;
    new_node->quantity = qu;
    new_node->next = NULL;
    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        xyz=start;
        while(xyz != NULL)
        {
            if(xyz->order_code == code)
            {
                xyz->quantity += qu;
                order--;
                return;
            }
            xyz=xyz->next;
        }
        new_node->next = start;
        start = new_node;
    }
}

void total_print(void)
{


    prin=serial_no[total_print_j];
    while(prin!=NULL)
    {
        if(prin->order_code==1001)
        {
            printf("|      %d      |  Chicken Pizza  |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*150);
        }
        else if(prin->order_code==1002)
        {
            printf("|      %d      |     Burger      |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*180);
        }
        else if(prin->order_code==1003)
        {
            printf("|      %d      | Grilled Chicken |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1004)
        {
            printf("|      %d      |  Fried Chicken  |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1005)
        {
            printf("|      %d      |     Noodles     |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1006)
        {
            printf("|      %d      |      Pasta      |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1007)
        {
            printf("|      %d      |   Oreo Shake    |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1008)
        {
            printf("|      %d      |   Cold Coffee   |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1009)
        {
            printf("|      %d      |    Cappuccino   |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        else if(prin->order_code==1010)
        {
            printf("|      %d      |      Coke       |        %2d        |      %4d       |\n",prin->order_code,prin->quantity,prin->quantity*110);
        }
        prin=prin->next;
    }
    prin=NULL;
}


/*void total_coustomer()
{
    int j;
    for(j=0; j<customer_serial_no; j++)
    {
        prin=serial_no[j];
        while(prin!=NULL)
        {
            printf("%d\t %d \t%d \t\n",prin->order_code,prin->order_no,prin->quantity);
            prin=prin->next;
        }
        prin=NULL;
        printf("\n\n\n");
    }
}*/

void Sorted_list(void)
{
    int i=0,j,k;
    x=start;
    while(x->next!=NULL)
    {
        Arr[i]=x->order_code;
        x=x->next;
        i++;
    }
    q=x;
    Arr[i]=x->order_code;

    QuickSort(0,node_no-1);


    j=0;
    if(start->next==NULL)
    {
        return;
    }

    while(j<=i)
    {
        struct node *new_node1;
        new_node1 = (struct node*)malloc(sizeof(struct node));
        r=start;
        for(k=0; k<=i; k++)
        {
            if(Arr[j]==r->order_code)
            {
                new_node1->order_no = r->order_no;
                new_node1->order_code = r->order_code;
                new_node1->quantity = r->quantity;
                new_node1->next = NULL;
                break;
            }
            r=r->next;
        }
        if(new_start==NULL)
        {
            new_start=new_node1;
        }
        else
        {
            temp=new_start;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next= new_node1;
        }
        j++;
    }
    start=new_start;
}

void QuickSort(int p,int r)
{
    int q;
    if(p<r)
    {
        q = partition(p,r);
        QuickSort(p,q-1);
        QuickSort(q+1,r);
    }
}
int partition(int p,int r)
{
    int x = Arr[r],i,j,temp,k;
    i=p-1;
    for(j=p ; j<r ; j++)
    {

        if(Arr[j]<=x)
        {
            i++;
            temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    }
    temp = Arr[i+1];
    Arr[i+1] = Arr[r];
    Arr[r] = temp;
    return i+1;
}

void staff_slip_Card()
{
    int i=0;
    total_order[l]=tNumb;
    token_numb[senumb]=tNumb;
    indibidualSell[senumb]=total_cost;
    printf("                               Receipt Paper                             \n");
    printf(".........................................................................\n");
    printf("|                              SAS Food Court                           |\n");
    printf("|\tToken Number: %d                                               |\n",token_numb[senumb]);
    time_and_date();
    printf("|\tName        : %-15s                                   |\n",p[order_count].name);
    abcd=start;
    printf("-------------------------------------------------------------------------\n");
    printf("|    Food Code   |    Food Name    |     Quantity     |       Taka      |\n");
    printf("-------------------------------------------------------------------------\n");
    for(i=0; i<node_no; i++)
    {
        if(abcd->order_code==1001)
        {
            printf("|      %d      |  Chicken Pizza  |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*150);
        }
        else if(abcd->order_code==1002)
        {
            printf("|      %d      |     Burger      |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*180);
        }
        else if(abcd->order_code==1003)
        {
            printf("|      %d      | Grilled Chicken |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*110);
        }
        else if(abcd->order_code==1004)
        {
            printf("|      %d      |  Fried Chicken  |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*160);
        }
        else if(abcd->order_code==1005)
        {
            printf("|      %d      |     Noodles     |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*120);
        }
        else if(abcd->order_code==1006)
        {
            printf("|      %d      |      Pasta      |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*140);
        }
        else if(abcd->order_code==1007)
        {
            printf("|      %d      |   Oreo Shake    |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*80);
        }
        else if(abcd->order_code==1008)
        {
            printf("|      %d      |   Cold Coffee   |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*60);
        }
        else if(abcd->order_code==1009)
        {
            printf("|      %d      |    Cappuccino   |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*100);
        }
        else if(abcd->order_code==1010)
        {
            printf("|      %d      |      Coke       |        %2d        |      %4d       |\n",abcd->order_code,abcd->quantity,abcd->quantity*30);
        }
        abcd=abcd->next;

    }
    printf(".........................................................................\n");
    printf("|                                      Your Total Taka is :  %4d tk    |\n",total_cost);
    printf(".........................................................................\n");

    tNumb++;
    senumb++;
    l++;
}

void time_and_date()
{
    char* arrDayNames[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    SYSTEMTIME st;
    GetLocalTime(&st);
    printf("|\tDate        : %2d/%2d/%2d                   Time : %2d/%2d/%2d      |\n", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);

    printf("|\tThe day is : %-15s                                    |\n", arrDayNames[st.wDayOfWeek]);
}



int   cheack_item(int code)
{
    switch(code)
    {
    case 1001:
        if(total_food[0]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1002:
        if(total_food[1]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1003:
        if(total_food[2]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1004:
        if(total_food[3]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1005:
        if(total_food[4]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1006:
        if(total_food[5]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1007:
        if(total_food[6]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1008:
        if(total_food[7]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1009:
        if(total_food[8]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    case 1010:
        if(total_food[9]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 5;
}

void coinChanging(int pay,int total)
{
    int m,i,back;
    back=pay-total;
    printf("Return taka : %d \n\nMinimum Note \n",back);
    printf(".........................\n");
    for(i=0; i<9; i++)
    {
        if(taka[i]<=back)
        {
            m=back/taka[i];
            printf("  %d taka note %d times\n",taka[i],m);
            back=back%taka[i];
        }
    }
    printf(".........................\n");
}

int Cooker_Login()
{
    while(1)
    {
        int x,n,m,i;
        printf ("\nDo you want to Stored food?\n1. Yes\n2. No\n");
        scanf("%d", &x);
        if (x == 1)
        {
            Food_items();
            printf("Enter Food Code That You Stored:\n");
label:
            scanf("%d",&n);
            printf("Enter Total Food That You Stored:\n");
            scanf("%d",&m);
            switch(n)
            {
            case 1001:
                total_food[0]+=m;
                break;
            case 1002:
                total_food[1]+=m;
                break;
            case 1003:
                total_food[2]+=m;
                break;
            case 1004:
                total_food[3]+=m;
                break;
            case 1005:
                total_food[4]+=m;
                break;
            case 1006:
                total_food[5]+=m;
                break;
            case 1007:
                total_food[6]+=m;
                break;
            case 1008:
                total_food[7]+=m;
                break;
            case 1009:
                total_food[8]+=m;
                break;
            case 1010:
                total_food[9]+=m;
                break;
            default :
                printf ("Invalid  Option. Please Enter code: ");
                //break;
                goto label;
            }

        }
        else
        {
            break;
        }
    }
}
void Staff_Login(void)
{
    int n,x,i,n1;
    //Food_items();
    check_order();
    if(running_order[0]==0)
    {
        printf("Please waiting for Customer!!\n");
    }
    else
    {
        printf("%d are served?\n1.Yes\n2.No\n",running_order[0]);
        scanf("%d",&n1);
        if(n1==1)
        {
            served=1;
            runningServe=1;
            check_order();
        }
    }
}

void check_order(void)
{
    int a[1];
    int ii,i,j,l;
    printf(".....................\n");
    printf("|   Running Order   |\n");
    printf(".....................\n");
    for(i=0; i<1; i++)
    {
        if(runningServe==1)
        {
            served_order[k]=running_order[i];
            running_order[i]=total_order[k+1];
            runningServe=0;
            k++;
        }
        else
        {
            running_order[i]=total_order[k];
        }
        if(running_order[i]!=0)
        {
            printf("|\t %d\t    |\n",running_order[i]);
        }
    }
    printf(".....................\n");
    printf("|    Served Order   |\n");
    printf(".....................\n");
    for(j=0; served_order[j]!=0; j++)
    {
        printf("|\t %d\t    |\n",served_order[j]);
    }
    printf(".....................\n");
    printf("|    pending Order  |\n");
    printf(".....................\n");
    for(l=k,j=0; total_order[l]!=0; l++,j++)
    {
        pending_order[j]=total_order[l+1];
        if(pending_order[j]!=0)
        {
            printf("|\t %d\t    |\n",pending_order[j]);
        }
    }
    printf(".....................\n");

}
