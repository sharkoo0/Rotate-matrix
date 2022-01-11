#include <iostream>
#include "PGM.h"
#include "PGMhelper.h"

void printMenu() {
    std::cout << "Choose one of the options and type its number.\n";
    std::cout << "1. Print the image\n";
    std::cout << "2. Rotate the image -90 degrees\n";
    std::cout << "3. Rotate the image 90 degrees\n";
    std::cout << "4. Rotate the image 180 degrees\n";
    std::cout << "5. Exit\n";
}

int main() {
    std::string fileName;
    std::cout << "Enter file name: ";
    std::cin >> fileName;
    PGM pgm (fileName);
    pgm.print();
    int choice;
    PGMhelper helper;
    while (true) {
        printMenu();
        std::cout << "Enter your choice(1, 2, 3, 4): ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            pgm.print();
            break;
        case 2:
            pgm.print();
            helper.rotate(pgm, -90);
            pgm.print();
            break;
        case 3:
            pgm.print();
            helper.rotate(pgm, 90);
            pgm.print();
            break;
        case 4:
            pgm.print();
            helper.rotate(pgm, 180);
            pgm.print();
            break;
        default:
            return 0;
        }
    }
    // PGMhelper helper;
    // helper.rotate(pgm, -90);
    // pgm.print();
    // helper.rotate(pgm, 90);
    // pgm.print();
    // helper.rotate(pgm, 180);
    // pgm.print();
    // helper.rotate(pgm, 90);
    // pgm.print();
    // helper.rotate(pgm, 180);
    // pgm.print();
    
}