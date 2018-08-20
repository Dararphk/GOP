#include "Question.h"

#include <ctime>
#include <iostream>

using namespace std;

const int questionTypes = 15;

Question::Question(int r_id){
    this->id = r_id % questionTypes;
    this->randomize();
}

void Question::randomize() {
    this->q = "";

    for (int i = 0; i < 4; i++) {
        answers[i] = "";
    }

    this->correctAnswer = -1;

    switch (this->id) {
        case 0:
            this->q = "Chi è il primogenito di Lord Gwyn?";
            answers[0] = "Solaire di Astora";
            answers[1] = "Il re senza nome";
            answers[2] = "Ornstein";
            answers[3] = "Smough";
            correctAnswer = 1;
            break;
    }
}

bool Question::answer(Player *p)
{
    int a=-1;
    cout << this->q+"\n";
    for (int i = 0; i < 4; i++) {
      cout << to_string(i) << " - " << answers[i] << "\n";
    }
    cout << "Numero risposta: ";
    cin >> a;
    if (a==correctAnswer) {
      p->move(2);
    }
    else
    {
      p->move(-2);
    }
    return true;
}
