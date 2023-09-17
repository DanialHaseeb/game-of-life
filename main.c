#include "raylib.h"
#include <stdbool.h>

const int width = 800;
const int height = 600;
const int cellSize = 10;
const int rows = height / cellSize;
const int cols = width / cellSize;

bool grid[rows][cols] = {false};
bool newGrid[rows][cols] = {false};

void setup()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{ grid[i][j] = (GetRandomValue(0, 1) == 1); }
	}
}

int countNeighbors(int x, int y)
{
	int count = 0;
	
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			int row = (x + i + rows) % rows;
			int col = (y + j + cols) % cols;
			count += grid[row][col];
		}
	}
	
	return count - grid[x][y];
}

void update()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int neighbors = countNeighbors(i, j);
			newGrid[i][j] = grid[i][j];
			if (grid[i][j] && (neighbors < 2 || neighbors > 3)) { newGrid[i][j] = false; }
			else if (!grid[i][j] && neighbors == 3) { newGrid[i][j] = true; }
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
    { grid[i][j] = newGrid[i][j]; }
	}
}

void draw()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (grid[i][j])
      { DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, WHITE); }
		}
	}
}

int main()
{
	InitWindow(width, height, "Game of Life");
	setup();

	SetTargetFPS(10);

	while (!WindowShouldClose())
	{
	  BeginDrawing();
		ClearBackground(BLACK);

		draw();
		update();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
