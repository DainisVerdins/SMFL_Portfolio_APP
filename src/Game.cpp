#include "Game.h"

Game::Game()
:m_window {"Chapter 2", sf::Vector2u{800,600}}
{
	m_mushroomTexture.loadFromFile("./res/filename.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i{ 4,4 };
}
void Game::Update() {
	m_window.Update(); // Update window events.
	MoveMushroom();
}
void Game::Render()
{
	m_window.BeginDraw();//clear
	m_window.Draw(m_mushroom);
	m_window.EndDraw();//Display
}
Window* Game::GetWindow()
{
	return &m_window;
}
void Game::MoveMushroom() {
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();
	if ((m_mushroom.getPosition().x >
		l_windSize.x - l_textSize.x && m_increment.x > 0) ||
		(m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
		m_increment.x = -m_increment.x;
	}
	if ((m_mushroom.getPosition().y >
		l_windSize.y - l_textSize.y && m_increment.y > 0) ||
		(m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
		m_increment.y = -m_increment.y;
	}
	m_mushroom.setPosition(
		m_mushroom.getPosition().x + m_increment.x,
		m_mushroom.getPosition().y + m_increment.y);
}