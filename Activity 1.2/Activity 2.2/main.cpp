//
//  main.cpp
//  Activity 2.2
//
//  Created by Diego Velázquez on 26/08/21.
//

#include <iostream>
using namespace std;

int totalCoins[0];

/*
 Function that counts the coins and returns the numbers of coins needed.
 INPUT
 coins[]= The coins available to choose.
 size = The size of the numbers it can take.
 value = The price of the product.
 Output = Total of numbers.
*/

int minCoins(int coins[], int total_coins, int N) // Function to return the minimum // coins needed
{
        if (N == 0) // If we have a combination then
        return 0;
  
    int result = INT_MAX; // Currently result is initialised as INT_MAX
  
    for (int i = 0; i < total_coins; i++) // run until availability of coins
    {
        if (coins[i] <= N) { // Add to the list of counting
            int sub_res = 1 + minCoins(coins, total_coins, N - coins[i]); // add 1 due to the coin inclusion
            // see if result can minimize
            if (sub_res < result)
                result = sub_res;
                cout<<coins[i]<<endl;
        }
    }
    return result;
}
  


int coinCounter(int coins[], int size, int cost, int payment){
    int count = 0;
    int change=payment-cost;
    
    if(payment<cost){
        change= change * -1;
        cout<<"There is not enough money, please add : "<<(change)<<"$"<<endl;
    }
    
    else if(payment==cost){
        cout<<"Thank you for paying"<<endl;
    }
    
    
    else{
        for(int i = 0; i<size; i++){
            while (change >= coins[i]){
                change -= coins[i];
                totalCoins[count]=coins[i];
                count++;
            }
            if(change == 0){
                break;
            }
            else if(change<coins[size-1]){
                cout<<"We owe you : "<<change<<"$"<<endl;
                break;
            }
            
            
        }
        return count;

    }
    
    
    
    return count;
    
        

    
    
}


int main() {
/*    int coins[]={25,20,10,5};
    int cost = 100;
    int payment = 140;

    int size = sizeof(coins)/sizeof(coins[0]);
    int MinCount = coinCounter(coins,size,cost,payment);
    cout<<"Coins : " <<MinCount<<"\n";
    printf("The coins to give are: ");
    for(int i = 0; i < MinCount; i++){
        cout<<endl<<totalCoins[i]<<"$";
//            printf("%d ", totalCoins[i],"/n");
 
 
 
    }
    cout<<"\n";*/
    
    int coins[] = { 30,10, 20, 25, 5 };
    int sum = 30; // the money to convert
    int total_coins = 3; // total availability of coins
    cout << "Minmum coins needed are " << minCoins(coins, total_coins, sum);
    
    
    
    return 0;
}
