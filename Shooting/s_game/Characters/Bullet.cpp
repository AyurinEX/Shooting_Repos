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
	// �p�E���ʊp�̏�����
	m_elevation = 0.0f;
	m_direction = 0.0f;
	// ���ʊp�Ƌp����P�ʃx�N�g�������߂�
	gsVector3FromEleDir(&m_vector, m_elevation, m_direction);
	// �P�ʃx�N�g���Ɋ|���Z�����Ĉړ��ʂ����߂�
	m_vector *= SPEED;
	// �ėp�^�C�}�̏�����
	m_timer = TIMER;
}

void Bullet::update()
{
	// �ړ�
	m_position += m_vector;

	m_timer--;
	if (m_timer <= 0)
	{
		delete this;
	}
}

void Bullet::draw()
{
	// �}�e���A���ݒ�
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GScolor4(1.0f, 1.0f, 0.5f, 1.0f));

	// �X�t�B�A�̕`��
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glutWireSphere(0.01f, 20, 20);
	glPopMatrix();
}
