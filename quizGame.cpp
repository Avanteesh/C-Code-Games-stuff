// quiz game 
#include <iostream>
#include <cctype>

using namespace std;

float score = 0.00;    // score

struct Questions    {   
	// question
	string theQuestion;
	// options
	string optionA;
	string optionB;
	string optionC;
	string optionD;
	char correctOption;

     // display question of quiz
     void questionsDisplay()     {
	     cout << "+---------------------------------------------------------+" << endl;
	     cout << "\t" << theQuestion << endl;
	     cout << "+---------------------------------------------------------+" << endl;
	     cout << endl;
	     cout << "A) " << optionA << endl;
	     cout << "B) " << optionB << endl;
	     cout << "C) " << optionC << endl;
	     cout << "D) " << optionD << endl;
	     cout << endl;

     }

     // true - answer is correct, false - answer is wrong
     bool answerIsRight(char optionByUser)    {
		// if letter is lower case convert it into upper
		if (islower(optionByUser))    {
		   optionByUser = toupper(optionByUser);
		}
		return (optionByUser == correctOption) ? true : false;
     }
};

// a linked list
struct QuestionNode   {
      // self refrential structure 
      Questions question;
      QuestionNode * next = NULL; 
      
};

// give grade based on the score
int totalQuestions(QuestionNode * Head)    {
	
	int counter = 0;
	QuestionNode * temp = Head;

	while (temp != NULL)   {
		
		counter++;
		temp = temp->next;
	}

	return counter;

}
void rateScore(float score, QuestionNode * Head)    {
	
	int total = totalQuestions(Head);
	float Score = (float)score/total * 100;

	if (Score <= 100 && Score > 90)    {
		cout << "\nScore: " << score << "/" << total << "\nExcellent Score!" << endl;
	} 
	else if (Score <= 90 && Score > 80)    {
		cout << "\nScore: " << score << "/" << total << "\nVery Good!" << endl;
	}
	else if (Score <= 80 && Score > 70)     {
		cout << "\nScore: " << score << "/" << total << "\nGood effort keep it up!" << endl;
	}
	else if (Score <= 70 && Score > 60)      {
		cout << "\nScore: " << score << "/" << total << "\nPretty decent!" << endl;
	}
	else if (Score <= 60 && Score > 30)     {
		cout << "\nScore: " << score << "/" << total << "\nGood, better luck next time" << endl;
	}        
	else if (Score < 30)     {
		cout << "\nScore: " << score << "/" << total << "\nYour failed :(" << endl;
	}    
}

int main(void)    {


	char userOption;

	Questions question_one;
	question_one.theQuestion = "Who invented C++?";
	question_one.optionA = "Ken thompson"; 
        question_one.optionB = "Dennis Ritchie"; 
        question_one.optionC = "Ryan dalh"; 
	question_one.optionD = "Bjarne stroustop";
	question_one.correctOption = 'D';

	Questions question_two;
	question_two.theQuestion = "C++ is ?";
	question_two.optionA = "Dyanamically typed, Object oriented";
        question_two.optionB = "statically typed, Procedural"; 
	question_two.optionC = "Dynamically typed, Procedural";
	question_two.optionD = "Statically typed, Object oriented";
	question_two.correctOption = 'D';

	Questions question_three;
	question_three.theQuestion = "Biggest disadvantage of C and C++ ?";
	question_three.optionA = "Difficult to learn";
	question_three.optionB = "Obsolete compared to other languages";
	question_three.optionC = "Lack of Memory Safety"; 
	question_three.optionD = "None";
	question_three.correctOption = 'C';

	Questions question_four;
	question_four.theQuestion = "Whats the Time Complexity of (at worst case) of Bubble Sort?";
	question_four.optionA = "O(n)";
	question_four.optionB = "O(log N)";
	question_four.optionC = "O(n^2)";
	question_four.optionD = "O(n!)";
	question_four.correctOption = 'C';

	Questions question_five;
	question_five.theQuestion = "What's Acrynomy for CSV?";
	question_five.optionA = "Client Server Verification";
	question_five.optionB = "Comma Separated Values";
	question_five.optionC = "Common Spreadsheet Vocabulary";
	question_five.optionD = "Completely Standardized Vocabulary";
	question_five.correctOption = 'B';

	Questions question_six;
	question_six.theQuestion = "What is the time complexity to count the number of Nodes in a linked list?";
	question_six.optionA = "O(n)";
	question_six.optionB = "O(1)";
	question_six.optionC = "O(n^2)";
	question_six.optionD = "O(sqrt(n))";
	question_six.correctOption = 'A';


	QuestionNode * Head;
	QuestionNode q1, q2, q3, q4, q5, q6;

	// Head pointer storing the address of first element
	Head = &q1;
	q1.next = &q2;
	q2.next = &q3;
	q3.next = &q4;
	q4.next = &q5;
	q5.next = &q6;
	q6.next = NULL;

	q1.question = question_one;
	q2.question = question_two;
	q3.question = question_three;
	q4.question = question_four;
	q5.question = question_five;
	q6.question = question_six;

	cout << "\nLets start the quiz!!\n" << endl;

	while (Head != NULL)    {
		Head->question.questionsDisplay();
		cout<<endl;
		cout << "Enter the option you choose: ";
		cin >> userOption;
		
		if (Head->question.answerIsRight(userOption))   {
			score += 2.00;
		}
		cout << endl;
		
		Head = Head->next;
	}


	rateScore(score, Head);

	return 0;

}

// end of file


