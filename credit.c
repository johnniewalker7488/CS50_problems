#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number; // card number
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    
    long n = number; // copy to keep number variable unchanged
    
    // calculating sum of every other digit from second-to-last
    int sum_even = 0; // counter
    int element; // number to be added
    
    for (int i = 0; n / 10 != 0; i++)
    {
        // we take away the last digit, then check the new last digit
        element = ((n / 10) % 10) * 2;
        // if element > 10 we sum up the digits of the element
        if ((element / 10) != 0)
        {
            element = (element % 10) + (element / 10);
        }
        // adding the element to counter
        sum_even += element;
        // now we need to get rid of the 2 last digits of number for the next iteration
        n /= 100;
    }
    
    // calculating sum of the rest of digits
    // when loop gets to end there is the only digit to count
    // so no need to divide by 10 in condition
    int sum_odd = 0;
    int elem;
    long m = number;
    for (int i = 0; m != 0; i++)
    {
        elem = m % 10;
        sum_odd += elem;
        m /= 100;
    }
    
    int total_sum = sum_even + sum_odd; // checksum
    // variables for convenience
    int amex_num = number / 10000000000000;
    int master_num = number / 100000000000000;
    int visa_1 = number / 1000000000000;
    int visa_2 = number / 1000000000000000;
    
    // checking the checksum
    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // if ok checking the first digits
    else
    {
        if ((amex_num == 34) || (amex_num == 37))
        {
            printf("AMEX\n");
        }
        else if ((master_num == 51) || (master_num == 52) || (master_num == 53) || 
                 (master_num == 54) || (master_num == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((visa_1 == 4) || (visa_2 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
