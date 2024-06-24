#include <iostream>
#include <raylib.h>

class minawan {
public:
	float x, y;
	float gravity;
	Color color;
	minawan(float x, float y, Color color, float gravity) : x(x), y(y), color(color), gravity(gravity) {}
	minawan* clone() {
		return new minawan(this->x, this->y, this->color, this->gravity);
	}
};

int main() {
	InitWindow(800, 600,"MinawanLandC++");
	minawan original(500.0f, 500.0f,RAYWHITE,9.87f);
	minawan* clone = original.clone();
	clone->x += 500;
	SetTargetFPS(NULL);
	while (!WindowShouldClose()) {
		// Update

		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw original object
		DrawCircle(static_cast<int>(original.x), static_cast<int>(original.y), 20, RED);

		// Draw cloned object
		DrawCircle(static_cast<int>(clone->x), static_cast<int>(clone->y), 20, BLUE);

		EndDrawing();
		clone->x = GetMousePosition().x;
		clone->y = GetMousePosition().y;
	}

	// Clean up
	delete clone;

	CloseWindow();

	return 0;
}