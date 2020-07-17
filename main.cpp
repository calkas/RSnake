#include <iostream>
#include <memory>
#include <vector>
#include "Engine.h"
#include "Snake.h"
#include "Board.h"
#include "Fruit.h"

using namespace std;



int main()
{
    RSnakeGame::Engine GameEngineObj;
    GameEngineObj.GameLoop();



    cout<<"\n\n\n"<<endl;

    return 0;
}
