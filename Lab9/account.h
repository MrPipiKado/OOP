#ifndef CLASSSS_COMPLEX_H
#define CLASSSS_COMPLEX_H

#include <cmath>
#include <string>
#include <utility>

class Account
{
public:
    explicit Account(std::string name = "", std::string surname = "",
            double sum = 0., int term = 0):
            name(std::move(name)), surname(std::move(surname)), sum(sum), term(term){};
    Account(const Account& old);
    virtual ~Account()= default;

    std::string get_name() const;
    void set_name(std::string new_name);
    std::string get_surname() const;
    void set_surname(std::string new_surname);
    double get_sum() const;
    void set_sum(double new_sum);
    int get_term() const;
    void set_term(int new_term);

    virtual double get_result() = 0;
    virtual std::string print() = 0;
protected:
    std::string name;
    std::string surname;
    double sum;
    int term;
};

//-------------------------------------------------------------------------------------------

class AccountPercent : virtual public Account
{
public:
    explicit AccountPercent(std::string name = "", std::string surname = "",
    double sum = 0., int term = 0, double percentage_of_year = 0.):
    Account(std::move(name), std::move(surname), sum, term),
    percentage_of_year(percentage_of_year){}
    AccountPercent(const AccountPercent& old);
    ~AccountPercent()= default;

    double get_percentage_of_year() const;
    void set_percentage_of_year(double new_percentage);

    std::string print() override;
    double get_result() override;
protected:
    double percentage_of_year;
};

//--------------------------------------------------------------------------------------------

class AccountProgressive : virtual public Account
{
public:
    explicit AccountProgressive(std::string name = "", std::string surname = "",
                       double sum = 0., int term = 0, const double *percentage = nullptr):
            Account(std::move(name), std::move(surname), sum, term)
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

    void get_percentage(double *dest) const;
    void set_percentage(const double *new_percentage);

    double get_result() override;
    std::string print() override;
protected:
    double *percentage;
};

//-------------------------------------------------------------------------------------------

class AccountMulti: public AccountPercent, public AccountProgressive
{
public:
    explicit AccountMulti(std::string name = "", std::string surname = "",
        double sum = 0., int term = 0,
        double percentage_of_year = 0.,const double *percentage = nullptr):
        Account(std::move(name), std::move(surname), sum, term),
        AccountPercent(std::move(name), std::move(surname), sum, term, percentage_of_year),
        AccountProgressive(std::move(name), std::move(surname), sum, term, percentage){}

    AccountMulti(const AccountMulti &old);

    double get_result() override;
    std::string print() override;
};

#endif //CLASSSS_COMPLEX_H
