#include "accounts.h"

#include <utility>
std::string Account::print()
{
    return "Account";
}
std::string AccountProgressive::print()
{
    return "AccountProgressive";
}
std::string AccountPercent::print()
{
    return "AccountPercent";
}

std::string Account::print(std::string smth)
{
    return "Account" + smth;
}

std::string AccountProgressive::print(std::string smth)
{
    return "AccountProgressive" + smth;
}

std::string AccountPercent::print(std::string smth)
{
    return "AccountPercent" + smth;
}


Account::Account(const Account &old)
{
    this->name = old.get_name();
    this->surname = old.get_surname();
    this->sum = old.get_sum();
}

std::string Account::get_name() const
{
    return name;
}

void Account::set_name(std::string new_name)
{
    this->name = std::move(new_name);
}

std::string Account::get_surname() const
{
    return surname;
}

void Account::set_surname(std::string new_surname)
{
    this->surname = std::move(new_surname);
}

double Account::get_sum() const
{
    return sum;
}

void Account::set_sum(double new_sum)
{
    this->sum = new_sum;
}



AccountPercent::AccountPercent(const AccountPercent &old)
{
    this->name = old.get_name();
    this->surname = old.get_surname();
    this->sum = old.get_sum();
    this->term = old.get_term();
    this->percentage = old.get_percentage();
}

int AccountPercent::get_term() const
{
    return term;
}

void AccountPercent::set_term(int new_term)
{
    this->term = new_term;
}

double AccountPercent::get_percentage() const
{
    return percentage;
}

void AccountPercent::set_percentage(double new_percentage)
{
    this->percentage = new_percentage;
}

double AccountPercent::get_result()
{
    double tmp = sum;
    for(int i = 0; i<term; ++i)
        tmp *= 1 + percentage/100;
    return tmp;
}



AccountProgressive::AccountProgressive(const AccountProgressive &old)
{
    this->name = old.get_name();
    this->surname = old.get_surname();
    this->sum = old.get_sum();
    this->term = old.get_term();
    this->percentage = new double[term];
    old.get_percentage(this->percentage);
}

int AccountProgressive::get_term() const
{
    return term;
}

void AccountProgressive::set_term(int new_term)
{
    this->term = new_term;
    delete [] this->percentage;
    this->percentage = new double[new_term];
}

void AccountProgressive::get_percentage(double *dest) const
{
    for(int i = 0; i<term; ++i)
        dest[i] = this->percentage[i];
}

void AccountProgressive::set_percentage(const double *new_percentage)
{
    for(int i = 0; i<term; ++i)
        this->percentage[i] = new_percentage[i];
}

double AccountProgressive::get_result()
{
    double tmp = sum;
    for(int i = 0; i<term; ++i)
        tmp *= 1 + percentage[i]/100;
    return tmp;
}
