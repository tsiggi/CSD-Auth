#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
    public:
        Account(char *);
        Account (char *,float);
        virtual bool withdraw(float);
        bool deposit(float);
        float getBalance();
        char *getDescription();
    protected:
        float balance;
        char *description;
};

#endif // ACCOUNT_H