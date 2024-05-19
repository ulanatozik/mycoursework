 


#include "Header.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>



string global_login;

    
string ProgrammChecks::checkSize(string s){//проверка на размер строки
        const int SIZE = 8;
        do
        {
            cin >> s;
            if (s.size() > SIZE)
            {
                std::cout << "Введенная строка превышает заданный размер. Пожалуйста, повторите ввод. " << std::endl;
            }
            else
            {
                return s;
                break;
            }
        } while (s.size() > SIZE);
        
        return " ";
        
}
    
string ProgrammChecks::checkString(string s)//проверка на ввод строки
{
        while (1) {
            getline(cin, s);
            
            int x = 0;
            for (int i = 0; i < s.size(); i++) {
                if (isdigit(s[i])) {
                    x = 1;
                    break;
                }
            }
            if (x == 0) return s;
            cout << "Некорректный ввод. Повторите попытку." << endl;
            
        }
}
    
bool ProgrammChecks::isNumberNumeric()//проверка на ввод числа
{
        if (cin.get() == '\n')
            return true;
        else
        {
            cin.clear();
            cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
            return false;
        }
}
    
bool ProgrammChecks::isNumberRangeCorrect(int number, int left_range, int right_range)//проверка на выход за границы
{
        if ((number >= left_range) && (number <= right_range)) return true;
        else return false;
}
    
int ProgrammChecks::inputNumber(int left_range, int right_range) {//ввод числа
        
        int number;
        while (true)
        {
            cin >> number;
            if( isNumberNumeric() &&  isNumberRangeCorrect(number, left_range, right_range)){
                return number;
            }
            else{
                cout << "Некорректный ввод. Повторите попытку ";
            }
            
        }
}
    
 

void Menu::start_menu() {//начальное меню
    int choice;
    EnterSystem sObj;
    ProgrammChecks checker;
    do{
        cout << "-------Введите-------- \n 1. Для регистрации \n 2. Для авторизации\n 3. Для выхода \n";
        cout << "Ваш выбор?" <<endl;
        choice = checker.inputNumber(1, 3);
        switch (choice) {
            case 1: {
                sObj.registration();
                sleep(3);
                break;
            }
            case 2: {
                sObj.authorization();
                break;
            }
            case 3: {
                cout<<"Совершен выход из программы.";
                break;
                
            }
        }
    }while(choice!=3);
}

 
    
void WorkWithFiles::writeUsersToFile(const vector<User>& users) {//запись пользователей в файл
    string filename = "/Users/ulanatozik/Материалы по учебе (БГУИР)/1 курс/Курсач 1 курс /мой курсачик/mycoursework/mycoursework/users.txt";
    ofstream outputFile(filename);
    EnterSystem sObj;
    
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << "для записи" << std::endl;
        return;
    }
    
    for (const User& user : users) {
        outputFile << user.getLogin() << " " << sObj.encrypt(user.getPassword()) << " " << user.getIsAdmin() << std::endl;
    }
    
    outputFile.close();
}
    
vector<User> WorkWithFiles::readUsersFromFile() {//достать пользователей из файла в вектор
       string fileName = "/Users/ulanatozik/Материалы по учебе (БГУИР)/1 курс/Курсач 1 курс /мой курсачик/mycoursework/mycoursework/users.txt";
       vector<User> users;
       EnterSystem sObj;
       ifstream inFile(fileName);
       if (inFile.is_open()) {
           std::string login, password, isAdminStr;
           while (inFile >> login >> password >> isAdminStr) {
               bool isAdmin = (isAdminStr == "1");
               User newUser;
               newUser.setLogin(login);
               newUser.setPassword(sObj.decrypt(password));
               newUser.setIsAdmin(isAdmin);
               users.push_back(newUser);
           }
           inFile.close();
       }
       else {
           std::cerr << "Невозможно открыть файл " << fileName << std::endl;
       }
       return users;
}
    
void WorkWithFiles::writeAccountsToFile(const vector<User>& accounts) {//Запись аккаунтов в файл
       string filename = "/Users/ulanatozik/Материалы по учебе (БГУИР)/1 курс/Курсач 1 курс /мой курсачик/mycoursework/mycoursework/accounts.txt";
       ofstream outputFile(filename);
       EnterSystem sObj;
       if (!outputFile.is_open()) {
           std::cerr << "Ошибка открытия файла" << filename << " для записи" << std::endl;
           return;
       }

       for (const User& account : accounts) {
           outputFile << account.getLogin() << " " << sObj.encrypt(account.getPassword()) << " " << account.getIsAdmin() << endl;
       }
       outputFile.close();
}
    
vector<User> WorkWithFiles::readAccountsFromFile() {//достать пользователей из файла в вектор
        string fileName = "/Users/ulanatozik/Материалы по учебе (БГУИР)/1 курс/Курсач 1 курс /мой курсачик/mycoursework/mycoursework/accounts.txt";
        vector<User> accounts;
        EnterSystem sObj;
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            string login, password, isAdminStr;
            while (inFile >> login >> password >> isAdminStr) {
                bool isAdmin = (isAdminStr == "1");
                User newUser;
                newUser.setLogin(login);
                newUser.setPassword(sObj.decrypt(password));
                newUser.setIsAdmin(isAdmin);
                accounts.push_back(newUser);
            }
            inFile.close();
        }
        else {
            cerr << "Невозможно открыть файл " << fileName << std::endl;
        }
        return accounts;
}

  
void WorkWithFiles::writeJewelryToFile(const vector<Jewelry>& jewelryProducts) {//запись товаров в файл
       string filename = "/Users/ulanatozik/Материалы по учебе (БГУИР)/1 курс/Курсач 1 курс /мой курсачик/mycoursework/mycoursework/jewelry.txt";
       ofstream outputFile(filename);
       if (!outputFile.is_open()) {
           std::cerr << "Ошибка открытия файла " << filename << " для записи." << std::endl;
           return;
       }
       for (const Jewelry& jewelry : jewelryProducts) {
           outputFile << jewelry.getProductType() << " " << jewelry.getMetall() << " " << jewelry.getMetallSample() << " " << jewelry.getPrice() << " "
               << jewelry.getAmount() << " " << jewelry.getBrand() << std::endl;
            
       }
       outputFile.close();
}

     

