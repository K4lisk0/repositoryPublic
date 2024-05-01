#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"





//метод для помещения элементов в конец списка
void list::push_back(std::string surename, std::string nameOfFacility, int numberOfGearsA, int numberOfGearsB, int numberOfGearsC)
{
    if (head == nullptr) {
        tail = head = new Worker(surename, nameOfFacility, numberOfGearsA, numberOfGearsB, numberOfGearsC);
        SizeOfList += 1;
    }
    else {
        Worker* nextElement = this->tail;
        Worker* currentWorker = this->tail;
        nextElement = new Worker(surename, nameOfFacility, numberOfGearsA, numberOfGearsB, numberOfGearsC);
        currentWorker->next = nextElement;
        nextElement->prev = currentWorker;
        tail = nextElement;
        SizeOfList += 1;
    }
}


//метод для демонстрации всех элементов списка
void list::ShowAllElements()
{
    
    Worker* currentElement = this->head;
    while (currentElement->next != nullptr) {
        std::cout << " Фамилия: " << currentElement->surename <<
            " Цех: " << currentElement->nameOfFacility <<std::endl<<
            " Колличество деталей типа А: " << currentElement->numberOfGearsA <<
            " Колличество деталей типа B: " << currentElement->numberOfGearsB <<
            " Колличество деталей типа C: " << currentElement->numberOfGearsC << " | "<<std::endl;
        currentElement = currentElement->next;
        

    }
}


