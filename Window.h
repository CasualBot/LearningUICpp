#pragma once
#include "imgui.h";

class Window
{
public:
	Window();
	virtual ~Window();
	Window(ImGuiIO& io);
	void Render();
private:
	ImGuiIO io;
	bool p_opened;
	bool show_another_window;
	bool show_demo_window;
};