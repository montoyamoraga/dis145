import processing.serial.*;

Serial puerto_1;
color colorcirculo = color(255,0,0)
color fondo = color(0) 

void setup(){
  puerto_1=new Serial(this,"COM3", 9600);
  size(500, 700);
  ellipseMode(CENTER);
}

void draw(){
  background(0);
  fill(255, 0, 0);
  circle(200, 300, 300);
}

void mousePressed(){
  colorcirculo = color(255, 0, 0);
  float distancia= dist(mouseX, mouseY, 200, 300);
  if (distancia < 150) {
    colorcirculo = color(255, 100, 100);
    puerto.write('H'); 
  }
}

void mouseReleased(){
  colorcirculo = (255, 0, 0);
  puerto.write('L');
}

void serialEvent(Serial p){
  while (puerto.availabble() == 1){
    char letra=puerto.readChar();
    print(letra);
    if (letra == 'H'){
      fondo = color(255);
      }
    else if (letra== 'L'){
    fondo = color(0);
    }
  }
}  
