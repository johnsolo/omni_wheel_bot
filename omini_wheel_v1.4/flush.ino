void serial_flush()
{
  while (Serial.available())
  {
    Serial.read();
    Serial.println("flushing");
  }
}
void out()
{
  Serial.println("out");
}
