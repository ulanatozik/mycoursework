 


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
   while (1) {
      system("cls");
       int choice;
       cout << "-------Введите-------- \n 1. Для регистрации \n 2. Для авторизации\n 3. Для выхода \n";
       choice = inputNumber(1, 3);
       switch (choice) {
       case 1: {
           system("cls");
           registration();
           sleep(3);
           break;
       }
       case 2: {
           system("cls");
           authorization();
           break;
       }
       case 3: {
           return;

       }
       }

   }
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
           accounts.push_back(User{ login,decrypt(password), isAdmin });
       }
       inFile.close();
   }
   else {
       std::cerr << "Невозможно открыть файл " << fileName << std::endl;
   }
   return accounts;
}

void printAccountsTable(const std::vector<User>& accounts) {//вывод таблицы аккаунтов
   system("cls");
   // вывод заголовка таблицы
   cout << "---------------------------------------" << endl;
   std::cout << "|" << setw(3) << "Аккаунт" << "|" << std::setw(10) << "Логин" << " | "
       << std::setw(10) << "Пароль" << " | "
       << std::setw(7) << "Админ" << "|" << std::endl;
   cout << "---------------------------------------" << endl;
   int i = 0;
   // вывод строк таблицы
   for (const auto& account : accounts) {
       std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << account.getLogin() << " | "
           << std::setw(10) << encrypt(account.getPassword()) << " | "
           << std::setw(7) << (account.getIsAdmin() ? "Да" : "Нет") << "|" << std::endl;
       cout << "---------------------------------------" << endl;
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
           users.push_back(User{ login,decrypt(password), isAdmin });
       }
       inFile.close();
   }
   else {
       std::cerr << "Невозможно открыть файл " << fileName << std::endl;
   }
   return users;
}

/*vector<Medical> readMedicalFromFile() {//достать записи из файла в вектор
   string fileName = "medicals.txt";
   vector<Medical> medicals;
   ifstream inputFile(fileName);
   if (inputFile.is_open()) {
       //Medical medical;
       string surname, name, patronymic;
       int day, month, year;
       double day_salary, quantity_miss_day,pay_day,result_pay;
       while (inputFile >> surname >> name >> patronymic
           >> day >>month >> year
           >> day_salary >> quantity_miss_day >> pay_day >> result_pay)
       {
           // добавляем структуру в вектор
           medicals.push_back(Medical{ FIO{surname,name,patronymic},Date{day,month,year},day_salary, quantity_miss_day,pay_day,result_pay });
       }

       inputFile.close();
   }
   else {
       cerr << "Ошибка открытия файла " << fileName << endl;
       return medicals;

   }
   return medicals;
}*/

