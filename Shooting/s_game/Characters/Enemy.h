/**
@file	Enemy.h
@brief	�G�l�~�[
@author Ayumu
@date	2017/02/10 Ver1.00
*/
#pragma once

#include "Character.h"

class Enemy : public Character
{
public:
	/* �R���X�g���N�^ */
	Enemy(float _x, float _y, float _z);
	/* �f�X�g���N�^ */
	~Enemy();
	/**
	* @brief ������
	*/
	virtual void initialize() override;
	/**
	* @brief �X�V
	*/
	virtual void update() override;
	/**
	* @brief �`��
	*/
	virtual void draw() override;

private:
	// �g�p�t���O
	bool m_alloc;
	// �ėp�^�C�}
	int m_timer;
	// �p
	float m_elevation;
	// ���ʊp
	float m_direction;
	// �ʒu
	GSvector3 m_position;
	// �ړ���
	GSvector3 m_vector;

};

