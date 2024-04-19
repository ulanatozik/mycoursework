


#include "Header.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>



std::string global_login;

string checkSize(string s){//проверка на размер строки
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

string checkString(string s)//проверка на ввод строки
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

bool isNumberNumeric()//проверка на ввод числа
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

bool isNumberRangeCorrect(int number, int left_range, int right_range)//проверка на выход за границы
{
   if ((number >= left_range) && (number <= right_range)) return true;
   else return false;
}

int inputNumber(int left_range, int right_range) {//ввод числа
   int number;
   while (true)
   {
       cin >> number;
       if(isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range)){
           return number;
       }
       else{
           cout << "Некорректный ввод. Повторите попытку ";
       }
            
   }
}

void start_menu() {//начальное меню
    int choice;
    do{
         
        cout << "-------Введите-------- \n 1. Для регистрации \n 2. Для авторизации\n 3. Для выхода \n";
        cout << "Ваш выбор?" <<endl;
        choice = inputNumber(1, 3);
        switch (choice) {
            case 1: {
                registration();
                sleep(3);
                break;
            }
            case 2: {
                authorization();
                break;
            }
            case 3: {
                cout<<"Совершен выход из программы.";
                break;
                
            }
        }
    }while(choice!=3);

   }


void writeUsersToFile(const vector<User>& users) {//запись пользователей в файл
   string filename = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/users.txt";
   std::ofstream outputFile(filename);

   if (!outputFile.is_open()) {
       std::cerr << "Ошибка открытия файла " << filename << "для записи" << std::endl;
       return;
   }

   for (const User& user : users) {
       outputFile << user.getLogin() << " " << encrypt(user.getPassword()) << " " << user.getIsAdmin() << std::endl;
   }

   outputFile.close();
}


vector<User> readAccountsFromFile() {//достать пользователей из файла в вектор
   string fileName = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/accounts.txt";
   std::vector<User> accounts;
   std::ifstream inFile(fileName);
   if (inFile.is_open()) {
       std::string login, password, isAdminStr;
       while (inFile >> login >> password >> isAdminStr) {
           bool isAdmin = (isAdminStr == "1");
           User newUser;
           newUser.setLogin(login);
           newUser.setPassword(decrypt(password));
           newUser.setIsAdmin(isAdmin);
           accounts.push_back(newUser);
       }
       inFile.close();
   }
   else {
       std::cerr << "Невозможно открыть файл " << fileName << std::endl;
   }
   return accounts;
}

void printAccountsTable(const std::vector<User>& accounts) {//вывод таблицы аккаунтов
   // вывод заголовка таблицы
    cout << "--------------------------------------------------------" << endl;
        cout << "|" << setw(3) << "№" << "|" << setw(10) << "Логин" << " | "
             << setw(10) << "Пароль" << " | " << setw(7) << "Админ" << "|" << endl;
        cout << "--------------------------------------------------------" << endl;
        int i = 0;
    //вывод строк таблицы
        for (const auto& account : accounts) {
            cout << "|" << setw(3) << ++i << "|" << setw(10) << account.getLogin() << " | "
                 << setw(10) << account.getPassword() << " | "
                 << setw(7) << (account.getIsAdmin() ? "Да" : "Нет") << "|" << endl;
            cout << "--------------------------------------------------------" << endl;
        }
}

