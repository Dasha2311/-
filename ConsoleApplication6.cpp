#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Оголошення базового класу "Товар"
class Product {
protected:
    string country_code;
    double price;

public:
    Product(string country_code, double price) : country_code(country_code), price(price) {}

    string get_country_code() {
        return country_code;
    }

    double get_price() {
        return price;
    }
};

// Оголошення похідного класу "Іграшка"
class Toy : public Product {
private:
    string name;
    int min_age;
    int max_age;

public:
    Toy(string country_code, double price, string name, int min_age, int max_age) :
        Product(country_code, price), name(name), min_age(min_age), max_age(max_age) {}

    string get_name() {
        return name;
    }

    int get_min_age() {
        return min_age;
    }

    int get_max_age() {
        return max_age;
    }
};

int main() {
    vector<Toy> toys;

    toys.push_back(Toy("US", 19.99, "Lego City", 5, 12));
    toys.push_back(Toy("CN", 12.99, "Transformers", 8, 14));
    toys.push_back(Toy("JP", 29.99, "Hello Kitty", 3, 7));
    toys.push_back(Toy("US", 9.99, "Barbie", 4, 10));
    toys.push_back(Toy("CN", 5.99, "Rubik's Cube", 8, 99));
    toys.push_back(Toy("KR", 24.99, "Pokemon", 6, 14));

    int min_age, max_age;
    double min_price, max_price;

    // Запит користувача на введення вікового діапазону та меж ціни
    cout << "Enter minimum age: ";
    cin >> min_age;
    cout << "Enter maximum age: ";
    cin >> max_age;
    cout << "Enter minimum price: ";
    cin >> min_price;
    cout << "Enter maximum price: ";
    cin >> max_price;

    // Перебір усіх іграшок та вивід тих, які відповідають вказаним критеріям
    for (Toy toy : toys) {
        if (toy.get_min_age() >= min_age && toy.get_max_age() <= max_age &&
            toy.get_price() >= min_price && toy.get_price() <= max_price) {
            cout << toy.get_name() << " (from " << toy.get_country_code() << ") - $" << toy.get_price() << endl;
        }
    }

    return 0;
}
