#pragma once
#include <iostream>

class MyString {
private:
    char *str;
    int lenght;

    int static mystrlen(const char *temp) {
        int i = 0;
        while (temp[i] != '\0')
            i++;
        return i;
    }

public:
    MyString() {
        str = nullptr;
        lenght = 0;
    }

//конструктор создания
    explicit MyString(const char *str)
    {
        lenght = mystrlen(str);
        this->str = new char[lenght + 1];
        strcpy(this->str,str);
    }

//конструктор копирования
    MyString(const MyString &other)
    {
        this->lenght = other.lenght;
        this->str = new char[lenght + 1];
        strcpy(this->str,other.str);
    }

    ~MyString() {
        delete[] this->str;
    }

    MyString &operator=(const MyString &other);
    MyString &operator=(const char* new_str);

    MyString operator+(const MyString &other);
    MyString operator+(const char*);
    friend MyString operator+(const char* new_str,const MyString& object);

    void operator+=(const char* new_str);
    void operator+=(const MyString &other);

    char operator[](int i);

    MyString operator*(int i);
    friend MyString operator*(int i,const MyString& object);

    bool operator==(const MyString &other);

    bool operator!=(const MyString &other);

    int lenghtStr() const;

    MyString reverse();

    MyString UP();

    MyString DOWN();

    bool in(const char* new_str);
    bool in(const MyString& other);

    void Print();

};



