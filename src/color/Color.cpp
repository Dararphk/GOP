#include "Color.h"

string Color::getColor(int id) {
    return "\033[0;3" + to_string(id + 1) + "m";
}

string Color::resetColor() {
    return "\033[0m";
}