vector<Jewelry> readJewelryFromFile() {//достать записи из файла в вектор
   string fileName = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/jewelry.txt";
   vector<Jewelry> jewelryProducts;
   ifstream inputFile(fileName);
   if (inputFile.is_open()) {
       //Medical medical;
       int price, amount, metallSample;
        
       string productType, metall, collection;
       
       while (inputFile >> price >> amount >> metallSample
           >> productType >> metall >> collection)
       {
           // добавляем класс в вектор
           Jewelry j(price, amount, productType, metall, metallSample, collection);
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

/*void writeJewelryToFile( std::vector<Medical>& medicals) {//запись больничных в файл
   string filename = "medicals.txt";
   std::ofstream outputFile(filename);

   if (!outputFile.is_open()) {
       std::cerr << "Ошибка открытия файла " << filename << " для записи." << std::endl;
       return;
   }

   for ( Medical& medical : medicals) {
       outputFile << medical.Fio.surname << " " << medical.Fio.name << " " << medical.Fio.patronymic << " " << medical.Data.day << " "
           << medical.Data.month << " " << medical.Data.year << " " << medical.day_salary << " "
           << medical.quantity_miss_day << " ";
       if (medical.quantity_miss_day >= 16) {
           medical.pay_day = medical.day_salary;
           medical.result_pay = medical.quantity_miss_day * medical.day_salary;
           outputFile << medical.day_salary << " " << medical.day_salary * medical.quantity_miss_day << endl;
       }
       else {
           medical.pay_day = medical.day_salary*0.8;
           medical.result_pay = medical.quantity_miss_day * medical.day_salary*0.8;
           outputFile << medical.day_salary*0.8 << " " << medical.day_salary * medical.quantity_miss_day*0.8 << endl;
       }
   }


   outputFile.close();
}*/



void writeJewelryToFile( std::vector<Jewelry>& jewelryProducts) {//запись больничных в файл
   string filename = "/Users/ulanatozik/материалы по учебе/курсач 1 курс /мой курсачик/mycoursework/mycoursework/jewelry.txt";
   std::ofstream outputFile(filename);

   if (!outputFile.is_open()) {
       std::cerr << "Ошибка открытия файла " << filename << " для записи." << std::endl;
       return;
   }

   for ( Jewelry& jewelry : jewelryProducts) {
       outputFile << jewelry.getPrice() << " " << jewelry.getAmount() << " " << jewelry.getMetallSample() << " " << jewelry.getProductType() << " "
           << jewelry.getMetall() << " " << jewelry.getCollection() << " ";
       /*if (medical.quantity_miss_day >= 16) {
           medical.pay_day = medical.day_salary;
           medical.result_pay = medical.quantity_miss_day * medical.day_salary;
           outputFile << medical.day_salary << " " << medical.day_salary * medical.quantity_miss_day << endl;
       }
       else {
           medical.pay_day = medical.day_salary*0.8;
           medical.result_pay = medical.quantity_miss_day * medical.day_salary*0.8;
           outputFile << medical.day_salary*0.8 << " " << medical.day_salary * medical.quantity_miss_day*0.8 << endl;
       }*/
   }


   outputFile.close();
}

void printUsersTable(const std::vector<User>& users)
{//Вывод таблицы аккаунтов
   system("cls");
   // Вывод заголовка таблицы
   cout << "---------------------------------------" << endl;
   std::cout << "|" << setw(3) << "Пользователь" << "|" << std::setw(10) << "Логин" << " | "
       << std::setw(10) << "Пароль" << " | "
       << std::setw(7) << "Админ" << "|" << std::endl;
   cout << "---------------------------------------" << endl;
   int i = 0;
   // Вывод строк таблицы
   for (const auto& user : users) {
       std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << user.getLogin() << " | "
           << std::setw(10) << encrypt(user.getPassword()) << " | "
           << std::setw(7) << (user.getIsAdmin() ? "Да" : "Нет") << "|" << std::endl;
       cout << "---------------------------------------" << endl;
   }
}

void printJewelryTable(std::vector<Jewelry>& jewelryProducts) {//вывод таблицы больничных
   system("cls");
   cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
   cout << "|" << std::setw(16) << "Вид изделия" << " | "
       << std::setw(10) << "Металл" << " | "
       << std::setw(14) << "Проба" << "|" << setw(5) << "Цена" << "|" << setw(5) << "Количество" << "|" << setw(7) << "Коллекция" << "|" << std::endl;
   cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
   int i = 0;
   for (auto& jewelry : jewelryProducts) {
       cout << "|" << setw(3) << ++i << "|" << std::setw(16) << jewelry.getProductType() << " | "
           << std::setw(10) << jewelry.getMetall() << " | "
       << std::setw(14) << jewelry.getMetallSample() << "|" << setw(5) << jewelry.getPrice() << "|" << setw(5) << jewelry.getAmount() << "|" << setw(12) << jewelry.getCollection() << "|";
       /*if (medical.quantity_miss_day >= 16) {
           medical.pay_day = medical.day_salary;
           cout << setw(9) << medical.day_salary << "|";
           medical.result_pay = medical.pay_day * medical.quantity_miss_day;
           cout << setw(5) << medical.result_pay << "|" << std::endl;
       }
       else {
           medical.pay_day = medical.day_salary * 0.8;
           cout << setw(9) << medical.day_salary * 0.8 << "|";
           medical.result_pay = medical.pay_day * medical.quantity_miss_day;
           cout << setw(5) << medical.result_pay << "|" << std::endl;
       }*/
       cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

   }
}
void headTable() {//шапка таблицы товаров
   system("cls");
   cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
   cout << "|" << std::setw(16) << "Вид изделия" << " | "
       << std::setw(10) << "Металл" << " | "
       << std::setw(14) << "Проба" << "|" << setw(5) << "Цена" << "|" << setw(5) << "Количество" << "|" << setw(7) << "Коллекция" << "|" << std::endl;
   cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
}

void approve() {//одобрение заявки //тут есть вопросы по get или set
   system("cls");
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
   system("cls");
   cout << "Добавить товар:" << endl;
   string productType, metall, collection;
   int price, amount, metallSample;

   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   while (true) {
       cout << "Введите вид ювелирного изделия:" << endl;
       productType = checkString(productType);
       cout << "Введите вид металла:" << endl;
       metall = checkString(metall);
       cout << "Введите пробу металла:" << endl;
       metallSample = inputNumber(375, 950);
       cout << "Введите цену за 1 единицу товара:" << endl;
       price = inputNumber(1, 10000);
       cout << "Введите количество данного товара в наличии:" << endl;
       amount = inputNumber(1, 100);
       cout << "Введите коллекцию, к которой принадлежит товар:" << endl;
       collection = checkString(collection);
       break;
   }
   Jewelry jewelry;
   jewelry.setProductType(productType);
   jewelry.setMetall(metall);
   jewelry.setMetallSample(metallSample);
   jewelry.setPrice(price);
   jewelry.setAmount(amount);
   jewelry.setCollection(collection);
   jewelryProducts.push_back(jewelry);
   writeJewelryToFile(jewelryProducts);
   printJewelryTable(jewelryProducts);
}

void addaccount() {//Добавить аккаунт
   system("cls");
   cout << "Добавить аккаунт" << endl;
   string login, password;
   bool isAdmin;
   vector<User> users = readUsersFromFile();
   while (true) {
       cout << "Введите логин" << endl;
       cin >> login;
       cout << "Введите пароль" << endl;
       cin >> password;
       cout << "Является ли админом (0,1)" << endl;
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

void deleteJewelry() {//удалить товар //???????
   system("cls");
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
   system("cls");
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

void editJewelry() {//редактирование товара
   while (1) {
       system("cls");
       vector<Jewelry> jewelryProducts = readJewelryFromFile();
       printJewelryTable(jewelryProducts);
       string productType, metall, collection;
       int price, amount, metallSample, number_for_edit;
       cout << "Введите номер товара, который хотите изменить " << endl;
       number_for_edit = inputNumber(1, jewelryProducts.size());
       cout << "--------------Нажмите--------------" << endl;
       cout << "1-Чтобы изменить вид изделия" << endl;
       cout << "2-Чтобы изменить количество товара в наличии" << endl;
       cout << "3-Чтобы изменить коллекцию, к которой принадлежит товар" << endl;
       cout << "4-Чтобы изменить цену товара" << endl;
       cout << "5-Чтобы выйти из режима редактирования" << endl;
       cout << "Ваш выбор: ";
       int choice;
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
           cout << "--Изменеие количества товара в наличии--" << endl;
           cout << setw(5) << "Новое количество: " << endl;
           int newAmount = inputNumber(1, 100);
           jewelryProducts.at(number_for_edit - 1).setAmount(newAmount);
           writeJewelryToFile(jewelryProducts);
           cout << "--Количество товара изменено--" << endl;
           break;
       }
       case 3: {
           cout << "--Изменение коллекции--" << endl;
           cout << setw(5) << "Новая коллекция:" << endl;
           string newCollection = checkString(collection);
           jewelryProducts.at(number_for_edit - 1).setCollection(newCollection);
           writeJewelryToFile(jewelryProducts);
           cout << "--Коллекция изменен--" << endl;
           break;
       }
       case 4: {
           cout << "--Изменение цены товара--" << endl;
           int newPrice = inputNumber(1, 10000);
           jewelryProducts.at(number_for_edit - 1).setPrice(newPrice);
           writeJewelryToFile(jewelryProducts);
           cout << "--Цена товара изменена--" << endl;
           break;
       }
       case 5: {
           return;
       }

       }

   }
}

void editAccount() {//редактирование аккаунтов
    while (1) {
        system("cls");
        vector<User> users = readUsersFromFile();
        printUsersTable(users);
        int i = 0;    
        int choice, number_for_edit;
        string newLogin;
        cout << "Введите номер аккаунта, который хотите изменить: " << endl;
        number_for_edit = inputNumber(1, users.size());
        cout << "--------------Введите--------------" << endl;
        cout << "1 - Чтобы изменить логин" << endl;
        cout << "2 - Чтобы изменить пароль¸" << endl;
        cout << "3 - Чтобы редактировать все данные аккаунта" << endl;
        cout << "4 - Чтобы выйти из режима редактирования" << endl;
        cout << "Ваш выбор: ";
        choice = inputNumber(1, 4);
        switch (choice) { //логин поменян, пароль и остальное еще надо менять
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
                    break;
                } else {
                    cout << "Данный логин занят, повторите попытку" << endl;
                }
                break;
            }
            case 2: {
                cout << "--Новый пароль--" << endl;
                bool userFound = false;
                int i = 0;
                while (i < users.size() && !userFound) {
                    if (users.at(i).getLogin() == global_login) {
                        cout << "Изменить пароль невозможно" << endl;
                        userFound = true;
                    }
                    i++;
                }

                if (!userFound) {
                    cout << "0 - роль администратора" << endl;
                    cout << "1 - роль пользователя" << endl;
                    users.at(number_for_edit - 1).setIsAdmin(inputNumber(0, 1));
                    writeUsersToFile(users);
                    cout << "---Успешно отредактировано---" << endl;
                }
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
                 cout << "--Новый пароль--" << endl;
                     bool userFound = false;
                     int i = 0;
                     while (i < users.size() && !userFound) {
                         if (users.at(i).getLogin() == global_login) {
                             cout << "Изменить пароль невозможно" << endl;
                             userFound = true;
                         }
                         i++;
                     }

                     if (!userFound) {
                         cout << "0 - роль администратора" << endl;
                         cout << "1 - роль пользователя" << endl;
                         users.at(number_for_edit - 1).setIsAdmin(inputNumber(0, 1));
                         writeUsersToFile(users);
                         cout << "---Успешно отредактировано---" << endl;
                     }
                 break;
                 
                 }
                 case 4: {
                 return;
                 }
                 }
                
            }
        }
    
       

void menuWorkWithUser() {//меню для работы с учетными записями
   while (1) {
       // system("cls");
       cout << "--------------Введите--------------" << endl;
       int choice;
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
           return;
       }
       }
   }
}

