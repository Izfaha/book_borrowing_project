# Book Borrowing Project
> [!NOTE]
> This is a simple project to enhace my c++ coding ability.

### How does this program work?
The program has 4 option, it is 
1. Input Data.
2. Output Data.
3. Edit or Update Data.
4. Exit.

Each option is encapsulated within a dedicated function, with each function receiving multiple parameters.<br>

> 1. Input Data

This requires a user to type text, number and some special character if needed, such as Name's buyer ```(string)```, Book Title ```(string)```, The name of book author ```(string)```, Book Publish ```(integer)```, number of book ```(integer)```, Price per Book ```(integer)```.

Within the function, a conditional statement is implemented to apply a 5% discount if the user purchases between 3 and 5 books. For purchases exceeding 6 books, a 10% discount is allocated.<br>

> 2. Output Data

Option 2 will print the data filled by the user into table, like database.<br>

> 3. Edit or Update Data

This option will edit the previous data by selecting index of an data that saves into array.<br>

> 4. Exit

This option will terminate the program.<br>

## Build-in Functions
- First Function is :
```
void aligmentPosition(const string text, int width, const string str);
```
This function is for giving fix position of the given-text in the title of program.

Honestly, I establish a condition to align the position automatically by simply inputting a command like "left," ensuring it adjusts seamlessly to the specified alignment.

- Second Function is :
```
void headerScript();
```
Function for giving the title of the program.

In this function, I utilize the ```void alignmentPosition(const string text, int width, const string str);``` method to refine the header script.

- Third Function is :
```
string formatIDRCurrency(double idr);
```
The format is adjusted to IDR, representing Indonesian Rupiah (Rp). For example, when a user inputs a numerical value such as 2000, it will be formatted and displayed as Rp 2,000.00. 

- Fourth Function is :
```
void inputBookData(dataLib dataInfo[], int &count);
```
The function will ask for the user to answer all of the available queries. 

- Fith Function is :
```
string outputDataFromInput(dataLib dataInfo[], int count);
```
This function print the output of the input user.

- Sixth Function is :
```
void updateData(dataLib dataInfo[], int count);
```
This will update the past user input into a newer data.