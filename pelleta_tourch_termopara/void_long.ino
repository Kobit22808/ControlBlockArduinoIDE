

void LongPressStart()
{
  if (A >= 1 && A <= 19)
  {
    EEPROM.write(21, vent_wait);
    EEPROM.write(22, vent_ignition);
    EEPROM.write(23, vent_heat);
    EEPROM.write(24, vent_support);
    EEPROM.write(25, vent_reburn);
    EEPROM.write(26, screw_ignition);
    EEPROM.write(27, screw_heat);
    EEPROM.write(28, screw_support);
    EEPROM.write(29, time_lamp_on);
    EEPROM.write(30, time_lamp);
    EEPROM.write(31, time_flame);
    EEPROM.write(32, screw_interval);
    EEPROM.write(33, time_ignition);
    EEPROM.write(34, temp_max);
    EEPROM.write(35, temp_control);
    EEPROM.write(36, temp_gist);
    EEPROM.write(37, time_reburn);
    
    EEPROM.write(180, beeper_on_off);
    
    EEPROM.put(210, temp_flame_control);
    EEPROM.put(220, temp_flame_max);

    lcd.clear();
    A = 0;
  }
  else if (A > 20 && pos == 1)
  {
    A = A - 20;
    pos = 0;
  }
}
