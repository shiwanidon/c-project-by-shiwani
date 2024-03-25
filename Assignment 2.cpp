#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 60
#define MAX_NAME_LENGTH 40

struct Ticket {
    int seat_number;
    char passenger_name[MAX_NAME_LENGTH];
    int booked;
};

void initialize_tickets(struct Ticket tickets[]);
void bus(struct Ticket tickets[]);
void booking(struct Ticket tickets[]);
void cancel(struct Ticket tickets[]);
void modify(struct Ticket tickets[]);
void status(struct Ticket tickets[]);

int main() {
    struct Ticket tickets[MAX_SEATS];
    initialize_tickets(tickets);
    int your_choice;
    char ch;
    do {
        bus(tickets);
        printf("\nPLEASE ENTER YOUR CHOICE:");
        scanf("%d", &your_choice);
        switch (your_choice) {
            case 1:
                booking(tickets);
                break;
            case 2:
                cancel(tickets);
                break;
            case 3:
                modify(tickets);
                break;
            case 4:
                status(tickets);
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Do you want to continue (y/n)?: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}

void initialize_tickets(struct Ticket tickets[]) {
    for (int i = 0; i < MAX_SEATS; i++) {
        tickets[i].seat_number = i + 1;
        strcpy(tickets[i].passenger_name, "Available");
        tickets[i].booked = 0;
    }
}

void bus(struct Ticket tickets[]) {
    printf("\n======== Welcome to the Bus Reservation System ========\nWhat do you want to do?");
    printf("\n1. Book a ticket\n");
    printf("2. Cancel your ticket\n");
    printf("3. Modify your booking\n");
    printf("4. View booking status\n");
    printf("5. Exit\n");
    printf("========================================================\n");
}

void booking(struct Ticket tickets[]) {
    int seat_num;
    printf("Enter the seat number you want to book: ");
    scanf("%d", &seat_num);
    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (tickets[seat_num - 1].booked) {
        printf("Seat already booked.\n");
        return;
    }
    printf("Enter passenger name: ");
    scanf("%s", tickets[seat_num - 1].passenger_name);
    tickets[seat_num - 1].booked = 1;
    printf("Booking successful.\n");
}

void cancel(struct Ticket tickets[]) {
    int seat_num;
    printf("Enter the seat number to cancel booking: ");
    scanf("%d", &seat_num);
    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (!tickets[seat_num - 1].booked) {
        printf("Seat not booked.\n");
        return;
    }
    strcpy(tickets[seat_num - 1].passenger_name, "Available");
    tickets[seat_num - 1].booked = 0;
    printf("Booking canceled.\n");
}

void modify(struct Ticket tickets[]) {
    int seat_num;
    printf("Enter the seat number to modify booking: ");
    scanf("%d", &seat_num);
    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (!tickets[seat_num - 1].booked) {
        printf("Seat not booked.\n");
        return;
    }
    printf("Enter new passenger name: ");
    scanf("%s", tickets[seat_num - 1].passenger_name);
    printf("Booking modified.\n");
}

void status(struct Ticket tickets[]) {
    int seat_num;
    printf("Enter the seat number to view status: ");
    scanf("%d", &seat_num);
    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (!tickets[seat_num - 1].booked) {
        printf("Seat not booked.\n");
        return;
    }
    printf("Seat Number: %d\n", tickets[seat_num - 1].seat_number);
    printf("Passenger Name: %s\n", tickets[seat_num - 1].passenger_name);
}
