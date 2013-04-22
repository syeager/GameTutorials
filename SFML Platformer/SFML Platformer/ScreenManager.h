#include "stdafx.h"


class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &Instance();

	void SetText(std::string text);
	void DrawText();

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	std::string text;
};

