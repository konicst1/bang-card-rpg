
#include <iostream>
#include "GameManager.h"
#include "Application.h"

using namespace std;


int main() {
/*//    DataLoader::saveGame("player1Name", 1, "player1Image", std::vector<std::string> (), std::vector<std::shared_ptr<PlayCard>> (),
//           "player2Name", 1, "player2Image", std::vector<std::string>(),  std::vector<std::shared_ptr<PlayCard>> ());
    GameManager gm;
    gm.selectPlayersAndInitNewGame();
    //gm.loadSavedGameAndPlay();*/

    Application app = Application();

    return app.start();


}
