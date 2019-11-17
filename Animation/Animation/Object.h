#pragma once
#include <DxLib.h>
#include <Windows.h>
#include <filesystem>
#include <string>
#include <vector>
#include "Keyboard.h"

typedef enum class Direction
{
	mNone,
	mRight,
	mLeft,
	mUp,
	mDown
}Dir;

enum class State
{
	mNormal,
	mDamege,
	mDeath
};

struct ObjInfo
{
	int cx = 0;					// 中心X座標
	int cy = 0;					// 中心Y座標
	int size[2] = { 0,0 };		// [0]...縦、[1]...横
	Dir dir = Dir::mNone;		// 向き
	State st = State::mNormal;	// 状態
};

class Object
{
public:
	Object();
	~Object();
	void Update();
	void Draw();

	ObjInfo obif;

private:
	std::string path;
	std::vector<int>graph;
};