#pragma once
#include<SFML/Graphics.hpp>
#include<string>
class Window {
public:
	Window() { Setup( "Window",sf::Vector2u{640,480} ); };
	Window(const std::string& l_title, const sf::Vector2u& l_size) { Setup(l_title, l_size); }
	~Window() { Destroy(); };
	void BeginDraw() { m_window.clear(sf::Color::Black); } // Clear the window.
	void EndDraw() { m_window.display(); } // Display the changes.
	void Update();
	bool IsDone() const { return m_isDone; }
	bool IsFullscreen() const { return m_isFullscreen; }
	sf::Vector2u GetWindowSize(){ return m_windowSize; }
	void ToggleFullscreen();
	void Draw(sf::Drawable& l_drawable) {m_window.draw(l_drawable);}
private:
	void Setup(const std::string& l_title,
		const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};

