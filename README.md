# Book Borrowing Project
> [!NOTE]
> This is a simple project to enhace my c++ coding ability.

### How does this program work?
The program has 4 option, it is 
1. Input Data.
2. Output Data.
3. Edit or Update Data.
4. Exit the program.

Each option is wrapped into a function and having several parameters of each.

## Build-in Functions
- First Function is :
```
void aligmentPosition(const string text, int width, const string str);
```
This function is for giving fix position of the given-text in the title of program.

- Second Function is :
```
void headerScript();
```
Function for giving the title of the program.

- Third Function is :
```
string formatIDRCurrency(double idr);
```
Setting the format from user to IDR or Indonesian Rupiah (Rp. ). For instance, if a user gives an input number like 2000, it'll be printed by Rp. 2,000.00. 