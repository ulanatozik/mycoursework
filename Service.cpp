 


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
    string filename = "users.txt";
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << "для записи" << std::endl;
        return;
    }

    for (const User& user : users) {
        outputFile << user.login << " " << encrypt(user.password) << " " << user.isAdmin << std::endl;
    }

    outputFile.close();
}


vector<User> readAccountsFromFile() {//достать пользователей из файла в вектор
    string fileName = "accounts.txt";
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
        std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << account.login << " | "
            << std::setw(10) << encrypt(account.password) << " | "
            << std::setw(7) << (account.isAdmin ? "Да" : "Нет") << "|" << std::endl;
        cout << "---------------------------------------" << endl;
    }
}

vector<User> readUsersFromFile() {//достать пользователей из файла в вектор
    string fileName = "users.txt";
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
    string fileName = "jewelry.txt";
    vector<Jewelry> jewelryProducts;
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
            jewelryProducts.push_back(Jewelry{ FIO{surname,name,patronymic},Date{day,month,year},day_salary, quantity_miss_day,pay_day,result_pay });
        }

        inputFile.close();
    }
    else {
        cerr << "Ошибка открытия файла " << fileName << endl;
        return medicals;

    }
    return medicals;
}

void writeAccountsToFile(const vector<User>& accounts) {//Запись аккаунтов в файл
    string filename = "accounts.txt";
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла" << filename << " для записи" << std::endl;
        return;
    }

    for (const User& account : accounts) {
        outputFile << account.login << " " << encrypt(account.password) << " " << account.isAdmin << endl;
    }

    outputFile.close();
}

void writeMedicalsToFile( std::vector<Medical>& medicals) {//запись больничных в файл
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
}

void printUsersTable(const std::vector<User>& users)
{//Вывод таблицы аккаунтов
    system("cls");
    // Вывод заголовка таблицы
    cout << "---------------------------------------" << endl;
    std::cout << "|" << setw(3) << "π" << "|" << std::setw(10) << "Логин" << " | "
        << std::setw(10) << "Пароль" << " | "
        << std::setw(7) << "Админ" << "|" << std::endl;
    cout << "---------------------------------------" << endl;
    int i = 0;
    // Вывод строк таблицы
    for (const auto& user : users) {
        std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << user.login << " | "
            << std::setw(10) << encrypt(user.password) << " | "
            << std::setw(7) << (user.isAdmin ? "Да" : "Нет") << "|" << std::endl;
        cout << "---------------------------------------" << endl;
    }
}

void printMedicalTable(std::vector<Medical>& medicals) {//вывод таблицы больничных
    system("cls");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(3) << "π" << "|" << std::setw(16) << "Фамилия" << " | "
        << std::setw(10) << "Имя" << " | "
        << std::setw(14) << "Отчество" << "|" << setw(5) << "День" << "|" << setw(5) << "Месяц" << "|" << setw(7) << "Год" << "|"
        << setw(12) << "ƒÌÂ‚Ì‡ˇ «œ" << "|" << setw(14) << "Пропущенные дни" << "|" << setw(8) << "Оплата" << "|" << setw(5) << "Итог" << "|" << std::endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    int i = 0;
    for (auto& medical : medicals) {
        cout << "|" << setw(3) << ++i << "|" << std::setw(16) << medical.Fio.surname << " | "
            << std::setw(10) << medical.Fio.name << " | "
            << std::setw(14) << medical.Fio.patronymic << "|" << setw(5) << medical.Data.day << "|" << setw(5) << medical.Data.month << "|" << setw(7) << medical.Data.year << "|"
            << setw(12) << medical.day_salary << "|" << setw(15) << medical.quantity_miss_day << "|";
        if (medical.quantity_miss_day >= 16) {
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
        }
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    }
}
void headTable() {//шапка таблицы больничных
    system("cls");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(3) << "π" << "|" << std::setw(16) << "Фпмилия" << " | "
        << std::setw(10) << "Имя" << " | "
        << std::setw(14) << "Отчество" << "|" << setw(5) << "День" << "|" << setw(5) << "Месяц" << "|" << setw(7) << "Год" << "|"
        << setw(12) << "ƒÌÂ‚Ì‡ˇ «œ" << "|" << setw(14) << "Пропущенные дни" << "|" << setw(8) << "Оплата" << "|" << setw(5) << "Итог" << "|" << std::endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
}

