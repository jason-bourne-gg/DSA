// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>

class Loan
{
private:
    double loanAmount;
    double interestRate;
    int tenure;

public:
    Loan(double loanAmount, double interestRate, int tenure) : loanAmount(loanAmount), interestRate(interestRate), tenure(tenure) {}

    double getLoanAmount() { return loanAmount; }
    double getInterestRate() { return interestRate; }
    double getTenure() { return tenure; }
};

// abstarct class / interface
class EMIstrategy
{
public:
    virtual double calculateEMI(Loan &loan) const = 0;
    virtual double calculateTotalInterestPaid(Loan &loan) const = 0;
};

class NoCostStrategy : public EMIstrategy
{
public:
    double calculateEMI(Loan &loan) const override
    {
        double loanAmount = loan.getLoanAmount();
        int tenure = loan.getTenure();

        int totalInstallments = tenure * 12; // monthly

        double emi = (loanAmount / totalInstallments);

        return emi;
    }

    double calculateTotalInterestPaid(Loan &loan) const override
    {
        return 0.0; // interest is 0 on such loans
    }
};

class NormalStrategy : public EMIstrategy
{
public:
    double calculateEMI(Loan &loan) const override
    {
        double loanAmount = loan.getLoanAmount();
        double interestRate = loan.getInterestRate();
        int tenure = loan.getTenure();

        double monthlyInterestRate = interestRate / (12 * 100); // monthlyInterst rate
        int totalInstallments = tenure * 12;                    // monthly

        double emi = (loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, totalInstallments)) / (pow(1 + monthlyInterestRate, totalInstallments) - 1);

        return emi;
    }

    double calculateTotalInterestPaid(Loan &loan) const override
    {
        double loanAmount = loan.getLoanAmount();
        double interestRate = loan.getInterestRate();
        int tenure = loan.getTenure();

        double emi = calculateEMI(loan);
        int totalInstallments = tenure * 12; // monthly

        double totalAmountPaid = emi * totalInstallments;

        return totalAmountPaid - loanAmount;
    }
};

class EMICalculator
{
private:
    EMIstrategy *emistrategy;

public:
    EMICalculator(EMIstrategy *emistrategy) : emistrategy(emistrategy) {}

    double calculateEMI(Loan &loan)
    {
        return emistrategy->calculateEMI(loan);
    }

    double calculateTotalInterestPaid(Loan &loan)
    {
        return emistrategy->calculateTotalInterestPaid(loan);
    }
};

int main()
{
    double loanAmount, interestRate;
    int tenure, strategy;

    cout << "Enter the loan amount" << endl;
    cin >> loanAmount;
    cout << "Enter the interest rate" << endl;
    cin >> interestRate;
    cout << "Enter the tenure in years" << endl;
    cin >> tenure;

    cout << "enter 1 for no cost emi, 2 for normal emi" << endl;
    cin >> strategy;

    Loan loan(loanAmount, interestRate, tenure);

    EMICalculator *calculator;
    if (strategy == 2)
    {
        NormalStrategy normalStrategy;
        calculator = new EMICalculator(&normalStrategy);
    }
    else
    {
        NoCostStrategy noCostStrategy;
        calculator = new EMICalculator(&noCostStrategy);
    }

    double emi = calculator->calculateEMI(loan);
    double interestPaid = calculator->calculateTotalInterestPaid(loan);

    // Output results
    cout << "Monthly EMI: " << emi << endl;
    cout << "Total Interest Payable: " << interestPaid << endl;

    return 0;
}

/* Yes, your implementation follows a few design patterns. Here's an explanation of the patterns used:

Strategy Pattern:

The Strategy Pattern is used to define a family of algorithms, encapsulate each one, and make them interchangeable. The pattern lets the algorithm vary independently from clients that use it.
In your code, EMIstrategy is the strategy interface that defines the methods calculateEMI and calculateTotalInterestPaid. NoCostStrategy and NormalStrategy are concrete implementations of this strategy. The EMICalculator class uses a strategy object to perform the EMI calculation, making it easy to switch between different EMI calculation strategies.
Abstract Factory Pattern (a variant):

While not a full implementation of the Abstract Factory Pattern, your code shows a simplified version where the type of EMI calculation strategy (factory) is selected at runtime.
Depending on the user's choice, either a NoCostStrategy or a NormalStrategy object is created and passed to the EMICalculator.
Single Responsibility Principle (SRP):

This principle states that a class should have only one reason to change, meaning it should only have one job or responsibility.
The Loan class is responsible for storing loan details. The EMIstrategy interface and its implementations are responsible for EMI calculation logic. The EMICalculator class is responsible for using a strategy to perform the EMI calculations. This separation of responsibilities adheres to the SRP.
Open/Closed Principle (OCP):

This principle states that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
In your code, the EMIstrategy interface can be extended to add new EMI calculation strategies without modifying the existing code. For example, you can add a new strategy by creating a new class that implements the EMIstrategy interface.
Dependency Injection:

This is a design pattern where an object receives other objects that it depends on. These other objects are called dependencies.
In your code, the EMICalculator class is injected with an EMIstrategy object via its constructor. This makes EMICalculator independent of which specific strategy it uses and adheres to the Dependency Injection principle.
Here's a brief recap of how these patterns and principles are applied in your code:

Strategy Pattern: EMIstrategy interface and its implementations (NoCostStrategy and NormalStrategy).
Abstract Factory Pattern: Selection of the strategy object based on user input.
Single Responsibility Principle: Separate classes for loan details, EMI calculation strategies, and EMI calculation execution.
Open/Closed Principle: The EMIstrategy interface can be extended without modifying existing code.
Dependency Injection: The EMICalculator class is constructed with an EMIstrategy object.





 */