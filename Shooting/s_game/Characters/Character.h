/**
@file	Character.h
@brief	���ۃL�����N�^�[
@author Ayumu
@date	2017/02/10 Ver1.00
*/
#pragma once

#include <GSgame.h>
#include <GSvector3.h>

class Character
{
public:
	/* ���z�f�X�g���N�^ */
	virtual ~Character() {}
	/**
	* @brief �������i�������z�֐��j
	*/
	virtual void initialize() = 0;
	/**
	* @brief �X�V�i�������z�֐��j
	*/
	virtual void update() = 0;
	/**
	* @brief �`��i�������z�֐��j
	*/
	virtual void draw() = 0;
};

