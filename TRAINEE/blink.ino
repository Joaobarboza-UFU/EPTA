int LED_BUILTIN = 2; //Led presente no modulo de desenvolvimento do
void setup()
{
 pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
 digitalWrite(LED_BUILTIN, HIGH); // Liga led
 delay(500); // Permanece 0,5 S ligado
 digitalWrite(LED_BUILTIN, LOW); // Desliga led
 delay(500); // Permanece 0,5 S desligado
}
