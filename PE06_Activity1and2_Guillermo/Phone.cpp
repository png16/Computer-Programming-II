#include <iostream>
using namespace std;

class Phone{
    private:
        string Brand;
        double Price;
        string operatingSystem;
    public:
        Phone(string newBrand, double newPrice, string newOS){
            Brand = newBrand;
            Price = newPrice;
            operatingSystem = newOS;
        }

        void view(){
            cout << "Phone Brand is = " << Brand << endl;
            cout << "Phone Price is = Php " << Price << endl;
            cout << "Phone Operating System is = " << operatingSystem << endl;
        }
};

int main(){
    cout << "Activity 1.1\n" << endl;
    Phone p("Xiaomi", 18999, "HyperOS");
    p.view();

    return 0;
}

