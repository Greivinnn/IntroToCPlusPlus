#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace CustomerInfo
{
    class Customer
    {
    public:
        Customer(std::string customerName, int phoneNumber, std::string customerEmail, int customerID);
        void PrintCustomerListInAdmin();
        void PrintCustomerList();
    private:
        std::string M_customerName;
        int M_phoneNumber;
        std::string M_customerEmail;
        int M_customerID;
    };
}
