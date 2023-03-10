#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the data model for the system
struct MenuItem {
    string name;
    double price;
    int quantity;
};

struct Order {
    vector<MenuItem> items;
    double total;
    bool paid;
};

// Define the class to manage orders
class OrderManager {
private:
    vector<Order> orders;
public:
    // Add an order to the system
    void addOrder(Order order) {
        orders.push_back(order);
    }
    
    // Get the total revenue for the system
    double getTotalRevenue() {
        double revenue = 0;
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].paid) {
                revenue += orders[i].total;
            }
        }
        return revenue;
    }
    
    // Get the number of orders in the system
    int getOrderCount() {
        return orders.size();
    }
};

int main() {
    // Initialize the order manager
    OrderManager orderManager;
    
    // Create some menu items
    MenuItem item1 = {"Hamburger", 8.99, 10};
    MenuItem item2 = {"Fries", 2.99, 20};
    MenuItem item3 = {"Soda", 1.99, 30};
    
    // Create an order
    Order order1;
    order1.items.push_back(item1);
    order1.items.push_back(item2);
    order1.items.push_back(item3);
    order1.total = item1.price + item2.price + item3.price;
    order1.paid = true;
    
    // Add the order to the system
    orderManager.addOrder(order1);
    
    // Display the total revenue and order count
    cout << "Total Revenue: $" << orderManager.getTotalRevenue() << endl;
    cout << "Order Count: " << orderManager.getOrderCount() << endl;
    
    return 0;
}
