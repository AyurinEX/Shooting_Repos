#include "Enemy.h"

Enemy::Enemy(float _x, float _y, float _z)
	:m_position(_x, _y, _z),
	m_vector(0.0f, 0.0f, 0.0f)
{
}

Enemy::~Enemy()
{
}

void Enemy::initialize()
{
	// �p�E���ʊp�̏�����
	m_elevation = 0.0f;
	m_direction = 0.0f;
	// �ėp�^�C�}�̏�����
	m_timer = 0.0f;
}

void Enemy::update()
{
	// ���ʊp�𑝂₷
	m_direction += 5.0f;
}

void Enemy::draw()
{
	// �}�e���A���ݒ�
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GScolor4(1.0f, 0.7f, 0.7f, 1.0f));

	// ���C���[�g�[���X�̕`��
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(m_direction, 0.0f, 1.0f, 0.0f);
	glutWireTorus(0.3f / 2.0f, 0.3f, 20, 20);
	glPopMatrix();
}
