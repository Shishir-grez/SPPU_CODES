#include <iostream>
#include <string>
using namespace std;
class Shop
{
public:
    string name;
    float price;
    void Name()
    {
        cout << "Book name: ";
        cin >> name;
        cout << endl;
    }
    void Price()
    {
        cout << "Book Price: ";
        cin >> price;
        cout << endl;
    }
    virtual void detail() = 0;
    virtual void display() = 0;
};
class Book : public Shop
{
public:
    float pages;
    int temp;

    void detail()
    {
        cout << "Page count: ";
        cin >> pages;
        cout << endl;
        temp = int(pages);
    }
    void display()
    {
        try
        {
            if (temp != pages)
            {
                throw temp;
            }
            else
            {
                cout << "Book name: " << name << endl;
                cout << "Book Price: " << price << endl;
                cout << "Page count: " << pages << endl;
            }
        }
        catch (int temp)
        {
            cout << "Book name : "
                 << "--" << endl;
            cout << "Book Price : "
                 << "0" << endl;
            cout << "Page count : "
                 << "0" << endl;
        }
    }
};

class AudioBook : public Shop
{
public:
    float time;
    int temp;
    void detail()
    {
        cout << "Duration : ";
        cin >> time;
        cout << endl;
        temp = int(time);
    }
    void display()
    {
        try
        {
            if (temp == time)
            {
                throw temp;
            }
            else
            {
                cout << "Book name: " << name << endl;
                cout << "Book Price: " << price << endl;
                cout << "Duration : " << time << endl;
            }
        }
        catch (int temp)
        {
            cout << "Book name : "
                 << "--" << endl;
            cout << "Book Price : "
                 << "0" << endl;
            cout << "Duration : "
                 << "0" << endl;
        }
    }
};
int main()
{
    Book A;
    AudioBook B;
    int ch;
    do
    {
        cout << "Enter 1 for Book " << endl;
        cout << "Enter 2 for AudioBook " << endl;
        cout << "Enter 3 to Exit " << endl;
        cout << "Enter choice : ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case (1):
        {
            A.Name();
            A.Price();
            A.detail();
            A.display();
            break;
        }
        case (2):
        {
            B.Name();
            B.Price();
            B.detail();
            B.display();
            break;
        }
        case (3):
        {
            return 0;
        }
        break;
        default:
        {
            cout << "Enter correct choice!";
        }
        break;
        }
    } while (ch != 3);
}