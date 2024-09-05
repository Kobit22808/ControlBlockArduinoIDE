

void updateEncoder()
{
  int MSB = digitalRead(encoderPin1);
  int LSB = digitalRead(encoderPin2);

  int encoded = (MSB << 1) | LSB;
  int sum  = (lastEncoded << 2) | encoded;

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
    encoderValue --;

  lastEncoded = encoded;
}

//////////////////  заставка 1  //////////////////////

void ZASTAVKA_1()
{
  lcd.createChar(0, bukva_P);
  lcd.createChar(1, bukva_l);
  lcd.createChar(2, bukva_t);
  lcd.createChar(3, bukva_n);
  lcd.createChar(4, bukva_iya);
  lcd.createChar(5, bukva_g);
  lcd.createChar(6, bukva_k);
  lcd.createChar(7, bukva_p);

  lcd.setCursor(3, 0);
  lcd.write((byte)0);
  lcd.print("e");
  lcd.write(1);
  lcd.write(1);
  lcd.print("e");
  lcd.write(2);
  lcd.write(3);
  lcd.print("a");
  lcd.write(4);

  lcd.setCursor(4, 1);
  lcd.write(5);
  lcd.print("o");
  lcd.print("p");
  lcd.print("e");
  lcd.write(1);
  lcd.write(6);
  lcd.print("a");
}

//////////////////  заставка 2  //////////////////////

void ZASTAVKA_2()
{
  lcd.setCursor(3, 1);
  lcd.print("Version 1.0");
}

////////////////  сигнал  ///////////////////

void BEEP()
{
  static bool beep;
  static unsigned long beep_time;

  if ((millis() - beep_time) > (beep ? 500 : 2000))
  {
    beep = !beep;
    beep_count += 2500;
    beep_time = millis();
  }

  if (beep == true)
    tone(BEEPER, 1300);
  else
    noTone(BEEPER);

  //////  пробибикали 2 мин  /////////////////

  if (beep_count >= 120000)
  {
    beep_count = 0;
    beeper_state = 2;
  }
}

/////////////////////////////////
