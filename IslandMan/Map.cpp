#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
	
	{0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0},
	{0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};

Map::Map() {

	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");

	LoadMap(lvl1);
	src.x = src.y = des.x = des.y = 0;
	src.h = des.h = 32;
	src.w = des.w = 32;
}

void Map::LoadMap(int arr[20][25]) {

	for (int row = 0; row < 20; row++)
	{
		for (int col = 0; col < 25; col++)
		{
			map[row][col] = arr[row][col];
		}
	}

}

void Map::DrawMap() {

	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int col = 0; col < 25; col++)
		{
			type = map[row][col];
			des.x = col * 32;
			des.y = row * 32;


			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, des);
				break;
			case 1:
				TextureManager::Draw(grass, src, des);
				break;
			case 2:
				TextureManager::Draw(dirt, src, des);
				break;
			default:
				break;
			}
		}
	}

}
