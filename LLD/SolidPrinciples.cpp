/* The SOLID principles are a set of design principles in object-oriented programming that help developers create flexible, maintainable, and scalable software. Shreyanh’s playlist on SOLID principles likely covers these principles in detail. Here’s a summary of each principle:

1. Single Responsibility Principle (SRP)
Definition: A class should have only one reason to change, meaning it should have only one job or responsibility.
Example: A class User that handles user data should not also handle user authentication. Instead, create separate classes for data handling and authentication.
2. Open/Closed Principle (OCP)
Definition: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
Example: Instead of modifying a class to add new features, create new classes that extend the existing class.
3. Liskov Substitution Principle (LSP)
Definition: Subtypes must be substitutable for their base types without altering the correctness of the program.
Example: If class Bird has a method fly(), then any subclass such as Sparrow or Eagle should implement fly() in a way that does not break the functionality expected of a Bird.
4. Interface Segregation Principle (ISP)
Definition: A client should not be forced to depend on interfaces it does not use. It's better to have many specific interfaces rather than one general-purpose interface.
Example: Instead of having a single Animal interface with methods run(), fly(), and swim(), create separate interfaces for Runnable, Flyable, and Swimmable.
5. Dependency Inversion Principle (DIP)
Definition: High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions.
Example: Instead of a class Database that directly depends on a class SQLDatabase, the Database class should depend on an interface IDatabase that SQLDatabase implements.
Summary with Example in Code:
 */

// Example in C++:

// SRP: Separate responsibilities into different classes
class User
{
    // Handles user data
};

class AuthService
{
    // Handles user authentication
};

// OCP: Extend functionality without modifying existing code
class Shape
{
public:
    virtual double area() const = 0;
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
};

// LSP: Subclasses can be used in place of base class without affecting functionality
void printArea(const Shape &shape)
{
    std::cout << "Area: " << shape.area() << std::endl;
}

// ISP: Segregate interfaces to be more specific
class Runnable
{
public:
    virtual void run() = 0;
};

class Flyable
{
public:
    virtual void fly() = 0;
};

class Bird : public Runnable, public Flyable
{
public:
    void run() override
    {
        std::cout << "Bird running" << std::endl;
    }
    void fly() override
    {
        std::cout << "Bird flying" << std::endl;
    }
};

// DIP: Depend on abstractions rather than concrete implementations
class IDatabase
{
public:
    virtual void connect() = 0;
};

class SQLDatabase : public IDatabase
{
public:
    void connect() override
    {
        // SQL connection code
    }
};

class Database
{
    IDatabase *db;

public:
    Database(IDatabase *database) : db(database) {}
    void connectToDatabase()
    {
        db->connect();
    }
};
