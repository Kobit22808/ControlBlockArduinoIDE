

void SCREW_HEAT()
{
  if (millis() - heat_Millis > (long)screw_heat * 1000)
  {
    digitalWrite(MOTOR, LOW);
  }

  if (millis() - heat_Millis > ((long)(screw_heat + screw_interval) * 1000))
  {
    digitalWrite(MOTOR, HIGH);
    heat_Millis = millis();
  }
}

///////////////////////////////////

void SCREW_SUPPORT()
{
  if (millis() - support_Millis > (long)screw_support * 1000)
  {
    digitalWrite(MOTOR, LOW);
  }

  if (millis() - support_Millis > ((long)(screw_support + screw_interval) * 1000))
  {
    digitalWrite(MOTOR, HIGH);
    support_Millis = millis();
  }
}
