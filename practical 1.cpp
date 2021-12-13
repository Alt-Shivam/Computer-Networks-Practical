/*
  Name:Shivank Chaudhary
  Roll No-20201424
  College roll no-20020570031
  Practical 1
  Simulate Cyclic Redundancy Check (CRC) error detection algorithm for noisy channel.
*/


#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void calc(int *tmp, int *gen, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tmp[i] == gen[i])
            tmp[i] = 0;
        else
            tmp[i] = 1;
    }
}

int main()
{
    int *message, *key;
    int msize, ksize, i;

    cout << "\nEnter Key Length-->";
    cin >> ksize;
    key = new int[ksize];

    cout << "\n Enter value of Key-->";
    for (i = 0; i < ksize; i++)
        cin >> key[i];

    cout << "\n Enter message size-->";
    cin >> msize;
    message = new int[msize + ksize - 1];

    cout << "\n Now Enter Message-->";
    for (i = 0; i < msize; i++)
        cin >> message[i];

    for (i = msize; i < msize + ksize - 1; i++)
        message[i] = 0;

    int *tmp = new int[ksize];
    int *zkey = new int[ksize];
    for (i = 0; i < ksize; i++)
    {
        tmp[i] = message[i];
        zkey[i] = 0;
    }

    for (i = ksize - 1; i < msize + ksize - 1; i++)
    {
        tmp[ksize - 1] = message[i];
        
        if (tmp[0] == 0)
            calc(tmp, zkey, ksize);

        else
            calc(tmp, key, ksize);

        for (int j = 1; j < ksize; j++)
        {
            tmp[j - 1] = tmp[j];
        }
    }

    cout << "\n Cyclic Redundancy Check (CRC) is:";
    for (i = 0; i < ksize - 1; i++)
        cout << tmp[i];

    for (int i = msize, j = 0; i < ksize + msize - 1, j < ksize - 1; i++, j++)
    {
        message[i] = tmp[j];
    }

    int n = rand() % (ksize + msize + 5);
    message[n] = !message[n];
    cout << "\n\t"<< n << "\n\t";

    for (i = 0; i < ksize; i++)
    {
        tmp[i] = message[i];
        zkey[i] = 0;
    }

    for (i = ksize - 1; i < msize + ksize - 1; i++)
    {
        tmp[ksize - 1] = message[i];
        if (tmp[0] == 0)
            calc(tmp, zkey, ksize);

        else
            calc(tmp, key, ksize);

        for (int j = 1; j < ksize; j++)
        {
            tmp[j - 1] = tmp[j];
        }
    }
    for (int i = 0; i < ksize - 1; i++)
    {
        cout << tmp[i];
    }

    int flag = 1;
    for (int i = 0; i < ksize - 1; i++)
    {
        if (tmp[i] == 1)
            flag = 0;
    }
    if (flag == 0)
        cout << "\nError";
    else
        cout << "\nNo error";

    getch();
    return 0;
}