void approve() {//одобрение заявки
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
        user.login = accounts.at(number_for_add - 1).login;
        user.password = accounts.at(number_for_add - 1).password;
        user.isAdmin = accounts.at(number_for_add - 1).isAdmin;
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

void addMedical() {//добавить больничный
    system("cls");
    cout << "Добавить больничный лист" << endl;
    string surname, name, patronymic;
    int day, month, year;
    double day_salary, quantity_miss_day;
    vector<Medical> medicals = readMedicalFromFile();
    while (true) {
        cout << "Введите фамилию сотрудника" << endl;
        surname = checkString(surname);
        cout << "Введите имя сотрудника" << endl;
        name = checkString(name);
        cout << "Введите отчество сотрудника" << endl;
        patronymic = checkString(patronymic);
        cout << "Введите дату получения больничного листа бухгалтерией" << endl;
        cout << setw(10) << "День" << endl;
        day = inputNumber(1, 31);
        cout << setw(10) << "Месяц" << endl;
        month = inputNumber(1, 12);
        cout << setw(10) << "Год" << endl;
        year = inputNumber(1970, 2023);
        cout << "Введите, сколько сотрудник получает в день" << endl;
        day_salary = inputNumber(1, 100);
        cout << "Введите количество пропущенных дней сотрудником" << endl;
        quantity_miss_day = inputNumber(1, 60);
        break;
    }
    Medical medical;
    medical.Fio.surname = surname;
    medical.Fio.name = name;
    medical.Fio.patronymic = patronymic;
    medical.Data.day = day;
    medical.Data.month = month;
    medical.Data.year = year;
    medical.day_salary = day_salary;
    medical.quantity_miss_day = quantity_miss_day;
    medicals.push_back(medical);
    writeMedicalsToFile(medicals);
    printMedicalTable(medicals);
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
        isAdmin = inputNumber(0, 1);
        if (checkLoginAndPasswordRegist(users, login, password, isAdmin)) {
            break;
        }
    }
    User user;
    user.login = login;
    user.password = password;
    user.isAdmin = isAdmin;


    users.push_back(user);
    writeUsersToFile(users);
}

void deleteMedical() {//удалить больничный
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    printMedicalTable(medicals);
    int number_for_delete;
    cout << "----Удаление больничного листа---" << endl << endl;
    cout << "Введите номер больничного, который хотите удалить" << endl;
    number_for_delete = inputNumber(1, medicals.size());
    int yes_or_no;
    cout << "1. Да" << endl
        << "2. Нет" << endl
        << "Ваш выбор?" << endl;
    yes_or_no = inputNumber(1, 2);
    if (yes_or_no == 1) {
        medicals.erase(medicals.begin() + number_for_delete - 1);
        cout << "----Больничный лист успешно удален----" << endl;
        writeMedicalsToFile(medicals);
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
            if (users.at(i).isAdmin == 1) {
                Count++;
                num = i;
            }
        }
        if (Count > 1) {
            users.erase(users.begin() + number_for_delete - 1);
            cout << "----Аккаунт успешно удален----" << endl;
            writeUsersToFile(users);
        }
        else if (Count == 1 && users.at(number_for_delete - 1).isAdmin != 1) {
            users.erase(users.begin() + number_for_delete - 1);
            cout << "----Аккаунт успешно удален----" << endl;
            writeUsersToFile(users);
        }
        else cout << "Удалить свой аккаунт невозможно" << endl;
    }
    else cout << "Вы отменили удаление" << endl;

}

