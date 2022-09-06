#include "Snake.h"
#include <string>
#include <random>

Vector2 Generate_Bonus(const Vector2&& player_pos, 
            const std::vector<Vector2>&& tail_pos, const int* window)
{
    Vector2 pos_bonus{(rand() % window[0]), (rand() % window[1])};

    while (!((static_cast<int>(pos_bonus.x) % 20) == 10 
            && (static_cast<int>(pos_bonus.y) % 20) == 10))
    {
        pos_bonus = {static_cast<float>(rand() % window[0]), static_cast<float>(rand() % window[1])};
        pos_bonus.x -= static_cast<int>(pos_bonus.x) % 10;
        pos_bonus.y -= static_cast<int>(pos_bonus.y) % 10;
    }
    
    if (tail_pos.size() != 0)
    {
        for (int i = 0; i < tail_pos.size(); i++)
        {
            if (i != 0)
            {
                if (pos_bonus.x == tail_pos[i].x
                    && pos_bonus.y == tail_pos[i].y)
                {
                    pos_bonus = {static_cast<float>(rand() % window[0]), static_cast<float>(rand() % window[1])};
                    pos_bonus.x -= static_cast<int>(pos_bonus.x) % 10;
                    pos_bonus.y -= static_cast<int>(pos_bonus.y) % 10;
                    i = -1;
                    continue;
                }         
            }
            else
            {
                if (pos_bonus.x == player_pos.x
                    && pos_bonus.y == player_pos.y
                    && (static_cast<int>(pos_bonus.x) % 20) == 10 
                    && (static_cast<int>(pos_bonus.y) % 20) == 10)
                {
                    pos_bonus = {static_cast<float>(rand() % window[0]), static_cast<float>(rand() % window[1])};
                    pos_bonus.x -= static_cast<int>(pos_bonus.x) % 10;
                    pos_bonus.y -= static_cast<int>(pos_bonus.y) % 10;
                    i = -1;
                    continue;
                }
                
                if (pos_bonus.x == tail_pos[i].x
                    && pos_bonus.y == tail_pos[i].y)
                {
                    pos_bonus = {static_cast<float>(rand() % window[0]), static_cast<float>(rand() % window[1])};
                    pos_bonus.x -= static_cast<int>(pos_bonus.x) % 10;
                    pos_bonus.y -= static_cast<int>(pos_bonus.y) % 10;
                    i = -1;
                    continue;
                }            
            }
        }
    }
    return pos_bonus;
}

int main(void)
{
    srand(time(NULL));
    // Window dimension
    int window_dimensions[2]{1200, 600};

    // Initialization Window
    InitWindow(window_dimensions[0], window_dimensions[1], "Snake");

    // Player
    Snake player{window_dimensions};

    Vector2 bonus{
        Generate_Bonus(std::move(player.getPos_Head()), 
            std::move(player.getPos_Tail()),
            window_dimensions)
    };

    bool end_game{};

    SetTargetFPS(5);
    while (!WindowShouldClose())
    {
        // Start drawing
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        // Function Game
        if (!end_game)
        {
            // Move Player
            player.move();

            // Detect window frame and player's tail which of them touches to head | true | false |
            end_game = player.collision() 
                || player.getPos_Head().x <= 0 || player.getPos_Head().x >= window_dimensions[0]
                || player.getPos_Head().y <= 0 || player.getPos_Head().y >= window_dimensions[1];

            if (player.getPos_Head().x <= bonus.x && bonus.x <= player.getPos_Head().x + player.getWidth()
                && player.getPos_Head().y <= bonus.y && bonus.y <= player.getPos_Head().y + player.getHeight())
            {
                player++;
                bonus = Generate_Bonus(std::move(player.getPos_Head()), std::move(player.getPos_Tail()), window_dimensions);
            }
        } 
        else
        {
            // Finish Game
            DrawText("You Lost!", 500, 260, 40, RED);
        }

        // Draw grid
        // x
        for (int i = 0; i <= window_dimensions[0]; i += 20)
        {
            DrawLine(i, 0, i, window_dimensions[1], BLACK);
        }

        // y
        for (int i = 0; i < window_dimensions[1]; i += 20)
        {
            DrawLine(0, i, window_dimensions[0], i, BLACK);
        }

        // Draw Bonus
        DrawCircle(bonus.x, bonus.y, 9.5, LIME);

        // Draw Player
        player.Draw();

        // Finish draw
        EndDrawing();
    }
    CloseWindow();

    return 0;
}