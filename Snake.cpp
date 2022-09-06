#include "Snake.h"

Snake::Snake(int* window) : key(KEY_D)
{
    // Initialization data
    data.x = window[0] / 2;
    data.y = window[1] / 2;
    data.height = data.width = 20;
}

float Snake::getWidth()
{
    return data.width;
}

float Snake::getHeight()
{
    return data.height;
}

Vector2 Snake::getPos_Head()
{
    return {data.x, data.y};
}

std::vector<Vector2> Snake::getPos_Tail()
{
    return tail;
}

void Snake::setKey()
{
    // Set current move snake
    if (IsKeyDown(KEY_A) and key != KEY_D)    
        key = KEY_A;
    else if (IsKeyDown(KEY_D) and key != KEY_A)
        key = KEY_D;
    else if (IsKeyDown(KEY_W) and key != KEY_S)
        key = KEY_W;
    else if (IsKeyDown(KEY_S) and key != KEY_W)
        key = KEY_S;
}

void Snake::Draw()
{
    // Draw Snake
    DrawRectangle(data.x, data.y, data.width, data.height, RED);
    for (const auto &value : tail)
    {
        DrawRectangle(value.x, value.y, data.width, data.height, BLUE);
    }
}

void Snake::move()
{
    setKey();

    // Move pos tail
    // After that move head
    if (IsKeyDown(key) and key == KEY_A)
    {
        if (tail.size() != 0)
        {
            for (int i = tail.size() - 1; i >= 0; i--)
            {
                if (i != 0)
                {
                    tail[i].x = tail[i-1].x;
                    tail[i].y = tail[i-1].y;            
                } 
                else
                {
                    tail[i].x = data.x;
                    tail[i].y = data.y;            
                }
            }
        }        
        data.x -= data.width;
    }
    else if (IsKeyDown(key) and key == KEY_D)
    {
        if (tail.size() != 0)
        {
            for (int i = tail.size() - 1; i >= 0; i--)
            {
                if (i != 0)
                {
                    tail[i].x = tail[i-1].x;
                    tail[i].y = tail[i-1].y;            
                } 
                else
                {
                    tail[i].x = data.x;
                    tail[i].y = data.y;            
                }
            }
        }        
        data.x += data.width;
    }
    else if (IsKeyDown(key) and key == KEY_W)
    {
        if (tail.size() != 0)
        {
            for (int i = tail.size() - 1; i >= 0; i--)
            {
                if (i != 0)
                {
                    tail[i].x = tail[i-1].x;
                    tail[i].y = tail[i-1].y;            
                } 
                else
                {
                    tail[i].x = data.x;
                    tail[i].y = data.y;            
                }
            }
        }        
        data.y -= data.height;
    }
    else if (IsKeyDown(key) and key == KEY_S)
    {
        if (tail.size() != 0)
        {
            for (int i = tail.size() - 1; i >= 0; i--)
            {
                if (i != 0)
                {
                    tail[i].x = tail[i-1].x;
                    tail[i].y = tail[i-1].y;            
                } 
                else
                {
                    tail[i].x = data.x;
                    tail[i].y = data.y;            
                }
            }
        }        
        data.y += data.height;
    }
    else
    {
        switch (key)
        {
        case KEY_A: 
            if (tail.size() != 0)
            {
                for (int i = tail.size() - 1; i >= 0; i--)
                {
                    if (i != 0)
                    {
                        tail[i].x = tail[i-1].x;
                        tail[i].y = tail[i-1].y;            
                    } 
                    else
                    {
                        tail[i].x = data.x;
                        tail[i].y = data.y;            
                    }
                }
            }        
            data.x -= data.width;        
        break;
        case KEY_D: 
            if (tail.size() != 0)
            {
                for (int i = tail.size() - 1; i >= 0; i--)
                {
                    if (i != 0)
                    {
                        tail[i].x = tail[i-1].x;
                        tail[i].y = tail[i-1].y;            
                    } 
                    else
                    {
                        tail[i].x = data.x;
                        tail[i].y = data.y;            
                    }
                }
            }        
            data.x += data.width;        
        break;
        case KEY_W: 
            if (tail.size() != 0)
            {
                for (int i = tail.size() - 1; i >= 0; i--)
                {
                    if (i != 0)
                    {
                        tail[i].x = tail[i-1].x;
                        tail[i].y = tail[i-1].y;            
                    } 
                    else
                    {
                        tail[i].x = data.x;
                        tail[i].y = data.y;            
                    }
                }
            }        
            data.y -= data.height;        
        break;
        case KEY_S: 
            if (tail.size() != 0)
            {
                for (int i = tail.size() - 1; i >= 0; i--)
                {
                    if (i != 0)
                    {
                        tail[i].x = tail[i-1].x;
                        tail[i].y = tail[i-1].y;            
                    } 
                    else
                    {
                        tail[i].x = data.x;
                        tail[i].y = data.y;            
                    }
                }
            }        
            data.y += data.height;        
        break;

        default:
            break;
        }
    }
}

bool Snake::collision()
{
    // find out if your head touches your tail
    for (auto &value : tail)
    {
        if (value.x == data.x
            && value.y == data.y)
        {
            return true;
        }
    }
    return false;
}

void Snake::operator++ (int)
{
    // Add tail
    if (tail.size() == 0)
        tail.push_back({data.x, data.y});
    else
        tail.push_back({tail[tail.size() - 1].x, tail[tail.size() - 1].y});
}