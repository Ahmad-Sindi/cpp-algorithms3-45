#include <iostream>
#include <string>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #45 Convert Record to Line
 *
 * This program reads bank client data as a structured record and converts it into a single formatted text line suitable for file storage or data serialization.
 *
 * The solution demonstrates how structured data (struct) can be transformed into a flat representation.
 *
 * Key focus:
 * - Struct-based data modeling
 * - User input handling
 * - Data serialization using separators
 */

// Structure to hold client data
struct ClientStructData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Reads client data from the user
ClientStructData ReadClientData()
{
    ClientStructData ClientData;

    cout << "Enter Account Number: ";
    getline(cin, ClientData.AccountNumber);

    cout << "Enter Pin Code: ";
    getline(cin, ClientData.PinCode);

    cout << "Enter Full Name: ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone Number: ";
    getline(cin, ClientData.Phone);

    cout << "Enter Account Balance: ";
    cin >> ClientData.AccountBalance;

    return ClientData;
}

// Converts a client record into a single line using a separator
string ConvertRecordToLine(
    ClientStructData Client,
    string Separator = "#//#")
{
    string ClientRecord = "";

    ClientRecord += Client.AccountNumber + Separator;
    ClientRecord += Client.PinCode + Separator;
    ClientRecord += Client.Name + Separator;
    ClientRecord += Client.Phone + Separator;
    ClientRecord += to_string(Client.AccountBalance);

    return ClientRecord;
}

int main()
{
    cout << "Please Enter Client Data:\n";

    ClientStructData ClientData = ReadClientData();

    cout << "\nClient Record for Saving:\n";
    cout << ConvertRecordToLine(ClientData);

    return 0;
}
