#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
using namespace std;

struct dataLib{
    string buyerName;
    string bookTitle;
    string bookAuthor;
    double bookPublish;
    double amountOfBook;
    double perBookPrice;
    double priceBookTotal;
};

enum Position{LEFT, CENTRE, RIGHT};

void headerScript();
void inputBookData(dataLib[], int &count);