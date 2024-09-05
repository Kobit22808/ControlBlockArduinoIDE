

///////////////////////////////////////////////////////

float getTemp1()
{
  byte data1[12];
  byte addr1[8];

  if ( !ds1.search(addr1))
  {
    ds1.reset_search();
    return -1000;
  }

  ds1.reset();
  ds1.select(addr1);
  ds1.write(0x44, 1);

  byte present1 = ds1.reset();
  ds1.select(addr1);
  ds1.write(0xBE);

  for (int i = 0; i < 9; i++)
  {
    data1[i] = ds1.read();
  }

  ds1.reset_search();

  byte MSB1 = data1[1];
  byte LSB1 = data1[0];

  float tempRead1 = ((MSB1 << 8) | LSB1);
  float TemperatureSum1 = tempRead1 / 16;

  return TemperatureSum1;
}

////////////////////////////////////////////////////////////////////

float getTemp2()
{
  byte data2[12];
  byte addr2[8];

  if ( !ds2.search(addr2))
  {
    ds2.reset_search();
    return -1000;
  }

  ds2.reset();
  ds2.select(addr2);
  ds2.write(0x44, 1);

  byte present2 = ds2.reset();
  ds2.select(addr2);
  ds2.write(0xBE);

  for (int i = 0; i < 9; i++)
  {
    data2[i] = ds2.read();
  }

  ds2.reset_search();

  byte MSB2 = data2[1];
  byte LSB2 = data2[0];

  float tempRead2 = ((MSB2 << 8) | LSB2);
  float TemperatureSum2 = tempRead2 / 16;

  return TemperatureSum2;
}

/////////////////////////////////////////////////////////////


float getTemp3()
{
  byte data3[12];
  byte addr3[8];

  if ( !ds3.search(addr3))
  {
    ds3.reset_search();
    return -1000;
  }

  ds3.reset();
  ds3.select(addr3);
  ds3.write(0x44, 1);

  byte present3 = ds3.reset();
  ds3.select(addr3);
  ds3.write(0xBE);

  for (int i = 0; i < 9; i++)
  {
    data3[i] = ds3.read();
  }

  ds3.reset_search();

  byte MSB3 = data3[1];
  byte LSB3 = data3[0];

  float tempRead3 = ((MSB3 << 8) | LSB3);
  float TemperatureSum3 = tempRead3 / 16;

  return TemperatureSum3;
}

////////////////////////////////////////////////////////
