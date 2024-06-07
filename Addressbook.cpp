#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string phoneNumber;
};

void addEntry(std::vector<Contact>& addressBook) {
    Contact newContact;

    std::cout << "Enter first name: ";
    std::cin >> newContact.firstName;

    std::cout << "Enter last name: ";
    std::cin >> newContact.lastName;

    std::cout << "Enter address: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.address);

    std::cout << "Enter phone number: ";
    std::cin >> newContact.phoneNumber;

    addressBook.push_back(newContact);
}

void viewEntries(const std::vector<Contact>& addressBook) {
    for (const auto& contact : addressBook) {
        std::cout << "First Name: " << contact.firstName << "\n"
                  << "Last Name: " << contact.lastName << "\n"
                  << "Address: " << contact.address << "\n"
                  << "Phone Number: " << contact.phoneNumber << "\n\n";
    }
}

void editEntry(std::vector<Contact>& addressBook) {
    std::string firstName;
    std::cout << "Enter the first name of the contact you want to edit: ";
    std::cin >> firstName;

    auto it = std::find_if(addressBook.begin(), addressBook.end(),
                           [&firstName](const Contact& c) { return c.firstName == firstName; });

    if (it != addressBook.end()) {
        std::cout << "Enter new first name: ";
        std::cin >> it->firstName;

        std::cout << "Enter new last name: ";
        std::cin >> it->lastName;

        std::cout << "Enter new address: ";
        std::cin.ignore();
        std::getline(std::cin, it->address);

        std::cout << "Enter new phone number: ";
        std::cin >> it->phoneNumber;
    } else {
        std::cout << "Contact not found.\n";
    }
}

void deleteEntry(std::vector<Contact>& addressBook) {
    std::string firstName;
    std::cout << "Enter the first name of the contact you want to delete: ";
    std::cin >> firstName;

    auto it = std::find_if(addressBook.begin(), addressBook.end(),
                           [&firstName](const Contact& c) { return c.firstName == firstName; });

    if (it != addressBook.end()) {
        addressBook.erase(it);
        std::cout << "Contact deleted.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

int main() {
    std::vector<Contact> addressBook;
    int option;

    do {
        std::cout << "Address Book\n"
                  << "============\n"
                  << "1. Add entry\n"
                  << "2. View entries\n"
                  << "3. Edit entry\n"
                  << "4. Delete entry\n"
                  << "5. Quit\n"
                  << "> ";
        std::cin >> option;

        switch (option) {
            case 1:
                addEntry(addressBook);
                break;
            case 2:
                viewEntries(addressBook);
                break;
            case 3:
                editEntry(addressBook);
                break;
            case 4:
                deleteEntry(addressBook);
                break;
            case 5:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option\n";
        }
    } while (option != 5);


    return 0;
}