vector<Jewelry> WorkWithFiles::readJewelryFromFile() {//достать записи из файла в вектор
       string fileName = "/Users/ulanatozik/Материалы по учебе (БГУИР)/1 курс/Курсач 1 курс /мой курсачик/mycoursework/mycoursework/jewelry.txt";
       vector<Jewelry> jewelryProducts;
       ifstream inputFile(fileName);
       if (inputFile.is_open())
       {
           int price, amount, metallSample;
           string productType, metall, brand;
           while (inputFile >> productType >> metall >> metallSample
               >> price >> amount >> brand)
           {
               Jewelry j;
               j.setProductType(productType);
               j.setMetall(metall);
               j.setMetallSample(metallSample);
               j.setPrice(price);
               j.setAmount(amount);
               j.setBrand(brand);
               jewelryProducts.push_back(j);
           }
           inputFile.close();
       }
       else {
           cerr << "Ошибка открытия файла " << fileName << endl;
           return jewelryProducts;
       }
       return jewelryProducts;
}


void Tables::printAccountsTable(const vector<User>& accounts) {//вывод таблицы аккаунтов
    // вывод заголовка таблицы
 
    cout << "\n|=============================================================================================|"
         << "\n|                                 ЗАЯВКИ НА РЕГИСТРАЦИЮ                                       |"
         << "\n|=============================================================================================|"
         << "\n|    №    |            Логин             |            Пароль            |         Админ       |"
         << "\n|=============================================================================================|\n";
    int i = 0;
    //вывод строк таблицы
    for (const auto& account : accounts) {
        cout << "|" << setw(9) << ++i << "|" << setw(16) << account.getLogin() << setw(16) << " | "
        << setw(16) << account.getPassword() << setw(15) << " | "
        << setw(13) << (account.getIsAdmin() ? "Да" : "Нет") << setw(10) << "|" << endl;
        cout << "|=============================================================================================|" << endl;
    }
}

void Tables::printUsersTable(const vector<User>& users)
{//Вывод таблицы аккаунтов
   EnterSystem sObj;
   // Вывод заголовка таблицы
    
    cout << "\n|=============================================================================================|"
         << "\n|                                 АККАУНТЫ ПОЛЬЗОВАТЕЛЕЙ                                      |"
         << "\n|=============================================================================================|"
         << "\n|    №    |            Логин             |            Пароль            |        Админ        |"
         << "\n|=============================================================================================|\n";
   int i = 0;
   // Вывод строк таблицы
   for (const auto& user : users) {
       cout << "|" << setw(9) << ++i << "|" << setw(18) << user.getLogin() << setw(14) << " | "
           << setw(16) << user.getPassword() << setw(15) << " | "
           << setw(13) << (user.getIsAdmin() ? "Да" : "Нет") << setw(10) << "|" << endl;
       cout << "|=============================================================================================|" << endl;
   }

}

void Tables::printJewelryTable(const vector<Jewelry>& jewelryProducts) {//вывод таблицы товаров
    headTable();
    int i = 0;
        
    for (const auto& jewelry : jewelryProducts) {
        cout << "| "
                 << setw(3) << ++i<< " | "
                 << setw(20) << jewelry.getProductType()  << setw(8) << " | "
                 << setw(17) << jewelry.getMetall() << setw(7) << " | "
                 << setw(13) << jewelry.getMetallSample() << setw(15) << " | "
                 << setw(6) << jewelry.getPrice() << setw(8) << " | "
                 << setw(8) << jewelry.getAmount()  << setw(10) << " | "
                 << setw(10) << jewelry.getBrand() << setw(3) << " |"
                 << endl
                 << "|=======================================================================================================================|" << endl;
        }

          i++;
}


void Tables::headTable() {//шапка таблицы товаров
    
    cout << "\n|=======================================================================================================================|"
        << "\n|                                        ЮВЕЛИРНЫЕ ТОВАРЫ                                                               |"
        << "\n|=======================================================================================================================|"
        << "\n|  №  |      Вид изделия     |     Металл     |       Проба металла       |    Цена     |   Количество    |    Бренд    |"
        << "\n|=======================================================================================================================|\n";
    }

void WorkWithAccounts::approve() {//одобрение заявки
    
   Tables tablesObj;
   WorkWithFiles filesObj;
    ProgrammChecks checker;
   vector<User> accounts = filesObj.readAccountsFromFile();
   vector<User> users = filesObj.readUsersFromFile();
   tablesObj.printAccountsTable(accounts);
   int number_for_add, choice;
   cout << "---Выберите---" << endl;
   cout << "1 - Для одобрения заявки" << endl;
   cout << "2 - Для выхода" << endl;
   choice = checker.inputNumber(1, 2);
   switch (choice) {
   case 1: {
       cout << "Выберите номер заявки, которую хотите одобрить" << endl;
       number_for_add = checker.inputNumber(1, accounts.size());
       User user;
       user.setLogin(accounts.at(number_for_add - 1).getLogin());
       user.setPassword(accounts.at(number_for_add - 1).getPassword());
       user.setIsAdmin(accounts.at(number_for_add - 1).getIsAdmin());
       users.push_back(user);
       filesObj.writeUsersToFile(users);
       cout << "Вы одобрили заявку" << endl;
       accounts.erase(accounts.begin() + number_for_add - 1);
       filesObj.writeAccountsToFile(accounts);
       break;
   }
   case 2: {
       return;
   }
   }
}
 

