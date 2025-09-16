#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

// Base User class
class User
{
protected:
    string username;
    string password;
    string email;
    int userId;
    static int nextId;

public:
    User() : userId(nextId++) {}
    User(string uname, string pwd, string em) : username(uname), password(pwd), email(em), userId(nextId++) {}

    virtual bool login(string uname, string pwd)
    {
        return (username == uname && password == pwd);
    }

    bool forgotPassword(string em)
    {
        if (email == em)
        {
            cout << "Enter new password: ";
            cin >> password;
            return true;
        }
        return false;
    }

    void displayUserInfo()
    {
        cout << "User ID: " << userId << endl;
        cout << "Username: " << username << endl;
        cout << "Email: " << email << endl;
    }

    string getUsername() { return username; }
    string getPassword() { return password; }
    string getEmail() { return email; }
    int getUserId() { return userId; }

    void setPassword(string pwd) { password = pwd; }

    virtual void saveToFile(ofstream &file)
    {
        file << userId << "," << username << "," << password << "," << email << endl;
    }

    virtual void loadFromFile(ifstream &file)
    {
        string line;
        getline(file, line, ',');
        userId = stoi(line);
        getline(file, username, ',');
        getline(file, password, ',');
        getline(file, email);
    }
};

int User::nextId = 1;

// Derived Customer class
class Customer : public User
{
private:
    string shippingAddress;
    vector<int> purchaseHistory;

public:
    Customer() : User() {}
    Customer(string uname, string pwd, string em, string address)
        : User(uname, pwd, em), shippingAddress(address) {}

    void setShippingAddress(string address)
    {
        shippingAddress = address;
    }

    string getShippingAddress()
    {
        return shippingAddress;
    }

    void addPurchase(int orderId)
    {
        purchaseHistory.push_back(orderId);
    }

    void viewPurchaseHistory()
    {
        cout << "Purchase History for " << username << ":" << endl;
        for (int id : purchaseHistory)
        {
            cout << "Order ID: " << id << endl;
        }
    }

    void saveToFile(ofstream &file) override
    {
        User::saveToFile(file);
        file << "," << shippingAddress << ",";
        for (size_t i = 0; i < purchaseHistory.size(); ++i)
        {
            file << purchaseHistory[i];
            if (i != purchaseHistory.size() - 1)
            {
                file << ";";
            }
        }
        file << endl;
    }

    void loadFromFile(ifstream &file) override
    {
        User::loadFromFile(file);
        file.ignore(); // skip the comma
        getline(file, shippingAddress, ',');

        string historyStr;
        getline(file, historyStr);
        if (!historyStr.empty())
        {
            size_t pos = 0;
            while ((pos = historyStr.find(';')) != string::npos)
            {
                string token = historyStr.substr(0, pos);
                purchaseHistory.push_back(stoi(token));
                historyStr.erase(0, pos + 1);
            }
            if (!historyStr.empty())
            {
                purchaseHistory.push_back(stoi(historyStr));
            }
        }
    }
};

// Product class
class Product
{
private:
    int productId;
    string name;
    double price;
    int stockQuantity;
    static int nextId;

public:
    Product() : productId(nextId++) {}
    Product(string n, double p, int qty) : name(n), price(p), stockQuantity(qty), productId(nextId++) {}

    void displayProduct()
    {
        cout << "ID: " << productId << " | Name: " << name
             << " | Price: $" << fixed << setprecision(2) << price
             << " | Stock: " << stockQuantity << endl;
    }

    bool updateStock(int quantity)
    {
        if (stockQuantity + quantity >= 0)
        {
            stockQuantity += quantity;
            return true;
        }
        return false;
    }

    int getProductId() { return productId; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getStockQuantity() { return stockQuantity; }

    void saveToFile(ofstream &file)
    {
        file << productId << "," << name << "," << price << "," << stockQuantity << endl;
    }

    void loadFromFile(ifstream &file)
    {
        string line;
        getline(file, line, ',');
        productId = stoi(line);
        getline(file, name, ',');
        getline(file, line, ',');
        price = stod(line);
        getline(file, line);
        stockQuantity = stoi(line);
    }
};

int Product::nextId = 1;

// Order class
class Order
{
private:
    int orderId;
    vector<pair<int, int>> products; // productId and quantity
    double totalAmount;
    double shippingFee;
    int customerId;
    static int nextId;

public:
    Order() : orderId(nextId++) {}
    Order(int custId) : customerId(custId), orderId(nextId++) {}

    void addProduct(int productId, int quantity)
    {
        products.push_back(make_pair(productId, quantity));
    }

    void calculateTotal(const vector<Product> &allProducts)
    {
        totalAmount = 0.0;
        for (const auto &item : products)
        {
            for (const Product &p : allProducts)
            {
                if (p.getProductId() == item.first)
                {
                    totalAmount += p.getPrice() * item.second;
                    break;
                }
            }
        }
    }

    void calculateShipping()
    {
        // Simple shipping calculation
        shippingFee = 5.99 + (products.size() * 1.50);
    }