void individualTask() {
    cout <<"Uraaa"<<endl;//индивидуальное задание
   /*system("cls");
   vector<Medical> medicals = readMedicalFromFile();
   int month, year; double payment = 0;
   cout << "Введите номер месяца: ";
   month = inputNumber(1, 12);
   cout << "Введите год: ";
   year = inputNumber(1970, 2023);
   int count = 0;
   cout << "---Выплаты по больничным листам---" << " за " << month << "." << year << endl;
   headTable();
   for (int i = 0; i < medicals.size(); i++) {
       if (medicals.at(i).Data.month == month && medicals.at(i).Data.year == year) {
           count++;
           cout << "|" << setw(3) << i + 1 << "|" << std::setw(16) << medicals.at(i).Fio.surname << " | "
               << std::setw(10) << medicals.at(i).Fio.name << " | "
               << std::setw(14) << medicals.at(i).Fio.patronymic << "|" << setw(5) << medicals.at(i).Data.day << "|" << setw(5) << medicals.at(i).Data.month << "|" << setw(7) << medicals.at(i).Data.year << "|"
               << setw(12) << medicals.at(i).day_salary << "|" << setw(15) << medicals.at(i).quantity_miss_day << "|";
           if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
           payment += medicals.at(i).result_pay;
       }
   }
   if (count > 0) {
       cout << "Общая сумма выплат за" << month << "месяц " << year << "год составила " << payment << endl;
   }
   else { cout << "Выплаты не производились" << endl; }*/
}


