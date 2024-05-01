#pragma once
const int SA = 45;
const int SB = 50;
const int SC = 25;

class list {
private:
    struct Worker {
        std::string surename;
        std::string nameOfFacility;
        int numberOfGearsA;
        int numberOfGearsB;
        int numberOfGearsC;
        Worker* next;// адресный блок
        Worker* prev;


        Worker(std::string surename = "no_surename", std::string nameOfFacility = "no_name", int numberOfGearsA = 0, int numberOfGearsB = 0, int numberOfGearsC = 0)
        {
            this->surename = surename;
            this->nameOfFacility = nameOfFacility;
            this->numberOfGearsA = numberOfGearsA;
            this->numberOfGearsB = numberOfGearsB;
            this->numberOfGearsC = numberOfGearsC;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    int SizeOfList;
    Worker* head = nullptr;
    Worker* tail = nullptr;

public:
    list() {
        SizeOfList = 0;
        Worker* head = nullptr;
        Worker* tail = nullptr;
    }
    ~list() {}

    void push_back(std::string surename = "no_surename", std::string nameOfFacility = "no_name", int numberOfGearsA = 0, int numberOfGearsB = 0, int numberOfGearsC = 0);
    void ShowAllElements();
    void totallNumberOfPartsInCurrentFacility(std::string nameOfFacility, std::string groupOfGears);
    void salarryFromCurrentFacility(std::string nameOfFacility);
    void midSalarryFromCurrenFacility(std::string nameOfFacility);
};
