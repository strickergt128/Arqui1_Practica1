#include <MatrizLed.h>

MatrizLed pantalla;

void setup() {
  pantalla.begin(11, 13, 12, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
  pantalla.rotar(true);
}

void loop() {
  pantalla.borrar();
  for(int i=0; i<200; i++){
    pantalla.borrar();
    //* Primera Pantalla
    pantalla.setLed(0, 7, 0+i, true);
    pantalla.setLed(0, 7, 2+i, true);
    pantalla.setLed(0, 6, 1+i, true);
    pantalla.setLed(0, 5, 0+i, true);
    pantalla.setLed(0, 5, 2+i, true);
    
    pantalla.escribirFrase("TP1", 16-i);

    //* Segunda Pantalla
    pantalla.setLed(1, 7, -6+i, true);
    pantalla.setLed(1, 7, -8+i, true);
    pantalla.setLed(1, 6, -7+i, true);
    pantalla.setLed(1, 5, -6+i, true);
    pantalla.setLed(1, 5, -8+i, true);

    //- Primera Pantalla
    pantalla.setLed(0, 4, -26+i, true);
    pantalla.setLed(0, 4, -27+i, true);
    pantalla.setLed(0, 4, -28+i, true);
    pantalla.setLed(0, 4, -29+i, true);
    pantalla.setLed(0, 3, -26+i, true);
    pantalla.setLed(0, 3, -27+i, true);
    pantalla.setLed(0, 3, -28+i, true);
    pantalla.setLed(0, 3, -29+i, true);

    //- Segunda Pantalla
    pantalla.setLed(1, 4, -34+i, true);
    pantalla.setLed(1, 4, -35+i, true);
    pantalla.setLed(1, 4, -36+i, true);
    pantalla.setLed(1, 4, -37+i, true);
    pantalla.setLed(1, 3, -34+i, true);
    pantalla.setLed(1, 3, -35+i, true);
    pantalla.setLed(1, 3, -36+i, true);
    pantalla.setLed(1, 3, -37+i, true);

    pantalla.escribirFrase("GRUPO 11", 46-i);

    //- Primera Pantalla
    pantalla.setLed(0, 4, -96+i, true);
    pantalla.setLed(0, 4, -97+i, true);
    pantalla.setLed(0, 4, -98+i, true);
    pantalla.setLed(0, 4, -99+i, true);
    pantalla.setLed(0, 3, -96+i, true);
    pantalla.setLed(0, 3, -97+i, true);
    pantalla.setLed(0, 3, -98+i, true);
    pantalla.setLed(0, 3, -99+i, true);

    //- Segunda Pantalla
    pantalla.setLed(1, 4, -104+i, true);
    pantalla.setLed(1, 4, -105+i, true);
    pantalla.setLed(1, 4, -106+i, true);
    pantalla.setLed(1, 4, -107+i, true);
    pantalla.setLed(1, 3, -104+i, true);
    pantalla.setLed(1, 3, -105+i, true);
    pantalla.setLed(1, 3, -106+i, true);
    pantalla.setLed(1, 3, -107+i, true);

    pantalla.escribirFrase("SECCION A", 116-i);

    //* Primera Pantalla
    pantalla.setLed(0, 7, -173+i, true);
    pantalla.setLed(0, 7, -175+i, true);
    pantalla.setLed(0, 6, -174+i, true);
    pantalla.setLed(0, 5, -173+i, true);
    pantalla.setLed(0, 5, -175+i, true);

    //* Segunda Pantalla
    pantalla.setLed(1, 7, -179+i, true);
    pantalla.setLed(1, 7, -181+i, true);
    pantalla.setLed(1, 6, -180+i, true);
    pantalla.setLed(1, 5, -179+i, true);
    pantalla.setLed(1, 5, -181+i, true);
    
    delay(100);
  }
  /*for(int i=0; i<10; i++){
    pantalla.escribirFrase("TP1", i);
    pantalla.escribirFrase("GRUPO 11", i+1);
    pantalla.escribirFrase("SECCION A", i+2);
    delay(500);
  }
  for(int i=10; i<20; i++){
    pantalla.escribirFrase("GRUPO 11", i);
    delay(500);
  }*/
}
