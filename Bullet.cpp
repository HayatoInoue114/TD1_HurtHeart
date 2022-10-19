#include"Bullet.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include "Player.hpp"

#include"Enemy.hpp"


BulletClass::BulletClass()
{
}



Bullet::Bullet()
{
}

BulletClass Bullet::bullet[BulletMaxCount] = {  };

void Bullet::Reset(int index)
{
	bullet[index].isAlive = false;

}

void Bullet::DrawBullet() {
	for (int i = 0; i < BulletMaxCount; i++) {
		if (bullet[i].isAlive) {
			Novice::DrawEllipse(bullet[i].position.x, ToWorld(bullet[i].position.y), bullet[i].radius, bullet[i].radius, 0.0f, WHITE, kFillModeSolid);
		}
	}
}

void Bullet::BulletDelete() {
	for (int i = 0; i < BulletMaxCount; i++) {
		if (bullet[i].position.x < 0 || bullet[i].position.x > ScreenSize.x) {
			bullet[i].isAlive = false;
		}

		if (bullet[i].position.y < 0 || bullet[i].position.y > ScreenSize.y) {
			bullet[i].isAlive = false;
		}

	}
}

void Bullet::BulletUpdate() {
	for (int i = 0; i < BulletMaxCount; i++) {
		if (bullet[i].isAlive) {
			bullet[i].position += bullet[i].velocity;
		}
	}
}

void Bullet::BulletReset() {
	for (int i = 0; i < BulletMaxCount; i++) {
		bullet[i].radius = 16;
		bullet[i].acceleration.Reset();
		bullet[i].color = 0xffffffff;
		bullet[i].position.Reset();
		bullet[i].velocity.Reset();
		bullet[i].srcX = 16;
		bullet[i].srcY = 16;
	}
}
