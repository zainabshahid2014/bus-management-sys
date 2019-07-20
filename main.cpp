#include <iostream>
using namespace std;

// Function declaration
void displayData(int num[10], string from[10], string to[10], string arrival[10], string departure[10], int *times);
void getinfo(int num[10], string from[10], string to[10], string arrival[10], string departure[10], int *times);
void showbus(int num[10], string from[10], string to[10], string arrival[10], string departure[10]);
void reserve(string status[10][10]);

int main()
{
    //local variables
    bool exit = false;
    int n;
    int times;
    int num[10];
    string from[10];
    string to[10];
    string arrival[10];
    string departure[10];
    string status[10][10];
    // storing data of seats for first time.
    for(int i = 1 ; i <= 10 ; i++)
    {
        for(int j = 1 ; j <= 10 ; j++)
        {
            status[i][j] = "Empty";
        }
    }

    //taking choice from user.
    while(!exit)
    {
        //taking choice.
        cout << "\nEnter the number to choose your option:\n";

        cout<<"\n\n\n\n";

        cout<<"\t\t\t1.Install\n\t\t\t"

        <<"2.Buses Available\n\t\t\t"

        <<"3.Show\n\t\t\t"

        <<"4.Reservation. \n\t\t\t"

        <<"5.Exit";

        cout<<"\n\t\t\tEnter your choice:-> ";

        cin >> n;
        if(n == 1)
        {
            getinfo(num, from , to , arrival, departure , &times);
        }
        else if(n == 2)
        {
            displayData(num, from , to , arrival, departure , &times);
        }
        else if(n == 3)
        {
            showbus(num, from , to , arrival, departure);
        }
        else if(n == 4)
        {
            reserve(status);
        }
        else if(n == 5)
        {
            exit = true;
        }
        else
        {
            cout << "Enter any valid option.";
        }
    }


   return 0;
}
void getinfo(int num[10], string from[10], string to[10], string arrival[10], string departure[10], int *times)
{
    cout << "how many buses you want to store: ";
    cin >> *times;

    for(int i = 0 ; i < *times ; i++)
    {
        cout << "\nEnter number of bus: ";
        cin >> num[i] ;
        cout << "Enter from: ";
        cin >> from[i];
        cout << "Enter to: ";
        cin >> to[i];
        cout << "Enter arrival: ";
        cin >> arrival[i];
        cout << "Enter departure: ";
        cin >> departure[i];
    }


}
void displayData(int num[10], string from[10], string to[10], string arrival[10], string departure[10], int *times)
{
     for(int i = 0 ; i < *times ; i++)
    {
        cout << "\nDisplaying Information.\n" << endl;
        cout << "bus number: " << num[i] << endl;
        cout <<"from: " << from[i] << endl;
        cout << "to: " << to[i] << endl;
        cout << "arrival: " << arrival[i] <<endl ;
        cout << "departure: " << departure[i];
    }

}
void showbus(int num[10], string from[10], string to[10], string arrival[10], string departure[10])
{
    int a;
    cout << "Enter the number of bus of which you want to see data: ";
    cin >> a;

    a = a - 1;
    cout << "\nShowing Information." << endl;
    cout << "bus number: " << num[a] << endl;
    cout <<"from: " << from[a] << endl;
    cout << "to: " << to[a] << endl;
    cout << "arrival: " << arrival[a] <<endl ;
    cout << "departure: " << departure[a];
}

void reserve(string status[10][10])
{
    int b, number;


    cout << "Enter bus number: ";
    cin >> b;

    for(int i = 1 ; i <= 10 ; i++)
    {
        cout << "seat " << i << ":" << status[b][i] << "\t";
        if(i == 5)
            cout << endl;
    }

    reserving:
    cout << "\nEnter the number of seat you want to reserve: ";
    cin >> number;

    if(status[b][number] == "occupied")
    {
        cout << "sorry! this seat is preoccupied.";
        goto reserving;
    }
    else
    {
        cout << "your seat has been successfully booked!";
    }

    status[b][number] = "occupied";

}


