#include "header.h"

void aligmentPosition(const string text, int width, const string str){
    // this if condition for str option such as, "left", "right", "center" 
    if (str == "left"){
        cout << left << setw(width) << text << endl;
    } else if (str == "right"){
        cout << right << setw(width) << text << endl;
    } else if (str == "center"){
        int padding = (width - text.length()) / 2;
        if (padding > 0){
            cout << string(padding, ' ') << text << endl;
        } else {
            cout << text << endl; // no padding 
        }
    } else {
        cout << "Invalid Aligment Options!";
    }
}

// void for header program
void headerScript(){
    cout << "########################################\n";
    aligmentPosition("Library Book Store Apps", 40, "center");
    aligmentPosition("Created by Fa'iz Maulana Habibi", 40, "center");
    cout << "########################################\n";
    cout << endl;
}

// function IDR format like Rp in this case
string formatIDRCurrency(double idr){
    ostringstream IDRformatter;

    // add the "Rp. " symbol
    IDRformatter << "Rp. ";

    // format the number with thousand separators
    IDRformatter.imbue(locale("en_US.UTF-8")); // A 'locale' determines how numbers, dates, and other data are formatted for a specific region.
    IDRformatter << fixed << setprecision(2) << idr; // arrange to idr formater like ; Rp. 100,000.00 

    return IDRformatter.str();
}

void inputBookData(dataLib dataInfo[], int &count){
    cout << "Masukan Nama: "; 
    getline(cin, dataInfo[count].buyerName);
    cin.ignore(100, '\n');
    cout << "Judul buku: "; 
    getline(cin, dataInfo[count].bookTitle);
    cin.ignore(100, '\n');
    cout << "Nama Author buku: "; 
    getline(cin, dataInfo[count].bookAuthor);
    cin.ignore(100, '\n');
    cout << "Tahun publish buku:";
    cin >> dataInfo[count].bookPublish;
    cout << "Jumlah Buku: ";
    cin >> dataInfo[count].amountOfBook; 
    cout << "Harga per/Buku: ";
    cin >> dataInfo[count].perBookPrice;

    // number discount user costing over 10 book
    /*
    if discount :
    book > 3 disc 5%
    book > 6 disc 10% 
    */ 
    if(dataInfo[count].amountOfBook > 3 && dataInfo[count].amountOfBook <= 5){
        /*
        Diskon 5% with formula total price = (price per book x number of book) - discount
        */
        cout << "You get discount 5%\n";
        dataInfo[count].priceBookTotal = (dataInfo[count].perBookPrice * dataInfo[count].amountOfBook) - 0.05;  
    } else if (dataInfo[count].amountOfBook > 6){
        /*
        Diskon 10% with formula total price = (price per book x number of book) - discount
        */
        cout << "You get discount 10%\n";
        dataInfo[count].priceBookTotal = (dataInfo[count].perBookPrice * dataInfo[count].amountOfBook) - 0.10;
    } else {
        cout << "You don't get discount!\n";
        dataInfo[count].priceBookTotal = dataInfo[count].perBookPrice * dataInfo[count].amountOfBook;
    }
    // IDR currency problem in misscalculation 
    string changeToIDRFormat = formatIDRCurrency(dataInfo[count].priceBookTotal); // altering = changing to IDR or Indonesian Rupiah 
    cout << "Yang harus anda bayarkan adalah " << changeToIDRFormat << endl;

    count ++;
}
