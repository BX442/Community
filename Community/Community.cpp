#include "pch.h"
#include <iostream>
#include <bitset>
//#include <Windows.h> // ошибка
#include <SFML/Graphics.hpp>
#include "a_random.h"
using std::cout;
using std::endl;

int main()
{
	///Settings
	system("color 80");
	setlocale(LC_ALL, "");
	
	///Parametrs
	sf::RenderWindow window(sf::VideoMode(640, 480), "Community");
	window.setVerticalSyncEnabled(true);

	time_t currentTime;
	time(&currentTime);
	srand(static_cast<int>(currentTime)); ///cout << currentTime << endl;
	
	///Start
	sf::Image tileSet;
	tileSet.loadFromFile("data/images/tileset/set_max.png");

	sf::Texture mainTexture;
	mainTexture.loadFromImage(tileSet);
	tileSet.~Image();

	sf::Sprite testSprite;
	testSprite.setTexture(mainTexture);
	testSprite.setTextureRect(sf::IntRect(11 * 32, 9 * 32, 32, 32));
	testSprite.setPosition(0, 0);





	//sf::Clock clock;
	while (window.isOpen())
	{
		clock_t start = clock();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) { testSprite.move(-0.1f, 0); } //первая координата Х отрицательна =>идём влево
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) { testSprite.move(0.1f, 0); } //первая координата Х положительна =>идём вправо
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) { testSprite.move(0, -0.1f); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) { testSprite.move(0, 0.1f); } //вторая координата (У) положительна =>идём вниз (если не понятно почему именно вниз - смотрим предыдущие уроки)

	
		window.clear();
		window.draw(testSprite);
		window.display();
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		//std::cout << "Время выполнения: " << seconds << std::endl;
	}
}


















//sf::Clock clock; //Таймер стартует сейчас	//Time elapsed = clock.restart(); //Возвращает время пройденое с предыдущего рестарта(или старта)//cout << "Время отрисовки: " << clock.restart().asMilliseconds() << endl; //sf::Time elapsed = clock.restart();// std::cout << "Время отрисовки: " << clock.restart().asMilliseconds() << std::endl;
/*
clock_t start = clock();
//code...
clock_t end = clock();
double seconds = (double)(end - start) / CLOCKS_PER_SEC;
std::cout << "Время выполнения: " << seconds << std::endl;
*/