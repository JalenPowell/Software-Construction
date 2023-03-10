 /* FILE NAME:Project1_Powell_Jrp0086.cpp.
  * AUTHOR: Solution Briefing
  * Jalen Powell, Jrp0086, Project1_Powell_Jrp008_,
  * 
  */

 #include <iostream>


 using namespace std; 

 int main() {
     // VARIABLE INITIALIZATION
        double interestRate = 0;
        double interestRateC = 0;
        double loan = 0;
        double monthlyPaid = 0;
        double interestTotal = 0;
        int currentMonth = 0;
        double tensa = 0;
        double interestAmt = 0;
        

     // CURRENCY FORMATTING
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     cout.precision(2);

     // USER INPUT
     cout << "\nLoad Amount: ";
     cin >> loan;

     while(true) {
     cout << "Interest Rate (% per year): ";
     cin >> interestRate;
     if(interestRate>0)   {
       break;
     }
      else{
        cout<<"Interest rate must be positive.\n";
      }
     }

     // GET PROPER INTEREST RATES FOR CALCULATIONS
     interestRate /= 12;
     interestRateC = interestRate / 100;
     
     while (true) {
     cout << "Monthly Payments: ";
     cin >> monthlyPaid;
    
     if (monthlyPaid < 0) {
       return 1;
       }  
       else{
       cout << "Monthly payment must be less than loan amount.\n";
        }
     
     cout << endl; 

     // AMORTIZATION TABLE
     cout << "*****************************************************************\n"
          << "\tAmortization Table\n"
          << "*****************************************************************\n"
          << "Month\tBalance\t\tPayment\tRate\tInterest\tPrinciple\n";

     // LOOP TO FILL TABLE
     while (loan > 0) {
       if (currentMonth == 0) {
         cout << currentMonth++ << "\t$"<< loan;
        if (loan < 1000) cout << "\t" ; // Formatting MAGIC
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
       } 
         
       else {
         interestAmt = loan * (interestRateC);
         interestTotal += interestAmt;
         tensa = (monthlyPaid - interestAmt);

         //if else statement
         if (loan > monthlyPaid) {
           loan -= tensa;
         }
         else {
           tensa = loan;
           monthlyPaid = loan + interestAmt;
           loan = 0; 
         }

         if (loan < 1000) {
                cout << currentMonth++ << "\t$" << loan << "\t\t" << monthlyPaid << "\t" 
                    << interestRate << "\t" << interestAmt << "\t\t" << tensa << "\n";
            } else {
                cout << currentMonth++ << "\t$" << loan << "\t" << monthlyPaid << "\t" 
                    << interestRate << "\t" << interestAmt << "\t\t" << tensa << "\n";             
            }
       }
     }
        
      cout << "****************************************************************\n";
             cout << "\nIt takes " << --currentMonth << " months to pay off "
                  << "the loan.\n"
                  << "Total interest paid is: $" << interestTotal;
             cout << endl << endl;
              return 0;

     }
 }
 