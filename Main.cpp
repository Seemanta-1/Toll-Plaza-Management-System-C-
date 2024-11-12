#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int mc = 0, cj = 0, mp = 0, b31 = 0, b32 = 0, trc5 = 0, trc58 = 0, totalVehicles = 0;
int ArrTotalVehicles[100];
int date[100],vehicle, month, year;
float total = 0;
float ArrTotal[100];
int first = 0;

void WriteToFile() {
    ofstream outfile("toll_records.txt", ios::app);
    if (!outfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }
    for (int i = 0; i < first; i++) {
        outfile << "Date: " << date[i] << "-" << month << "-" << year << "\tTotal Vehicles: " << ArrTotalVehicles[i] << "\tTotal Toll: " << ArrTotal[i] << " TAKA" << endl;
    }
    outfile.close();
    cout << "Data has been written to file." << endl;
}

void ReadFromFile() {
    ifstream infile("toll_records.txt");
    if (!infile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}

void Add_day() {
     float motor_cycle = 50.00;
    float low_weight_vehiclesCJ = 550.00;
    float low_weight_vehiclesMP = 600.00;
    float mini_bus31 = 750.00;
    float mini_bus32 = 1000.00;
    float small_truckLT5T = 1000.00;
    float midium_truck58 = 1250.00;

    if (totalVehicles != 0) {
        totalVehicles = 0;
        mc = 0;
        cj = 0;
        mp = 0;
        b31 = 0;
        b32 = 0;
        trc5 = 0;
        trc58 = 0;
    }

    for (int i = first; i < (first + 1); i++) {
        cout << "Please enter the full date" << endl;
        cout << "Date: ";
        cin >> date[i];
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;

        cout << "\n\t\t\t\tTake inputs of " << date[i] << "-" << month << "-" << year << endl;
        cout << "\t...........................\n";
        cout << "\t1-motorcycle\n";
        cout << "\t2-low weight vehicles(car/jeep)\n";
        cout << "\t3-low weight vehicles(micro/pickup)(lower than 1.5 ton)\n";
        cout << "\t4-mini bus(31 seat or less)\n";
        cout << "\t5-big bus(32 seat or more)\n";
        cout << "\t6-small truck(less than 5 ton)\n";
        cout << "\t7-medium truck(5-8 ton)\n";

        cout << "\t...........................";

        do {
            cout << "\nPlease enter the right vehicle number and you can stop taking inputs by pressing 0: ";
            cin >> vehicle;

            switch (vehicle) {
            case 0: {
                cout << "\t\t..............................\n";
                cout << "\t\t\t End of " << date[i] << "-" << month << "-" << year << endl;
                cout << "\t\t..............................\n";
            } break;
            case 1: {
                mc = mc + 1;
                total = total + motor_cycle;
                cout << "\t\t motorcycle, Tk: 50.00 Toll added!" << endl;
            } break;
            case 2: {
                cj = cj + 1;
                total = total + low_weight_vehiclesCJ;
                cout << "\t\t low weight vehicles(car/jeep), Tk: 550.00 Toll added!" << endl;
            } break;
            case 3: {
                mp = mp + 1;
                total = total + low_weight_vehiclesMP;
                cout << "\t\t low weight vehicles(micro/pickup)(lower than 1.5 ton), Tk: 600.00 Toll added!" << endl;
            } break;
            case 4: {
                b31 = b31 + 1;
                total = total + mini_bus31;
                cout << "\t\t mini bus(31 seat or less), Tk: 750.00 Toll added!" << endl;
            } break;
            case 5: {
                b32 = b32 + 1;
                total = total + mini_bus32;
                ArrTotal[i] = ArrTotal[i] + mini_bus32;
                cout << "\t\t big bus(32 seat or more), Tk: 1000.00 Toll added!" << endl;
            } break;
            case 6: {
                trc5 = trc5 + 1;
                total = total + small_truckLT5T;
                cout << "\t\t small truck(less than 5 ton), Tk: 1000.00 Toll added!" << endl;
            } break;
            case 7: {
                trc58 = trc58 + 1;
                total = total + midium_truck58;
                cout << "\t\t medium truck(5-8 ton), Tk: 1250.00 Toll added!" << endl;
            } break;

            default:
                cout << "\t\t Invalid vehicles\n";
            }
        } while (vehicle != 0);

        ArrTotal[i] = total;
        totalVehicles = mc + cj + mp + b31 + b32 + trc5 + trc58;
        ArrTotalVehicles[i] = totalVehicles;
    }
    first = first + 1;
    vehicle = 0;
}

void Today() {
    cout << "\n--------------------\n";
    cout << "Day report\n";
    cout << "\t motorcycle=" << mc << endl;
    cout << "\t low weight vehicles(car/jeep)=" << cj << endl;
    cout << "\t low weight vehicles(micro/pickup)(lower than 1.5 ton)=" << mp << endl;
    cout << "\t mini bus(31 seat or less)=" << b31 << endl;
    cout << "\t big bus(32 seat or more)=" << b32 << endl;
    cout << "\t small truck(less than 5 ton)=" << trc5 << endl;
    cout << "\t medium teruck(5-8 ton)=" << trc58 << endl;

    cout << "\t...........................\n";
    cout << "\t Total Vehicles = " << totalVehicles << endl;
    cout << "\t Total Toll money = " << total << " TAKA" << endl;
}

void History() {
    for (int i = 0; i < first; i++) {
        cout << "\t...........................\n";
        cout << "date: " << date[i];
        cout << "\t Total vehicle passed = " << ArrTotalVehicles[i];
        cout << "\t Total Toll money = " << ArrTotal[i] << " TAKA" << endl;
    }
}

int main() {
    int option;

    for (;;) {
        cout << "\tToll Management System\n";
        cout << "\t...........................\n";
        cout << "\t\tMENU\n";
        cout << "Press 1 to start the day\n";
        cout << "Press 2 for day's report\n";
        cout << "Press 3 for entire history of the month\n";
        cout << "Press 4 to write data to file\n";
        cout << "Press 5 to read data from file\n";
        cout << "Press 0 to exit program\n";
        cout << "\t...........................\n";
        cout << "Please enter your option here: ";
        cin >> option;

        switch (option) {
            case 1:
                Add_day();
                break;
            case 2:
                Today();
                break;
            case 3:
                History();
                break;
            case 4:
                WriteToFile(); // Option to write data to a file
                break;
            case 5:
                ReadFromFile(); // Option to read data from a file
                break;
            case 0:
                exit(0);
            default:
                cout << "\t\t ***********Invalid option*************\n";
                break;
        }
    }
    return 0;
}
