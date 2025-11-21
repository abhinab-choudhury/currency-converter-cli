#ifndef CURRENCY_CONVERTER_CLI_MENU_H
#define CURRENCY_CONVERTER_CLI_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
  #include <sys/ioctl.h>
#endif


class Menu {
    static const int BLOCK_WIDTH = 58;

    int getTerminalWidth();
    void printCenter(const std::string& text);
    void printTwoColumnTable(const std::vector<std::string>& items);
public:
    void printBlockLine(const std::string& line);
    void printBlockNewLine(const std::string& line);
    void showConvertMenu(const std::vector<std::string>& options);
};


#endif