    void displayOrder(const vector<Product> &allProducts)
    {
        cout << "Order ID: " << orderId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Products:" << endl;

        for (const auto &item : products)
        {
            for (const Product &p : allProducts)
            {
                if (p.getProductId() == item.first)
                {
                    cout << " - " << p.getName() << " x" << item.second
                         << " @ $" << p.getPrice() << " each" << endl;
                    break;
                }
            }
        }

        cout << "Subtotal: $" << fixed << setprecision(2) << totalAmount << endl;
        cout << "Shipping: $" << shippingFee << endl;
        cout << "Total: $" << (totalAmount + shippingFee) << endl;
    }

    int getOrderId() { return orderId; }
    int getCustomerId() { return customerId; }
    double getTotalAmount() { return totalAmount; }
    double getShippingFee() { return shippingFee; }
    const vector<pair<int, int>> &getProducts() { return products; }

    void saveToFile(ofstream &file)
    {
        file << orderId << "," << customerId << "," << totalAmount << "," << shippingFee << ",";
        for (size_t i = 0; i < products.size(); ++i)
        {
            file << products[i].first << ":" << products[i].second;
            if (i != products.size() - 1)
            {
                file << ";";
            }
        }
        file << endl;
    }

    void loadFromFile(ifstream &file)
    {
        string line;
        getline(file, line, ',');
        orderId = stoi(line);
        getline(file, line, ',');
        customerId = stoi(line);
        getline(file, line, ',');
        totalAmount = stod(line);
        getline(file, line, ',');
        shippingFee = stod(line);

        getline(file, line);
        if (!line.empty())
        {
            size_t pos = 0;
            while ((pos = line.find(';')) != string::npos)
            {
                string token = line.substr(0, pos);
                size_t colon = token.find(':');
                int prodId = stoi(token.substr(0, colon));
                int qty = stoi(token.substr(colon + 1));
                products.push_back(make_pair(prodId, qty));
                line.erase(0, pos + 1);
            }
            if (!line.empty())
            {
                size_t colon = line.find(':');
                int prodId = stoi(line.substr(0, colon));
                int qty = stoi(line.substr(colon + 1));
                products.push_back(make_pair(prodId, qty));
            }
        }
    }
};

int Order::nextId = 1;

// Store class to manage all operations
class Store
{
private:
    vector<Customer> customers;
    vector<Product> products;
    vector<Order> orders;
    Customer *currentUser;

    void loadData()
    {
        // Load products
        ifstream productFile("products.dat");
        if (productFile.is_open())
        {
            while (productFile.peek() != EOF)
            {
                Product p;
                p.loadFromFile(productFile);
                products.push_back(p);
            }
            productFile.close();
        }
        else
        {
            // Initialize with some default products if file doesn't exist
            products.push_back(Product("Laptop", 999.99, 10));
            products.push_back(Product("Smartphone", 699.99, 15));
            products.push_back(Product("Headphones", 149.99, 20));
            products.push_back(Product("Tablet", 349.99, 8));
            products.push_back(Product("Smartwatch", 199.99, 12));
        }

        // Load customers
        ifstream customerFile("customers.dat");
        if (customerFile.is_open())
        {
            while (customerFile.peek() != EOF)
            {
                Customer c;
                c.loadFromFile(customerFile);
                customers.push_back(c);
            }
            customerFile.close();
        }

        // Load orders
        ifstream orderFile("orders.dat");
        if (orderFile.is_open())
        {
            while (orderFile.peek() != EOF)
            {
                Order o;
                o.loadFromFile(orderFile);
                orders.push_back(o);
            }
            orderFile.close();
        }
    }

    void saveData()
    {
        // Save products
        ofstream productFile("products.dat");
        for (Product &p : products)
        {
            p.saveToFile(productFile);
        }
        productFile.close();

        // Save customers
        ofstream customerFile("customers.dat");
        for (Customer &c : customers)
        {
            c.saveToFile(customerFile);
        }
        customerFile.close();

        // Save orders
        ofstream orderFile("orders.dat");
        for (Order &o : orders)
        {
            o.saveToFile(orderFile);
        }
        orderFile.close();
    }

    void createAccount()
    {
        string username, password, email, address;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter shipping address: ";
        cin.ignore();
        getline(cin, address);

        // Check if username already exists
        for (Customer &c : customers)
        {
            if (c.getUsername() == username)
            {
                cout << "Username already exists. Please choose another." << endl;
                return;
            }
        }

        Customer newCustomer(username, password, email, address);
        customers.push_back(newCustomer);
        cout << "Account created successfully!" << endl;
    }

    void login()
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (Customer &c : customers)
        {
            if (c.login(username, password))
            {
                currentUser = &c;
                cout << "Login successful! Welcome, " << username << "!" << endl;
                return;
            }
        }

        cout << "Invalid username or password." << endl;
    }

    void displayProducts()
    {
        cout << "Available Products:" << endl;
        for (Product &p : products)
        {
            p.displayProduct();
        }
    }

