#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
int main() {
	int user_choice;

	cout << "Welcome to the homepage of GAMEMETICS where the world of mathematics merges with the diverse range of games !!" << endl;
	cout << endl;

	cout << "Heylooo, We at GAMEMETICS, offer the following games:"<<endl<<endl; 
	cout<<">> To play Roll Master: The Dice of Destiny that is a two player game that depends on quadratic equation press 1 :)"<<endl<<endl;
	cout<<">> To play Quadratic Quest: Graph Master a game that plots graph of the function f(x)= x^n + x^(n-1) for any value of x and n entered press 2 :)" << endl;
	cout << endl;

	cin >> user_choice;

	cout << endl << endl;
	
	cin.get();
	system("cls");

	switch (user_choice) {
    case 1:{ 
    cout<<"Welcome to RollMaster : The dice of Destiny"<<endl<<endl<<endl;
    cout<<"Following are the rules and instruction you need to know before you play the game :"<<endl;
    cout<<" 1. In the starting you will be asked to enter the name and roll numbers of both players"<<endl;
    cout<<" 2. Now, the game consists of five rounds and each player rolls the 6 sided dice twice in each round"<<endl;
    cout<<" 3. While the sum of the scores on both dices are added to the total score of each player there are some bonus points as well."<<endl;
    cout<<" 4. If the sum of the roll matches the sum of the last two digits of a player's roll number, the player gets additional points equal to the last digit of the roll number AND";
	cout<<" If the sum of the roll matches the index of the last letter of the player's name (case-insensitive), the player gets an additional 5 points."<<endl;
	cout<<" 5. Now to make it more challenging we have an extra roll but for that If a player rolls a double and the sum fits the equation x^2 - ax + a =0  with a single solution, then the player gets an extra roll."<<endl;
	cout<<" 6. The player with the highest score after five rounds wins In case of a tie, each player rolls one die. The highest roll wins, repeating if necessary until there is a winner."<<endl<<endl;
	
	cout<<"Press any key to start your game now."<<endl;
	cin.get();
	system("cls");
    
	    // Initialize random seed
        unsigned int seed = time(NULL);
        srand(seed);

        //declare variables
        string player1Name, player2Name, extra;
        int player1RollNumber, player2RollNumber;

        // Input player information
        cout << "Enter Player 1's First Name : ";
        cin.ignore();
        getline(cin, player1Name);

        int aa; //input validation for player1 name
        aa = player1Name.length();
        char tempchar;
        while (aa)
        {
            tempchar = player1Name[player1Name.length() - aa]; //get one character at a time and check if its a alphabet
            aa--;
            if ((tempchar >= 'a' && tempchar <= 'z') || (tempchar >= 'A' && tempchar <= 'Z' || tempchar == ' '))
            {
                cout;
            }
            else
            {
                cout << "Incorrect input for name 1, pls input the value again : ";
                cin >> player1Name;
                aa = player1Name.length();
            }
        }

        cout << "Enter Player 1's Roll Number (last three digits): ";
        cin >> player1RollNumber;
        getline(cin, extra);

        while (player1RollNumber < 0) //input validation for player 1 Rollnumber
        {
            cout << "Incorrect input for roll no. 1, pls input the value again : ";
            cin >> player1RollNumber;

        }

        cout << "Enter Player 2's First Name: ";
        getline(cin, player2Name);
        int bb; //Input validation for player 2 Name
        bb = player2Name.length();
        while (bb)
        {
            tempchar = player2Name[player2Name.length() - bb]; //get one character at a time anch check if its a alphabet
            bb--;
            if ((tempchar >= 'a' && tempchar <= 'z') || (tempchar >= 'A' && tempchar <= 'Z' || tempchar == ' '))
            {
                cout;
            }
            else
            {
                cout << "Incorrect input for name 2, pls input the value again : ";
                cin >> player2Name;
                bb = player2Name.length();
            }
        }

        cout << "Enter Player 2's Roll Number (last three digits): ";
        cin >> player2RollNumber;
        getline(cin, extra);

        while (player2RollNumber < 0) //Input Validation for player 2 roll number
        {
            cout << "Incorrect input for roll no. 2, pls input the value again : ";
            cin >> player2RollNumber;
        }

        //initialize variables
        int player1Score = 0, player2Score = 0;
        int previousPlayer1Score = 0, previousPlayer2Score = 0;

        //extract last two digits and last digit from player 1
        int lastTwoDigitsPlayer1 = player1RollNumber % 100;
        int lastDigitPlayer1 = lastTwoDigitsPlayer1 % 10;

        //extract last two digits and last digit from player2
        int lastTwoDigitsPlayer2 = player2RollNumber % 100;
        int lastDigitPlayer2 = lastTwoDigitsPlayer2 % 10;

        //main outer loop for five rounds
        for (int round = 1; round <= 5; round++) {
            cout << endl;
            cout << "----------------------------------------";
            cout << "Round " << round << " begins!" << endl;

            // Player 1's turn
            cout << player1Name << ", press Enter to roll the dice...";
            cin.get();
            int die1 = (rand() % 6) + 1;
            int die2 = (rand() % 6) + 1;
            int totalRoll = die1 + die2;

            // Check for a double roll
            bool doubleRollPlayer1 = die1 == die2;

            // Check if the equation has a single solution
            bool singleSolutionPlayer1 = ((totalRoll * totalRoll) - 4 * totalRoll) == 0;

            //if player has double roll and single solution, player will get a extra roll
            if (doubleRollPlayer1 && singleSolutionPlayer1) {
                cout << player1Name << " gets an extra roll!" << endl;
                cin.get();
                int extraDie1 = (rand() % 6) + 1;
                int extraDie2 = (rand() % 6) + 1;
                int extraTotalRoll = extraDie1 + extraDie2;
                totalRoll += extraTotalRoll;
            }

            // Check if the total matches the sum of the last two digits of Roll Number
            if (totalRoll == lastTwoDigitsPlayer1) {
                player1Score += lastDigitPlayer1;
                cout << "Extra " << lastDigitPlayer1 << " points awarded!" << endl;
            }

            // Update player's score
            player1Score += totalRoll;

            // Check if the total matches the index of the last character (case-insensitive)
            //player1Name.length()-1 gets the index of the last character
            char lastChar1 = player1Name[player1Name.length() - 1];
            //ternary operator to calculate the index based on the last character of player1 name
            int index1 = (lastChar1 >= 'a' && lastChar1 <= 'z') ? lastChar1 - 'a' + 'A' + 1 : lastChar1 - 'A' + 1;
            if (player1Score == index1) {
                player1Score += 5;
                cout << "Extra 5 points awarded!" << endl;
            }

            cout << player1Name << " rolled a " << die1 << " and a " << die2 << ", resulting in a total of " << totalRoll << " (+" << player1Score - previousPlayer1Score << " points)" << endl;
            cout << "Current Scores: " << player1Name << " - " << player1Score << " | " << player2Name << " - " << player2Score << endl;

            // Player 2's turn
            cout << player2Name << ", press Enter to roll the dice...";
            cin.ignore();
            cin.get();
            die1 = (rand() % 6) + 1;
            die2 = (rand() % 6) + 1;
            totalRoll = die1 + die2;

            // Check for a double roll
            bool doubleRollPlayer2 = die1 == die2;

            // Check if the equation has a single solution
            bool singleSolutionPlayer2 = ((totalRoll * totalRoll) - 4 * totalRoll) == 0;

            ////if player has double roll and single solution, player will get a extra roll
            if (doubleRollPlayer2 && singleSolutionPlayer2) {
                cout << player2Name << " gets an extra roll!" << endl;
                cin.get();
                int extraDie1 = (rand() % 6) + 1;
                int extraDie2 = (rand() % 6) + 1;
                int extraTotalRoll = extraDie1 + extraDie2;
                totalRoll += extraTotalRoll;
            }

            // Check if the total matches the sum of the last two digits of Roll Number
            if (totalRoll == lastTwoDigitsPlayer2) {
                player2Score += lastDigitPlayer2;
                cout << "Extra " << lastDigitPlayer2 << " points awarded!" << endl;
            }

            // Update player's score
            player2Score += totalRoll;

            // Check if the total matches the index of the last character (case-insensitive)
            //player2Name.length()-1 gets the index of the last character
            char lastChar2 = player2Name[player2Name.length() - 1];
            ////ternary operator to calculate the index based on the last character of player1 name
            int index2 = (lastChar2 >= 'a' && lastChar2 <= 'z') ? lastChar2 - 'a' + 'A' + 1 : lastChar2 - 'A' + 1;
            if (player2Score == index2) {
                player2Score += 5;
                cout << "Extra 5 points awarded!" << endl;
            }

            cout << player2Name << " rolled a " << die1 << " and a " << die2 << ", resulting in a total of " << totalRoll << " (+" << player2Score - previousPlayer2Score << " points)" << endl;
            cout << "Current Scores: " << player1Name << " - " << player1Score << " | " << player2Name << " - " << player2Score << endl;

            previousPlayer1Score = player1Score;
            previousPlayer2Score = player2Score;
        }
        cout << "\n-----------------------------------------------------------------------------";
        cout << "\nGame Over!" << endl;
        if (player1Score > player2Score) {
            cout << "Winner: " << player1Name << " with a score of " << player1Score << endl;
        }
        else if (player2Score > player1Score) {
            cout << "Winner: " << player2Name << " with a score of " << player2Score << endl;
        }
        else {
            cout << "It's a tie! The game will be decided with a dice roll-off." << endl;

            // Dice roll-off in case of a tie
            int tieBreakerRound = 1;
            while (player1Score == player2Score) {
                cout << "Tie-breaker Round " << tieBreakerRound << " begins!" << endl;

                // Player 1's tie-breaker roll
                cout << player1Name << ", press Enter to roll the dice...";
                cin.get();
                int tieDie1 = (rand() % 6) + 1;

                // Player 2's tie-breaker roll
                cout << player2Name << ", press Enter to roll the dice...";
                cin.ignore();
                cin.get();
                int tieDie2 = (rand() % 6) + 1;

                if (tieDie1 > tieDie2) {
                    player1Score++;
                    cout << player1Name << " wins the tie-breaker!" << endl;
                }
                else if (tieDie2 > tieDie1) {
                    player2Score++;
                    cout << player2Name << " wins the tie-breaker!" << endl;
                }
                else {
                    cout << "It's still a tie! Continuing to the next tie-breaker round." << endl;
                }

                cout << "Current Scores: " << player1Name << " - " << player1Score << " | " << player2Name << " - " << player2Score << endl;
                tieBreakerRound++;
            }
        }
        //final output of scores and winner
        cout << "\nFinal Result!" << endl;
        if (player1Score > player2Score) {
            cout << "Winner: " << player1Name << " with a score of " << player1Score << endl;
        }
        else if (player2Score > player1Score) {
            cout << "Winner: " << player2Name << " with a score of " << player2Score << endl;
        }

        break;
    }
       
    
    case 2:{
    cout<<"Welcome to Quadratic Quest : Graph Master"<<endl<<endl<<endl;
    cout<<"Following are the basic instructions you need to know before you play the game :"<<endl;
    cout<<" 1. In this game, we will plot a graph for the function f(x)= x^n + x^(n-1) for value of x and n entered by user. We will be plotting a graph for the range[0,x]"<<endl;
    cout<<" 2. Enter the maximum value of x, as our y axis of graph will be according to the max value of x"<<endl;
    cout<<" 3. Now, enter a positive integer n that is the power of the equation."<<endl<<endl;
    
	cout<<"Press any key to start your game now."<<endl;
	cin.get();
	system("cls");
	
    	int x, n, y_axis, x_axis, a, c; //x is max value, n is integer
    int b=0;

    cout << "Kindly input the max value (x) : ";
    cin >> x;
    cout << "You entered x = " << x << endl; // Display the value of x entered
    cout << endl;
   
    x= abs(x);         //calculate absolute value of x
    cout << "Now using the absolute value of x:  x = " << x << endl;  //Output the absolute value of x


    cout << "Kindly input a positive integer (n) : ";
    cin >> n;
    cout << endl;

    while (n <= 0) // Input validation for n
	{
        cout << "Incorrect input. Please enter a positive integer for n: ";
        cin >> n;
        cout << endl;
    }

    a = pow(x, n) + pow(x, n - 1); // Calculate value of a and store it in y_axis variable
    y_axis = a;

    if (y_axis % 2 == 1)  // Check if y axis is odd, if yes, increment 1 to make it even and have equal widths
	{
        y_axis = y_axis + 1;
    }

    x_axis = x;  // Storing value for x in variable x_axis

    for (int i = a; i >= 0; i = i - 2) // Iteration of 2 in each as y value decreases to zero
	{
        if (i < 10)  // If value is less than 10, it prints a zero on the left side of the digit
		 {
            cout << "0";
            b = 1;
        }

        cout << i;  // To align the graph
        cout << " ";

        for (int j = x; j > 0; j--)  // Print spaces according to the horizontal spacing based on the value of x
		{
            cout << "    ";
        }

        if (i == (pow(x, n) + pow(x, n - 1))) // Print if it satisfies the equation
		{
            cout << "*";
            x--;
        }
        cout << endl;
    }

    if (b == 1)  // Checks if b is equal to one, b equal to one means it is a single digit (less than 10)
	{
        cout << " ";
    }

    cout << "  ";   // To align the graph
    
    for (int i = 0; i <= x_axis; i++)  // Print x-axis labels from zero to max value
	{
        cout << i;
        cout << "   ";
    }
		break;
	}


    default:
        cout << "Nothing";
        break;


	}


	return 0;


}
