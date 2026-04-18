#pragma once
#ifndef WAGON_H_
#define WAGON_H_

class Wagon {
public:
    void init(int seats, double ticketPrice);
    void read();
    void display();
    double expectedRevenue();
    int getSeats();
    double getTicketPrice();

private:
    int seats;
    double ticketPrice;
};

#endif