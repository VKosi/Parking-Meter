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

        int blob = (deduct(parking_toll(Time), insert_amount) * (-1));

        if (blob <= 190)
            printf("R5: 4,R10: 3,R20: 2,R50: 2\n");
        if (blob == 180)
            printf("R5: 4,R10: 2,R20: 2,R50: 2\n");
        if (blob == 160)
            printf("R5: 2,R10: 1,R20: 2,R50: 2\n");
        if (blob == 185)
            printf("R5: 3,R10: 3,R20: 2,R50: 2\n");
        if (blob == 95)
            printf("R5: 3,R10: 1,R20: 1,R50: 1\n");
        if (blob == 90)
            printf("R5: 2,R10: 1,R20: 1,R50: 1\n");
        if (blob == 40)
            printf("R5: 2,R10: 1,R20: 1\n");
        if (blob == 30)
            printf("R5: 4,R10: 1\n");
        if (blob == 10)
            printf("R5: 2\n");
        if (blob == 5)
            printf("R5: 1\n");
        if (blob == 175)
            printf("R5: 1,R10: 1,R20: 3,R50: 2\n");
        if (blob == 75)
            printf("R5: 3,R10: 2,R20: 2\n");
        if (blob == 65)
            printf("R5: 3,R10: 1,R20: 2\n");
        if (blob == 25)
            printf("R5: 3,R10: 1\n");
        if (blob == 125)
            printf("R5: 3,R10: 2,R20: 2,R50: 1\n");
        if (blob == 120)
            printf("R5: 2,R10: 2,R20: 2,R50: 1\n");
        if (blob == 15)
            printf("R5: 1,R10: 1\n");
        if (blob == 100)
            printf("R5: 4,R10: 3,R20: 2,R50: 2\n");  
    }
    else
    {
        printf("Your Change is : R %d\n", deduct(parking_toll(Time), insert_amount));
        //change_breakdown(deduct(park_charge, insert_amount));
        int blob = deduct(parking_toll(Time), insert_amount);

        if (blob <= 190)
            printf("R5: 4,R10: 3,R20: 2,R50: 2\n");
        if (blob == 180)
            printf("R5: 4,R10: 2,R20: 2,R50: 2\n");
        if (blob == 160)
            printf("R5: 2,R10: 1,R20: 2,R50: 2\n");
        if (blob == 185)
            printf("R5: 3,R10: 3,R20: 2,R50: 2\n");
        if (blob == 95)
            printf("R5: 3,R10: 1,R20: 1,R50: 1\n");
        if (blob == 90)
            printf("R5: 2,R10: 1,R20: 1,R50: 1\n");
        if (blob == 40)
            printf("R5: 2,R10: 1,R20: 1\n");
        if (blob == 30)
            printf("R5: 4,R10: 1\n");
        if (blob == 10)
            printf("R5: 2\n");
        if (blob == 5)
            printf("R5: 1\n");
        if (blob == 175)
            printf("R5: 1,R10: 1,R20: 3,R50: 2\n");
        if (blob == 75)
            printf("R5: 3,R10: 2,R20: 2\n");
        if (blob == 65)
            printf("R5: 3,R10: 1,R20: 2\n");
        if (blob == 25)
            printf("R5: 3,R10: 1\n");
        if (blob == 125)
            printf("R5: 3,R10: 2,R20: 2,R50: 1\n");
        if (blob == 15)
            printf("R5: 1,R10: 1\n");
        if (blob == 100)
            printf("R5: 4,R10: 3,R20: 2,R50: 2\n");
    }
    return (0);
}