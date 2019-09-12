#include <LiquidCrystal.h>
const int rs = 11, en = 12, d4 = 13, d5 = 14, d6 = 15, d7 = 16;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void allOff(){
  for(int i = 22; i < 47; i++){
    digitalWrite(i, LOW);
  }  
}

int select = 0;
int inGame = 0;
int head = 22;                       
int input = 0; 
int i = 0; 
int k = 0;   
int enter = 6;
int up = 5;
int left = 3;
int down = 4;
int right = 2;
//Snake
int direct = 0;
int islit = 0;
int food;   
int snake[26]; 
int fat = 0;
int temp = 0;
//Simon
int light1 = 22;
int light25 = 46;
const int blue = 1;
const int green = 2;
const int yellow = 4;
const int red = 3;
const int spkr = 8;
int pattern[128];
int highscore = 0;
int score = 0;
int color = 0;
int speed = 50;
int song6[40];
int rthm6[40];

int setMusic(int song){
  
const int c3 = 131;
const int cs3 = 139;
const int d3 =  147;
const int ds3 =  156;
const int e3 =  165;
const int f3 =  175;
const int fs3 =  185;
const int g3 =  196;
const int gs3 = 208;
const int a3 =  220;
const int as3 =  233;
const int b3 =  247;
const int c4 =  262;
const int cs4 =  277;
const int d4 =  294;
const int ds4 = 311;
const int e4 = 330;
const int f4 = 349;
const int fs4 = 370;
const int g4 = 392;
const int gs4 = 415;
const int a4 = 440;
const int as4 = 466;
const int b4 = 494;
const int c5 = 523;
const int cs5 =554;
const int d5 =  587;
const int ds5 =  622;
const int e5 =  660;
const int f5 =  698;
const int fs5 = 740;
const int g5 = 784;
const int gs5 =  831;
const int a5 =  880;
const int as5 =  932;
const int b5 = 988;
const int c6 =  1047;
const int cs6 = 1109;
const int d6 =  1175;
const int ds6 = 1245;
const int e6 =  1319;
const int f6 =  1397;
const int fs6 =  1480;
const int g6 =  1568;
const int gs6 =  1661;
const int a6 =  1760;
const int as6 =  1865;
const int b6 =  1976;

 if(song == 1){

  song6[0] = d4;
  song6[1] = d4;
  song6[2] = d4;
  song6[3] = as3;
  song6[4] = f4;
  song6[5] = d4;
  song6[6] = as3;
  song6[7] = f4;
  song6[8] = d4;
  song6[9] = a4;
  song6[10] = a4;
  song6[11] = a4;
  song6[12] = as4;
  song6[13] = f4;
  song6[14] = d4;
  song6[15] = as3;
  song6[16] = f4;
  song6[17] = d4;
 
  rthm6[0] = 4;
  rthm6[1] = 4;
  rthm6[2] = 4;
  rthm6[3] = 3;
  rthm6[4] = 1;
  rthm6[5] = 4;
  rthm6[6] = 3;
  rthm6[7] = 1;
  rthm6[8] = 8;
  rthm6[9] = 4;
  rthm6[10] = 4;
  rthm6[11] = 4;
  rthm6[12] = 3;
  rthm6[13] = 1;
  rthm6[14] = 4;
  rthm6[15] = 3;
  rthm6[16] = 1;
  rthm6[17] = 8;
  return 18;
   
 }else if(song == 2){ 
  song6[0] = c5;
  song6[1] = g4;
  song6[2] = c5;
  song6[3] = g4;
  song6[4] = c5;
  song6[5] = g4;
  song6[6] = c5;
  song6[7] = e5;
  song6[8] = g5;
  song6[9] = f5;
  song6[10] = d5;
  song6[11] = f5;
  song6[12] = d5;
  song6[13] = f5;
  song6[14] = d5;
  song6[15] = b4;
  song6[16] = d5;
  song6[17] = g4;
  
  rthm6[0] = 6;
  rthm6[1] = 2;
  rthm6[2] = 6;
  rthm6[3] = 2;
  rthm6[4] = 2;
  rthm6[5] = 2;
  rthm6[6] = 2;
  rthm6[7] = 2;
  rthm6[8] = 8;
  rthm6[9] = 6;
  rthm6[10] = 2;
  rthm6[11] = 6;
  rthm6[12] = 2;
  rthm6[13] = 2;
  rthm6[14] = 2;
  rthm6[15] = 2;
  rthm6[16] = 2;
  rthm6[17] = 8;
  return 18;
   
 }else if(song == 3){
  song6[0] = as3;
  song6[1] = c4;
  song6[2] = cs4;
  song6[3] = as3;
  song6[4] = f4;
  song6[5] = f4;
  song6[6] = ds4;
  song6[7] = gs3;
  song6[8] = as3;
  song6[9] = c4;
  song6[10] = gs3;
  song6[11] = ds4;
  song6[12] = ds4;
  song6[13] = cs4;
  song6[14] = c4;
  song6[15] = as3;
  song6[16] = as3;
  song6[17] = c4;
  song6[18] = cs4;
  song6[19] = as3;
  song6[20] = cs4;
  song6[21] = ds4;
  song6[22] = c4;
  song6[23] = as3;
  song6[24] = gs3;
  song6[25] = f3;
  song6[26] = ds4;
  song6[27] = cs4;
 
  rthm6[0] = 1;
  rthm6[1] = 1;
  rthm6[2] = 1;
  rthm6[3] = 1;
  rthm6[4] = 3;
  rthm6[5] = 3;
  rthm6[6] = 6;
  rthm6[7] = 1;
  rthm6[8] = 1;
  rthm6[9] = 1;
  rthm6[10] = 1;
  rthm6[11] = 3;
  rthm6[12] = 3;
  rthm6[13] = 3;
  rthm6[14] = 1;
  rthm6[15] = 3;
  rthm6[16] = 1;
  rthm6[17] = 1;
  rthm6[18] = 1;
  rthm6[19] = 1;
  rthm6[20] = 5;
  rthm6[21] = 2;
  rthm6[22] = 2;
  rthm6[23] = 2;
  rthm6[24] = 3;
  rthm6[25] = 1;
  rthm6[26] = 4;
  rthm6[27] = 4;
  return 28;
   
 }else if(song == 4){
  song6[0] = e4;
  song6[1] = f4;
  song6[2] = g4;
  song6[3] = c5;
  song6[4] = d4;
  song6[5] = e4;
  song6[6] = f4;
  song6[7] = g4;
  song6[8] = a4;
  song6[9] = b4;
  song6[10] = f5;
  song6[11] = a4;
  song6[12] = b4;
  song6[13] = c5;
  song6[14] = d5;
  song6[15] = e5;
 
  rthm6[0] = 3;
  rthm6[1] = 1;
  rthm6[2] = 2;
  rthm6[3] = 8;
  rthm6[4] = 3;
  rthm6[5] = 1;
  rthm6[6] = 8;
  rthm6[7] = 3;
  rthm6[8] = 1;
  rthm6[9] = 2;
  rthm6[10] = 8;
  rthm6[11] = 3;
  rthm6[12] = 1;
  rthm6[13] = 4;
  rthm6[14] = 4;
  rthm6[15] = 4;
  return 16;
   
 }else if(song == 5){
  song6[0] = g3;
  song6[1] = 0;
  song6[2] = g3;
  song6[3] = 0;
  song6[4] = as3;
  song6[5] = c4;
  song6[6] = g3;
  song6[7] = 0;
  song6[8] = g3;
  song6[9] = 0;
  song6[10] = f3;
  song6[11] = fs3;
  song6[12] = g3;
  song6[13] = 0;
  song6[14] = g3;
  song6[15] = 0;
  song6[16] = as3;
  song6[17] = c4;
  song6[18] = g3;
  song6[19] = 0;
  song6[20] = g3;
  song6[21] = 0;
  song6[22] = f3;
  song6[23] = fs3;
  song6[24] = g3;
   
  rthm6[0] = 2;
  rthm6[1] = 1;
  rthm6[2] = 2;
  rthm6[3] = 1;
  rthm6[4] = 2;
  rthm6[5] = 2;
  rthm6[6] = 2;
  rthm6[7] = 1;
  rthm6[8] = 2;
  rthm6[9] = 1;
  rthm6[10] = 2;
  rthm6[11] = 2;
  rthm6[12] = 2;
  rthm6[13] = 1;
  rthm6[14] = 2;
  rthm6[15] = 1;
  rthm6[16] = 2;
  rthm6[17] = 2;
  rthm6[18] = 2;
  rthm6[19] = 1;
  rthm6[20] = 2;
  rthm6[21] = 1;
  rthm6[22] = 2;
  rthm6[23] = 2;
  rthm6[24] = 3;  
  return 25;
   
 }else if(song == 6){
  song6[0] = a4;
  song6[1] = c5;
  song6[2] = d5;
  song6[3] = d5;
  song6[4] = 0;  
  song6[5] = d5;
  song6[6] = e5;
  song6[7] = f5;
  song6[8] = f5;
  song6[9] = 0;    
  song6[10] = f5;
  song6[11] = g5;
  song6[12] = e5;
  song6[13] = e5;
  song6[14] = 0;   
  song6[15] = d5;
  song6[16] = c5;
  song6[17] = c5;
  song6[18] = d5;
  song6[19] = 0;    
  song6[20] = a4;  
  song6[21] = c5;
  song6[22] = d5;
  song6[23] = d5;
  song6[24] = 0;    
  song6[25] = d5;
  song6[26] = e5;
  song6[27] = f5;
  song6[28] = f5;
  song6[29] = 0;    
  song6[30] = f5;
  song6[31] = g5;
  song6[32] = e5;
  song6[33] = e5;
  song6[34] = 0;    
  song6[35] = d5;
  song6[36] = c5;
  song6[37] = d5;
  song6[38] = 0;  
  
  rthm6[0] = 2;
  rthm6[1] = 2;
  rthm6[2] = 4;
  rthm6[3] = 3;
  rthm6[4] = 1;  
  rthm6[5] = 2;
  rthm6[6] = 2;
  rthm6[7] = 4;
  rthm6[8] = 3;
  rthm6[9] = 1;  
  rthm6[10] = 2;
  rthm6[11] = 2;
  rthm6[12] = 4;
  rthm6[13] = 3;
  rthm6[14] = 1;  
  rthm6[15] = 2;
  rthm6[16] = 2;
  rthm6[17] = 2;
  rthm6[18] = 6;
  rthm6[19] = 2;  
  rthm6[20] = 2;
  rthm6[21] = 2;
  rthm6[22] = 4;
  rthm6[23] = 3;
  rthm6[24] = 1;  
  rthm6[25] = 2;
  rthm6[26] = 2;
  rthm6[27] = 4;
  rthm6[28] = 3;
  rthm6[29] = 1;  
  rthm6[30] = 2;
  rthm6[31] = 2; 
  rthm6[32] = 4;
  rthm6[33] = 3;
  rthm6[34] = 1;  
  rthm6[35] = 2;
  rthm6[36] = 2;
  rthm6[37] = 7;
  rthm6[38] = 1;  
  return 39;
   
 }
 return 0;
}

