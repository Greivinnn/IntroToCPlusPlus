#include <iostream>
#include "Email.h"

using namespace std;

void Email::SendEmail()
{
    cout << "Sending email..." << endl;
    // Internal processes are abstracted
    TransmitData();
    cout << "Email sent!" << endl;
}

void Email::TransmitData()
{
    cout << "Transmitting data over the network." << endl;
}