void searchProductType() {//поиск по виду изделия
   system("cls");
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
           cout << "|" << setw(3) << ++a << "|" << std::setw(16) << jewelryProducts.at(i).getProductType() << " | "
               << std::setw(10) << jewelryProducts.at(i).getMetall() << " | "
               << std::setw(14) << jewelryProducts.at(i).getMetallSample() << "|" << setw(5) << jewelryProducts.at(i).getPrice() << "|"
               << setw(5) << jewelryProducts.at(i).getAmount() << "|" << setw(7) << jewelryProducts.at(i).getCollection() << "|";
               
           /*if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }*/
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchMetall() {// поиск по виду металла
   system("cls");
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
           cout << "|" << setw(3) << ++a << "|" << std::setw(16) << jewelryProducts.at(i).getProductType() << " | "
               << std::setw(10) << jewelryProducts.at(i).getMetall() << " | "
               << std::setw(14) << jewelryProducts.at(i).getMetallSample() << "|" << setw(5) << jewelryProducts.at(i).getPrice() << "|"
               << setw(5) << jewelryProducts.at(i).getAmount() << "|" << setw(7) << jewelryProducts.at(i).getCollection() << "|";
               
           /*if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }*/
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchPrice() {//поиск по цене
   system("cls");
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   int price;
   int count = 0;
   int a = 0;
   cout << "--Поиск по цене--" << endl;
   cout << "Введите цену: ";
   price = inputNumber(0, 10000);
   headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getPrice() == price) {
           count++;
           cout << "|" << setw(3) << ++a << "|" << std::setw(16) << jewelryProducts.at(i).getProductType() << " | "
               << std::setw(10) << jewelryProducts.at(i).getMetall() << " | "
               << std::setw(14) << jewelryProducts.at(i).getMetallSample() << "|" << setw(5) << jewelryProducts.at(i).getPrice() << "|"
               << setw(5) << jewelryProducts.at(i).getAmount() << "|" << setw(7) << jewelryProducts.at(i).getCollection() << "|";
           /*if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }*/
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }


}
void searchAmount() {//поиск по количеству
   system("cls");
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   int amount;
   int count = 0;
   int a = 0;
   cout << "--Поиск по количеству товара в наличии--" << endl;
   cout << "Введите количество товара в наличии: ";
   amount = inputNumber(0, 100);
   headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getAmount() == amount) {
           count++;
           cout << "|" << setw(3) << ++a << "|" << std::setw(16) << jewelryProducts.at(i).getProductType() << " | "
               << std::setw(10) << jewelryProducts.at(i).getMetall() << " | "
               << std::setw(14) << jewelryProducts.at(i).getMetallSample() << "|" << setw(5) << jewelryProducts.at(i).getPrice() << "|"
               << setw(5) << jewelryProducts.at(i).getAmount() << "|" << setw(7) << jewelryProducts.at(i).getCollection() << "|";
           /*if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }*/
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }


}
void searcMetallSample() {//поиск по пробе металла
system("cls");
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   int metallSample;
   int count = 0;
   int a = 0;
   cout << "--Поиск по пробе металла--" << endl;
   cout << "Введите пробу металла: ";
   metallSample = inputNumber(375, 950);
   headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getMetallSample() == metallSample) {
           count++;
           cout << "|" << setw(3) << ++a << "|" << std::setw(16) << jewelryProducts.at(i).getProductType() << " | "
               << std::setw(10) << jewelryProducts.at(i).getMetall() << " | "
               << std::setw(14) << jewelryProducts.at(i).getMetallSample() << "|" << setw(5) << jewelryProducts.at(i).getPrice() << "|"
               << setw(5) << jewelryProducts.at(i).getAmount() << "|" << setw(7) << jewelryProducts.at(i).getCollection() << "|";
           /*if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }*/
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchCollection() {// поиск по коллекции
   system("cls");
   vector<Jewelry> jewelryProducts = readJewelryFromFile();
   string collection;
   int count = 0;
   int a = 0;
   cout << "--Поиск по виду металла--" << endl;
   cout << "Введите вид металла: ";
   collection = checkString(collection);
   headTable();
   for (int i = 0; i < jewelryProducts.size(); i++) {
       if (jewelryProducts.at(i).getCollection() == collection) {
           count++;
           cout << "|" << setw(3) << ++a << "|" << std::setw(16) << jewelryProducts.at(i).getProductType() << " | "
               << std::setw(10) << jewelryProducts.at(i).getMetall() << " | "
               << std::setw(14) << jewelryProducts.at(i).getMetallSample() << "|" << setw(5) << jewelryProducts.at(i).getPrice() << "|"
               << setw(5) << jewelryProducts.at(i).getAmount() << "|" << setw(7) << jewelryProducts.at(i).getCollection() << "|";
               
           /*if (medicals.at(i).quantity_miss_day >= 16) {
               cout << setw(9) << medicals.at(i).day_salary << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }
           else {
               cout << setw(9) << medicals.at(i).day_salary * 0.8 << "|";
               medicals.at(i).pay_day = medicals.at(i).day_salary * 0.8;
               medicals.at(i).result_pay = medicals.at(i).pay_day * medicals.at(i).quantity_miss_day;
               cout << setw(5) << medicals.at(i).result_pay << "|" << std::endl;
           }*/
           cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
       }
   }
   if (count == 0) {
       cout << "Ничего не найдено" << endl;
   }

}

void searchJewelry() {//поиск товаров
   system("cls");
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
       searchCollection(); //поиск по пробе металла
       break;
   }
   }
}

