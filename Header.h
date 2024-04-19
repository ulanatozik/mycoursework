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
 


extern bool isNumberNumeric();//проверка на ввод числа
extern bool isNumberRangeCorrect(int number, int left_range, int right_range);//проверка на ввод промежутка
extern string checkString(string s);//проверка на ввод строки
extern int inputNumber(int left_range, int right_range);//проверка на ввод числа в промежутке
extern void start_menu();//стартовое меню
extern void menuWorkWithUser();//меню работы с аккаунтами
extern void menuWorkWithJewelry();//меню работы с товарами
extern void menuSort();//меню сортировок
extern void menuUser();//меню пользователя
extern void menuAdministrator();//меню администратора
extern void writeUsersToFile(const vector<User>& users);//запись информации о пользователях в файл
extern vector<User> readUsersFromFile();//чтение информации о пользователях из файла
extern void writeJewelryToFile(const std::vector<Jewelry>& jewelryProducts);//запись информации о ювелирных изделий в файл
extern vector<Jewelry> readJewelryFromFile();//чтение информации о ювелирных изделиях из файла
extern void writeAccountsToFile(const vector<User>& accounts);//запись аккаунтов в файл
extern vector<User> readAccountsFromFile();//чтение аккаунтов из файла
extern void headTable();//шапка таблицы товаров
extern void printAccountsTable(const std::vector<User>& accounts); //вывод таблицы аккаунтов
extern void printUsersTable(const std::vector<User>& users);//вывод таблицы пользователей
extern void printJewelryTable(const std::vector<Jewelry>& jewelryProducts);//отображение перечня ювелирных изделий
extern void addJewelry();//добавление товара
extern void deleteJewelry();//удаление товара
extern void editJewelry();//редактирование товара
extern void printTotalRevenue(const std::vector<Jewelry>& jewelryProducts); //подсчёт общего числа выручки и количества проданных товаров
extern bool checkLoginAndPassword(std::vector<User>& users, std::string login, std::string password);//проверка на ввод логина и пароля
extern bool checkLoginAndPasswordRegist(std::vector<User>& users, std::string login, std::string password, bool isAdmin);//проверка на существование аккаунта
extern void authorization();//авторизация
extern void registration();//регистрация
extern void addaccount(); //добавление аккаунта
extern void deleteAccount();//удаление аккаунта
extern void editAccount();//редактирование аккаунта
extern void approve(); //одобрение заявки на регистрацию
extern string encrypt(string input);//зашифровка
extern string decrypt(string input);//расшифровка
extern bool isSortByPrice(Jewelry price_a, Jewelry price_b);//сортировка по цене
extern bool isSortByAmount(Jewelry amount_a, Jewelry amounth_b);//сортировка по количеству товара в наличии
extern bool isSortByMetallSample(Jewelry sample_a, Jewelry sample_b);//сортировка по пробе металла
extern bool isSortByMetall(Jewelry metall_a, Jewelry metall_b);//сортировка по виду металла
extern void searchPrice();//поиск по цене
extern void searchAmount(); //поиск по количеству товара в наличии
extern void searchProductType(); //поиск по виду изделия
extern void searchMetall(); //поиск по виду металла
extern void searcMetallSample(); //поиск по пробе металла
extern void searchBrand();//поиск по названию бренда
extern void individualTask();//индивидуальное задание (оформление заказа или предзаказа)

 
 
 




#endif /* Header_h */
