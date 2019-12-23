#include <GL/glut.h>
#include <math.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // สีพื้นหลัง
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // กำหนดขอบเขคจอขนาด -10 ถึง 10
}

void draw(void)
{
	const double PI = 3.14159;
	for (int j = 0; j < 100; j++) { // วาดวงกลม 3 วง
		double r = (rand() % 200 + 1.0)/100; // สุ่มขนาดรัศมี r [0.01,2]
		double x0 = rand() % 17 - 8.0; // สุ่มจุดกำเนิด x [-8,8]
		double y0 = rand() % 17 - 8.0; // สุ่มจุดกำเนิด y [-8,8]

		double R = rand() % 101 / 100.0;
		double G = rand() % 101 / 100.0;
		double B = rand() % 101 / 100.0;
		glColor3f(R, G, B); // สุ่มสีเส้น

		glBegin(GL_POLYGON);
		for (int i = 1; i < 360; i++) { // วาดวงกลม
			glVertex2f(x0 + r*cos(i*PI/180.0), y0 + r*sin(i*PI/180.0));
			//glVertex2f(x0 + r*cos((i + 1)*PI/180.0), y0 + r*sin((i + 1)*PI/180.0));
		}
		glEnd();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Test OpenGL");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}