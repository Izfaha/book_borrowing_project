#include "header.h"

void aligmentPosition(const string text, int width, const string str)
{
    // this if condition for str option such as, "left", "right", "center"
    if (str == "left")
    {
        cout << left << setw(width) << text << endl;
    }
    else if (str == "right")
    {
        cout << right << setw(width) << text << endl;
    }
    else if (str == "center")
    {
        int padding = (width - text.length()) / 2;
        if (padding > 0)
        {
            cout << string(padding, ' ') << text << endl;
        }
        else
        {
            cout << text << endl; // no padding
        }
    }
    else
    {
        cout << "Invalid Aligment Options!";
    }
}

// void for header program
void headerScript()
{
    cout << "########################################\n";
    aligmentPosition("Library Book Store Apps", 40, "center");
    aligmentPosition("Created by Fa'iz Maulana Habibi", 40, "center");
    cout << "########################################\n";
    cout << endl;
}

// function IDR format like Rp in this case
string formatIDRCurrency(double idr)
{
    ostringstream IDRformatter;

    // add the "Rp. " symbol
    IDRformatter << "Rp. ";

    // format the number with thousand separators
    IDRformatter.imbue(locale("en_US.UTF-8"));       // A 'locale' determines how numbers, dates, and other data are formatted for a specific region.
    IDRformatter << fixed << setprecision(2) << idr; // arrange to idr formater like ; Rp. 100,000.00

    return IDRformatter.str();
}

void inputBookData(dataLib dataInfo[], int &count)
{
    cout << "Masukan Nama: ";
    getline(cin, dataInfo[count].buyerName);
    // cin.ignore();
    cout << "Judul buku: ";
    getline(cin, dataInfo[count].bookTitle);
    // cin.ignore();
    cout << "Nama Author buku: ";
    getline(cin, dataInfo[count].bookAuthor);
    // cin.ignore();
    cout << "Tahun publish buku: ";
    cin >> dataInfo[count].bookPublish;
    cout << "Jumlah Buku: ";
    cin >> dataInfo[count].amountOfBook;
    cout << "Harga per/Buku: ";
    cin >> dataInfo[count].perBookPrice;
    cin.ignore();

    // number discount user costing over 10 book
    /*
    if discount :
    book > 3 disc 5%
    book > 6 disc 10%
    */
    double totalPrice = dataInfo[count].perBookPrice * dataInfo[count].amountOfBook;

    if (dataInfo[count].amountOfBook > 3 && dataInfo[count].amountOfBook <= 5)
    {
        /*
        Diskon 5% with formula total price = (price per book x number of book) - discount
        */
        cout << "You get discount 5%\n";
        totalPrice *= 0.95; // 5%
    }
    else if (dataInfo[count].amountOfBook > 6)
    {
        /*
        Diskon 10% with formula total price = (price per book x number of book) - discount
        */
        cout << "You get discount 10%\n";
        totalPrice *= 0.90; // 10%
    }
    else
    {
        cout << "No discount applied\n";
    }

    dataInfo[count].priceBookTotal = totalPrice;
    cout << "Yang harus anda bayarkan adalah " << formatIDRCurrency(totalPrice) << endl; // altering = changing to IDR or Indonesian Rupiah
    cout << "====================================================================================\n";
    cout << endl;

    count++;
}

string outputDataFromInput(dataLib dataInfo[], int count)
{
    cout << "========================================================DATA PEMBELI BUKU========================================================\n";
    cout << left << setw(20) << "Nama Peminjam" << "|"
         << setw(20) << "Judul Buku" << "|"
         << setw(20) << "Nama Author buku" << "|"
         << setw(10) << "Tahun Publish buku" << "|"
         << setw(10) << "Jumlah buku" << "|"
         << setw(15) << "Harga per Buku" << "|"
         << setw(15) << "Total Bayar" << "|\n";
    cout << "=================================================================================================================================\n";

    for (int i = 0; i < count; i++)
    {
        cout << left << setw(20) << dataInfo[i].buyerName
             << "|" << setw(20) << dataInfo[i].bookTitle
             << "|" << setw(20) << dataInfo[i].bookAuthor
             << "|" << setw(10) << dataInfo[i].bookPublish
             << "|" << setw(10) << dataInfo[i].amountOfBook
             << "|" << setw(15) << formatIDRCurrency(dataInfo[i].perBookPrice)
             << "|" << setw(15) << formatIDRCurrency(dataInfo[i].priceBookTotal) << "|\n";
    }
    cout << "=================================================================================================================================\n";
    return "Output Completed\n";
}

void updateData(dataLib dataInfo[], int count)
{
    cout << "============================================================Update Book Data=======================================================\n";
    cout << "Masukan index data yang ingin diubah (1 - " << count << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > count)
    {
        cout << "Index tidak valid.\n";
        return;
    }
    
    index --;
    cout << "Mengubah data untuk: " << dataInfo[index].buyerName << endl;
    inputBookData(dataInfo, index);
    cout << "===================================================================================================================================\n";
}