#include "classes.h"
#include <iostream>
#include <string>
using namespace  std;

// Snack //////////////////////////////////////////////////////////////////////
Snack::Snack(std::string v_name, double v_price, int v_cn, int v_expDate)
{
	name = v_name;
	price = v_price;
	caloriesNumber = v_cn;
	expirationDate = v_expDate;
}
Snack::Snack(const Snack& other)
{
	this->name = other.name;
	this->price = other.price;
	this->caloriesNumber = other.caloriesNumber;
	this->expirationDate = other.expirationDate;
}
void Snack::setName(std::string v_name)
{
	name = v_name;
}
std::string Snack::getName() const
{
	return name;
}
double Snack::getPrice() const
{
	return price;
}
void Snack::showSnackInfo() const
{
	cout << name << " - Количество калорий: " << caloriesNumber << ", Цена: " << price << endl;
}
void Snack::showSnackInfoAll() const
{
	cout << name << " - Количество калорий: " << caloriesNumber 
		 << ", Срок хранения: " << expirationDate << ", Цена: " << price << endl;
}

// SnakSlot ///////////////////////////////////////////////////////////////////
SnackSlot::SnackSlot()
{
	p_snack = new Snack*[maxSnackCount];
	for (int i = 0; i < maxSnackCount; i++)
		 p_snack[i] = new Snack();
	snackCount = 0;
}
SnackSlot::~SnackSlot()
{
	delete[] p_snack;
}
SnackSlot::SnackSlot(const SnackSlot& other)
{
	this->p_snack = other.p_snack;
}
int SnackSlot::getSnackCount() const
{
	return snackCount;
}
int SnackSlot::getMaxSnackCount() const
{
	return maxSnackCount;
}
void SnackSlot::addSnack(Snack *v_snack)
{
	p_snack[snackCount++] = v_snack;
}
void SnackSlot::initSlot(Snack *v_snack)
{
	int count = snackCount;
	for (int i = 0; i < maxSnackCount - count; i++) addSnack(v_snack);
}
double SnackSlot::buySnack()
{
	if (snackCount > 0)
	{
		double price;
		system("cls");
		cout << endl << "Покупаем " << this->p_snack[snackCount-1]->getName() << endl;
		cout << "Оплатите " << this->p_snack[snackCount-1]->getPrice() << ": ";
		cin >> price;
		if (price >= this->p_snack[snackCount-1]->getPrice()) {
			snackCount--;
			system("cls");
			return price;
		}
		else 
		{
			system("cls");
			cout << "Недостаточно средств. Оплатите всю сумму.";
			return 0;
		}
	}
	else
	{
		system("cls");
		cout << endl << "Товар распродан. Выберите другой товар...";
	}
}
void SnackSlot::slotInfo()
{
	for (int i = 0; i < snackCount; i++)
		this->p_snack[i]->showSnackInfoAll();
}

// VendingMachine /////////////////////////////////////////////////////////////
VendingMachine::VendingMachine()
{
	p_slot = new SnackSlot*[maxSlotCount];
	for (int i = 0; i < maxSlotCount; i++)
		p_slot[i] = new SnackSlot();
	slotCount = 0;
}
VendingMachine::~VendingMachine()
{
	delete[] p_slot;
}
int VendingMachine::getSlotCount() const
{
	return slotCount;
}
int VendingMachine::getEmptySlotsCount() const
{
	return maxSlotCount - slotCount;
}
void VendingMachine::addSlot(SnackSlot* v_slot)
{
	p_slot[slotCount++] = v_slot;
}

// CashRegister ///////////////////////////////////////////////////////////////
CashRegister::CashRegister(double cashIn)
{
	if (cashIn >= 0)
		cashInVM = cashIn;
	else
		cashInVM = 500;
}
double CashRegister::getCurrentBalance() const
{
	return cashInVM;
}
void CashRegister::acceptAmount(double amountIn)
{
	cashInVM += amountIn;
}
