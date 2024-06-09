
//this bus reservation system designed  and created by furkan askin with c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a bus
struct Bus {
string busNumber;
int totalSeats;
int availableSeats;
};

// Function to display available buses
void displayBuses(const vector<Bus>& buses) {
cout << "Available Buses:\n";
cout << "-----------------\n";
cout << "Bus Number\tTotal Seats\tAvailable Seats\n";
for (const auto& bus : buses) {
    cout << bus.busNumber << "\t\t" << bus.totalSeats << "\t\t" << bus.availableSeats << endl;
}
cout << "-----------------\n";
}

// Function to book tickets
void bookTicket(vector<Bus>& buses, const string& busNumber, int numTickets) {
for (auto& bus : buses) {
    if (bus.busNumber == busNumber) {
        if (bus.availableSeats >= numTickets) {
            bus.availableSeats -= numTickets;
            cout << numTickets << " tickets booked successfully for bus " << busNumber << endl;
        } else {
            cout << "Sorry, insufficient seats available for booking" << endl;
        }
        return;
    }
}
cout << "Bus with number " << busNumber << " not found" << endl;
  }

// Function to cancel tickets
void cancelTicket(vector<Bus>& buses, const string& busNumber, int numTickets) {
for (auto& bus : buses) {
    if (bus.busNumber == busNumber) {
        bus.availableSeats += numTickets;
        cout << numTickets << " tickets cancelled successfully for bus " << busNumber << endl;
        return;
    }
}
cout << "Bus with number " << busNumber << " not found" << endl;
}

int main() {
vector<Bus> buses = {{"B001", 50, 50}, {"B002", 40, 20}, {"B003", 30, 30}}; // Sample buses

while (true) {
    cout << "\nWelcome to Bus Reservation System\n";
    cout << "1. Display Available Buses\n";
    cout << "2. Book Tickets\n";
    cout << "3. Cancel Tickets\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            displayBuses(buses);
            break;
        case 2:
        {
            string busNumber;
            int numTickets;
            cout << "Enter bus number: ";
            cin >> busNumber;
            cout << "Enter number of tickets to book: ";
            cin >> numTickets;
            bookTicket(buses, busNumber, numTickets);
        }
            break;
        case 3:
        {
            string busNumber;
            int numTickets;
            cout << "Enter bus number: ";
            cin >> busNumber;
            cout << "Enter number of tickets to cancel: ";
            cin >> numTickets;
            cancelTicket(buses, busNumber, numTickets);
        }
            break;
        case 4:
            cout << "Thank you for using the Bus Reservation System. Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

return 0;
  }