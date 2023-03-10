/*
 * This program is tasked with merging the numbers in two files 
 * and writes all numbers into a third file
 * Name: Project3_Powell_jrp0086.cpp
 * Author: Jalen Powell
 * Date: 3/3/2021
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* declare your user-defined functions */
bool check_file(string);

/* do not forget to describe each function */
vector<int> read_file(string);

void write_file(string, vector<int>);

vector<int> merge(vector<int>, vector<int>);


bool check_file(string aizen) {

    /* Input file stream */
    ifstream stream;

    /* Check file */
    stream.open(aizen.c_str());
    if (stream.fail()) {
        stream.close();
        return false;
    }

    stream.close();

    return true;
}

vector<int> read_file(string aizen) {
    
    /* Input file stream. (ifstream) */
    ifstream stream;

    /* Vector containing numbers from file. (vector<int>) */
    vector<int> ichigo;

    /* Integer read from file. (int) */
    int i = 0;

    /* Add each number in the file to a vector. */
    stream.open(aizen.c_str());
    while (stream >> i) {
        ichigo.insert(ichigo.end(), i);
    }
    stream.close();

    return ichigo;
}

void write_file(string aizen, vector<int> ichigo) {

    /* Output file stream. (ofstream) */
    ofstream stream;

    stream.open(aizen.c_str());
    for (unsigned int i = 0; i < ichigo.size(); i++) {
        stream << ichigo.at(i) << endl;
    }
    stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {

    /* VARIABLES */
    vector<int> v3 = v1;

    /* Compare both vectors */
    v3.insert(v3.end(), v2.begin(), v2.end());
    
    sort(v3.begin(), v3.end());

    return v3;
}

void to_string(vector<int> ichigo) {

    for (unsigned short i = 0; i < ichigo.size(); i++) {
        cout << ichigo.at(i) << endl;
    }
    cout << endl;
}

/*
 * Merge the numbers in two files and write the numbers to third file
 * in ascending order.
 * 
 * Return: 1 program completed successfully. (int)
 */

int main() {
    
    /* VARIABLES */
    
    vector<int> ghouls1;
    vector<int> ghouls2;
    vector<int> kenList;
    string cayde1;
    string ikora2;
    string zavala3;

    cout << "*** Welcome to Jalen's sorting program ***" << endl;


    /* FILE 1 */

    do {
        cout << "Enter the first input file name: ";
        cin >> cayde1;

    } while (cin.fail() || !check_file(cayde1));

    /* Numbers from file one */
    ghouls1 = read_file(cayde1);
    cout << "The list of " << ghouls1.size()
         << " numbers in the file " + cayde1 + " is:\n";
    to_string(ghouls1);
    

    /* FILE 2 */

    do {
        /* user friendly interfaces */
        cout << "Enter the second input file name: ";
        cin >> ikora2;

    } while (cin.fail() || !check_file(ikora2));

    /* Numbers from file two */
    ghouls2 = read_file(ikora2);
    cout << "The list of " << ghouls2.size()
         << " numbers in file " + ikora2 + "is:\n";
    to_string(ghouls2);

    /* Combine vectors and display the sorted result */
    kenList = merge(ghouls1, ghouls2);
    cout << "The sorted list of " << kenList.size() << " numbers is: ";
    for (unsigned int i = 0; i < kenList.size(); i++) {
        cout << kenList.at(i) << " ";
    }
    cout << endl;

    /* OUTPUT */
    
    do {
        /* user friendly interfaces */
        cout << "Enter the output file name: ";
        cin >> zavala3;
    } while (cin.fail());

    /* Write combined vector in output */
    write_file(zavala3, kenList);
    
    cout << "*** Please check the new file - " + zavala3 + " ***" << endl
         << "*** Goodbye. ***\n";

    return 0;

}
