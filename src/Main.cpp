
#include "include/Menu.h"
#include "include/CurrencyConverter.h"
#include <iostream>
#include <vector>

const std::vector<std::string> currencyArray = {
    "USD - United States Dollar",
    "EUR - Euro",
    "GBP - British Pound Sterling",
    "INR - Indian Rupee",
    "JPY - Japanese Yen",
    "AUD - Australian Dollar",
    "CAD - Canadian Dollar",
    "CHF - Swiss Franc",
    "CNY - Chinese Yuan Renminbi",
    "NZD - New Zealand Dollar",
    "SGD - Singapore Dollar",
    "SEK - Swedish Krona",
    "NOK - Norwegian Krone",
    "RUB - Russian Ruble",
    "KRW - South Korean Won",
    "ZAR - South African Rand",
    "BRL - Brazilian Real",
    "MXN - Mexican Peso",
    "AED - UAE Dirham",
    "SAR - Saudi Riyal"
};

int main(int argc, char *argv[]) {
    Menu menu;
    menu.showConvertMenu(currencyArray);

    menu.printBlockNewLine("");
    menu.printBlockNewLine("Enter the currency code in fields below");

    std::string fromCurrency, toCurrency;
    float amount = 0.0f;

    menu.printBlockLine("From:");
    std::cin >> fromCurrency;
    menu.printBlockLine("To:");
    std::cin >> toCurrency;
    menu.printBlockLine("Amount:");
    std::cin >> amount;

    CurrencyConverter converter;
    float result = converter.convert(fromCurrency, toCurrency, amount);
    const std::string resultString = std::to_string(amount) + " " +fromCurrency + " → " + std::to_string(result) + " " +toCurrency;
    menu.printBlockNewLine(resultString);

    return 0;
}