void WorkWithProducts::addJewelry() {//добавить товар
   ProgrammChecks checker;
   WorkWithFiles filesObj;
   Tables tableObj;
   cout << "Добавить товар:" << endl;
   string productType, metall, brand;
    int price, amount = 0;
    int sampleIndex = 0;
    int validSamples[] = {375, 500, 750, 958};

   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
 
       cout << "Введите вид ювелирного изделия (1. Cерьги, 2. Кольцо, 3. Колье, 4. Брошь, 5. Цепь):" << endl;
                   
           
               int typeIndex = checker.inputNumber(1, 5);
               
               while (typeIndex<1 || typeIndex>5) {
                   cout << "Выбранный вид изделия недопустим. Пожалуйста, выберите снова:" << endl;
                   typeIndex = checker.inputNumber(1, 5);
               }
    
               switch(typeIndex)
               {
                   case 1:
                   {
                       productType = "Серьги";
                       break;
                   }
                   case 2:
                   {
                       productType = "Кольцо";
                       break;
                   }
                   case 3:
                   {
                       productType = "Колье";
                       break;
                   }
                   case 4:
                   {
                       productType = "Брошь";
                       break;
                   }
                   case 5:
                   {
                       productType = "Цепь";
                       break;
                   }
               }
 
               cout << "Выберите вид металла (1. Золото, 2. Серебро, 3. Платина):" << endl;
               
              
               int metalIndex = checker.inputNumber(1, 3);
               
               while (metalIndex<1 || metalIndex>3) {
                   cout << "Выбранный вид металла недопустим. Пожалуйста, выберите снова:" << endl;
                   metalIndex = checker.inputNumber(1, 3);
               }
    
              switch(metalIndex)
              {
                  case 1:
                  {
                      metall= "Золото";
                      break;
                  }
                  case 2:
                  {
                      metall = "Серебро";
                      break;
                  }
                  case 3:
                  {
                      metall = "Платина";
                      break;
                  }
              }
     
               
               cout << "Введите пробу металла (1. 375, 2. 500, 3. 750, 4. 958):" << endl;
               sampleIndex = checker.inputNumber(1, 4);
               
       while (sampleIndex<1 || sampleIndex>4) {
           cout << "Выбранная проба металла недопустима. Пожалуйста, выберите снова:" << endl;
           sampleIndex = checker.inputNumber(1, 4);
       }
       cout << "Введите цену за 1 единицу товара:" << endl;
       price = checker.inputNumber(1, 10000);
       cout << "Введите количество данного товара в наличии:" << endl;
       amount = checker.inputNumber(0, 100);
       cout << "Введите бренд товара:" << endl;
       brand = checker.checkString(brand);
       
   
   Jewelry jewelry;
   jewelry.setProductType(productType);
   jewelry.setMetall(metall);
   jewelry.setMetallSample(validSamples[sampleIndex - 1]);
   jewelry.setPrice(price);
   jewelry.setAmount(amount);
   jewelry.setBrand(brand);
   jewelryProducts.push_back(jewelry);
   filesObj.writeJewelryToFile(jewelryProducts);
   tableObj.printJewelryTable(jewelryProducts);
}

void WorkWithAccounts::addaccount() {//Добавить аккаунт
   WorkWithFiles filesObj;
   EnterSystem sObj;
    ProgrammChecks checker;
  
    
    cout << "Добавить аккаунт" << endl;
       string login, password;
       bool isAdmin;
       vector<User> users = filesObj.readUsersFromFile();
       while (true) {
           cout << "Введите логин" << endl;
           cin >> login;
           cout << "Введите пароль" << endl;
           cin >> password;
           cout << "Является ли админом (1/0)" << endl;
           isAdmin = checker.inputNumber(0,1);
           if (sObj.checkLoginAndPasswordRegist(users, login, password, isAdmin)) {
               break;
           }
       }
       User user;
       user.setLogin(login);
       user.setPassword(password);
       user.setIsAdmin(isAdmin);


       users.push_back(user);
       filesObj.writeUsersToFile(users);

}

void WorkWithProducts::deleteJewelry() {//удалить товар
   WorkWithFiles filesObj;
   Tables tableObj;
    ProgrammChecks checker;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   tableObj.printJewelryTable(jewelryProducts);
   int number_for_delete;
   cout << "----Удаление товара---" << endl << endl;
   cout << "Введите номер товара, который хотите удалить" << endl;
   number_for_delete = checker.inputNumber(1, jewelryProducts.size());
   int yes_or_no;
   cout << "1. Да" << endl
       << "2. Нет" << endl
       << "Ваш выбор?" << endl;
   yes_or_no = checker.inputNumber(1, 2);
   if (yes_or_no == 1) {
       jewelryProducts.erase(jewelryProducts.begin() + number_for_delete - 1);
       cout << "----Товар успешно удален----" << endl;
       filesObj.writeJewelryToFile(jewelryProducts);
   }
   else cout << "Вы отменили удаление" << endl;
}

void WorkWithAccounts::deleteAccount() {//удалить аккаунт
   Tables tableObj;
   WorkWithFiles filesObj;
    ProgrammChecks checker;
   vector<User> users = filesObj.readUsersFromFile();
   tableObj.printUsersTable(users);
   int number_for_delete;
   cout << "----Удаление учетной записи----" << endl << endl;;
   cout << "Введите номер аккаунта, который хотите удалить" << endl;
   number_for_delete = checker.inputNumber(1, users.size());
   cout << "Вы уверены, что хотите удалить аккаунт?" << endl;
   int yes_or_no;
   cout << "1. Да" << endl
       << "2. Нет" << endl
       << "Ваш выбор:" << endl;
   yes_or_no = checker.inputNumber(1, 2);
    if (yes_or_no == 1) {
            if (users.at(number_for_delete - 1).getIsAdmin() == 1) {
                cout << "Удалить свой аккаунт невозможно" << endl;
            } else {
                users.erase(users.begin() + number_for_delete - 1);
                cout << "----Аккаунт успешно удален----" << endl;
                filesObj.writeUsersToFile(users);
            }
        } else {
            cout << "Вы отменили удаление" << endl;
        }
}


