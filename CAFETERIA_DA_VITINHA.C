#include "raylib.h"

typedef enum {
    HOME,
    MENU,
    TELA1,
    TELA2,
    TELA3,
    FIM
} GameState;

GameState gameState = HOME;

void Cabeçalho() {
   
    BeginDrawing();
    ClearBackground(RAYWHITE);

        DrawText("Voce escolheu o", 60, 80, 19, DARKGRAY);
        if (gameState = TELA1){
            DrawText("Expresso!", 60, 100, 19, DARKGRAY);
        }else if (gameState = TELA2){
            DrawText("Capuccino!", 60, 100, 19, DARKGRAY);
        }else if (gameState = TELA3){
            DrawText("Moccachino!", 60, 100, 19, DARKGRAY);
        }

    EndDrawing();
}


int main(void) {
    InitWindow(400, 400, "Cafeteria da vitinha");

    Vector2 recPosi = {140, 170};
    Vector2 recSize = {120, 60};
    Vector2 mousePosition = {0};

    GameState gameState = HOME;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        mousePosition = GetMousePosition();

        switch (gameState) {
            case HOME:
            
                BeginDrawing();
                
    ClearBackground(RAYWHITE);

        DrawText("Seja muito bem-vindo à Cafeteria da Vitinha", 14, 60, 19, DARKGRAY);
        DrawText("Vamos começar a preparar seu café?", 5, 90, 20, DARKGRAY);
        DrawRectangleV(recPosi, recSize, BROWN);
        DrawText("START", 165, 190, 20, WHITE);
    
    EndDrawing();

                if (CheckCollisionPointRec(mousePosition, (Rectangle){recPosi.x, recPosi.y, recSize.x, recSize.y})) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        gameState = MENU;
                    }
                }
                break;

            case MENU:
            
            BeginDrawing();
            ClearBackground(RAYWHITE);
            
                DrawText("DIGITE A LETRA DO CAFÉ QUE VOCÊ DESEJA\n(A) expresso\n(B) capuccino\n(C) moccachino\n(Z) SAIR DO PROGRAMA\n(M) MENU", 60, 60, 19, DARKGRAY);
                
                EndDrawing();
                
                 if (IsKeyPressed(KEY_A)) {
                    gameState = TELA1;
                } else if (IsKeyPressed(KEY_B)) {
                    gameState = TELA2;
                } else if (IsKeyPressed(KEY_C)) {
                    gameState = TELA3;
                } else if (IsKeyPressed(KEY_Z)) {
                    gameState = FIM;
                } else if (IsKeyPressed(KEY_M)) {
                    gameState = MENU;
                }
                
                break;

            case TELA1:
            
            Cabeçalho();
           
                break;

            case TELA2:
            
            Cabeçalho();
            
                break;

            case TELA3:
           
            Cabeçalho();
            
                break;

            case FIM:
            
            BeginDrawing();
    ClearBackground(RAYWHITE);

        DrawText("Obrigada por usar o programa!", 60, 60, 19, DARKGRAY);
        DrawText("Volte sempre!", 120, 90, 20, DARKGRAY);

    EndDrawing();
                break;
        }
        if (IsKeyPressed(KEY_Z)) {
                    gameState = FIM;
                } else if (IsKeyPressed(KEY_M)) {
                    gameState = MENU;
                }
    }
    

    CloseWindow();

    return 0;
}

