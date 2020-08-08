//game make by HerooNAB
/******************************************/
#include "Dependencies/freeglut/glut.h"
#include "cmath"
#include "cstdlib"
#include "iostream"
#include "string"
#include "ctime"

using namespace std;
int fruittini;
int counter = 1;
const float DT = 0.03;
int x = 0; 
int y = 0;
bool down = false;
unsigned char key;
char press;


float sqr(float x)
{
	return x * x;
}

struct P
{
	P() : z(0), vz(0) {}
	float x;
	float y;
	float z;
	float vz;
	int g; 
};

struct box 
{
	float x[2];
	float y[2];
	float z[2];
	float vz;
	box () 
	{
	}
};
struct rott
{
	char j, k, l, i;
};

struct release
{
	char a, s, d, w, j, k, l, i;
};


release relaese;
const int N = 20;
rott rot;
box b[400];
box fruit[1];
P p[N][N];
P back[N][N];
int dif = 200;
int n = 0;
void drawBox(box b) {
	glBegin(GL_QUADS);
	glVertex3f(b.x[0], b.y[0], b.z[0]);
	glVertex3f(b.x[1], b.y[0], b.z[0]);
	glVertex3f(b.x[1], b.y[1], b.z[0]);
	glVertex3f(b.x[0], b.y[1], b.z[0]);
	glEnd();
}
void drawCube(box *b, int i) {
	if (b[i].vz != 1)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.6f, 0.0f, 0.2f);
	if (i == 0 && b[i].vz != 1)
		glColor3f(0.5f, 0.7f, 0.2f);

	glBegin(GL_QUADS);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[0]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[1]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[1]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[1]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[1]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[0]);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[0]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[0]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[0]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[0]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[0]);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[1], b[i].z[1]);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[1], b[i].y[0], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[0], b[i].y[0], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[1]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[1]);
	glVertex3f(b[i].x[0], b[i].y[1], b[i].z[0]);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	for (int x = 0; x < N; ++x)
	{
		glBegin(GL_LINE_STRIP);
		for (int y = 0; y < N; ++y)
			glVertex3f(p[x][y].x, p[x][y].y, p[x][y].z * 10);
		glEnd();
	}
	for (int y = 0; y < N; ++y)
	{
		glBegin(GL_LINE_STRIP);
		for (int x = 0; x< N; ++x)
			glVertex3f(p[x][y].x, p[x][y].y, p[x][y].z * 10);
		glEnd();
	}

	if (rot.l == 'l' && relaese.l != 'i')
		glRotatef(-5, 200, 200, 0);

	for (int i = 0; i <= n; i++)
		drawCube(b, i);
	drawCube(fruit, 0);
	glutSwapBuffers();
}

string difficulty;
bool valid_move(box *b, int i) {
	float tempx1, tempy1;
	float tempx2, tempy2;
	tempx1 = b[0].x[0];
	tempx2 = b[0].x[1];
	tempy1 = b[0].y[0];
	tempy2 = b[0].y[1];

	if (relaese.a = 'a') {
		tempx1 -= 480 / N;
		tempx2 -= 480 / N;
		for (int m = 1; m < 1; m++)
		{
			if (tempx1 == b[m - 1].x[0] && tempx2 == b[m - 1].x[1] && tempy1 == b[m - 1].y[0] && tempy2 == b[m - 1].y[1]);
			return false;
		}
		return true;
	}

	if (relaese.s = 's') {
		tempy1 -= 480 / N;
		tempy2 -= 480 / N;
		for (int m = 1; m < 1; m++)
		{
			if (tempx1 == b[m - 1].x[0] && tempx2 == b[m - 1].x[1] && tempy1 == b[m - 1].y[0] && tempy2 == b[m - 1].y[1]);
			return false;
		}
		return true;
	}

	if (relaese.w = 'w') {
		tempy1 += 480 / N;
		tempy2 += 480 / N;
		for (int m = 1; m < 1; m++)
		{
			if (tempx1 == b[m - 1].x[0] && tempx2 == b[m - 1].x[1] && tempy1 == b[m - 1].y[0] && tempy2 == b[m - 1].y[1]);
			return false;
		}
		return true;
	}
}

void moveOtherCubes(box *b, int n) {
	if (n != 0) {
		for (int m = n; m>0;m--)
		{
			b[m].x[0] = b[m - 1].x[0];
			b[m].x[1] = b[m - 1].x[1];
			b[m].y[0] = b[m - 1].y[0];
			b[m].y[1] = b[m - 1].y[1];
			b[m].z[0] = b[m - 1].z[0];
			b[m].z[1] = b[m - 1].z[1];
		}
	}
}

void keyPressed(unsigned char key, int x, int y) {
	if (key == 'd' && b[1].x[0] != b[0].x[1]) {
		press = 'd';
		relaese.d = 0;
	}
	if (key == 'a' && b[1].x[1] != b[0].x[0]) {
		press = 'a';
		relaese.a = 0;
	}
	if (key == 'w' && b[1].y[0] != b[0].y[1]) {
		press = 'w';
		relaese.w = 0;
	}
	if (key == 's' && b[1].y[1] != b[0].y[0]) {
		press = 's';
		relaese.s = 0;
	}
	if (key == 'l') {
		press = 'l';
		relaese.a = 0;
	}
	if (key == 'j') {
		press = 'j';
		relaese.j = 0;
	}
	if (key == 'k') {
		press = 'k';
		relaese.k = 0;
	}
	if (key == 'i') {
		press = 'i';
		relaese.i = 0;
	}
}

