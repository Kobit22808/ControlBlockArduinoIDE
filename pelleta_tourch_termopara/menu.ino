


if (A == 0)
{

  lcd.setCursor(0, 0);
  lcd.print("T");
  lcd.setCursor(2, 0);
  lcd.print("_");
  lcd.setCursor(3, 0);
  if (error_state_in == 0 && temp_in > 0)
  {
    if (temp_in < 10)
    {
      lcd.print(" ");
      lcd.print(temp_in);
    }
    else
      lcd.print(temp_in);
  }
  else
    lcd.print("Er");
  lcd.setCursor(6, 0);
  lcd.print("C");

  lcd.setCursor(1, 1);
  lcd.print("_");

  if (temp_flame < 100)
  {
    lcd.print(" ");
    lcd.print(temp_flame);
  }
  else
    lcd.print(temp_flame);

  ///////////////////////////////////

  lcd.setCursor(8, 1);
  if (state == 0)
  {
    lcd.createChar(0, gradus);
    lcd.createChar(1, bukva_k);
    lcd.createChar(2, bukva_P);
    lcd.createChar(3, bukva_z);
    lcd.createChar(4, bukva_i);
    lcd.createChar(5, bukva_d);
    lcd.createChar(6, bukva_n);

    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.setCursor(5, 0);
    lcd.write((byte)0);
    lcd.setCursor(14, 0);
    lcd.write((byte)0);
    lcd.setCursor(0, 1);
    lcd.write((byte)2);

    lcd.setCursor(5, 1);
    lcd.write((byte)0);
    lcd.print("C");

    lcd.setCursor(7, 1);
    lcd.print(" O");
    lcd.write((byte)3);
    lcd.write((byte)4);
    lcd.write((byte)5);
    lcd.print("a");
    lcd.write((byte)6);
    lcd.write((byte)4);
    lcd.print("e");
  }
  else if (state == 1)
  {
    lcd.createChar(0, gradus);
    lcd.createChar(1, bukva_k);
    lcd.createChar(2, bukva_P);
    lcd.createChar(3, bukva_ze);
    lcd.createChar(4, bukva_z);
    lcd.createChar(5, bukva_i);
    lcd.createChar(6, bukva_g);

    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.setCursor(5, 0);
    lcd.write((byte)0);
    lcd.setCursor(14, 0);
    lcd.write((byte)0);
    lcd.setCursor(0, 1);
    lcd.write((byte)2);

    lcd.setCursor(5, 1);
    lcd.write((byte)0);
    lcd.print("C");

    lcd.setCursor(7, 1);
    lcd.print("   Po");
    lcd.write((byte)3);
    lcd.write((byte)4);
    lcd.write((byte)5);
    lcd.write((byte)6);
  }
  else if (state == 2)
  {
    lcd.createChar(0, gradus);
    lcd.createChar(1, bukva_k);
    lcd.createChar(2, bukva_P);
    lcd.createChar(3, bukva_g);
    lcd.createChar(4, bukva_v);

    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.setCursor(5, 0);
    lcd.write((byte)0);
    lcd.setCursor(14, 0);
    lcd.write((byte)0);
    lcd.setCursor(0, 1);
    lcd.write((byte)2);

    lcd.setCursor(5, 1);
    lcd.write((byte)0);
    lcd.print("C");

    lcd.setCursor(7, 1);
    lcd.print("   Ha");
    lcd.write((byte)3);
    lcd.print("pe");
    lcd.write((byte)4);
  }
  else if (state == 3)
  {
    lcd.createChar(0, gradus);
    lcd.createChar(1, bukva_k);
    lcd.createChar(2, bukva_P);
    lcd.createChar(3, bukva_d);
    lcd.createChar(4, bukva_z);
    lcd.createChar(5, bukva_i);
    lcd.createChar(6, bukva_g);

    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.setCursor(5, 0);
    lcd.write((byte)0);
    lcd.setCursor(14, 0);
    lcd.write((byte)0);
    lcd.setCursor(0, 1);
    lcd.write((byte)2);

    lcd.setCursor(5, 1);
    lcd.write((byte)0);
    lcd.print("C");

    lcd.setCursor(7, 1);
    lcd.write((byte)2);
    lcd.print("o");
    lcd.write((byte)3);
    lcd.write((byte)3);
    lcd.print("ep");
    lcd.write((byte)4);
    lcd.write((byte)1);
    lcd.print("a");
  }
  else if (state == 4)
  {
    lcd.createChar(0, gradus);
    lcd.createChar(1, bukva_k);
    lcd.createChar(2, bukva_P);
    lcd.createChar(3, bukva_iii);
    lcd.createChar(4, bukva_z);
    lcd.createChar(5, bukva_i);
    lcd.createChar(6, bukva_g);
    lcd.createChar(7, bukva_n);

    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.setCursor(5, 0);
    lcd.write((byte)0);
    lcd.setCursor(14, 0);
    lcd.write((byte)0);
    lcd.setCursor(0, 1);
    lcd.write((byte)2);

    lcd.setCursor(5, 1);
    lcd.write((byte)0);
    lcd.print("C");

    lcd.setCursor(7, 1);
    lcd.print("B");
    lcd.write((byte)3);
    lcd.write((byte)4);
    lcd.write((byte)5);
    lcd.write((byte)6);
    lcd.print("a");
    lcd.write((byte)7);
    lcd.write((byte)5);
    lcd.print("e");
  }
}

