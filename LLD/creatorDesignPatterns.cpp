/*
Certainly !Below are the notes and comments on each of the creational design pattern examples, explaining how the patterns solve specific problems.
1. Singleton
Ensures a class has only one instance and provides a global point of access to it.
This is useful when exactly one object is needed to coordinate actions across the system.
 */

class Singleton
{
private:
    static Singleton *instance; // Static variable to hold the single instance

    Singleton() {} // Private constructor to prevent direct instantiation

public:
    static Singleton *getInstance()
    { // Public method to provide access to the instance
        if (!instance)
            instance = new Singleton(); // Create the instance if it doesn't exist
        return instance;                // Return the instance
    }
};

// Initialize static member
Singleton *Singleton::instance = nullptr;
/* Notes:

The constructor is private, preventing direct instantiation.
The getInstance method ensures that only one instance of the class is created.
This pattern is useful in scenarios such as logging, configuration management, and device driver management where a single instance is sufficient.
2. Factory Method
Defines an interface for creating an object but allows subclasses to alter the type of objects that will be created. This pattern is useful for creating objects without specifying the exact class of object that will be created.
 */

class Product
{
public:
    virtual void use() = 0; // Pure virtual method to be implemented by derived classes
};

class ConcreteProductA : public Product
{
public:
    void use() override
    {
        std::cout << "Using Product A" << std::endl; // Implementation of use method
    }
};

class ConcreteProductB : public Product
{
public:
    void use() override
    {
        std::cout << "Using Product B" << std::endl; // Implementation of use method
    }
};

class Creator
{
public:
    virtual Product *createProduct() = 0; // Pure virtual method to create product
};

class ConcreteCreatorA : public Creator
{
public:
    Product *createProduct() override
    {
        return new ConcreteProductA(); // Creates a ConcreteProductA
    }
};

class ConcreteCreatorB : public Creator
{
public:
    Product *createProduct() override
    {
        return new ConcreteProductB(); // Creates a ConcreteProductB
    }
};
/* Notes:

The Creator class declares the factory method that returns an object of type Product.
Subclasses (ConcreteCreatorA and ConcreteCreatorB) implement the factory method to create specific product objects.
This pattern allows the client code to be decoupled from the specific types of products it needs to create.
3. Abstract Factory
Provides an interface for creating families of related or dependent objects without specifying their concrete classes. Useful when the system needs to be independent of how its objects are created.
 */
class AbstractProductA
{
public:
    virtual void use() = 0; // Pure virtual method to be implemented by derived classes
};

class AbstractProductB
{
public:
    virtual void use() = 0; // Pure virtual method to be implemented by derived classes
};

class ConcreteProductA1 : public AbstractProductA
{
public:
    void use() override
    {
        std::cout << "Using Product A1" << std::endl; // Implementation of use method
    }
};

class ConcreteProductA2 : public AbstractProductA
{
public:
    void use() override
    {
        std::cout << "Using Product A2" << std::endl; // Implementation of use method
    }
};

class ConcreteProductB1 : public AbstractProductB
{
public:
    void use() override
    {
        std::cout << "Using Product B1" << std::endl; // Implementation of use method
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    void use() override
    {
        std::cout << "Using Product B2" << std::endl; // Implementation of use method
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA *createProductA() = 0; // Factory method to create ProductA
    virtual AbstractProductB *createProductB() = 0; // Factory method to create ProductB
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() override
    {
        return new ConcreteProductA1(); // Creates a ConcreteProductA1
    }

    AbstractProductB *createProductB() override
    {
        return new ConcreteProductB1(); // Creates a ConcreteProductB1
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() override
    {
        return new ConcreteProductA2(); // Creates a ConcreteProductA2
    }

    AbstractProductB *createProductB() override
    {
        return new ConcreteProductB2(); // Creates a ConcreteProductB2
    }
};
/* Notes:

The AbstractFactory class declares the factory methods for creating products.
Concrete factories (ConcreteFactory1 and ConcreteFactory2) implement these methods to create specific combinations of products.
This pattern is useful for ensuring that related products are used together and for decoupling the client code from specific product classes.
4. Builder
Separates the construction of a complex object from its representation, allowing the same construction process to create different representations.

 */
class Product
{
public:
    void setPartA(const std::string &part)
    {
        partA = part; // Set partA
    }

    void setPartB(const std::string &part)
    {
        partB = part; // Set partB
    }

    void showProduct()
    {
        std::cout << "Product Parts: " << partA << ", " << partB << std::endl; // Display parts
    }

private:
    std::string partA; // PartA of the product
    std::string partB; // PartB of the product
};

class Builder
{
public:
    virtual void buildPartA() = 0;    // Pure virtual method to build PartA
    virtual void buildPartB() = 0;    // Pure virtual method to build PartB
    virtual Product *getResult() = 0; // Pure virtual method to get the final product
};

class ConcreteBuilder : public Builder
{
public:
    ConcreteBuilder()
    {
        product = new Product(); // Initialize product
    }

    void buildPartA() override
    {
        product->setPartA("PartA"); // Build PartA
    }

    void buildPartB() override
    {
        product->setPartB("PartB"); // Build PartB
    }

    Product *getResult() override
    {
        return product; // Return the final product
    }

private:
    Product *product; // The product being built
};

class Director
{
public:
    void setBuilder(Builder *b)
    {
        builder = b; // Set the builder
    }

    void construct()
    {
        builder->buildPartA(); // Construct PartA
        builder->buildPartB(); // Construct PartB
    }

private:
    Builder *builder; // The builder used for construction
};
/* Notes:

The Builder class defines the methods to create parts of a Product.
The ConcreteBuilder class implements these methods to construct specific parts.
The Director class uses a Builder object to construct the product step by step.
This pattern is useful for constructing complex objects step by step and for creating different representations of an object using the same construction process.
5. Prototype
Specifies the kinds of objects to create using a prototypical instance and creates new objects by copying this prototype. This pattern is useful when the cost of creating a new object is high and there are already existing objects that can be cloned.
 */

class Prototype
{
public:
    virtual Prototype *clone() const = 0; // Pure virtual method to clone the object
    virtual void use() = 0;               // Pure virtual method to use the object
};

class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1(int value) : value(value) {} // Constructor with a value

    Prototype *clone() const override
    {
        return new ConcretePrototype1(*this); // Clone the object
    }

    void use() override
    {
        std::cout << "Using Prototype1 with value " << value << std::endl; // Use the object
    }

private:
    int value; // Value of the prototype
};

class ConcretePrototype2 : public Prototype
{
public:
    ConcretePrototype2(int value) : value(value) {} // Constructor with a value

    Prototype *clone() const override
    {
        return new ConcretePrototype2(*this); // Clone the object
    }

    void use() override
    {
        std::cout << "Using Prototype2 with value " << value << std::endl; // Use the object
    }

private:
    int value; // Value of the prototype
};

/* The Prototype class defines a method for cloning itself.
Concrete prototypes (ConcretePrototype1 and ConcretePrototype2) implement the clone method to return a copy of themselves.
This pattern is useful when creating an object is resource-intensive and when there are existing objects that can be copied to create new instances. */