#include <QGraphicsView>
#include <QGraphicsScene>


class Game : public QGraphicsView{
  Q_OBJECT

 private:
  QGraphicsScene* scene;
  //the scene on which the enemies and the map will be displayed.
  
 public:
  Game(QWidget* parent = NULL);
  //Initializes a new game
  

  QGraphics* getScene();
  //returns the scene that was initialized in the constructed in the constructor that them enemies and map objects were created and displayed on
  


  void mainMenu();

  void start(int CharClass);
    //int CharClass represents the class(warrior, ranger, DR.BC) that the user choose
    //this will be called by UI once the player chooses their class and presses start game
     
};
  