void showHighscore(){
  lcd.clear();
  lcd.print(":::High Score:::");
  lcd.setCursor(7, 2);
  lcd.print(highscore);
}

void playTune(int tune){
    allOff();  
    int length = setMusic(tune);
    int tempo = 0;
    int light = light1;
    int tmp = 0;
    
    if(tune == 1){
      tempo = 100;
    }else if(tune == 2){
      tempo = 60;
    }else if(tune == 3){
      tempo = 80;
    }else if(tune == 4){
      tempo = 80;
    }else if(tune == 5){
      tempo = 60;
    }else if(tune == 6){
      tempo = 40;
    }
    
    digitalWrite(light, HIGH);
    for(int i = 0; i < length; i++){
    play(song6[i], rthm6[i], tempo);
        digitalWrite(light, LOW);
        if(song6[i] >= tmp){ 
            if(light == light25){
                light = light1;
            }else{
                light += 1;
            }
        }else{
            if(light == light1){
                light = light25;
            }else{
                light -= 1;
            }
        }
        digitalWrite(light, HIGH);
        tmp = song6[i];
  }
  allOff();
}

void play(int note, int len, int tpo){
  if(note == 0){
    delay(2*tpo*len);
  }else{
    tone(spkr, note);
      delay(tpo*len);
    noTone(spkr);
      delay(tpo*len);
  }
}

