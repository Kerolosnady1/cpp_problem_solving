#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Product
{
    int id;
    string name;
    int price;
};

struct CartItem
{
    int productID;
    Product Name;
    int quantity;
};

class shipzy_store
{
private:
    vector<Product> products = {
        {111, "Smart Watch", 200},
        {222, "Bluetooth Speaker", 300},
        {333, "Power Bank", 60},
        {444, "Wireless Mouse", 140},
        {555, "LED Lamp", 100}};

    vector<CartItem> cart;

public:
    void run()
    {
        int Num;
        while (true)
        {
            cout << "\t  ============================" << endl;
            cout << "\t  Welcome to your shipzy store  \n";
            cout << "\t  ============================\n"
                 << endl;
            cout << "\t Menu:\n";
            cout << "\t *****\n";
            cout << "1: Create Account\n";
            cout << "2: Login\n";
            cout << "3: Display Products\n";
            cout << "4: Buy Products\n";
            cout << "5: Cancel Products\n";
            cout << "6: Calculate_Total \n";
            cout << "7: Forgot Password\n";
            cout << "8: Exit Store\n";
            cout << "Enter your choice: ";
            cin >> Num;
            cin.ignore();

            if (Num == 1)
            {
                Create_Account();
            }
            else if (Num == 2)
            {
                Login();
            }
            else if (Num == 3)
            {
                Display_Products();
            }
            else if (Num == 4)
            {
                Buy_Products();
            }
            else if (Num == 5)
            {
                Cancel_Products();
            }
            else if (Num == 6)
            {
                Calculate_Total();
            }
            else if (Num == 7)
            {
                Forgot_Password();
            }
            else if (Num == 8)
            {
                cout << "Thank you for visiting Shipzy Store" << endl;
                break;
            }
            else
            {
                break;
            }
        }
    }

    void Create_Account()
    {
        char username[100], password[100], email[100];

        cout << "Enter your username: ";
        cin.getline(username, sizeof(username));

        cout << "Enter your email: ";
        cin.getline(email, sizeof(email));

        if (strstr(email, "@gmail.com") == nullptr)
        {
            cout << "Invalid email format. Must include '@gmail.com'\n";
            return;
        }

        cout << "Enter your password (min 8 characters): ";
        cin.getline(password, sizeof(password));

        if (strlen(password) < 8)
        {
            cout << "Password is too short.\n";
            return;
        }

        ofstream file("data.txt", ios::app);
        file << username << " " << email << " " << password << endl;
        file.close();

        cout << "Account created successfully!\n";
    }

    void Login()
    {
        string username, password, email, storedUsername, storedPassword, storedEmail;

        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your email: ";
        getline(cin, email);
        cout << "Enter your password: ";
        getline(cin, password);

        ifstream file("data.txt");

        if (!file)
        {
            cout << "Error: Could not open the file!" << endl;
            return;
        }

        bool loginSuccess = false;

        while (file >> storedUsername >> storedEmail >> storedPassword)
        {
            if (storedUsername == username && storedPassword == password)
            {
                loginSuccess = true;
                break;
            }
        }

        file.close();

        if (loginSuccess)
        {
            cout << "Login successful!\n";
        }
        else
        {
            cout << "Invalid username or password.\n";
        }
    }

    void Display_Products()
    {
        cout << "\nAvailable Products:\n";
        cout << "----------------------------\n";
        for (const auto &product : products)
        {
            cout << "Product ID: " << product.id
                 << " | Name: " << product.name
                 << " | Price: $" << product.price << "\n";
        }
        cout << "----------------------------\n";
    }

