#include <MatrizLed.h>
#include <stdlib.h>

MatrizLed pantalla;

int body[200][2];
int n = 1;
int tamano = 3;
int x = 0, y = 2;
int dir = 3;
int xfood = 6, yfood = 6;
int puntos = 0;

#define S1 8
#define S2 9

#define btn1 2
#define btn2 3
#define btn3 4
#define btn4 5

#define start 6

void setup() {
  pinMode (S1, INPUT);
  pinMode (S2, INPUT);
  
  pinMode (btn1, INPUT);
  pinMode (btn2, INPUT);
  pinMode (btn3, INPUT);
  pinMode (btn4, INPUT);

  pinMode (start, INPUT);
  
  pantalla.begin(11, 13, 12, 2);
  pantalla.rotar(true);
}


void guardarPos(){
  body[n][0] = x;
  body[n][1] = y;
  n++;
  if(n == tamano){
    n = 1;
  }
}

void dibujarCuerpo(){
  for(int i = 1; i < tamano; i ++){
    if(body[i][0] > 7){
      pantalla.setLed(1, body[i][1],-8+body[i][0], true);
    }else{
      pantalla.setLed(0, body[i][1],body[i][0], true);
    }
  }
}

void borrarCuerpo(){
  if(body[n][0] > 7){
    pantalla.setLed(1, body[n][1],-8+body[n][0], false);
  }else{
    pantalla.setLed(0, body[n][1],body[n][0], false);
  }
}

void cambiarDireccion(){
    if(digitalRead(btn1) == LOW){
      if(dir != 2){
        dir = 1;
      }
    }else if(digitalRead(btn3) == LOW){
      if(dir != 1){
        dir = 2;
      }
    }else if(digitalRead(btn2) == LOW){
      if(dir != 4){
        dir = 3; 
      }
    }else if(digitalRead(btn4) == LOW){
      if(dir != 3){
        dir = 4;
      }
    }
}

void food(){
  if(x == xfood && y == yfood){
    xfood = (rand()%15);
    yfood = (rand()%8);

    tamano++;
    puntos++;
    
    if(xfood > 7){
      pantalla.setLed(1, yfood,-8+xfood, true);
    }else{
      pantalla.setLed(0, yfood,xfood, true);
    }
  }
}

void puntos(){
  
}

bool gameOver(){
  if( y == -1 || y == 8 || x == -1 || x == 16 ){
    return true;
  }
  for(int j = tamano - 1; j > 0; j--){
    if(body[j][0] == x && body[j][1] == y){
      return true;
    }
  }

  return false;
}

void loop() {
  

  if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
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
      pantalla.setLed(1, 7, -181+i, true);
      pantalla.setLed(1, 7, -183+i, true);
      pantalla.setLed(1, 6, -182+i, true);
      pantalla.setLed(1, 5, -181+i, true);
      pantalla.setLed(1, 5, -183+i, true);
      if(digitalRead(S1) == LOW && digitalRead(S2) == HIGH || digitalRead(start) == LOW){
        pantalla.borrar();
        break;
      }
      delay(100);
    }
  }
  
  pantalla.setLed(0, yfood,xfood, true);
  
  while(digitalRead(start) == LOW && !gameOver()){
    borrarCuerpo();
    guardarPos();
    dibujarCuerpo();
    food();
    cambiarDireccion();
    cambiarDireccion();
    if(dir == 1) y--;
    if(dir == 2) y++;
    if(dir == 3) x++;
    if(dir == 4) x--;
    delay(500);
  }
    
  while(digitalRead(S1) == LOW && digitalRead(S2) == HIGH){
    pantalla.borrar();
    
    //* Primera Pantalla
    pantalla.setLed(1, 7, 5, true);
    pantalla.setLed(1, 7, 7, true);
    pantalla.setLed(1, 6, 6, true);
    pantalla.setLed(1, 5, 5, true);
    pantalla.setLed(1, 5, 7, true);
    
    delay(500);
    
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    
    pantalla.escribirCaracter('T' , 0);
    delay(500);

    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    
    pantalla.borrar();
    pantalla.escribirCaracter('P' , 0);
    delay(500);

    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    
    pantalla.borrar();
    pantalla.escribirCaracter('1' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    
    //- Primera Pantalla
    pantalla.setLed(1, 4, 2, true);
    pantalla.setLed(1, 4, 3, true);
    pantalla.setLed(1, 4, 4, true);
    pantalla.setLed(1, 4, 5, true);
    pantalla.setLed(1, 3, 2, true);
    pantalla.setLed(1, 3, 3, true);
    pantalla.setLed(1, 3, 4, true);
    pantalla.setLed(1, 3, 5, true);

    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('G' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('R' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('U' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('P' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('O' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('1' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('1' , 0);

    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    
    //- Primera Pantalla
    pantalla.setLed(1, 4, 2, true);
    pantalla.setLed(1, 4, 3, true);
    pantalla.setLed(1, 4, 4, true);
    pantalla.setLed(1, 4, 5, true);
    pantalla.setLed(1, 3, 2, true);
    pantalla.setLed(1, 3, 3, true);
    pantalla.setLed(1, 3, 4, true);
    pantalla.setLed(1, 3, 5, true);

    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('S' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('E' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('C' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('C' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('I' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('O' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('N' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    pantalla.escribirCaracter('A' , 0);
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
    pantalla.borrar();
    //* Primera Pantalla
    pantalla.setLed(1, 7, 5, true);
    pantalla.setLed(1, 7, 7, true);
    pantalla.setLed(1, 6, 6, true);
    pantalla.setLed(1, 5, 5, true);
    pantalla.setLed(1, 5, 7, true);
    
    delay(500);
    if(digitalRead(S1) == HIGH && digitalRead(S2) == HIGH){
      pantalla.borrar();
      break;
    }
  }
  
  
  
}