//метод для подсчёта общего количества конкретных деталей конерктного цеха
void list::totallNumberOfPartsInCurrentFacility(std::string nameOfFacility, std::string groupOfGears)
{
    Worker* currentElement = this->head;
    Worker* elementForFlag = this->head;
    int flag = 0;
    for (int i = 0; i < SizeOfList; i++) {
        if (nameOfFacility == elementForFlag->nameOfFacility) {
            flag = 1;
            break;
        }
        elementForFlag = elementForFlag->next;
       
    }
    if (flag == 0)
        std::cout << "Была допущена ошибка в написаниии названия цеха" << std::endl;
    int packOfGears{ 0 };
    for (int i = 0; i < SizeOfList; i++) {
        if (currentElement->nameOfFacility == nameOfFacility) {
            if (groupOfGears == "A") {
                packOfGears += currentElement->numberOfGearsA;
            }
            if (groupOfGears == "B") {
                packOfGears += currentElement->numberOfGearsB;
            }
            if (groupOfGears == "C") {
                packOfGears += currentElement->numberOfGearsC;
            }

        }
        currentElement = currentElement->next;
    }
    if (packOfGears == 0)
        std::cout << "Данные были введены неверно, ,была допущена ошибка в написании типа деталей"<<std::endl;
    std::cout << "Количество деталей категории " << groupOfGears << " - " << packOfGears << std::endl;
}
//метод отвечающий за ведомоть заработной платы работнков
void list::salarryFromCurrentFacility(std::string nameOfFacility)
{
    Worker* currentElement = this->head;
    Worker* elementForFlag = this->head;
    int flag = 0;
    for (int i = 0; i < SizeOfList; i++) {
        if (nameOfFacility == elementForFlag->nameOfFacility) {
            flag = 1;
            break;
        }
        elementForFlag = elementForFlag->next;

    }
    if (flag == 0)
        std::cout << "Была допущена ошибка в написаниии названия цеха" << std::endl;
    int salary{ 0 };
    for (int i = 0; i < SizeOfList; i++) {
        if (currentElement->nameOfFacility == nameOfFacility) {
            int packOfGearsA{ 0 };
            int packOfGearsB{ 0 };
            int packOfGearsC{ 0 };
            std::cout <<"Фамилия: " << currentElement->surename;
                packOfGearsA = currentElement->numberOfGearsA;
                packOfGearsB = currentElement->numberOfGearsB;
                packOfGearsC = currentElement->numberOfGearsC;   
                salary = packOfGearsA * SA + packOfGearsB * SB + packOfGearsC * SC;
                std::cout << " Зарплата: " << salary << std::endl;
                
        }
        currentElement = currentElement->next;
    }
   
}
//средняя зарплата по цеху
void list::midSalarryFromCurrenFacility(std::string nameOfFacility)
{
    Worker* currentElement = this->head;
    Worker* elementForFlag = this->head;
    int numberOfEmployForCurrentFacility{ 0 };
    int flag = 0;
    for (int i = 0; i < SizeOfList; i++) {
        if (nameOfFacility == elementForFlag->nameOfFacility) {
            flag = 1;
            numberOfEmployForCurrentFacility += 1;  
            
        }
        elementForFlag = elementForFlag->next;

    }
    if (flag == 0)
        std::cout << "Была допущена ошибка в написаниии названия цеха" << std::endl;
    int salary{ 0 };
    int totalSallary{ 0 };
    for (int i = 0; i < SizeOfList; i++) {
        if (currentElement->nameOfFacility == nameOfFacility) {
            int packOfGearsA{ 0 };
            int packOfGearsB{ 0 };
            int packOfGearsC{ 0 };
            packOfGearsA = currentElement->numberOfGearsA;
            packOfGearsB = currentElement->numberOfGearsB;
            packOfGearsC = currentElement->numberOfGearsC;
            salary += packOfGearsA * SA + packOfGearsB * SB + packOfGearsC * SC;
            

        }
        currentElement = currentElement->next;
    }
    std::cout << " Средняя зарплата цеха " << nameOfFacility << " - " << salary / numberOfEmployForCurrentFacility<<std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    std::string path = "text.txt";
    std::ifstream text;
    std::string surename;
    std::string nameOfFacility;
    int numberOfGearsA{ 0 };
    int numberOfGearsB{ 0 };
    int numberOfGearsC{ 0 };
    std::string nameOfFacilityForCase1 = "no_data";
    std::string nameOfFacilityForCase2 = "no_data";
    std::string nameOfFacilityForCase3 = "no_data";
    std::string groupOfGears = "no_data";
    text.open(path, std::ios::app);
    if (text.is_open()) {
        int exitToEscapeCycle{ 0 };
            list newlist;
            text.seekg(0, std::ios::beg);
            while (exitToEscapeCycle == !1) {
                std::cout << std::endl << "Напечатайте цифру, отвечающую за ваш выбор:" << std::endl
                << " 0 - вывести все элементы" << std::endl
                << " 1 - общее количество деталей категории А, В, С, собранных рабочими определённого цеха " << std::endl
                << " 2 - ведомомсть заработной платы рабочих определённого цеха " << std::endl
                << " 3 - средний размер заработной платы работников конкретного цеха" << std::endl
                << " 4 - Для выхода. " << std::endl;
            while (!text.eof()) {
                text >> surename >> nameOfFacility >> numberOfGearsA >> numberOfGearsB >> numberOfGearsC;
                newlist.push_back(surename, nameOfFacility, numberOfGearsA, numberOfGearsB, numberOfGearsC);
            }
            int choise{ 0 };
            std::cin >> choise;
            switch (choise) {
            case 0:
                newlist.ShowAllElements();
                break;
            case 1:
                
                std::cout << "Введите название цеха. Например: facility_А ,facility_B  или facility_С ." << std::endl;
                std::cin >> nameOfFacilityForCase1;
                std::cout << "Введите название категории деталей, без пробелов, на английском. Например: A , В или С ." << std::endl;
                std::cin >> groupOfGears;
                newlist.totallNumberOfPartsInCurrentFacility(nameOfFacility, groupOfGears);
                break;
            case 2:
                std::cout << "Введите название цеха. Например: facility_А ,facility_B  или facility_С ." << std::endl;
                std::cin >> nameOfFacilityForCase2;
                newlist.salarryFromCurrentFacility(nameOfFacilityForCase2);
                break;
            case 3:
                std::cout << "Введите название цеха. Например: facility_А ,facility_B  или facility_С ." << std::endl;
                std::cin >> nameOfFacilityForCase3;
                newlist.midSalarryFromCurrenFacility(nameOfFacilityForCase3);
                break;
            case 4:
                exitToEscapeCycle = 1;
                break;
            }
        }
    }
    else {
        std::cout << "файл не открылся";
    }
    text.close();
    return 1;
}