void WorkWithProducts::editJewelry() { //редактирование товара
   int choice;
   Tables tableObj;
   WorkWithFiles filesObj;
   ProgrammChecks checker;
    
   do {
       vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
       tableObj.printJewelryTable(jewelryProducts);
       string productType, metall, brand;
       int newPrice, newAmount, number_for_edit;
       cout << "Введите номер товара, который хотите изменить " << endl;
       number_for_edit = checker.inputNumber(1, jewelryProducts.size());
       cout << "--------------Введите--------------" << endl;
       cout << "1 - Чтобы изменить вид изделия" << endl;
       cout << "2 - Чтобы изменить количество товара в наличии" << endl;
       cout << "3 - Чтобы изменить бренд товара" << endl;
       cout << "4 - Чтобы изменить цену товара" << endl;
       cout << "5 - Чтобы выйти из режима редактирования" << endl;
       cout << "Ваш выбор: ";
        
       choice = checker.inputNumber(1, 5);
       switch (choice) {
       case 1: {
           cout << "--Изменение вида изделия--" << endl;
           cout << setw(5) << "Новый вид изделия (1. Cерьги, 2. Кольцо, 3. Колье, 4. Брошь, 5. Цепь):" << endl;
           int typeIndex=checker.inputNumber(1,5);
           string newProductType;
           switch(typeIndex)
           {
               case 1:
               {
                   newProductType = "Серьги";
                   break;
               }
               case 2:
               {
                   newProductType = "Кольцо";
                   break;
               }
               case 3:
               {
                   newProductType = "Колье";
                   break;
               }
               case 4:
               {
                   newProductType = "Брошь";
                   break;
               }
               case 5:
               {
                   newProductType = "Цепь";
                   break;
               }
           }
           jewelryProducts.at(number_for_edit - 1).setProductType(newProductType);
           filesObj.writeJewelryToFile(jewelryProducts);
           cout << "--Вид изделия изменен--" << endl;
           break;
       }
       case 2: {
           cout << "--Изменение количества товара в наличии--" << endl;
           cout << setw(5) << "Новое количество: " << endl;
           newAmount = checker.inputNumber(1, 100);
           jewelryProducts.at(number_for_edit - 1).setAmount(newAmount);
           filesObj.writeJewelryToFile(jewelryProducts);
           cout << "--Количество товара изменено--" << endl;
           break;
       }
       case 3: {
           cout << "--Изменение бренда--" << endl;
           cout << setw(5) << "Новый бренд:" << endl;
           string newBrand = checker.checkString(brand);
           jewelryProducts.at(number_for_edit - 1).setBrand(newBrand);
           filesObj.writeJewelryToFile(jewelryProducts);
           cout << "--Бренд изменен--" << endl;
           break;
       }
       case 4: {
           cout << "--Изменение цены товара--" << endl;
           newPrice = checker.inputNumber(1, 10000);
           jewelryProducts.at(number_for_edit - 1).setPrice(newPrice);
           filesObj.writeJewelryToFile(jewelryProducts);
           cout << "--Цена товара изменена--" << endl;
           break;
       }
       case 5: {
           break;
       }

       }

   }while(choice!=5);
}

void WorkWithAccounts::editAccount() {//редактирование аккаунтов
    int choice;
    Tables tableObj;
    WorkWithFiles filesObj;
    ProgrammChecks checker;
    do{
        vector<User> users = filesObj.readUsersFromFile();
        tableObj.printUsersTable(users);
        int i = 0;
        int number_for_edit;
        string newLogin;
        cout << "Введите номер аккаунта, который хотите изменить: " << endl;
        number_for_edit = checker.inputNumber(1, users.size());
        cout << "--------------Введите--------------" << endl;
        cout << "1 - Чтобы изменить логин" << endl;
        cout << "2 - Чтобы изменить роль пользователя" << endl;
        cout << "3 - Чтобы редактировать все данные аккаунта" << endl;
        cout << "4 - Чтобы выйти из режима редактирования" << endl;
        cout << "Ваш выбор: ";
        choice = checker.inputNumber(1, 4);
        switch (choice) {
            case 1: {
                cout << "--Новый логин--" << endl;
                cin >> newLogin;

                bool isLoginTaken = false;
                for (int i = 0; i < users.size(); ++i) {
                    if (users.at(i).getLogin() == newLogin) {
                        isLoginTaken = true;
                        break;
                    }
                }

                if (!isLoginTaken) {
                    users.at(number_for_edit - 1).setLogin(newLogin);
                    filesObj.writeUsersToFile(users);
                    cout << "--Логин успешно заменен--" << endl;
                } else {
                    cout << "Данный логин занят, повторите попытку" << endl;
                    break;
                }
                break;
            }
            case 2: {
                cout << "--Новая роль пользователя--" << endl;
                cout << "1 - роль администратора" << endl;
                cout << "0 - роль пользователя" << endl;
                users.at(number_for_edit - 1).setIsAdmin(checker.inputNumber(0, 1));
                filesObj.writeUsersToFile(users);
                cout << "---Успешно отредактировано---" << endl;
                break;
                 }
            case 3: {
                cout << "--Новый логин--" << endl;
                cin >> newLogin;
                while (i < users.size()) {
                if (users.at(i).getLogin() == newLogin) {
                  cout << "Данный логин занят, повторите попытку" << endl;
                  cin >> newLogin;
                  i = 0;
                }
                else i++;
                }
                 users.at(number_for_edit - 1).setLogin(newLogin);
                     cout << "--Новая роль пользователя--" << endl;
                     cout << "1 - роль администратора" << endl;
                     cout << "0 - роль пользователя" << endl;
                     users.at(number_for_edit - 1).setIsAdmin(checker.inputNumber(0, 1));
                     filesObj.writeUsersToFile(users);
                     cout << "---Успешно отредактировано---" << endl;
                 break;
                 }
            case 4:{
                break;
            }
            }
                
    }while(choice!=4);
}
    
       

