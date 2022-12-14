#pragma once

#include "BaseData.hpp"
#include "Vector2.hpp"

#include "SpriteClass.hpp"

const unsigned int ParticleMax = 128;

/// <summary>
	/// Ballクラス
	/// </summary>
	/// <param name="position">位置ベクトル</param>
	/// <param name="velocity">移動速度ベクトル</param>
	/// <param name="acceleration">加速度ベクトル</param>
	/// <param name="radius">半径</param>
	/// <param name="norm">ノルム</param>
	/// <param name="mass">重量</param>
	/// <param name="color">色 0xRRGGBBAA</param>
	/// <param name="aliveFlame">生存時間</param>
	/// <param name="maxFlame">寿命</param>
	/// <param name="isAlive">生存の真偽値</param>
class ParticleClass:public Ball, public SpriteClass{
public:
	int aliveFlame;
	int maxFlame;
	bool isAlive;

	ParticleClass();
};

class Particle
{
public:
	Particle();

	ParticleClass particles[ParticleMax];

	void Spawn(const Vector2& Position);
	void Spawn(const Vector2& Position, unsigned int count);

	void Update();

	void CheckDelete();
	void CheckDelete(int index);

	//画面外に出たとき
	void OffScreen(int index);
	void LifeEnd(int index);

	void Reset(int index);


	void Draw();

private:

};






