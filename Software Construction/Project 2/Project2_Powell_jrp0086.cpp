/**
 * @file Project2_Powell_jrp0086.ccp.cpp
 * @author Jalen Powell (jrp0086@auburn.edu)
 * @brief To learn “while” and “do-while” statements
 * @version 0.1
 * @date 2021-02-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<iostream>

#include<stdlib.h>

#include<assert.h>

#include<ctime>

using namespace std;

// VARIABLES
int aaronWins = 0;
int aaronWins2 = 0;
int bobWins = 0;
int charlieWins = 0;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;

const int TOTAL_RUNS = 10000;
const int AARON_ACCURACY = 100/3;
const int BOB_ACCURACY = 100/2;

bool at_least_two_alive(bool aaronAlive, bool bobAlive, bool charlieAlive) {

    if (aaronAlive && bobAlive || aaronAlive && charlieAlive || bobAlive && charlieAlive) {
        return true;
    }
    else {
        return false;
    }
}

void test_at_least_two_alive(void) {

    cout << "Unit Testing 1: Function - at_least_two_alive()\n";
    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    aaronAlive = false;
    bobAlive = true;
    charlieAlive = true;

    assert(true == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    aaronAlive = true;
    bobAlive = false;
    charlieAlive = true;

    assert(true == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    aaronAlive = true;
    bobAlive = true;
    charlieAlive = false;

    assert(true == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    aaronAlive = false;
    bobAlive = false;
    charlieAlive = true;

    assert(false == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    aaronAlive = false;
    bobAlive = true;
    charlieAlive = false;

    assert(false == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    aaronAlive = true;
    bobAlive = false;
    charlieAlive = false;

    assert(false == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    aaronAlive = false;
    bobAlive = false;
    charlieAlive = false;

    assert(false == at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
    cout << "\tCase passed ...\n";

}

void Aaron_shoots1(bool& bobAlive, bool& charlieAlive) {

    int shootResult = rand() % 100;
    if (shootResult < AARON_ACCURACY) {

    if (charlieAlive) {
        //if (shootResult <= AARON_ACCURACY) {
            charlieAlive = false;
        }
     else {
        //if (shootResult <= AARON_ACCURACY){
            bobAlive = false;
        }
    } 
       
  
}

void  test_Aaron_shoots1(void) {

    cout << "Unit Testing 2: Function Aaron_shoots1(BobAlive, Charlie_alive)\n";

    bobAlive = true;
    charlieAlive = true;

    cout << "\tCase 1: Bob alive, Charlie alive\n"
          << "\t\tAaron is shooting at Charlie\n";

    Aaron_shoots1(bobAlive, charlieAlive);

    bobAlive = false;
    charlieAlive = true;

    cout << "\tCase 2: Bob dead, Charlie alive\n"
            << "\t\tAaron is shooting at Charlie\n";

    Aaron_shoots1(bobAlive, charlieAlive);

    bobAlive = true;
    charlieAlive = false;

    cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";

    Aaron_shoots1(bobAlive, charlieAlive);
}

void Bob_shoots(bool& aaronAlive, bool& charlieAlive){

    int shootResult = rand() % 100;
    if (shootResult < BOB_ACCURACY) {

    if (charlieAlive) {
        //if (shootResult <= BOB_ACCURACY) {
            charlieAlive = false;
    }
        else {
            //if (shootResult <= BOB_ACCURACY)
            aaronAlive = false;
        }   
    }
    
}

void test_Bob_shoots(void) {

    cout << "Unit Testing 3: Function Bob_shoots(aaronAlive, charlieAlive)\n";

        aaronAlive = true;
        charlieAlive = true;

    cout << "\tCase 1: Aaron alive, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";

    Bob_shoots(aaronAlive, charlieAlive);

        aaronAlive = false;
        charlieAlive = true;

    cout << "\tCase 2: Aaron dead, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";

    Bob_shoots(aaronAlive, charlieAlive);

        aaronAlive = true;
        charlieAlive = false;
    
    cout << "\tCase 3: Aaron alive, Charlie dead\n"
        << "\t\tBob is shooting at Aaron\n";
    
    Bob_shoots(aaronAlive, charlieAlive);
}

void Charlie_shoots(bool& aaronAlive, bool& bobAlive) {

    if (bobAlive){
        bobAlive = false;

    }
    else {
        aaronAlive = false;
    }
}

void test_Charlie_shoots(void) {

    cout << "Unit Testing 4: Function Charlie_shoots(aaronAlive, bobAlive)\n";

    aaronAlive = true;
    bobAlive = true;

    cout << "\tCase 1: Aaron alive, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";

    Charlie_shoots(aaronAlive, bobAlive); 

    aaronAlive = false;
    bobAlive = true;

    cout << "\tCase 2: Aaron dead, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";

    Charlie_shoots(aaronAlive, bobAlive);

    aaronAlive = true;
    bobAlive = false;

    cout << "\tCase 3: Aaron alive, Bob alive\n"
        << "\t\tCharlie is shooting at Aaron\n";

    Charlie_shoots(aaronAlive, bobAlive);
}

void Aaron_shoots2(bool& bobAlive, bool& charlieAlive) {

    if (bobAlive && charlieAlive) {
        return;
    }
    
    int shootResult = rand() % 100;
    if (shootResult < AARON_ACCURACY) {

        if (charlieAlive) {
             charlieAlive = false;
        
        }
        else {
            //if (shootResult <= AARON_ACCURACY) {
             bobAlive = false;
        
        }
    }
}

void test_Aaron_shoots2(void) {

    cout << "Unit Testing 5: Function Aaron_shoots2(bobAlive, charlieAlive)\n";

    bobAlive = true;
    charlieAlive = true;

    cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron intentionally misses his first shot\n"
        << "\t\tBoth Bob and Charlie are alive\n";

    Aaron_shoots2(bobAlive, charlieAlive);

    bobAlive = false;
    charlieAlive = true;

    cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";

    Aaron_shoots2(bobAlive, charlieAlive);

    bobAlive = true;
    charlieAlive = false;

    cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";

    Aaron_shoots2(bobAlive, charlieAlive);
}

void Press_any_key(void) {
    cout << "Press any key to continue...";
    cin.ignore().get(); //Pause Command for Linux Terminal
}

//START OF MAIN
int main() {

    //Initializes Random number generator's seed and calls test functions

    cout << "*** Welcome to Jalen's Duel Simulator ***\n";
    srand(time(0));

    test_at_least_two_alive();

    Press_any_key();

    test_Aaron_shoots1();

    Press_any_key();

    test_Bob_shoots();

    Press_any_key();

    test_Charlie_shoots();

    Press_any_key();

    test_Aaron_shoots2();

    Press_any_key();

    //Starts strategy 1 and runs 10,000

    cout << "Ready to test strategy 1 (run 10000 times):\n";

    Press_any_key();

    for (int i = 0; i < TOTAL_RUNS; i++) {

        //initialize all three competitiors as alive
        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {

            if (aaronAlive) {
                Aaron_shoots1(bobAlive, charlieAlive);
            }

            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }

            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }

        }
        

        if (aaronAlive) {
            aaronWins++;
        }
        else if (bobAlive) {
            bobWins++;
        }
        else {
            charlieWins++;
        }


    }

    cout << "Aaron won " << aaronWins << "/10000 duels or " << static_cast<double>(aaronWins) /
        TOTAL_RUNS * 100 << "%\n"

        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS
        * 100 << "%\n"
        
        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
        TOTAL_RUNS * 100 << "%\n"

        << endl;

    
    //Reinitializes variables and start strategy 2 to run 10,000 times

    bobWins = 0;
    charlieWins = 0;

    cout << "Ready to test strategy 2 (run 10000 times):\n";

        Press_any_key();

        for (int i = 0; i < TOTAL_RUNS; i++) {
            
            aaronAlive = true;
            bobAlive = true;
            charlieAlive = true;

            while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {

                if (aaronAlive) {
                    Aaron_shoots2(bobAlive, charlieAlive);
                }

                if (bobAlive) {
                    Bob_shoots(aaronAlive, charlieAlive);
                }
                
                if (charlieAlive) {
                    Charlie_shoots(aaronAlive, bobAlive);
                }
            }
             if (aaronAlive) {
                aaronWins2++;
             }

             if (bobAlive) {
                 bobWins++;
             }

             if (charlieAlive) {
                 charlieWins++;
             }
        }
    
    cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) /
        TOTAL_RUNS * 100 << "%\n"

        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS
        * 100 << "%\n"
        
        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
        TOTAL_RUNS * 100 << "%\n"

        << endl;

    if (aaronWins > aaronWins2) {
        cout << "Strategy 1 is better than Strategy 2.\n";
    }
    else {
        cout << "Strategy 2 is better than Strategy 1.\n";
    }
    return 0;

}