vector<User> readUsersFromFile() {//достать пользователей из файла в вектор
   string fileName = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/users.txt";
   std::vector<User> users;
   std::ifstream inFile(fileName);
   if (inFile.is_open()) {
       std::string login, password, isAdminStr;
       while (inFile >> login >> password >> isAdminStr) {
           bool isAdmin = (isAdminStr == "1");
           User newUser;
           newUser.setLogin(login);
           newUser.setPassword(decrypt(password));
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

 

vector<Jewelry> readJewelryFromFile() {//достать записи из файла в вектор
   string fileName = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/jewelrypr.txt";
   vector<Jewelry> jewelryProducts;
   ifstream inputFile(fileName);
   if (inputFile.is_open()) {
        
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

void writeAccountsToFile(const vector<User>& accounts) {//Запись аккаунтов в файл
   string filename = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/accounts.txt";
   std::ofstream outputFile(filename);

   if (!outputFile.is_open()) {
       std::cerr << "Ошибка открытия файла" << filename << " для записи" << std::endl;
       return;
   }

   for (const User& account : accounts) {
       outputFile << account.getLogin() << " " << encrypt(account.getPassword()) << " " << account.getIsAdmin() << endl;
   }

   outputFile.close();
}

void writeJewelryToFile( std::vector<Jewelry>& jewelryProducts) {//запись товаров в файл
   string filename = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/jewelrypr.txt";
   std::ofstream outputFile(filename);

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

void printUsersTable(const std::vector<User>& users)
{//Вывод таблицы аккаунтов
   // Вывод заголовка таблицы
   cout << "---------------------------------------" << endl;
   cout << "|" << setw(5) << "№" << "|" << setw(15) << "Логин" << " | "
       << setw(16) << "Пароль" << " | "
       << setw(10) << "Админ" << "|" << endl;
   cout << "---------------------------------------" << endl;
   int i = 0;
   // Вывод строк таблицы
   for (const auto& user : users) {
       cout << "|" << setw(3) << ++i << "|" << setw(10) << user.getLogin() << " | "
           << setw(10) << encrypt(user.getPassword()) << " | "
           << setw(7) << (user.getIsAdmin() ? "Да" : "  Нет") << "|" << endl;
       cout << "---------------------------------------" << endl;
   }
}

void printJewelryTable(std::vector<Jewelry>& jewelryProducts) {//вывод таблицы товаров
    headTable();
   int i = 0;
   for (const auto& jewelry : jewelryProducts) {
       cout<<"| ";
       cout << left << setw(4) << ++i;
       cout<<" | ";
           cout << left << setw(17) << jewelry.getProductType();
       cout<<" | ";
           cout << left << setw(20) << jewelry.getMetall();
       cout<<" | ";
           cout << left << setw(15) << jewelry.getMetallSample();
       cout<<" | ";
           cout << left << setw(10) << jewelry.getPrice();
       cout<<" | ";
           cout << left << setw(13) << jewelry.getAmount();
       cout<<" | ";
           cout << left << setw(13) << jewelry.getBrand();
       cout<<" |"<<endl;
        
       cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }


void headTable() {//шапка таблицы товаров
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
         
    cout<<"| ";
    cout << left << setw(6) << "№";
    cout<<" | ";
        cout << left << setw(20) << "Вид изделия";
    cout<<" | ";
        cout << left << setw(20) << "Металл";
    cout<<" | ";
        cout << left << setw(27) << "Проба металла ";
    cout<<" | ";
        cout << left << setw(14) << "Цена";
    cout<<" | ";
        cout << left << setw(23) << "Количество";
    cout<<" | ";
        cout << left << setw(22) << "Бренд";
    cout<<" |"<<endl;
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

void approve() {//одобрение заявки
 
   vector<User> accounts = readAccountsFromFile();
   vector<User> users = readUsersFromFile();
   cout << "---Заявки на регистрацию---" << endl;
   printAccountsTable(accounts);
   int number_for_add, choice;
   cout << "---Выберите---" << endl;
   cout << "1 - Для одобрения заявки" << endl;
   cout << "2 - Для выхода" << endl;
   choice = inputNumber(1, 2);
   switch (choice) {
   case 1: {
       cout << "Выберите номер заявки, которую хотите одобрить" << endl;
       number_for_add = inputNumber(1, accounts.size());
       User user;
       user.setLogin(accounts.at(number_for_add - 1).getLogin());
       user.setPassword(accounts.at(number_for_add - 1).getPassword());
       user.setIsAdmin(accounts.at(number_for_add - 1).getIsAdmin());
       users.push_back(user);
       writeUsersToFile(users);
       cout << "Вы одобрили заявку" << endl;
       accounts.erase(accounts.begin() + number_for_add - 1);
       writeAccountsToFile(accounts);
       break;
   }
   case 2: {
       return;
   }
   }
}
 

void addJewelry() {//добавить товар

   cout << "Добавить товар:" << endl;
   string productType, metall, brand;
   int price, amount, metallSample;

   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   while (true) {
       cout << "Введите вид ювелирного изделия:" << endl;
       productType = checkString(productType);
       cout << "Введите вид металла:" << endl;
       metall = checkString(metall);
       cout << "Введите пробу металла (1. 375, 2. 500, 3. 750, 4. 958):" << endl;
       int validSamples[] = {375, 500, 750, 958};
       int sampleIndex = inputNumber(0, 3);
       while (validSamples[sampleIndex] != 375 && validSamples[sampleIndex] != 500 &&
       validSamples[sampleIndex] != 750 && validSamples[sampleIndex] != 958)
       {
            cout << "Выбранная проба металла недопустима. Пожалуйста, выберите снова:" << endl;
            sampleIndex = inputNumber(0, 3);
       }
       metallSample = validSamples[sampleIndex];
       cout << "Введите цену за 1 единицу товара:" << endl;
       price = inputNumber(1, 10000);
       cout << "Введите количество данного товара в наличии:" << endl;
       amount = inputNumber(0, 100);
       cout << "Введите бренд товара:" << endl;
       brand = checkString(brand);
       break;
   }
   Jewelry jewelry;
   jewelry.setProductType(productType);
   jewelry.setMetall(metall);
   jewelry.setMetallSample(metallSample);
   jewelry.setPrice(price);
   jewelry.setAmount(amount);
   jewelry.setBrand(brand);
   jewelryProducts.push_back(jewelry);
   writeJewelryToFile(jewelryProducts);
   printJewelryTable(jewelryProducts);
}

void addaccount() {//Добавить аккаунт
  
   cout << "Добавить аккаунт" << endl;
   string login, password;
   bool isAdmin;
   vector<User> users = readUsersFromFile();
   while (true) {
       cout << "Введите логин" << endl;
       cin >> login;
       cout << "Введите пароль" << endl;
       cin >> password;
       cout << "Является ли админом (1/0)" << endl;
       isAdmin = inputNumber(0,1);
       if (checkLoginAndPasswordRegist(users, login, password, isAdmin)) {
           break;
       }
   }
   User user;
   user.setLogin(login);
   user.setPassword(password);
   user.setIsAdmin(isAdmin);


   users.push_back(user);
   writeUsersToFile(users);
}

void deleteJewelry() {//удалить товар
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   printJewelryTable(jewelryProducts);
   int number_for_delete;
   cout << "----Удаление товара---" << endl << endl;
   cout << "Введите номер товара, который хотите удалить" << endl;
   number_for_delete = inputNumber(1, jewelryProducts.size());
   int yes_or_no;
   cout << "1. Да" << endl
       << "2. Нет" << endl
       << "Ваш выбор?" << endl;
   yes_or_no = inputNumber(1, 2);
   if (yes_or_no == 1) {
       jewelryProducts.erase(jewelryProducts.begin() + number_for_delete - 1);
       cout << "----Товар успешно удален----" << endl;
       writeJewelryToFile(jewelryProducts);
   }
   else cout << "Вы отменили удаление" << endl;
}

void deleteAccount() {//удалить аккаунт
   vector<User> users = readUsersFromFile();
   printUsersTable(users);
   int number_for_delete;
   int Count = 0;
   int num = 0;
   cout << "----Удаление учетной записи----" << endl << endl;;
   cout << "Введите номер аккаунта, который хотите удалить" << endl;
   number_for_delete = inputNumber(1, users.size());
   cout << "Вы уверены, что хотите удалить аккаунт?" << endl;
   int yes_or_no;
   cout << "1. Да" << endl
       << "2. Нет" << endl
       << "Ваш выбор:" << endl;
   yes_or_no = inputNumber(1, 2);
   if (yes_or_no == 1) {
       for (int i = 0; i < users.size(); i++) {
           if (users.at(i).getIsAdmin() == 1) {
               Count++;
               num = i;
           }
       }
       if (Count > 1) {
           users.erase(users.begin() + number_for_delete - 1);
           cout << "----Аккаунт успешно удален----" << endl;
           writeUsersToFile(users);
       }
       else if (Count == 1 && users.at(number_for_delete - 1).getIsAdmin() != 1) {
           users.erase(users.begin() + number_for_delete - 1);
           cout << "----Аккаунт успешно удален----" << endl;
           writeUsersToFile(users);
       }
       else cout << "Удалить свой аккаунт невозможно" << endl;
   }
   else cout << "Вы отменили удаление" << endl;

}

void editJewelry() { //редактирование товара
   int choice;
    
   do {
       vector<Jewelry> jewelryProducts = readJewelryFromFile();
       printJewelryTable(jewelryProducts);
       string productType, metall, brand;
       int newPrice, newAmount, number_for_edit;
       cout << "Введите номер товара, который хотите изменить " << endl;
       number_for_edit = inputNumber(1, jewelryProducts.size());
       cout << "--------------Введите--------------" << endl;
       cout << "1 - Чтобы изменить вид изделия" << endl;
       cout << "2 - Чтобы изменить количество товара в наличии" << endl;
       cout << "3 - Чтобы изменить коллекцию, к которой принадлежит товар" << endl;
       cout << "4 - Чтобы изменить цену товара" << endl;
       cout << "5 - Чтобы выйти из режима редактирования" << endl;
       cout << "Ваш выбор: ";
        
       choice = inputNumber(1, 5);
       switch (choice) {
       case 1: {
           cout << "--Изменение вида изделия--" << endl;
           cout << setw(5) << "Новый вид изделия:" << endl;
           string newProductType = checkString(productType);
           jewelryProducts.at(number_for_edit - 1).setProductType(newProductType);
           writeJewelryToFile(jewelryProducts);
           cout << "--Вид изделия изменен--" << endl;
           break;
       }
       case 2: {
           cout << "--Изменение количества товара в наличии--" << endl;
           cout << setw(5) << "Новое количество: " << endl;
           newAmount = inputNumber(1, 100);
           jewelryProducts.at(number_for_edit - 1).setAmount(newAmount);
           writeJewelryToFile(jewelryProducts);
           cout << "--Количество товара изменено--" << endl;
           break;
       }
       case 3: {
           cout << "--Изменение коллекции--" << endl;
           cout << setw(5) << "Новая коллекция:" << endl;
           string newBrand = checkString(brand);
           jewelryProducts.at(number_for_edit - 1).setBrand(newBrand);
           writeJewelryToFile(jewelryProducts);
           cout << "--Коллекция изменен--" << endl;
           break;
       }
       case 4: {
           cout << "--Изменение цены товара--" << endl;
           newPrice = inputNumber(1, 10000);
           jewelryProducts.at(number_for_edit - 1).setPrice(newPrice);
           writeJewelryToFile(jewelryProducts);
           cout << "--Цена товара изменена--" << endl;
           break;
       }
       case 5: {
           break;
       }

       }

   }while(choice!=5);
}

void editAccount() {//редактирование аккаунтов
    int choice;
    do{
        vector<User> users = readUsersFromFile();
        printUsersTable(users);
        int i = 0;    
        int number_for_edit;
        string newLogin;
        cout << "Введите номер аккаунта, который хотите изменить: " << endl;
        number_for_edit = inputNumber(1, users.size());
        cout << "--------------Введите--------------" << endl;
        cout << "1 - Чтобы изменить логин" << endl;
        cout << "2 - Чтобы изменить роль пользователя" << endl;
        cout << "3 - Чтобы редактировать все данные аккаунта" << endl;
        cout << "4 - Чтобы выйти из режима редактирования" << endl;
        cout << "Ваш выбор: ";
        choice = inputNumber(1, 4);
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
                    writeUsersToFile(users);
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
                users.at(number_for_edit - 1).setIsAdmin(inputNumber(0, 1));
                writeUsersToFile(users);
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
                     users.at(number_for_edit - 1).setIsAdmin(inputNumber(0, 1));
                     writeUsersToFile(users);
                     cout << "---Успешно отредактировано---" << endl;
                 break;
                 }
            case 4:{
                break;
            }
            }
                
    }while(choice!=4);
}
    
       

void menuWorkWithUser() { //меню для работы с учетными записями
   int choice;
   do {
       cout << "--------------Введите--------------" << endl;
       vector<User> users = readUsersFromFile();
       cout << "1 - для вывода учетных записей" << endl;
       cout << "2 - чтобы добавить учетную запись" << endl;
       cout << "3 - для редактирования учетных записей" << endl;
       cout << "4 - чтобы удалить учетную запись" << endl;
       cout << "5 - для одобрения заявок на регистрацию" << endl;
       cout << "6 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = inputNumber(1, 6);
       switch (choice) {
       case 1: {
           printUsersTable(users);
           break;
       }
       case 2: {
           addaccount();
           break;
       }
       case 3: {
           editAccount();
           break;
       }
       case 4: {
           deleteAccount();
           break;
       }
       case 5: {
           approve();
       }
       case 6: {
           break;
       }
       default:cout<<"Введено некорректное значение. Попробуйте снова.";
       }
   }while(choice!=6);
}

void individualTask() {
    vector<Jewelry> jewelryProducts = readJewelryFromFile();
    cout << "--Заказ товара--" << endl;
    cout << "Введите номер товара, который хотите заказать: "<<endl;
    printJewelryTable(jewelryProducts);
    int choice;
    int choice2;
    int choice3;
 
    choice=inputNumber(1, jewelryProducts.size())-1;
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
    writeJewelryToFile(jewelryProducts);
}


void printTotalRevenue(const std::vector<Jewelry>& jewelryProducts) { //подсчёт общего числа выручки и количества проданных товаров
        int totalSoldQuantity = 0;
        int totalRevenue = 0;
        int number=0;
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


void searchProductType() {//поиск по виду изделия
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   string productType;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду изделия--" << endl;
   cout << "Введите вид изделия: ";
   productType = checkString(productType);
   headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getProductType() == productType) {
           count++;
           cout<<"|";
           cout << left << setw(3) << ++a;
           cout<<" | ";
               cout << left << setw(17) << jewelryProducts.at(i).getProductType();
           cout<<" | ";
               cout << left << setw(20) << jewelryProducts.at(i).getMetall();
           cout<<" | ";
               cout << left << setw(15) << jewelryProducts.at(i).getMetallSample();
           cout<<" | ";
               cout << left << setw(10) << jewelryProducts.at(i).getPrice();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getAmount();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getBrand();
           cout<<" |"<<endl;
            
           cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchMetall() {// поиск по виду металла
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   string metall;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду металла--" << endl;
   cout << "Введите вид металла: ";
   metall = checkString(metall);
   headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getMetall() == metall) {
           count++;
           cout<<"|";
           cout << left << setw(3) << ++a;
           cout<<" | ";
               cout << left << setw(17) << jewelryProducts.at(i).getProductType();
           cout<<" | ";
               cout << left << setw(20) << jewelryProducts.at(i).getMetall();
           cout<<" | ";
               cout << left << setw(15) << jewelryProducts.at(i).getMetallSample();
           cout<<" | ";
               cout << left << setw(10) << jewelryProducts.at(i).getPrice();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getAmount();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getBrand();
           cout<<" |"<<endl;
            
           cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchPrice() {//поиск по цене
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   int price;
   int count = 0;
   int a = 0;
   cout << "--Поиск по цене--" << endl;
   cout << "Введите цену: ";
   price = inputNumber(0, 10000);
    
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getPrice() == price) {
           count++;
           headTable();
           cout<<"|";
           cout << left << setw(3) << ++a;
           cout<<" | ";
               cout << left << setw(17) << jewelryProducts.at(i).getProductType();
           cout<<" | ";
               cout << left << setw(20) << jewelryProducts.at(i).getMetall();
           cout<<" | ";
               cout << left << setw(15) << jewelryProducts.at(i).getMetallSample();
           cout<<" | ";
               cout << left << setw(10) << jewelryProducts.at(i).getPrice();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getAmount();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getBrand();
           cout<<" |"<<endl;
            
           cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }


}
void searchAmount() {//поиск по количеству
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   int amount;
   int count = 0;
   int a = 0;
   cout << "--Поиск по количеству товара в наличии--" << endl;
   cout << "Введите количество товара в наличии: ";
   amount = inputNumber(0, 100);
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getAmount() == amount) {
           count++;
           headTable();
           cout<<"|";
           cout << left << setw(3) << ++a;
           cout<<" | ";
               cout << left << setw(17) << jewelryProducts.at(i).getProductType();
           cout<<" | ";
               cout << left << setw(20) << jewelryProducts.at(i).getMetall();
           cout<<" | ";
               cout << left << setw(15) << jewelryProducts.at(i).getMetallSample();
           cout<<" | ";
               cout << left << setw(10) << jewelryProducts.at(i).getPrice();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getAmount();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getBrand();
           cout<<" |"<<endl;
            
           cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }


}
void searcMetallSample() {//поиск по пробе металла
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   int metallSample;
   int count = 0;
   int a = 0;
   cout << "--Поиск по пробе металла--" << endl;
   cout << "Введите пробу металла: ";
   metallSample = inputNumber(375, 950);
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getMetallSample() == metallSample) {
           count++;
           headTable();
           cout<<"|";
           cout << left << setw(3) << ++a;
           cout<<" | ";
               cout << left << setw(17) << jewelryProducts.at(i).getProductType();
           cout<<" | ";
               cout << left << setw(20) << jewelryProducts.at(i).getMetall();
           cout<<" | ";
               cout << left << setw(15) << jewelryProducts.at(i).getMetallSample();
           cout<<" | ";
               cout << left << setw(10) << jewelryProducts.at(i).getPrice();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getAmount();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getBrand();
           cout<<" |"<<endl;
            
           cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchBrand() {// поиск по коллекции
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   string brand;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду металла--" << endl;
   cout << "Введите вид металла: ";
   brand = checkString(brand);
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getBrand() == brand) {
           count++;
           headTable();
           cout<<"|";
           cout << left << setw(3) << ++a;
           cout<<" | ";
               cout << left << setw(17) << jewelryProducts.at(i).getProductType();
           cout<<" | ";
               cout << left << setw(20) << jewelryProducts.at(i).getMetall();
           cout<<" | ";
               cout << left << setw(15) << jewelryProducts.at(i).getMetallSample();
           cout<<" | ";
               cout << left << setw(10) << jewelryProducts.at(i).getPrice();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getAmount();
           cout<<" | ";
               cout << left << setw(13) << jewelryProducts.at(i).getBrand();
           cout<<" |"<<endl;
            
           cout << "----------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchJewelry() {//поиск товаров
   cout << "--------------Введите--------------" << endl;
   int choice;
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   cout << "1 - для поиска по цене" << endl;
   cout << "2 - для поиска по количеству" << endl;
   cout << "3 - для поиска по виду изделия" << endl;
   cout << "4 - для поиска по виду металла" << endl;
   cout << "5 - для поиска по пробе металла" << endl;
   cout << "6 - для поиска по названию коллекции" << endl;
   cout << "Ваш выбор:  ";
   choice = inputNumber(1, 6);
   switch (choice) {
   case 1: {
       searchPrice();//поиск по цене
       break;

   }
   case 2: {
       searchAmount(); //поиск по количеству
       break;
   }
   case 3: {
       searchProductType(); //поиск по виду изделия
       break;
   }
   case 4: {
       searchMetall(); //поиск по виду металла
       break;

   }
   case 5: {
       searcMetallSample(); //поиск по пробе металла
       break;
   }
   case 6: {
       searchBrand(); //поиск по пробе металла
       break;
   }
   }
}

void menuSort() {//меню сортировки
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   vector<Jewelry> jewelry_temp;
   jewelry_temp = jewelryProducts;
   int choice;
   cout << "---—Сортировка---" << endl;
   cout << "1 - по цене " << endl;
   cout << "2 - по количеству товара в наличии " << endl;
   cout << "3 - по виду металла" << endl;
   cout << "4 - по пробе металла" << endl;
   cout << "Ваш выбор:" << endl;
   choice = inputNumber(1, 4);
   switch (choice) {
   case 1: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), isSortByPrice);
       break;
   }
   case 2: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), isSortByAmount);
       break;
   }
   case 3: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), isSortByMetallSample);
       break;
   }
   case 4: {
       sort(jewelry_temp.begin(), jewelry_temp.end(), isSortByMetall);
       break;
   }
   }
   cout << "--Успешно отсортировано--" << endl;
   printJewelryTable(jewelry_temp);

}

