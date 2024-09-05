
val = encoderValue / 4;
if (val < val_old)
{
  if (A >= 1 && A <= 19)
  {
    A --;
    if (A <= 1)
    {
      A = 1;
    }
  }

  //////////////////////////////////////////////////////

  if (A == 21)
  {
    if (vent_wait > 10)
    {
      vent_wait --;
    }
  }
  if (A == 22)
  {
    if (vent_ignition > 10)
    {
      vent_ignition --;
    }
  }
  if (A == 23)
  {
    if (vent_heat > 10)
    {
      vent_heat --;
    }
  }
  if (A == 24)
  {
    if (vent_support > 10)
    {
      vent_support --;
    }
  }
  if (A == 25)
  {
    if (vent_reburn > 10)
    {
      vent_reburn --;
    }
  }
  if (A == 26)
  {
    if (screw_ignition > 1)
    {
      screw_ignition --;
    }
  }
  if (A == 27)
  {
    if (screw_heat > 1)
    {
      screw_heat --;
    }
  }
  if (A == 28)
  {
    if (screw_support > 1)
    {
      screw_support --;
    }
  }
  if (A == 29)
  {
    if (time_lamp_on > 1)
    {
      time_lamp_on --;
    }
  }
  if (A == 30)
  {
    if (time_lamp > 1)
    {
      time_lamp --;
    }
  }
  if (A == 31)
  {
    if (time_flame > 1)
    {
      time_flame --;
    }
  }
  if (A == 32)
  {
    if (screw_interval > 1)
    {
      screw_interval --;
    }
  }
  if (A == 33)
  {
    if (time_ignition > 1)
    {
      time_ignition --;
    }
  }
  if (A == 34)
  {
    if (temp_max > 80)
    {
      temp_max --;
    }
  }
  if (A == 35)
  {
    if (temp_control > 20)
    {
      temp_control --;
    }
  }
  if (A == 36)
  {
    if (temp_gist > 2)
    {
      temp_gist --;
    }
  }
  if (A == 37)
  {
    if (time_reburn > 1)
    {
      time_reburn --;
    }
  }
  if (A == 38)
  {
    if (temp_flame_control > 30)
    {
      temp_flame_control --;
    }
  }
  if (A == 39)
  {
    if (temp_flame_max > 200)
    {
      temp_flame_max -= 10;
    }
  }

  val_old = val;
}



