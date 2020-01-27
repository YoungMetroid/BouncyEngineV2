#include "TextWindow.h"



enum Init_Allegro::allEvents;

TextWindow::TextWindow(int startingXCoordinate, int startingYCoordinate,
	int endingXCoordinate, int endingYCoordinate)
{
	this->startingXCoordinate = startingXCoordinate;
	this->startingYCoordinate = startingYCoordinate;
	this->endingXCoordinate = endingXCoordinate;
	this->endingYCoordinate = endingYCoordinate;

	text.push_back({ { { "Please enter the size of"} ,{"the linkedList to generate" }, {"third line"} } });
	text.push_back({ { { "Second Paragraph"} ,{"the linkedList to generate" }, {"third line"} } });
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
	if (windowFrame == nullptr)
	{
		loadImage(menuFrame2);
	}
	al_draw_scaled_bitmap(windowFrame, 0,0, imageWidth, imageHeight, startingXCoordinate,
		startingYCoordinate, endingXCoordinate, endingYCoordinate, NULL);
}
void TextWindow::drawText(int xOffSet, int yOffSet) 
{
		if (text.size() > 0 && paragraghCount < text.size())
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
			if (rowCount == text[paragraghCount].size())
			{
				doneDrawingParagragh = true;
				if (paragraghCount >= text.size()-1 && rowCount == text[paragraghCount].size())
				{
					lastParagragh = true;
					doneDrawingAllText = true;
				}
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
void TextWindow::drawInstantText()
{
	al_draw_text(Init_Allegro::FONT, al_map_rgb(red, green, blue), 
		this->startingXCoordinate + this->endingXCoordinate *.05, 
		this->startingYCoordinate + this->endingYCoordinate /2,
		ALLEGRO_ALIGN_LEFT, loadedText.c_str());
}
void TextWindow::drawUserInput()
{
	if(userInput.size() > 0)
		al_draw_text(
		Init_Allegro::FONT, al_map_rgb(255, 255, 255),
		this->startingXCoordinate, this->startingYCoordinate + 70,
		ALLEGRO_ALIGN_LEFT, userInput.c_str());
}
bool TextWindow::getDoneDrawingAllText()
{
	return doneDrawingAllText;
}
bool TextWindow::getDoneDrawingParagraph()
{
	return doneDrawingParagragh;
}
bool TextWindow::isLastParagraph()
{
	return lastParagragh;
}
std::string TextWindow::getUserInput()
{
	int keyCode = 0; 
	
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
	{
		keyCode = keyBoardEvent::returnEvent().keyboard.keycode;
		std::cout << keyCode << std::endl;
		if(keyCode <= 26)
		{
			userInput += (static_cast <char>('a' - 1 + keyBoardEvent::returnEvent().keyboard.keycode));
		}
		else if (keyCode <= ALLEGRO_KEY_9)
		{
			userInput += (static_cast <char>('0' - 27 + keyBoardEvent::returnEvent().keyboard.keycode));
		}
		else if (keyCode <= ALLEGRO_KEY_PAD_9)
		{
			userInput += (static_cast <char>('0' - 37 + keyBoardEvent::returnEvent().keyboard.keycode));
		}
		else if (keyCode == ALLEGRO_KEY_BACKSPACE or keyCode == ALLEGRO_KEY_DELETE)
		{
			if (userInput.size() > 0)
				userInput.pop_back();
		}
		else if (keyCode == ALLEGRO_KEY_ENTER)
		{
			return userInput;

			bool flag = std::all_of(userInput.begin(), userInput.end(), ::isdigit);
			if (userInput.size() > 0)
			{
				try 
				{
					int inputConversion = std::stoi(userInput);
					if (inputConversion > 1 && inputConversion < 10000)
					{
						currentEvent = Init_Allegro::allEvents::menu2;
					}
				}
				catch (std::exception ex)
				{
					std::cout << ex.what() << std::endl;
				}
			}
		}
	}
	return "";
}
int TextWindow::getEvent()
{
	return currentEvent;
}
void TextWindow::loadImage(const char *image)
{
	windowFrame = al_load_bitmap(image);
	imageHeight = al_get_bitmap_height(windowFrame);
	imageWidth = al_get_bitmap_width(windowFrame);
}
void TextWindow::loadText(std::string text)
{
	loadedText = text;
}
bool TextWindow::mouseInArea(int x, int y)
{
	if(x >= startingXCoordinate &&
		x <= startingXCoordinate + endingXCoordinate)
		if (y >= startingYCoordinate &&
			y <= startingYCoordinate + endingYCoordinate)
		{
			red = 20; green = 20; blue = 120;
			return true;
		}		
	red = 255; green = 255; blue = 255;
	return false;
}
void TextWindow::nextTextSignal()
{
	rowCount = 0;
	paragraghCount++;
	wait = false;
	doneDrawingParagragh = false;
	printText.clear();
}
void TextWindow::resetEvent()
{
	userInput.clear();
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