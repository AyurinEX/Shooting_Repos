/**
@file	Character.h
@brief	抽象キャラクター
@author Ayumu
@date	2017/02/10 Ver1.00
*/
#pragma once

#include <GSgame.h>
#include <GSvector3.h>

class Character
{
public:
	/* 仮想デストラクタ */
	virtual ~Character() {}
	/**
	* @brief 初期化（純粋仮想関数）
	*/
	virtual void initialize() = 0;
	/**
	* @brief 更新（純粋仮想関数）
	*/
	virtual void update() = 0;
	/**
	* @brief 描画（純粋仮想関数）
	*/
	virtual void draw() = 0;
};

