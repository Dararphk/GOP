#include "Question.h"

#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct entry {
    string _q;
    string _answers[4];
    int _correctAnswer;
};

//insert comment outside /* "entry questions[] = {...} */" to add custom questions
entry questions[] = {
{
	"Chi è il primogenito di Lord Gwyn?",
	{
	"Solaire di Astora",
	"Il re senza nome",
	"Ornstein",
	"Smough"
	},
	1
},
{
	"Qual è il drop di Havel la Roccia?",
	{
	"Scaglia di titanite",
	"Armatura di Havel",
	"Spadone di Havel",
	"Anello di Havel"
	},
	3
},
{
	"Da cosa viene ucciso Solaire in uno dei possibili finali della sua sidequest?",
	{
	"Uno scheletro",
	"Un insetto del sole",
	"Il non morto prescelto",
	"Lautrec di Carim"
	},
	1
},
{
	"Come si torna al Manicomio dei non morti una volta arrivati a Lordran?",
	{
	"A piedi",
	"Con un drago",
	"Con un corvo gigante",
	"Teletrasporto"
	},
	2
},
{
	"Come si chiama il pittore da cui prende il nome il primo dei DLC del primo capitolo?",
	{
	"Ariamis",
	"Andre",
	"Logan",
	"Griggs"
	},
	0
},
{
	"Che boss si trova nella cattedrale di Lothric dopo aver ucciso Vordt?",
	{
	"Gael",
	"Ocelotte",
	"Armatura del cavaliere drago",
	"Danzatrice della valle boreale"
	},
	3
},
{
	"In che zona si trova l’anello della cloranzia?",
	{
	"All’altare del vincolo",
	"Borgo dei non morti",
	"Strada dei sacrifici",
	"Irithyll della valle boreale"
	},
	1
},
{
	"Chi appare all’altare del vincolo dopo aver fatto suonare le due campane del risveglio?",
	{
	"Il cavaliere caduto (crestfallen)",
	"Frampt, cercatore di re",
	"Andre di Astora",
	"Kirk, cavaliere delle spine"
	},
	1
},
{
	"Chi è il fido compagno di Artorias, il camminatore dell’abisso?",
	{
	"Smough",
	"Il demone toro",
	"Girandola",
	"Sif, il grande lupo"
	},
	3
},
{
	"Chi è il boss finale del secondo capitolo?",
	{
	"Dragone antico",
	"Vendrick",
	"Nashandra",
	"Velstadt"
	},
	2
},
{
	"Chi appare come illusione dopo aver battuto i cavalieri Ornstein e Smough?",
	{
	"Gwyndolin",
	"Solaire",
	"Lord Gwyn",
	"Gwynevere"
	},
	3
},
};

Question::Question(int r_id){
    n = sizeof(questions) / sizeof(*questions);
    int tmp = r_id % n;
    this->q = questions[tmp]._q;
    for (int i = 0; i < 4; i++)
        this->answers[i] = questions[tmp]._answers[i];
    this->correctAnswer = questions[tmp]._correctAnswer;
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
