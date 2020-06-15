
#include <iostream>
#include "GameManager.h"
#include "Application.h"

using namespace std;

/**
 * Main class. Boots up the whole application.
 * */
int main() {
    Application app = Application();

    return app.start();


}
