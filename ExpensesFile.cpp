#include <iostream>
#include <string>
#include "ExpensesFile.h"
#include "Markup.h"

using namespace std;

void ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup XMLfile;
    XMLfile.Load(fileName);
    if(!XMLfile.FindElem("expenses")) {
        XMLfile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        XMLfile.AddElem("expenses");
    }

    XMLfile.IntoElem();
    XMLfile.AddElem( "expense");
    XMLfile.IntoElem();
    XMLfile.AddElem( "expenseId", expense.getExpenseId());
    XMLfile.AddElem( "userId", expense.getUserId());
    XMLfile.AddElem( "date", expense.getDate());
    XMLfile.AddElem( "item", expense.getItem());
    XMLfile.AddElem( "amount", amountConvertion.convertDoubleToString(expense.getAmount()));
    XMLfile.OutOfElem();

    XMLfile.Save(fileName);
}

int ExpensesFile::loadAllUserExpenses(vector<Expense> &expenses, int loggedUserId) {

    Expense expense;
    CMarkup XMLfile;
    int lastExpenseId = 0;

    if(XMLfile.Load(fileName)) {
        if(XMLfile.FindElem("expenses")) {
            XMLfile.IntoElem();
            while(XMLfile.FindElem("expense")) {
                XMLfile.IntoElem();
                XMLfile.FindElem("expenseId");
                expense.setExpenseId(atoi(XMLfile.GetData().c_str()));
                lastExpenseId = expense.getExpenseId();

                XMLfile.FindElem("userId");

                if(loggedUserId == atoi(XMLfile.GetData().c_str())) {

                    XMLfile.FindElem("userId");
                    expense.setUserId(atoi(XMLfile.GetData().c_str()));

                    XMLfile.FindElem("date");
                    expense.setDate(atoi(XMLfile.GetData().c_str()));

                    XMLfile.FindElem("item");
                    expense.setItem(XMLfile.GetData());

                    XMLfile.FindElem("amount");
                    expense.setAmount(amountConvertion.convertStringToDouble(XMLfile.GetData().c_str()));

                    expenses.push_back(expense);
                }
                XMLfile.OutOfElem();
            }
        }
    }
    return lastExpenseId;
}

int ExpensesFile::getLastExpenseIdFromFile() {
    int lastExpenseId;
    CMarkup XMLfile;
    XMLfile.Load(fileName);

    if(!XMLfile.FindElem("expenses"))
        return 1;
    else {
        XMLfile.IntoElem();
        while(XMLfile.FindElem("expense")) {
            XMLfile.IntoElem();

            XMLfile.FindElem("expenseId");
            lastExpenseId = atoi(MCD_2PCSZ(XMLfile.GetData()));

            XMLfile.OutOfElem();
        }
        return ++lastExpenseId;
    }
}
