// #include <iostream>
// #include <pqxx/pqxx> // Подключение библиотеки

// int main() {
//     try {
//         // Строка подключения к базе данных
//         std::string conninfo = "host=localhost port=5432 dbname=postgres user=postgres password=";

//         // Устанавливаем соединение с базой данных
//         pqxx::connection conn(conninfo);

//         if (conn.is_open()) {
//             std::cout << "Connected to database: " << conn.dbname() << std::endl;
//         } else {
//             std::cerr << "Failed to connect to the database." << std::endl;
//             return 1;
//         }

//         // Закрываем соединение
//         conn.close();
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return 1;
//     }

//     return 0;
// }








// #include <iostream>
// #include <pqxx/pqxx>
// int main()
// {
//     try
//     {
//         pqxx::connection conn(
//             "host=localhost "
//             "port=5432 "
//             "dbname=restaurant_db "
//             "user=myuser "
//             "password=mypassword"
//         );
//         pqxx::work txn{conn};
//         txn.commit();
//         std::cout << "Table created/Table existed" << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << "Error with creating table: " << e.what() << std::endl;
//     }
//     return 0;
// }

#include <iostream>
#include <memory>
#include <pqxx/pqxx>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

void log(const string& message);

class Database {
public:
    pqxx::connection conn;
    Database() : conn(
        "host=localhost "
        "port=5432 "
        "dbname=restaurant_db "
        "user=myuser "
        "password=mypassword"
    ) {}
};


class Category {
private:
    Database& db;
public:
    Category(Database& database) : db(database) {}
    void add(const string& name) {
        try {
            pqxx::work txn(db.conn);
            txn.exec("INSERT INTO categories (category_name) VALUES (" + txn.quote(name) + ")");
            txn.commit();
            log("Added category: " + name);
        } catch (const exception& e) {
            cerr << "Error adding category: " << e.what() << endl;
        }
    }
};

class Dish {
protected:
    Database& db;
public:
    Dish(Database& database) : db(database) {}
    virtual void add(const string& name, int category_id, double price) {
        try {
            pqxx::work txn(db.conn);
            txn.exec("INSERT INTO dishes (name, category_id, price) VALUES (" + 
                     txn.quote(name) + ", " + 
                     to_string(category_id) + ", " + 
                     to_string(price) + ")");
            txn.commit();
            log("Added dish: " + name);
        } catch (const exception& e) {
            cerr << "Error adding dish: " << e.what() << endl;
        }
    }
};

class MainCourse : public Dish {
public:
    MainCourse(Database& database) : Dish(database) {}
};

class Dessert : public Dish {
public:
    Dessert(Database& database) : Dish(database) {}
};

class Order {
private:
    Database& db;
public:
    Order(Database& database) : db(database) {}
    void add(int dish_id, const string& date, int quantity) {
        try {
            pqxx::work txn(db.conn);
            pqxx::result res = txn.exec("SELECT price FROM dishes WHERE id = " + to_string(dish_id));
            
            if (res.empty()) {
                throw runtime_error("Dish with ID " + to_string(dish_id) + " not found");
            }
            
            double price = res[0][0].as<double>();
            double total = price * quantity;
            
            txn.exec("INSERT INTO orders (dish_id, order_date, quantity, total_price) VALUES (" +
                     to_string(dish_id) + ", " +
                     txn.quote(date) + ", " +
                     to_string(quantity) + ", " +
                     to_string(total) + ")");
            txn.commit();
            log("Added order for dish_id: " + to_string(dish_id));
        } catch (const exception& e) {
            cerr << "Error adding order: " << e.what() << endl;
        }
    }
};

void log(const string& message) {
    ofstream file("log.txt", ios::app);
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    file << put_time(localtime(&time), "%Y-%m-%d %H:%M:%S") << " - " << message << endl;
}

void viewDishes(Database& db) {
    try {
        pqxx::work txn(db.conn);
        pqxx::result res = txn.exec("SELECT d.id, d.name, c.category_name, d.price FROM dishes d JOIN categories c ON d.category_id = c.id");
        
        if (res.empty()) {
            cout << "No dishes found." << endl;
        } else {
            for (const auto& row : res) {
                cout << "ID: " << row[0].as<int>() 
                     << ", Name: " << row[1].as<string>() 
                     << ", Category: " << row[2].as<string>() 
                     << ", Price: " << row[3].as<double>() << endl;
            }
        }
        log("Viewed all dishes");
    } catch (const exception& e) {
        cerr << "Error viewing dishes: " << e.what() << endl;
    }
}

void viewOrders(Database& db) {
    try {
        pqxx::work txn(db.conn);
        pqxx::result res = txn.exec("SELECT o.order_id, d.name, o.order_date, o.quantity, o.total_price FROM orders o JOIN dishes d ON o.dish_id = d.id");
        
        if (res.empty()) {
            cout << "No orders found." << endl;
        } else {
            for (const auto& row : res) {
                cout << "Order ID: " << row[0].as<int>() 
                     << ", Dish: " << row[1].as<string>() 
                     << ", Date: " << row[2].as<string>() 
                     << ", Quantity: " << row[3].as<int>() 
                     << ", Total: " << row[4].as<double>() << endl;
            }
        }
        log("Viewed all orders");
    } catch (const exception& e) {
        cerr << "Error viewing orders: " << e.what() << endl;
    }
}