///////////////////////////////////

if (A > 0)
{
  if (pos == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("> ");
    lcd.setCursor(0, 1);
    lcd.print("  ");
  }
  else if (pos == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("  ");
    lcd.setCursor(0, 1);
    lcd.print("> ");
  }
}

////////////////////////////////////////////

if (A == 1 || A == 21)
{
  lcd.createChar(0, bukva_n);
  lcd.createChar(1, bukva_t);
  lcd.createChar(2, bukva_z);
  lcd.createChar(3, bukva_i);
  lcd.createChar(4, bukva_d);


  lcd.setCursor(2, 0);
  lcd.print("Be");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.print("o");
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.print("a");
  lcd.write((byte)0);
  lcd.write((byte)3);
  lcd.print("e ");

  lcd.setCursor(6, 1);
  if (vent_wait < 100)
  {
    lcd.print(" ");
    lcd.print(vent_wait);
  }
  else
    lcd.print(vent_wait);
  lcd.print(" %    ");
}

///////////////////////////////////

if (A == 2 || A == 22)
{
  lcd.createChar(0, bukva_n);
  lcd.createChar(1, bukva_t);
  lcd.createChar(2, bukva_ze);
  lcd.createChar(3, bukva_z);
  lcd.createChar(4, bukva_i);
  lcd.createChar(5, bukva_g);


  lcd.setCursor(2, 0);
  lcd.print(" Be");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.print("po");
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.print("  ");

  lcd.setCursor(6, 1);
  if (vent_ignition < 100)
  {
    lcd.print(" ");
    lcd.print(vent_ignition);
  }
  else
    lcd.print(vent_ignition);
  lcd.print(" %    ");
}

///////////////////////////////////

if (A == 3 || A == 23)
{
  lcd.createChar(0, bukva_n);
  lcd.createChar(1, bukva_t);
  lcd.createChar(2, bukva_g);
  lcd.createChar(3, bukva_v);

  lcd.setCursor(2, 0);
  lcd.print(" Be");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)0);
  lcd.print("a");
  lcd.write((byte)2);
  lcd.print("pe");
  lcd.write((byte)3);
  lcd.print("  ");

  lcd.setCursor(6, 1);
  if (vent_heat < 100)
  {
    lcd.print(" ");
    lcd.print(vent_heat);
  }
  else
    lcd.print(vent_heat);
  lcd.print(" %    ");
}

///////////////////////////////////

if (A == 4 || A == 24)
{
  lcd.createChar(0, bukva_n);
  lcd.createChar(1, bukva_t);
  lcd.createChar(2, bukva_p);
  lcd.createChar(3, bukva_d);
  lcd.createChar(4, bukva_z);
  lcd.createChar(5, bukva_k);

  lcd.setCursor(2, 0);
  lcd.print("Be");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)2);
  lcd.print("o");
  lcd.write((byte)3);
  lcd.write((byte)3);
  lcd.print("ep");
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.print("a");

  lcd.setCursor(6, 1);
  if (vent_support < 100)
  {
    lcd.print(" ");
    lcd.print(vent_support);
  }
  else
    lcd.print(vent_support);
  lcd.print(" %    ");
}

///////////////////////////////////

if (A == 5 || A == 25)
{
  lcd.createChar(0, bukva_n);
  lcd.createChar(1, bukva_t);
  lcd.createChar(2, bukva_v);
  lcd.createChar(3, bukva_iii);
  lcd.createChar(4, bukva_z);
  lcd.createChar(5, bukva_i);
  lcd.createChar(6, bukva_g);

  lcd.setCursor(2, 0);
  lcd.print("Be");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.write((byte)6);
  lcd.print("a");
  lcd.write((byte)0);
  lcd.write((byte)5);
  lcd.print("e");

  lcd.setCursor(6, 1);
  if (vent_reburn < 100)
  {
    lcd.print(" ");
    lcd.print(vent_reburn);
  }
  else
    lcd.print(vent_reburn);
  lcd.print(" %    ");
}

