#include <iostream>
#include <string.h>
#include <stdlib.h>

class book
{
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book()
    {
        author = new char[30];
        title = new char[30];
        publisher = new char[30];
        price = new float;
        stock = new int;
    }
    void fetch();
    void show();
    void edit();
    int search(char[], char[]);
    void buy();
};

void book::fetch()
{
    std::cin.ignore();
    std::cout << "\t1. Enter author: ";
    std::cin.getline(author, 30);
    std::cout << "\t2. Enter title: ";
    std::cin.getline(title, 30);
    std::cout << "\t3. Enter publisher: ";
    std::cin.getline(publisher, 30);
    std::cout << "\t4. Enter price: ";
    std::cin >> *price;
    std::cout << "\t5. Enter stock: ";
    std::cin >> *stock;
}

void book::show()
{
    std::cout << "You are looking at the following book:" << std::endl;
    std::cout << "\n\t1. Author: " << author;
    std::cout << "\n\t2. Title: " << title;
    std::cout << "\n\t3. Publisher: " << publisher;
    std::cout << "\n\t4. Price: " << *price;
    std::cout << "\n\t5. Stock: " << *stock;
}

void book::edit()
{
    std::cin.ignore();
    std::cout << "\t1. Enter author: ";
    std::cin.getline(author, 30);
    std::cout << "\t2. Enter title: ";
    std::cin.getline(title, 30);
    std::cout << "\t3. Enter publisher: ";
    std::cin.getline(publisher, 30);
    std::cout << "\t4. Enter price: ";
    std::cin >> *price;
    std::cout << "\t5. Enter stock: ";
    std::cin >> *stock;
}

int book::search(char titl[30], char auth[30])
{
    if (strcmp(titl, title) == 0 && strcmp(auth, author) == 0)
        return 1;
    else
        return 0;
}

void book::buy()
{
    int count;
    std::cout << "Enter the number of books would you like to buy: ";
    std::cin >> count;
    if (count <= *stock)
    {
        *stock -= count;
        std::cout << "\nYou bought your books succesffully! Nice!";
        std::cout << "\nTotal price: " << (*price) * count << " zloty.";
        std::cout << "\nHave a nice day!";
    }
    else
    {
        std::cout << "Probably not enough copies in stock!" << std::endl;
    }
}

int main()
{
    book *books[20];
    int i = 0, r, t, choice;
    char title[30], author[30];
    while (1)
    {
        std::cout << "\nWELCOME INTO BOOKRENTAL! YOU CAN SEARCH, SHOW, EDIT AND BUY OUR BOOKS!" << std::endl;
        std::cout << "Choose your option from menu:";
        std::cout << "\n\t1. Entry of new book";
        std::cout << "\n\t2. Search for book";
        std::cout << "\n\t3. Edit details of book";
        std::cout << "\n\t4. Buy book";
        std::cout << "\n\t5. Exit program";
        std::cout << "\n> ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            books[i] = new book;
            books[i]->fetch();
            i++;
            break;
        case 2:
            std::cin.ignore();
            std::cout << "Enter title: ";
            std::cin.getline(title, 30);
            std::cout << "Enter author: ";
            std::cin.getline(author, 30);
            for (t = 0; t < i; t++)
            {
                if (books[t]->search(title, author))
                {
                    std::cout << "\nBook found successfully!" << std::endl;
                    books[t]->show();
                    break;
                }
            }
            if (t == i)
            {
                std::cout << "\nThere is not a book you are looking for!" << std::endl;
            }
            break;
        case 3:
            std::cin.ignore();
            std::cout << "Enter title: ";
            std::cin.getline(title, 30);
            std::cout << "Enter author: ";
            std::cin.getline(author, 30);
            for (t = 0; t < i; t++)
            {
                if (books[t]->search(title, author))
                {
                    std::cout << "\nFound the book!" << std::endl;
                    books[t]->edit();
                    break;
                }
            }
            if (t == i)
            {
                std::cout << "\nThis book is not in stock!" << std::endl;
            }
            break;
        case 4:
            std::cin.ignore();
            std::cout << "Enter title: ";
            std::cin.getline(title, 30);
            std::cout << "Enter author: ";
            std::cin.getline(author, 30);
            for (t = 0; t < i; t++)
            {
                if (books[t]->search(title, author))
                {
                    books[t]->buy();
                    break;
                }
            }
            if (t == 1)
            {
                std::cout << "\nThis book is not in stock!" << std::endl;
            }
            break;
        case 5:
            std::cout << "BYEBYE!" << std::endl;
            exit(0);
            break;
        default:
            std::cout << "Wrong option or it does not exist! Try again!" << std::endl;
            break;
        }
    }

    return 0;
}