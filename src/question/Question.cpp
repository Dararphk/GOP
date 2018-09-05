#include "Question.h"

#include <string>
#include <iostream>
#include <limits>

using namespace std;

const int questionTypes = 1;

Question::Question(int r_id){
    this->id = r_id % questionTypes;
    this->randomize();
}

void Question::randomize() {

    this->correctAnswer = -1;

    /*
    ** (!!!) mancano tutte le domande, possibile veloce
    ** implementazione delle stesse tramite template su
    ** excel, convertito poi in testo con spaziatura nulla
    */
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

bool Question::answer(Player *p) {
    int a=-1;
    cout << this->q << endl;
    for (int i = 0; i < 4; i++) {
        cout << to_string(i) << " - " << answers[i] << "\n";
    }
    cout << "Numero risposta: ";
    cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if (a==correctAnswer) {
        cout << "Risposta esatta! " << p->getName() << " va avanti di 2\n";
        p->move(2);
        return true;
    }
    cout << "Risposta errata.\n";
    return false;
}
