#pragma once
#include <GLFW/glfw3.h> // For glfwGetTime()
#include <windows.h> // For Sleep() 
#include <sstream>

namespace GLGame
{
	static const int max_fps = 65;
	static const bool print_fps = true;

	/*
	void CalculateFrameRate()
	{
		static float framesPerSecond = 0.0f;
		static float fps;
		static double lastTime = 0.0f;
		double currentTime = glfwGetTime();
		++framesPerSecond;
		if (currentTime - lastTime > 1.0f)
		{
			lastTime = currentTime;
			fps = framesPerSecond;
			framesPerSecond = 0;
		}

		Sleep(((double)1 / max_fps * 1000) - (double)(currentTime - lastTime));

		if (print_fps)
		{
			cout << fps ;
		}
	}*/

	void CalculateFrameRate(GLFWwindow* pWindow)
	{
		static const double expected_time = (double)(((double)1 / max_fps) * (double)1000.0);
		static double lastTime = 0;
		static float nbFrames = 0;
		double currentTime = glfwGetTime();
		double delta = currentTime - lastTime;
		nbFrames++;
		if (delta >= 1.0) { // If last cout was more than 1 sec ago
			//cout << 1000.0 / double(nbFrames) << endl;

			double fps = double(nbFrames) / delta;

			std::stringstream ss;
			ss << "Opengl" << " " << "3.3" << " [" << fps << " FPS]";

			glfwSetWindowTitle(pWindow, ss.str().c_str());

			nbFrames = 0;
			lastTime = currentTime;
		}

		Sleep(expected_time - (currentTime - lastTime));
	}

	void DisplayFrameRate(GLFWwindow* pWindow)
	{
		static double lastTime = 0;
		static float nbFrames = 0;
		double currentTime = glfwGetTime();
		double delta = currentTime - lastTime;
		nbFrames++;
		if (delta >= 1.0) { // If last cout was more than 1 sec ago
			//cout << 1000.0 / double(nbFrames) << endl;

			double fps = double(nbFrames) / delta;

			std::stringstream ss;
			ss << "Opengl" << " " << "3.3" << " [" << fps << " FPS]";

			glfwSetWindowTitle(pWindow, ss.str().c_str());

			nbFrames = 0;
			lastTime = currentTime;
		}

	}
}