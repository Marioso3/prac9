//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Sotres Cataño Mario**************//
//*************				Máquina 10					******//
//*************			Visual Studio 2015				******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -30; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1; //variable de tipo textura
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_madera;
CTexture t_madera2;
CTexture t_piedra;
CTexture t_ventana;
CTexture t_puerta;
CTexture t_techo;


int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);  //Habilitamos las texturas

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_madera.LoadTGA("madera.tga"); //cargamos la textura
	t_madera.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_madera.ReleaseImage();

	t_madera2.LoadTGA("madera2.tga"); //cargamos la textura
	t_madera2.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_madera2.ReleaseImage();

	t_piedra.LoadTGA("piedra.tga"); //cargamos la textura
	t_piedra.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_piedra.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga"); //cargamos la textura
	t_puerta.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_puerta.ReleaseImage();

	t_techo.LoadTGA("techo.tga"); //cargamos la textura
	t_techo.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_techo.ReleaseImage();

	t_ventana.LoadTGA("ventana.tga"); //cargamos la textura
	t_ventana.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_ventana.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2,float a, float b, float c,float d)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); //Se ponen los vértices donde está la textura. La primer coordenada de la
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[0]); //textura pertenece al primer vértice 0
			glTexCoord2f(a, d); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[7]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(a, d); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(a, d); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(a, d); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(a, d); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0, d); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(b, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(b, c); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, c); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();

}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
		glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	
		//*****PISO********
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glScalef(26.0,4.0,31.0);  
			prisma(t_piedra.GLindex, t_madera.GLindex, 3.0, 5.0, 3.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//********Escalón 1************		
		glPushMatrix();
			glTranslatef(0.0f, -1.0f, 16.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Escalón 2************		
		glPushMatrix();
			glTranslatef(0.0f, 1.0f, 16.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 2.0, 1.0);
			prisma(t_piedra.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Pared frontal************		
		glPushMatrix();							//parte de hasta arriba
			glTranslatef(0.0f, 13.5f, 10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(26.0, 3.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex,3.0,5.0, 3.0, 0.20); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de hasta abajo lado izquierdo
			glTranslatef(-7.5f, 4.5f, 10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(11.0, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 1.25, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de hasta abajo lado derecho
			glTranslatef(7.5f, 4.5f, 10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(11.0, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 1.25, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado izquierdo
			glTranslatef(-12.25f, 9.5f, 10.0f);		
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.5, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado derecho
			glTranslatef(12.25f, 9.5f, 10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.5, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio/centro lado izquierdo
			glTranslatef(-4.25f, 9.5f, 10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.5, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.5, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();
		
		glPushMatrix();							//parte de en medio/centro lado derecho
			glTranslatef(4.25f, 9.5f, 10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.5, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.5, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		//********Pared trasera************		
		glPushMatrix();							//parte de hasta arriba
			glTranslatef(0.0f, 13.5f, -15.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(26.0, 3.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 3.0, 5.0, 3.0, 0.20); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de hasta abajo
			glTranslatef(0.0f, 4.5f, -15.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(26.0, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 3.0, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado derecho
			glTranslatef(12.25f, 9.5f, -15.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.5, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado izquierdo
			glTranslatef(-12.25f, 9.5f, -15.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.5, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio
			glTranslatef(0.0f, 9.5f,-15.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(13.0, 5.0, 1.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 1.5, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		//********Pared derecha************		

		glPushMatrix();							//parte de hasta abajo
			glTranslatef(12.5f, 4.5f, -2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 24.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 3.0, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de hasta arriba
			glTranslatef(12.5f, 13.5f, -2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 3.0, 24.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 3.0, 5.0, 3.0, 0.20); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado derecho
			glTranslatef(12.5f, 9.5f, -13.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 2.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado izquierdo
			glTranslatef(12.5f, 9.5f, 8.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 2.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio
			glTranslatef(12.5f, 9.5f, -2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 10.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 1.5, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();


		//********Pared izquierda************		
		glPushMatrix();							//parte de hasta abajo
			glTranslatef(-12.5f, 4.5f, -2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 24.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 3.0, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de hasta arriba
			glTranslatef(-12.5f, 13.5f, -2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 3.0, 24.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 3.0, 5.0, 3.0, 0.20); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado derecho
			glTranslatef(-12.5f, 9.5f, -13.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 2.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio lado izquierdo
			glTranslatef(-12.5f, 9.5f, 8.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 2.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 0.20, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();

		glPushMatrix();							//parte de en medio
			glTranslatef(-12.5f, 9.5f, -2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 5.0, 10.0);
			prisma(t_madera2.GLindex, t_madera2.GLindex, 1.5, 5.0, 3.0, 0.4); //Estamos asignando la textura madera
		glPopMatrix();


		//********Techo************		
		glPushMatrix();
			glTranslatef(0.0f, 15.25f, 0.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(26.0, 0.5, 31.0);
			prisma(t_madera2.GLindex, t_techo.GLindex, 5.0, 3.0, 2.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Puerta************		
		glPushMatrix();
			glTranslatef(0.0f, 7.0f, 10.15f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 10.0, 0.2);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_puerta.GLindex, t_puerta.GLindex, 1.0, 1.0, 1.0, -1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 1************		
		glPushMatrix();
			glTranslatef(-9.0f, 9.5f, 10.45f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(5.0, 5.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 2************		
		glPushMatrix();
			glTranslatef(9.0f, 9.5f, 10.45f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(5.0, 5.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 3************		
		glPushMatrix();
			glTranslatef(9.0f, 9.5f, -15.45);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(5.0, 5.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 4************		
		glPushMatrix();
			glTranslatef(-9.0f, 9.5f, -15.45f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(5.0, 5.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 5************		
		glPushMatrix();
			glTranslatef(12.95f, 9.5f, 5.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 5.0, 5.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 6************		
		glPushMatrix();
			glTranslatef(-12.95f, 9.5f, 5.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 5.0, 5.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 7************		
		glPushMatrix();
			glTranslatef(12.95f, 9.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 5.0, 5.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 8************		
		glPushMatrix();
			glTranslatef(-12.95f, 9.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 5.0, 5.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Poste vertical 1************		
		glPushMatrix();
			glTranslatef(-4.75f, 8.5f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 13.0, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical 2************		
		glPushMatrix();
			glTranslatef(4.75f, 8.5f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 13.0, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 1************		
		glPushMatrix();
			glTranslatef(-12.75f, 8.5f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 13.0, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 2************		
		glPushMatrix();
			glTranslatef(-10.75f, 4.25f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 3************		
		glPushMatrix();
			glTranslatef(-8.75f, 4.25f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 4************		
		glPushMatrix();
			glTranslatef(-6.75f, 4.25f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste horizontal 1************		
		glPushMatrix();
			glTranslatef(-8.75f, 6.75f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(7.5, 0.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 11************		
		glPushMatrix();
			glTranslatef(-12.75f, 4.25f, 13.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 12************		
		glPushMatrix();
			glTranslatef(-12.75f, 4.25f, 11.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste horizontal 4************		
		glPushMatrix();
			glTranslatef(-12.75f, 6.75f, 12.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 4.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 5************		
		glPushMatrix();
			glTranslatef(6.75f, 4.25f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 6************		
		glPushMatrix();
			glTranslatef(8.75f, 4.25f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 7************		
		glPushMatrix();
			glTranslatef(10.75f, 4.25f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 8************		
		glPushMatrix();
			glTranslatef(12.75f, 8.5f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 13.0, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste horizontal 2************		
		glPushMatrix();
			glTranslatef(8.75f, 6.75f, 15.25f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(7.5, 0.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 9************		
		glPushMatrix();
			glTranslatef(12.75f, 4.25f, 13.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste vertical chiquito 10************		
		glPushMatrix();
			glTranslatef(12.75f, 4.25f, 11.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 4.5, 0.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Poste horizontal 3************		
		glPushMatrix();
			glTranslatef(12.75f, 6.75f, 12.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 4.5);
			prisma(t_madera.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();
		

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 'u':
		case 'U':
			pos_camY += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'i':
		case 'I':
			pos_camY -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}