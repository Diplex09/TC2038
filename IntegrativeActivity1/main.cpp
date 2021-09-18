/*                                                  */
/*  Actividad Integradora 1 - Strings               */
/*                                                  */
/*  Diego Velazquez Moreno - A01632240              */
/*  Aldo Alejandro Degollado Padilla - A01638391    */
/*                                                  */

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

//La funcion de prefixSufixCalc permite guardar el arreglo de prefixsufix para implementarlo el la funcion de patternfinder
//el la funcion de patternfinder
void prefixSufixCalc(char* pattern, int lenghtPat, int* prefixSufixArray)
{
    int lenght = 0;

    prefixSufixArray[0] = 0;

    int i = 1;
    while (i < lenghtPat) 
    {
        if (pattern[i] == pattern[lenght]) 
        {
            lenght++;
            prefixSufixArray[i] = lenght;
            i++;
        }
        else
        {
            if (lenght != 0) 
            {
                lenght = prefixSufixArray[lenght - 1];
            }
            else
            {
                prefixSufixArray[i] = 0;
                i++;
            }
        }
    }
}

//Es una función que funciona con el algoritmo KMP para la busqueda de patrones, dentro del algoritmo se utiliza una funcion
//prefixSufixcalc para poder hacer un arreglo con los prefijos posibles y poder adelantar posiciones que distigue el KMP
void patternFinder(char* pattern, char* txt)
{
    int lenghtPat = strlen(pattern);
    int lengthtxt = strlen(txt);
    int endOfPat = 0;
    int prefixSufixArray[lenghtPat];
    bool flag = false;

    prefixSufixCalc(pattern, lenghtPat, prefixSufixArray);

    int i = 0;
    int j = 0;
    while (i < lengthtxt) 
    {
        if (pattern[j] == txt[i]) 
        {
            j++;
            i++;
        }

        if (j == lenghtPat)
        {
            flag = true;
            cout << "True "<< i - j << endl;
            endOfPat = i;
            j = prefixSufixArray[j-1];
            return;
        }

        else if (i < lengthtxt && pattern[j] != txt[i])
        {
            if (j != 0)
            {
                j = prefixSufixArray[j-1];
            }
            else
            {
                i = i + 1;
            }
        }
    }

    if (flag == false)
    {
        cout<< "False \n";
        return;
    }
}

//Esta funcion encuentra el palindromo más largo con la tecnica de Manachers,
void findLongestPalindromicString(char* transmission)
{
    int N = strlen(transmission);

    if(N == 0)
    {
        return;
    }

    N = 2 * N + 1; 
    int palindromeArray[N]; 
    palindromeArray[0] = 0;
    palindromeArray[1] = 1;
    int middle = 1;
    int middleRightPos = 2;
    int iMirror;
    int lengthpalindrome = 0;
    int maxLPSCenterPosition = 0;
    int difference = -1;
    int start = -1;
    int end = -1;
    int min;
    
    for (int i = 2; i < N; i++)
    {
        iMirror = 2 * middle - i;
        palindromeArray[i] = 0;
        difference = middleRightPos - i;

        if(difference > 0)
        {
            int min = palindromeArray[iMirror];
            if(difference < palindromeArray[iMirror])
            {
                min = difference;
                palindromeArray[i] = min;
            }
        }
            
        while ( ((i + palindromeArray[i]) < N && (i - palindromeArray[i]) > 0) &&
            ( ((i + palindromeArray[i] + 1) % 2 == 0) ||
            (transmission[(i + palindromeArray[i] + 1)/2] == transmission[(i - palindromeArray[i] - 1)/2] )))
        {
            palindromeArray[i]++;
        }
 
        if(palindromeArray[i] > lengthpalindrome)
        {
            lengthpalindrome = palindromeArray[i];
            maxLPSCenterPosition = i;
        }
 
        if (i + palindromeArray[i] > middleRightPos)
        {
            middle = i;
            middleRightPos = i + palindromeArray[i];
        }
        
    }
    start = (maxLPSCenterPosition - lengthpalindrome)/2;
    end = start + lengthpalindrome - 1;
    cout << start << " " << end << endl;
}

//Esta funcion calcula el substring comun mas largo, cuando se encuentra el substring más largo busca el penultimo más largo
//para conocer cual fue el punto de inicio del actual mas largo.
void commonSubstringCal(char* transmission1, char* transmission2)
{
    int lastLongestPos;
    int longestPreviousString;
    int lengthtransmision = strlen(transmission1);
    int lengthtransmision2 = strlen(transmission2);
    int longestSuffixArray[lengthtransmision + 1][lengthtransmision2 + 1];
    int lenghtLSA = 0;
 
    for (int i = 0; i <= lengthtransmision; i++)
    {
        for (int j = 0; j <= lengthtransmision2; j++)
        {
            if (i == 0 || j == 0)
                longestSuffixArray[i][j] = 0;
 
            else if (transmission1[i - 1] == transmission2[j - 1]) 
            {
                longestSuffixArray[i][j] = longestSuffixArray[i - 1][j - 1] + 1;
                lenghtLSA = max(lenghtLSA, longestSuffixArray[i][j]);
                if(lenghtLSA>longestPreviousString)
                {
                    lastLongestPos = i;
                }
                longestPreviousString = lenghtLSA;
            }
            else
            {
                longestSuffixArray[i][j] = 0;
            }
        }
    }
    int start = lastLongestPos - lenghtLSA;
    cout<< start << " " << start + lenghtLSA - 1 << endl;

}
 
