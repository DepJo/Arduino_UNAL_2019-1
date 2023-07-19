#include "DHT.h"
#define DHT11_PIN A0
#define DHTTYPE DHT11
DHT dht (DHT11_PIN, DHTTYPE);
int pul=12, tiempoantirrebote=10, cuenta=0, estado, estadoanterior;
int inp1=2, inp2=3, inp3=4, inp4=5, led=13;
int inp11=8, inp22=9, inp33=10, inp44=11;

int Temp;
int Hum;
int luz;
bool antirrebote(int pin){
  int cont=0;
  bool Estado;
  bool estadoAnterior;
  
  do{
    Estado= digitalRead(pin);
    if (Estado != estadoAnterior){
      cont=0;
      estadoAnterior = Estado;
    }
    else{
      cont+=1;
    }
    delay(1);
  }while (cont < tiempoantirrebote);
  return estado;
}

void temperatura(){
  Temp = dht.readTemperature();
  
  int dec= Temp/10;
  int uni=Temp-(dec*10);
  Serial.println(Temp);
  Serial.println(dec);
  Serial.println(uni);
  delay(1000);
  switch (uni){
    case 0: 
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 1:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 2:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 3:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 4:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 5:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 6:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 7:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2,HIGH);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 8:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,HIGH);//4
    break;
    case 9:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,HIGH);//4
    break;
  }
  switch(dec){
    case 0: 
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 1:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 2:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 3:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 4:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 5:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 6:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 7:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22,HIGH);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 8:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,HIGH);//4
    break;
    case 9:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,HIGH);//4
    break;
  }
  
}
void humedad (){
  Hum = dht.readHumidity();
  int dece= Hum/10;
  int unid= Hum-(dece*10);
  Serial.println(Hum);
  Serial.println(dece);
  Serial.println(unid);
  switch (unid){
    case 0: 
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 1:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 2:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 3:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 4:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 5:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 6:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 7:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2,HIGH);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 8:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,HIGH);//4
    break;
    case 9:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,HIGH);//4
    break;
  }
  switch(dece){
    case 0: 
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 1:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 2:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 3:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 4:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 5:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 6:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 7:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22,HIGH);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 8:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,HIGH);//4
    break;
    case 9:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,HIGH);//4
    break;
  }
}

void intensidad(int pin){
  luz = analogRead(pin);
  int inten=map(luz,1024,0,0,99);
  int decena= inten/10;
  int unidad= inten-(decena*10);
  Serial.println(inten);
  Serial.println(decena);
  Serial.println(unidad);
  switch (unidad){
    case 0: 
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 1:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 2:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 3:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 4:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 5:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 6:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, HIGH);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 7:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2,HIGH);//2
    digitalWrite(inp3,HIGH);//3
    digitalWrite(inp4,LOW);//4
    break;
    case 8:
    digitalWrite(inp1, LOW);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,HIGH);//4
    break;
    case 9:
    digitalWrite(inp1, HIGH);//1
    digitalWrite(inp2, LOW);//2
    digitalWrite(inp3,LOW);//3
    digitalWrite(inp4,HIGH);//4
    break;
    
  }
  switch(decena){
    case 0: 
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 1:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 2:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 3:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 4:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 5:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 6:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, HIGH);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 7:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22,HIGH);//2
    digitalWrite(inp33,HIGH);//3
    digitalWrite(inp44,LOW);//4
    break;
    case 8:
    digitalWrite(inp11, LOW);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,HIGH);//4
    break;
    case 9:
    digitalWrite(inp11, HIGH);//1
    digitalWrite(inp22, LOW);//2
    digitalWrite(inp33,LOW);//3
    digitalWrite(inp44,HIGH);//4
    break;
  }
}
void setup() {
  Serial.begin (9600);
  pinMode(pul,INPUT);
  dht.begin();
  pinMode(led, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(inp3, OUTPUT);
  pinMode(inp4, OUTPUT);
  pinMode(inp11, OUTPUT);
  pinMode(inp22, OUTPUT);
  pinMode(inp33, OUTPUT);
  pinMode(inp44, OUTPUT);

}

void loop() {
  estado = digitalRead(pul);
  if (estado !=estadoanterior){
    if (antirrebote(pul)){
      cuenta++;
      if( cuenta <4){
        Serial.println(cuenta);
        switch (cuenta){
          case 1: 
          digitalWrite(led,HIGH);
          delay(500);
          digitalWrite(led,LOW);
          temperatura();
          break;
          case 2: 
          digitalWrite(led,HIGH);
          delay(500);
          digitalWrite(led,LOW);
          humedad();
          break;
          case 3: 
          digitalWrite(led,HIGH);
          delay(500);
          digitalWrite(led,LOW);
          intensidad(A1);
          break;
        }
      }else{
        cuenta=0;
      }
    }
  }
  estadoanterior=estado;

}
