#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Declare files
ifstream inFile;
ofstream outFile;

//Declare variables
int account_num;
char account_type;
char sub_acc_type;
float min_balance;
float current_balance;
float interest;
float service_charge;

//Delclare functions
float compute_service_charge(float, float, char);
float compute_interest(float, float, char, char);
void print_report(char, char, float, float);
string find_acct_type(char, char);
float print_new_balance(float, float, float);

//Main
int main() {
  //Call line variable
  int line = 0;
  //Open File
  inFile.open("infile.txt");
  //Read file
  while(line < 5){
    inFile >> account_num >> account_type >> sub_acc_type >> min_balance >> current_balance;

    compute_service_charge(min_balance,  current_balance,  sub_acc_type);
    compute_interest(min_balance, current_balance, sub_acc_type, account_type);
    print_new_balance(interest, service_charge,  current_balance);
    print_report(account_type, sub_acc_type, account_num,  current_balance);
    find_acct_type(sub_acc_type, account_type);

    line++; 
  }
  //Close File
  inFile.close();
}

//Service Charge
float compute_service_charge(float min_balance, float current_balance, char sub_acc_type ){
  float service_charge;
  //Checking
  switch (sub_acc_type){
    case 'b':
    service_charge = 5.00;
    case 'P':
    service_charge = 15.00;
    case 'E':
    service_charge = 20.00;
    case 'J':
    service_charge = 1.00;
    case 'S':
    service_charge = 3.00;
    case 'C':
    service_charge = 10.00;
    case 'h':
    service_charge = 25.00;
    case 'D':
    service_charge = 75.00;
  }
  return service_charge;
}

//Interest
float compute_interest(float min_balance, float current_balance, char sub_acc_type, char account_type){
  float interest;
  //Checking
  if (account_type == 'C' || current_balance > 5000){
    interest = current_balance * 0.005;
  }
  //Savings
  else if (account_type == 'S'){
    switch (sub_acc_type){
      case 'J':
      interest = current_balance * 0.01;
      case 'S':
      interest = current_balance * 0.02;
      case 'C':
      interest = current_balance * 0.03;
      case 'H':
      interest = current_balance * 0.05;
      case 'D':
      interest = current_balance * 0.08;
    }
  }
  return interest;
}

//New balance
float print_new_balance(float interest, float service_charge, float current_balance){
float new_balance;

  new_balance = current_balance - (compute_service_charge(min_balance, current_balance, sub_acc_type)) + (compute_interest(min_balance, current_balance, sub_acc_type, account_type));
  return new_balance;

}

//Translate account type
string find_acct_type(char sub_acc_type, char account_type){
  string print_sub_acc = "";

  if (account_type == 'C'){
    switch (sub_acc_type){
      case 'b':
        print_sub_acc = "Basic Checking Account";
        break;
      case 'P':
        print_sub_acc = "Premier Checking Account";
        break;
      case 'E':
        print_sub_acc = "Elite Checking Account";
        break;
      case 'J':
        print_sub_acc = "Junior Checking Account";
        break;
      case 'S':
        print_sub_acc = "Student Checking Account";
        break;
      case 'C':
        print_sub_acc = "Classic Checking Account";
        break;
      case 'h':
        print_sub_acc = "High-Yield Checking Account";
        break;
      case 'D':
        print_sub_acc = "Diamond Checking Account";
        break;
  
    }

  }
  else if(account_type == 'S'){
      switch (sub_acc_type){
      case 'b':
        print_sub_acc = "Basic Savings Account";
        break;
      case 'P':
        print_sub_acc = "Premier Savings Account";
        break;
      case 'E':
        print_sub_acc = "Elite Savings Account";
        break;
      case 'J':
        print_sub_acc = "Junior Savings Account";
        break;
      case 'S':
        print_sub_acc = "Student Savings Account";
        break;
      case 'C':
        print_sub_acc = "Classic Savings Account";
        break;
      case 'h':
        print_sub_acc = "High-Yield Savings Account";
        break;
      case 'D':
        print_sub_acc = "Diamond Savings Account";
        break;
    }    
  }
  return print_sub_acc;
}

//Print report 
void print_report(char account_type, char sub_acc_type, float account_num, float current_balance){

      cout << "************************************" << endl << "Account Number: " << account_num << endl; 
      cout << "Account Type: " << find_acct_type(sub_acc_type, account_type) << endl << 
      fixed << setprecision(2) <<
      "Previous Balance: $" << current_balance << endl << 
      "Service Charge: $" << compute_service_charge(min_balance, current_balance, sub_acc_type) << endl <<
     "Interest Earned: $" << compute_interest(min_balance, current_balance, sub_acc_type, account_type) << endl <<
      "New Balance: $" << print_new_balance(interest, service_charge, current_balance) << endl;
}
