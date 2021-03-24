# 🐍 RSnake

Simple console game in C++ based on historical "Snake"

![image info](./RSnake_gameScreen.png)

Player Controls:
Keys: <kbd>UP</kbd>, <kbd>DOWN</kbd>, <kbd>LEFT</kbd>, <kbd>RIGHT</kbd>

## 📊 UML Class Diagram

![image info](./RSnake_classDiagram.png)

```plantuml
@startuml

hide empty attributes
hide empty methods
title RSnake Game - Class Diagram

class Engine {
  +Engine(...)
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

class StoryBoard {
 + void Update()
 + void Show()
 + void GameOver()
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

Engine o-- RSnake
Engine o-- Board
Engine o-- Fruit
Engine o-right- StoryBoard
Engine o-up- IControl

RSnake o-- AObjectShape
Board  o-- AObjectShape
Fruit  o-- AObjectShape

@enduml
```

## 🕹️ How to Run
### Building on Windows with CMake and MinGW

Execute the following commands:

```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```