void lose(){
  lcd.clear();
  lcd.print("Your Score Was:");
  lcd.setCursor(7, 2);
  lcd.print(score);
  int light = light25;
  digitalWrite(light, HIGH);
  for(int i = 1175; i >= 294; i --){
    
    tone(spkr, i);
    
    if(i % 12 == 0){
      digitalWrite(light, LOW);
      if(light == light1){
          light = light25;
      }else{
          light = light - 1;
      }
      digitalWrite(light, HIGH);
    }  
    delay(4);
    noTone(spkr);
  }
  noTone(spkr);
  digitalWrite(light, LOW);
  playTune(1);
      
      lcd.clear();
  if(score > highscore){
      lcd.print("Old High Score:");
      lcd.setCursor(7, 2);
      lcd.print(highscore);
      delay(3000);
      lcd.clear();
      lcd.print(" You Got A New ");
      lcd.setCursor(0, 1);
      lcd.print("   High Score   ");      
      playTune(2); 
      highscore = score;
      lcd.clear();
  }   
      showHighscore();
      score = -1;
}

void start(){
  int light = light1;
  for(int i = 0; i <= 523; i++){
    
    tone(spkr, i);
    
    if(i % 12 == 0){
      digitalWrite(light, LOW);
      if(light == light25){
          light = light1;
      }else{
          light += 1;
      }
      digitalWrite(light, HIGH);
    }
    
    if(i == 523){
        delay(500);
    }else{
      delay(5);
    }
  }
  noTone(spkr);
  digitalWrite(light, LOW);
 
}

