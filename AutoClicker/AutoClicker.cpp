#include <iostream>
#include <Windows.h>

bool bEnabled = false;
int sleep = 0;
POINT mouse;

int main()
{
	printf("Autoclicker by morganlewiswall\nInsert - Run/Pause\n");
	printf("Sleep value (The lower the value the faster the auto clicker): ");
	std::cin >> sleep;

	while (true)
	{
		printf("Paused\n");

		if (GetAsyncKeyState(VK_INSERT) & 1)
			bEnabled = !bEnabled;

		while (bEnabled)
		{
			printf("Running\n");
			GetCursorPos(&mouse);
			mouse_event(MOUSEEVENTF_LEFTDOWN, mouse.x, mouse.y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, mouse.x, mouse.y, 0, 0);
			Sleep(sleep);
			
			if (GetAsyncKeyState(VK_INSERT) & 1)
				bEnabled = !bEnabled;
			
			system("cls");
		}
		Sleep(1);

		system("cls");
	}
}