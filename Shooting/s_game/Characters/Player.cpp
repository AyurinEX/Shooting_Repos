#include "Player.h"

Player::Player(float _x, float _y, float _z)
	:m_position(_x, _y, _z),
	m_vector(0.0f, 0.0f, 0.0f)
{
}

Player::~Player()
{
}

void Player::initialize()
{
	// 仰角・方位角の初期化
	m_elevation = 0.0f;
	m_direction = 0.0f;
	// 汎用タイマの初期化
	m_timer = 0.0f;
}

void Player::update()
{
	GSvector3 speed(0.0f, 0.0f, 0.0f);
	// 前進・後退
	if (gsGetKeyState(GKEY_UP) == GS_TRUE)
	{
		speed = GSvector3(0.1f, 0.1f, 0.1f);
	}
	if (gsGetKeyState(GKEY_DOWN) == GS_TRUE)
	{
		speed = GSvector3(-0.1f, -0.1f, -0.1f);
	}
	// 方向転換
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE)
	{
		m_direction = m_direction + 2.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE)
	{
		m_direction = m_direction - 2.0f;
	}
	// 弾発射
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE)
	{

	}
	// 方位角と仰角から単位ベクトルを求める
	gsVector3FromEleDir(&m_vector, m_elevation, m_direction);

	// 単位ベクトルに移動スピードを掛け算して移動量を求める
	m_vector *= speed;
	// 現在の座標に移動量を加える
	m_position += m_vector;
}

void Player::draw()
{
	// マテリアル設定
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GScolor4(0.6f, 1.0f, 0.6f, 1.0f));

	// ワイヤートーラスの描画
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(m_direction, 0.0f, 1.0f, 0.0f);
	glRotatef(m_elevation, -1.0f, 0.0f, 0.0f);
	glutWireTorus(0.3f / 2.0f, 0.3f, 20.0f, 20.0f);
	glPopMatrix();
}
