#pragma once
#include <iostream>
#include <string>

class Snack
{
public:
	Snack() = default;
	Snack(std::string, double, int, int);
	~Snack() = default;
	Snack(const Snack&); // Ссылка на копию?
	void setName(std::string);
	std::string getName() const;
	double getPrice() const;
	void showSnackInfo() const;
	void showSnackInfoAll() const;
private:
	std::string name;
	double price = 0;
	int caloriesNumber = 0;
	int expirationDate = 0;
};

class SnackSlot
{
public:
	SnackSlot();
	~SnackSlot();
	SnackSlot(const SnackSlot&);
	int getSnackCount() const;
	int getMaxSnackCount() const;
	void addSnack(Snack*);
	void initSlot(Snack*);
	double buySnack();
	void slotInfo();
private:
	const int maxSnackCount = 10;
	int snackCount = 0;
	Snack **p_snack = nullptr;
};

class VendingMachine
{
public:
	VendingMachine();
	~VendingMachine();
	int getSlotCount() const;
	int getEmptySlotsCount() const;
	void addSlot(SnackSlot*);
private:
	int slotCount;
	const int maxSlotCount = 5;
	SnackSlot** p_slot = nullptr;
};

class CashRegister
{
public:
	CashRegister(double cashIn = 0);
	double getCurrentBalance() const;
	void acceptAmount(double amountIn);
private:
	double cashInVM;
};