void Menu::menuWorkWithUser() { //меню для работы с учетными записями
   int choice;
   Tables tableObj;
   WorkWithAccounts accountObj;
   WorkWithFiles filesObj;
    ProgrammChecks checker;
   do {
       cout << "--------------Введите--------------" << endl;
       vector<User> users = filesObj.readUsersFromFile();
       cout << "1 - для вывода учетных записей" << endl;
       cout << "2 - для добавления учетных записей" << endl;
       cout << "3 - для редактирования учетных записей" << endl;
       cout << "4 - для удаления учетных записей" << endl;
       cout << "5 - для одобрения заявок на регистрацию" << endl;
       cout << "6 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = checker.inputNumber(1, 6);
       switch (choice) {
       case 1: {
           tableObj.printUsersTable(users);
           break;
       }
       case 2: {
           accountObj.addaccount();
           break;
       }
       case 3: {
           accountObj.editAccount();
           break;
       }
       case 4: {
           accountObj.deleteAccount();
           break;
       }
       case 5: {
           accountObj.approve();
       }
       case 6: {
           break;
       }
       default:cout<<"Введено некорректное значение. Попробуйте снова.";
       }
   }while(choice!=6);
}

void WorkWithProducts::orderProduct() {
    Tables tableObj;
    WorkWithFiles filesObj;
    ProgrammChecks checker;
    vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
    cout << "--Заказ товара--" << endl;
    cout << "Введите номер товара, который хотите заказать: "<<endl;
    tableObj.printJewelryTable(jewelryProducts);
    int choice;
    int choice2;
    int choice3;
 
    choice=checker.inputNumber(1, jewelryProducts.size())-1;
    if(jewelryProducts[choice].getAmount()>0)
    {
            cout<<"Вы уверены, что хотите заказать этот товар?"<<endl;
            cout<<"1. Да"<<endl;
            cout<<"2. Нет"<<endl;
            cout<<"Ваш выбор?"<<endl;
            cin >> choice2;
            switch(choice2)
            {
                case 1:
                {
                    cout<<"Ожидайте ответа администратора для подтверждения вашего заказа."<<endl;
                    sleep(3);
                    cout<<"Заказ товара подтвержден."<<endl;
                    jewelryProducts[choice].setAmount(jewelryProducts[choice].getAmount() - 1);
                    jewelryProducts[choice].sell();
                    break;
                }
                case 2:
                {
                    cout<<"Вы отменили заказ товара."<<endl;
                    return;
                }
                default:cout<<"Неверный выбор. Попробуйте снова.";
            }
    }
    else if(jewelryProducts[choice].getAmount()==0)
    {
            cout<<"Выбранного вами товара на данный момент нет в наличии. Желаете оформить предзаказ?"<<endl;
            cout<<"1. Да"<<endl;
            cout<<"2. Нет"<<endl;
            cout<<"Ваш выбор?"<<endl;
            cin >> choice3;
            switch(choice3)
            {
                case 1:
                {
                    cout<<"Ожидайте ответа администратора для подтверждения вашего предзаказа."<<endl;
                    sleep(3);
                    cout<<"Предзаказ оформлен. Вы получите свой товар, как только он появится в наличии."<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Вы отменили предзаказ товара."<<endl;
                    return;
                }
                default: cout<<"Неверный выбор. Попробуйте снова";
            }
    }
    filesObj.writeJewelryToFile(jewelryProducts);
}


void WorkWithProducts::printTotalRevenue(const vector<Jewelry>& jewelryProducts) { //подсчёт общего числа выручки и количества проданных товаров
        int totalSoldQuantity = 0;
        int totalRevenue = 0;
        int number=1;
        for (const auto& jewelry : jewelryProducts) {
            if (jewelry.getTotalSoldQuantity() > 0) {
                totalSoldQuantity += jewelry.getTotalSoldQuantity();
                totalRevenue += jewelry.getPrice() * jewelry.getTotalSoldQuantity();
                std::cout << "Общее количество проданных товаров для товара " << jewelry.getProductType() << "(номер " << number++ << "): " << jewelry.getTotalSoldQuantity() << std::endl;
                std::cout << "Общая выручка для товара " << jewelry.getProductType() << ": " << jewelry.getPrice() * jewelry.getTotalSoldQuantity() << std::endl;
            }
        }
        std::cout << "Обшее количество проданных товаров: " << totalSoldQuantity << std::endl;
        std::cout << "Общая выручка от всех проданных товаров: " << totalRevenue << std::endl;
}


