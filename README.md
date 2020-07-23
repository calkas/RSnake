# RSnake

Simple game in C++ base on historical "Snake"

![image info](./RSnake_gameScreen.png)


### 1.1 Class Diagram

![image info](./RSnake_classDiagram.png)


```plantuml
@startuml

hide empty attributes
hide empty methods
title RSnake Game - Class Diagram

class Engine {
  +Engine(Board *pBoard, Snake *pSnake, Fruit *pFruit, IControl *pControl)
  +void GameLoop()
}

class RSnake {
  +void Update()
  +void Draw()
  +void AddPartOfSnakeBody()
  +bool isCollision()
  +int GetHeadSnakeX()
  +int GetHeadSnakeY()
  +void MoveSnake()
  -vector<AObjectShape *> m_VecOfSnakeBody
}

class Board {
 +void Draw()
 +bool isCollision()
 -vector<AObjectShape *> m_VecOfBoardWalls
}

class Fruit {
 + void Update()
 + void Draw()
 +bool isCollision()
 -AObjectShape *m_pFruitShape
}

interface IControl{
  +bool isUpPressed()
  +bool isDownPressed()
  +bool isLeftPressed()
  +bool isRightPressed()
}

class InputControl {
}

abstract AObjectShape {
  + void Draw()
  - m_posX :int
  - m_posY :int

}

class DBoardWall {
}
class DSnakeBody {
}
class DFruit {
}

InputControl --|> IControl

AObjectShape <|-down- DSnakeBody
AObjectShape <|-down- DBoardWall
AObjectShape <|-down- DFruit

Engine --> RSnake
Engine --> Board
Engine --> Fruit
Engine -up-> IControl

RSnake o-- AObjectShape
Board  o-- AObjectShape
Fruit  o-- AObjectShape

@enduml
```

### 1.2 Building on Windows with CMake and MinGW

Execute the following commands:

> mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make


