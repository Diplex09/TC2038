/*                                                  */
/*  Actividad 1.1 - Implimentación Merge Sort       */
/*                                                  */
/*  Diego Velázquez Moreno - A01632240              */
/*  Aldo Alejandro Degollado Padilla - A01638391    */
/*                                                  */

#include <iostream>

void merge(double a[], int start, int end)
{
    int middle = (start + end) / 2;
    int j = start;
    int k = middle + 1;
    int arraySize = end - start + 1;
    double arrayTemp[arraySize];

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

void mergeSort(double a[], int start, int end)
{
    if(start < end)
    {
        int middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        merge(a, start, end);
    }
}

void mergeSortStart(double a[], int size)
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
 
int main(void)
{
    std::cout << "\n |-|-|      RECURSIVE MERGE SORT IMPLEMENTATION      |-|-|" << std::endl;
    std::cout << "By: Aldo Degollado, Diego Velazquez\n" << std::endl;

    double totalNums = 0;
    double num = 0;
    bool flag = true;

    std::cout << "Please enter the total of numbers to sort:\n";
    std::cin >> totalNums;
    
    if(!(totalNums - int(totalNums) > 0) && totalNums > 0)
    {
        double numsToSort[int(totalNums)];

        std::cout << "\nPlease enter the " << totalNums << " numbers to sort:\n";

        for (int i=0; i < totalNums; i++)
        {
        std::cin >> num;
        numsToSort[i] = num;
        }

        mergeSortStart(numsToSort, totalNums);
    }
    else
    {
        flag = false;
    }

    if(totalNums > 0 && flag)
    {
        std::cout << "\n\n\nThe sorting of your file has ended, thank for using our program!\n" << std::endl;
    }
    else
    {
        std::cout << "\n\n\nInvalid number, try again.\n" << std::endl;
    }
    return 0;
}