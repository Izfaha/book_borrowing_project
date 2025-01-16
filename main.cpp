#include "header.h"

int main()
{

    int iteration = 0;
    dataLib information[100]; // '100' declare the number of array | // if array has been declared, no need to declare anymore
    while (true)
    {
        headerScript();
        cout << "PENGINAPAN ADEM AYEM\n";
        cout << "---------------------------------\n";
        cout << "[1] Input Data Penyewa\n";
        cout << "[2] Tampil Data Penyewa\n";
        cout << "[3] Ubah Data\n";
        cout << "[4] Keluar\n";
        cout << "Pilih Menu [1/2/3/4]: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            inputBookData(information, iteration); // in this function . "information[]" = is incorrect
            cout << endl;
        } else if (choice == 2){
            outputDataFromInput(information, iteration);
            cout << endl;
        } else if (choice == 3){
            char answer;
            updateData(information, iteration, answer);
            cout << endl;
        } else if (choice == 4){
            break;
        } else {
            cout << "Option is not falid\n";
        }
    }
    return 0;
}
