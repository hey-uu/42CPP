#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/** PUBLIC **/
Account::Account(int initial_deposit)
{
    // common
    _nbAccounts++;
    _totalAmount += initial_deposit;
    // unique
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    // message
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed";
    std::cout << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
    // before making deposit
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    // common
    _totalAmount += deposit;
    _totalNbDeposits++;
    // unique
    _amount += deposit;
    _nbDeposits++;
    // after making deposit
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    // before making withdrawal
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    // making withdrawal
    if (checkAmount() < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    // common
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    // unique
    _amount -= withdrawal;
    _nbWithdrawals++;
    // after making withdrawal
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

/** PRIVATE **/
Account::Account(void)
{
}

void Account::_displayTimestamp(void)
{
    // std::cout << "[19920104_091532] ";
    time_t timer = time(NULL);
    struct tm *t = localtime(&timer);

    std::cout << "[";
    std::cout << std::setw(4) << std::setfill('0') << t->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << t->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_sec;
    std::cout << "] ";
}
