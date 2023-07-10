#include "raylib.h"


/*logica das telas
logica dos passos
desenhos etc*/

typedef enum {
    HOME,
    MENU,
    TELABASE,
    TELABOTAO,
    TELAFINAL,
    FIM
} Telas;

Telas tela = HOME;

void Cabeçalho(char tipoCafe[]);
void SetasNav();
int SetasInt();
int BotaoInt();
void Passos();
void PrintCafeteira(bool encher);
void PrintColher();
void PrintCopo(bool esvaziar);
void PrintLeite();
void PrintChocolate();
void PrintLeiteChocolate();
void PrintMocaccino();
void PrintCapuccino();
void PrintXicara();
void PrintCafeteiraZoom();
void PrintCafeteiraCompleta(bool despejar);
void TelaFinal();

Vector2 setaE[3] = {{60,25},{15,40}, {60, 55}};
Vector2 setaD[3] = {{390,40},{345,25}, {345, 55}};
Vector2 mousePosition = {0};
Vector2 centro = {200, 275};

int setaPressionada;
int passo = 1;
int indexCafe; //0 - expresso, 1 - capuccino, 2  mocaccino
float alturaA = 80, posYA = 219;
float alturaC = 0, posYC = 300; //altura maxima = 60, pos final = 239
float alturaCP = 0;

int main(void) {
    InitWindow(400, 400, "Cafeteria da vitinha");

    Vector2 recPosiStart = {140, 170};
    Vector2 recSizeStart = {120, 60};
    
    SetTargetFPS(60);
    
    char tipoCafe[3][32] = {"Expresso!", "Capuccino!", "Moccachino!"};
    
    while (!WindowShouldClose()) {
        mousePosition = GetMousePosition();
        
        switch (tela) {
            case HOME:
            
                BeginDrawing();
                
                ClearBackground(RAYWHITE);

                DrawText("Seja muito bem-vindo à Cafeteria da Vitinha", 14, 60, 19, DARKGRAY);
                DrawText("Vamos começar a preparar seu café?", 5, 90, 20, DARKGRAY);
                DrawRectangleV(recPosiStart, recSizeStart, BROWN);
                DrawText("START", 165, 190, 20, WHITE);
            
                EndDrawing();

                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    if (CheckCollisionPointRec(mousePosition, (Rectangle){recPosiStart.x, recPosiStart.y, recSizeStart.x, recSizeStart.y})) {
                        tela = MENU;
                    }
                }
                break;

            case MENU:
            
                BeginDrawing();
                ClearBackground(RAYWHITE);
            
                DrawText("DIGITE A LETRA DO CAFÉ QUE\n VOCÊ DESEJA\n\n(A) expresso\n(B) capuccino\n(C) moccachino\n(Z) SAIR DO PROGRAMA\n(M) MENU", 60, 60, 19, DARKGRAY);
                
                EndDrawing();
                
                 if (IsKeyPressed(KEY_A)) {
                    tela = TELABASE;
                    indexCafe = 0;
                } else if (IsKeyPressed(KEY_B)) {
                    tela = TELABASE;
                    indexCafe = 1;
                } else if (IsKeyPressed(KEY_C)) {
                    tela = TELABASE;
                    indexCafe = 2;
                } else if (IsKeyPressed(KEY_Z)) {
                    tela = FIM;
                } else if (IsKeyPressed(KEY_M)) {
                    tela = MENU;
                }
                
                break;

            case TELABASE:
                BeginDrawing();
                Cabeçalho(tipoCafe[indexCafe]);
                Passos();
                EndDrawing();
                break;
            
            case TELABOTAO:
                BeginDrawing();
                Passos();
                EndDrawing();
                break;
                
            case TELAFINAL:
                BeginDrawing();
                SetasNav();
                Passos();
                EndDrawing();
                break;
                            
            case FIM:
            
                BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawText("Obrigada por usar o programa!", 60, 60, 19, DARKGRAY);
                DrawText("Volte sempre!", 120, 90, 20, DARKGRAY);

                EndDrawing();
                break;
        }
        
        setaPressionada = SetasInt();
        if(setaPressionada){
            alturaA = 80;
            posYA = 219;
           if(setaPressionada == 1){
                if(!(--passo)){
                    passo = 1;
                }
                if(passo == 4){
                    passo--;
                }
            }
            else if(setaPressionada == 2){
                if(++passo > 9){
                    passo = 9;
                }
            }        
        }

        if (IsKeyPressed(KEY_Z)) {
            tela = FIM;
        } else if (IsKeyPressed(KEY_M)) {
            tela = MENU;
            passo = 1;
            alturaC = 0;
            posYC = 300;
        }
    }
    

    CloseWindow();

    return 0;
}


