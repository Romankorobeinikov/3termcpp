#include "MyString.h"


MyString &MyString::operator=(const MyString &other) {
    if (this->str != nullptr)
        delete[] this->str;

    this->lenght = other.lenght;
    this->str = new char[lenght + 1];
    strcpy(this->str, other.str);
    return *this;
}

MyString &MyString::operator=(const char *new_str) {
    if (this->str != nullptr)
        delete[] this->str;

    this->lenght = mystrlen(new_str);
    this->str = new char[lenght + 1];
    strcpy(this->str,new_str);
    return *this;
}

MyString MyString::operator+(const MyString &other) {
    MyString temp;
    int first = this->lenght;
    int second = other.lenght;
    int sum = first + second;
    temp.str = new char[sum + 1];
    temp.lenght = sum;
    for (int i = 0; i < sum; i++) {
        if (i < first)
            temp.str[i] = this->str[i];
        else
            temp.str[i] = other.str[i - first];
    }
    temp.str[sum] = '\0';
    return temp;
}

MyString MyString::operator+(const char *new_str) {

    MyString temp;
    int first = this->lenght;
    int second = mystrlen(new_str);
    int sum = first + second;
    temp.str = new char[sum + 1];
    temp.lenght = sum;
    for (int i = 0; i < sum; i++) {
        if (i < first)
            temp.str[i] = this->str[i];
        else
            temp.str[i] = new_str[i - first];
    }
    temp.str[sum] = '\0';
    return temp;

}

MyString operator+(const char *new_str, const MyString &object) {
    MyString temp;
    int size_str = strlen(new_str);
    temp.lenght = object.lenght + size_str;
    temp.str = new char[temp.lenght + 1];
    for (int i = 0; i < temp.lenght; i++) {
        if (i < size_str)
            temp.str[i] = new_str[i];
        else
            temp.str[i] = object.str[i - size_str];
    }
    temp.str[temp.lenght] = '\0';
    return temp;
}

bool MyString::operator==(const MyString &other) {
    if (this->lenght != other.lenght)
        return false;
    for (int i = 0; i < lenght; i++)
        if (this->str[i] != other.str[i])
            return false;
    return true;
}

bool MyString::operator!=(const MyString &other) {
    return !(*this == other);
}

void MyString::operator+=(const char *new_str) {
    *this = *this + new_str;
}

void MyString::operator+=(const MyString &other) {
    *this = *this + other;
}

char MyString::operator[](int i) {
    if (i < lenght && i >= 0)
        return this->str[i];
    else if (i >= -lenght && i < 0)
        return this->str[lenght + i];
    else
        return '#';
}

MyString MyString::operator*(int i) {
    MyString temp;
    temp.lenght = this->lenght * i;
    temp.str = new char[temp.lenght + 1];
    for (int j = 0; j < i; j++)
        for (int k = 0; k < this->lenght; k++)
            temp.str[k + j * this->lenght] = this->str[k];
    return temp;
}

MyString operator*(int i, const MyString &object) {
    MyString temp;
    temp.lenght = object.lenght * i;
    temp.str = new char[temp.lenght + 1];
    for (int j = 0; j < i; j++)
        for (int k = 0; k < object.lenght; k++)
            temp.str[k + j * object.lenght] = object.str[k];
    return temp;
}


int MyString::lenghtStr() const {
    return lenght;
}

MyString MyString::reverse() {
    MyString temp;
    temp.lenght = lenght;
    temp.str = new char[lenght + 1];
    for (int i = 0; i < lenght; i++) {
        temp.str[i] = str[lenght - i - 1];
    }
    temp.str[lenght] = '\0';
    return temp;
}

MyString MyString::UP()
{
    MyString temp = *this;
    for(int i = 0;i<lenght;i++)
        if(temp.str[i]>='a' && temp.str[i]<='z')
            temp.str[i] -=32;
    return temp;
}

MyString MyString::DOWN()
{
    MyString temp = *this;
    for(int i = 0;i<lenght;i++)
        if(temp.str[i]>='A' && temp.str[i]<='Z')
            temp.str[i] +=32;
    return temp;
}

bool MyString::in(const char* new_str)
{
    int new_len = mystrlen(new_str);
    for(int i = 0;i<lenght-new_len+1;i++)
    {
        if(str[i] == new_str[0])
        {
            bool flag = true;
            for(int j = 1;j<new_len;j++)
                if(str[i + j] != new_str[j])
                    flag = false;

            if (flag)
                return true;
        }
    }
    return false;
}

bool MyString::in(const MyString& other)
{
    int new_len = other.lenght;
    for(int i = 0;i<lenght-new_len+1;i++)
    {
        if(str[i] == other.str[0])
        {
            bool flag = true;
            for(int j = 1;j<new_len;j++)
                if(str[i + j] != other.str[j])
                    flag = false;

            if (flag)
                return true;
        }
    }
    return false;
}

void MyString::Print() {
    std::cout << str << std::endl;
}

