#include <stdio.h>
#include <raylib.h>
#include <math.h>

float calculateXPosition(float Vx, float t) {
    return Vx * t;
}

float calculateYPosition(float Voy, float t, float g, float initialHeight) {
    return (Voy * t) - (0.5 * g * t * t);
}

float maxReach(float Vo, float angle, float g) {
    float radianAngle = angle * (PI / 180);
    return ((Vo * Vo) * sin(radianAngle * 2)) / g;
}

float maxHeight(float Voy, float g) {
    return (Voy * Voy) / (2 * g);
}

float totalTime(float Voy, float g) {
    return (2 * Voy) / g;
}

int main(void) {
    const int width = 1920;
    const int height = 1080;

    float initialVelocity;
    int angle;

    Vector2 ballPos = {20.f, height};  // Start from the ground level

    printf("Initial velocity: ");
    scanf("%f", &initialVelocity);

    printf("Angle (in degrees): ");
    scanf("%d", &angle);

    float radianAngle = angle * (PI / 180.0f);

    const float Vx = initialVelocity * cos(radianAngle);
    const float Voy = initialVelocity * sin(radianAngle);
    const float g = 9.8f;
    const float initialHeight = height;

    const float R = maxReach(initialVelocity, angle, g);
    const float T = totalTime(Voy, g);
    const float H = maxHeight(Voy, g);
    const float mToPx = 50;

    printf("Vx = %f\n", Vx);
    printf("Vy = %f\n", Voy);
    printf("Reach = %f\n", R);
    printf("Total time = %f\n", T);
    printf("Max height = %f\n", H);

    // 1m = 100px

    InitWindow(width, height, "Oblique Launch");
    SetTargetFPS(60);  // Set the frame rate

    float t = 0.0f;


    while (!WindowShouldClose()) {
        t += 0.016;

        Vector2 newBallPos;
        

        BeginDrawing();
        ClearBackground(WHITE);
        if (t < T)
        {
            newBallPos.x = calculateXPosition(Vx, t) * mToPx;
            newBallPos.y = 900 - (calculateYPosition(Voy, t, g, initialHeight) * mToPx);
        }
        if (t >= T ) {
            printf("Ball pos.x on px-> %f", newBallPos.x);
            printf("Ball pos.y on px-> %f", newBallPos.y);
        }
       
        DrawCircle((int)newBallPos.x, (int)newBallPos.y, 10, RED);

        



        DrawRectangle(0,910,width,1080-910,BLACK);
        EndDrawing();
    }
    printf("\n");
    printf("%f",  calculateYPosition(Vx, T/2, g, 1000));

    CloseWindow();
    return 0;
}