void Cabeçalho(char tipoCafe[]){
    ClearBackground(RAYWHITE);

    DrawText("Voce escolheu o ", 80, 30, 19, DARKGRAY);
    DrawText(tipoCafe, 235, 30, 19, DARKGRAY);
    SetasNav();
}

void SetasNav(){
    DrawTriangle(setaE[0], setaE[1], setaE[2], BROWN);
    DrawTriangle(setaD[0], setaD[1], setaD[2], BROWN);
}

int SetasInt(){
    mousePosition = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointTriangle(mousePosition, setaE[0], setaE[1], setaE[2])){
            return 1;
        }
        else if(CheckCollisionPointTriangle(mousePosition, setaD[0], setaD[1], setaD[2])){
            return 2;
        }
    }
    return 0;
}

void Passos(){
    switch(passo){
        case 1:
            PrintCafeteira(0);
            DrawText("1. Pegue a cafeteira elétrica", 30, 70, 19, DARKGRAY);
        break;
        case 2:
            alturaC = 0;
            posYC = 300;
            PrintCafeteira(0);
            PrintColher();
            DrawText("2. Adicione um novo filtro e coloque\nseu pó de café;", 30, 70, 19, DARKGRAY);
        break;
        case 3:
            PrintCafeteira(1);
            PrintCopo(1);
            DrawText("3. Coloque um copo de água na cafeteira", 30, 70, 19, DARKGRAY);
        break;
        case 4:
            tela = TELABOTAO;
            ClearBackground(RAYWHITE);
            alturaC = 60;
            posYC = 300;
            PrintCafeteiraZoom();
            if(BotaoInt()){
                passo++;
            }
        break;
        case 5:
            tela = TELABASE;
            ClearBackground(RAYWHITE);
            DrawText("4. Após ligar a cafeteira Aguarde seu\ncafé ficar pronto...", 30, 70, 19, DARKGRAY);
            PrintCafeteiraCompleta(1);
        break;
        case 6:
            if(indexCafe == 0){
                TelaFinal();
            }
            else if(indexCafe == 1){
               tela = TELABASE;
               PrintLeite();
               DrawText("5. Vaporize Um copo de leite", 30, 70, 19, DARKGRAY);
            }
            else{
                tela = TELABASE;
                DrawText("5. Misture água quente e chocolate\naté dissolver", 30, 70, 19, DARKGRAY);
                PrintChocolate();
            }
        break;
        case 7:
            ClearBackground(RAYWHITE);
            if(indexCafe == 0){
                passo--;
            }
            if(indexCafe == 1){
                DrawText("6. Finalize colocando o leite no café\nexpresso", 30, 70, 19, DARKGRAY);
                PrintCapuccino();
            }
            else{
                DrawText("6. Vaporize Leite e adcione ao seu\nchocolate", 30, 70, 19, DARKGRAY);
                PrintLeiteChocolate();
            }
            break;
        case 8:
            ClearBackground(RAYWHITE);
            if(indexCafe == 1){
                TelaFinal();
            }
            else{
                DrawText("7. Finalize colocando o café expresso", 30, 70, 19, DARKGRAY);
                PrintMocaccino();
            }
            break;
        case 9:
            if(indexCafe == 1){
                passo--;
            }
            else{
                TelaFinal();
            }
            break;
    }
}

void PrintCafeteira(bool encher){        
    DrawCircleSector((Vector2){140, 200}, 60, 270, 90, 90, RED);
    DrawCircle(160, 170, 7, GRAY);
    DrawCircleLines(160, 170, 5, BLACK);
    DrawRectangle(159, 164, 2, 7, BLACK);
    DrawRectangle(80, 200, 30, 100, BLACK);
    DrawRectangle(20, 300, 190, 50, RED);
    DrawRectangleLines(20, 200, 60, 100, RED);
    DrawRectangle(21, posYC, 58, alturaC, DARKBROWN);
    if(encher && posYC > 239){
        alturaC += 0.5;
        posYC -= 0.5;
    }
}

