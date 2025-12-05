#include<stdio.h>
#include<string.h>
#include<conio.h>

/*Declare Functions*/
void head_msg(void);
void msg_in_center(void);
void welcome_msg(void);
void menu(void);
int is_name_valid(char *name);
int is_date_valid(int date,int month,int year);
void add_vehicle_data_base(int *vehicle_count);

/*Declare max amount of individual vehicle info at a time*/
#define stock 10

/*Structure to store individual vehicle data*/
struct vehicle_info_store
{
    char vehicle_ID[50];
    char vehicle_name[80];
    char manufacturer_name[80]; 
    int issued_date, issued_month, issued_year; 
}category_[stock];


int main(void)
{
    head_msg();

    return 0;
}

void head_msg(void)
{
    char title_1[600];/*used to store Title design for easier access*/

    strcpy(title_1,
    "\n          _________________________________________________"
    "\n          |||||||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|||||||"
    "\n          |||||||     Vehicle Management System     |||||||"
    "\n          |||||||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|||||||"
    "\n          ||||||           ______________            ||||||"
    "\n          |||||           /              \\            |||||"
    "\n          ||||       ____/________________\\____        ||||"
    "\n          |||       /  ___               ___   \\        |||"
    "\n          ||       |__/   \\_____________/   \\__/         ||"
    "\n          |___________\\___/_____________\\___/_____________|"
    );

    printf("%s",title_1);
    printf("\n\n");
    msg_in_center();/*calling function*/

    printf("%s",title_1);

    menu();/*calling function*/
}

void msg_in_center(void)
{
    char msg[50],str[100];
    int i,remain,lft_side,rgt_side;

    printf("\nLogin: ");
    gets(msg);

    strcpy(str,"=====================================================================\n\n");/*seventy equal to signs*/
    printf("\n\n\n%s",str);                                                               

    remain = 70 - strlen(msg);/*seventy minus size of msg input*/

    lft_side = remain/2;/*gap in left side to center msg*/
    rgt_side = remain - lft_side;/*gap in right side to center msg*/
    
    for(i=0;i<lft_side;i++)
    {
        printf(" ");/*print spaces accordingly*/
    }

    printf("%s",msg);/*prints msg*/

    for(i=0;i<rgt_side;i++)
    {
        printf(" ");/*print spaces accordingly*/
    }

    printf("\n\n%s\n",str);

    welcome_msg();/*calling function*/
}

void welcome_msg(void)
{
    printf("\n              ||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||");
    printf("\n              ||                Welcome                ||");
    printf("\n              ||               To Vehicle              ||");
    printf("\n              ||            Management System          ||");
    printf("\n              ||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||");

    printf("\n\n\n");
    printf("Press any key to continue...\n");
    getche();
    printf("\r \r");/*clears screen*/
}