///////////////////////////////////

if (A == 6 || A == 26)
{
  lcd.createChar(0, bukva_SH);
  lcd.createChar(1, bukva_n);
  lcd.createChar(2, bukva_k);
  lcd.createChar(3, bukva_ze);
  lcd.createChar(4, bukva_z);
  lcd.createChar(5, bukva_i);
  lcd.createChar(6, bukva_g);

  lcd.setCursor(2, 0);
  lcd.print(" ");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("e");
  lcd.write((byte)2);
  lcd.print("_po");
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.write((byte)6);
  lcd.print("  ");

  lcd.setCursor(6, 1);
  if (screw_ignition < 10)
  {
    lcd.print(" ");
    lcd.print(screw_ignition);
  }
  else
    lcd.print(screw_ignition);
  lcd.print(" ce");
  lcd.write((byte)2);
  lcd.print("     ");
}

///////////////////////////////////

if (A == 7 || A == 27)
{
  lcd.createChar(0, bukva_SH);
  lcd.createChar(1, bukva_n);
  lcd.createChar(2, bukva_k);
  lcd.createChar(3, bukva_g);
  lcd.createChar(4, bukva_v);

  lcd.setCursor(2, 0);
  lcd.print(" ");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("e");
  lcd.write((byte)2);
  lcd.print("_");
  lcd.write((byte)1);
  lcd.print("a");
  lcd.write((byte)3);
  lcd.print("pe");
  lcd.write((byte)4);
  lcd.print("  ");

  lcd.setCursor(6, 1);
  if (screw_heat < 10)
  {
    lcd.print(" ");
    lcd.print(screw_heat);
  }
  else
    lcd.print(screw_heat);
  lcd.print(" ce");
  lcd.write((byte)2);
  lcd.print("     ");
}

///////////////////////////////////

if (A == 8 || A == 28)
{
  lcd.createChar(0, bukva_SH);
  lcd.createChar(1, bukva_n);
  lcd.createChar(2, bukva_k);
  lcd.createChar(3, bukva_p);
  lcd.createChar(4, bukva_d);
  lcd.createChar(5, bukva_z);
  lcd.createChar(6, bukva_k);

  lcd.setCursor(2, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("e");
  lcd.write((byte)2);
  lcd.print("_");
  lcd.write((byte)3);
  lcd.print("o");
  lcd.write((byte)4);
  lcd.write((byte)4);
  lcd.print("ep");
  lcd.write((byte)5);
  lcd.write((byte)6);
  lcd.print("a");

  lcd.setCursor(6, 1);
  if (screw_support < 10)
  {
    lcd.print(" ");
    lcd.print(screw_support);
  }
  else
    lcd.print(screw_support);
  lcd.print(" ce");
  lcd.write((byte)2);
  lcd.print("     ");
}

///////////////////////////////////

if (A == 9 || A == 29)
{
  lcd.createChar(0, bukva_k);
  lcd.createChar(1, bukva_l);
  lcd.createChar(2, bukva_m);
  lcd.createChar(3, bukva_p);
  lcd.createChar(4, bukva_iii);

  lcd.setCursor(2, 0);
  lcd.print("  B");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)1);
  lcd.print("a");
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.print("   ");

  lcd.setCursor(6, 1);
  if (time_lamp_on < 10)
  {
    lcd.print(" ");
    lcd.print(time_lamp_on);
  }
  else
    lcd.print(time_lamp_on);
  lcd.print(" ce");
  lcd.write((byte)0);
  lcd.print("     ");
}


///////////////////////////////////////////

if (A == 10 || A == 30)
{
  lcd.createChar(0, bukva_b);
  lcd.createChar(1, bukva_t);
  lcd.createChar(2, bukva_l);
  lcd.createChar(3, bukva_m);
  lcd.createChar(4, bukva_p);
  lcd.createChar(5, bukva_iii);
  lcd.createChar(6, bukva_i);
  lcd.createChar(7, bukva_n);

  lcd.setCursor(2, 0);
  lcd.print("Pa");
  lcd.write((byte)0);
  lcd.print("o");
  lcd.write((byte)1);
  lcd.print("a ");
  lcd.write((byte)2);
  lcd.print("a");
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.print("    ");

  lcd.setCursor(6, 1);
  if (time_lamp < 10)
  {
    lcd.print(" ");
    lcd.print(time_lamp);
  }
  else
    lcd.print(time_lamp);
  lcd.print(" ");
  lcd.write((byte)3);
  lcd.write((byte)6);
  lcd.write((byte)7);
  lcd.print("     ");
}

