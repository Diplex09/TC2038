//
//  main.cpp
//  Activity 2.2
//
//  Created by Diego Velázquez on 26/08/21.
//

#include <iostream>
using namespace std;

int totalCoins[0];
int change=0;

// La funcion merge realiza el ordenamiento del arreglo que se le ingresa
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

//La funcion mergeSort hace la division e inicia la recursion para el ordenamiento del arreglo
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



//La funcion mergeSortStart manda a llamar el resto de funciones "Merge" para el ordenamiento del arreglo
void mergeSortStart(int a[], int size)
{
    mergeSort(a, 0, size - 1);

    std::cout << "\nSorted list from highest to lowest of the " << size << " given numbers:\n";

    for (int i=0; i<size; i++)
    {
        if(i == size - 1)
        {
            std::cout << a[i] << std::endl;
        }
        else
        {
            std::cout << a[i] << ", ";
        }
    }
}
 



// La funcion changeConverter es utilizada para una bandera, ademas que registra el cambio que vamos a recibir
bool changeConverter(int cost, int payment) {
     change=payment-cost;;
    
    if(payment<cost){
        change= change * -1;
        cout<<"There is not enough money, please add : "<<(change)<<"$"<<endl;
        return false;
    }
    
    else if(payment==cost){
        cout<<"Thank you for paying"<<endl;
        return false;
    }
    
    return true;
};


//La funcion minCoinDynamic a traves de la programacion dinamica y los apuntadores de arreglos realizan las
//posibles combinaciones que pueden dar el cambio, siempre buscando dar la menor cantidad de monedas posibles y te regresa el numero de monedas que va a regresar
int minCoinDynamic(int amount, int coins[], int size, int C[], int s[])
{
    C[0] = 0;
    for(int j = 1; j <= amount; j++) {
    C[j] = INT_MAX;
    for(int i = 0; i < size; i++) {

        if(j >= coins[i] && 1 + C[j-coins[i]] < C[j] ) {
        C[j] = 1 + C[j-coins[i]];

        // i-th denomination used for the amount of j
        s[j] = i;
        }
    }
    }
    return C[amount];
}




// La funcion minCoinGreedy busca cuantas monedas va a devolver, es importante mencionar que en este caso funciona mejor si le das el numero de monedas ordenado de mayor a menor (por eso es greedy).
int minCoinGreedy(int coins[], int size, int cost){
    int count = 0;
    
    for(int i = 0; i<size; i++){
        while (cost >= coins[i]){
            cost -= coins[i];
            totalCoins[count]=coins[i];
            count++;
            
        }
        if(cost == 0){
            break;
    
        }

            
        }
        return count;
    
}

//Se instancian varias variables a utilizar y despliegan los resultados
int main() {
    
    int cost,num,payment;
    int numberArray;
    cout<<"How many coins do you want to add?"<<endl;
    cin>> numberArray;
    cout<<"Enter the coins"<<endl;
    int coins[numberArray];
    for(int i=0;i<numberArray;i++){
        cin>>num;
        coins[i]=num;
    }
    cout<<"Enter the price of the product"<<endl;
    cin>>cost;
    cout<<"Enter the amount of money that you are going to pay"<<endl;
    cin>>payment;
    
    
    bool flag=changeConverter(cost,payment);
    
    
    int amount = change;
    int size = sizeof(coins)/sizeof(coins[0]);
    int *C = new int[amount+1];
    int *s = new int[amount+1];
    
    
    
    
    if(flag == true){
        
      
//      Dynamic algoritm
        int totalChangeDyn = minCoinDynamic(amount, coins, size, C, s);
        cout << "The coins to give are = " << totalChangeDyn << endl;
        cout << "coins used: " ;
        int k = amount;
        int sortCoinDyn[totalChangeDyn];
        int i=0;
        while(k) {
            sortCoinDyn[i] = coins[s[k]];
            k = k - coins[s[k]];
            i++;
        }
        mergeSortStart(sortCoinDyn, totalChangeDyn);
        
        
//      Greedy Algoritm
        int totalChangeGreedy = minCoinGreedy(coins,size,amount);
        int sortCoinGreed[totalChangeGreedy];
        cout<<"Coins : " <<totalChangeGreedy<<"\n";
        cout << "The coins to give are = " << totalChangeGreedy << endl;
        for(int i = 0; i < totalChangeGreedy ;i++){
            sortCoinGreed[i]=totalCoins[i];
        }
        mergeSortStart(sortCoinGreed, totalChangeGreedy);

        delete[] C;
        delete[] s;
    }
         
    
    return 0;
}
