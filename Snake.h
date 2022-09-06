#include "raylib.h"
#include <vector>

class Snake
{
private:
    std::vector<Vector2> tail{};
    Rectangle data;
    KeyboardKey key;
public:
    Snake(int* window);

    float getWidth();
    float getHeight();
    Vector2 getPos_Head();
    std::vector<Vector2> getPos_Tail();
    void setKey();

    void Draw();
    void move();
    bool collision();

    void operator++ (int);
};
