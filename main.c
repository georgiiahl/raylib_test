#include "raylib.h"

int main()
{

    const int screenWidth = 360;
    const int screenHeight = 760;

    InitWindow(screenWidth, screenHeight, "Vertical Raylib Pong");


    Rectangle playerPaddle = {screenWidth / 2 - 50, screenHeight - 20, 100, 10};
    Rectangle aiPaddle = {screenWidth / 2 - 50, 10, 100, 10};
    int paddleSpeed = 200;


    Vector2 ballPosition = {screenWidth / 2, screenHeight / 2};
    Vector2 ballSpeed = {0, -300};
    int ballSize = 10;

    // Score
    int playerScore = 0;
    int aiScore = 0;

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

        float dt = GetFrameTime();


        if (IsKeyDown(KEY_LEFT) && playerPaddle.x >= 0)
        {
            playerPaddle.x -= paddleSpeed * dt;
        }
        if (IsKeyDown(KEY_RIGHT) && playerPaddle.x <= screenWidth - playerPaddle.width)
        {
            playerPaddle.x += paddleSpeed * dt;
        }

        if (aiPaddle.x + aiPaddle.width / 2 < ballPosition.x)
        {
            aiPaddle.x += paddleSpeed * dt;
        }
        if (aiPaddle.x + aiPaddle.width / 2 > ballPosition.x)
        {
            aiPaddle.x -= paddleSpeed * dt;
        }

        ballPosition.x += ballSpeed.x * dt;
        ballPosition.y += ballSpeed.y * dt;

        if (ballPosition.x <= 0 || ballPosition.x >= screenWidth)
        {
            ballSpeed.x *= -1;
        }

        if (CheckCollisionCircleRec(ballPosition, ballSize, playerPaddle) ||
            CheckCollisionCircleRec(ballPosition, ballSize, aiPaddle))
        {
            ballSpeed.y *= -1;
        }

        if (ballPosition.x < 0)
        {
            aiScore++;
            ballPosition.x = screenWidth / 2;  // Reset ball x position
            ballPosition.y = screenHeight / 2; // Reset ball y position
            ballSpeed.x = 300;                 // Reset ball x speed
            ballSpeed.y = 300;                 // Reset ball y speed
        }
        if (ballPosition.x > screenWidth)
        {
            playerScore++;
            ballPosition.x = screenWidth / 2;  // Reset ball x position
            ballPosition.y = screenHeight / 2; // Reset ball y position
            ballSpeed.x = -300;                // Reset ball x speed to move in opposite direction
            ballSpeed.y = 300;                 // Reset ball y speed
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(TextFormat("Player: %d", playerScore), 10, screenHeight - 30, 20, DARKGRAY);
        DrawText(TextFormat("AI: %d", aiScore), screenWidth - MeasureText(TextFormat("AI: %d", aiScore), 20) - 10, 10, 20, DARKGRAY);
        DrawRectangleRec(playerPaddle, BLACK);
        DrawRectangleRec(aiPaddle, BLACK);
        DrawCircleV(ballPosition, ballSize, DARKBLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