void simonCheck(int condition){
  int light = light1 + 2;
  while(color == 0){
    if(condition > 0){
      condition++;
      digitalWrite(light, HIGH);
    }
    int push = 0;
    for(int i = right; i <= enter && color == 0; i++){
        push = digitalRead(i);
        if(push){
            color = i - 1;               
        }
     }

     if(condition == 15000){
        digitalWrite(light, LOW);
        if(light == light1 + 2){
            light = light1 + 10;
        }else if(light == light1 + 10){
            light = light1 + 21;
        }else if(light == light1 + 21){
            light = light1 + 13;
        }else if(light == light1 + 13){
            light = light1 + 2;
        }
        condition = 1;
     }
  }
  if(color == 5){
    inGame = 0;
    lcd.clear();
  }
}

void blink(int a){
  
    if(a == blue){
      digitalWrite(light1 + 13, HIGH);
      tone(spkr, 262); 
    }else if(a == green){
      digitalWrite(light1 + 10, HIGH);
      tone(spkr, 294);
    }else if(a == yellow){
      digitalWrite(light1 + 21, HIGH);
      tone(spkr, 392);
    }else{
      digitalWrite(light1 + 2, HIGH);
      tone(spkr, 523);
    }
    delay(speed * 5);
    noTone(spkr);
    delay(speed * 5);
    allOff();
    
    delay(speed * 10);
}

void playSimon(){
 start();
 while(inGame){
  if(score == 0){
    
  simonCheck(1);
    if(color == blue){
      speed = 50;
      delay(1000);
    playTune(3); 
    }
    if(color == green){
      speed = 35;
      delay(1000);
    playTune(4);       
    }
    if(color == yellow){
      speed = 20;
      delay(1000);
        playTune(6); 
         
    }
    if(color == red){
      speed = 12;
      delay(1000);
      playTune(5); 
    }
    if(color == 5){
      color = 0;
      allOff();
      break;
    }
    color = 0;
  delay(1000);
  }
    showHighscore();
    pattern[score] = random(1, 5);
    
  for(int j = 0; j <= score; j++){
      blink(pattern[j]);
        Serial.println(score);
    }
    for(int j = 0; j <= score; j++){
      simonCheck(0);
      if(color == pattern[j]){
            
          blink(color);
          color = 0;
        }else{
          color = 0;
          lose();
        }
    }
    score++;
    delay(1000);
 }
}

void mainMenu(){
    lcd.setCursor(0,0);
    lcd.print("   Simon");
    lcd.setCursor(0,1);
    lcd.print("   Snake");
}

void menuCheck(){
  int push = 1;
  while(push){
    for(int x = 2; x < 7; x++){
      if(digitalRead(x)){
        push = 0;
        direct = x;
      }
    }
  }
}


void reset(){
    head = 22;
    i = 0;
    direct = 0;
    islit = 0;
    fat = 0;
    allOff();
    delay(1000);
    if(digitalRead(enter)){
      inGame = 0;
    }
}
void on(int o){
    digitalWrite(o, HIGH);
}

void off(int f){
    digitalWrite(f, LOW);
}
void winner(){
    
}

