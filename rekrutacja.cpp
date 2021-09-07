#include <iostream>
#include<windows.h>
#include<cstdlib>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
int score=0;
void czysc()
{
	string R;
	Sleep(5000);
	cout<<"If you ready, please type 'R' to go to the next question"<<endl;
	cin>>R;
	Sleep(1000);
	system("cls");
}
void wczytaj_quiz()
{
	string quiz, credits, ans;
	string content[5], ansA[5], ansB[5], ansC[5], ansD[5], correct[5];
	
	
	int nr_line=1;
    string line;
    int nr_question=0;

    fstream plik;
    plik.open("quiz.txt",ios::in);

    if (plik.good()==false)
    {
        cout<<"We can't open the quiz file!";
        exit(0);
    }

    while(getline(plik,line))
    {
        switch(nr_line)
        {
            case 1: quiz=line; break;
            case 2: credits=line;break;
            case 3: content[nr_question] = line;break;
            case 4: ansA[nr_question] = line;break;
            case 5: ansB[nr_question] = line;break;
            case 6: ansC[nr_question] = line; break;
            case 7: ansD[nr_question] = line; break;
            case 8: correct[nr_question] = line;break;
        }
        if (nr_line==8) {nr_line=2; nr_question++;}
        nr_line++;
    }
    plik.close();
    for (int i=0; i<=4; i++)
    {
        cout<<endl<<content[i]<<endl;
        cout<<"A. "<<ansA[i]<<endl;
        cout<<"B. "<<ansB[i]<<endl;
        cout<<"C. "<<ansC[i]<<endl;
        cout<<"D. "<<ansD[i]<<endl;

        cout<<"Your answer: ";
        cin>>ans;

        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

        if (ans==correct[i])
        {
            cout<<"Well done! You have just scored a point!"<<endl;
            score++;
        }
        else cout<<"Bad answer! Correct answer is: "<<correct[i]<<endl;
    }
    cout<<"That is all. Scored points: "<<score;
    Sleep(5000);
    system("cls");
}
void ocena_rekrutera()
{
	float oceny[5], suma=0, srednia;
	cout<< endl<< "Now the assessments are completed by the recruiter";
		Sleep(3750);
		cout<<" To qualify, the average must be greater than 3.8. Points for the test are added to the average."<<endl;
		cout<<"Points for the test are doubled"<<endl;
		Sleep(12000);
		system("cls");
	for (int i = 0; i < 5; i++)
	{
		
		cout << "Type mark(2-5) for a "<< i+1<< ". question: "<<endl;
		cin >> oceny[i];
		suma +=oceny[i];
		suma = suma + (score*0.4);
	}
	srednia = suma/7;
	cout << endl << "sum= " << suma;
	Sleep(1000);
	cout << endl << "average= " << srednia;
	if(srednia>=3.8)
	{	cout<<"Congratulations, you are qualified to our company. Please chcek the e-mail and follow next recrutation steps."<<endl;}
	else
	{	cout<<"Unfortunetly, we can not hire you. Please try again next year."<<endl;}
}

int main()
{
	cout << "Welcome to the recrutation" << endl;
	Sleep(3000);
	system("cls");
	cout << "First step. Tell us where do you study, which semester and field." << endl;
	czysc();
	cout << "Thank you, the 2nd question: Why did you decide to apply to our company? " << endl;
	czysc();
	cout << "Thank you, let's go next: What is your hobby and how many time do you spend on Internet, what kind of things in the net." << endl;
	czysc();
	cout << "List at least 5 math functions in C ++. Describe what it is for and how it is used."<<endl;
	czysc();
	cout << "Which libraries will you use if you want to use srand (), Sleep () and the fstream command."<<endl;
	czysc();
	cout << "Let's make a short test to check out your C++ competition."<<endl;
	czysc();
	
	wczytaj_quiz();
	
	
	ocena_rekrutera();
	czysc;
}