void SearchProducts::searchProductType() {//поиск по виду изделия
   Tables tableObj;
   ProgrammChecks checker;
   WorkWithFiles filesObj;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   string productType;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду изделия--" << endl;
   cout << "Введите вид изделия: ";
   productType = checker.checkString(productType);
   tableObj.headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getProductType() == productType) {
           count++;
           cout << "| "
                    << setw(3) << ++a<< " | "
           << setw(20) << jewelryProducts.at(i).getProductType()  << setw(8) << " | "
           << setw(17) << jewelryProducts.at(i).getMetall() << setw(7) << " | "
           << setw(13) << jewelryProducts.at(i).getMetallSample() << setw(15) << " | "
           << setw(6) << jewelryProducts.at(i).getPrice() << setw(8) << " | "
           << setw(8) << jewelryProducts.at(i).getAmount() << setw(10) << " | "
                    << setw(10) << jewelryProducts.at(i).getBrand() << setw(3) << " |"
                    << endl
                    << "|=======================================================================================================================|" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void SearchProducts::searchMetall() {// поиск по виду металла
   WorkWithFiles filesObj;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   Tables tableObj;
   ProgrammChecks checker;
   string metall;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду металла--" << endl;
   cout << "Введите вид металла: ";
   metall = checker.checkString(metall);
   tableObj.headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getMetall() == metall) {
           count++;
           cout << "| "
                    << setw(3) << ++a<< " | "
           << setw(20) << jewelryProducts.at(i).getProductType()  << setw(8) << " | "
           << setw(17) << jewelryProducts.at(i).getMetall() << setw(7) << " | "
           << setw(13) << jewelryProducts.at(i).getMetallSample() << setw(15) << " | "
           << setw(6) << jewelryProducts.at(i).getPrice() << setw(8) << " | "
           << setw(8) << jewelryProducts.at(i).getAmount() << setw(10) << " | "
                    << setw(10) << jewelryProducts.at(i).getBrand() << setw(3) << " |"
                    << endl
                    << "|=======================================================================================================================|" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void SearchProducts::searchPrice() {//поиск по цене
   WorkWithFiles filesObj;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   Tables tableObj;
    ProgrammChecks checker;
   int price;
   int count = 0;
   int a = 0;
   cout << "--Поиск по цене--" << endl;
   cout << "Введите цену: ";
   price = checker.inputNumber(0, 10000);
    tableObj.headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getPrice() == price) {
           count++;
            
           cout << "| "
                    << setw(3) << ++a<< " | "
           << setw(20) << jewelryProducts.at(i).getProductType()  << setw(8) << " | "
           << setw(17) << jewelryProducts.at(i).getMetall() << setw(7) << " | "
           << setw(13) << jewelryProducts.at(i).getMetallSample() << setw(15) << " | "
           << setw(6) << jewelryProducts.at(i).getPrice() << setw(8) << " | "
           << setw(8) << jewelryProducts.at(i).getAmount() << setw(10) << " | "
                    << setw(10) << jewelryProducts.at(i).getBrand() << setw(3) << " |"
                    << endl
                    << "|=======================================================================================================================|" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }


}
void SearchProducts::searchAmount() {//поиск по количеству
    WorkWithFiles filesObj;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
    ProgrammChecks checker;
   int amount;
   Tables tableObj;
   int count = 0;
   int a = 0;
   cout << "--Поиск по количеству товара в наличии--" << endl;
   cout << "Введите количество товара в наличии: ";
   amount = checker.inputNumber(0, 100);
    tableObj.headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getAmount() == amount) {
           count++;
            
           cout << "| "
                    << setw(3) << ++a<< " | "
           << setw(20) << jewelryProducts.at(i).getProductType()  << setw(8) << " | "
           << setw(17) << jewelryProducts.at(i).getMetall() << setw(7) << " | "
           << setw(13) << jewelryProducts.at(i).getMetallSample() << setw(15) << " | "
           << setw(6) << jewelryProducts.at(i).getPrice() << setw(8) << " | "
           << setw(8) << jewelryProducts.at(i).getAmount() << setw(10) << " | "
                    << setw(10) << jewelryProducts.at(i).getBrand() << setw(3) << " |"
                    << endl
                    << "|=======================================================================================================================|" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }


}
void SearchProducts::searcMetallSample() {//поиск по пробе металла
    WorkWithFiles filesObj;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   int metallSample;
   Tables tableObj;
    ProgrammChecks checker;
   int count = 0;
   int a = 0;
   cout << "--Поиск по пробе металла--" << endl;
   cout << "Введите пробу металла: ";
   metallSample = checker.inputNumber(375, 950);
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getMetallSample() == metallSample) {
           count++;
           tableObj.headTable();
           cout << "| "
                    << setw(3) << ++a<< " | "
           << setw(20) << jewelryProducts.at(i).getProductType()  << setw(8) << " | "
           << setw(17) << jewelryProducts.at(i).getMetall() << setw(7) << " | "
           << setw(13) << jewelryProducts.at(i).getMetallSample() << setw(15) << " | "
           << setw(6) << jewelryProducts.at(i).getPrice() << setw(8) << " | "
           << setw(8) << jewelryProducts.at(i).getAmount() << setw(10) << " | "
                    << setw(10) << jewelryProducts.at(i).getBrand() << setw(3) << " |"
                    << endl
                    << "|=======================================================================================================================|" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void SearchProducts::searchBrand() {// поиск по коллекции
    WorkWithFiles filesObj;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   string brand;
   Tables tableObj;
   ProgrammChecks checker;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду металла--" << endl;
   cout << "Введите вид металла: ";
   brand = checker.checkString(brand);
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getBrand() == brand) {
           count++;
           tableObj.headTable();
           cout << "| "
                    << setw(3) << ++a<< " | "
           << setw(20) << jewelryProducts.at(i).getProductType()  << setw(8) << " | "
           << setw(17) << jewelryProducts.at(i).getMetall() << setw(7) << " | "
           << setw(13) << jewelryProducts.at(i).getMetallSample() << setw(15) << " | "
           << setw(6) << jewelryProducts.at(i).getPrice() << setw(8) << " | "
           << setw(8) << jewelryProducts.at(i).getAmount() << setw(10) << " | "
                    << setw(10) << jewelryProducts.at(i).getBrand() << setw(3) << " |"
                    << endl
                    << "|=======================================================================================================================|" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void Menu::menuSearch() {//поиск товаров
   SearchProducts searchObj;
    WorkWithFiles filesObj;
    ProgrammChecks checker;
   cout << "--------------Введите--------------" << endl;
   int choice;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   cout << "1 - для поиска по цене" << endl;
   cout << "2 - для поиска по количеству" << endl;
   cout << "3 - для поиска по виду изделия" << endl;
   cout << "4 - для поиска по виду металла" << endl;
   cout << "5 - для поиска по пробе металла" << endl;
   cout << "6 - для поиска по названию коллекции" << endl;
   cout << "Ваш выбор:  ";
   choice = checker.inputNumber(1, 6);
   switch (choice) {
   case 1: {
       searchObj.searchPrice();//поиск по цене
       break;

   }
   case 2: {
       searchObj.searchAmount(); //поиск по количеству
       break;
   }
   case 3: {
       searchObj.searchProductType(); //поиск по виду изделия
       break;
   }
   case 4: {
       searchObj.searchMetall(); //поиск по виду металла
       break;
   }
   case 5: {
       searchObj.searcMetallSample(); //поиск по пробе металла
       break;
   }
   case 6: {
       searchObj.searchBrand(); //поиск по пробе металла
       break;
   }
   }
}

void Menu::menuSort() {//меню сортировки
   Tables tableObj;
   SortProducts sortObj;
    WorkWithFiles filesObj;
    ProgrammChecks checker;
   vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
   vector<Jewelry> jewelry_temp;
   jewelry_temp = jewelryProducts;
   int choice;
   cout << "---—Введите---" << endl;
   cout << "1 - для сортировки по цене " << endl;
   cout << "2 - для сортировки по количеству товара в наличии " << endl;
   cout << "3 - для сортировки по пробе металла" << endl;
   cout << "4 - для сортировки по виду металла" << endl;
   cout << "Ваш выбор:" << endl;
   choice = checker.inputNumber(1, 4);
   switch (choice) {
   case 1: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), bind(&SortProducts::isSortByPrice, &sortObj, placeholders::_1, placeholders::_2));
       break;
   }
   case 2: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), bind(&SortProducts::isSortByAmount, &sortObj, placeholders::_1, placeholders::_2));
       break;
   }
   case 3: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), bind(&SortProducts::isSortByMetallSample, &sortObj, placeholders::_1, placeholders::_2));
       break;
   }
   case 4: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), bind(&SortProducts::isSortByMetall, &sortObj, placeholders::_1, placeholders::_2));
       break;
   }
   }
   cout << "--Успешно отсортировано--" << endl;
   tableObj.printJewelryTable(jewelry_temp);

}

