#include "account.h"

#include <utility>

Account::Account(const Account &old)
{
    this->name = old.get_name();
    this->surname = old.get_surname();
    this->sum = old.get_sum();
    this->term = old.get_term();
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

int Account::get_term() const
{
    return term;
}

void Account::set_term(int new_term)
{
    this->term = new_term;
}

//-------------------------------------------------------------

AccountPercent::AccountPercent(const AccountPercent &old):
Account(old)
{
    this->percentage_of_year = old.get_percentage_of_year();
}

double AccountPercent::get_percentage_of_year() const
{
    return percentage_of_year;
}

void AccountPercent::set_percentage_of_year(double new_percentage)
{
    this->percentage_of_year = new_percentage;
}

double AccountPercent::get_result()
{
    double tmp = sum;
    for(int i = 0; i<term; ++i)
        tmp *= 1 + percentage_of_year / 100;
    return tmp;
}

std::string AccountPercent::print()
{
    return "AccountPercent";
}

//----------------------------------------------------------------------

AccountProgressive::AccountProgressive(const AccountProgressive &old):
Account(old)
{
    this->percentage = new double[term];
    old.get_percentage(this->percentage);
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

std::string AccountProgressive::print()
{
    return "AccountProgressive";
}

//-----------------------------------------------------------------------

AccountMulti::AccountMulti(const AccountMulti &old):
Account(old), AccountPercent(old), AccountProgressive(old)
{}

double AccountMulti::get_result()
{
    double tmp = sum;
    for(int i = 0; i<term; ++i)
    {
        tmp *= 1 + percentage_of_year / 100;
        tmp *= 1 + percentage[i]/100;
    }
    return tmp;
}

std::string AccountMulti::print()
{
    return "AccountMulti";
}
