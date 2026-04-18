#include <iostream>
#include "wagon.h"

void Wagon::init(int seats, double ticketPrice) {
    this->seats = seats;
    this->ticketPrice = ticketPrice;
}

void Wagon::read() {
    std::cout << "Enter number of seats: ";
    std::cin >> seats;
    std::cout << "Enter ticket price: ";
    std::cin >> ticketPrice;
}

void Wagon::display() {
    std::cout << "Wagon: " << seats << " seats, ticket price: "
        << ticketPrice << ", expected revenue: " << expectedRevenue() << std::endl;
}

double Wagon::expectedRevenue() {
    return seats * ticketPrice;
}

int Wagon::getSeats() {
    return seats;
}

double Wagon::getTicketPrice() {
    return ticketPrice;
}