bool isSortByPrice(Jewelry price_a, Jewelry price_b){//сортировка по цене
 return price_a.getPrice() < price_b.getPrice();
}

bool isSortByAmount(Jewelry amount_a, Jewelry amount_b){//сортировка по количеству в наличии
 return amount_a.getAmount() < amount_b.getAmount();
}

bool isSortByMetallSample(Jewelry sample_a, Jewelry sample_b){//сортировка по пробе металла
 return sample_a.getMetallSample() < sample_b.getMetallSample();
}

bool isSortByMetall(Jewelry metall_a, Jewelry metall_b){//сортировка по виду металла
 return metall_a.getMetall() < metall_b.getMetall();
}



void menuWorkWithJewelry() {//меню для работы с товарами
   while (1) {
       cout << "--------------Введите--------------" << endl;
       int choice;
       vector<Jewelry> jewelryProducts = readJewelryFromFile();
       cout << "1 - для отображения перечня ювелирных изделий" << endl;
       cout << "2 - для добавления товара" << endl;
       cout << "3 - для редактирования товара" << endl;
       cout << "4 - для удаления товара" << endl;
       cout << "5 - для поиска товара" << endl;
       cout << "6 - для сортировки товаров" << endl;
       cout << "7 - для вывода выручки и количества проданных товаров" << endl;
       cout << "8 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = inputNumber(1, 8);
       switch (choice) {
       case 1: {
           printJewelryTable(jewelryProducts);
           break;
       }
       case 2: {
           addJewelry();
           break;
       }
       case 3: {
           editJewelry();
           break;
       }
       case 4: {
           deleteJewelry();
           break;
       }
       case 5: {
           searchJewelry();
           break;
       }
       case 6: {
           menuSort();
           break;
       }
       case 7: {
           printTotalRevenue(jewelryProducts);
           break;
       }
           case 8:{
               return;
           }
               
       }
   }
}

