#include <stdlib.h>
#include <windows.h>
#include <GL/freeglut.h>
#include <iostream>
#include "glm.h"
#include "Texture.h"
#include <cmath>
using namespace std;

GLMmodel* punteroM1 = NULL; // DOMO
GLMmodel* punteroM2 = NULL; // pista
GLMmodel* camino = NULL; // CAMINO
GLMmodel* pasto = NULL; // PASTO
GLMmodel* piso = NULL; //piso
GLMmodel* mostrador = NULL; //mostrador
GLMmodel* paredTienda = NULL; //pared de la tienda
GLMmodel* contornoTienda = NULL; //marcos y puertas
GLMmodel* techo = NULL; // techo de la tienda
GLMmodel* banner1 = NULL; //banner 1
GLMmodel* letras = NULL; // letrero
GLMmodel* banner2 = NULL;// letrero 2
GLMmodel* pisosCasas = NULL; //pisos de las demas casas como un solo obj
GLMmodel* techosCasas = NULL; //techos de las casas alrededor
GLMmodel* base = NULL; //base de todo
GLMmodel* casa1 = NULL; //casa amarilla
GLMmodel* ventanas = NULL; //ventanas
GLMmodel* casa2 = NULL; //casa 2 verde oscuro
GLMmodel* casa3 = NULL; //casa 3 naranja
GLMmodel* casa4 = NULL; //casa 4 morada
GLMmodel* casa5 = NULL; //casa 5 crema
GLMmodel* mesita1 = NULL;
GLMmodel* mesita2 = NULL;
GLMmodel* mesita3 = NULL;
GLMmodel* mesita4 = NULL;
GLMmodel* mesita5 = NULL;
GLMmodel* cajera = NULL;
GLMmodel* oferta1 = NULL;
GLMmodel* oferta2 = NULL;
GLMmodel* letreroRefrigeradora = NULL;
GLMmodel* letreroMicroondas = NULL;
GLMmodel* letreroTelevisor = NULL;
GLMmodel* letreroLicuadora = NULL;
GLMmodel* letreroLavadora = NULL;
GLMmodel* letreroTostadora = NULL;
GLMmodel* letreroCocina = NULL;
GLMmodel* letreroPlancha = NULL;
//ELECTRODOMESTICOS
GLMmodel* lavadora1 = NULL;
GLMmodel* lavadora2 = NULL;
GLMmodel* lavadora3 = NULL;
GLMmodel* refrigeradora1 = NULL;
GLMmodel* refrigeradora2 = NULL;
GLMmodel* refrigeradora3 = NULL;
GLMmodel* tostadora1 = NULL;
GLMmodel* tostadora2 = NULL;
GLMmodel* tostadora3 = NULL;
GLMmodel* televisor1 = NULL;
GLMmodel* televisor2 = NULL;
GLMmodel* televisor3 = NULL;
GLMmodel* cocina1 = NULL;
GLMmodel* cocina2 = NULL;
GLMmodel* cocina3 = NULL;
GLMmodel* licuadora1 = NULL;
GLMmodel* licuadora2 = NULL;
GLMmodel* licuadora3 = NULL;
GLMmodel* plancha1 = NULL;
GLMmodel* plancha2 = NULL;
GLMmodel* plancha3 = NULL;
GLMmodel* microondas1 = NULL;
GLMmodel* microondas2 = NULL;
GLMmodel* microondas3 = NULL;
//ROBOT
GLMmodel* mascara = NULL;
GLMmodel* cabeza = NULL;
GLMmodel* cuello = NULL;
GLMmodel* tronco = NULL;
GLMmodel* principal = NULL;
GLMmodel* sacro = NULL;
GLMmodel* hombroIzq = NULL;
GLMmodel* brazoIzq = NULL;
GLMmodel* codoIzq = NULL;
GLMmodel* antIzq = NULL;
GLMmodel* munneIzq = NULL;
GLMmodel* manoIzq = NULL;
GLMmodel* hombroDer = NULL;
GLMmodel* brazoDer = NULL;
GLMmodel* codoDer = NULL;
GLMmodel* antDer = NULL;
GLMmodel* munneDer = NULL;
GLMmodel* manoDer = NULL;
GLMmodel* caderaDer = NULL;
GLMmodel* musloDer= NULL;
GLMmodel* rodDer = NULL;
GLMmodel* pierDer = NULL;
GLMmodel* tobiDer = NULL;
GLMmodel* pieDer = NULL;
GLMmodel* caderaIzq = NULL;
GLMmodel* musloIzq = NULL;
GLMmodel* rodIzq = NULL;
GLMmodel* pierIzq = NULL;
GLMmodel* tobiIzq = NULL;
GLMmodel* pieIzq = NULL;

GLuint	texture;
Texture	treeTextureAr[75];

