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
	int cx = 0;					// ���SX���W
	int cy = 0;					// ���SY���W
	int size[2] = { 0,0 };		// [0]...�c�A[1]...��
	Dir dir = Dir::mNone;		// ����
	State st = State::mNormal;	// ���
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