/**
@file	Player.h
@brief	プレイヤー
@author Ayumu
@date	2017/02/10 Ver1.00
*/
#pragma once

#include "Character.h"

class Player : public Character
{
public:
	/**
	* @brief コンストラクタ
	* @param (_x, _y, _z)  各位置
	*/
	Player(float _x, float _y, float _z);
	/* デストラクタ */
	~Player();
	/**
	* @brief 初期化
	*/
	virtual void initialize() override;
	/**
	* @brief 更新
	*/
	virtual void update() override;
	/**
	* @brief 描画
	*/
	virtual void draw() override;

private:
	// 使用フラグ
	bool m_alloc;
	// 汎用タイマ
	int m_timer;
	// 仰角
	float m_elevation;
	// 方位角
	float m_direction;
	// 位置
	GSvector3 m_position;
	// 移動量
	GSvector3 m_vector;

};