void editMedical() {//редактирование больничных
    while (1) {
        system("cls");
        vector<Medical> medicals = readMedicalFromFile();
        printMedicalTable(medicals);
        int choice, number_for_edit;
        string surname, name, patronymic;
        int day, month, year;
        double day_salary, quantity_miss_day;
        cout << "Введите номер аккаунта, который хотите изменить " << endl;
        number_for_edit = inputNumber(1, medicals.size());
        cout << "--------------Нажмите--------------" << endl;
        cout << "1-Чтобы изменить ФИО" << endl;
        cout << "2-Чтобы изменить дату получения больничного бухгалтерией" << endl;
        cout << "3-Чтобы изменить дневную оплату сотрудника" << endl;
        cout << "4-Чтобы изменить количество пропущенных дней" << endl;
        cout << "5-˜ÚÓ·˚ ‚˚ÈÚË ËÁ ÂÊËÏ‡ Â‰‡ÍÚËÓ‚‡ÌËˇ" << endl;
        cout << "¬‡¯ ‚˚·Ó: ";
        choice = inputNumber(1, 5);
        switch (choice) {
        case 1: {
            cout << "--Изменение ФИО--" << endl;
            cout << setw(5) << "Фамилия:" << endl;
            surname = checkString(surname);
            cout << setw(5) << "Имя: " << endl;
            name = checkString(name);
            cout << setw(5) << "Отчество: " << endl;
            patronymic = checkString(patronymic);
            medicals.at(number_for_edit - 1).Fio.surname = surname;
            medicals.at(number_for_edit - 1).Fio.name = name;
            medicals.at(number_for_edit - 1).Fio.patronymic = patronymic;
            writeMedicalsToFile(medicals);
            cout << "--Изменено--" << endl;
            break;
        }
        case 2: {
            cout << "--Изменеие даты получения--" << endl;
            cout << setw(5) << "День: " << endl;
            day = inputNumber(1, 31);
            cout << setw(5) << "Месяц: " << endl;
            month = inputNumber(1, 12);
            cout << setw(5) << "Год: " << endl;
            year = inputNumber(1970, 2023);
            medicals.at(number_for_edit - 1).Data.day = day;
            medicals.at(number_for_edit - 1).Data.month = month;
            medicals.at(number_for_edit - 1).Data.year = year;
            writeMedicalsToFile(medicals);
            cout << "--Дата изменена--" << endl;
            break;
        }
        case 3: {
            cout << "--Изменение дневной оплаты˚--" << endl;
            day_salary = inputNumber(1, 100);
            medicals.at(number_for_edit - 1).day_salary = day_salary;
            writeMedicalsToFile(medicals);
            cout << "--Дневная оплата изменена--" << endl;
            break;
        }
        case 4: {
            cout << "--Изменение количества пропущенных дней--" << endl;
            quantity_miss_day = inputNumber(1, 60);
            medicals.at(number_for_edit - 1).quantity_miss_day = quantity_miss_day;
            writeMedicalsToFile(medicals);
            cout << "-- Количество пропущенных дней изменено--" << endl;
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
        int i = 0;    int choice, number_for_edit;
        string login;
        cout << "Введите номер аккаунта, который хотите изменить: " << endl;
        number_for_edit = inputNumber(1, users.size());
        cout << "--------------¬¬≈ƒ»“≈--------------" << endl;
        cout << "1-чтобы изменить логин" << endl;
        cout << "2-чтобы изменить пароль¸" << endl;
        cout << "3-чтобы редактировать все данные аккаунта" << endl;
        cout << "4-чтобы выйти из режима редактирования" << endl;
        cout << "Ваш выбор: ";
        choice = inputNumber(1, 4);
        switch (choice) {
        case 1: {
            cout << "--ÕÓ‚˚È ÎÓ„ËÌ--" << endl;
            cin >> login;
            while (i < users.size()) {
                if (users.at(i).login == login) {
                    cout << "Данный логин занят, повторите попытку" << endl;
                    cin >> login;
                    i = 0;
                }
                else i++;
            }
            users.at(number_for_edit - 1).login = login;
            writeUsersToFile(users);
            cout << "--Логин успешно заменен--" << endl;
            break;
        }
        case 2: {
            cout << "--Новый пароль--" << endl;
            for (int i = 0; i < users.size(); i++)
                if (users.at(number_for_edit - 1).login == global_login) {
                    cout << "Изменить пароль невозможно" << endl;
                    break;
                }
                else {
                    cout << "0 - роль администратора" << endl;
                    cout << "1 - роль пользователя" << endl;
                    users.at(number_for_edit - 1).isAdmin = inputNumber(0, 1);
                    writeUsersToFile(users);
                    cout << "---Успешно отредактировано---" << endl;
                    break;

                }
            break;
        }
        case 3: {
            cout << "--Новый логин--" << endl;
            cin >> login;
            while (i < users.size()) {
                if (users.at(i).login == login) {
                    cout << "Данный логин занят, повторите попытку" << endl;
                    cin >> login;
                    i = 0;
                }
                else i++;
            }
            users.at(number_for_edit - 1).login = login;
            cout << "--Новый пароль--" << endl;
            for (int i = 0; i < users.size(); i++)
                if (users.at(number_for_edit - 1).login == global_login) {
                    cout << "Изменить роль невозможно" << endl;
                    break;
                }
                else {
                    cout << "0 - роль администратора" << endl;
                    cout << "1 - роль пользователя" << endl;
                    users.at(number_for_edit - 1).isAdmin = inputNumber(0, 1);
                    writeUsersToFile(users);
                    cout << "---Успешно отредактировано---" << endl;
                    break;

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

void individualTask() {//индивидуальное задание
    system("cls");
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
    else { cout << "Выплаты не производились" << endl; }
}
void searchSurname() {//поиск по фамилии
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    string surname;
    int count = 0;
    int a = 0;
    cout << "--Поиск по фамилии--" << endl;
    cout << "Введите фамилию: ";
    surname = checkString(surname);
    headTable();
    for (int i = 0; i < medicals.size(); i++) {
        if (medicals.at(i).Fio.surname == surname) {
            count++;
            cout << "|" << setw(3) << ++a << "|" << std::setw(16) << medicals.at(i).Fio.surname << " | "
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
        }
    }
    if (count == 0) {
        cout << "Ничего не найдено" << endl;
    }

}
void searchMonth() {// поиск по месяцу
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    int month;
    int a = 0;
    int count = 0;
    cout << "--Поиск по месяцу--" << endl;
    cout << "Введите месяц: ";
    month = inputNumber(1, 12);
    headTable();
    for (int i = 0; i < medicals.size(); i++) {
        if (medicals.at(i).Data.month == month) {
            count++;
            cout << "|" << setw(3) << a << "|" << std::setw(16) << medicals.at(i).Fio.surname << " | "
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
        }
    }
    if (count == 0) {
        cout << "Ничего не найдено" << endl;
    }

}
void searchYear() {//поиск по году
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    int year;
    int count = 0;
    int a = 0;
    cout << "--Поиск по году--" << endl;
    cout << "Введите год: ";
    year = inputNumber(1970, 2023);
    headTable();
    for (int i = 0; i < medicals.size(); i++) {
        if (medicals.at(i).Data.year == year) {
            count++;
            cout << "|" << setw(3) << ++a << "|" << std::setw(16) << medicals.at(i).Fio.surname << " | "
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
        }
    }
    if (count == 0) {
        cout << "Ничего не найдено" << endl;
    }


}
void searchQuantity() {//поиск по количеству пропущенных дней
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    int quantity;
    int count = 0;
    int a = 0;
    cout << "--Поиск по количеству пропущенных дней--" << endl;
    cout << "Введите количество дней: ";
    quantity = inputNumber(1, 60);
    headTable();
    for (int i = 0; i < medicals.size(); i++) {
        if (medicals.at(i).quantity_miss_day == quantity) {
            count++;
            cout << "|" << setw(3) << ++a << "|" << std::setw(16) << medicals.at(i).Fio.surname << " | "
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
        }
    }
    if (count == 0) {
        cout << "Ничего не найдено" << endl;
    }


}
void searchDaySalary() {//поиск по дневной зарплате
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    int day_salary;
    int count = 0;
    int a = 0;
    cout << "--Поиск по дневной зарплате--" << endl;
    cout << "Введите зарплату: ";
    day_salary = inputNumber(1, 100);
    headTable();
    for (int i = 0; i < medicals.size(); i++) {
        if (medicals.at(i).day_salary == day_salary) {
            count++;
            cout << "|" << setw(3) << ++a << "|" << std::setw(16) << medicals.at(i).Fio.surname << " | "
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
        }
    }
    if (count == 0) {
        cout << "Ничего не найдено" << endl;
    }

}
void searchMedical() {//поиск больничных
    system("cls");
    cout << "--------------Введите--------------" << endl;
    int choice;
    vector<Medical> medicals = readMedicalFromFile();
    cout << "1 - для поиска по фамилии" << endl;
    cout << "2 - для поиска по месяцу" << endl;
    cout << "3 - для поиска по году" << endl;
    cout << "4 - для поиска по количеству пропущенных дней" << endl;
    cout << "5 - для поиска по дневной зарплате" << endl;
    cout << "Ваш выбор:  ";
    choice = inputNumber(1, 5);
    switch (choice) {
    case 1: {
        searchSurname();
        break;

    }
    case 2: {
        searchMonth();
        break;
    }
    case 3: {
        searchYear();
        break;
    }
    case 4: {
        searchQuantity();
        break;

    }
    case 5: {
        searchDaySalary();
        break;
    }
    }
}
void menuSort() {//меню сортировки
    system("cls");
    vector<Medical> medicals = readMedicalFromFile();
    vector<Medical> medicals_temp;
    medicals_temp = medicals;
    int choice;
    cout << "---—Сортировка---" << endl;
    cout << "1 - по фамилии " << endl;
    cout << "2 - по номеру месяца " << endl;
    cout << "3 - по номеру года" << endl;
    cout << "4 - по количеству дней пропущенных по болезни" << endl;
    cout << "5 - по дневной зарплате" << endl;
    cout << "Ваш выбор:" << endl;
    choice = inputNumber(1, 5);
    switch (choice) {
    case 1: {
        sort(medicals_temp.begin(), medicals_temp.end(), isSortBySurname);
        break;
    }
    case 2: {
        sort(medicals_temp.begin(), medicals_temp.end(), isSortByMonth);
        break;
    }
    case 3: {
        sort(medicals_temp.begin(), medicals_temp.end(), isSortByYear);
        break;
    }
    case 4: {
        sort(medicals_temp.begin(), medicals_temp.end(), isSortByDay);
        break;
    }
    case 5: {
        sort(medicals_temp.begin(), medicals_temp.end(), isSortBySalary);
        break;
    }
    }
    cout << "--Успешно отсортировано--" << endl;
    printMedicalTable(medicals_temp);

}
bool isSortBySurname(Medical name_a, Medical name_b) {//ÙÛÌÍˆËˇ-ÍÓÏÔ‡‡ÚÓ
    return name_a.Fio.surname < name_b.Fio.surname;
}
bool isSortByMonth(Medical month_a, Medical month_b) {//ÙÛÌÍˆËˇ-ÍÓÏÔ‡‡ÚÓ
    return month_a.Data.month < month_b.Data.month;
}
bool isSortByYear(Medical year_a, Medical year_b) {//ÙÛÌÍˆËˇ-ÍÓÏÔ‡‡ÚÓ
    return year_a.Data.year < year_b.Data.year;
}
bool isSortByDay(Medical day_a, Medical day_b) {//ÙÛÌÍˆËˇ-ÍÓÏÔ‡‡ÚÓ
    return day_a.quantity_miss_day < day_b.quantity_miss_day;
}
bool isSortBySalary(Medical salary_a, Medical salary_b) {//ÙÛÌÍˆËˇ-ÍÓÏÔ‡‡ÚÓ
    return salary_a.day_salary < salary_b.day_salary;
}
void menuWorkWithMedical() {//меню для работы с больничными
    while (1) {
        // system("cls");
        cout << "--------------Введите--------------" << endl;
        int choice;
        vector<Medical> medicals = readMedicalFromFile();
        cout << "1 - для вывода всех больничных листов" << endl;
        cout << "2 - добавить больничный лист" << endl;
        cout << "3 - для редактирования больничных листов" << endl;
        cout << "4 - чтобы удалить больничный лист" << endl;
        cout << "5 - для вывода выплат за определенный месяц" << endl;
        cout << "6 - для поиска больничного листа" << endl;
        cout << "7 - для сортировки больничных листов" << endl;
        cout << "8 - для выхода" << endl;
        cout << "Ваш выбор:  ";
        choice = inputNumber(1, 8);
        switch (choice) {
        case 1: {
            printMedicalTable(medicals);
            break;
        }
        case 2: {
            addMedical();
            break;
        }
        case 3: {
            editMedical();
            break;
        }
        case 4: {
            deleteMedical();
            break;
        }
        case 5: {
            individualTask();
            break;
        }
        case 6: {
            searchMedical();
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
        vector<Medical> medicals = readMedicalFromFile();
        cout << "1 - для просмотра данных" << endl;
        cout << "2 - для поиска данных" << endl;
        cout << "3 - для сортировки данных" << endl;
        cout << "4 - для вывода выплат за определенный месяц" << endl;
        cout << "5 - для выхода" << endl;
        cout << "Ваш выбор:  ";
        choice = inputNumber(1, 5);
        switch (choice)
        {
        case 1: {
            printMedicalTable(medicals);
            break;
        }
        case 2: {
            searchMedical();
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
        cout << "--------------Введите≈--------------" << endl;
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
            menuWorkWithMedical();
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
        if (user.login == login && user.password == password) {
            std::cout << "Добро пожаловать, " << user.login << "!" << std::endl;
            if (user.isAdmin == 0) { menuUser(); }
            if (user.isAdmin == 1) { menuAdministrator(); }
            return true;
        }
    }
    std::cout << "Неверный логин или пароль!" << std::endl;
    return false;
}
bool checkLoginAndPasswordRegist(std::vector<User>& users, std::string login, std::string password, bool isAdmin) {//проверка на существование пользователя
    for (auto& user : users) {
        if (user.login == login && user.password == password && user.isAdmin == isAdmin) {
            std::cout << "Такой пользователь уже существует" << endl;
            return false;
        }
    }
    return true;
}

 

void authorization() {//авторизация
        
    cout << "Authorization" << std::endl;
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
    cout << "Регистрация" << endl;
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
        account.login = login;
        account.password = password;
        account.isAdmin = isAdmin;
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
