#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define pinDHT 18
#define tipoDHT DHT22
#define pinLED 2
#define pinLed2 4
#define pinLed3 15

int intensidade = 0;
int intensidade2 = 0;
int intensidade3 = 0;

bool estadoLed1 = true;
bool estadoLed2 = false;
bool estadoLed3 = false;
bool cicloCompleto = false;

DHT medidorzinho(pinDHT, tipoDHT);

LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned long tempoAnterior = 0;
unsigned long intervaloV = 100;

void setup()
{
  float tempoC = medidorzinho.readTemperature();
  float tempoF = medidorzinho.readTemperature(true);
  float umidade = medidorzinho.readHumidity();

  pinMode(pinLED, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);

  Serial.begin(115200);
  medidorzinho.begin();
  Serial.println("Teste de DHT22");

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Temp em c:");

  lcd.setCursor(0, 1);
  lcd.print("Temp em f:");

  lcd.setCursor(0, 2);
  lcd.print("Umidade em c:");
}

void loop()
{
  float tempoC = medidorzinho.readTemperature();
  float tempoF = medidorzinho.readTemperature(true);
  float umidade = medidorzinho.readHumidity();

  unsigned long tempoAtual = millis();
  
  //ex (aula 09/10)
  // if (tempoAtual - tempoAnterior >= intervalo)
  // {
    //  tempoAnterior = tempoAtual;
    
    //   lcd.setCursor(11, 0);
    //   lcd.print(tempoC);
    
    //   lcd.setCursor(11, 1);
    //   lcd.print(tempoF);
    
    //   lcd.setCursor(13, 2);
    //   lcd.print(umidade);
    // }
    
    //   if (intensidade == 0){
      //   intensidade += 5;
      //   }
      
      //   if (intensidade > 255){
        //     intensidade -= 5;
        // }
        

// ex 1 (aula 16/10)
// if (intensidade >= 255 && !cicloCompleto)
// {
//   estadoLed2 = true;
// }

  // if (intensidade2 >= 255 && !cicloCompleto)
  // {
  //   estadoLed3 = true;
  // }

  // if (intensidade3 >= 255)
  // {
  //   cicloCompleto = true;
  //   estadoLed3 = false;
  // }

  // if (intensidade3 <= 0 && cicloCompleto)
  // {
  //   estadoLed2 = false;
  // }

  // if (intensidade2 <= 0 && cicloCompleto)
  // {
  //   estadoLed1 = false;
  // }

  // if (intensidade <= 0)
  // {
  //   estadoLed1 = true;
  //   cicloCompleto = false;
  // }

  // if (tempoAtual - tempoAnterior >= intervaloV)
  // {
  //   tempoAnterior = tempoAtual;

  //   if (estadoLed1 == true && intensidade < 255)
  //   {
  //     intensidade += 5;
  //   }
  //   else if (estadoLed1 == false && intensidade > 0)
  //   {
  //     intensidade -= 5;
  //   }

  //   if (estadoLed2 == true && intensidade2 < 255)
  //   {
  //     intensidade2 += 5;
  //   }
  //   else if (estadoLed2 == false && intensidade2 > 0)
  //   {
  //     intensidade2 -= 5;
  //   }

  //   if (estadoLed3 == true && intensidade3 < 255)
  //   {
  //     intensidade3 += 5;
  //   }
  //   else if (estadoLed3 == false && intensidade3 > 0)
  //   {
  //     intensidade3 -= 5;
  //   }

  //   Serial.println(intensidade);
  //   Serial.println(intensidade2);
  //   Serial.println(intensidade3);

  //   analogWrite(pinLed1, intensidade);
  //   analogWrite(pinLed2, intensidade2);
  //   analogWrite(pinLed3, intensidade3);
  // }

  // ex2

  // if (tempoC >= 15)
  // {
  //   digitalWrite(pinLED, HIGH);
  // }
  // else
  // {
  //   digitalWrite (pinLED, LOW);
  // }
  
  // if (umidade >= 57)
  // {
  //   digitalWrite(pinLed2, HIGH);
    
  // }
  // else
  // {
  //   digitalWrite(pinLed2, LOW);
  // }

  //etapa 2 
if ( umidade >= 58 && intensidade < 255)
    {
      intensidade += 5;
      digitalWrite (pinLED, HIGH);
    }
    else if (umidade <= 58 && intensidade > 0)
    {
      intensidade3 -= 5;
      digitalWrite (pinLED, LOW);
    }
  

  // Serial.println(tempoC);
  Serial.println(umidade);
}