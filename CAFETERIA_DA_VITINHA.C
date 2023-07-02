#include "raylib.h"

typedef enum {
    HOME,
    MENU,
    TELA1,
    TELA2,
    TELA3,
    TELA4,
    TELA5,
    FIM
} GameState;

int main(void)
{
    InitWindow(400, 400, "Cafeteria da vitinha");

    Vector2 recPosi = {140, 170};
    Vector2 recSize = {120, 60};
    Vector2 mousePosition = {0};

    GameState gameState = HOME;

    SetTargetFPS(90);

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();

        switch (gameState) {
            case HOME:
                if (CheckCollisionPointRec(mousePosition, (Rectangle){recPosi.x, recPosi.y, recSize.x, recSize.y}))
                {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        gameState = MENU;
                }
                break;
                
            case MENU:
               /* if (IsKeyPressed(KEY_A))
                    gameState = TELA1;
                else if (IsKeyPressed(KEY_B))
                    gameState = TELA2;
                else if (IsKeyPressed(KEY_C))
                    gameState = TELA3;
                else if (IsKeyPressed(KEY_D))
                    gameState = TELA4;
                else if (IsKeyPressed(KEY_E))
                    gameState = TELA5;*/
                gameState = getche();
                break;
                
            case TELA1:
                break;
                
            case TELA2:
                break;
                
            case TELA3:
                break;
                
            case TELA4:
                break;
                
            case TELA5:
                break;
                
            case FIM:
                break;
        }
        
        if (IsKeyPressed(KEY_Z))
            gameState = FIM;
        else if (IsKeyPressed(KEY_M))
                    gameState = MENU;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (gameState) {
            case HOME:
                DrawText("Seja muito bem-vindo à Cafeteria da Vitinha", 14, 60, 19, DARKGRAY);
                DrawText("Vamos começar a preparar seu café?", 5, 90, 20, DARKGRAY);
                DrawRectangleV(recPosi, recSize, BROWN);
                DrawText("START", 165, 190, 20, WHITE);
                break;
                
            case MENU:
                ClearBackground(RAYWHITE);
                DrawText("Digite a letra do cafe que voce deseja\n(A) espresso\n(B) cappuccino\n(C) Irish coffee\n(D) caffe latte\n(E) macchiato\n(Z) sair do programa\n(M) MENU", 14, 60, 19, DARKGRAY);
                break;
                
            case TELA1:
                ClearBackground(RAYWHITE);
                DrawText("VOCÊ ESCOLHEU O ESPRESSO!", 60, 60, 19, DARKGRAY);
                //DrawRectangleLines(150, 150, 100, 150, PINK);
                //DrawRectangleLines(101, 180, 50, 70, PINK);
                //DrawRectangle(151, 199, 98, 100, BROWN);
                DrawCircleSector((Vector2){100, 200}, 60, 270, 90, 90, RED); 
                //aqui eu to fazendo a cafeteira, mas esse nao é meu problema agora, entao ignore, nao mexa aqui aaaaaaaaaaaaaa!
                break;
                
            case TELA2:
                ClearBackground(RAYWHITE);
                DrawText("VOCÊ ESCOLHEU O CAPPUCCINO!", 60, 60, 19, DARKGRAY);
                DrawRectangleLines(150, 150, 100, 150, PINK);
                DrawRectangleLines(101, 180, 50, 70, PINK);
                DrawRectangle(151, 199, 98, 100, BROWN);
                break;
                
            case TELA3:
                ClearBackground(RAYWHITE);
                DrawText("VOCÊ ESCOLHEU O IRISH COFFEE!", 40, 60, 19, DARKGRAY);
                DrawRectangleLines(150, 150, 100, 150, PINK);
                DrawRectangleLines(101, 180, 50, 70, PINK);
                DrawRectangle(151, 199, 98, 100, BROWN);
                break;
                
            case TELA4:
                ClearBackground(RAYWHITE);
                DrawText("VOCÊ ESCOLHEU O COFFEE LATTE!", 40, 60, 19, DARKGRAY);
                DrawRectangleLines(150, 150, 100, 150, PINK);
                DrawRectangleLines(101, 180, 50, 70, PINK);
                DrawRectangle(151, 199, 98, 100, BROWN);
                break;
                
            case TELA5:
                ClearBackground(RAYWHITE);
                DrawText("VOCÊ ESCOLHEU O MACCHIATO!", 50, 60, 19, DARKGRAY);
                DrawRectangleLines(150, 150, 100, 150, PINK);
                DrawRectangleLines(101, 180, 50, 70, PINK);
                DrawRectangle(151, 199, 98, 100, BROWN);
                break;
                
            case FIM:
                ClearBackground(RAYWHITE);
                DrawText("APROVEITE SEU CAFÉ!", 90, 60, 19, DARKGRAY);
                DrawRectangleLines(150, 150, 100, 150, PINK);
                DrawRectangleLines(101, 180, 50, 70, PINK);
                DrawRectangle(151, 199, 98, 100, BROWN);
                break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}