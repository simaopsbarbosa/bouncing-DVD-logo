#include <iostream>
#include <raylib.h>
#include <raymath.h>

#define PIE 3.14159265

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;
Color colors[9] = { YELLOW, ORANGE, RED,
GREEN,PINK, BLUE,MAROON, PURPLE, MAGENTA };
int currentColor = 0;

void nextColor(int &currentColor) {
    if (currentColor < 8) {
        currentColor += 1;
    }
    else {
        currentColor = 0;
    }
}

class Ball {

public: 
    float x;
    float y;
    int width;
    int height;
    float angle;
    int speed;
    Color color;

    void Draw() {
        DrawRectangle(x, y, width,height,colors[currentColor]);
    }

    void Update() {
        x += cos(angle * PIE / 180.0) * speed;
        y += sin(angle * PIE / 180.0) * speed;
    }

    


    void CheckCollision() {
        if (x + width > screenWidth) {
            // hits right
            angle = 180- angle;
            nextColor(currentColor);
        }
        if (x < 0) {
            // hits left
            angle = 180 - angle;
            nextColor(currentColor);
        }
        if (y < 0) {
            // hits top
            angle = -angle;
            nextColor(currentColor);
        }
        if (y + height > screenHeight) {
            // hits bottom
            angle = -angle;
            nextColor(currentColor);
        }
    }
};

Ball player; 

int main() {

    cout << "Starting Game" << endl;
    srand(time(NULL));
    InitWindow(screenWidth, screenHeight, "Hello World!");
    SetTargetFPS(60);

    player.x = screenWidth / 2;
    player.y = screenHeight / 2;
    player.angle = rand() % 360;
    player.width = 90;
    player.height = 70;
    player.speed = 4;


    while (!WindowShouldClose()) {
        // main loop
        
        player.CheckCollision();
        player.Update();

        BeginDrawing();
            ClearBackground(BLACK);
            player.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}