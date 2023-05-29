#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdexcept>
#include <cstdlib>
using namespace std;
class Interface{
    public:
    virtual void Randomword()= 0;
    virtual void Check() = 0;
    
    virtual ~Interface(){}
};
int lives =20;
int a = 1;
class GenerateWord {
 
  public:

GenerateWord(): GuessingWord(){};
 string GuessingWord;
 virtual void RandomWord ( string wordList[])
  {
       GuessingWord = wordList[rand ()%15];
  }
};

class CheckPosition: public GenerateWord
{
    private:
    int position;
    public:
    CheckPosition(): GenerateWord(), position(0){};
    void Check (int position, string GuessingWord, char letter)
    {
         position = GuessingWord.find(letter);
     
      if (position != string::npos)
     {
         cout<<"There is letter "<<letter<<" in this word! "<<endl;
        for (int i = 0; i<GuessingWord.length();i++)
        {
            if (i == position)
            {
                cout<<letter;
            }
           else
           cout<<" _ ";
        }
         cout<<endl;
     }
     else
       {
         cout<<"There is no letter "<<letter<< " in this word "<<endl;
         lives--;
         cout<<"You have got "<<lives<<" lives left"<<endl;
       }
    }
};
class Exeption : public invalid_argument
{
    public:
    explicit Exeption(const string& message)
    : invalid_argument(message){}
};
void FunctionThatThrows()
{
    throw Exeption("Give a proper number!");
}
class Ask
{
    public:
    

    void AskIf(int answear2){
         
if (answear2==1)
{
    a=1;
}
else if (answear2==2)
    {
        cout<<"Thanks for playing!";
     exit(0);
      
    }
    else 
    {
      try
      { FunctionThatThrows();}
        catch (const Exeption& e)
        {
            cerr<<e.what()<<endl;
        }
 cin>>answear2;
  AskIf(answear2);

}
         
     } ;    
};
int main() {
  Ask ask;
  srand (time (NULL));
  char letter;
  int a =1;
  while (a== 1)
  {
GenerateWord word;

 CheckPosition position1;
string wordList [15] = { "cat",  "hamster", "dog", "bird", "turtle", "rabbit", "cow", "horse", "chicken", "dolphin", "tiger", "fish", "hedgehog", "ant", "duck" };
word.RandomWord ( wordList);
  cout<<"Your word has "<<word.GuessingWord.length()<<" letters"<<endl;
 while (lives > 0)
 {
   
     int i = 0;
  cout<<"Give a letter"<<endl;
     cin>>letter;
	 letter =  tolower(letter);
    position1.Check(i, word.GuessingWord, letter);
    cout<<"Are you ready to guess the pasword? If yes type 1 if no type 2 "<<endl;  
  int answer; 
    cin>>answer;
    if (answer==1)
    {
        cout<<"Type your answear"<<endl;
       string UserAnswear;
       cin>>UserAnswear;
       if(UserAnswear == word.GuessingWord)
       {
           cout<<"Congrats! You guessed the word!"<<endl;
           break;
       }
       else 
       {
           cout<<"You didint guess the right word! Keep guessing!"<<endl;
       }
    }
     if (answer==2)
    {
        continue;
    }
    else 
    {
      try
      { FunctionThatThrows();}
        catch (const Exeption& e)
        {
            cerr<<e.what()<<endl;
        }
    }
 }
 if (lives == 0)
 {
cout<<"You ran out of lives!";
 } 
int answer2;
cout<<"Do you want to play again? Type 1 if yes type 2 if no";
cin>>answer2; 
    

ask.AskIf(answer2);


}


    return 0;
}
