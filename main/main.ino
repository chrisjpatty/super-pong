#include <math.h>
#include <Arduboy2.h>
Arduboy2 arduboy;

BeepPin1 beep;
BeepPin2 beep2;

const unsigned char logo[] PROGMEM  = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8, 0x8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0x92, 0x92, 0xf2, 0x00, 0x00, 0xfe, 0x80, 0x80, 0xfe, 0x00, 0x00, 0xfe, 0x12, 0x12, 0xc, 0x00, 0x00, 0xfe, 0x92, 0x92, 0x92, 0x00, 0x00, 0xfe, 0x12, 0x12, 0xec, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf, 0x3, 0x83, 0x83, 0x83, 0x83, 0x83, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x7, 0x00, 0x80, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0xbc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x38, 0x00, 0x00, 0x80, 0xe0, 0x8c, 0x3c, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0xc0, 0xf8, 0xfc, 0xfc, 0xfc, 0x3c, 0x4, 0x00, 0xc0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0x3f, 0xf, 0x3, 0x3, 0x3, 0x3, 0x3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x3, 0x00, 0x00, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x3, 0x3, 0x00, 0x00, 0x00, 0x98, 0x9f, 0x9f, 0x9f, 0x9f, 0x8f, 0x81, 0xc0, 0xc0, 0xc0, 0xc0, 0xcc, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xc1, 0xc0, 0xc0, 0xcc, 0xcf, 0xcf, 0xcf, 0xc0, 0xc0, 0xc3, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0x4f, 0x1, 0x80, 0x80, 0xce, 0xcf, 0x8f, 0x9f, 0x1f, 0x3f, 0x79, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf1, 0xf1, 0xf9, 0xff, 0xff, 0x3f, 0xf, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8, 0x8, 0xc, 0x4, 0x4, 0x6, 0x6, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x23, 0x23, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x19, 0x19, 0x19, 0x19, 0x9, 0x9, 0xd, 0xd, 0xd, 0x1d, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x61, 0xc, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

bool mute = false;
int score = 0;
int gameState = 0;
int lives = 3;

class Screen{
  public:
    int blinkFrame = 0;
    void invert(){
      unsigned char* p = arduboy.getBuffer();
      for(int i = 0; i <= 1024; i++){
        if(p[i] == 0x00){
          p[i] = 0xFF;
        }else{
          p[i] = 0x00;
        }
      }
    }
};
Screen screen;

class Tones{
  public:
    void playScoreSound(){
      if(!mute){
        beep.tone(beep.freq(913.251), 3);
        beep2.tone(beep2.freq(1063.251), 3);
      }
    }
    void playHitSound(){
      if(!mute){
        beep.tone(beep.freq(783.251), 3);
        beep2.tone(beep2.freq(753.251), 3);
      }
    }
    void playDeathSound(){
      if(!mute){
        beep.tone(beep.freq(353.251), 2);
        beep2.tone(beep2.freq(413.251), 5);
      }
    }
    void playGameOverSound(){
      if(!mute){
        beep.tone(beep.freq(253.251), 2);
        beep2.tone(beep2.freq(113.251), 5);
      }
    }
};
Tones tones;

class Paddle{
  public:
    int width = 3;
    int height = 15;
    int x = 3;
    int y = 3;
    int speed = 2;
    void handleEvents(){
      if(arduboy.pressed(DOWN_BUTTON) && y < HEIGHT - height) {
        y += speed;
      }
      if(arduboy.pressed(UP_BUTTON) && y > 0) {
        y -= speed;
      }
    }
    void render(){
      arduboy.fillRect(x, y, width, height, WHITE);
      handleEvents();
    }
};

class Ball{
  public:
    int size = 4;
    int x = 7;
    int y = 3;
    float yModFrame = 0;
    int speed = 4;
    int xDirection = 1;
    int yDirection = -1;
    float yMod = 2;
    bool collidedWithPlayer = false;
    bool collidedWithBackboard = false;
    void testCollision(Paddle p){
      collidedWithPlayer = x <= p.x + p.width && y + size > p.y && y < p.y + p.height && xDirection == -1;
      collidedWithBackboard = x >= WIDTH - size;
      if(collidedWithPlayer){
        collidedWithPlayer = true;
        float percent = (float)(y - p.y) / (float)p.height;
        float shifted  = percent - .5;
        yMod = abs(3 * shifted);
        if(percent < .5) yDirection = -1;
        if(percent >= .5) yDirection = 1;
      }
      if(collidedWithBackboard){
        float randomNum = ((float)random(0, 100) / 100) - .5;
        yMod = abs(3 * (randomNum - .5));
        if(randomNum < .5) yDirection = -1;
        if(randomNum >= .5) yDirection = 1;
      }
    }
    void setPosition(){
      if(collidedWithPlayer){
        tones.playHitSound();
        xDirection = 1;
      }
      if(x < 0){
        xDirection = 1;
      }
      if(x + size > WIDTH){
        xDirection = -1;
      }
      if(y < 0){
        yDirection = 1;
      }
      if(y + size > HEIGHT){
        yDirection = -1;
      }
      x += speed * xDirection;
      yModFrame += yMod;
      if(yModFrame >= 1){
        y += ceil(yMod) * yDirection;
        yModFrame = 0;
      }
    }
    void render(){
      arduboy.fillRect(x, round(y), size, size, WHITE);
      setPosition();
    }
};

