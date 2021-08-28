/*                                                                                   */
/*  Actividad 1.2 - Implimentación de algoritmo greedy y programación dinámica       */
/*                                                                                   */
/*  Diego Velázquez Moreno - A01632240                                               */
/*  Aldo Alejandro Degollado Padilla - A01638391                                     */
/*                                                                                   */

#include <iostream>
using namespace std;

int totalCoins[0];
int change = 0;

// The merge function sorts the array that gets inputted
void merge(int a[], int start, int end)
{
    int middle = (start + end) / 2;
    int j = start;
    int k = middle + 1;
    int arraySize = end - start + 1;
    int arrayTemp[arraySize];

    for(int i=0; i < arraySize; i++)
    {
        if(j <= middle && k <= end)
        {
            if(a[j] > a[k])
            {
                arrayTemp[i] = a[j++];
            }
            else
            {
                arrayTemp[i] = a[k++];
            }
        }
        else if(j <= middle)
        {
            arrayTemp[i] = a[j++];
        }
        else
        {
            arrayTemp[i] = a[k++];
        }
    }

    for(int m=0; m < arraySize; m++)
    {
        a[start + m] = arrayTemp[m];
    }
}

// The mergeSort function makes splits the array in two and starts the recursion process to sort the array.
void mergeSort(int a[], int start, int end)
{
    if(start < end)
    {
        int middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        merge(a, start, end);
    }
}

// The mergeSortStart function mergeSortStart starts the sorting process by calling the mergeSort function.
void mergeSortStart(int a[], int size, bool flag)
{
    mergeSort(a, 0, size - 1);

    if (flag)
    {
        for (int i=0; i<size; i++)
        {
            std::cout << a[i] << std::endl;
        }
    }
}
 
// The changeConverter function is used as a flag, it verifies if there is enough money to pay.
bool changeConverter(int cost, int payment) {
     change = payment - cost;;
    
    if(payment < cost)
    {
        change = change * - 1;
        cout << "There is not enough money, please add : " << (change) << "$" << endl;
        return false;
    }
    else if(payment == cost)
    {
        cout << "\nThank you for paying." << endl;
        return false;
    }

    return true;
};

/* The minCoinDynamic funtion is a dynamic programming algorithm that uses pointers to array in order to determine all the possible combinations of change that can be
given. The algorithm is always looking to give the minimum amount of coins. It returns the number of coins to return. */
int minCoinDynamic(int amount, int coins[], int size, int C[], int s[])
{
    C[0] = 0;
    for(int j = 1; j <= amount; j++) 
    {
        C[j] = INT_MAX;
        for(int i = 0; i < size; i++)
        {
            if(j >= coins[i] && 1 + C[j-coins[i]] < C[j]) 
            {
                C[j] = 1 + C[j-coins[i]];
                cout << C[j] << endl;
                // i-th denomination used for the amount of j
                s[j] = i;
            }
        }
    }
    return C[amount];
}

/* The minCoinGreedy function calculates the amount of coins to give back. The algorithm will always try to give the coins with the highest value. */
int minCoinGreedy(int coins[], int size, int changeToGive){
    int count = 0;
    
    mergeSortStart(coins, size, false);

    for(int i = 0; i < size; i++)
    {
        while (changeToGive >= coins[i])
        {
            changeToGive -= coins[i];
            totalCoins[count] = coins[i];
            count++;
        }

        if(changeToGive == 0)
        {
            break;
        }    
    }
    return count;
    
}

int main() 
{
    std::cout << "\n |-|-|      GREEDY AND DYNAMIC PROGRAMMATION IMPLEMENTATION      |-|-|" << std::endl;
    std::cout << "By: Aldo Degollado, Diego Velazquez\n" << std::endl;

    int cost, num, payment;
    int numberArray;

    cout << "How many coins do you want to add?" << endl;
    cin >> numberArray;

    if (numberArray > 0)
    {
        int coins[numberArray];
        bool invalidCoinValue = false;
        cout << "\nEnter the value of the coins:" << endl;

        for(int i=0;i<numberArray;i++)
        {
            cin >> num;
            if (num <= 0)
            {
                i = numberArray + 1;
                invalidCoinValue = true;
            }
            else
            {
                coins[i] = num;
            }
        }

        if (!invalidCoinValue)
        {
            cout << "\nEnter the price of the product:" << endl;
            cin >> cost;

            if (cost > 0)
            {
                cout << "\nEnter the amount of money that you are going to pay:" << endl;
                cin >> payment;
                
                if (payment >= 0)
                {
                    bool flag = changeConverter(cost, payment);
                    
                    int amount = change;
                    int size = sizeof(coins) / sizeof(coins[0]);
                    int *C = new int[amount + 1];
                    int *s = new int[amount + 1];
                    
                    if(flag == true)
                    {
                        //      Dynamic algoritm
                        int totalChangeDyn = minCoinDynamic(amount, coins, size, C, s);
                        cout << totalChangeDyn << endl;
                        if (totalChangeDyn > 0 && totalChangeDyn < INT_MAX)
                        {
                            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~ DYNAMIC PROGRAMMING ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "\nThe minimum amount of coins to give are " << totalChangeDyn << "." << endl;
                            cout << "Given coins: " << endl;
                            int k = amount;
                            int sortCoinDyn[totalChangeDyn];
                            int i=0;
                            while(k) 
                            {
                                sortCoinDyn[i] = coins[s[k]];
                                k = k - coins[s[k]];
                                i++;
                            }
                            mergeSortStart(sortCoinDyn, totalChangeDyn, true);
                            
                            //      Greedy Algoritm
                            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GREEDY ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            int totalChangeGreedy = minCoinGreedy(coins,size,amount);
                            int sortCoinGreed[totalChangeGreedy];
                            cout << "\nThe amount of coins to give are " << totalChangeGreedy << "." << endl;
                            cout << "Given coins: " << endl;
                            for(int i = 0; i < totalChangeGreedy ;i++)
                            {
                                sortCoinGreed[i]=totalCoins[i];
                            }
                            mergeSortStart(sortCoinGreed, totalChangeGreedy, true);

                            delete[] C;
                            delete[] s;   
                        }
                        else
                        {
                            cout << "\nThere is no possible combination of the given coins that can be given as change." << endl;
                        }
                    }   
                }
                else
                {
                    cout << "\nSorry, you inputted a invalid amount to pay, try again." << endl;
                }
            }
            else
            {
                cout << "\nSorry, you inputted a invalid price to pay, try again." << endl;
            }
        }
        else
        {
            cout << "\nSorry, you inputted a invalid value of a coin, try again." << endl;
        }
    }
    else
    {
        cout << "\nSorry, you inputted a invalid amount of coins, try again." << endl;
    }
         
    return 0;
}