////////////////////////////////////////////////

if (A == 11 || A == 31)
{
  lcd.createChar(0, bukva_F);
  lcd.createChar(1, bukva_i);
  lcd.createChar(2, bukva_k);
  lcd.createChar(3, bukva_p);
  lcd.createChar(4, bukva_l);
  lcd.createChar(5, bukva_m);
  lcd.createChar(6, bukva_n);

  lcd.setCursor(2, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.print("c_");
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.print("a");
  lcd.write((byte)5);
  lcd.print("e");
  lcd.write((byte)6);
  lcd.write((byte)1);
  lcd.print("   ");

  lcd.setCursor(6, 1);
  if (time_flame < 10)
  {
    lcd.print(" ");
    lcd.print(time_flame);
  }
  else
    lcd.print(time_flame);
  lcd.print(" ce");
  lcd.write((byte)2);
  lcd.print("     ");
}

//////////////////////////////////////////////////////

if (A == 12 || A == 32)
{
  lcd.createChar(0, bukva_k);
  lcd.createChar(1, bukva_l);
  lcd.createChar(2, bukva_scha);
  lcd.createChar(3, bukva_n);
  lcd.createChar(4, bukva_k);

  lcd.setCursor(2, 0);
  lcd.print("  B");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.print("e");
  lcd.write((byte)4);
  lcd.print("a   ");

  lcd.setCursor(6, 1);
  if (screw_interval < 10)
  {
    lcd.print(" ");
    lcd.print(screw_interval);
  }
  else
    lcd.print(screw_interval);
  lcd.print(" ce");
  lcd.write((byte)0);
  lcd.print("     ");
}

///////////////////////////////////////////////

if (A == 13 || A == 33)
{
  lcd.createChar(0, bukva_z);
  lcd.createChar(1, bukva_ze);
  lcd.createChar(2, bukva_i);
  lcd.createChar(3, bukva_g);
  lcd.createChar(4, bukva_m);
  lcd.createChar(5, bukva_n);

  lcd.setCursor(2, 0);
  lcd.print("    Po");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.print("    ");

  lcd.setCursor(6, 1);
  if (time_ignition < 10)
  {
    lcd.print(" ");
    lcd.print(time_ignition);
  }
  else
    lcd.print(time_ignition);
  lcd.print(" ");
  lcd.write((byte)4);
  lcd.write((byte)2);
  lcd.write((byte)5);
  lcd.print("     ");
}

///////////////////////////////////////////////////////

if (A == 14 || A == 34)
{
  lcd.createChar(0, bukva_m);
  lcd.createChar(1, bukva_p);
  lcd.createChar(2, bukva_k);
  lcd.createChar(3, gradus);

  lcd.setCursor(2, 0);
  lcd.print("  Te");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)0);
  lcd.print("a");
  lcd.write((byte)2);
  lcd.print("c   ");

  lcd.setCursor(6, 1);
  if (temp_max < 10)
  {
    lcd.print(" ");
    lcd.print(temp_max);
  }
  else
    lcd.print(temp_max);
  lcd.write((byte)3);
  lcd.print("C      ");
}

//////////////////////////////////////////

if (A == 15 || A == 35)
{
  lcd.createChar(0, bukva_m);
  lcd.createChar(1, bukva_p);
  lcd.createChar(2, bukva_t);
  lcd.createChar(3, bukva_v);
  lcd.createChar(4, bukva_k);
  lcd.createChar(5, gradus);

  lcd.setCursor(2, 0);
  lcd.print("Te");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_yc");
  lcd.write((byte)2);
  lcd.print("a");
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.print("a  ");

  lcd.setCursor(6, 1);
  if (temp_control < 10)
  {
    lcd.print(" ");
    lcd.print(temp_control);
  }
  else
    lcd.print(temp_control);
  lcd.write((byte)5);
  lcd.print("C      ");
}

///////////////////////////////////////////////////

if (A == 16 || A == 36)
{
  lcd.createChar(0, bukva_G);
  lcd.createChar(1, bukva_i);
  lcd.createChar(2, bukva_t);
  lcd.createChar(3, bukva_ze);
  lcd.createChar(4, gradus);

  lcd.setCursor(2, 0);
  lcd.print("  ");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("c");
  lcd.write((byte)2);
  lcd.print("epe");
  lcd.write((byte)3);
  lcd.write((byte)1);
  lcd.print("c  ");

  lcd.setCursor(6, 1);
  if (temp_gist < 10)
  {
    lcd.print(" ");
    lcd.print(temp_gist);
  }
  else
    lcd.print(temp_gist);
  lcd.write((byte)4);
  lcd.print("C     ");
}

