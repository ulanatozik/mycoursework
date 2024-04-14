//
//  Header.h
//  mycoursework
//
//  Created by Ульяна Тозик on 13.04.24.
//

#ifndef Header_h
#define Header_h
#define service_hpp

#include <stdio.h>
#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <unistd.h>

using namespace std;

class User
{
private:
    string login;
    string password;
    bool isAdmin;
public:
     User(const std::string& login, const std::string& password, bool isAdmin)
         : login(login), password(password), isAdmin(isAdmin) {}

     // Методы доступа к полям класса
     const std::string& getLogin() const {
         return login;
     }

     const std::string& getPassword() const {
         return password;
     }

     bool getIsAdmin() const {
         return isAdmin;
     }
};

class Jewelry
{
private: 
    int price;
    int amount;
    string productType;
    string metall;
    int metallSample;
    string collection;
public:
    Jewelry(int price, int amount, const string& productType, const string& metall, int metallSample, const string& collection )
        : price(price), amount(amount), productType(productType), metall(metall), metallSample(metallSample), collection(collection)  {}

    // Методы доступа к полям класса
    const string& getProductType() const {
        return productType;
    }

    const string& getMetall() const {
        return metall;
    }

    int getPrice() const {
        return price;
    }
    
    int getAmount() const {
        return amount;
    }
    
    int getMetallSample() const {
        return metallSample;
    }
    
    const string& getCollection() const {
        return collection;
    }
    
};
/*struct User {
    string login;
    string password;
    bool isAdmin;
};*/

class Jewelry
{
private: 
    int price;
    int amount;
    string productType;
    string metall;
    int metallSample;
    string collection;
public:

    

}

struct Jewelry{
    int price;
    int amount;
    string productType;
    string metall;
    int metallSample;
    string collection;
};

/*struct FIO {
    string surname;
    string name;
    string patronymic;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Medical {
    struct FIO Fio;
    struct Date Data;
    double day_salary;
    double quantity_miss_day;
    double pay_day;
    double result_pay;
};*/

extern bool isNumberNumeric();//проверка на ввод числа
extern bool isNumberRangeCorrect(int number, int left_range, int right_range);//проверка на ввод промежутка
extern int inputNumber(int left_range, int right_range);//проверка на ввод числа в промежутке
extern string checkString(string s);//проверка на ввод строки
extern void start_menu();//стартовое меню
extern void writeUsersToFile(const vector<User>& users);//функция записей пользователя в файл
extern vector<User> readUsersFromFile();//функция чтения пользователей из файла
extern void printUsersTable(const std::vector<User>& users);//вывод таблицы пользователей
extern void menuWorkWithUser();//меню работы с аккаунтами
extern void menuWorkWithJewelry();//меню работы с товарами
extern void menuUser();//меню пользователя
extern void menuAdministrator();//меню администратопа
extern bool checkLoginAndPassword(std::vector<User>& users, std::string login, std::string password);//проверка на ввод логина и пароля
extern bool checkLoginAndPasswordRegist(std::vector<User>& users, std::string login, std::string password, bool isAdmin);//проверка на существование аккаунта
extern void authorization();//авторизация
extern void registration();//регистрация
extern void deleteAccount();//удаление аккаунта

/*extern void writeMedicalsToFile(const std::vector<Medical>& medicals);//заменяем на*/
extern void writeJewelryToFile(const std::vector<Jewelry>& jewelryProducts);//запись ювелирных изделий в файл

/*extern vector<Medical> readMedicalFromFile();//заменяем на*/
extern vector<Jewelry> readJewelryFromFile()//чтение информации о ювелирных изделиях из файла

extern string encrypt(string input);//зашифровка
extern string decrypt(string input);//расшифровка

/*extern void printMedicalTable(const std::vector<Medical>& medicals);//заменяем на*/
extern void printJewelryTable(const std::vector<Jewelry>& jewelryProducts);//отображение перечня ювелирных изделий


/*extern bool isSortBySurname(Medical name_a, Medical name_b);//заменяем на
extern bool isSortByMonth(Medical month_a, Medical month_b);/ 
extern bool isSortByYear(Medical year_a, Medical year_b); 
extern bool isSortByDay(Medical day_a, Medical day_b); 
extern bool isSortBySalary(Medical salary_a, Medical salary_b); */
extern bool isSortByPrice(Jewelry price_a, Jewelry price_b);//сортировка по цене
extern bool isSortByAmount(Jewelry amount_a, Jewelry amounth_b);//сортировка по количеству в наличии
extern bool isSortByMetallSample(Jewelry sample_a, Jewelry sample_b);//сортировка по пробе металла
extern bool isSortByMetall(Jewelry metall_a, Jewelry metall_b);//сортировка по типу металла



extern void writeAccountsToFile(const vector<User>& accounts);//запись аккаунтов в файл
extern vector<User> readAccountsFromFile();//достать пользователей из аккаунта в вектор
extern void printAccountsTable(const std::vector<User>& accounts); //вывод таблицы аккаунтов
extern void headTable();//шапка таблицы товаров
extern void approve(); //одобрение заявки

/*extern void addMedical();//заменяем на*/
extern void addJewelry();//добавление товара

extern void addaccount(); 

/*extern void deleteMedical();//заменяем на*/
extern void deleteJewelry();//удаление товара

extern void deleteAccount();//удаление аккаунта

/*extern void editMedical();//заменяем на*/
extern void editJewelry();//редактирование товара

extern void editAccount();//редактирование аккаунта

extern void individualTask();//индивидуальное задание (оформление заказа или предзаказа)

/*extern void searchSurname();//заменяем на
extern void searchMonth();
extern void searchYear(); 
extern void searchQuantity(); 
extern void searchDaySalary(); 
extern void searchMedical();*/
extern void searchPrice();//поиск по цене
extern void searchAmount(); //поиск по количеству
extern void searchProductType(); //поиск по виду изделия
extern void searchMetall(); //поиск по виду металла
extern void searcMetallSample(); //поиск по пробе металла
extern void searchCollection();//поиск по названию коллекции
 
extern void menuSort();//меню сортировок




#endif /* Header_h */