bool SortProducts::isSortByPrice(Jewelry price_a, Jewelry price_b){//сортировка по цене
 return price_a.getPrice() < price_b.getPrice();
}

bool SortProducts::isSortByAmount(Jewelry amount_a, Jewelry amount_b){//сортировка по количеству в наличии
 return amount_a.getAmount() < amount_b.getAmount();
}

bool SortProducts::isSortByMetallSample(Jewelry sample_a, Jewelry sample_b){//сортировка по пробе металла
 return sample_a.getMetallSample() < sample_b.getMetallSample();
}

bool SortProducts::isSortByMetall(Jewelry metall_a, Jewelry metall_b){//сортировка по виду металла
 return metall_a.getMetall() < metall_b.getMetall();
}


void Menu::menuWorkWithJewelry() {//меню для работы с товарами
   Tables tableObj;
   WorkWithProducts prObj;
    WorkWithFiles filesObj;
    ProgrammChecks checker;
   while (1) {
       cout << "--------------Введите--------------" << endl;
       int choice;
       vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
       cout << "1 - для отображения перечня ювелирных изделий" << endl;
       cout << "2 - для добавления товара" << endl;
       cout << "3 - для редактирования товара" << endl;
       cout << "4 - для удаления товара" << endl;
       cout << "5 - для поиска товара" << endl;
       cout << "6 - для сортировки товаров" << endl;
       cout << "7 - для вывода выручки и количества проданных товаров" << endl;
       cout << "8 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = checker.inputNumber(1, 8);
       switch (choice) {
       case 1: {
           tableObj.printJewelryTable(jewelryProducts);
           break;
       }
       case 2: {
           prObj.addJewelry();
           break;
       }
       case 3: {
           prObj.editJewelry();
           break;
       }
       case 4: {
           prObj.deleteJewelry();
           break;
       }
       case 5: {
           menuSearch();
           break;
       }
       case 6: {
           menuSort();
           break;
       }
       case 7: {
           prObj.printTotalRevenue(jewelryProducts);
           break;
       }
           case 8:{
               return;
           }
               
       }
   }
}

void Menu::menuUser() {//меню пользователя
    Tables tableObj;
    WorkWithProducts prObj;
    WorkWithFiles filesObj;
    ProgrammChecks checker;
    int choice;
   do {
        
       vector<Jewelry> jewelryProducts = filesObj.readJewelryFromFile();
       cout << "--------------МЕНЮ ПОЛЬЗОВАТЕЛЯ--------------" << endl;
       cout << "Введите:" << endl;
       cout << "1 - для просмотра данных" << endl;
       cout << "2 - для поиска данных" << endl;
       cout << "3 - для сортировки данных" << endl;
       cout << "4 - для оформления заказа или предзаказа" << endl;
       cout << "5 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice=checker.inputNumber(1,5);
       switch (choice)
       {
       case 1: {
           tableObj.printJewelryTable(jewelryProducts);
           break;
       }
       case 2: {
           menuSearch();
           break;
       }
       case 3: {
           menuSort();
           break;
       }
       case 4: {
           prObj.orderProduct();
           break;
       }
       case 5: {
           break;
       }
       }
   }while(choice!=5);
}