//////////////////////////////////////////////

if (A == 17 || A == 37)
{
  lcd.createChar(0, bukva_iii);
  lcd.createChar(1, bukva_z);
  lcd.createChar(2, bukva_i);
  lcd.createChar(3, bukva_g);
  lcd.createChar(4, bukva_m);
  lcd.createChar(5, bukva_n);

  lcd.setCursor(2, 0);
  lcd.print("  B");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.print("a");
  lcd.write((byte)5);
  lcd.write((byte)2);
  lcd.print("e   ");

  lcd.setCursor(6, 1);
  if (time_reburn < 10)
  {
    lcd.print(" ");
    lcd.print(time_reburn);
  }
  else
    lcd.print(time_reburn);
  lcd.print(" ");
  lcd.write((byte)4);
  lcd.write((byte)2);
  lcd.write((byte)5);
  lcd.print("     ");
}

//////////////////////////////////////////////

if (A == 18 || A == 38)
{
  lcd.createChar(0, bukva_m);
  lcd.createChar(1, bukva_p);
  lcd.createChar(2, bukva_z);
  lcd.createChar(3, bukva_ze);
  lcd.createChar(4, bukva_i);
  lcd.createChar(5, bukva_g);
  lcd.createChar(6, gradus);

  lcd.setCursor(2, 0);
  lcd.print("Te");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_po");
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.print("a  ");

  lcd.setCursor(6, 1);
  lcd.print(temp_flame_control);

  lcd.write((byte)6);
  lcd.print("C     ");
}

//////////////////////////////////////////////////////////////

if (A == 19 || A == 39)
{
  lcd.createChar(0, bukva_m);
  lcd.createChar(1, bukva_p);
  lcd.createChar(2, bukva_k);
  lcd.createChar(3, bukva_t);
  lcd.createChar(4, bukva_l);
  lcd.createChar(5, gradus);

  lcd.setCursor(2, 0);
  lcd.print(" Te");
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.print("_");
  lcd.write((byte)2);
  lcd.print("o");
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.print("a   ");

  lcd.setCursor(6, 1);
  lcd.print(temp_flame_max);

  lcd.write((byte)5);
  lcd.print("C     ");
}

//////////////////////////////////////////////////////////////////
/////////  аварийные ситуации  ///////////////////////////////////
//////////////////////////////////////////////////////////////////

////////////////  перегрев воды  //////////////////////////////

if (A == 100)
{
  lcd.createChar(0, bukva_P);
  lcd.createChar(1, bukva_III);
  lcd.createChar(2, bukva_SH);
  lcd.createChar(3, bukva_Y);

  lcd.setCursor(3, 0);
  lcd.write((byte)0);
  lcd.print("PEB");
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.print("EHA");

  lcd.setCursor(2, 1);
  lcd.print("TEM");
  lcd.write((byte)0);
  lcd.print("EPAT");
  lcd.write((byte)3);
  lcd.print("PA!");
}

///////////////  датчик в котле  ///////////////////////////////

if (A == 101)
{
  lcd.createChar(0, bukva_D);
  lcd.createChar(1, bukva_CH);
  lcd.createChar(2, bukva_I);
  lcd.createChar(3, bukva_G);

  lcd.setCursor(5, 0);
  lcd.write((byte)0);
  lcd.print("AT");
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.print("K");

  lcd.setCursor(5, 1);
  lcd.print("HA");
  lcd.write((byte)3);
  lcd.print("PEBA");
}

///////////////  датчик обратки  ////////////////////////////////

if (A == 102)
{
  lcd.createChar(0, bukva_D);
  lcd.createChar(1, bukva_CH);
  lcd.createChar(2, bukva_I);
  lcd.createChar(3, bukva_B);

  lcd.setCursor(5, 0);
  lcd.write((byte)0);
  lcd.print("AT");
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.print("K");

  lcd.setCursor(5, 1);
  lcd.print("O");
  lcd.write((byte)3);
  lcd.print("PATK");
  lcd.write((byte)2);
}

///////////////  перегрев котла  ////////////////////////////////

if (A == 103)
{
  lcd.createChar(0, bukva_P);
  lcd.createChar(1, bukva_G);
  lcd.createChar(2, bukva_L);

  lcd.setCursor(4, 0);
  lcd.write((byte)0);
  lcd.print("EPE");
  lcd.write((byte)1);
  lcd.print("PEB");

  lcd.setCursor(5, 1);
  lcd.print("KOT");
  lcd.write((byte)2);
  lcd.print("A");
}

}




