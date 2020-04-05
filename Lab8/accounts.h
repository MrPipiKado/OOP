#ifndef CLASSSS_COMPLEX_H
#define CLASSSS_COMPLEX_H

#include <cmath>
#include <string>
#include <utility>

class Account
{
public:
    Account():name(""), surname(""), sum(0){};
    Account(std::string name, std::string surname):
            name(std::move(name)), surname(std::move(surname)), sum(0){};
    Account(std::string name, std::string surname, double sum):
            name(std::move(name)), surname(std::move(surname)), sum(sum){};;
    Account(const Account& old);
    ~Account()= default;;
    std::string print();
    std::string print(std::string smth);

    std::string get_name() const;
    void set_name(std::string new_name);
    std::string get_surname() const;
    void set_surname(std::string new_surname);

    double get_sum() const;
    void set_sum(double new_sum);
protected:
    std::string name;
    std::string surname;
    double sum;
};

class AccountPercent : public Account
{
public:
    AccountPercent():Account(), term(0), percentage(0){};
    AccountPercent(std::string name, std::string surname, double sum):
    Account(std::move(name), std::move(surname), sum),term(0), percentage(0){};
    AccountPercent(std::string name, std::string surname,
                   double sum, int term, double percentage):
            Account(std::move(name), std::move(surname), sum),
            term(term), percentage(percentage){};
    AccountPercent(const AccountPercent& old);
    ~AccountPercent()= default;;
    std::string print();
    std::string print(std::string smth);

    int get_term() const;
    void set_term(int new_term);

    double get_percentage() const;
    void set_percentage(double new_percentage);

    double get_result();
protected:
    int term;
    double percentage;
};

class AccountProgressive : public Account
{
public:
    AccountProgressive():Account(), term(0)
    {
        percentage = new double [1];
        *percentage = 0;
    };
    AccountProgressive(std::string name, std::string surname, double sum):
            Account(std::move(name), std::move(surname), sum),
            term(0)
    {
        percentage = new double [1];
        *percentage = 0;
    }
    AccountProgressive(std::string name, std::string surname,
                       double sum, int term, const double *percentage):
            Account(std::move(name), std::move(surname), sum), term(term)
    {
        this->percentage = new double [term];
        for(int i = 0; i<term; ++i)
            this->percentage[i] = percentage[i];
    }
    AccountProgressive(const AccountProgressive &old);
    ~AccountProgressive()
    {
        delete[] percentage;
    }
    std::string print();
    std::string print(std::string smth);

    int get_term() const;
    void set_term(int new_term);
    void get_percentage(double *dest) const;
    void set_percentage(const double *new_percentage);

    double get_result();
protected:
    int term;
    double *percentage;
};

#endif //CLASSSS_COMPLEX_H