    void buyProducts()
    {
        if (currentUser == nullptr)
        {
            cout << "Please login first." << endl;
            return;
        }

        displayProducts();
        Order newOrder(currentUser->getUserId());
        char choice;

        do
        {
            int productId, quantity;
            cout << "Enter product ID to purchase (0 to finish): ";
            cin >> productId;

            if (productId == 0)
                break;

            cout << "Enter quantity: ";
            cin >> quantity;

            bool productFound = false;
            for (Product &p : products)
            {
                if (p.getProductId() == productId)
                {
                    productFound = true;
                    if (p.updateStock(-quantity))
                    {
                        newOrder.addProduct(productId, quantity);
                        cout << "Added to order." << endl;
                    }
                    else
                    {
                        cout << "Insufficient stock." << endl;
                    }
                    break;
                }
            }

            if (!productFound)
            {
                cout << "Product not found." << endl;
            }

            cout << "Add another product? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        if (newOrder.getProducts().size() > 0)
        {
            newOrder.calculateTotal(products);
            newOrder.calculateShipping();
            orders.push_back(newOrder);
            currentUser->addPurchase(newOrder.getOrderId());
            cout << "Order placed successfully!" << endl;
            newOrder.displayOrder(products);
        }
        else
        {
            cout << "No products were ordered." << endl;
        }
    }

    void cancelOrder()
    {
        if (currentUser == nullptr)
        {
            cout << "Please login first." << endl;
            return;
        }

        cout << "Your Orders:" << endl;
        bool hasOrders = false;

        for (Order &o : orders)
        {
            if (o.getCustomerId() == currentUser->getUserId())
            {
                hasOrders = true;
                o.displayOrder(products);
                cout << "-------------------" << endl;
            }
        }

        if (!hasOrders)
        {
            cout << "You have no orders to cancel." << endl;
            return;
        }

        int orderId;
        cout << "Enter Order ID to cancel (0 to cancel): ";
        cin >> orderId;

        if (orderId == 0)
            return;

        for (auto it = orders.begin(); it != orders.end(); ++it)
        {
            if (it->getOrderId() == orderId && it->getCustomerId() == currentUser->getUserId())
            {
                // Restore stock
                for (const auto &item : it->getProducts())
                {
                    for (Product &p : products)
                    {
                        if (p.getProductId() == item.first)
                        {
                            p.updateStock(item.second);
                            break;
                        }
                    }
                }

                orders.erase(it);
                cout << "Order cancelled successfully." << endl;
                return;
            }
        }

        cout << "Order not found or you don't have permission to cancel it." << endl;
    }

    void displayTotalPurchases()
    {
        if (currentUser == nullptr)
        {
            cout << "Please login first." << endl;
            return;
        }

        double totalSpent = 0.0;
        double totalShipping = 0.0;
        int orderCount = 0;

        cout << "Your Purchase History:" << endl;
        for (Order &o : orders)
        {
            if (o.getCustomerId() == currentUser->getUserId())
            {
                orderCount++;
                totalSpent += o.getTotalAmount();
                totalShipping += o.getShippingFee();
                o.displayOrder(products);
                cout << "-------------------" << endl;
            }
        }

        if (orderCount == 0)
        {
            cout << "You haven't made any purchases yet." << endl;
        }
        else
        {
            cout << "Summary:" << endl;
            cout << "Total Orders: " << orderCount << endl;
            cout << "Total Spent on Products: $" << fixed << setprecision(2) << totalSpent << endl;
            cout << "Total Shipping Fees: $" << totalShipping << endl;
            cout << "Grand Total: $" << (totalSpent + totalShipping) << endl;
        }
    }

    void forgotPassword()
    {
        string username, email;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter email: ";
        cin >> email;

        for (Customer &c : customers)
        {
            if (c.getUsername() == username && c.getEmail() == email)
            {
                string newPassword;
                cout << "Enter new password: ";
                cin >> newPassword;
                c.setPassword(newPassword);
                cout << "Password updated successfully!" << endl;
                return;
            }
        }

        cout << "Username and email combination not found." << endl;
    }

public:
    Store() : currentUser(nullptr)
    {
        loadData();
    }

    ~Store()
    {
        saveData();
    }

    void displayMenu()
    {
        cout << "\nWelcome to Shipzy Store" << endl;
        cout << "Menu:" << endl;
        cout << "1: Create Account" << endl;
        cout << "2: Login" << endl;
        cout << "3: Display Products" << endl;
        cout << "4: Buy Products" << endl;
        cout << "5: Cancel Order" << endl;
        cout << "6: Total Purchases and Shipping Fees" << endl;
        cout << "7: Forgot Password" << endl;
        cout << "8: Exit Store" << endl;
    }

    void run()
    {
        int choice;
        do
        {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                buyProducts();
                break;
            case 5:
                cancelOrder();
                break;
            case 6:
                displayTotalPurchases();
                break;
            case 7:
                forgotPassword();
                break;
            case 8:
                cout << "Thank you for shopping with Shipzy Store. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (choice != 8);
    }
};

int main()
{
    Store shipzyStore;
    shipzyStore.run();
    return 0;
}