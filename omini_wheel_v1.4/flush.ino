/////////////////////////////////////////////////FLUSH ANY DATA IN SERIAL BUFFER BEFORE READING//////////////////////////////////////////////////////////////////
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
