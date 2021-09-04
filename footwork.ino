#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define tombol1 6
#define tombol2 7
#define tombol3 8
#define tombol4 9
#define relay1 2
#define relay2 3
#define relay3 4
#define relay4 5
#define buzzer 11
long day = 86400000;
long hour = 3600000;
long minute = 60000;
long second =  1000;
int days, hours, minutes, seconds, millisc;
long timer[10], timerButton, timerLCD;
long lasttimer[10];
int posisitimer = 0;
bool flag[10] = {true, false, false, false, false, false, false, false, false, false}, runningFailed = false, runningDone = false;
unsigned long waktuberjalan = 0;
unsigned long lastwaktuberjalan = 0;
long cp1, cp2, cp3, cp4, cp5, cp6, cp7, cp8, cp9, cp10, totalcp;
int ledflag = 0;
const int button = 10;
long bataswaktu = 10000;
long rule;

void setup() {
  Serial.begin(9600);
  //-----------------------------------------//
  pinMode(buzzer, OUTPUT);
  //-----------------------------------------//
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Latihan Footwork");
  lcd.setCursor(0, 1);
  lcd.print("  Bulu Tangkis  ");
  delay(3000);
  lcd.clear();
  //-----------------------------------------//
  pinMode(tombol1, INPUT_PULLUP);
  pinMode(tombol2, INPUT_PULLUP);
  pinMode(tombol3, INPUT_PULLUP);
  pinMode(tombol4, INPUT_PULLUP);
  //-----------------------------------------//
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  //-----------------------------------------//
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  waktuberjalan = millis();
  //  Serial.println(waktuberjalan);
  if (digitalRead(button) == LOW) {
    while (digitalRead(button) == LOW) {
      for (int i = 1; i <= random(100); i++) {
        rule = random(1, 6);
        Serial.println(rule);
      }
      Serial.println(rule);
    }

    if (ledflag == 0) {
      for (int i = 0; i <= 2; i++)
      {
        digitalWrite(buzzer, HIGH);
        if (i == 2) {
          delay(1000);
        }
        else {
          delay(500);
        }
        digitalWrite(buzzer, LOW);
        delay(500);
      }
      waktuberjalan = millis();
      lastwaktuberjalan = waktuberjalan;
      timerButton = waktuberjalan + bataswaktu;
      lasttimer[posisitimer] = lastwaktuberjalan;
      waktuberjalan = millis();
      if (rule == 1) {
        Serial.println("Rule 1");
        while (1) {
          Running1();
          if (runningFailed)
            break;
          else if (runningDone)
            break;
        }
      } else if (rule == 2) {
        Serial.println("Rule 2");
        while (1) {
          Running2();
          if (runningFailed)
            break;
          else if (runningDone)
            break;
        }
      } else if (rule == 3) {
        Serial.println("Rule 3");
        while (1) {
          Running3();
          if (runningFailed)
            break;
          else if (runningDone)
            break;
        }
      } else if (rule == 4) {
        Serial.println("Rule 4");
        while (1) {
          Running4();
          if (runningFailed)
            break;
          else if (runningDone)
            break;
        }
      } else if (rule == 5) {
        Serial.println(random(1, 10));
        while (1) {
          Running5();
          if (runningFailed)
            break;
          else if (runningDone)
            break;
        }
      }
    }
    else {
      ledflag = 0;
      Serial.println("Nggak Dong !");
    }
    delay(1000);
  }
}

void RunningSelesai() {
  lcd.setCursor(0, 0);
  lcd.print("Footwork Done !");
  lcd.setCursor(0, 1);
  lcd.print("Waktu : ");
  printMinute(minutes);
  printSecond(seconds);
  lcd.print('.');
  lcd.print(millisc);
  Serial.println();
  printMinute(minutes);
  printSecond(seconds);
  Serial.print(".");
  Serial.print(millisc);
  Serial.println();
  ledflag = 1;
  Serial.println("trig 0");
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void RunningFail() {
  lcd.setCursor(0, 0);
  lcd.print("Footwork Gagal !");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  ledflag = 1;
  Serial.println("trig 0");
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void printMinute(byte digits) {
  if (digits < 10) {
    Serial.print('0'); lcd.print("0");
  }
  lcd.print(digits, DEC);
  Serial.print(digits, DEC);
}

void printSecond(byte digits) {
  Serial.print(":");
  lcd.print(":");
  if (digits < 10) {
    Serial.print('0'); lcd.print("0");
  }
  lcd.print(digits, DEC);
  Serial.print(digits, DEC);
}

void Relay1on() {
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void Relay2on() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void Relay3on() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
}

void Relay4on() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
}

void Relayoff() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void BuzzerOff() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void parsingData() {
  if (cp1 != 0 && cp2 != 0 && cp3 != 0 && cp4 != 0 && cp5 != 0 && cp6 != 0 && cp7 != 0 && cp8 != 0 && cp9 != 0 && cp10 != 0) {
    Serial.println("trig 1");
    Serial.print("cp1 "); Serial.println(cp1);
    Serial.print("cp2 "); Serial.println(cp2);
    Serial.print("cp3 "); Serial.println(cp3);
    Serial.print("cp4 "); Serial.println(cp4);
    Serial.print("cp5 "); Serial.println(cp5);
    Serial.print("cp6 "); Serial.println(cp6);
    Serial.print("cp7 "); Serial.println(cp7);
    Serial.print("cp8 "); Serial.println(cp8);
    Serial.print("cp9 "); Serial.println(cp9);
    Serial.print("cp10 "); Serial.println(cp10);
  }
  else {
    Serial.println("trig 0");
  }
}
