#pragma once
#include <iostream>
#include <vector>

class map
{
public:
	map(int SizeTyped);
	~map(void);
	void Round(void);



private:
	std::vector< std::vector<char>> MapInfo;
	int XCor;
	int YCor;
	int Size;
	int FullSize;
	char Command;
	bool PathExist;
	void DrawMap(void);
	void PlayerMovement(void);
	void GenerateMap(void);
	bool CheckIfWall(void);


};