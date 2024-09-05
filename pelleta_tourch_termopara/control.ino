


switch (state) {
case 0:                                        ///  ожидание
  {
    analogWrite(VENT, (vent_wait * 255) / 100);
  }
  break;
case 1:                                        ///  розжиг ///////////////////
  {
    analogWrite(VENT, (vent_ignition * 255) / 100);

    if (millis() - ignition_Millis > 1000)
    {
      count_ignition ++;
      ignition_Millis = millis();
    }

    if (count_ignition >= screw_ignition)      ///  вырубили подачу
    {
      digitalWrite(MOTOR, LOW);
    }

    if (count_ignition >= time_lamp_on)        ///  вкл лампу
    {
      digitalWrite(LAMP, HIGH);
    }

    if (count_ignition - time_lamp_on >= time_lamp * 60)  ///  выкл лампу
    {
      digitalWrite(LAMP, LOW);
    }

    ///////// обнаружили пламя ///////////////////////////////////////////////////////////////////////////

    if (temp_flame >= temp_flame_control)
    {
      if (flame_state == 0)
      {
        count_flame = count_ignition;
        flame_state = 1;
      }
    }

    ////////////  время фиксации пламени  ///////////////////

    if (count_ignition - count_flame >= time_flame && temp_flame >= temp_flame_control && flame_state == 1)
    {
      digitalWrite(LAMP, LOW);
      digitalWrite(MOTOR, HIGH);
      count_ignition = 0;
      heat_Millis = millis();
      //flame_state = 0;
      state = 2;
    }
    else if (count_ignition - count_flame >= time_flame && temp_flame < temp_flame_control && flame_state == 1)
    {
      digitalWrite(LAMP, LOW);
      digitalWrite(MOTOR, LOW);
      count_ignition = 0;
      flame_state = 0;
      state = 0;
    }

    //////////  прошло время розжига, пламени  не было  ///////////////////////////////////////////////////////

    if (count_ignition >= time_ignition * 60 && temp_flame < temp_flame_control && flame_state == 0)
    {
      digitalWrite(LAMP, LOW);
      digitalWrite(MOTOR, LOW);
      count_ignition = 0;
      flame_state = 0;
      state = 0;
    }
  }
  break;
case 2:                                        ///  нагрев
  {
    analogWrite(VENT, (vent_heat * 255) / 100);
    SCREW_HEAT();

    if (temp_in >= temp_control)
    {
      support_Millis = millis();
      digitalWrite(MOTOR, HIGH);

      state = 3;
    }

    ///////////  пропало пламя  //////////////

    if (temp_flame < temp_flame_control && flame_state == 1)
    {
      digitalWrite(MOTOR, LOW);
      count_ignition = 0;
      flame_state = 0;
      state = 0;
    }
  }
  break;
case 3:                                        ///  поддержка
  {
    analogWrite(VENT, (vent_support * 255) / 100);
    SCREW_SUPPORT();

    if (temp_in <= temp_control - temp_gist)
    {
      heat_Millis = millis();
      digitalWrite(MOTOR, HIGH);

      state = 2;
    }

    ///////////  пропало пламя  //////////////

    if (temp_flame < temp_flame_control && flame_state == 1)
    {
      digitalWrite(MOTOR, LOW);
      count_ignition = 0;
      flame_state = 0;
      state = 0;
    }
  }
  break;
case 4:                                        ///  выжигание
  {
    analogWrite(VENT, (vent_reburn * 255) / 100);

    if (millis() - reburn_Millis > 1000)
    {
      count_reburn ++;
      reburn_Millis = millis();
    }

    if (count_reburn >= time_reburn * 60)
    {
      count_reburn = 0;
      beeper_state = 0;

      if (error_state_temp == 0 && error_state_in == 0 && error_state_out == 0 && error_state_flame == 0)
      {
        state = 0;
      }
      else if (error_state_temp == 1)
      {
        lcd.clear();
        A = 100;
        state = 100;
      }
      else if (error_state_in == 1)
      {
        lcd.clear();
        A = 101;
        state = 100;
      }
      else if (error_state_out == 1)
      {
        lcd.clear();
        A = 102;
        state = 100;
      }
      else if (error_state_flame == 1)
      {
        lcd.clear();
        A = 103;
        state = 100;
      }
    }
  }
  break;

case 100:                                      ///  аварии
  {
    analogWrite(VENT, 0);
  }
  break;
}





