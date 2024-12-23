#include "classes.h"
#include <iostream>
#include <string>
//#include <ctime>
#include <conio.h>
using namespace  std;

const string code = { "123" }; //Код для входа в сервисное меню

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    string vcode = { "000" };
    char oper = '0';

    //Первичная инициализация аппарата
    VendingMachine* machine = new VendingMachine();
    CashRegister* cash = new CashRegister();
    Snack* bounty = new Snack("Баунти", 250, 300, 10);
    Snack* snickers = new Snack("Сникерс", 235, 340, 11);
    Snack* mars = new Snack("Марс", 220, 315, 12);
    SnackSlot* slot1 = new SnackSlot();
    SnackSlot* slot2 = new SnackSlot();
    SnackSlot* slot3 = new SnackSlot();
    for (int i = 0; i < slot1->getMaxSnackCount(); i++) slot1->addSnack(bounty);
    for (int i = 0; i < slot2->getMaxSnackCount(); i++) slot2->addSnack(snickers);
    for (int i = 0; i < slot3->getMaxSnackCount(); i++) slot3->addSnack(mars);
    machine->addSlot(slot1);
    machine->addSlot(slot2);
    machine->addSlot(slot3);

    while (true)
    {
        if (code != vcode)
        {
            cout << endl << "В наличии:" << endl;
            if (slot1->getSnackCount() != 0) bounty->showSnackInfo();
            if (slot2->getSnackCount() != 0) snickers->showSnackInfo();
            if (slot3->getSnackCount() != 0) mars->showSnackInfo();
            cout << endl << "Введите '1' для покупки Баунти, '2' для покупки Сникерса, '3' для покупки Марса, " << endl;
            cout << "        's' для входа в сервисное меню: ";
            oper = _getch();
        }
        else if (code == vcode)
        {
            cout << "Выручка: " << cash->getCurrentBalance() << endl;
            cout << "Количество слотов: " << machine->getSlotCount() << endl;
            cout << "Количество пустых слотов: " << machine->getEmptySlotsCount() << endl;
            cout << "Количество снеков " << bounty->getName() << ": " << slot1->getSnackCount() << endl;
            cout << "Количество снеков " << snickers->getName() << ": " << slot2->getSnackCount() << endl;
            cout << "Количество снеков " << mars->getName() << ": " << slot3->getSnackCount() << endl;
            //slot1->slotInfo();
            //slot2->slotInfo();
            //slot3->slotInfo();
            cout << endl << "Введите 'i' для заполнения аппарата товаром, ";
            cout << endl << "'b' для возврата в пользовательское меню, 'q' для выхода: ";
            oper = _getch();
        }
        if (oper == 's')
        {
            cout << endl << "Введите код: ";
            cin >> vcode;
            system("cls");
        }
        if (oper == 'q' && code == vcode)
        {
            cout << "Завершение работы.\n";
            break;
        }
        switch (oper) //
        {
        case '1': // Покупка Баунти
            cash->acceptAmount(slot1->buySnack());
            break;
        case '2': //Покупка Сникерса
            cash->acceptAmount(slot2->buySnack());
            break;
        case '3': //Покупка Марса
            cash->acceptAmount(slot3->buySnack());
            break;
        case 'i': // Загрузка недостающего товара
            slot1->initSlot(bounty);
            slot2->initSlot(snickers);
            slot3->initSlot(mars);
            system("cls");
            break;
        case 'b': //Возврат в пользовательское меню
            vcode = { "000" };
            system("cls");
            break;
        default:
            system("cls");
            if (vcode != code) cout << endl << "Вы ввели неправильный символ." << endl;
            break;
        }
    }

    delete bounty;
    delete snickers;
    delete mars;
    delete slot1;
    delete slot2;
    delete slot3;
    delete cash;
    delete machine;

    return 0;
}
