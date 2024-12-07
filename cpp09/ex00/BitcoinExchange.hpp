
#include <map>
#include <iostream>

#define DATA_PATH "data.csv"

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void process(std::string input);
    private:
        std::map<std::string, float> _data;
};

