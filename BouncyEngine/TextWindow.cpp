#include "TextWindow.h"

//ALLEGRO_FONT* Init_Allegro::FONT;
enum Init_Allegro::allEvents;

TextWindow::TextWindow(int startingXCoordinate, int startingYCoordinate,
	int endingXCoordinate, int endingYCoordinate)
{
	this->startingXCoordinate = startingXCoordinate;
	this->startingYCoordinate = startingYCoordinate;
	this->endingXCoordinate = endingXCoordinate;
	this->endingYCoordinate = endingYCoordinate;

	text.push_back({ { { "Please enter the size of"} ,{"the linkedList to generate" } } });
	std::cout << "StartingXCoordinate: " << this->startingXCoordinate << std::endl;
	std::cout << "StartingYCoordinate: " << this->startingYCoordinate << std::endl;
	std::cout << "EndingXCoordinate: " << this->endingXCoordinate << std::endl;
	std::cout << "EndingYCoordinate: " << this->endingYCoordinate << std::endl;

}
TextWindow::~TextWindow()
{
	std::cout << "TextWindow Destructor" << std::endl;
}
void TextWindow::drawWindow()
{
	al_draw_filled_rounded_rectangle(
		startingXCoordinate, startingYCoordinate,
		endingXCoordinate, endingYCoordinate,
		0.5, 0.5,
		al_map_rgb(50, 50, 50));
}
void TextWindow::drawText(int xOffSet, int yOffSet) 
{
	if (text.size() > 0)
	{
		if (rowCount < text[paragraghCount].size())
		{
			if (columncount <= text[paragraghCount][rowCount].length())
			{
				currentText = text[paragraghCount][rowCount].substr(0, columncount);
				columncount++;
			}
			else if (rowCount < text[paragraghCount].size())
			{
				printText.push_back(currentText);
				currentText = "";
				rowCount++;
				columncount = 0;
			}
		}

		switch (rowCount)
		{
			case 0:
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 
					this->startingXCoordinate+xOffSet, this->startingYCoordinate+yOffSet, ALLEGRO_ALIGN_LEFT, currentText.c_str());
				break;
			case 1:
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, printText[0].c_str());
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 20, ALLEGRO_ALIGN_LEFT, currentText.c_str());
				break;
			case 2:
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, printText[0].c_str());
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 20, ALLEGRO_ALIGN_LEFT, printText[1].c_str());
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 40, ALLEGRO_ALIGN_LEFT, currentText.c_str());
				break;
			case 3:
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, printText[0].c_str());
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 20, ALLEGRO_ALIGN_LEFT, printText[1].c_str());
				al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
					this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 40, ALLEGRO_ALIGN_LEFT, printText[2].c_str());
				
				break;
		}
		if (rowCount == text[0].size())
		{
			doneDrawingText = true;
		}
	}
}
void TextWindow::drawCurrentText(int xOffSet, int yOffSet)
{
	switch (rowCount)
	{
	case 0:
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, currentText.c_str());
		break;
	case 1:
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, printText[0].c_str());
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 20, ALLEGRO_ALIGN_LEFT, currentText.c_str());
		break;
	case 2:
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, printText[0].c_str());
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 20, ALLEGRO_ALIGN_LEFT, printText[1].c_str());
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 40, ALLEGRO_ALIGN_LEFT, currentText.c_str());
		break;
	case 3:
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet, ALLEGRO_ALIGN_LEFT, printText[0].c_str());
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 20, ALLEGRO_ALIGN_LEFT, printText[1].c_str());
		al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255),
			this->startingXCoordinate + xOffSet, this->startingYCoordinate + yOffSet + 40, ALLEGRO_ALIGN_LEFT, printText[2].c_str());

		break;
	}
}
void TextWindow::drawUserInput()
{
	if(name.size() > 0)
		al_draw_text(
		Init_Allegro::FONT, al_map_rgb(255, 255, 255),
		this->startingXCoordinate, this->startingYCoordinate + 70,
		ALLEGRO_ALIGN_LEFT, name.c_str());
}
bool TextWindow::getDoneDrawingText()
{
	return doneDrawingText;
}
void TextWindow::getUserInput()
{
	int keyCode = 0; 
	
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
	{
		keyCode = keyBoardEvent::returnEvent().keyboard.keycode;
		std::cout << keyCode << std::endl;
		if(keyCode <= 26)
		{
			int value = 'a' - 1;
			std::cout << value<< std::endl;
			name += (static_cast <char>('a' - 1 + keyBoardEvent::returnEvent().keyboard.keycode));
			//al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_LEFT, name.c_str());
		}
		else if (keyCode <= ALLEGRO_KEY_9)
		{
			int value = '0' -21;
			std::cout << value << std::endl;
			name += (static_cast <char>('0' - 27 + keyBoardEvent::returnEvent().keyboard.keycode));
		}
		else if (keyCode <= ALLEGRO_KEY_PAD_9)
		{
			name += (static_cast <char>('0' - 37 + keyBoardEvent::returnEvent().keyboard.keycode));
		}
		else if (keyCode == ALLEGRO_KEY_BACKSPACE or keyCode == ALLEGRO_KEY_DELETE)
		{
			if (name.size() > 0)
			name.pop_back();
		}
		else if (keyCode == ALLEGRO_KEY_ENTER)
		{
			currentEvent = Init_Allegro::allEvents::normal;
		}
	}
}
int TextWindow::getEvent()
{
	return currentEvent;
}
void TextWindow::setEvent(int event)
{
	this->currentEvent = event;
}
void TextWindow::setTextObject(std::vector<std::vector<std::string>> characterText)
{
	text = characterText;
}

std::vector<std::vector<std::string>> TextWindow::getTextObject()
{
	return text;
}