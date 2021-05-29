#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <GL/glut.h>  // GLUT

using namespace std;

int  figura;

void DDA(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	
	//PLANO CARTESIANO
	glLineWidth(12.0);
	glColor3f(0.0f, 0.0f, 0.0f);//BLACK
	glBegin(GL_LINES);
		glVertex2d(-30,0); 
		glVertex2d(30,0);
		glVertex2d(0,30);
		glVertex2d(0,-30);
	glEnd();
	
	//LINEAS CUADRICULADAS
	glLineWidth(2.0);
	glColor3f(0.1f, 0.1f, 0.1f);//DARK GREY
	
	glBegin(GL_LINES);
		for(int j=31;j>-30;j--){ //LINEAS HORIZONTALES
			glVertex2f(-30,j+0.5);
			glVertex2f(30,j+0.5);
		}
		for(int j=31;j>-30;j--){ //LINEAS VERTICALES
			glVertex2f(j+0.5, -30);
			glVertex2f(j+0.5, 30);
		}
	glEnd();
	
	glPointSize(14);
	glBegin(GL_POINTS);
		glColor3f(1.0f, 5.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f); //ORIGEN
		glColor3f(0.0f, 0.5f, 0.5f);//COLOR BLUE-GREEN
		//ALGORITMO DDA
		double x_1, y_1, x_2, y_2,steps, dy, dx, x_3;
		double xinc,yinc;
		
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA X1 DEL TRIANGULO EQUILATERO ==>"; cin >> x_1;
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA Y1 DEL TRIANGULO EQUILATERO ==>"; cin >> y_1;
		cout <<"INGRESE LA ALTURA X2 DEL TRIANGULO EQUILATERO ==> "; cin >> x_2;
		cout <<"INGRESE LA ALTURA Y2 DEL TRIANGULO EQUILATERO ==>"; cin >> y_2;
		cout <<"INGRESE LA BASE DEL TRIANGULO EQUILATERO ==>"; cin >> x_3;
		
		if(x_1<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else if(y_1<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else if(x_2<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else if(y_2<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else{
			
			dx=(x_2 - x_1);
			dy=(y_2 - y_1);
		
			cout << "DX: " << dx << "\n";
			cout << "DY: " << dy << "\n";
			
			if(dx>dy){
				steps=dx;
				cout << "STEPS: " << steps << "\n";
			}
			else{
				steps=dy;
				cout << "STEPS: " << steps << "\n";
			}
			
			yinc=(dy/steps);
			xinc=(dx/steps);
			
			for(int k=0;k<steps+1;k++){ 
				glVertex2d(round(x_1),round(y_1));
				x_1= x_1 + xinc;
				y_1= y_1 + yinc;
				cout <<"=>(" << x_1 <<","<< y_1 <<")" "\n";
			}
				
			for(int k=0;k<steps+1;k++){ 
				glVertex2d(round(x_2),round(y_1-1));
				x_2= x_2 + xinc;
				y_1= y_1 - yinc;
				cout <<"=>(" << x_2 <<","<< y_1 <<")" "\n";
			}
			
			x_1=1;
			y_1=2;
				
			for(x_1;x_1<=x_3;x_1++){
				glVertex2d(round(x_1),round(y_1));
				cout <<"===>(" << x_1 <<","<< y_1 <<")" "\n";
			}
		}
			
	glEnd();
	
	glFlush();
}

void Bresenham(){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	
	//PLANO CARTESIANO
	glLineWidth(12.0);
	glColor3f(0.0f, 0.0f, 0.0f);//BLACK
	glBegin(GL_LINES);
		glVertex2d(-30,0); 
		glVertex2d(30,0);
		glVertex2d(0,30);
		glVertex2d(0,-30);
	glEnd();
	
	//LINEAS CUADRICULADAS
	glLineWidth(2.0);
	glColor3f(0.1f, 0.1f, 0.1f);//DARK GREY
	
	glBegin(GL_LINES);
		for(int j=31;j>-30;j--){ //LINEAS HORIZONTALES
			glVertex2f(-30,j+0.5);
			glVertex2f(30,j+0.5);
		}
		for(int j=31;j>-30;j--){ //LINEAS VERTICALES
			glVertex2f(j+0.5, -30);
			glVertex2f(j+0.5, 30);
		}
	glEnd();
	
	glPointSize(14);
	glBegin(GL_POINTS);
		glColor3f(1.0f, 5.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f); //ORIGEN
		glColor3f(0.0f, 0.5f, 0.5f);//BLUE-GREEN
		
		//ALGORITMO BRESENHAM
		int x_1, y_1, x_2, y_2, x_3, dy, dx, p;
		
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA X1 DEL TRIANGULO EQUILATERO ==>"; cin >> x_1;
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA Y1 DEL TRIANGULO EQUILATERO ==>"; cin >> y_1;
		cout <<"INGRESE LA ALTURA X2 DEL TRIANGULO EQUILATERO ==> "; cin >> x_2;
		cout <<"INGRESE LA ALTURA Y2 DEL TRIANGULO EQUILATERO ==>"; cin >> y_2;
		cout <<"INGRESE LA BASE DEL TRIANGULO EQUILATERO ==>"; cin >> x_3;
		
		dx= (x_2 - x_1);
		dy= (y_2 - y_1);
		
		p= (2*dy-dx);
		
		if(x_1<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else if(y_1<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else if(x_2<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else if(y_2<0){
			cout << "NO SE ACEPTAN NUMEROS NEGATIVOS\n";
			glutHideWindow();
		}else{
			
			for(int k=0;k<p+1;k++){ 
				glVertex2d(round(x_1),round(y_1));
				x_1++;
				y_1++;
				cout <<"=>(" << x_1 <<","<< y_1 <<")" "\n";
			}
			
			for(int k=0;k<p+1;k++){ 
				glVertex2d(round(x_2),round(y_1-1));
				x_2++;
				y_1--;
				cout <<"=>(" << x_2 <<","<< y_1 <<")" "\n";
			}
			
			x_1=1;
			y_1=2;
				
			for(x_1;x_1<=x_3;x_1++){
				glVertex2d(round(x_1),round(y_1));
				cout <<"===>(" << x_1 <<","<< y_1 <<")" "\n";
			}
		}
		
	glEnd();
	
	glFlush();
}


void Init(){
	glClearColor(1,1,1,0); //COLOR DE PANTALLA EN BLANCO
}

void reshape(int width, int height){
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30,30,-30,30,-1,1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char *argv[]){
	cout <<"INGRESE CON QUE METODO DESEA DIBUJAR EL TRIANGULO EQUILATERO \n ===>DDA=1 \n ===>BRESENHAM=2 \n"; cin>> figura;
	if (figura==1){
		glutInit(& argc, argv); //INICIALIZACION DE LA BIBLIOTECA GLUT
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //MODO DE DISPLAY CON EL QUE SE CREA LA VENTANA
		glutInitWindowSize(800,800); //TAMANIO DE LA VENTANA
		glutInitWindowPosition(0,0); //POSICION INICIAL
		glutCreateWindow("Algoritmo DDA"); //TITULO A LA VENTANA
		Init(); //SE EJECUTA LA INICIALIZACION
		glutDisplayFunc(DDA); //ASIGNA LA IMAGEN A LA VENTANA DE VISUALIZACION 
		//ESPECIFICA QUE VA A CONTENER LA VENTANA DE VISUALIZACION Y ENVIA LOS GRAFICOS A LA VENTANA DE VISUALIZACION
		glutReshapeFunc(reshape); //CAMBIO DE TAMANIO A LA VENTANA ACTUAL 
		glutMainLoop();// SE MUESTRA EL CONTENIDO
	}else if (figura==2){
		glutInit(& argc, argv); //INICIALIZACION DE LA BIBLIOTECA GLUT
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //MODO DE DISPLAY CON EL QUE SE CREA LA VENTANA
		glutInitWindowSize(800,800); //TAMANIO DE LA VENTANA
		glutInitWindowPosition(0,0); //POSICION INICIAL
		glutCreateWindow("Algoritmo Bresenham"); //TITULO A LA VENTANA
		Init(); //SE EJECUTA LA INICIALIZACION
		glutDisplayFunc(Bresenham); //ASIGNA LA IMAGEN A LA VENTANA DE VISUALIZACION 
		//ESPECIFICA QUE VA A CONTENER LA VENTANA DE VISUALIZACION Y ENVIA LOS GRAFICOS A LA VENTANA DE VISUALIZACION
		glutReshapeFunc(reshape); //CAMBIO DE TAMANIO A LA VENTANA ACTUAL 
		glutMainLoop();// SE MUESTRA EL CONTENIDO
	}
	return 0;
}