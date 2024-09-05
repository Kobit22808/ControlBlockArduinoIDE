

void Click()
{
  if ( A == 0)
  {
    lcd.clear();
    A = 1;
    pos = 0;
  }
  else if ((A >= 1 && A <= 19) && pos == 0)
  {
    A = A + 20;
    pos = 1;
  }
}

////////////////////////////////////////////

void PUSK()
{
  if ((state == 0 || state == 200) && error_state_in == 0 && error_state_out == 0
      &&  error_state_temp == 0 &&  error_state_flame == 0)
  {
    digitalWrite(MOTOR, HIGH);
    ignition_Millis = millis();

    state = 1;
  }
  else if (state >= 1 && state <= 3)
  {
    digitalWrite(LAMP, LOW);
    digitalWrite(MOTOR, LOW);
    reburn_Millis = millis();

    state = 4;
  }
}