class Scoreboard{
  public:
    void render(){
      int xMod = 0;
      if(score >= 10) xMod = 8;
      if(score >= 100) xMod = 16;
      arduboy.setCursor(120 - xMod, 3);
      arduboy.print(score);
    }
};

typedef struct {
  int x;
  int y;
  int w;
  int h;
} rectFrame;

class Backboard{
  public:
    int frame = 0;
    bool running = false;
    rectFrame frames[8] = {
      { WIDTH, 0, 0, HEIGHT },
      { WIDTH, 0, 0, HEIGHT },
      { WIDTH - 1, 0, 3, HEIGHT },
      { WIDTH - 2, 0, 3, HEIGHT },
      { WIDTH - 3, 0 + (HEIGHT / 4 / 2), 2, HEIGHT - (HEIGHT / 4) },
      { WIDTH - 3, 0 + (HEIGHT / 3 / 2), 2, HEIGHT - (HEIGHT / 3) },
      { WIDTH - 4, 0 + (HEIGHT / 2 / 2), 1, HEIGHT - (HEIGHT / 2) },
      { WIDTH - 4, 0 + ((float)HEIGHT / 1.5 / 2), 1, HEIGHT - ((float)HEIGHT / 1.5) }
    };
    void testCollision(Ball b){
      if(b.x >= WIDTH - b.size && !running){
        score++;
        tones.playScoreSound();
        running = true;
      }
    }
    void render(){
      if(running){
        rectFrame current = frames[frame];
        arduboy.fillRect(current.x, current.y, current.w, current.h, WHITE);
        frame++;
        if(frame > 7){
          frame = 0;
          running = false;
        }
      }
    };
};

class Frontboard{
  public:
    bool running = false;
    int frame = 0;
    rectFrame frames[8] = {
      { 0, 0, 0, HEIGHT },
      { 0, 0, 0, HEIGHT },
      { 1, 0, 3, HEIGHT },
      { 2, 0, 3, HEIGHT },
      { 3, 0 + (HEIGHT / 4 / 2), 2, HEIGHT - (HEIGHT / 4) },
      { 3, 0 + (HEIGHT / 3 / 2), 2, HEIGHT - (HEIGHT / 3) },
      { 4, 0 + (HEIGHT / 2 / 2), 1, HEIGHT - (HEIGHT / 2) },
      { 4, 0 + ((float)HEIGHT / 1.5 / 2), 1, HEIGHT - ((float)HEIGHT / 1.5) }
    };
    void testCollision(Ball b){
      if(b.x <= 0){
        if(lives == 0){
          gameState = 2;
          tones.playGameOverSound();
        }else{
          lives--;
          tones.playDeathSound();
        }
        running = true;
      }
    }
    void render(){
      if(running){
        rectFrame current = frames[frame];
        arduboy.fillRect(current.x, current.y, current.w, current.h, WHITE);
        frame++;
        if(frame > 7){
          frame = 0;
          running = false;
        }
      }
    }
};

class StartScreen{
  public:
    int frame = 0;
    int frames[24] = {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0};
    void render(){
      arduboy.drawBitmap(15, 10, logo, 98, 34, WHITE);
      arduboy.setCursor(16, 50);
      if(frames[frame] == 1){
        arduboy.print(F("PRESS A TO START"));
      }
      if(frame == 23){
        frame = 0;
      }else{
        frame++;
      }
      if(arduboy.pressed(A_BUTTON)){
        gameState = 1;
      }
    }
};

class GameOver{
  public:
    int frame = 0;
    int frames[24] = {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0};
    void render(){
      arduboy.setCursor(37, 28);
      arduboy.print(F("GAME OVER"));
      if(frames[frame] == 1){
        arduboy.setCursor(16, 50);
        arduboy.print(F("PRESS A TO START"));
      }
      if(frame == 23){
        frame = 0;
      }else{
        frame++;
      }
      if(arduboy.pressed(A_BUTTON)){
        gameState = 1;
        lives = 3;
        score = 0;
      }
    }
};

class Life{
  public:
    int x;
    int y;
    Life(int x, int y){
      this->x = x;
      this->y = y;
    }
    render(){
      arduboy.fillRect(x, y, 6, 2, WHITE);
    }
};

Life* life1 = new Life(52, HEIGHT - 2);
Life* life2 = new Life(62, HEIGHT - 2);
Life* life3 = new Life(72, HEIGHT - 2);

class Toolbar{
  public:
    render(){
      if(lives >= 1) life1->render();
      if(lives >= 2) life2->render();
      if(lives >= 3) life3->render();
    }
};

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  beep.begin();
  //Serial.begin(9600);
  arduboy.clear();
}

Ball ball;
Paddle paddle;
Scoreboard scoreboard;
Backboard backboard;
Frontboard frontboard;
StartScreen startScreen;
Toolbar toolbar;
GameOver gameOver;

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  beep.timer();
  beep2.timer();
  arduboy.clear();
  switch(gameState){
    case 0:
      startScreen.render();
      break;
    case 1:
      //Playing
      frontboard.testCollision(ball);
      frontboard.render();
      backboard.testCollision(ball);
      backboard.render();
      ball.testCollision(paddle);
      ball.render();
      paddle.render();
      scoreboard.render();
      toolbar.render();
      break;
    case 2:
      //Game Over
      gameOver.render();
  }
  arduboy.display();
}