void menuUser() {//меню пользователя
   while (1) {
       int choice;
       vector<Jewelry> jewelryProducts = readJewelryFromFile();
       cout << "--------------МЕНЮ ПОЛЬЗОВАТЕЛЯ--------------" << endl;
       cout << "Введите:" << endl;
       cout << "1 - для просмотра данных" << endl;
       cout << "2 - для поиска данных" << endl;
       cout << "3 - для сортировки данных" << endl;
       cout << "4 - для оформления заказа или предзаказа" << endl;
       cout << "5 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = inputNumber(1, 5);
       switch (choice)
       {
       case 1: {
           printJewelryTable(jewelryProducts);
           break;
       }
       case 2: {
           searchJewelry();
           break;
       }
       case 3: {
           menuSort();
           break;
       }
       case 4: {
           individualTask();
           break;
       }
       case 5: {
           return;
       }
       }
   }
}

void menuAdministrator() {//меню администратора
   while (1) {
       int choice;
       cout << "--------------МЕНЮ АДМИНИСТРАТОРА--------------" << endl;
       cout << "Введите:" << endl;
       cout << "1 - для работы с учетными записями" << endl;
       cout << "2 - для работы с данными" << endl;
       cout << "3 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = inputNumber(1, 3);
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
   }
}

bool checkLoginAndPassword(std::vector<User>& users, std::string login, std::string password) {//проверка логина и пароля
   for (auto& user : users) {
       if (user.getLogin() == login && user.getPassword() == password) {
           std::cout << "Добро пожаловать, " << user.getLogin() << "!" << std::endl;
           if (user.getIsAdmin() == 0) { menuUser(); }
           if (user.getIsAdmin() == 1) { menuAdministrator(); }
           return true;
       }
   }
   return false;
}

