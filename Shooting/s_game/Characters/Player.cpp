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
	// �p�E���ʊp�̏�����
	m_elevation = 0.0f;
	m_direction = 0.0f;
	// �ėp�^�C�}�̏�����
	m_timer = 0.0f;
}

void Player::update()
{
	GSvector3 speed(0.0f, 0.0f, 0.0f);
	// �O�i�E���
	if (gsGetKeyState(GKEY_UP) == GS_TRUE)
	{
		speed = GSvector3(0.1f, 0.1f, 0.1f);
	}
	if (gsGetKeyState(GKEY_DOWN) == GS_TRUE)
	{
		speed = GSvector3(-0.1f, -0.1f, -0.1f);
	}
	// �����]��
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE)
	{
		m_direction = m_direction + 2.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE)
	{
		m_direction = m_direction - 2.0f;
	}
	// �e����
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE)
	{

	}
	// ���ʊp�Ƌp����P�ʃx�N�g�������߂�
	gsVector3FromEleDir(&m_vector, m_elevation, m_direction);

	// �P�ʃx�N�g���Ɉړ��X�s�[�h���|���Z���Ĉړ��ʂ����߂�
	m_vector *= speed;
	// ���݂̍��W�Ɉړ��ʂ�������
	m_position += m_vector;
}

void Player::draw()
{
	// �}�e���A���ݒ�
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GScolor4(0.6f, 1.0f, 0.6f, 1.0f));

	// ���C���[�g�[���X�̕`��
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(m_direction, 0.0f, 1.0f, 0.0f);
	glRotatef(m_elevation, -1.0f, 0.0f, 0.0f);
	glutWireTorus(0.3f / 2.0f, 0.3f, 20.0f, 20.0f);
	glPopMatrix();
}