void PrintColher(){
     //vetores para o triangulo
    Vector2 v1 = { 260, 135 };
    Vector2 v2 = { 240, 150 };
    Vector2 v3 = { 280, 150 };
                
    //colher:
    //triangulo e seus vetores:
    DrawTriangle(v1, v2, v3, DARKBROWN);
    DrawCircleSector((Vector2){260, 150}, 30, 270, 450, 90, GRAY);
    DrawRectangle(280, 150, 100, 10, GRAY);
}

void PrintCopo(bool esvaziar){
   // copo de agua:
    DrawRectangleLines(290, 200, 50, 100, GRAY);
    DrawRectangle(291,posYA, 48, alturaA, SKYBLUE);
    if(esvaziar){
        alturaA -= 0.5;
        posYA += 0.5;
    }
}

void PrintLeite(){
    DrawRectangleLines(290, 200, 50, 100, GRAY);
    DrawRectangle(291,259, 48, 40, WHITE);
}

void PrintChocolate(){
    DrawRectangleLines(290, 200, 50, 100, GRAY);
    DrawRectangle(291,279, 48, 20, BROWN);
}

void PrintLeiteChocolate(){
    DrawRectangleLines(290, 200, 50, 100, GRAY);
    DrawRectangle(291,279, 48, 20, BROWN);    
    DrawRectangle(291,239, 48, 40, WHITE);
}

void PrintCapuccino(){
    DrawRectangleLines(290, 200, 50, 100, GRAY);
    DrawRectangle(291,239, 48, 20, WHITE);    
    DrawRectangle(291,259, 48, 40, DARKBROWN);
}

void PrintMocaccino(){
    DrawRectangleLines(290, 200, 50, 100, GRAY);
    DrawRectangle(291,279, 48, 20, BROWN);    
    DrawRectangle(291,239, 48, 40, WHITE);
    DrawRectangle(291,205, 48, 33, DARKBROWN);
}

void PrintXicara(){
    Vector2 centro = { 270, 239 };
        
    DrawRectangle(185, 120, 5, 60, (Color){ 200, 200, 200, 255 });
    DrawRectangle(215, 145, 5, 40, (Color){ 200, 200, 200, 255 });
    DrawRectangle(155, 150, 5, 40, (Color){ 200, 200, 200, 255 });
    DrawRing(centro, 30, 40, 0, 360, 360, (Color){ 255, 182, 193, 255 });
    DrawCircleSector((Vector2){190, 200}, 90, 270, 450, 90, (Color){ 255, 182, 193, 255 });
}

void PrintCafeteiraZoom(){
    DrawCircleSector((Vector2){100, 300}, 300, 270, 90, 90, RED);
    DrawCircle(200, 190, 47, GRAY);
    DrawCircleLines(200, 190, 35, BLACK);
    DrawRectangle(195, 150, 10, 45, BLACK);
}

void PrintCafeteiraCompleta(bool despejar){
    alturaC = 60;
    posYC = 239;
    PrintCafeteira(0);
    DrawCircle(160, 170, 7, GREEN);
    DrawCircleLines(160, 170, 5, BLACK);
    DrawRectangle(159, 164, 2, 7, BLACK);
    DrawRing(centro, 10, 15, 0, 360, 360, (Color){ 255, 182, 193, 255 });
    DrawCircleSector((Vector2){160, 260}, 40, 270, 450, 90, (Color){ 255, 182, 193, 255 });
    DrawRectangle(155, 200, 8, alturaCP, DARKBROWN);
    if(despejar && alturaCP < 60){
        alturaCP += 1;
    }
}
int BotaoInt(){
    mousePosition = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointCircle(mousePosition,(Vector2){100,300},300)){
            return 1;
        }
    }
    return 0;
}
void TelaFinal(){
    tela = TELAFINAL;
    ClearBackground(RAYWHITE);
    DrawText("Aproveite seu café :)", 30, 70, 19, DARKGRAY);
    PrintXicara();
}