int main()
{
    cout << "\n |-|-|      STRING ANALYZER      |-|-|" << endl;
    cout << "By: Aldo Degollado, Diego Velazquez" << endl;
    
    ifstream expressionsFile;
    vector<string> fileNames = {"transmission1.txt", "transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};
    vector<string> transmissionFiles;
    vector<string> mcodeFiles;
    int count = 5;
    
    for (int i=0; i < fileNames.size(); i++)
    {
        string line, fullFile;
        int lineLength;

        expressionsFile.open(fileNames[i], ios::in);
        
        // Asks the name of the file to analyze until the user inputs it correctly
        if (expressionsFile.fail())
        {
            cout << "Unable to open \"" << fileNames[i] << "\"";
            break;
        }

        // Read each line of the file
        while(expressionsFile.is_open() && !expressionsFile.eof())
        {
            getline(expressionsFile, line);
            fullFile = fullFile + line;
        }
        expressionsFile.close();
        lineLength = fullFile.length();

        switch (count)
        {
            case 5:
            {
                transmissionFiles.push_back(fullFile);
                break;
            }

            case 4:
            {
                transmissionFiles.push_back(fullFile);
                break;
            }

            case 3:
            {
                mcodeFiles.push_back(fullFile);
                break;
            }

            case 2:
            {
                mcodeFiles.push_back(fullFile);
                break;
            }

            case 1:
            {
                mcodeFiles.push_back(fullFile);
                break;
            }
        }
        count--;
    }

    cout << "\n| --------------------- Files content --------------------- |" << endl;

    char transmissionOne[transmissionFiles[0].size()];

    for (int i=0; i < transmissionFiles[0].size(); i++)
    {
        transmissionOne[i] = transmissionFiles[0][i];
    }
    cout << "Transmission 1 (size " << transmissionFiles[0].size() << "):" << endl;
    for (int i=0; i < transmissionFiles[0].size(); i++)
    {
        cout << transmissionOne[i];
    }
    cout << "\n\n";

    char transmissionTwo[transmissionFiles[1].size()];

    for (int i=0; i < transmissionFiles[1].size(); i++)
    {
        transmissionTwo[i] = transmissionFiles[1][i];
    }
    cout << "Transmission 2 (size " << transmissionFiles[1].size() << "):" << endl;
    for (int i=0; i < transmissionFiles[1].size(); i++)
    {
        cout << transmissionTwo[i];
    }
    cout << "\n\n";

    char mcodeOne[mcodeFiles[0].size()];

    for (int i=0; i < mcodeFiles[0].size(); i++)
    {
        mcodeOne[i] = mcodeFiles[0][i];
    }
    cout << "Mcode 1 (size " << mcodeFiles[0].size() << "):" << endl;
    for (int i=0; i < mcodeFiles[0].size(); i++)
    {
        cout << mcodeOne[i];
    }
    cout << "\n\n";

    char mcodeTwo[mcodeFiles[1].size()];

    for (int i=0; i < mcodeFiles[1].size(); i++)
    {
        mcodeTwo[i] = mcodeFiles[1][i];
    }
    cout << "Mcode 2 (size " << mcodeFiles[1].size() << "):" << endl;
    for (int i=0; i < mcodeFiles[1].size(); i++)
    {
        cout << mcodeTwo[i];
    }
    cout << "\n\n";

    char mcodeThree[mcodeFiles[2].size()];

    for (int i=0; i < mcodeFiles[2].size(); i++)
    {
        mcodeThree[i] = mcodeFiles[2][i];
    }
    cout << "Mcode 3 (size " << mcodeFiles[2].size() << "):" << endl;
    for (int i=0; i < mcodeFiles[2].size(); i++)
    {
        cout << mcodeThree[i];
    }
    cout << "\n\n";

//  Inicio de programa
    cout <<"| --------------------- Part 1 --------------------- |" << endl;
    cout << "T R A N S M I S S I O N  1" << endl;
    patternFinder(mcodeOne, transmissionOne);
    patternFinder(mcodeTwo, transmissionOne);
    patternFinder(mcodeThree, transmissionOne);
    
    cout << "\nT R A N S M I S S I O N  2" << endl;
    patternFinder(mcodeOne, transmissionTwo);
    patternFinder(mcodeTwo, transmissionTwo);
    patternFinder(mcodeThree, transmissionTwo);
    
    cout <<"\n| --------------------- Part 2 --------------------- |" << endl;
    cout << "\nT R A N S M I S S I O N  1" << endl;
    findLongestPalindromicString(transmissionOne);
    cout << "\nT R A N S M I S S I O N  2" << endl;
    findLongestPalindromicString(transmissionTwo);

    cout <<"\n| --------------------- Part 3 --------------------- |" << endl;
    commonSubstringCal(transmissionOne, transmissionTwo);
    
    return 0;
}