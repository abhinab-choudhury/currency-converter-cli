#ifndef CURRENCY_CONVERTER_CLI_CURRENCYCONVERTER_H
#define CURRENCY_CONVERTER_CLI_CURRENCYCONVERTER_H

#include <ctime>
#include <iomanip>
#include <string>
#include <curl/curl.h>

class CurrencyConverter {
public:
    float convert(std::string from, std::string to, float amount);
};

#endif
