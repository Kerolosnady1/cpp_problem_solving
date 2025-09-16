#include <iostream>
using namespace std;

int calcOffer(int numberOfMangoes, int price)
{
    if (numberOfMangoes % 3 == 0)
    {
        cout << "For Every Three Mangoes You Bought, You Get One Free Of Them." << endl;
        cout << "Number Of The Free Mangoes: " << numberOfMangoes / 3 << endl;
        cout << "The Number Of Mangoes Without The Free Ones: " << numberOfMangoes - (numberOfMangoes / 3) << endl;
        cout << "The Price Of Mangoes: " << (numberOfMangoes - (numberOfMangoes / 3)) * price;
    }
    else if (numberOfMangoes % 3 != 0 > 2)
    {
        cout << "Number Of The Free Mangoes: " << numberOfMangoes / 3 << endl;
        cout << "The Number Of Mangoes Without The Free Ones: " << numberOfMangoes - (numberOfMangoes / 3) << endl;
        cout << "The Price Of Mangoes: " << (numberOfMangoes - (numberOfMangoes / 3)) * price;
    }
    else
        cout << "You Are Out Of The Offer.";
    return 0;
}

int main()
{
    // 17April25
    // Program:
    // If you buy 3 mangoes you have to buy 2 and get the third for free!
    int numberOfMangoes, price;

    cout << "Enter The Number Of Mangoes: ";
    cin >> numberOfMangoes;
    cout << "Enter The Price: ";
    cin >> price;

    calcOffer(numberOfMangoes, price);
}