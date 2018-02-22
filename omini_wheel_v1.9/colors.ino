void red_color()
{
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
}
void blue_color()
{
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
}
void green_color()
{
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
}
void yellow_color()
{
        analogWrite(green, 150);
        analogWrite(blue, 0);
        analogWrite(red, 255);
}
