#include "include/list.h"

void List::print_menu() {
    int choice;

    cout << "********************** \n";
    cout << "1 - Print list. \n";
    cout << "2 - Add to list. \n";
    cout << "3 - Delete from list. \n";
    cout << "4 - Save list. \n";
    cout << "5 - Quit. \n";
    cout << "Enter your choice and press return/enter. \n";

    cin >> choice;

    if (choice == 5) {
        return;
    }
    else if (choice == 4) {
        save_list();
    }
    else if (choice == 3) {
        delete_item();
    }
    else if (choice == 2) {
        add_item();
    }
    else if (choice == 1) {
        print_list();
    }
    else {
        cout << "Sorry choice hasn't been implemented. \n";
    }
}

void List::add_item() {
    cout << "\n \n";
    cout << "*** Add Item *** \n";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "Successfully added an item to the list \n\n\n";
    cin.clear();

    print_menu();
}

void List::delete_item() {
    cout << "*** Delete Item *** \n";
    cout << "Select an item index number to delete: \n";

    if (list.size()) {
        for (unsigned int i = 0; i < list.size(); i++) {
            cout << i << ": " << list[i] << "\n";
        }
        int choiceNum;
        cin >> choiceNum;
        list.erase(list.begin() + choiceNum);
    }
    else {
        cout << "No item in the list to delete. \n";
    }

    print_menu();
}

void List::print_list() {
    cout << "\n \n";
    cout << "*** Print List *** \n";

    for (unsigned int list_index = 0; list_index < list.size(); list_index++) {
        cout << " * " << list[list_index] << "\n";
    }

    cout << "\n\nM - Menu \n";
    char choice;
    cin >> choice;

    if (choice == 'M' || choice == 'm') {
        print_menu();
    }
    else {
        cout << "Invalid Choice. Quitting.. \n";
    }
}

bool List::find_userList() {
    bool userFound = false;
    cout << "\n \n";
    cout << "*** Welcome "<< name <<" *** \n";

    for (unsigned int user_index = 0; user_index < mainList.size(); user_index++) {
        cout << mainList[user_index][0] << "\n";
        if(mainList[user_index][0] == name) {
            cout << "User has been found: " << mainList[user_index][0] << "\n";
            list = mainList[user_index];
            currrentUserIndex = user_index;
            userFound = true;
            break;
        }
    }

    if(userFound == false) {
        list.push_back(name);
        mainList.push_back(list);
        currrentUserIndex = mainList.size() - 1;
    }

    return userFound;
}

void List::save_list() {
    cout << "Saving the List ...\n";
    mainList[currrentUserIndex] = list;
    data.write(mainList);
    print_menu();
}