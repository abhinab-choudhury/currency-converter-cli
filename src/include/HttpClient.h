
#ifndef CURRENCY_CONVERTER_CLI_HTTPCLIENT_H
#define CURRENCY_CONVERTER_CLI_HTTPCLIENT_H

#include <string>
#include <curl/curl.h>
#include "json.h"

class HttpClient {
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output);
public:
    std::string get(const std::string& path);
};

#endif
