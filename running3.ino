void Running3() {
  // rule 3,1,4,2,4,2,3,1,3,1
  
  //Menampilkan LED
  if (flag[0]) {
    Relay3on();
  } else if (flag[1]) {
    Relay1on();
  } else if (flag[2]) {
    Relay4on();
  } else if (flag[3]) {
    Relay2on();
  } else if (flag[4]) {
    Relay4on();
  } else if (flag[5]) {
    Relay2on();
  } else if (flag[6]) {
    Relay3on();
  } else if (flag[7]) {
    Relay1on();
  } else if (flag[8]) {
    Relay3on();
  } else if (flag[9]) {
    Relay1on();
  } else {
    Relayoff();
  }

  if (millis() >= timerButton) {
    RunningFail();
    BuzzerOff();
    runningFailed = true;
  }

  if (digitalRead(tombol3) == 0 && flag[0]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp1 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 1 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
  }
  else if (digitalRead(tombol1) == 0 && flag[1]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp2 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 2 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
  }
  else if (digitalRead(tombol4) == 0 && flag[2]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp3 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 3 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
  }
  else if (digitalRead(tombol2) == 0 && flag[3]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp4 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 4 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
  }
  else if (digitalRead(tombol4) == 0 && flag[4]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp5 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 5 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
  }
  else if (digitalRead(tombol2) == 0 && flag[5]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp6 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 6 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
  }
  else if (digitalRead(tombol3) == 0 && flag[6]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp7 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 7 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
  }
  else if (digitalRead(tombol1) == 0 && flag[7]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp8 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 8 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
  }
  else if (digitalRead(tombol3) == 0 && flag[8]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    lasttimer[posisitimer + 1] = waktuberjalan;
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp9 = timer[posisitimer];
    lcd.setCursor(0, 0);
    lcd.print("  CP 9 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
  }
  else if (digitalRead(tombol1) == 0 && flag[9]) {
    waktuberjalan = millis();
    timer[posisitimer] = waktuberjalan - lasttimer[posisitimer] + timer[posisitimer - 1];
    //    Serial.print("timer : ");
    //    Serial.print(timer[posisitimer]);
    //    Serial.print("   waktu berjalan : ");
    //    Serial.print(waktuberjalan);
    //    Serial.print("   last timer : ");
    //    Serial.println(lasttimer[posisitimer]);
    cp10 = timer[posisitimer];
    //totalcp = cp1 + cp2 + cp3 + cp4 + cp5 + cp6 + cp7 + cp8 + cp9 + cp10;
    //    Serial.println(cp10);
    //    Serial.println(float(cp10) / 1000.0);
    //    Serial.println(float(cp10) / 60.0);
    minutes = ((cp10 % day) % hour) / minute ;
    seconds = (((cp10 % day) % hour) % minute) / second;
    millisc = ((((cp10 % day) % hour) % minute) % second) % second;
    lcd.setCursor(0, 0);
    lcd.print("  CP 10 : DONE ! ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //    Serial.println(posisitimer);
    //    Serial.println(timer[posisitimer]);
    parsingData();
    //    Serial.println(lasttimer[posisitimer]);
    //lasttimer[posisitimer] = timer[posisitimer];
    flag[posisitimer] = false;
    posisitimer++;
    flag[posisitimer] = true;
    //    Serial.println(posisitimer);
    timerButton = millis() + bataswaktu;
    BuzzerOff();
    RunningSelesai();
    runningDone = true;
  }
}
