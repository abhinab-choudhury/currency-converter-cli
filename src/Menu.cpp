#include "include/Menu.h"

int Menu::getTerminalWidth()
{
    #ifdef _WIN32
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
            return csbi.srWindow.Right - csbi.srWindow.Left + 1;
        return 80;
    #else
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        return size.ws_col > 0 ? size.ws_col : 80;
    #endif
}

void Menu::printCenter(const std::string& text)
{
    int termWidth = getTerminalWidth();
    int padding = (termWidth - text.length())/ 2;
    if (padding < 0) padding = 0;

    std::cout << std::string(padding, ' ') << text << "\n";
}

void Menu::printBlockNewLine(const std::string& line)
{
    int termWidth = getTerminalWidth();
    int padding = (termWidth - BLOCK_WIDTH) / 2;
    if (padding < 0) padding = 0;

    std::cout << std::string(padding, ' ') << line << "\n";
}

void Menu::printBlockLine(const std::string& line)
{
    int termWidth = getTerminalWidth();
    int padding = (termWidth - BLOCK_WIDTH) / 2;
    if (padding < 0) padding = 0;

    std::cout << std::string(padding, ' ') << line << " ";
}

void Menu::printTwoColumnTable(const std::vector<std::string>& items)
{
    int termWidth = getTerminalWidth();
    const int gap = 4;

    size_t maxWidth = 0;
    for (const auto& item : items) {
        if (item.length() > maxWidth)
            maxWidth = item.length();
    }

    size_t totalRowWidth = maxWidth * 2 + gap;

    for (size_t i = 0; i < items.size(); i += 2)
    {
        std::stringstream ss;

        ss << std::left << std::setw(maxWidth) << items[i];
        ss << std::string(gap, ' ');

        if (i + 1 < items.size())
            ss << items[i + 1];

        printBlockNewLine(ss.str());
    }
}

void Menu::showConvertMenu(const std::vector<std::string>& options)
{
    printCenter("----------------------------------------------------------");
    printCenter("Currency Converter");
    printCenter("----------------------------------------------------------");
    printTwoColumnTable(options);
}