void loser(){
  lcd.print("Your Score Was:");
  lcd.setCursor(7, 1);
  lcd.print(fat+1);
  allOff();
  for(int j = 22; j < 47; j++){
    if(j == 23 || j == 24 || j == 25 || j == 26 || j == 28 || j == 33 || j == 38 || j == 43){
      on(j);
    }
  }
  delay(750);
  allOff();
  for(int j = 22; j < 47; j++){
    if(j == 24 || j == 25 || j == 28 || j == 33 || j == 38 || j == 31 || j == 36 || j == 41 || j == 44 || j == 45){
      on(j);
    }
  }
  delay(750);
  allOff();
  for(int j = 22; j < 47; j++){
    if(j == 23 || j == 24 || j == 25 || j == 31 || j == 34 || j == 35 || j == 38 || j == 44 || j == 45 || j == 46){
      on(j);
    }
  }
  delay(750);
  allOff();
  for(int j = 22; j < 47; j++){
    if(j == 23 || j == 24 || j == 25 || j == 26 || j == 28 || j == 33 || j == 38 || j == 43 || j == 44 || j == 45 || j == 46 || j == 34 || j == 35){
      on(j);
    }
  }
  delay(750);
  allOff();
  for(int j = 22; j < 47; j++){
    if(j == 23 || j == 25 || j == 28 || j == 33 || j == 38 || j == 43 || j == 44 || j == 40 || j == 34 || j == 29){
      on(j);
    }
  }
  delay(750);
  allOff();
  lcd.clear();
}
void blinkhead(){
    on(head);
      delay(250);
    off(head); 
      delay(250);
    on(head);
      delay(250);
    off(head); 
      delay(250);
    on(head);
      delay(250);
}

void snakeCheck(){
  for(int j = 0; j < 20000; j++){
    for(int x = 2; x < 7; x++){
      if(digitalRead(x)){
        direct = x;
      }
    }
  }
}

void playSnake(){
 while(inGame){

  while(i < 1){
    blinkhead();    
    for(int s = 1; s < 26; s++){
        snake[s] = 0;
    }
    snake[0] = head;
  i++;
  }

  if(islit == 0){
    
    while(islit == 0){
      food = random(22, 47);
      for(int r = 0; r <= fat; r++){
        if(food == snake[r]){
          islit = 2;
        }
      }  
      if(islit != 2){  
        on(food);
        islit = 1;
      }else{
        islit = 0;
      }
    }
  }
  
  snakeCheck();
      
  temp = head;
  if(direct == up){
    if(head < 42){
      head = head + 5;
    }else{
      loser();
      reset();
    }
  }
  if(direct == left){
    if((head - 2) % 5 != 0){
      head = head - 1;
    }else{
      loser();
      reset();
    }
  }
  if(direct == down){
    if(head > 26){
      head = head - 5;
    }else{
      loser();
      reset();
    }
  }
  if(direct == right){
    if((head - 1) % 5 != 0){
      head = head + 1;
    }else{
      loser();
      reset();
    }
  }
  for(int lose = 0; lose < fat; lose++){
    if(head == snake[lose]){
      loser();
      reset();
    }
  }
  if(food == head){
    blinkhead();
    fat += 1;
    if(fat > 23){
      winner();
      reset();
    }
    snake[fat] = head;
    islit = 0;
  }else{
    off(snake[0]);
    on(head);
    snake[fat] = head;
    k = 0;  
    while(k < fat - 1){
      snake[k] = snake[k+1];
      k++;
    }
    if(fat > 0){
       snake[fat-1] = temp;
    }
  }
  if(digitalRead(enter)){
    reset();
  }  
 } 
}

void setup()
{

  randomSeed(analogRead(0));
  Serial.begin(9600);
  for(int i = 22; i < 47; i++){
    pinMode(i, OUTPUT);
  }
  for(int i = 2; i < 7; i++){
    pinMode(i, INPUT);
  }
  lcd.begin(16, 2);
  lcd.display();
  lcd.setCursor(3,0);
  lcd.print("Welcome To");
  lcd.setCursor(1,1);
  lcd.print("Arduino Gaming");
  delay(2000);
  lcd.clear();
  
}

void loop(){
  if(direct == 0){
    mainMenu();
  }
  menuCheck();
  if(direct == up){
    mainMenu();
    lcd.setCursor(0,0);
    lcd.print(">>");
    select = 1;
  }
  if(direct == down){
    mainMenu();
    lcd.setCursor(0,1);
    lcd.print(">>"); 
    select = 2;   
  }
  if(direct == enter && select){
    direct = 0;
    if(select == 1){
      select = 0;
      inGame = 1;
      lcd.clear();
      playSimon();
    }
    if(select == 2){
      select = 0;
      inGame = 1;
      lcd.clear();
      playSnake();
    }
  }
  
}

