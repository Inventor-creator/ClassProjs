#include <stdio.h>

void sort(int profit[], int weight[], float ratio[], int n)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {

                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;


                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;


                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;
            }
        }
    }
}

int main()
{
    int n, i, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    float ratio[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);

        ratio[i] = (float)profit[i] / weight[i];
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    sort(profit, weight, ratio, n);

    float totalProfit = 0.0;

    for(i = 0; i < n; i++)
    {
        if(capacity >= weight[i])
        {
            totalProfit = totalProfit + profit[i];
            capacity = capacity - weight[i];
        }
        else
        {
            totalProfit = totalProfit + profit[i] * ((float)capacity / weight[i]);
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
