#include "saper.h"

bool easy_button(int x, int y) {
    return x > 150 && x < 600 - 150 && y > 150 && y < 250;
}
bool medium_button(int x, int y) {
    return x > 150 && x < 600 - 150 && y > 300 && y < 400;
}
bool hard_button(int x, int y) {
    return x > 150 && x < 600 - 150 && y > 450 && y < 550;
}
bool close(int x, int y) {
    return x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60;
}