const int lightLength = 30;
//const int numberOfPlayers = 2;
const int scoreThreshold = 3;


int gameData[lightLength];

int player1Score;

int player2Score;

bool pToggle;

int playerNumber;

void AISetup() {
  //set up game data
  player1Score = 0;
  player2Score = 0;

  pToggle = true;

  for(int i = 0; i < lightLength;i++)
    gameData[i] = 0;    
}
// changes player
void togglePlayer(){
  if(pToggle){
    playerNumber = 1; 
  }else{
    playerNumber = 2;
  }
  pToggle = !pToggle;
}
int getEnemyNumber(){
  if(playerNumber == 1){
    return 2;
  }else{
    return 1;
  }
}
// player chooses a spot on the light strip
int playerSelect(){

  if(playerNumber == 1){
    if()
  }else{
    
  }
  
  int s;
  if(){
    
  }else{
    s = random(lightLength);
    while(gameData[s] != 0){
      int s = random(lightLength);
    }
  }

  gameData[s] = playerNumber; 

  check(s);
  
  togglePlayer();
}
//player makes move that blocks enemy
int smartMove(int n){
  int p[4] = {-1 ,-1 ,-1 ,-1};
  int pL = 4;
  int pInv = 0;
  
  int i = 0;

  bool foundSpot = false;
  //selects a slot next to enemy spot
  while(pInv < pL && i < lightLength){
    if(i != 0 || i != lightLength-1){
      if(gameData[i] == 0 && (gameData[i-1] == n || gameData[i+1] == n)){
        p[pInv] = i;
        pInv++;
        foundSpot = true;
      }
    }else if(i == 0){
       if(gameData[i] == 0 && gameData[i+1] == n){
        p[pInv] = i;
        pInv++;
        foundSpot = true;
      }
    }else if(i == lightLength-1){
      if(gameData[i] == 0 && gameData[i-1] == n){
        p[pInv] = i;
        pInv++;
        foundSpot = true;
      }
    }
    i++;
  }
if(foundSpot){
  int r = random(pL);
  while(p[r] == -1){
    r = random(pL);
  }
  return p[r];
}
  return -1;
}


// checks the left and right to tell if you can add points
void check(int s){
  int count = 0;
  int i = s;
  while(gameData[--i] == playerNumber){
    count++;
    i--;
    if(i < 0)
      break;
  }
  i = s;
  while(gameData[++i] == playerNumber){
    count++;
    i++;
    if(i >= lightLength)
      break;
  }
  if(count >= scoreThreshold){
    incScore();
  }
}
//add points to current player
void incScore(){
  if(pToggle){
    player1Score++;
  }else{
    player2Score++;
  }
}