bool checkLoginAndPasswordRegist(std::vector<User>& users, std::string login, std::string password, bool isAdmin) {//проверка на существование пользователя
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

 

void authorization() {//авторизация
       
    cout << "Авторизация:" << std::endl;
       string login, password;
       vector<User> accounts = readAccountsFromFile(); // Ваша функция для чтения пользователей из файла
       bool isLoggedIn = false;

       while (!isLoggedIn) {
           cout << "Введите логин:  ";
           cin >> login;
                   
           cout << "Введите пароль: ";
           cin >> password;

           if (checkLoginAndPassword(accounts, login, password))
           {
               isLoggedIn = true;
               }
           else
           {
               std::cout << "Неверный логин или пароль. Попробуйте снова." << std::endl;
           }
       }

}


void registration() {//регистрация
    cout << "Регистрация:" << endl;
       string login, password;
       bool isAdmin;
       vector<User> accounts = readAccountsFromFile();
       vector<User> users = readUsersFromFile();
       while (true) {
           cout << "Введите логин" << endl;
           login = checkSize(login);
           cout << "Введите пароль" << endl;
           password = checkSize(password);
           cout << "Является ли админом (1/0)" << endl;
           isAdmin = inputNumber(0, 1);
           if (checkLoginAndPasswordRegist(accounts, login, password, isAdmin)&& checkLoginAndPasswordRegist(users, login, password, isAdmin)) {
               break;
           }
         
           
       }
      
           User account;
           account.setLogin(login);
           account.setPassword(password);
           account.setIsAdmin(isAdmin);
           accounts.push_back(account);
           writeAccountsToFile(accounts);
           cout << "Ваша заявка на регистрацию отправлена, ожидайте ответ администратора" << endl;
}


string encrypt(string input) {//шифровка
   string output(input.size(), ' ');
   for (int i = 0; i < input.size(); i++) {
       output[i] = (char)((int)input[i] + 3) % 256;
   }
   return output;
}

string decrypt(string input) {//дешифровка
   string output(input.size(), ' ');
   for (int i = 0; i < input.size(); i++) {
       output[i] = (char)((int)input[i] - 3) % 256;
   }
   return output;
}
