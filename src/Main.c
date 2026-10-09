#include "/home/codeleaded/System/Static/Library/WindowEngine.h"
#include "/home/codeleaded/System/Static/Library/Elastic.h"

Elastic env;
Elastic_Particle* selected;

void Setup(AlxWindow* w){
    env = Elastic_New((Vec2){ 0.0f,0.0f });

    //Elastic_Add(
    //    &env,
    //    (Elastic_Rope[]){ Elastic_Rope_New(
    //        (Vec2){ 0.0f,0.0f },
    //        1000,
    //        0.1f,
    //        100.0f
    //    )},
    //    sizeof(Elastic_Rope)
    //);

    Elastic_Add(
        &env,
        (Elastic_Shape[]){ Elastic_Rect_New(
            (Vec2){ 0.0f,0.0f },
            150,
            150,
            0.1f,
            100.0f
        )},
        sizeof(Elastic_Shape)
    );
}
void Update(AlxWindow* w){
    TransformedView_HandlePanZoom(&env.tv,w->Strokes,GetMouse());
    const Vec2 m = TransformedView_ScreenWorldPos(&env.tv,GetMouse());

    if(Stroke(ALX_MOUSE_L).PRESSED){
        selected = Elastic_Interact(&env,m);
    }else if(Stroke(ALX_MOUSE_L).DOWN){
        if(selected){
            selected->pos = m;
            selected->vel = (Vec2){ 0.0f,0.0f };
        }
    }else if(Stroke(ALX_MOUSE_L).RELEASED){
        selected = NULL;
    }
    
    if(Stroke(ALX_MOUSE_R).PRESSED){
        Elastic_Particle* found = Elastic_Interact(&env,m);
        if(found){
            found->fixed = !found->fixed;
        }
    }

    Elastic_Update(&env,F32_Min(w->ElapsedTime,0.5f));

    Clear(BLACK);

    Elastic_Render(&env,WINDOW_STD_ARGS);
}
void Delete(AlxWindow* w){
    Elastic_Free(&env);
}

int main() {
    if(Create("Elastic Simulation",1900,1000,1,1,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
