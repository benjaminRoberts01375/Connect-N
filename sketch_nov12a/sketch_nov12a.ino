
 //length of game data
 int dataLength = 30;
  
 //data of game
 int gameData[dataLength]; 

 bool playerOneTurn = true;

int scorePlayer1;

int scorePlayer2;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < dataLength; i++)
    gameData[i] = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(playerOneTurn){

  //Logic
  
  
  playerOneTurn = false; 
  }else{


  //Logic
  
  playerOneTurn = true;  
  }
  

}

int selectSpot(){
  
}
