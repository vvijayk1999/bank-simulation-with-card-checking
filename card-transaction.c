#include<stdio.h>
#include<stdlib.h>
struct Date
{
    int day;
    int month;
    int year;
};
struct CardDetails{
    int card_number;
    int pin;
    struct Date exp_date;
    int balance;
}cards[3];

struct Date getCurrentDate()
{
    struct Date current_date;
    
    current_date.day = 18;
    current_date.month = 02;
    current_date.year = 2020;

    return current_date;
}
int checkDateValidity(struct Date current_date, struct Date exp_date)
{
    if(exp_date.year > current_date.year)
        return 1;
    else
    {
        if(exp_date.year == current_date.year)
        {
            if(exp_date.month > current_date.month)
                return 1;
            else
            {
                if(exp_date.month == current_date.month)
                {
                    if(exp_date.day > current_date.day)
                        return 1;
                }
            }
        }
    }
    
    return 0;
}
void displayMenu()
{
    printf("\n\n\nWelcome USER ! :)\n\n");
    printf("\n[1] View balance");
    printf("\n[2] Withdraw money");
    printf("\n[3] Deposit money");
    printf("\n[4] Quit");
    printf("\n\nEnter your choise : ");
}

void addBalance(int index)
{
    int money;
    printf("\nEnter money to be deposited : ");
    scanf("%d",&money);
    cards[index].balance += money;
    printf("\nSuccessfuly added %d to your account\nCurrent balance is %d",money,cards[index].balance);
}

void subBalance(int index)
{
    int money;
    printf("\nEnter money to be withdrawn : ");
    scanf("%d",&money);
    cards[index].balance -= money;
    printf("\nSuccessfuly deducted %d from your account\nCurrent balance is %d",money,cards[index].balance);
}

void viewBalance(int index)
{
    printf("\nYour balance is : %d",cards[index].balance);
}

int main()
{
    struct Date current_date;
    
    int card_number,pin,menu_choice=1,i,j,pin_entered_count=0;
    /* Flags */
    int card_valid_flag = 0,card_expired_flag= 1, pin_valid = 0;

    /*  Vijay's Card Details */
    cards[0].card_number = 123456;
    cards[0].pin = 1234;
    cards[0].exp_date.day = 19;
    cards[0].exp_date.month = 2;
    cards[0].exp_date.year = 2020;
    cards[0].balance = 500;

    printf("\nEnter your card number : ");
    scanf("%d",&card_number);

    for(i=0;i<3;i++)
        if(cards[i].card_number == card_number)
        {
            card_valid_flag = 1;
            current_date = getCurrentDate();
            if(checkDateValidity(current_date,cards[i].exp_date))
            {
                card_expired_flag = 0 ;
                break;
            }
        }
    if (card_valid_flag)
    {
        if(!card_expired_flag)
        {
            // check pin
            while(pin_entered_count < 3)
            {
                printf("\nEnter PIN : ");
                scanf("%d",&pin);
                if(pin == cards[i].pin)
                {
                    pin_valid = 1;
                    break;
                }else
                {
                    printf("\n!! Your PIN is wrong try agian !!");
                    pin_entered_count++;
                }
            }
            if(pin_valid)
            {
                while (menu_choice != 0)
                {
                    displayMenu();
                    scanf("%d",&menu_choice);
                    switch (menu_choice)
                    {
                    case 1 : viewBalance(i);
                        break;
                    case 2 : addBalance(i);
                        break;
                    case 3 : subBalance(i);
                        break;
                    case 4 :  menu_choice=0;
                        break;
                    default: printf("\nInvalid operation !\tTry again");
                        break;
                    }
                }
                printf("\nExiting . . .");
                exit(0);
            }
        }
        else
            printf("\nCard Expired");
    }else
        printf("\nCard is invalid");
}