    void Buy_Products()
    {
        int productID, quantity;
        char addMore = 'y';

        while (addMore == 'y' || addMore == 'Y')
        {
            cout << "Enter the Product ID you want to buy: ";
            cin >> productID;
            cout << "Enter the quantity: ";
            cin >> quantity;

            bool found = false;
            for (const auto &product : products)
            {
                if (product.id == productID)
                {
                    cart.push_back({productID, product, quantity});
                    cout << product.name << " (x" << quantity << ") added to your cart." << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Invalid Product ID." << endl;
            }

            cout << "Add another product? (y/n): ";
            cin >> addMore;
        }
    }

    void Cancel_Products()
    {
        if (cart.empty())
        {
            cout << "your cart is empty \n";
            return;
        }
        cout << "Your cart contains:\n";
        for (int i = 0; i < cart.size(); ++i)
        {

            cout << i + 1 << " product ID = " << cart[i].productID << endl;
            cout << i + 1 << " name = " << cart[i].Name.name << endl;
            cout << i + 1 << " quantity = " << cart[i].quantity << endl;
        }

        int choice;
        cout << "enter the number of the product you want to cancel \n";
        cin >> choice;

        if (choice < 1 || choice > cart.size())
        {
            cout << "Invalid choice.\n";
            return;
        }

        CartItem *itemToDelete = &cart[choice - 1];
        cout << "Removing: Product ID = " << itemToDelete->productID
             << " , Name = " << itemToDelete->Name.name
             << ", Quantity = " << itemToDelete->quantity << endl;

        cart.erase(cart.begin() + (choice - 1));

        cout << "Product removed from cart successfully.\n";
    }

    void Calculate_Total()
    {
        Product productId;
        int total = 0, totalQuantity, price;
        for (const auto &item : cart)
        {
            for (const auto &product : products)
            {
                if (product.id == item.productID)
                {
                    total += product.price * item.quantity;
                    totalQuantity = item.quantity;
                }
            }
        }
        cout << "===============================================\n";
        cout << "Total: $" << total << endl;
        cout << "===============================================\n";
        cout << "Total Quantities: " << totalQuantity << endl;
        cout << "===============================================\n";
        cout << "Last Product ID: " << productId.id << endl;
        cout << "===============================================\n";
        cout << "Name of Last Product: " << productId.name << endl;
        cout << "===============================================\n";
        cout << "Price of Last Product For Peace: $" << productId.price << endl;
        cout << "===============================================\n";
        cout << "Another Products Price For Peace: " << (total - productId.price * totalQuantity) / totalQuantity << endl;
        cout << "===============================================\n";
        cout << "Products With ID & Price: \n"
             << endl;
        cout << "ID: 111, PN: Smart Watch, Price: 200," << endl;
        cout << "ID: 222, PN: Bluetooth Speaker, Price: 300" << endl;
        cout << "ID: 333, PN: Power Bank, Price: 60" << endl;
        cout << "ID: 444, PN: Wireless Mouse, Price: 140" << endl;
        cout << "ID: 555, PN: LED Lamp, Price: 100" << endl;
    }

    void Forgot_Password()
    {
        string username, id, email, password;
        cout << "Enter your username: ";
        cin >> username;

        ifstream file("data.txt");

        bool found = false;
        while (file >> id >> email >> password)
        {
            if (id == username)
            {
                found = true;
                break;
            }
        }
        file.close();

        if (found)
        {
            cout << "Account found! your  email   is: " << email << "\n";
            cout << "Account found! your password is: " << password << "\n";
        }
        else
        {
            cout << "Username not found.\n";
        }
    }
};

int main()
{
    shipzy_store store;
    store.run();
    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Product
{
    int id;
    string name;
    int price;
};

struct CartItem
{
    int productID;
    Product Name;
    int quantity;
};

class shipzy_store
{
private:
    vector<Product> products = {
        {111, "Smart Watch", 200},
        {222, "Bluetooth Speaker", 300},
        {333, "Power Bank", 60},
        {444, "Wireless Mouse", 140},
        {555, "LED Lamp", 100}};

    vector<CartItem> cart;

public:
    void run()
    {
        int Num;
        while (true)
        {
            cout << "\t  ============================" << endl;
            cout << "\t  Welcome to your shipzy store  \n";
            cout << "\t  ============================\n"
                 << endl;
            cout << "\t Menu:\n";
            cout << "\t *****\n";
            cout << "1: Create Account\n";
            cout << "2: Login\n";
            cout << "3: Display Products\n";
            cout << "4: Buy Products\n";
            cout << "5: Cancel Products\n";
            cout << "6: Calculate_Total \n";
            cout << "7: Forgot Password\n";
            cout << "8: Exit Store\n";
            cout << "Enter your choice: ";
            cin >> Num;
            cin.ignore();

            if (Num == 1)
            {
                Create_Account();
            }
            else if (Num == 2)
            {
                Login();
            }
            else if (Num == 3)
            {
                Display_Products();
            }
            else if (Num == 4)
            {
                Buy_Products();
            }
            else if (Num == 5)
            {
                Cancel_Products();
            }
            else if (Num == 6)
            {
                Calculate_Total();
            }
            else if (Num == 7)
            {
                Forgot_Password();
            }
            else if (Num == 8)
            {
                cout << "Thank you for visiting Shipzy Store" << endl;
                break;
            }
            else
            {
                break;
            }
        }
    }

    void Create_Account()
    {
        char username[100], password[100], email[100];

        cout << "Enter your username: ";
        cin.getline(username, sizeof(username));

        cout << "Enter your email: ";
        cin.getline(email, sizeof(email));

        if (strstr(email, "@gmail.com") == nullptr)
        {
            cout << "Invalid email format. Must include '@gmail.com'\n";
            return;
        }

        cout << "Enter your password (min 8 characters): ";
        cin.getline(password, sizeof(password));

        if (strlen(password) < 8)
        {
            cout << "Password is too short.\n";
            return;
        }

        ofstream file("data.txt", ios::app);
        file << username << " " << email << " " << password << endl;
        file.close();

        cout << "Account created successfully!\n";
    }

    void Login()
    {
        string username, password, email, storedUsername, storedPassword, storedEmail;

        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your email: ";
        getline(cin, email);
        cout << "Enter your password: ";
        getline(cin, password);

        ifstream file("data.txt");

        if (!file)
        {
            cout << "Error: Could not open the file!" << endl;
            return;
        }

        bool loginSuccess = false;

        while (file >> storedUsername >> storedEmail >> storedPassword)
        {
            if (storedUsername == username && storedPassword == password)
            {
                loginSuccess = true;
                break;
            }
        }

        file.close();

        if (loginSuccess)
        {
            cout << "Login successful!\n";
        }
        else
        {
            cout << "Invalid username or password.\n";
        }
    }

    void Display_Products()
    {
        cout << "\nAvailable Products:\n";
        cout << "----------------------------\n";
        for (const auto &product : products)
        {
            cout << "Product ID: " << product.id
                 << " | Name: " << product.name
                 << " | Price: $" << product.price << "\n";
        }
        cout << "----------------------------\n";
    }

    void Buy_Products()
    {
        int productID, quantity;
        char addMore = 'y';

        while (addMore == 'y' || addMore == 'Y')
        {
            cout << "Enter the Product ID you want to buy: ";
            cin >> productID;
            cout << "Enter the quantity: ";
            cin >> quantity;

            bool found = false;
            for (const auto &product : products)
            {
                if (product.id == productID)
                {
                    cart.push_back({productID, product, quantity});
                    cout << product.name << " (x" << quantity << ") added to your cart." << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Invalid Product ID." << endl;
            }

            cout << "Add another product? (y/n): ";
            cin >> addMore;
        }
    }

    void Cancel_Products()
    {
        if (cart.empty())
        {
            cout << "your cart is empty \n";
            return;
        }
        cout << "Your cart contains:\n";
        for (int i = 0; i < cart.size(); ++i)
        {

            cout << i + 1 << " product ID = " << cart[i].productID << endl;
            cout << i + 1 << " name = " << cart[i].Name.name << endl;
            cout << i + 1 << " quantity = " << cart[i].quantity << endl;
        }

        int choice;
        cout << "enter the number of the product you want to cancel \n";
        cin >> choice;

        if (choice < 1 || choice > cart.size())
        {
            cout << "Invalid choice.\n";
            return;
        }

        CartItem *itemToDelete = &cart[choice - 1];
        cout << "Removing: Product ID = " << itemToDelete->productID
             << " , Name = " << itemToDelete->Name.name
             << ", Quantity = " << itemToDelete->quantity << endl;

        cart.erase(cart.begin() + (choice - 1));

        cout << "Product removed from cart successfully.\n";
    }

    void Calculate_Total()
    {
        Product productId;
        int total = 0, totalQuantity, price;
        for (const auto &item : cart)
        {
            for (const auto &product : products)
            {
                if (product.id == item.productID)
                {
                    total += product.price * item.quantity;
                    totalQuantity = item.quantity;
                }
            }
        }
        cout << "===============================================\n";
        cout << "Total: $" << total << endl;
        cout << "===============================================\n";
        cout << "Total Quantities: " << totalQuantity << endl;
        cout << "===============================================\n";
        cout << "Last Product ID: " << productId.id << endl;
        cout << "===============================================\n";
        cout << "Name of Last Product: " << productId.name << endl;
        cout << "===============================================\n";
        cout << "Price of Last Product For Peace: $" << productId.price << endl;
        cout << "===============================================\n";
        cout << "Another Products Price For Peace: " << (total - productId.price * totalQuantity) / totalQuantity << endl;
        cout << "===============================================\n";
        cout << "Products With ID & Price: \n"
             << endl;
        cout << "ID: 111, PN: Smart Watch, Price: 200," << endl;
        cout << "ID: 222, PN: Bluetooth Speaker, Price: 300" << endl;
        cout << "ID: 333, PN: Power Bank, Price: 60" << endl;
        cout << "ID: 444, PN: Wireless Mouse, Price: 140" << endl;
        cout << "ID: 555, PN: LED Lamp, Price: 100" << endl;
    }

    void Forgot_Password()
    {
        string username, id, email, password;
        cout << "Enter your username: ";
        cin >> username;

        ifstream file("data.txt");

        bool found = false;
        while (file >> id >> email >> password)
        {
            if (id == username)
            {
                found = true;
                break;
            }
        }
        file.close();

        if (found)
        {
            cout << "Account found! your  email   is: " << email << "\n";
            cout << "Account found! your password is: " << password << "\n";
        }
        else
        {
            cout << "Username not found.\n";
        }
    }
};

int main()
{
    shipzy_store store;
    store.run();
}