void menuSort() {//меню сортировки
   system("cls");
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
       // system("cls");
       cout << "--------------Введите--------------" << endl;
       int choice;
       vector<Jewelry> jewelryProducts = readJewelryFromFile();
       cout << "1 - для отображения перечня ювелирных изделий" << endl;
       cout << "2 - для добавления товара" << endl;
       cout << "3 - для редактирования товара" << endl;
       cout << "4 - для удаления товара" << endl;
       cout << "5 - для оформления заказа или предзаказа" << endl;
       cout << "6 - для поиска товара" << endl;
       cout << "7 - для сортировки товаров" << endl;
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
           individualTask();
           break;
       }
       case 6: {
           searchJewelry();
           break;
       }
       case 7: {
           menuSort();
           break;
       }
       case 8: {
           return;
       }
       }
   }
}

void menuUser() {//меню пользователя
   while (1) {
       cout << "Добро пожаловать в меню пользователя" << endl;
       cout << "--------------Введите--------------" << endl;
       int choice;
       vector<Jewelry> jewelryProducts = readJewelryFromFile();
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
       system("cls");
       cout << "Добро пожаловать в меню администратора" << endl;
       cout << "--------------Введите--------------" << endl;
       int choice;
       cout << "1 - для работы с учетными записями" << endl;
       cout << "2 - для работы с данными" << endl;
       cout << "3 - для выхода" << endl;
       cout << "Ваш выбор:  ";
       choice = inputNumber(1, 3);
       switch (choice) {
       case 1: {
           system("cls");
           menuWorkWithUser();
           break;
       }
       case 2: {
           system("cls");
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
   std::cout << "Неверный логин или пароль!" << std::endl;
   return false;
}

bool checkLoginAndPasswordRegist(std::vector<User>& users, std::string login, std::string password, bool isAdmin) {//проверка на существование пользователя
   for (auto& user : users) {
       if (user.getLogin() == login && user.getPassword() == password && user.getIsAdmin() == isAdmin) {
           std::cout << "Такой пользователь уже существует" << endl;
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
           std::cout << "Вы вошли в систему." << std::endl;
           isLoggedIn = true;
           }
       else
       {
           std::cout << "Неверный логин или пароль. Попробуйте снова." << std::endl;
       }
   }
       /* while ((ch = std::cin.get()) != '\r') {   // \r - символ Enter //там где cin get это я поменяла, может не работать
           if (ch == '\b') {   // \b - символ "backspace"
               if (i > 0) {
                   cout << "\b \b";   // Отображаем backspace, пробел и еще один backspace
                   i--;
                   password.erase(i, 1);
               }
           }
           else {
               password.insert(i, 1, ch);
               i++;
               cout << '*';
           }
       }*/
       /*cout << endl;
       if (checkLoginAndPassword(accounts, login, password)) {
           break;
       }*/

}


void registration() {//регистрация
   //system("cls");
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