bool LoadTreeTextures()
{
	int i;
	if (LoadTGA(&treeTextureAr[0], "texturas/cieloEsfera.tga") && LoadTGA(&treeTextureAr[1], "texturas/pista.tga")
     && LoadTGA(&treeTextureAr[2], "texturas/camino.tga") && LoadTGA(&treeTextureAr[3], "texturas/pasto.tga")
     && LoadTGA(&treeTextureAr[4], "texturas/piso.tga") && LoadTGA(&treeTextureAr[5], "texturas/colorMarron.tga")
     && LoadTGA(&treeTextureAr[6], "texturas/paredTienda.tga")&&LoadTGA(&treeTextureAr[7], "texturas/techo.tga")
     && LoadTGA(&treeTextureAr[8], "texturas/banner1.tga") && LoadTGA(&treeTextureAr[9], "texturas/letras.tga")
     && LoadTGA(&treeTextureAr[10], "texturas/banner2.tga") && LoadTGA(&treeTextureAr[11], "texturas/colorGris.tga")
     && LoadTGA(&treeTextureAr[12], "texturas/colorAmarillo.tga") && LoadTGA(&treeTextureAr[13], "texturas/ventana.tga")
     && LoadTGA(&treeTextureAr[14], "texturas/colorVerde.tga") && LoadTGA(&treeTextureAr[15], "texturas/colorNaranja.tga")
     && LoadTGA(&treeTextureAr[16], "texturas/colorMorado.tga") && LoadTGA(&treeTextureAr[17], "texturas/colorCrema.tga")
     && LoadTGA(&treeTextureAr[18], "texturas/paleta3.tga")
     && LoadTGA(&treeTextureAr[19], "texturas/RefrigeradoraAzul.tga")
     && LoadTGA(&treeTextureAr[20], "texturas/colorTostadora1.tga")
     && LoadTGA(&treeTextureAr[21], "texturas/negroTele.tga")
     && LoadTGA(&treeTextureAr[22], "texturas/colorCocina1.tga")
     && LoadTGA(&treeTextureAr[23], "texturas/colorTostadora2.tga")
     && LoadTGA(&treeTextureAr[24], "texturas/colorTostadora3.tga")
     && LoadTGA(&treeTextureAr[25], "texturas/colormesita2.tga")
     && LoadTGA(&treeTextureAr[26], "texturas/colorRefrigeradora3.tga")
     && LoadTGA(&treeTextureAr[27], "texturas/colorCocina2.tga")
     && LoadTGA(&treeTextureAr[28], "texturas/colorCocina3.tga")
     && LoadTGA(&treeTextureAr[29], "texturas/colorLicuadora1.tga")
     && LoadTGA(&treeTextureAr[30], "texturas/colortv2.tga")
     && LoadTGA(&treeTextureAr[31], "texturas/televisorSony3.tga")
     && LoadTGA(&treeTextureAr[32], "texturas/colorLicuadora2.tga")
     && LoadTGA(&treeTextureAr[33], "texturas/colorPlancha1.tga")
     && LoadTGA(&treeTextureAr[34], "texturas/colorPlancha2.tga")
     && LoadTGA(&treeTextureAr[35], "texturas/colorPlancha3.tga")
     && LoadTGA(&treeTextureAr[36], "texturas/colorMicro1.tga")
     && LoadTGA(&treeTextureAr[37], "texturas/colorMicro2.tga")
     && LoadTGA(&treeTextureAr[38], "texturas/colorMicro3.tga")
     && LoadTGA(&treeTextureAr[39], "texturas/robot/colorCrema.tga")
     && LoadTGA(&treeTextureAr[40], "texturas/robot/colorGris.tga")
     && LoadTGA(&treeTextureAr[41], "texturas/robot/colorAmarillo.tga")
     && LoadTGA(&treeTextureAr[42], "texturas/cajera/cajera.tga")
     && LoadTGA(&treeTextureAr[43], "texturas/letrero/oferta1.tga")
     && LoadTGA(&treeTextureAr[44], "texturas/letrero/oferta2.tga")
     && LoadTGA(&treeTextureAr[45], "texturas/letrero/letreroRefrigeradora1.tga")
     && LoadTGA(&treeTextureAr[46], "texturas/letrero/letreroRefrigeradora2.tga")
     && LoadTGA(&treeTextureAr[47], "texturas/letrero/letreroRefrigeradora3.tga")
     && LoadTGA(&treeTextureAr[48], "texturas/letrero/letreroMicroondas1.tga")
     && LoadTGA(&treeTextureAr[49], "texturas/letrero/letreroMicroondas2.tga")
     && LoadTGA(&treeTextureAr[50], "texturas/letrero/letreroMicroondas3.tga")
     && LoadTGA(&treeTextureAr[51], "texturas/letrero/letreroTelevisor1.tga")
     && LoadTGA(&treeTextureAr[52], "texturas/letrero/letreroTelevisor2.tga")
     && LoadTGA(&treeTextureAr[53], "texturas/letrero/letreroTelevisor3.tga")
     && LoadTGA(&treeTextureAr[54], "texturas/letrero/letreroLicuadora1.tga")
     && LoadTGA(&treeTextureAr[55], "texturas/letrero/letreroLicuadora2.tga")
     && LoadTGA(&treeTextureAr[56], "texturas/letrero/letreroLicuadora3.tga")
     && LoadTGA(&treeTextureAr[57], "texturas/letrero/letreroLavadora1.tga")
     && LoadTGA(&treeTextureAr[58], "texturas/letrero/letreroLavadora2.tga")
     && LoadTGA(&treeTextureAr[59], "texturas/letrero/letreroLavadora3.tga")
     && LoadTGA(&treeTextureAr[60], "texturas/letrero/letreroTostadora1.tga")
     && LoadTGA(&treeTextureAr[61], "texturas/letrero/letreroTostadora2.tga")
     && LoadTGA(&treeTextureAr[62], "texturas/letrero/letreroTostadora3.tga")
     && LoadTGA(&treeTextureAr[63], "texturas/letrero/letreroCocina1.tga")
     && LoadTGA(&treeTextureAr[64], "texturas/letrero/letreroCocina2.tga")
     && LoadTGA(&treeTextureAr[65], "texturas/letrero/letreroCocina3.tga")
     && LoadTGA(&treeTextureAr[66], "texturas/letrero/letreroPlancha1.tga")
     && LoadTGA(&treeTextureAr[67], "texturas/letrero/letreroPlancha2.tga")
     && LoadTGA(&treeTextureAr[68], "texturas/letrero/letreroPlancha3.tga")
     )
	{
		for (i = 0; i<69; i++){
			glGenTextures(1, &treeTextureAr[i].texID);
			glBindTexture(GL_TEXTURE_2D, treeTextureAr[i].texID);
			glTexImage2D(GL_TEXTURE_2D, 0, treeTextureAr[i].bpp / 8, treeTextureAr[i].width, treeTextureAr[i].height, 0, treeTextureAr[i].type, GL_UNSIGNED_BYTE, treeTextureAr[i].imageData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			if (treeTextureAr[i].imageData)
			{
				free(treeTextureAr[i].imageData);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

//GLOBALES PARA ROBOTO (PERSONAJE) ===============================================================
void animateBrazoDer();
void animateBrazoIzq();
void animateCaderaDer();
void animateCaderaIzq();
void animatePiernaDer();
void animatePiernaIzq();
void animate_quieto();
void mover_codo_der();
void mover_codo_izq();
void mover_manos_click();

//CAMINAR
float anim_cadera_der = 0; bool band = true;
float anim_pierna_der = 0; bool band1 = true;
float anim_cadera_izq = 0; bool band2 = true;
float anim_pierna_izq = 0; bool band3 = true;

float anim_brazo_der = 0;  bool band4 = true;
float anim_brazo_izq = 0;  bool band5 = true;

float anim_codo_der = 0;  bool band6 = true;
float anim_codo_izq = 0;  bool band7 = true;

float mover_mano_der = 0; bool band8 = true;
float mover_mano_izq = 0;

float vel_caminar = 8; //velocidad de extremidades al caminar
float anguloRobot = 0; //rotacion del robot eje y

float rotacion_microondas = 0;
float rotacion_refrigeradora = 0;
float rotacion_televisor = 0;
float rotacion_licuadora = 0;
float rotacion_lavadora = 0;
float rotacion_tostadora = 0;
float rotacion_cocina = 0;
float rotacion_plancha = 0;

//CAMBIO DE ELECTRODOMESTICO *******************************************************
int tipo_microondas = 1;
int tipo_refrigeradora = 1;
int tipo_televisor = 1;
int tipo_licuadora = 1;
int tipo_lavadora = 1;
int tipo_tostadora = 1;
int tipo_cocina = 1;
int tipo_plancha = 1;

void cambio_microondas(){
    if(tipo_microondas==3)
    tipo_microondas = 1;
    else
    tipo_microondas = tipo_microondas + 1;
}
void cambio_refrigeradora(){
    if(tipo_refrigeradora==3)
    tipo_refrigeradora = 1;
    else
    tipo_refrigeradora = tipo_refrigeradora + 1;
}
void cambio_televisor(){
    if(tipo_televisor==3)
    tipo_televisor = 1;
    else
    tipo_televisor = tipo_televisor + 1;
}
void cambio_licuadora(){
    if(tipo_licuadora==3)
    tipo_licuadora = 1;
    else
    tipo_licuadora = tipo_licuadora + 1;
}
void cambio_lavadora(){
    if(tipo_lavadora==3)
    tipo_lavadora = 1;
    else
    tipo_lavadora = tipo_lavadora + 1;
}
void cambio_tostadora(){
    if(tipo_tostadora==3)
    tipo_tostadora = 1;
    else
    tipo_tostadora = tipo_tostadora + 1;
}
void cambio_cocina(){
    if(tipo_cocina==3)
    tipo_cocina = 1;
    else
    tipo_cocina = tipo_cocina + 1;
}
void cambio_plancha(){
    if(tipo_plancha==3)
    tipo_plancha = 1;
    else
    tipo_plancha = tipo_plancha + 1;
}

//CAMARA **************************************************************************
float robotX = 0.0f; // Posición X del robot
float robotY = -0.5f; // Posición Y del robot
float robotZ = 8.0f; // Posición Z del robot

float cameraDistance = 3.0f; // Distancia inicial entre la cámara y el robot
float cameraYaw = 0.0f;     // Rotación horizontal
float cameraPitch = 0.0f;   // Rotación vertical

int modoVista = 1;
int activarW = 1;

void updateCamera() {

    if (modoVista == 1){
        // Calcula las coordenadas cartesianas de la cámara alrededor del robot
        float cameraX = robotX + cameraDistance * sin(cameraYaw) * cos(cameraPitch);
        float cameraY = robotY + cameraDistance * sin(cameraPitch);
        float cameraZ = robotZ + cameraDistance * cos(cameraYaw) * cos(cameraPitch);

        glLoadIdentity();

        gluLookAt(
            cameraX, cameraY, cameraZ,
            robotX, robotY, robotZ,
            0.0, 1.0, 0.0
        );

    }else{
        // Modo primera persona
        float cameraX = robotX;
        float cameraY = robotY + 0.57;  // Altura de los ojos del robot (ajustar según tu modelo)
        float cameraZ = robotZ;

        glLoadIdentity();

        gluLookAt(
            cameraX, cameraY, cameraZ,
            cameraX + cos(cameraYaw) * cos(cameraPitch),
            cameraY + sin(cameraPitch),
            cameraZ + sin(cameraYaw) * cos(cameraPitch),
            0.0, 1.0, 0.0
        );
    }
}

void handleMouse(int x, int y) {
    int centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
    int centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;

    int deltaX = x - centerX;
    int deltaY = y - centerY;

    const float sensitivity = 0.005f;
    cameraYaw += deltaX * sensitivity;
    cameraPitch += deltaY * sensitivity;

    // Limitar la inclinación vertical para evitar giros excesivos
    cameraPitch = fmin(1.5f, fmax(-1.5f, cameraPitch));

    // Reposicionar el puntero del mouse al centro
    glutWarpPointer(centerX, centerY);

    glutPostRedisplay();
}

void moveRobot(float deltaX, float deltaY, float deltaZ) {
    float cameraSpeed = 0.2f; //Velocidad

    robotX += deltaX * cameraSpeed;
    robotY += deltaY;
    robotZ += deltaZ * cameraSpeed;

    // Calcula el ángulo de rotación en radianes basado en la dirección de avance
    anguloRobot = -atan2(deltaZ, deltaX) + 45.5;

    glutPostRedisplay();
}

//Avanzar el robot
void advanceRobot(float distance) {
    // Avanzar el robot en la dirección de la cámara (orientación horizontal)
    float deltaRobotX = -distance * sin(cameraYaw);
    float deltaRobotZ = -distance * cos(cameraYaw);

    moveRobot(deltaRobotX, 0.0f, deltaRobotZ);
}

void handleKeypress(unsigned char key, int x, int y) {
    float cameraSpeed = 0.2f;

    switch (key) {
        case 'w':
            if (activarW == 1){

            animateBrazoDer();
            animateBrazoIzq();
            animateCaderaDer();
            animateCaderaIzq();
            animatePiernaDer();
            animatePiernaIzq();

            advanceRobot(1);
            }
            break;
        case 'c':
            if (modoVista==1){ //Vista 3era persona
                anim_brazo_der-=100;
                anim_brazo_izq-=100;
                modoVista = 0;
                activarW = 0;
            }
            else{
                anim_brazo_der=0;
                anim_brazo_izq=0;
                modoVista = 1;
                activarW = 1;

                rotacion_microondas = 0;
                rotacion_refrigeradora = 0;
                rotacion_televisor = 0;
                rotacion_licuadora = 0;
                rotacion_lavadora = 0;
                rotacion_tostadora = 0;
                rotacion_cocina = 0;
                rotacion_plancha = 0;

                anim_codo_der = 0;
                anim_codo_izq = 0;
                mover_mano_der = 0; mover_mano_izq = 0;
            }
            break;

        case '+': //Aumentar distancia de camara
            cameraDistance += 1;
            break;

        case '-': //Disminuir distancia de camara
            if (cameraDistance > 2)
            cameraDistance -= 1;
            break;

        default:
            break;
    }

    glutPostRedisplay();
}
void teclaLiberada(unsigned char tecla, int x, int y) {
    switch (toupper(tecla)) {
        case 'W':
            animate_quieto();
            break;
        default: glutPostRedisplay();
            break;
    }
    glutPostRedisplay();
}

void special_key(int Tecla1,int x,int y){
    switch (Tecla1){
        case GLUT_KEY_LEFT:
            if(robotX < 4.1 && robotX > 0.9 && robotZ > -8.1 && robotZ < -4.9)
            {rotacion_microondas -= 3; mover_codo_der();}

            if(robotX > -4.1 && robotX <-0.9 && robotZ > -8.1 && robotZ < -4.9)
            {rotacion_refrigeradora-=3; mover_codo_der();}

            if(robotX > -7.6 && robotX < -4.6 && robotZ > -5.6 && robotZ < -2.4)
            {rotacion_televisor -=3; mover_codo_der();}

            if(robotX < 7.6 && robotX > 4.6 && robotZ > -5.6 && robotZ < -2.4)
            {rotacion_licuadora -= 3; mover_codo_der();}

            if(robotX > -8.1 && robotX < -3.1 && robotZ > -19.1 && robotZ < -14.9)
            {rotacion_lavadora -=3; mover_codo_der();}

            if(robotX < 8.1 && robotX > 3.1 && robotZ > -19.1 && robotZ < -14.9)
            {rotacion_tostadora -=3; mover_codo_der();}

            if(robotX > -8.1 && robotX <-3.1 && robotZ > -25.1 && robotZ < -20.9)
            {rotacion_cocina -=3; mover_codo_der(); }

            if(robotX < 8.1 && robotX > 3.1 && robotZ > -25.1 && robotZ < -20.9)
            {rotacion_plancha -=3; mover_codo_der();}

            mover_mano_der = 0; mover_mano_izq = 0; //QUITAR LA ANIMACION DE LAS MANOS
            break;
        case GLUT_KEY_RIGHT:
            if(robotX < 4.1 && robotX > 0.9 && robotZ > -8.1 && robotZ < -4.9)
            {rotacion_microondas += 3; mover_codo_izq();}

            if(robotX > -4.1 && robotX <-0.9 && robotZ > -8.1 && robotZ < -4.9)
            {rotacion_refrigeradora+=3; mover_codo_izq();}

            if(robotX > -7.6 && robotX < -4.6 && robotZ > -5.6 && robotZ < -2.4)
            {rotacion_televisor +=3; mover_codo_izq();}

            if(robotX < 7.6 && robotX > 4.6 && robotZ > -5.6 && robotZ < -2.4)
            {rotacion_licuadora += 3; mover_codo_izq();}

            if(robotX > -8.1 && robotX < -3.1 && robotZ > -19.1 && robotZ < -14.9)
            {rotacion_lavadora +=3; mover_codo_izq();}

            if(robotX < 8.1 && robotX > 3.1 && robotZ > -19.1 && robotZ < -14.9)
            {rotacion_tostadora +=3; mover_codo_izq();}

            if(robotX > -8.1 && robotX <-3.1 && robotZ > -25.1 && robotZ < -20.9)
            {rotacion_cocina +=3; mover_codo_izq(); }

            if(robotX < 8.1 && robotX > 3.1 && robotZ > -25.1 && robotZ < -20.9)
            {rotacion_plancha +=3; mover_codo_izq();}

            mover_mano_der = 0; mover_mano_izq = 0; //QUITAR LA ANIMACION DE LAS MANOS
            break;
        case GLUT_KEY_UP: break;
        case GLUT_KEY_DOWN: break;
        case GLUT_KEY_PAGE_UP: break;
        case GLUT_KEY_PAGE_DOWN: break;
	}
    glutPostRedisplay();
}

//click
void handleMouseClick(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Lógica para manejar el clic del mouse izquierdo

        if(robotX > -4.1 && robotX <-0.9 && robotZ > -8.1 && robotZ < -4.9)
        {cambio_refrigeradora(); rotacion_refrigeradora = 0;
        anim_codo_der = 0; anim_codo_izq =0; mover_manos_click(); }

        if(robotX < 4.1 && robotX > 0.9 && robotZ > -8.1 && robotZ < -4.9)
        {cambio_microondas(); rotacion_microondas = 0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click(); }

        if(robotX > -7.6 && robotX < -4.6 && robotZ > -5.6 && robotZ < -2.4)
        {cambio_televisor(); rotacion_televisor = 0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click(); }

        if(robotX < 7.6 && robotX > 4.6 && robotZ > -5.6 && robotZ < -2.4)
        {cambio_licuadora(); rotacion_licuadora =0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click(); }

        if(robotX > -8.1 && robotX < -3.1 && robotZ > -19.1 && robotZ < -14.9)
        {cambio_lavadora(); rotacion_lavadora = 0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click(); }

        if(robotX < 8.1 && robotX > 3.1 && robotZ > -19.1 && robotZ < -14.9)
        {cambio_tostadora(); rotacion_tostadora = 0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click();}

        if(robotX > -8.1 && robotX <-3.1 && robotZ > -25.1 && robotZ < -20.9)
        {cambio_cocina(); rotacion_cocina = 0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click(); }

        if(robotX < 8.1 && robotX > 3.1 && robotZ > -25.1 && robotZ < -20.9)
        {cambio_plancha(); rotacion_plancha = 0;
        anim_codo_der = 0; anim_codo_izq = 0; mover_manos_click(); }
    }

}

void graficar(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	updateCamera();

    //Posicion inicial
	glTranslatef(0,-2,0);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
	glmDraw(punteroM1, GLM_SMOOTH | GLM_TEXTURE);

	glPushMatrix();
	glTranslatef(0,0.2,0);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[1].texID);
        glmDraw(punteroM2, GLM_SMOOTH | GLM_TEXTURE);

        glBindTexture(GL_TEXTURE_2D, treeTextureAr[2].texID);
        glmDraw(camino, GLM_SMOOTH | GLM_TEXTURE);

        glBindTexture(GL_TEXTURE_2D, treeTextureAr[3].texID);
        glmDraw(pasto, GLM_SMOOTH | GLM_TEXTURE);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[4].texID);
	glmDraw(piso, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
	glmDraw(mostrador, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
	glmDraw(paredTienda, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[7].texID);
	glmDraw(contornoTienda, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[7].texID);
	glmDraw(techo, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[8].texID);
	glmDraw(banner1, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[9].texID);
	glmDraw(letras, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[10].texID);
	glmDraw(banner2, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[11].texID);
	glmDraw(pisosCasas, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
	glmDraw(techosCasas, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[11].texID);
	glmDraw(base, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[12].texID);
	glmDraw(casa1, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[13].texID);
	glmDraw(ventanas, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[14].texID);
	glmDraw(casa2, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[15].texID);
	glmDraw(casa3, GLM_SMOOTH | GLM_TEXTURE);

    glBindTexture(GL_TEXTURE_2D, treeTextureAr[16].texID);
	glmDraw(casa4, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[17].texID);
	glmDraw(casa5, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
	glmDraw(mesita1, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[25].texID);
	glmDraw(mesita2, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
	glmDraw(mesita3, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
	glmDraw(mesita4, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[11].texID);
	glmDraw(mesita5, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[42].texID);
	glmDraw(cajera, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[43].texID);
	glmDraw(oferta1, GLM_SMOOTH | GLM_TEXTURE);

	glBindTexture(GL_TEXTURE_2D, treeTextureAr[44].texID);
	glmDraw(oferta2, GLM_SMOOTH | GLM_TEXTURE);

    //3 PLANCHAS ===========================================
    switch(tipo_plancha){
        case 1:
            glPushMatrix();
            glTranslatef(6.0157,0,-22.92);
            glRotatef(rotacion_plancha,0,1,0);
            glTranslatef(-6.0157,0,22.92);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[33].texID);
            glmDraw(plancha1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[66].texID);
            glmDraw(letreroPlancha, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(6.0157,0,-22.92);
            glRotatef(rotacion_plancha,0,1,0);
            glTranslatef(-6.0157,0,22.92);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[34].texID);
            glmDraw(plancha2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[67].texID);
            glmDraw(letreroPlancha, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(6.0157,0,-22.92);
            glRotatef(rotacion_plancha,0,1,0);
            glTranslatef(-6.0157,0,22.92);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[35].texID);
            glmDraw(plancha3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[68].texID);
            glmDraw(letreroPlancha, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }

    //3 COCINAS ============================================
    switch(tipo_cocina){
        case 1:
            glPushMatrix();
            glTranslatef(-6.9643,0,-23.12);
            glRotatef(rotacion_cocina,0,1,0);
            glTranslatef(6.9643,0,23.12);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[22].texID);
            glmDraw(cocina1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[63].texID);
            glmDraw(letreroCocina, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(-6.9643,0,-23.12);
            glRotatef(rotacion_cocina,0,1,0);
            glTranslatef(6.9643,0,23.12);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[27].texID);
            glmDraw(cocina2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[64].texID);
            glmDraw(letreroCocina, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(-6.9643,0,-23.12);
            glRotatef(rotacion_cocina,0,1,0);
            glTranslatef(6.9643,0,23.12);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[28].texID);
            glmDraw(cocina3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[65].texID);
            glmDraw(letreroCocina, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }

    //3 TOSTADORAS =========================================
    switch(tipo_tostadora){
        case 1:
            glPushMatrix();
            glTranslatef(5.5157,0,-18.42);
            glRotatef(rotacion_tostadora,0,1,0);
            glTranslatef(-5.5157,0,18.42);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[20].texID);
            glmDraw(tostadora1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[60].texID);
            glmDraw(letreroTostadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(5.5157,0,-18.42);
            glRotatef(rotacion_tostadora,0,1,0);
            glTranslatef(-5.5157,0,18.42);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[23].texID);
            glmDraw(tostadora2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[61].texID);
            glmDraw(letreroTostadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(5.5157,0,-18.42);
            glRotatef(rotacion_tostadora,0,1,0);
            glTranslatef(-5.5157,0,18.42);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[24].texID);
            glmDraw(tostadora3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[62].texID);
            glmDraw(letreroTostadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }

    //3 LAVADORAS ==========================================
	switch(tipo_lavadora){
        case 1:
            glPushMatrix();
            glTranslatef(-5.9843,0,-18.6);
            glRotatef(rotacion_lavadora,0,1,0);
            glTranslatef(5.9843,0,18.6);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[18].texID);
            glmDraw(lavadora1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[57].texID);
            glmDraw(letreroLavadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(-5.9843,0,-18.6);
            glRotatef(rotacion_lavadora,0,1,0);
            glTranslatef(5.9843,0,18.6);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[18].texID);
            glmDraw(lavadora2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[58].texID);
            glmDraw(letreroLavadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(-5.9843,0,-18.6);
            glRotatef(rotacion_lavadora,0,1,0);
            glTranslatef(5.9843,0,18.6);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[18].texID);
            glmDraw(lavadora3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[59].texID);
            glmDraw(letreroLavadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
	}

    //3 LICUADORAS =========================================
    switch(tipo_licuadora){
        case 1:
            glPushMatrix();
            glTranslatef(6.0157,0,-2.2997);
            glRotatef(rotacion_licuadora,0,1,0);
            glTranslatef(-6.0157,0,2.2997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[29].texID);
            glmDraw(licuadora1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[54].texID);
            glmDraw(letreroLicuadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(6.0157,0,-2.2997);
            glRotatef(rotacion_licuadora,0,1,0);
            glTranslatef(-6.0157,0,2.2997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[32].texID);
            glmDraw(licuadora2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[55].texID);
            glmDraw(letreroLicuadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(6.0157,0,-2.2997);
            glRotatef(rotacion_licuadora,0,1,0);
            glTranslatef(-6.0157,0,2.2997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[18].texID);
            glmDraw(licuadora3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[56].texID);
            glmDraw(letreroLicuadora, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }

    //3 TELEVISORES ========================================
    switch(tipo_televisor){
        case 1:
            glPushMatrix();
            glTranslatef(-5.8933,0,-1.9997);
            glRotatef(rotacion_televisor,0,1,0);
            glTranslatef(5.8933,0,1.9997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[21].texID);
            glmDraw(televisor1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[51].texID);
            glmDraw(letreroTelevisor, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(-5.8933,0,-1.9997);
            glRotatef(rotacion_televisor,0,1,0);
            glTranslatef(5.8933,0,1.9997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[30].texID);
            glmDraw(televisor2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[52].texID);
            glmDraw(letreroTelevisor, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(-5.8933,0,-1.9997);
            glRotatef(rotacion_televisor,0,1,0);
            glTranslatef(5.8933,0,1.9997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[31].texID);
            glmDraw(televisor3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[53].texID);
            glmDraw(letreroTelevisor, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }

    //3 REFRIGERADORAS =====================================
    switch(tipo_refrigeradora){
        case 1:
            glPushMatrix();
            glTranslatef(-2.4933,0,-8.5997);
            glRotatef(rotacion_refrigeradora,0,1,0);
            glTranslatef(2.4933,0,8.5997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[19].texID);
            glmDraw(refrigeradora1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[45].texID);
            glmDraw(letreroRefrigeradora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(-2.4933,0,-8.5997);
            glRotatef(rotacion_refrigeradora,0,1,0);
            glTranslatef(2.4933,0,8.5997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[19].texID);
            glmDraw(refrigeradora2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[46].texID);
            glmDraw(letreroRefrigeradora, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(-2.4933,0,-8.5997);
            glRotatef(rotacion_refrigeradora,0,1,0);
            glTranslatef(2.4933,0,8.5997);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[26].texID);
            glmDraw(refrigeradora3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[47].texID);
            glmDraw(letreroRefrigeradora, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }

    //3 MICROONDAS =========================================
    switch(tipo_microondas){
        case 1:
            glPushMatrix();
            glTranslatef(2.4567,0,-8.6497);
            glRotatef(rotacion_microondas,0,1,0);
            glTranslatef(-2.4567,0,8.6497);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[36].texID);
            glmDraw(microondas1, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[48].texID);
            glmDraw(letreroMicroondas, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 2:
            glPushMatrix();
            glTranslatef(2.4567,0,-8.6497);
            glRotatef(rotacion_microondas,0,1,0);
            glTranslatef(-2.4567,0,8.6497);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[37].texID);
            glmDraw(microondas2, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[49].texID);
            glmDraw(letreroMicroondas, GLM_SMOOTH | GLM_TEXTURE);
            break;
        case 3:
            glPushMatrix();
            glTranslatef(2.4567,0,-8.6497);
            glRotatef(rotacion_microondas,0,1,0);
            glTranslatef(-2.4567,0,8.6497);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[38].texID);
            glmDraw(microondas3, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[50].texID);
            glmDraw(letreroMicroondas, GLM_SMOOTH | GLM_TEXTURE);
            break;
    }


//ROBOT (PERSONAJE)====================================================================================
//====================================================================================================
    glPushMatrix();
    glTranslatef(robotX,robotY+0.5,robotZ);
    glRotatef(anguloRobot * (180.0f / M_PI), 0.0f, 1.0f, 0.0f);

    ///CABEZA
    glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
    glmDraw(cuello, GLM_SMOOTH | GLM_TEXTURE);

    glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
    glmDraw(cabeza, GLM_SMOOTH | GLM_TEXTURE);

    glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
    glmDraw(mascara, GLM_SMOOTH | GLM_TEXTURE);

    ///PRINCIPAL
    glBindTexture(GL_TEXTURE_2D, treeTextureAr[41].texID);
    glmDraw(principal, GLM_SMOOTH | GLM_TEXTURE);

    ///SACRO
    glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
    glmDraw(sacro, GLM_SMOOTH | GLM_TEXTURE);

    ///TRONCO
    glBindTexture(GL_TEXTURE_2D, treeTextureAr[41].texID);
    glmDraw(tronco, GLM_SMOOTH | GLM_TEXTURE);

    //PIERNA DERECHA ANIMACION
    glPushMatrix();
        glTranslated(+0.17,1,0);
        glRotated(anim_cadera_der,1,0,0);
        glTranslated(-0.17,-1,0);

        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(caderaIzq, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
        glmDraw(musloIzq, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(rodIzq, GLM_SMOOTH | GLM_TEXTURE);

        glPushMatrix();
            glTranslated(+0.17,0.6,0);
            glRotated(anim_pierna_der,1,0,0);
            glTranslated(-0.17,-0.6,0);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
            glmDraw(pierIzq, GLM_SMOOTH | GLM_TEXTURE);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
            glmDraw(tobiIzq, GLM_SMOOTH | GLM_TEXTURE);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
            glmDraw(pieIzq, GLM_SMOOTH | GLM_TEXTURE);

        glPopMatrix();
    glPopMatrix();

    //ANIMACIÓN PIERNA IZQUIERDA
    glPushMatrix();
        glTranslated(+0.17,1,0);
        glRotated(anim_cadera_izq,1,0,0);
        glTranslated(-0.17,-1,0);

        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(caderaDer, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
        glmDraw(musloDer, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(rodDer, GLM_SMOOTH | GLM_TEXTURE);

        glPushMatrix();
            glTranslated(+0.17,0.6,0);
            glRotated(anim_pierna_izq,1,0,0);
            glTranslated(-0.17,-0.6,0);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
            glmDraw(pierDer, GLM_SMOOTH | GLM_TEXTURE);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
            glmDraw(tobiDer, GLM_SMOOTH | GLM_TEXTURE);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
            glmDraw(pieDer, GLM_SMOOTH | GLM_TEXTURE);

        glPopMatrix();
    glPopMatrix();

    //BRAZO DERECHO
    glPushMatrix();
        glTranslated(-0.5,1.5,0);
        glRotated(anim_brazo_der,1,0,0);
        glTranslated(+0.5,-1.5,0);

        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(hombroDer, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
        glmDraw(brazoIzq, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(codoIzq, GLM_SMOOTH | GLM_TEXTURE);

        glPushMatrix(); //Codo - antebrazo
            glTranslated(-0.4,1.2,0);
            glRotated(anim_codo_der,0,0,1);
            glTranslated(+0.4,-1.2,0);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
            glmDraw(antIzq, GLM_SMOOTH | GLM_TEXTURE);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
            glmDraw(munneIzq, GLM_SMOOTH | GLM_TEXTURE);

            glPushMatrix(); //Muñeca- mano
                glTranslated(-0.38,0.94,0);
                glRotated(mover_mano_der,0,0,1);
                glTranslated(+0.38,-0.94,0);

                glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
                glmDraw(manoIzq, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    //BRAZO IZQUIERDO
    glPushMatrix();
        glTranslated(+0.5,1.5,0);
        glRotated(anim_brazo_izq,1,0,0);
        glTranslated(-0.5,-1.5,0);

        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(hombroIzq, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
        glmDraw(brazoDer, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
        glmDraw(codoDer, GLM_SMOOTH | GLM_TEXTURE);

        glPushMatrix(); //Codo - antebrazo
            glTranslated(+0.4,1.2,0);
            glRotated(anim_codo_izq,0,0,1);
            glTranslated(-0.4,-1.2,0);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
            glmDraw(antDer, GLM_SMOOTH | GLM_TEXTURE);
            glBindTexture(GL_TEXTURE_2D, treeTextureAr[39].texID);
            glmDraw(munneDer, GLM_SMOOTH | GLM_TEXTURE);

            glPushMatrix(); //Muñeca-mano
                glTranslated(+0.38,0.94,0);
                glRotated(mover_mano_izq,0,0,1);
                glTranslated(-0.38,-0.94,0);

                glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
                glmDraw(manoDer, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();
       glPopMatrix();
    glPopMatrix();
    glPopMatrix();

	glutSwapBuffers();
}

//ANIMACIONES ROBOT (CAMINAR)
void animateCaderaDer(){
	if (band == true)
	if (anim_cadera_der > -45)
    anim_cadera_der -= vel_caminar;
    else band = false;

    if (band == false)
    if (anim_cadera_der < 45)
    anim_cadera_der += vel_caminar;
    else band = true;

	glutPostRedisplay();
}
void animateCaderaIzq(){
	if (band2 == true)
	if (anim_cadera_izq < 45)
    anim_cadera_izq += vel_caminar;
    else band2 = false;

    if (band2 == false)
    if (anim_cadera_izq > -45)
    anim_cadera_izq -= vel_caminar;
    else band2 = true;

	glutPostRedisplay();
}

void animatePiernaDer(){
    if (band1 == true)
	if (anim_pierna_der > 4)
    anim_pierna_der -= vel_caminar;
    else band1 = false;

    if (band1 == false)
    if (anim_pierna_der < 35)
    anim_pierna_der += vel_caminar;
    else band1 = true;

	glutPostRedisplay();
}

void animatePiernaIzq(){
    if (band3 == true)
	if (anim_pierna_izq < 35)
    anim_pierna_izq += vel_caminar;
    else band3 = false;

    if (band3 == false)
    if (anim_pierna_izq > 4)
    anim_pierna_izq -= vel_caminar;
    else band3 = true;

	glutPostRedisplay();
}

void animateBrazoDer(){
    if (band4 == true)
	if (anim_brazo_der < 45)
    anim_brazo_der += vel_caminar;
    else band4 = false;

    if (band4 == false)
    if (anim_brazo_der > -45)
    anim_brazo_der -= vel_caminar;
    else band4 = true;

	glutPostRedisplay();
}

void animateBrazoIzq(){
    if (band5 == true)
	if (anim_brazo_izq > -45)
    anim_brazo_izq -= vel_caminar;
    else band5 = false;

    if (band5 == false)
    if (anim_brazo_izq < 45)
    anim_brazo_izq += vel_caminar;
    else band5 = true;

	glutPostRedisplay();
}

void animate_quieto(){
    anim_brazo_der = 0;
    anim_brazo_izq = 0;
    anim_cadera_der = 0;
    anim_cadera_izq = 0;
    anim_pierna_der = 0;
    anim_pierna_izq = 0;
}

void mover_codo_der(){
    if (band6 == true)
	if (anim_codo_der < 45)
    anim_codo_der += 2;
    else band6 = false;

    if (band6 == false)
    if (anim_codo_der > -1)
    anim_codo_der -= 10;
    else band6 = true;

	glutPostRedisplay();
}
void mover_codo_izq(){
    if (band7 == true)
	if (anim_codo_izq > -45)
    anim_codo_izq -= 2;
    else band7 = false;

    if (band7 == false)
    if (anim_codo_izq < 1)
    anim_codo_izq += 10;
    else band7 = true;

	glutPostRedisplay();
}

void mover_manos_click(){
    if (band8 == true)
	{
	    mover_mano_der+= 45;
	    mover_mano_izq = 0;
	    band8 = false;
	}
    else
    {
        mover_mano_izq-=45;
        mover_mano_der = 0;
        band8 = true;
    }
	glutPostRedisplay();
}

void redimensionar(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
}
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	LoadTreeTextures();
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1200, 650);
	glutInitWindowPosition(100, 10);
	glutCreateWindow("TIENDA EN OPEN GL");
	init();
	glutDisplayFunc(graficar);
	glutReshapeFunc(redimensionar);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(special_key);
    glutPassiveMotionFunc(handleMouse); //Para el movimiento del mouse
    glutMouseFunc(handleMouseClick);    // Para el clic del mouse
    glutKeyboardUpFunc(teclaLiberada); //Para soltar el clic del mouse */

	punteroM1 = glmReadOBJ("modelos/cieloEsfera.obj");
	punteroM2 = glmReadOBJ("modelos/pista.obj");
	camino = glmReadOBJ("modelos/camino.obj");
	pasto = glmReadOBJ("modelos/pasto.obj");
    piso = glmReadOBJ("modelos/piso.obj");
    mostrador = glmReadOBJ("modelos/mostrador.obj");
    paredTienda = glmReadOBJ("modelos/paredTienda.obj");
    contornoTienda = glmReadOBJ("modelos/contornoTienda.obj");
    techo = glmReadOBJ("modelos/techo.obj");
    banner1 = glmReadOBJ("modelos/banner1.obj");
    letras = glmReadOBJ("modelos/letras.obj");
    banner2 = glmReadOBJ("modelos/banner2.obj");
    pisosCasas = glmReadOBJ("modelos/pisosCasas.obj");
    techosCasas = glmReadOBJ("modelos/techosCasas.obj");
    casa1 = glmReadOBJ("modelos/casa1.obj");
    base = glmReadOBJ("modelos/base.obj");
    ventanas = glmReadOBJ("modelos/ventanas.obj");
    casa2 = glmReadOBJ("modelos/casa2.obj");
    casa3 = glmReadOBJ("modelos/casa3.obj");
    casa4 = glmReadOBJ("modelos/casa4.obj");
    casa5 = glmReadOBJ("modelos/casa5.obj");
    mesita1 = glmReadOBJ("modelos/mesita1.obj");
    mesita2 = glmReadOBJ("modelos/mesita2TV.obj");
    mesita3 = glmReadOBJ("modelos/mesita3.obj");
    mesita4 = glmReadOBJ("modelos/mesaPlancha123.obj");
    mesita5 = glmReadOBJ("modelos/mesita5.obj");
    cajera = glmReadOBJ("modelos/cajera/cajera.obj");
    oferta1 = glmReadOBJ("modelos/letrero/oferta1.obj");
    oferta2 = glmReadOBJ("modelos/letrero/oferta2.obj");
    letreroRefrigeradora = glmReadOBJ("modelos/letrero/letreroRefrigeradora1.obj");
    letreroMicroondas = glmReadOBJ("modelos/letrero/letreroMicroondas.obj");
    letreroTelevisor = glmReadOBJ("modelos/letrero/letreroTelevisor.obj");
    letreroLicuadora = glmReadOBJ("modelos/letrero/letreroLicuadora.obj");
    letreroLavadora = glmReadOBJ("modelos/letrero/letreroLavadora.obj");
    letreroTostadora = glmReadOBJ("modelos/letrero/letreroTostadora.obj");
    letreroPlancha = glmReadOBJ("modelos/letrero/letreroPlancha.obj");
    letreroCocina = glmReadOBJ("modelos/letrero/letreroCocina.obj");
    lavadora1 = glmReadOBJ("modelos/lavadora1.obj");
    lavadora2 = glmReadOBJ("modelos/lavadora2.obj");
    lavadora3 = glmReadOBJ("modelos/lavadora3.obj");
    refrigeradora1 = glmReadOBJ("modelos/RefrigeradoraAzul.obj");
    refrigeradora2 = glmReadOBJ("modelos/refrigeradora2.obj");
    refrigeradora3 = glmReadOBJ("modelos/refrigeradora2.obj");
    tostadora1 = glmReadOBJ("modelos/tostadora1.obj");
    tostadora2 = glmReadOBJ("modelos/tostadora2.obj");
    tostadora3 = glmReadOBJ("modelos/tostadora3.obj");
    televisor1 = glmReadOBJ("modelos/televisor1.obj");
    televisor2 = glmReadOBJ("modelos/Televissor2.obj");
    televisor3 = glmReadOBJ("modelos/televisor3.obj");
    cocina1 = glmReadOBJ("modelos/cocina1.obj");
    cocina2 = glmReadOBJ("modelos/cocina1.obj");
    cocina3 = glmReadOBJ("modelos/cocina1.obj");
    licuadora1 = glmReadOBJ("modelos/licuadora1.obj");
    licuadora2 = glmReadOBJ("modelos/licuadora2.obj");
    licuadora3 = glmReadOBJ("modelos/licuadora3.obj");
    plancha1 = glmReadOBJ("modelos/plancha1.obj");
    plancha2 = glmReadOBJ("modelos/plancha2.obj");
    plancha3 = glmReadOBJ("modelos/plancha3.obj");
    microondas1 = glmReadOBJ("modelos/microondas1.obj");
    microondas2 = glmReadOBJ("modelos/microondas2.obj");
    microondas3 = glmReadOBJ("modelos/microondas3.obj");
    //ROBOT ===========================================
    sacro = glmReadOBJ("modelos/robot/sacro.obj");
	tronco = glmReadOBJ("modelos/robot/tronco.obj");
	principal = glmReadOBJ("modelos/robot/principal.obj");
	mascara = glmReadOBJ ("modelos/robot/mascara.obj");
	cabeza = glmReadOBJ("modelos/robot/cabeza.obj");
	cuello = glmReadOBJ("modelos/robot/cuello.obj");
	hombroDer = glmReadOBJ("modelos/robot/hombroDer.obj");
	hombroIzq = glmReadOBJ("modelos/robot/hombroIzq.obj");
	brazoDer = glmReadOBJ("modelos/robot/brazoDer.obj");
	brazoIzq = glmReadOBJ("modelos/robot/brazoIzq.obj");
	codoDer = glmReadOBJ("modelos/robot/codoDer.obj");
	codoIzq = glmReadOBJ("modelos/robot/codoIzq.obj");
	antDer = glmReadOBJ("modelos/robot/antDer.obj");
	antIzq = glmReadOBJ("modelos/robot/antIzq.obj");
	munneDer = glmReadOBJ("modelos/robot/munneDer.obj");
	munneIzq = glmReadOBJ("modelos/robot/munneIzq.obj");
	manoDer = glmReadOBJ("modelos/robot/manoDer.obj");
	manoIzq = glmReadOBJ("modelos/robot/manoIzq.obj");
	caderaDer = glmReadOBJ("modelos/robot/caderaDer.obj");
	caderaIzq = glmReadOBJ("modelos/robot/caderaIzq.obj");
	musloDer = glmReadOBJ("modelos/robot/musloDer.obj");
	musloIzq = glmReadOBJ("modelos/robot/musloIzq.obj");
	rodDer = glmReadOBJ("modelos/robot/rodDer.obj");
	rodIzq = glmReadOBJ("modelos/robot/rodIzq.obj");
	pierDer = glmReadOBJ("modelos/robot/pierDer.obj");
	pierIzq = glmReadOBJ("modelos/robot/pierIzq.obj");
	tobiDer = glmReadOBJ("modelos/robot/tobiDer.obj");
	tobiIzq = glmReadOBJ("modelos/robot/tobiIzq.obj");
	pieDer = glmReadOBJ("modelos/robot/pieDer.obj");
	pieIzq = glmReadOBJ("modelos/robot/pieIzq.obj");

    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();
	return 0;
}


