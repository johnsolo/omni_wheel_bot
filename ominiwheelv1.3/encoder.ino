void encoder(int c, int d, int a, int b, int step_in)
{
  digitalWrite(c, a);
  digitalWrite(d, b);
  static int K, N;
  while (steps != step_in)
  {
    K = digitalRead(encoder1);
    if (K != N)
    {
      steps++;
    }
    N = K;
  }
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  Serial.print("steps=");
  Serial.println(steps);
  steps = 0;
}
