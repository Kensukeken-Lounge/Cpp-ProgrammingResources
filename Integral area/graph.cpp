#include <GL/glut.h>

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Axis
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 5.0);
    glEnd();

    // Function
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (float x = 0.5; x <= 4.5; x += 0.01) {
        float y = 0.2 * x * x;
        glVertex2f(x, y);
    }
    glEnd();

    // Integral area
    glColor4f(1.0, 0.0, 0.0, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(1.0, 0.0);
    for (float x = 1.0; x <= 4.0; x += 0.01) {
        float y = 0.2 * x * x;
        glVertex2f(x, y);
    }
    glVertex2f(4.0, 0.0);
    glEnd();

    // Axis labels
    glColor3f(0.0, 0.0, 0.0);
    for (float x = 1.0; x <= 4.0; x += 1.0) {
        glBegin(GL_LINES);
        glVertex2f(x, -0.1);
        glVertex2f(x, 0.1);
        glEnd();
    }
    for (float y = 1.0; y <= 4.0; y += 1.0) {
        glBegin(GL_LINES);
        glVertex2f(-0.1, y);
        glVertex2f(0.1, y);
        glEnd();
    }

    // Integral notation
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(2.5, 3.0);
    const char text[] = "∫_a^b f(x) dx";
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    // Dashed lines
    glColor3f(0.0, 0.0, 0.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xAAAA);
    glBegin(GL_LINES);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 1.8);
    glVertex2f(4.0, 0.0);
    glVertex2f(4.0, 3.2);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Distance notation
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(2.5, 1.9);
    const char distance[] = "b - a";
    for (int i = 0; distance[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, distance[i]);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Integral Area");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
