#include "Window.h";

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

Window::Window() : p_opened(true), show_another_window(false), show_demo_window(false) {};
Window::~Window() {};
Window::Window(ImGuiIO& _io) : Window() 
{
	io = _io;
}

void Window::Render()
{
	//TODO: Figure out class variable reference passing and updating in memory so window can be closed
	if (p_opened)
	{
		if (!ImGui::Begin("Hello, world!", &p_opened))
		{
			ImGui::End();
			return;
		}
		else
		{

			if (show_demo_window)
			{
				ImGui::ShowDemoWindow(&show_demo_window);
			}

			//static float f = 0.0f;
			//static int counter = 0;

			//ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
			ImGui::Text("p_open: %s", &p_opened ? "true" : "false");
			// Buttons return true when clicked (most widgets return true when edited/activated)
			//if (ImGui::Button("Button"))
			//{
			//	counter++;
			//}
			//ImGui::SameLine();
			//ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

			ImGui::End();

			if (show_another_window)
			{
				ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
				ImGui::Text("Hello from another window!");
				if (ImGui::Button("Close Me"))
					show_another_window = false;
				ImGui::End();
			}
		}
	}
}