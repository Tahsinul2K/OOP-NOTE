#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string productName;
    string productID;
    double price;
    int stockChanges[100];
    int numStockChanges;
public:
    void addStock(int amount)
    {
        stockChanges[numStockChanges++] = amount;
    }
    void reduceStock(int amount)
    {
        for(int i = 0 ; i < numStockChanges ; i++)
        {
            if(stockChanges[i] == amount)
            {
                for(int j= i+1 ; j < numStockChanges ; j++)
                {
                    stockChanges[j-1] = stockChanges[j];
                }
            }
        }
    }
}