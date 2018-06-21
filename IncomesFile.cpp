#include <iostream>
#include <string>
#include "IncomesFile.h"
#include "Markup.h"

using namespace std;

void IncomesFile::addIncomeToFile(Income income) {
    CMarkup XMLfile;
    XMLfile.Load(fileName);
    if(!XMLfile.FindElem("incomes")) {
        XMLfile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        XMLfile.AddElem("incomes");
    }

    XMLfile.IntoElem();
    XMLfile.AddElem( "income");
    XMLfile.IntoElem();
    XMLfile.AddElem( "incomeId", income.getIncomeId());
    XMLfile.AddElem( "userId", income.getUserId());
    XMLfile.AddElem( "date", income.getDate());
    XMLfile.AddElem( "item", income.getItem());
    XMLfile.AddElem( "amount", amountConvertion.convertDoubleToString(income.getAmount()));
    XMLfile.OutOfElem();

    XMLfile.Save(fileName);
}

int IncomesFile::loadAllUserIncomes(vector<Income> &incomes, int loggedUserId) {

    Income income;
    CMarkup XMLfile;
    int lastIncomeId = 0;

    if(XMLfile.Load(fileName)) {
        if(XMLfile.FindElem("incomes")) {
            XMLfile.IntoElem();
            while(XMLfile.FindElem("income")) {
                XMLfile.IntoElem();
                XMLfile.FindElem("incomeId");
                income.setIncomeId(atoi(XMLfile.GetData().c_str()));
                lastIncomeId = income.getIncomeId();

                XMLfile.FindElem("userId");

                if(loggedUserId == atoi(XMLfile.GetData().c_str())) {

                    XMLfile.FindElem("userId");
                    income.setUserId(atoi(XMLfile.GetData().c_str()));

                    XMLfile.FindElem("date");
                    income.setDate(atoi(XMLfile.GetData().c_str()));

                    XMLfile.FindElem("item");
                    income.setItem(XMLfile.GetData());

                    XMLfile.FindElem("amount");
                    income.setAmount(amountConvertion.convertStringToDouble(XMLfile.GetData().c_str()));

                    incomes.push_back(income);
                }
                XMLfile.OutOfElem();
            }
        }
    }
    return lastIncomeId;
}

int IncomesFile::getLastIncomeIdFromFile() {
    int lastIncomeId;
    CMarkup XMLfile;
    XMLfile.Load(fileName);

    if(!XMLfile.FindElem("incomes"))
        return 1;
    else {
        XMLfile.IntoElem();
        while(XMLfile.FindElem("income")) {
            XMLfile.IntoElem();

            XMLfile.FindElem("incomeId");
            lastIncomeId = atoi(MCD_2PCSZ(XMLfile.GetData()));

            XMLfile.OutOfElem();
        }
        return ++lastIncomeId;
    }
}
