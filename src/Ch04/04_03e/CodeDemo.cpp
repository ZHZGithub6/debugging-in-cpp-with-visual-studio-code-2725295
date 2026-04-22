// Debugging in C++ with Visual Studio Code
// Exercise 04_03 with modifications
// Linker Errors, by Eduardo Corpeño

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "globals.h"

// Linker error: redefined variable (globalDiscount is already defined in globals.h)
// double globalDiscount = 5.0;

// Linker error: external function declared but not defined anywhere
void externalPromotion();

// Computes the total bill by adding tip and subtracting a discount.
double computeTotal(double bill, int people, double tipPercentage){
    double tipAmount = bill * (tipPercentage / 100);
    double discount = globalDiscount; // Flat discount applied to the bill.
    return std::round((bill + tipAmount - discount) * 100.0) / 100.0;
}

// Semantic error: Function declared to return int but returns a string literal.
std::string getBonusOffer(){
    return "20% off on your next visit."; // Wrong return type.
}

// Print a message when the split is not even
void printUnevenSplit(double totalBill, double perPerson, int numPeople){
    int diff = std::round(((perPerson * numPeople) - totalBill) * 100);
    if(diff > 0)
        // Syntax error: missing semicolon after the output statement.
        std::cout << "FYI: We are " << diff << "¢ over." << std::endl;
    if(diff < 0)
        // Syntax error: missing << operator.
        std::cout << "FYI: We are " << -diff << "¢ short." << std::endl;
    std::cout << std::endl;
}

int main(){
    double billAmount, tipPercentage;
    int numPeople;            
    // Semantic error: Declaration of a reference without initialization.
    double &tip = tipPercentage;

    std::cout << "===== Bill Split Calculator =====" << std::endl << std::endl;
    
    std::cout << "Enter bill amount: $";
    std::cin >> billAmount;
    std::cout << "Enter number of people: ";
    std::cin >> numPeople;
    std::cout << "Enter tip percentage: ";
    std::cin >> tip;
    
    // Syntax error: missing opening curly brace for the if statement's true branch.
    if(numPeople > 2)
        std::cout << std::endl << "Group discounts may apply!" << std::endl;
    // } // Erroneous extra closing curly brace
    
    // Semantic error: Declaration with auto without an initializer.
    // auto totalBill;
    auto totalBill = computeTotal(billAmount, numPeople, tip);
    double perPerson = std::round((totalBill / numPeople) * 100.0) / 100.0;

    std::cout << std::endl << "Grand Total: $" << totalBill << std::endl;
    
    // Semantic error: Use of an undefined variable.
    std::cout << "Each person should pay: $" << std::fixed 
              << std::setprecision(2) << perPerson << std::endl;
    
    // Semantic error: Wrong number of arguments (3 expected but only 2 are provided).
    printUnevenSplit(totalBill, perPerson, numPeople);

    // Logical error: bonus should be a string
    std::string bonus = getBonusOffer();
    std::cout << "Bonus offer: " << bonus << std::endl;
    
    // Linker error: Call to an external function that is declared but not defined.
    externalPromotion();
    
    std::cout << std::endl << std::endl;
    
    return 0;
}
