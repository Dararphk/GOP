#include "..\player\Player.h"

#include <string>

using namespace std;

class Card {
      string name;
      int id;
      string desc;
      void randomize(int l);

public:
    Card(int r_id);
};
