#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Question {
  public:
  Question(string text, int points){
      isCorrect = false;
      this->text = text;
      this->points = points;
  }
  
  int getPoints() const {
      if(isCorrect){
          return points;
      }
  }
  
  virtual void AskQuestion() = 0;
  
  
  
  protected:
  bool isCorrect;
  string text;
  int points;
};

class TrueFalseQuestion : public Question {
    public:
    TrueFalseQuestion(string text, int points, bool correctAnswer) :
        Question(text, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void AskQuestion(){
        cout << "\nTrue or False: " << endl;
        cout << text << endl;
        cout << "Enter T or F: " << endl;
        char answer;
        bool boolAnswer;
        cin >> answer;
        boolAnswer = answer == 'T' ? true : false;
        isCorrect = boolAnswer == correctAnswer;
    }
    
    private:
    bool correctAnswer;
};

class ShortAnswerQuestion : public Question {
    public:
    
    ShortAnswerQuestion(string text, int points, string correctAnswer) :
    Question(text, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void AskQuestion(){
        cout << endl << "Short Answer: " << endl << text << endl << "Enter answer in all lowercase: " << endl;
        string answer;
        cin >> answer;
        
        isCorrect = answer == correctAnswer;
    }
    
    private:
    string correctAnswer;
};

class MathQuestion : public Question {
    public:
    
    MathQuestion(string text, int points, double correctAnswer) :
    Question(text, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void AskQuestion(){
        cout << endl << "Math Question: " << endl;
        cout << text << endl;
        string answer;
        cin >> answer;
        
        isCorrect = abs(stod(answer) - correctAnswer) < 0.0001;
    }
    
    private:
    double correctAnswer;
};

int main(){
    
    //TrueFalseQuestion q1("Is the sky blue?" , 10, true);
    //ShortAnswerQuestion q2("What language is taught in ECGR 2104?" , 10, "c++");
    //TrueFalseQuestion q3("C++ lines of code end in a semicolon." , 10, true);
    
   vector<Question*> quiz;
   quiz.push_back(new TrueFalseQuestion ("Is the sky blue?" , 10, true));
   quiz.push_back(new ShortAnswerQuestion ("What language is taught in ECGR 2104?" , 10, "c++"));
   quiz.push_back(new TrueFalseQuestion ("C++ lines of code end in a semicolon." , 10, true));
   quiz.push_back(new MathQuestion ("What is 2+2?" , 10, 4.0));
   
   int score = 0;
   for(int i = 0; i < quiz.size(); i++){
       quiz.at(i)->AskQuestion();
       score += (quiz.at(i))->getPoints();
   }
    
    cout << "You scored: " << score << endl;
    
    
    return 0;
}