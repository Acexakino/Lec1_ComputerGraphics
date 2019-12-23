#include <GL/glut.h>
#include <math.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // สีพื้นหลัง
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // กำหนดขอบเขคจอขนาด -10 ถึง 10
}

void draw(void)
{
	for (int j = 0; j < 3; j++) { // วาดวงกลม 3 วง
		double r = rand() % 5 + 1.0; // สุ่มขนาดรัศมี r [1,5]
		double x0 = rand() % 11 - 5.0; // สุ่มจุดกำเนิด x [-5,5]
		double y0 = rand() % 11 - 5.0; // สุ่มจุดกำเนิด y [-5,5]

		double R = rand() % 101 / 100.0;
		double G = rand() % 101 / 100.0;
		double B = rand() % 101 / 100.0;
		glColor3f(R, G, B); // สุ่มสีเส้น

		for (int i = 1; i < 360; i++) { // วาดวงกลม
			glBegin(GL_LINE_STRIP);
			glVertex2f(x0 + r*cos(i), y0 + r*sin(i));
			glVertex2f(x0 + r*cos(i + 1), y0 + r*sin(i + 1));
			glEnd();
		}
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