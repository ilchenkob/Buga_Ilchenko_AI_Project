#pragma once

class CGame
{
public:
	static const CGame& Instance() { static CGame inst; return inst; }
	void Run();
private:
	CGame() {}

	void Draw();
	void Update();
};