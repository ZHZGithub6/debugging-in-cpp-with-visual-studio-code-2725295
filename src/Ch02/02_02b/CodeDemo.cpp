// Debugging in C++ with Visual Studio Code
// Exercise 02_02
// Printing Variable Values, by Eduardo Corpeño

#include <iostream>
using namespace std;
class Battery{
private:
    double charge;
    double normalDrain;
    double lowPowerDrain;

public:
    Battery(double capacity, double normalDrain, double lowPowerDrain)
    : charge(capacity), normalDrain(lowPowerDrain), lowPowerDrain(lowPowerDrain) {}

    void simulateUsage(int hours){
        for(int i = 1; i <= hours; i++){
            cout<<charge<<'%'<<endl;
            if(charge > 20){
                cout<<"normalDrain";
                charge -= normalDrain; } // Normal power usage
            else{
                cout<<"lowPowerDrain";
                charge -= lowPowerDrain; // Reduced drain in power-saving mode
            }

            if(charge < 0) charge = 0; // Prevent negative charge
        }
    }

    double getCharge() const { return charge; }
};

int main(){
    double batteryCapacity = 100.0; // 100% battery
    double normalDrain = 5.0;       // Normal power usage (5% per hour)
    double lowPowerDrain = 2.0;     // Power-saving mode (2% per hour)
    int hours = 24;                 // Simulate 24 hours of usage

    Battery myBattery(batteryCapacity, normalDrain, lowPowerDrain);
    myBattery.simulateUsage(hours);

    cout << "Battery charge after " << hours << " hours: "
              << myBattery.getCharge() << "%" << endl;

    cout << endl <<endl;
    return 0;
}
