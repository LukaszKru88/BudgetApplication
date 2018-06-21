#include <iostream>
#include "Expense.h"

using namespace std;

Expense::Expense() {
    expenseId = 0;
    userId = 0;
    date = 0;
    item = "";
    amount = 0.0f;
}

Expense::~Expense() {;}

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

double Expense::getAmount() {
    return amount;
}

void Expense::setExpenseId(int expenseId) {
    this->expenseId = expenseId;
}

void Expense::setUserId(int userId) {
    this->userId = userId;
}

void Expense::setDate(int date) {
    this->date = date;
}

void Expense::setItem(string item) {
    this->item = item;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
}


