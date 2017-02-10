#include <GSgame.h>
#include "Characters\Player.h"
#include "Characters\Enemy.h"

class MyGame : public gslib::Game {
public:
	MyGame() :
		Game(1280, 720, false, 60.0f)
	{}

private:
	// 開始
	virtual void start() override
	{
		m_player = new Player(0.0f, 0.0f, 0.0f);
		m_player->initialize();
		m_enemy = new Enemy(0.0f, 0.0f, 2.0f);
		m_enemy->initialize();
	}
	// 更新
	virtual void update(float deltaTime) override
	{
		m_player->update();
		m_enemy->update();
	}
	// 描画
	virtual void draw() override
	{
		m_player->draw();
		m_enemy->draw();
	}
	// 終了
	virtual void end() override
	{
		delete m_player;
		delete m_enemy;
	}

private:
	Player* m_player;
	Enemy* m_enemy;


};

int main() {
	return MyGame().run();
}
