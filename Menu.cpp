//
// Created by Miguel Pedrosa on 01/04/2023.
//

#include "Menu.h"
#include "Display.h"
#include "Reader.h"
#include "Operations.h"
#include "Storer.h"

void Menu::showMenu()
{
    std::vector<std::string> followers;
    std::vector<std::string> following;
    std::string fileFollowers = "../instagram_data/followers.json";
    std::string fileFollowing = "../instagram_data1/following.json";
    Reader::reader(fileFollowers, followers);
    Reader::reader(fileFollowing, following);
    std::vector<std::string> result;
    result = Operations::subtract(followers, following);

    int option;

    while (option != 5) {
        std::cout << "WELCOME INSTAGRAM FOLLOWERS MANAGER" << "\n";
        std::cout << "[1] " << "DISPLAY FOLLOWING" << std::endl;
        std::cout << "[2] " << "DISPLAY FOLLOWERS" << std::endl;
        std::cout << "[3] " << "DISPLAY USERS WHO DON'T FOLLOW BACK" << std::endl;
        std::cout << "[4] " << "STORE INFORMATION IN FILE" << std::endl;
        std::cout << "[5] " << "QUIT" << std::endl;

        std::cin >> option;

        switch (option) {
            case 1:
                Display::displayFollowing(following);
                break;
            case 2:
                Display::displayFollowers(followers);
                break;
            case 3:
                Display::displayPeopleWhoDontFollowBack(result);
                break;
            case 4:
                Storer::storeVectorToFile("../peoplewhodontfollowback.txt", result);
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid input" << std::endl;
        }
    }
}