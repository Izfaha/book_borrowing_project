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
        cin.ignore();

        switch (choice) {
            case 1:
                inputBookData(information, iteration);
                break;
            case 2:
                outputDataFromInput(information, iteration);
                break;
            case 3:
                updateData(information, iteration);
                break;
            case 4:
                return 0;
            default:
                cout << "Option is not valid\n";
        }
        cout << endl;
    }
    return 0;
}
