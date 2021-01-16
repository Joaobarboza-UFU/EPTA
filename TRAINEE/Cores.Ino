TaskHandle_t Task1;
TaskHandle_t Task2;


const int Red = 2;
const int Green = 4;
boolean flag = true;
int counter = 0;

void setup() {
  Serial.begin(115200); 
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  xTaskCreatePinnedToCore(Task1code,"Task1",10000,NULL,1,&Task1,0);                      
  delay(1000); 
  xTaskCreatePinnedToCore(Task2code,"Task2",10000,NULL,1,&Task2,1);         
  delay(1000); 
}

void Task1code( void * pvParameters ){

  for(;;){
    if(!flag){
      digitalWrite(Red, HIGH);
      delay(1000);
      digitalWrite(Green, LOW);
      delay(1000);
      flag = true;}
    else{
      digitalWrite(Red, HIGH);
      delay(1000);
      digitalWrite(Green, LOW);
      delay(1000);
      flag = false;
    }}
}

void Task2code( void * pvParameters ){
  for(;;){
    Serial.println(counter);
    counter = counter + 1;
    delay(1000);
    }
}

void loop() {
  
}
