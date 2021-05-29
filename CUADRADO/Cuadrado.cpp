#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <GL/glut.h>  // GLUT

using namespace std;

int figura;

void DDA(){
	
	//ESTABLECE EL COLOR DE LA VENTANA 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	
	//PLANO CARTESIANO
	glLineWidth(12.0); //ANCHURA DE LA LINEA
	glColor3f(0.0f, 0.0f, 0.0f);//COLOR DE LINEA (NEGRO)
	glBegin(GL_LINES); //FUNCION PARA GRAFICAR LINEAS
		glVertex2d(-30,0); //LINEA NEGRA DE PLANO (X)
		glVertex2d(30,0);
		glVertex2d(0,30); //LINEA NEGRA DE PLANO (Y)
		glVertex2d(0,-30);
	glEnd();
	
	//LINEAS CUADRICULADAS DEL PLANO
	glLineWidth(2.0); //ANCHURA DE LA LINEA 
	glColor3f(0.0f, 0.5f, 0.5f);//COLOR DE LINEA (BLUE-GREEN)
	glBegin(GL_LINES); //FUNCION PARA GRAFICAR LINEAS
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
		glColor3f(0.0f, 0.5f, 0.5f);
		glVertex3f(0.0f, 0.0f, 0.0f); //ORIGEN
		glColor3f(1.0f, 0.5f, 0.0f);//COLOR ORANGE
		//ALGORITMO DDA
		double x_1, y_1, x_2, y_2,steps, dy, dx,pendiente;
		double xinc,yinc;
		
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA X1 DEL CUADRADO ==>"; cin >> x_1;
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA Y1 DEL CUADRADO ==>"; cin >> y_1;
		cout <<"INGRESE LA ESQUINA SUPERIOR DERECHA X2 DEL CUADRADO ==> "; cin >> x_2;
		cout <<"INGRESE LA ESQUINA SUPERIOR DERECHA Y2 DEL CUADRADO ==>"; cin >> y_2;
		
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
			pendiente=(dy/dx);
			cout << "PENDIENTE: " << pendiente << "\n";
			if(pendiente==1){
				//Y1
				for(int k=0;k<steps+1;k++){ 
					glVertex2d(round(x_1),round(y_1));
					y_1= y_1 + yinc;
					cout <<"=>(" << x_1 <<","<< y_1 <<")" "\n";
				}
				//X2
				for(int k=0;k<steps+1;k++){ 
					glVertex2d(round(x_1),round(y_1-1));
					x_1= x_1 + xinc;
					cout <<"=>(" << x_1 <<","<< y_1 <<")" "\n";
				}
				//Y2
				for(int k=0;k<steps+1;k++){ 
					glVertex2d(round(x_2),round(y_1-1));
					y_1= y_1 - yinc;
					cout <<"=>(" << x_2 <<","<< y_1 <<")" "\n";
				}
				//HACIA ORIGEN X1
				for(int k=0;k<steps+1;k++){ 
					glVertex2d(round(x_2),round(y_1));
					x_2= x_2 - xinc;
					cout <<"=>(" << x_2 <<","<< y_1 <<")" "\n";
				}
			}else{
				cout << "LAS COORDENADAS INGRESADAS NO DAN UN ANGULO DE 45 GRADOS, NO ES POSIBLE HACER EL CUADRADO\n";
				glutHideWindow();
			}
		}

	glEnd();
	
	glFlush();//PROCESA SUBRUTINAS DE GLUT
	
}

void Bresenham(){

	//ESTABLECE EL COLOR DE LA VENTANA 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	
	//PLANO CARTESIANO
	glLineWidth(12.0); //ANCHURA DE LA LINEA
	glColor3f(0.0f, 0.0f, 0.0f);//COLOR DE LINEA (NEGRO)
	glBegin(GL_LINES); //FUNCION PARA GRAFICAR LINEAS
		glVertex2d(-30,0); //LINEA NEGRA DE PLANO (X)
		glVertex2d(30,0);
		glVertex2d(0,30); //LINEA NEGRA DE PLANO (Y)
		glVertex2d(0,-30);
	glEnd();
	
	//LINEAS CUADRICULADAS DEL PLANO
	glLineWidth(2.0); //ANCHURA DE LA LINEA 
	glColor3f(0.0f, 0.5f, 0.5f);//COLOR DE LINEA (BLUE-GREEN)
	glBegin(GL_LINES); //FUNCION PARA GRAFICAR LINEAS
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
		glColor3f(0.0f, 0.5f, 0.5f);
		glVertex3f(0.0f, 0.0f, 0.0f); //ORIGEN
		glColor3f(1.0f, 0.5f, 0.0f);//COLOR ORANGE
		
		//ALGORITMO BRESENHAM
		int x_1, y_1, x_2, y_2, dy, dx, p;
		double pendiente;
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA X1 DEL CUADRADO ==>"; cin >> x_1;
		cout <<"INGRESE LA ESQUINA INFERIOR IZQUIERDA Y1 DEL CUADRADO ==>"; cin >> y_1;
		cout <<"INGRESE LA ESQUINA SUPERIOR DERECHA X2 DEL CUADRADO ==> "; cin >> x_2;
		cout <<"INGRESE LA ESQUINA SUPERIOR DERECHA Y2 DEL CUADRADO ==>"; cin >> y_2;
		int x = x_1;
		int y= y_1;
		
		dx= (x_2 - x_1);
		dy= (y_2 - y_1);
		pendiente=(dy/dx);
		cout <<"PENDIENTE: "<< pendiente <<"\n";
		
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
		
		if (pendiente==1){ //ANGULO 45 Y SE PUEDE HACER EL CUADRADO
				//Y1
				p= (2*dy-dx);
				for(int k=0;k<p+1;k++){ 
					glVertex2d(round(x_1),round(y_1));
					y_1++;
					cout <<"==>(" << x_1 <<","<< y_1 <<")" "\n";
				}
				//X2
				for(int k=0;k<p+1;k++){ 
					glVertex2d(round(x_1),round(y_1-1));
					x_1++;
					cout <<"=>(" << x_1 <<","<< y_1 <<")" "\n";
				}
				//Y2
				for(int k=0;k<p+1;k++){ 
					glVertex2d(round(x_2),round(y_1-1));
					y_1--;
					cout <<"=>(" << x_2 <<","<< y_1 <<")" "\n";
				}
				//HACIA ORIGEN X1
				for(int k=0;k<p+1;k++){ 
					glVertex2d(round(x_2),round(y_1));
					x_2--;
					cout <<"=>(" << x_2 <<","<< y_1 <<")" "\n";
				}
			}else{
				cout << "LAS COORDENADAS INGRESADAS NO DAN UN ANGULO DE 45 GRADOS, NO ES POSIBLE HACER EL CUADRADO\n";
				glutHideWindow();
			}
		}
		
	glEnd();
	
	glFlush(); //PROCESA SUBRUTINAS DE GLUT
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
	cout <<"INGRESE CON QUE METODO DESEA DIBUJAR EL CUADRADO \n ===>DDA=1 \n ===>BRESENHAM=2 \n"; cin>> figura;
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