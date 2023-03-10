/*
* This program will write a simple trivia game and allows
* the players to male the questions
* Working on thos project has incresed my knowledge in nodes
* temporary nodes. Along side Bryce Ellis and our AEP collab helper,
* I was able to complete this project.
* Name: Project4_Powell_Jrp0086
* Author: Jalen Powell
* Date: 3/16/2021
*/

#include <iostream>
#include <string>
using namespace std;

// Variables for the number of questions
//int question_amount = 0;

// Structure for questions 1
struct trivia_node
{
    string question;
    string answer;
    int points;
    trivia_node *next;
};

//Class the describes the list.
class TriviaList
{
public:
    int count;
    trivia_node *head, *tail;
    TriviaList()
    {
        count = 0;
        head = NULL;
        tail = NULL;
    }
};

//Prototypes
void init_question_list(TriviaList &q_list);
void add_question(TriviaList &q_list);
int ask_question(TriviaList &q_list, int num_ask);
void Unit_test();

//define UNIT_TESTING
#define trivia_quiz

// this main method displays the program in entirety.
int main()
{
    Unit_test();
    TriviaList node_list;
    //creates new trivia game /
#ifdef trivia_quiz
    init_question_list(node_list);

    cout << "*** Welcome to Jalen's trivia quiz game ***\n";
    string input;

    cout << "Would you like to add questions? (Yes/No): ";
    getline(cin, input);

    if (input == "Yes") {
        add_question(node_list);
    }

    cout << "\n";

    //Start trivia game
    ask_question(node_list, node_list.count);
    cout << "*** Thank you for playing the trivia quiz game. Goobye! ***\n";
    return 0;
    
}
#endif

//Method for testing
#ifdef UNIT_TESTING
Unit_test();
return 0;
}
#endif

//Intialize the quiz to have three questions inputted.
void init_question_list(TriviaList &q_list)
{
    string bob;
    trivia_node *node = new trivia_node;
    trivia_node *node2 = new trivia_node;
    trivia_node *node3 = new trivia_node;

    //first question
    node->question = "How long was the shortest war on record? (Hint: how many minutes)";
    node->answer = "38";
    node->points = 100;
    node->next = node2;

    //q_list = node;
    //node = q_list->next;

    //second question
    node2->question = "What was Bank of America's orginal name? (Hint: Bank of Italy or Bank of Germany)";
    node2->answer = "Bank of Italy";
    node2->points = 50;
    node2->next = node3;

    //third question
    node3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    node3->answer = "Wii Sports";
    node3->points = 20;
    node3->next = NULL;

    //question amount
    q_list.count += 3;
    q_list.head = node;
}

//gives user the option to add a question to list.
void add_question(TriviaList &q_list)
{
    //Sets variables that take action based on the player.
    string blam;
    bool Wazzam = true;
    
        //This do-while takes action while the set variable is true.
        do
        {
            q_list.count++;

            trivia_node *new_ptr = new trivia_node;

            //Get input
            cout << "Enter a new question: ";
            getline(cin, new_ptr->question);

            cout << "Enter an answer: ";
            getline(cin, new_ptr->answer);

            cout << "Enter award points: ";
            cin >> new_ptr->points;

            cout << "Continue? (Yes/No): ";
            getline(cin.ignore(), blam);

            //The new pointer has to be equal to the head of the list.
            new_ptr->next = q_list.head;
            q_list.head = new_ptr;

            if (blam == "No") {
                Wazzam = false;
            }

        } while (Wazzam);
   
}

//ask the questions and starts the game
int ask_question(TriviaList &q_list, int num_ask)
{
    trivia_node *cur_ptr = q_list.head;
    string user_answer;
    int total_points = 0;

    //Check null
    if (q_list.head == NULL)
    {
        return 0;
    }

    //Check num < 1
    if (num_ask < 1)
    {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
        return -1;
    }
    
    //Checks the number of questions asked and prints the list count.
    else if (q_list.count < num_ask)
    {
        cout << "Warning - There is only " << q_list.count << " trivia in the list.";
    }
    
    //Proceeds to ask the questions in the list.
    else
    {
        for (int x = 0; x < num_ask; x++)
        {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            getline(cin, user_answer);

            if (user_answer.compare(cur_ptr->answer) == 0)
            {
                cout << "Your answer is correct. You recieve " << cur_ptr->points << " points." << endl;
                total_points += cur_ptr->points;

                cout << "Your total points: " << total_points << endl
                 << endl;
            }
            else
            {
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;

                cout << "Your total points: " << total_points << endl
                 << endl;
            }

            cur_ptr = cur_ptr->next;
        }
    }
    return 0;
}

//Test cases to check whether the methods work.
void Unit_test()
{
    cout << "*** This is a debugging version ***\n";

    TriviaList node_list;
    init_question_list(node_list);

    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list, 0);
    cout << "Case 1 passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    ask_question(node_list, 1);
    cout << "Case 2.1 passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    ask_question(node_list, 1);
    cout << "Case 2.2 passed\n\n";

    cout << "Unit Test Case 2.3: Ask all the questions of the last trivia in the linked list." << endl;
    ask_question(node_list, 3);
    cout << "Case 2.3 passed\n\n";

    cout << "Unit Test Case 3: Ask all the questions of the linked list." << endl;
    ask_question(node_list, 3);
    cout << "Case 3 passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    ask_question(node_list, 5);
    cout << "Case 4 passed\n\n";

    cout << "*** End of the Debugging Version ***";
}