void menu(void)
{
    int option;
    char title_2 [600];
    
    int vehicle_count = 0;/*setting initial vehicle count as 0*/

    strcpy(title_2,
    "\n          _________________________________________________"
    "\n          |||||||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|||||||"
    "\n          |||||||     Vehicle Management System     |||||||"
    "\n          |||||||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|||||||"
    "\n          ||||||           ______________            ||||||"
    "\n          |||||           /              \\            |||||"
    "\n          ||||       ____/________________\\____        ||||"
    "\n          |||       /  ___               ___   \\        |||"
    "\n          ||       |__/   \\_____________/   \\__/         ||"
    "\n          |___________\\___/_____________\\___/_____________|"
    );

    
    while(option != 6)
    {
        printf("%s", title_2);

        printf("\n\n=====================================================================\n");
        printf("\n                              Main Menu                              ");
        printf("\n\n=====================================================================\n\n");

        printf("\n");


        printf("1. Add Vehicle\n2. Search Vehicle\n3. View Vehicles\n4. Delete Vehicle\n5. Update Password\n6. Exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&option);
        printf("\n\n");

        if(option<1 || option>6) 
        {
            printf("\nInvalid choice please try again.\n\n");
            break;
        }

        switch(option)
        {
            case 1:
            {
                printf("%s", title_2);
                add_vehicle_data_base(&vehicle_count); /*calling function*/
                break;
            }

            case 2:
            {
                printf("%s",title_2);
                break;
            }

            case 3:
            {
                printf("%s",title_2);
                break;
            }

            case 4:
            {
                printf("%s",title_2);
                break;
            }

            case 5:
            {
                printf("%s",title_2);
                break;
            }

            case 6:
            {
                printf("\n-Exiting Program");
                return;
            }

        }  

    }

}
    

int is_name_valid(char *name) 
{
    int has_letter = 0;

    for (int i = 0; name[i] != '\0'; i++)/*loop stops when it encounters the null terminator, i.e., the end of the string.*/
    {
       if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) 
        {
            return 0; 
        }

       if (((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) 
        {
            has_letter = 1;
        }
    }
    
    return has_letter;
}


int is_date_valid(int date,int month,int year)
{
    int days_each_month;

    if(year<1900)/*makes sure car was not made before year 1900*/
    {
        return 0;
    }

    if(month<1 || month>12)/*makes sure month is not less/more than it should be*/
    {
        return 0;
    }

    if(date<1)/*makes sure date is not less than one*/
    {
        return 0;
    }

    if(month == 4 || month == 6 || month == 9 || month == 11)/*account for months with 30 days*/
    {
        days_each_month = 30;
    }
    else if(month == 2)/*account for leap year*/
    {
        if((year%4 == 0 && year%100 != 0) || (year%400 == 0))/*leap year calculations*/
        {
            days_each_month = 29;
        }
        else
        {
            days_each_month = 28;
        }
    }
    else
    {
        days_each_month = 31;/*account for months with 31 days*/
    }

    if(date>days_each_month)/*make sure date is not more than days in a month*/
    {
        return 0;
    }
    return 1;
}

void add_vehicle_data_base(int *vehicle_count)
{
    char name[80];

    if (*vehicle_count >= stock)/*making sure vehicle count does not exceed or equal to stock(max vehicles)*/
    {
        printf("\nVehicle data storage is full!\n");
        return;
    }
    
    printf("\n\n=====================================================================\n");
    printf("                            ADD NEW VEHICLE                 ");
    printf("\n=====================================================================\n\n");

    printf("\nEnter Vehicle Details below: ");
    printf("\n-------------------------------");

    printf("\nEnter Vehicle ID: ");
    getchar();
    gets(category_[*vehicle_count].vehicle_ID);
    

    do
    {
        printf("\nEnter Vehicle Name: ");
        gets(name);

        if(!is_name_valid(name))/*makes sure name is within specific letters*/
        {
            printf("\nInvalid Name. Please try again.");
        }

    } while (!is_name_valid(name));

    strcpy(category_[*vehicle_count].vehicle_name, name);
    printf("Vehicle name is valid and has been entered.\n");

    do
    {
        printf("\nEnter Manufacturer Name: ");
        gets(name);

        if(!is_name_valid(name))/*makes sure name is within specific letters*/
        {
            printf("\nManufacturer name is invalid. Please try again.");
        }

    } while (!is_name_valid(name));

    strcpy(category_[*vehicle_count].manufacturer_name, name);
    printf("Vehicle name is valid and has been entered.\n");

    do 
    {
        printf("\nEnter Issued Date (date/month/year): ");
        scanf("%d/%d/%d", &category_[*vehicle_count].issued_date, &category_[*vehicle_count].issued_month, &category_[*vehicle_count].issued_year);

        if (!is_date_valid(category_[*vehicle_count].issued_date, category_[*vehicle_count].issued_month, category_[*vehicle_count].issued_year)) 
        {
            printf("\nInvalid Issued Date. Please try again keeping in mind; ");
            printf("\nyear should be more than 1900"); 
            printf("\ndate should be between 1 and the max in a month accounting for leap years"); 
            printf("\nlastly month should be between and including 1 and 12. \n");
        }
    }while(!is_date_valid(category_[*vehicle_count].issued_date, category_[*vehicle_count].issued_month, category_[*vehicle_count].issued_year));

    printf("Issued Date is valid and has been entered.\n\n");

    (*vehicle_count)++;
    printf("\nVehicle Data input successfully.");

    printf("\nPress any key to continue...\n");
    getche();
    printf("\r \r");


    return;    
}
