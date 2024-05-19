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
#include <termios.h>
#include <functional>
#include <locale.h>

using namespace std;

class User
{
private:
    string login;
    string password;
    bool isAdmin;
public:
     User(){}
    
     User(const std::string& login, const std::string& password, bool isAdmin)
         : login(login), password(password), isAdmin(isAdmin) {}

     const std::string& getLogin() const {
         return login;
     }

     const std::string& getPassword() const {
         return password;
     }

     bool getIsAdmin() const {
         return isAdmin;
     }
    
     void setLogin(const string& newLogin) {
        login = newLogin;
     }
     
     void setPassword(const string& newPassword) {
        password = newPassword;
     }
    
     void setIsAdmin(bool newIsAdmin){
        isAdmin = newIsAdmin;
     }
};


class Jewelry
{
private: 
    string productType;
    string metall;
    int metallSample;
    int price;
    int orderNumber;
    int amount;
    string brand;
    int totalRevenue;
    int totalSoldQuantity;
public:
    
    Jewelry(){}
    
    Jewelry(const std::string& productType, const std::string& metall, int metallSample, int price, int orderNumber, int amount, const std::string& brand )
        : productType(productType),metall(metall), metallSample(metallSample),   price(price), orderNumber(orderNumber), amount(amount), brand(brand), totalRevenue(0), totalSoldQuantity(0)   {}
    
    void sell() {
            totalSoldQuantity++;
            totalRevenue += price;
        }

    const std::string& getProductType() const {
        return productType;
    }

    const std::string& getMetall() const {
        return metall;
    }

    int getPrice() const {
        return price;
    }
    
    int getTotalRevenue() const{
            return totalRevenue;
        }

    int getTotalSoldQuantity() const {
            return totalSoldQuantity;
    }
    
    int getAmount() const {
        return amount;
    }
    
    int getMetallSample() const {
        return metallSample;
    }
    
    const std::string& getBrand() const {
        return brand;
    }
    
    void setProductType(const string& newProductType) {
        productType = newProductType;
    }
    
    void setMetall(const string& newMetall) {
        metall = newMetall;
    }
    
    void setPrice(int newPrice) {
        price = newPrice;
    }
    
    void setOrderNumber(int newOrderNumber){
        orderNumber = newOrderNumber;
    }
    
    void setAmount(int newAmount) {
        amount = newAmount;
    }
    
    void setMetallSample(int newMetallSample) {
        metallSample = newMetallSample;
    }
    
    void setBrand (const string& newBrand){
        brand = newBrand;
    }
    
};
 

class ProgrammChecks{//класс для хранения функций проверок
public:
     bool isNumberNumeric();//проверка на ввод числа
     bool isNumberRangeCorrect(int number, int left_range, int right_range);//проверка на ввод промежутка
     string checkSize(string s);//проверка на размер строки
     string checkString(string s);//проверка на ввод строки
     int inputNumber(int left_range, int right_range);//проверка на ввод числа в промежутке
};

class Menu{
public:
    void start_menu();//стартовое меню
    void menuWorkWithUser();//меню работы с аккаунтами
    void menuWorkWithJewelry();//меню работы с товарами
    void menuSort();//меню сортировок
    void menuSearch();//меню поиска
    void menuUser();//меню пользователя
    void menuAdministrator();//меню администратора
};

class WorkWithFiles{//класс для работы с файлами
public:
    void writeUsersToFile(const vector<User>& users);//запись информации о пользователях в файл
    vector<User> readUsersFromFile();//чтение информации о пользователях из файла
    void writeJewelryToFile(const vector<Jewelry>& jewelryProducts);//запись информации о ювелирных изделий в файл
    vector<Jewelry> readJewelryFromFile();//чтение информации о ювелирных изделиях из файла
    void writeAccountsToFile(const vector<User>& accounts);//запись аккаунтов в файл
    vector<User> readAccountsFromFile();//чтение аккаунтов из файла
};

class Tables{//класс для хранения функций, которые выводят таблицы
public:
    void headTable();//шапка таблицы товаров
    void printAccountsTable(const std::vector<User>& accounts); //вывод таблицы аккаунтов
    void printUsersTable(const std::vector<User>& users);//вывод таблицы пользователей
    void printJewelryTable(const std::vector<Jewelry>& jewelryProducts);//отображение перечня ювелирных изделий
};

class WorkWithProducts: public Jewelry{
public:
    void addJewelry();//добавление товара
    void deleteJewelry();//удаление товара
    void editJewelry();//редактирование товара
    void printTotalRevenue(const std::vector<Jewelry>& jewelryProducts); //подсчёт общего числа выручки и количества проданных товаров
    void orderProduct();//индивидуальное задание (оформление заказа или предзаказа)
};

class WorkWithAccounts: public User{
public:
    void addaccount(); //добавление аккаунта
    void deleteAccount();//удаление аккаунта
    void editAccount();//редактирование аккаунта
    void approve(); //одобрение заявки на регистрацию
};

class EnterSystem{
public:
    bool checkLoginAndPassword(vector<User>& users, string login, string password);//проверка на ввод логина и пароля
    bool checkLoginAndPasswordRegist(vector<User>& users, string login, string password, bool isAdmin);//проверка на существование аккаунта
    void authorization();//авторизация
    void registration();//регистрация
    string encrypt(string input);//зашифровка
    string decrypt(string input);//расшифровка
};

class SortProducts{
public:
    bool isSortByPrice(Jewelry price_a, Jewelry price_b);//сортировка по цене
    bool isSortByAmount(Jewelry amount_a, Jewelry amounth_b);//сортировка по количеству товара в наличии
    bool isSortByMetallSample(Jewelry sample_a, Jewelry sample_b);//сортировка по пробе металла
    bool isSortByMetall(Jewelry metall_a, Jewelry metall_b);//сортировка по виду металла
};
 
class SearchProducts{
public:
    void searchPrice();//поиск по цене
    void searchAmount(); //поиск по количеству товара в наличии
    void searchProductType(); //поиск по виду изделия
    void searchMetall(); //поиск по виду металла
    void searcMetallSample(); //поиск по пробе металла
    void searchBrand();//поиск по названию бренда
};
 

/*cout << setw(13) << this->code << "|" << setw(26) << this->name << "|" << setw(20) << this->price << "|" << setw(15) << this->numberOf << "|";*/

#endif /* Header_h */
