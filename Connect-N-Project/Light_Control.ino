void displayScores(uint32_t p1Color, uint32_t p2Color) {
  resetStrip();
  int p1Score = getP1Score();
  int p2Score = getP2Score();
  int ledP1Score = p1Score;
  int ledP2Score = p2Score;

  //LEDs turn on one after another
  for (int i = 0; i < strip.numPixels(); i++){
    if (ledP1Score > 0) { //Only activate new LEDs if p1 has the score for it
      strip.setPixelColor(i, p1Color);
      ledP1Score--; //Remove a point since LED is now shown
    }
    
    if (ledP2Score > 0) { //Only activate new LEDs if p2 has the score for it
      strip.setPixelColor(strip.numPixels() - 1 - i, p2Color); //Account for 1 offset
      ledP2Score--; //Remove a point since LED is now shown
    }
    
    strip.show();
    delay(100);
  }

  //Blink winner
  int blinkCount = 5;
  int blinkDelay = 250; //Used for turning off and on (total 500)

  //Assume P1 won
  int LEDOffset = 0;
  int winnerPoints = p1Score;
  uint32_t winnerColor = p1Color;
  //Who to blink
  if (p2Score > p1Score){ //If P2 won
    LEDOffset = strip.numPixels() - p2Score; 
    winnerPoints = p2Score;
    winnerColor = p2Color;
  }
  else if (p1Score == p2Score) { //If tie
    winnerPoints = strip.numPixels();
    winnerColor = p1Color + p2Color;
  }
  //Blinking logic
  for (int i = 0; i < blinkCount; i++){ //Blink n times
    resetStrip(); //Blink off
    delay(blinkDelay);
    
    for (int j = 0; j < winnerPoints; j++) { //Blink on
      strip.setPixelColor(LEDOffset + j, winnerColor);
    } //Blink on
    strip.show();
    delay(blinkDelay);
  }
}

void resetStrip(){ //Removes all color from the strip
  Serial.print(strip.numPixels());
  for (int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}
