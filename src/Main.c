#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Rope.h"

Rope rope;
Particle* selected;

void Setup(AlxWindow* w){
    rope = Rope_New(
        (Vec2){ 0.0f,0.0f },
        (Vec2){ 0.0f,10.0f },
        20,
        0.1f,
        100.0f
    );
}
void Update(AlxWindow* w){
    TransformedView_HandlePanZoom(&rope.tv,w->Strokes,GetMouse());
    const Vec2 m = TransformedView_ScreenWorldPos(&rope.tv,GetMouse());

    if(Stroke(ALX_MOUSE_L).PRESSED){
        selected = Rope_Interact(&rope,m);
    }else if(Stroke(ALX_MOUSE_L).DOWN){
        if(selected){
            selected->pos = m;
            selected->vel = (Vec2){ 0.0f,0.0f };
        }
    }else if(Stroke(ALX_MOUSE_L).RELEASED){
        selected = NULL;
    }

    Rope_Update(&rope,w->ElapsedTime);

    Clear(BLACK);

    Rope_Render(&rope,WINDOW_STD_ARGS);
}
void Delete(AlxWindow* w){
    Rope_Free(&rope);
}

int main() {
    if(Create("Rope",1900,1000,1,1,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
