/**
@file	Player.h
@brief	�v���C���[
@author Ayumu
@date	2017/02/10 Ver1.00
*/
#pragma once

#include "Character.h"

class Player : public Character
{
public:
	/**
	* @brief �R���X�g���N�^
	* @param (_x, _y, _z)  �e�ʒu
	*/
	Player(float _x, float _y, float _z);
	/* �f�X�g���N�^ */
	~Player();
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
