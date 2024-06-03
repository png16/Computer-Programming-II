#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Product {
	protected:
	    string name;
	    string brand;
	    double price;
	    int quantity;
	    string description;
	    string size;
	    string color;
	    string category;

	public:
	    // Constructors for Product Class
	    Product(const string &name, const string &brand, double price, int quantity,
	            const string &description, const string &size, const string &color, const string &category);
	
	    // Getters
	    string getName() const;
	    string getBrand() const;
	    double getPrice() const;
	    int getQuantity() const;
	    string getDescription() const;
	    string getSize() const;
	    string getColor() const;
	    string getCategory() const;
	
	    // Setters
	    void setName(const string &name);
	    void setBrand(const string &brand);
	    void setPrice(double price);
	    void setQuantity(int quantity);
	    void setDescription(const string &description);
	    void setSize(const string &size);
	    void setColor(const string &color);
	    void setCategory(const string &category);
	
	    // Virtual method to print product details
	    virtual void printDetails() const;
};

class Clothing : public Product {
	private:
	    string material;
	
	public:
	    // Constructor
	    Clothing(const string &name, const string &brand, double price, int quantity,
	             const string &description, const string &size, const string &color, const string &category,
	             const string &material);
	
	    // Getter
	    string getMaterial() const;
	
	    // Setter
	    void setMaterial(const string &material);
	
	    // Override method to print details
	    void printDetails() const override;
	};

class Electronics : public Product {
	private:
	    string model;
	    int warranty;
	    string techSpecifications;
	
	public:
	    // Constructors for Electronics class
	    Electronics(const string &name, const string &brand, double price, int quantity,
	                const string &description, const string &size, const string &color, const string &category,
	                const string &model, int warranty, const string &techSpecifications);
	
	    // Getters
	    string getModel() const;
	    int getWarranty() const;
	    string getTechSpecifications() const;
	
	    // Setters
	    void setModel(const string &model);
	    void setWarranty(int warranty);
	    void setTechSpecifications(const string &techSpecifications);
	
	    // Override method to print details
	    void printDetails() const override;
};

// Product class implementation
Product::Product(const string &name, const string &brand, double price, int quantity,
                 const string &description, const string &size, const string &color, const string &category)
    : name(name), brand(brand), price(price), quantity(quantity), description(description), size(size), color(color), category(category) {}

	// Getters
	string Product::getName() const {
		return name; 
	}
	string Product::getBrand() const {
		return brand; 
	}
	double Product::getPrice() const { 
		return price; 
	}
	int Product::getQuantity() const {
		return quantity; 
	}
	string Product::getDescription() const {
		return description; 
	}
	string Product::getSize() const {
		return size; 
	}
	string Product::getColor() const { 
		return color;
	}
	string Product::getCategory() const {
		return category;
	}
	
	// Setters
	void Product::setName(const string &name) {
		this->name = name; 
	}
	void Product::setBrand(const string &brand) { 
		this->brand = brand; 
	}
	void Product::setPrice(double price) { 
		this->price = price; 
	}
	void Product::setQuantity(int quantity) { 
		this->quantity = quantity; 
	}
	void Product::setDescription(const string &description) { 
		this->description = description; 
	}
	void Product::setSize(const string &size) { 
		this->size = size; 
	}
	void Product::setColor(const string &color) { 
		this->color = color; 
	}
	void Product::setCategory(const string &category) { 
		this->category = category; 
	}
	
	// Print details method
	void Product::printDetails() const {
	    cout << "\tName: " << name << "\n"
	         << "\tBrand: " << brand << "\n"
	         << "\tPrice: Php" << price << "\n"
	         << "\tQuantity: " << quantity << "\n"
	         << "\tDescription: " << description << "\n"
	         << "\tSize: " << size << "\n"
	         << "\tColor: " << color << "\n"
	         << "\tCategory: " << category << "\n";
	}

// Clothing class implementation
Clothing::Clothing(const string &name, const string &brand, double price, int quantity,
                   const string &description, const string &size, const string &color, const string &category,
                   const string &material)
    : Product(name, brand, price, quantity, description, size, color, category), material(material) {}

	// Getter
	string Clothing::getMaterial() const {
		return material; 
	}
	
	// Setter
	void Clothing::setMaterial(const string &material) {
		this->material = material; 
	}
	
	// Override print details method
	void Clothing::printDetails() const {
	    Product::printDetails();
	    cout << "\tMaterial: " << material << "\n";
	}

// Electronics class implementation
Electronics::Electronics(const string &name, const string &brand, double price, int quantity,
                         const string &description, const string &size, const string &color, const string &category,
                         const string &model, int warranty, const string &techSpecifications)
    : Product(name, brand, price, quantity, description, size, color, category), model(model), warranty(warranty), techSpecifications(techSpecifications) {}

	// Getters
	string Electronics::getModel() const {
		return model; 
	}
	int Electronics::getWarranty() const {
		return warranty; 
	}
	string Electronics::getTechSpecifications() const { 
		return techSpecifications;
	}
	
	// Setters
	void Electronics::setModel(const string &model) { 
		this->model = model; 
	}
	void Electronics::setWarranty(int warranty) { 
		this->warranty = warranty; 
	}
	void Electronics::setTechSpecifications(const string &techSpecifications) { 
		this->techSpecifications = techSpecifications; 
	}
	
	// Override print details method
	void Electronics::printDetails() const {
	    Product::printDetails();
	    cout << "\tModel: " << model << "\n"
	         << "\tWarranty: " << warranty << " months\n"
	         << "\tTechnical Specifications: " << techSpecifications << "\n";
	}
