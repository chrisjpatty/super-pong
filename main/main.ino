#include <math.h>
#include <Arduboy2.h>
Arduboy2 arduboy;

BeepPin1 beep;

bool mute = 1;

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
    int speed = 2;
    int xDirection = 1;
    int yDirection = -1;
    int yMod = 2;
    bool collidedWithPlayer = false;
    bool collidedWithAI = false;
    void testCollision(Paddle p){
      collidedWithPlayer = false;
      collidedWithAI = false;
      if(x <= p.x + p.width && y + size > p.y && y < p.y + p.height && xDirection == -1){
        collidedWithPlayer = true;
        float percent = (float)(y - p.y) / (float)p.height;
        yMod = round(2 * percent) + 2;
        if(percent < .5) yDirection = -1;
        if(percent > .5) yDirection = 1;
      }
    }
    void setPosition(){
      if(collidedWithPlayer){
        xDirection = 1;
        if(!mute)
          beep.tone(beep.freq(523.251), 2);
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
      y += yMod * yDirection;
    }
    void render(){
      arduboy.fillRect(x, y, size, size, WHITE);
      setPosition();
    }
};

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  beep.begin();
  Serial.begin(9600);
  arduboy.clear();
}

Ball ball;
Paddle paddle;

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  beep.timer();
  arduboy.clear();
  ball.testCollision(paddle);
  ball.render();
  paddle.render();
  arduboy.display();
}
