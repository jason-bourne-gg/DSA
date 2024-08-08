// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>

// abstarct class / interface
class EMIstrategy
{
    virtual double calculateEMI(Loan &loan) const return = 0;
    virtual double calculateEMI(Loan &loan) const return = 0;
};

class NoCostStrategy : public EMIstrategy
{
public:
    double calculateEMI(Loan &loan)
    {
        double loanAmount = loan.getLoanAmount();
        int tenure = loan.getTenure();

        int totalInstallments = tenure * 12; // monthly

        double emi = (loanAmount / totalInstallments)

            return emi;
    }

    double calculateTotalInterestPaid(Loan &loan)
    {
        return 0.0; // interest is 0 on such loans
    }
};

class NormalStrategy : public EMIstrategy
{
public:
    double calculateEMI(Loan &loan)
    {
        double loanAmount = loan.getLoanAmount();
        double interestRate = loan.getInterestRate();
        int tenure = loan.getTenure();

        double monthlyInterestRate = interestRate / (12 * 100); // monthlyInterst rate
        int totalInstallments = tenure * 12;                    // monthly

        double emi = (loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, totalInstallments)) / (pow(1 + monthlyInterestRate, totalInstallments) - 1);

        return emi;
    }

    double calculateTotalInterestPaid(Loan &loan)
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

class EMICalculator
{
private:
    EMIstrategy *emistrategy;

public:
    EMICalculator(EMIstrategy *emistrategy) : emistrategy(emistrategy) {}

    double calculateEMI(Loan &loan)
    {
        return emistrategy.calculateEMI(loan);
    }

    double calculateTotalInterestPaid(Loan &loan)
    {
        return emistrategy.calculateTotalInterestPaid(loan);
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
    if (strategy == 1)
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
    double interestPaid = calculator.calculateTotalInterestPaid(loan);

    // Output results
    cout << "Monthly EMI: " << emi << endl;
    cout << "Total Interest Payable: " << interestPaid << endl;

    return 0;
}