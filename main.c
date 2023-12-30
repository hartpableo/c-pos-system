#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int order, orderType, orderStatus, quantity, orderValid = 0;
    float totalPrice, itemPrice;

    system("clear");
    printf("\n========= MCDOLLIBEEKING MENU =========\n\n");

    // Dine in or take out?
    printf("Dine In (1) or Take Out (2)? ");
    do
    {
        if (scanf("%d", &orderType) != 1) 
        {
            printf("\nSorry! Invalid input. Please enter a valid number (1 or 2). ");
            scanf("%*s");
        }
        else if (orderType < 1 || orderType > 2)
        {
            printf("\nSorry! Invalid input. Please enter only 1 for Dine In or 2 for Take Out. ");
        }
        else
        {
            break;
        }
    } while (orderType != 1 || orderType != 2);

    // Handle orders
    do
    {
        // Print menu
        printf("\n1. Original Hamburger\t\t P35.00\n");
        printf("2. Cheeseburger\t\t\t P40.00\n");
        printf("3. Pineapple Pizza (Small)\t P135.00\n");
        printf("4. Pineapple Pizza (Large)\t P195.00\n");
        printf("5. French Fries\t\t\t P25.00\n");
        printf("6. Rice + Chicken\t\t P95.00\n");

        do
        {
            printf("\nChoose the number for your order: ");
            if (scanf("%d", &order) != 1) 
            {
                printf("\nSorry! Invalid input. Please enter a valid number.\n");
                orderValid = 0;
                scanf("%*s");
            } 
            else if (order < 1 || order > 6) 
            {
                printf("\nSorry! Invalid order number. Please try again.\n");
                orderValid = 0;
            } 
            else 
            {
                orderValid = 1;
            }
        } while (orderValid == 0);

        switch (order)
        {
            case 1:
                itemPrice = 35.00;
                break;
            
            case 2:
                itemPrice = 40.00;
                break;

            case 3:
                itemPrice = 135.00;
                break;

            case 4:
                itemPrice = 195.00;
                break;

            case 5:
                itemPrice = 25.00;
                break;

            case 6:
                itemPrice = 95.00;
                break;
            
            default:
                break;
        };

        // Quantity of order
        sleep(1.5);
        printf("\nOrder Quantity: ");
        do
        {
            if (scanf("%d", &quantity) != 1) 
            {
                printf("\nSorry! Invalid input. Please enter a valid number. ");
                scanf("%*s");
            }
            else
            {
                break;
            }
        } while (quantity <= 0);
        itemPrice = itemPrice * quantity;
        totalPrice = totalPrice + itemPrice;

        // Add to cart
        sleep(1.5);
        printf("\nYour order has been added to cart.\n");
        sleep(.75);
        printf("\nCurrent Total: P%f\n", totalPrice);
        sleep(1);
        printf("\nWould you like to Continue ordering (1) or Proceed to checkout (2)? ");
        do
        {
            if (scanf("%d", &orderStatus) != 1) 
            {
                printf("\nSorry! Invalid input. Please enter a valid number (1 or 2). ");
                scanf("%*s");
            }
            else if (orderStatus < 1 || orderStatus > 2)
            {
                printf("\nSorry! Invalid input. Please enter only 1 if you want to continue ordering or 2 if you want to proceed to checkout. ");
            }
            else
            {
                break;
            }
        } while (orderStatus != 1 || orderStatus != 2);
    } while (orderStatus != 2);
    
    // Display order info
    sleep(1);
    printf("\n\n======================\n\n");
    printf("TOTAL: %f\n", totalPrice);
    if (orderType == 1)
    {
        printf("Order Type: DINE IN");
    }
    else
    {
        printf("Order Type: TAKE OUT");
    }
    printf("\n\n======================\n\n");
    
    return 0;
}