void keyUp(unsigned char key, int x, int y) {}
void moveCube(box *b, int i) {
	bool ok = true;
	bool lose = false;
	if (!lose) {
		if (press == 'a' && valid_move(b, i)) {
			if (b[0].x[0] != 0) {
				moveOtherCubes(b, i);
				b[0].x[0] -= 480 / N;
				b[0].x[1] -= 480 / N;
			}
			ok = true;
		}
		if (press == 's') {
			if (b[0].y[0] != 480 / N) {
				moveOtherCubes(b, i);
				b[0].y[0] -= 480 / N;
				b[0].y[1] -= 480 / N;
			}
		}
		if (press == 'd') {
			if (b[0].x[0] != (N-2)*480 / N) {
				moveOtherCubes(b, i);
				b[0].x[0] += 480 / N;
				b[0].x[1] += 480 / N;
			}
		}
		if (press == 'w') {
			if (b[0].y[0] != (N - 1) * 480 / N) {
				moveOtherCubes(b, i);
				b[0].y[0] += 480 / N;
				b[0].y[1] += 480 / N;
			}
		}
	}
}

void checkFruit(box *b) {
	if (b[0].x[0] == fruit[0].x[0] && b[0].x[1] == fruit[0].x[1] && b[0].y[0] == fruit[0].y[0] && b[0].y[1] == fruit[0].y[1]) {
		n++;
		system("cls");
		cout << "			\n\n\n\n\n\n\n\n\n\n\n\n\n\n Your Score: " << 100 * n << "				Difficulty: " << difficulty << endl;
		fruittini = rand() % 17 + 1;
		fruit[0].x[0] = fruittini * 480 / N;
		fruit[0].x[1] = (fruittini +1) * 480 / N;

		fruit[0].y[0] = fruittini * 480 / N;
		fruit[0].y[1] = (fruittini + 1) * 480 / N;

		fruit[0].z[0] = 0 * 480 / N;
		fruit[0].z[1] = 1 * 480 / N;

		fruit[0].vz = 1;
	}
}

void timer(int = 0) {
	moveCube(b, n);

	display();

	checkFruit(b);
	glutTimerFunc(dif, timer, 0);
}

void mouse(int button, int state, int ax, int ay) {
	x = ax;
	y = ay;
	down = state == GLUT_DOWN;
}

void motion(int ax, int ay) {
	x = ax;
	y = ay;
}
int main(int argc, char **argv) 
{
	srand(time(0));
	fruittini = rand() % 100;
	while (fruittini > 19)
		fruittini /= 2;

	b[0].x[0] = counter * 480 / N;
	b[0].x[1] = (counter + 1) * 480 / N;

	b[0].y[0] = counter * 480 / N;
	b[0].y[1] = (counter + 1) * 480 / N;

	b[0].z[0] = 0 * 480 / N;
	b[0].z[1] = 1 * 480 / N;

	b[0].vz = 0;

	fruit[0].x[0] = fruittini * 480 / N;
	fruit[0].x[1] = (fruittini + 1) * 480 / N;

	fruit[0].y[0] = fruittini * 480 / N;
	fruit[0].y[1] = (fruittini + 1) * 480 / N;

	fruit[0].z[0] = 0 * 480 / N;
	fruit[0].z[1] = 1 * 480 / N;

	fruit[0].vz = 1;

for (int x = 0; x < N; ++x)
	for (int y = 0; y < N; ++y) 
	{
		p[x][y].x = x * 480 / N;
		p[x][y].y = (y + 1) * 480 / N;
		p[x][y].vz = rand() % 480 / 100.0 - 2.4;
		p[x][y].g = 0;

		back[x][y].x = x * 480 / N;
		back[x][y].y = y * 480 / N;
		back[x][y].z = y * 480 / N;
		back[x][y].vz = rand() % 480 / 100.0 - 2.4;
		back[x][y].g = 0;
	}
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(852, 480);
glutInitWindowPosition(700, 450);
cout << "Welcome to Snake Game make by HerooNAB!" << endl << endl;
system("PAUSE");
Menu: 
system("cls");
cout << "Main Menu: " << endl << endl;
cout << "1 - Start Game" << endl;
cout << "2 - Chose Difficulty" << endl;
cout << "3 - High Scores" << endl;
int Answer;
cout << "Your Choose: ";
cin >> Answer;
switch (Answer) {
	case 1: break;
	case 2: 
		system("cls");
		cout << "1 - Easy" << endl;
		cout << "2 - Medium" << endl;
		cout << "3 - Hard" << endl;
		cin >> Answer;
		switch (Answer) {
			case 1: dif = 350;
				goto Menu;
				break;
			case 2:
				dif = 300;
				goto Menu;
				break;
			case 3:
				dif = 100;
				goto Menu;
				break;
			case 5:
				goto Menu;
				break;
		}
	case 3: system("cls");
		cout << "HighScores: " << endl;
		break;
	}
if (dif == 100)
	difficulty = "Hard";
if (dif == 300)
	difficulty = "Medium";;
if (dif == 350)
	difficulty = "Easy";

system("cls");
cout << "			\n\n\n\n\n\n\n\n\n\n\n\n\n\n Your Score: " << 0 << "				Difficulty: " << difficulty << endl;
glutCreateWindow("HerooNAB Snake Game!");
glClearColor(0, 0, 0, 1.0);
glShadeModel(GL_SMOOTH);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-100, 100, -100, 100, 100, 2000);
glMatrixMode(GL_MODELVIEW);
glTranslatef(-240, -150, -220);
glRotatef(-30, 1, 0, 0);

glutDisplayFunc(display);
timer();
glutKeyboardFunc(keyPressed);
glutKeyboardUpFunc(keyUp);
glutPassiveMotionFunc(motion);
glutMainLoop();
goto Menu;
}