void revenueByCategory(Database& db) {
    try {
        pqxx::work txn(db.conn);
        pqxx::result res = txn.exec(
            "SELECT c.category_name, COALESCE(SUM(o.total_price), 0) as revenue "
            "FROM categories c "
            "LEFT JOIN dishes d ON c.id = d.category_id "
            "LEFT JOIN orders o ON d.id = o.dish_id "
            "GROUP BY c.category_name ORDER BY revenue DESC"
        );
        
        cout << "Revenue by category:" << endl;
        for (const auto& row : res) {
            cout << "Category: " << row[0].as<string>() 
                 << ", Revenue: " << row[1].as<double>() << endl;
        }
        log("Executed revenue by category query");
    } catch (const exception& e) {
        cerr << "Error calculating revenue by category: " << e.what() << endl;
    }
}

void topSellingDishes(Database& db) {
    try {
        pqxx::work txn(db.conn);
        pqxx::result res = txn.exec(
            "SELECT d.name, COALESCE(SUM(o.quantity), 0) as total_quantity "
            "FROM dishes d "
            "LEFT JOIN orders o ON d.id = o.dish_id "
            "GROUP BY d.name ORDER BY total_quantity DESC LIMIT 3"
        );
        
        cout << "Top 3 selling dishes:" << endl;
        for (const auto& row : res) {
            cout << "Dish: " << row[0].as<string>() 
                 << ", Quantity sold: " << row[1].as<int>() << endl;
        }
        log("Executed top selling dishes query");
    } catch (const exception& e) {
        cerr << "Error getting top selling dishes: " << e.what() << endl;
    }
}

void averageOrderValue(Database& db) {
    try {
        pqxx::work txn(db.conn);
        pqxx::result res = txn.exec("SELECT COALESCE(AVG(total_price), 0) FROM orders");
        
        double avg = res[0][0].as<double>();
        cout << "Average order value: " << fixed << setprecision(2) << avg << endl;
        log("Executed average order value query");
    } catch (const exception& e) {
        cerr << "Error calculating average order value: " << e.what() << endl;
    }
}

void ordersPerDish(Database& db) {
    try {
        pqxx::work txn(db.conn);
        pqxx::result res = txn.exec(
            "SELECT d.name, COALESCE(COUNT(o.order_id), 0) as order_count "
            "FROM dishes d "
            "LEFT JOIN orders o ON d.id = o.dish_id "
            "GROUP BY d.name ORDER BY order_count DESC"
        );
        
        cout << "Orders per dish:" << endl;
        for (const auto& row : res) {
            cout << "Dish: " << row[0].as<string>() 
                 << ", Orders: " << row[1].as<int>() << endl;
        }
        log("Executed orders per dish query");
    } catch (const exception& e) {
        cerr << "Error counting orders per dish: " << e.what() << endl;
    }
}

int main() {
    try {
        Database db;
        Category category(db);
        MainCourse mainCourse(db);
        Dessert dessert(db);
        Order order(db);

        cout << "Restaurant Management System" << endl;
        cout << "Connected to database successfully!" << endl;

        int choice;
        do {
            cout << "\nMenu:" << endl;
            cout << "1. Add category" << endl;
            cout << "2. Add dish" << endl;
            cout << "3. Add order" << endl;
            cout << "4. View all dishes" << endl;
            cout << "5. View all orders" << endl;
            cout << "6. Revenue by category" << endl;
            cout << "7. Top 3 selling dishes" << endl;
            cout << "8. Average order value" << endl;
            cout << "9. Orders per dish" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                string name;
                cout << "Category name: ";
                getline(cin, name);
                category.add(name);
            } else if (choice == 2) {
                string name;
                int cat_id;
                double price;
                cout << "Dish name: ";
                getline(cin, name);
                cout << "Category ID: ";
                cin >> cat_id;
                cout << "Price: ";
                cin >> price;
                mainCourse.add(name, cat_id, price);
            } else if (choice == 3) {
                int dish_id, quantity;
                string date;
                cout << "Dish ID: ";
                cin >> dish_id;
                cout << "Order date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Quantity: ";
                cin >> quantity;
                order.add(dish_id, date, quantity);
            } else if (choice == 4) viewDishes(db);
            else if (choice == 5) viewOrders(db);
            else if (choice == 6) revenueByCategory(db);
            else if (choice == 7) topSellingDishes(db);
            else if (choice == 8) averageOrderValue(db);
            else if (choice == 9) ordersPerDish(db);
            else if (choice == 0) cout << "Exiting..." << endl;
            else cout << "Invalid choice. Please try again." << endl;
        } while (choice != 0);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}