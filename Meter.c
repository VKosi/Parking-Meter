#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int parking_toll(int time)
{

    int park_charge;

    if (time > 0 && time <= 30)
    {
        park_charge = 10;
    }
    else if (time >= 31 && time <= 60)
    {
        park_charge = 25;
    }
    else if (time >= 61 && time <= 120)
    {
        park_charge = 50;
    }
    else if (time >= 121 && time <= 180)
    {
        park_charge = 75;
    }
    else if (time >= 181 && time <= 240)
    {
        park_charge = 100;
    }
    else
        park_charge = 200;

    return (park_charge);
}

int deduct(int park_charge, int insert_amount)
{
    int change;

    if (park_charge > 0)
    {
        change = park_charge - insert_amount;
    }
    return (change);
}

int change_breakdown(int Change,int time,int insert_amount)
{
    int denom_5 = 0;
    int denom_10 = 0;
    int denom_20 = 0;
    int denom_50 = 0;
    int denom_100 = 0;
    int denom_200 = 0;
    int change;
    int complete;
    int park_charge = parking_toll(time);

    if (deduct(park_charge, insert_amount) < 0)
            change = deduct(park_charge, insert_amount) * (-1);
    else
        change = deduct(park_charge, insert_amount);

    complete = 0;
    if (change >= 5 && change <= 50)
    {
        while (complete <= change)
        {
            while (denom_5 < 2 || (change - complete == 5))
            {
                denom_5++;
                complete += 5;
                break;
            }
            while (denom_5 < 1 || (change - complete == 10))
            {
                denom_10++;
                complete += 10;
                break;
            }
            while (denom_20 < 1)
            {
                denom_20++;
                complete += 20;
                break;
            }
        }
    }
    else if (change >= 55 && change <= 100)
    {
        while (complete <= change)
        {
            while (denom_5 < 2 || (change - complete == 5))
            {
                denom_5++;
                complete += 5;
                break;
            }
            while (denom_5 < 1 || (change - complete == 10))
            {
                denom_10++;
                complete += 10;
                break;
            }
            while (denom_20 < 1 || (change - complete == 20))
            {
                denom_20++;
                complete += 20;
                break;
            }
            while (denom_50 < 1)
            {
                denom_50++;
                complete += 50;
                break;
            }
        }
    }
    else if (change >= 105 && change <= 195)
    {
        while (complete <= change)
        {
            while (denom_5 < 2 || (change - complete == 5))
            {
                denom_5++;
                complete += 5;
                break;
            }
            while (denom_5 < 1 || (change - complete == 10))
            {
                denom_10++;
                complete += 10;
                break;
            }
            while (denom_20 < 1 || (change - complete == 20))
            {
                denom_20++;
                complete += 20;
                break;
            }
            while (denom_50 < 1 || (change - complete == 20))
            {
                denom_50++;
                complete += 50;
                break;
            }
            while (denom_100 < 1)
            {
                denom_100++;
                complete += 100;
                break;
            }
        }
    }
    return (denom_5, denom_10, denom_50, denom_50, denom_100);
}

int main(void)
{

    int insert_amount = 0;
    srand(time(0));
    int Time = (rand() % (300 - 0 + 1)) + 0;
    int change = 0;
    int park_charge = 0;
    int x = 0;

    if (x < 1)
    {
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("    Good Day , Machine accepts R5,R10,R20,R50,R100,R200    \n");
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Good Day ,your charge is R%d . Please insert an amount : ", parking_toll(Time));
        scanf("%d", &insert_amount);
        while (insert_amount != 5 && insert_amount != 10 && insert_amount != 20 &&
               insert_amount != 50 && insert_amount != 100 && insert_amount != 200)
        {
            printf("Please enter a Valid amount : ");
            scanf("%d", &insert_amount);
        }
    }
    if (deduct(park_charge, insert_amount) > 0)
    {
        while (deduct(park_charge, insert_amount) > 1)
        {
            int add_on;
            if (deduct(parking_toll(Time), insert_amount) <= 0)
                break;
            printf("Oops thats not enough , R%d Short . Please add more to pay : ", deduct(parking_toll(Time), insert_amount));
            scanf(" %d", &add_on);
            while (add_on != 5 && add_on != 10 && add_on != 20 &&
                   add_on != 50 && add_on != 100 && add_on != 200)
            {
                printf("Please enter a Valid amount : ");
                scanf("%d", &add_on);
            }
            insert_amount += add_on;
        }
    }

    if (deduct(park_charge, insert_amount) < 0)
    {
        printf("Your Change is : R %d\n", (deduct(parking_toll(Time), insert_amount) * (-1)));
        //printf("%d \n", change_breakdown(change,Time,insert_amount));
    }
    else 
    {
        printf("Your Change is : R %d\n", deduct(parking_toll(Time), insert_amount));
        //printf("%d \n", change_breakdown(change,Time,insert_amount));
    }
    return (0);
}