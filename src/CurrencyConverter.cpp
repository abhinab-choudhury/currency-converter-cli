#include "include/CurrencyConverter.h"
#include "include/HttpClient.h"

float CurrencyConverter::convert(std::string from, std::string to, float amount)
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    std::stringstream ss;
    ss << std::put_time(now, "%Y-%m-%d");
    std::string date = ss.str();

    HttpClient client;
    std::string url =
            "https://api.fxratesapi.com/convert"
            "?from="   + from +
            "&to="     + to +
            "&date="   + date +
            "&amount=" + std::to_string(amount) +
            "&format=json";
    std::string response = client.get(url);

    if(response.empty())
    {
        throw std::runtime_error("Failed to fetch data");
    }

    using json = nlohmann::json;
    json data;
    try {
        data = json::parse(response);
    } catch (...) {
        throw std::runtime_error("API response missing 'result'");
    }

    return data["result"].get<float>();
}
