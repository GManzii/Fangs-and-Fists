int azul = 5;
int verde = 4;
int amarelo = 2;
int vermelho = 7;

bool estadoAzul = false;
bool estadoVerde = false;
bool estadoAmarelo = false;
bool estadoVermelho = false;

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {

  pinMode(azul, INPUT_PULLUP);
  pinMode(verde, INPUT_PULLUP);
  pinMode(amarelo, INPUT_PULLUP);
  pinMode(vermelho, INPUT_PULLUP);

  Serial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init();

}

void loop() {

  // 🔵 AZUL
  if (digitalRead(azul) == LOW) {

    if (!estadoAzul) {
      Serial.println("AZUL");
      estadoAzul = true;
    }

  } else {
    estadoAzul = false;
  }

  // 🟢 VERDE
  if (digitalRead(verde) == LOW) {

    if (!estadoVerde) {
      Serial.println("VERDE");
      estadoVerde = true;
    }

  } else {
    estadoVerde = false;
  }

  // 🟡 AMARELO
  if (digitalRead(amarelo) == LOW) {

    if (!estadoAmarelo) {
      Serial.println("AMARELO");
      estadoAmarelo = true;
    }

  } else {
    estadoAmarelo = false;
  }

  // 🔴 VERMELHO
  if (digitalRead(vermelho) == LOW) {

    if (!estadoVermelho) {
      Serial.println("VERMELHO");
      estadoVermelho = true;
    }

  } else {
    estadoVermelho = false;
  }

  //NFC
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) uid += " ";
  }

  uid.toUpperCase();

  Serial.println(uid);
}
