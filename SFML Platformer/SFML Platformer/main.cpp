// Video: 
#include "stdafx.h"


int main()
{
	ScreenManager::Instance().SetText("Hello World");
	ScreenManager::Instance().DrawText();

	system("pause");
	return 0;
}