void Menu::menuAdministrator() {//меню администратора
    ProgrammChecks checker;
    int choice;
   do {
    
       cout << "--------------МЕНЮ АДМИНИСТРАТОРА--------------" << endl;
       cout << "Введите:" << endl;
       cout << "1 - для работы с учетными записями" << endl;
       cout << "2 - для работы с данными" << endl;
       cout << "3 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice=checker.inputNumber(1,5);
       switch (choice) {
       case 1: {
           menuWorkWithUser();
           break;
       }
       case 2: {
           menuWorkWithJewelry();
           break;
       }
       case 3: {
           return;
       }
       }
   }while(choice!=3);
}

bool EnterSystem::checkLoginAndPassword(std::vector<User>& users, std::string login, std::string password) {//проверка логина и пароля
    Menu menuObj;
    WorkWithFiles fileObj;
    int found=0;
   for (auto& user : users) {
       if (user.getLogin() == login && user.getPassword() == password) {
           found=1;
           std::cout << "Добро пожаловать, " << user.getLogin() << "!" << std::endl;
           if (user.getIsAdmin() == 0) {
               menuObj.menuUser();
           }
           if (user.getIsAdmin() == 1) {
               menuObj.menuAdministrator();
           }
           return true;
       }
   }
    
    vector<User>accounts = fileObj.readAccountsFromFile();
    for(auto& account:accounts)
    {
        if(account.getLogin()==login && account.getPassword()==password)
        {
            found=1;
            cout<<"Ваша заявка на регистрацию еще не подтверждена."<<endl;
            return false;
        }
    }
     
    if(found==0)
    {
        cout<<"Неверный логин или пароль. Попробуйте снова"<<endl;
    }
    
   return false;
}

bool EnterSystem::checkLoginAndPasswordRegist(std::vector<User>& users, std::string login, std::string password, bool isAdmin) {//проверка на существование пользователя
   for (auto& user : users) {
       if (user.getLogin() == login && user.getPassword() == password && user.getIsAdmin() == isAdmin) {
           std::cout << "Такой пользователь уже существует" << endl;
           return false;
       }
       if (user.getLogin() == login) {
           std::cout << "Пользователь с таким логином уже существует" << endl;
           return false;
       }
   }
   return true;
}

 

void EnterSystem::authorization() {//авторизация
 
    WorkWithFiles filesObj;
    
    cout << "Авторизация:" << std::endl;
         string login, password;
        // Ваша функция для чтения пользователей из файла
         bool isLoggedIn = false;

         while (!isLoggedIn) {
             cout << "Введите логин:  ";
             cin >> login;
                     
             cout << "Введите пароль: ";
             cin >> password;

             vector<User> users = filesObj.readUsersFromFile();
             if (checkLoginAndPassword(users, login, password))
             {
                 isLoggedIn = true;
                 }
             /*else
             {
                 std::cout << "Неверный логин или пароль. Попробуйте снова." << std::endl;
             }*/
         }
       /*string login, password;
       vector<User> accounts = filesObj.readAccountsFromFile();
       vector<User> users = filesObj.readUsersFromFile();
       bool isLoggedIn = false;
       int choice=0;

       while (!isLoggedIn) {
           cout << "Введите логин:  ";
           cin >> login;
                   
           cout << "Введите пароль: ";
           cin >> password;

           if (checkLoginAndPassword(users, login, password) )
           {
               isLoggedIn = true;
            }
           else if (checkLoginAndPassword(accounts, login, password))
           {
               cout<<"Администратор пока что не подтвердил вашу заявку на вход в систему. Попробуйте в другой раз";
               return;
           }
            
           else
           {
               std::cout << "Неверный логин или пароль. Введите:" << std::endl;
               std::cout << "1 - чтобы попробовать снова" << std::endl;
               std::cout << "2 - чтобы выйти в главное меню" << std::endl;
               cin >> choice;
               switch(choice)
               {
                   case 1:
                   {
                       break;
                   }
                   case 2:
                   {
                       return;
                   }
               }
           }
       }*/

}


void EnterSystem::registration() {//регистрация
    ProgrammChecks checker;
    WorkWithFiles filesObj;
    cout << "Регистрация:" << endl;
       string login, password;
       bool isAdmin;
       vector<User> accounts = filesObj.readAccountsFromFile();
       vector<User> users = filesObj.readUsersFromFile();
       while (true) {
           cout << "Введите логин" << endl;
           login = checker.checkSize(login);
           cout << "Введите пароль" << endl;
           password = checker.checkSize(password);
           cout << "Является ли админом (1/0)" << endl;
           isAdmin = checker.inputNumber(0, 1);
           if (checkLoginAndPasswordRegist(accounts, login, password, isAdmin)&& checkLoginAndPasswordRegist(users, login, password, isAdmin)) {
               break;
           }
       }
           User account;
           account.setLogin(login);
           account.setPassword(password);
           account.setIsAdmin(isAdmin);
           accounts.push_back(account);
           filesObj.writeAccountsToFile(accounts);
           cout << "Ваша заявка на регистрацию отправлена, ожидайте ответ администратора" << endl;
}


string EnterSystem::encrypt(string input) {//шифровка
   string output(input.size(), ' ');
   for (int i = 0; i < input.size(); i++) {
       output[i] = (char)((int)input[i] + 3) % 256;
   }
   return output;
}

string EnterSystem::decrypt(string input) {//дешифровка
   string output(input.size(), ' ');
   for (int i = 0; i < input.size(); i++) {
       output[i] = (char)((int)input[i] - 3) % 256;
   }
   return output;
}
