#include "Bullet.h"

const float SPEED = 0.01f;
const float TIMER = 60.0f;

Bullet::Bullet(GSvector3 _position, float _elevation, float _direction)
	:m_position(_position),
	m_vector(0.0f, 0.0f, 0.0f),
	m_elevation(_elevation),
	m_direction(_direction)
{
}

Bullet::~Bullet()
{
}

void Bullet::initialize()
{
	// 仰角・方位角の初期化
	m_elevation = 0.0f;
	m_direction = 0.0f;
	// 方位角と仰角から単位ベクトルを求める
	gsVector3FromEleDir(&m_vector, m_elevation, m_direction);
	// 単位ベクトルに掛け算をして移動量を求める
	m_vector *= SPEED;
	// 汎用タイマの初期化
	m_timer = TIMER;
}

void Bullet::update()
{
	// 移動
	m_position += m_vector;

	m_timer--;
	if (m_timer <= 0)
	{
		delete this;
	}
}

void Bullet::draw()
{
	// マテリアル設定
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GScolor4(1.0f, 1.0f, 0.5f, 1.0f));

	// スフィアの描画
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glutWireSphere(0.01f, 20, 20);
	glPopMatrix();
}
