
if (val > val_old)
{
  if (A >= 1 && A < 19)
  {
    A ++;
    if (A >= 19)
    {
      A = 19;
    }
  }

  ///////////////////////////////////////////////

  if (A == 21)
  {
    if (vent_wait < 100)
    {
      vent_wait ++;
    }
  }
  if (A == 22)
  {
    if (vent_ignition < 100)
    {
      vent_ignition ++;
    }
  }
  if (A == 23)
  {
    if (vent_heat < 100)
    {
      vent_heat ++;
    }
  }
  if (A == 24)
  {
    if (vent_support < 100)
    {
      vent_support ++;
    }
  }
  if (A == 25)
  {
    if (vent_reburn < 100)
    {
      vent_reburn ++;
    }
  }
  if (A == 26)
  {
    if (screw_ignition < 99)
    {
      screw_ignition ++;
    }
  }
  if (A == 27)
  {
    if (screw_heat < 99)
    {
      screw_heat ++;
    }
  }
  if (A == 28)
  {
    if (screw_support < 99)
    {
      screw_support ++;
    }
  }
  if (A == 29)
  {
    if (time_lamp_on < 99)
    {
      time_lamp_on ++;
    }
  }
  if (A == 30)
  {
    if (time_lamp < 30)
    {
      time_lamp ++;
    }
  }
  if (A == 31)
  {
    if (time_flame < 60)
    {
      time_flame ++;
    }
  }
  if (A == 32)
  {
    if (screw_interval < 99)
    {
      screw_interval ++;
    }
  }
  if (A == 33)
  {
    if (time_ignition < 30)
    {
      time_ignition ++;
    }
  }
  if (A == 34)
  {
    if (temp_max < 90)
    {
      temp_max ++;
    }
  }
  if (A == 35)
  {
    if (temp_control < 90)
    {
      temp_control ++;
    }
  }
  if (A == 36)
  {
    if (temp_gist < 20)
    {
      temp_gist ++;
    }
  }
  if (A == 37)
  {
    if (time_reburn < 30)
    {
      time_reburn ++;
    }
  }
  if (A == 38)
  {
    if (temp_flame_control < 90)
    {
      temp_flame_control ++;
    }
  }
  if (A == 39)
  {
    if (temp_flame_max < 500)
    {
      temp_flame_max += 10;
    }
  }

  val_old = val;
}



