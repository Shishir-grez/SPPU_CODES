#include <iostream>
#include <string>

#define N 20

#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

using namespace std;

string Q[N];
int Pr[N];
int heapSize = -1;

void maxHeapify(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left <= heapSize && Pr[left] > Pr[largest])
        largest = left;

    if (right <= heapSize && Pr[right] > Pr[largest])
        largest = right;

    if (largest != i)
    {
        swap(Pr[i], Pr[largest]);
        swap(Q[i], Q[largest]);
        maxHeapify(largest);
    }
}

void buildMaxHeap()
{
    for (int i = (heapSize - 1) / 2; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

void enqueue(string data, int p)
{
    if (heapSize == N - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }

    heapSize++;
    Q[heapSize] = data;
    Pr[heapSize] = p;

    int i = heapSize;
    while (i > 0 && Pr[i] > Pr[(i - 1) / 2])
    {
        swap(Pr[i], Pr[(i - 1) / 2]);
        swap(Q[i], Q[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dequeue()
{
    if (heapSize < 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Deleted Element = " << Q[0] << endl;
    cout << "Its Priority = " << Pr[0] << endl;

    swap(Pr[0], Pr[heapSize]);
    swap(Q[0], Q[heapSize]);
    heapSize--;

    maxHeapify(0);
}

void print()
{
    if (heapSize < 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = 0; i <= heapSize; i++)
    {
        cout << "Patient's Name - " << Q[i];
        switch (Pr[i])
        {
        case 1:
            cout << " Priority - 'Checkup' " << endl;
            break;
        case 5:
            cout << " Priority - 'Non-serious' " << endl;
            break;
        case 10:
            cout << " Priority - 'Serious' " << endl;
            break;
        default:
            cout << "Priority not found" << endl;
        }
    }
}

int main()
{
    string data;
    int opt, n, i, p;
    cout << "Enter Your Choice:-" << endl;

    do
    {
        cout << "1 for Insert the Data in Queue" << endl
             << "2 for show the Data in Queue " << endl
             << "3 for Delete the data from the Queue"
             << endl
             << "0 for Exit" << endl;
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter the number of patients: ";
            cin >> n;
            i = 0;

            while (

                i < n)
            {
                cout << "Enter the name of the patient: ";
                cin >> data;

            ifnotdoagain:
                cout << "Enter the priority (0: serious, 1: non-serious, 2: general checkup): ";
                cin >> p;

                switch (p)
                {
                case 0:
                    enqueue(data, SERIOUS);
                    break;
                case 1:
                    enqueue(data, NONSERIOUS);
                    break;
                case 2:
                    enqueue(data, CHECKUP);
                    break;
                default:
                    goto ifnotdoagain;
                }

                i++;
            }
            buildMaxHeap();
            break;

        case 2:
            print();
            break;

        case 3:
            dequeue();
            break;

        case 0:
            cout << "Bye Bye!" << endl;
            break;

        default:
            cout << "Incorrect Choice" << endl;
        }
    } while (opt != 0);

    return 0;
}
