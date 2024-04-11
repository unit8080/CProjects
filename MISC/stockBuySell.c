#include <stdio.h>

int stock[] = {100, 180, 260, 310, 40, 535, 695};
struct Record {
    int buy;
    int sell;
};

void stockBuySell (int stock[], int len)
{
    if (len < 2)
        return;

    struct Record rec[len/2+1];
    int count = 0; // transaction counter
    int i = 0;

    while (i < len-1) {
        while (i < len-1 && stock[i+1] <= stock[i]) {
            i++; // skip if buy price next day is lesser.
        }
        if (i >= len-1)
            break;
        
        rec[count].buy = i;    // buy day
        i++;
        while (i < len && stock[i] >= stock[i-1]) {
            i++; // skip if sell price next day is higher.
        }
        rec[count].sell = i-1; // sell day 
        count++; // next transaction
    }
    if (count == 0) {
        printf("\n There is no sell/buy transaction.\n");
        return;
    }
    for (int j = 0; j < count; j++)
        printf("Buy day: %d, sell day: %d\n", rec[j].buy, rec[j].sell);
}
int main()
{
    int len = sizeof(stock)/sizeof(stock[0]);
    stockBuySell(stock, len);
}
