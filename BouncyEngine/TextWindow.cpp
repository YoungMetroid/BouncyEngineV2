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
				if (paragraghCount >= text.size()-1)
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
	al_draw_text(Init_Allegro::FONT, al_map_rgb(255, 255, 255), 
		this->startingXCoordinate + this->endingXCoordinate *.05, 
		this->startingYCoordinate + this->endingYCoordinate /2,
		ALLEGRO_ALIGN_LEFT, loadedText.c_str());
}
void TextWindow::drawUserInput()
{
	if(name.size() > 0)
		al_draw_text(
		Init_Allegro::FONT, al_map_rgb(255, 255, 255),
		this->startingXCoordinate, this->startingYCoordinate + 70,
		ALLEGRO_ALIGN_LEFT, name.c_str());
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
void TextWindow::getUserInput()
{
	int keyCode = 0; 
	
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
	{
		keyCode = keyBoardEvent::returnEvent().keyboard.keycode;
		std::cout << keyCode << std::endl;
		if(keyCode <= 26)
		{
			name += (static_cast <char>('a' - 1 + keyBoardEvent::returnEvent().keyboard.keycode));
		}
		else if (keyCode <= ALLEGRO_KEY_9)
		{
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
			bool flag = std::all_of(name.begin(), name.end(), ::isdigit);
			if (name.size() > 0)
			{
				try 
				{
					int inputConversion = std::stoi(name);
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
void TextWindow::nextTextSignal()
{
	rowCount = 0;
	paragraghCount++;
	wait = false;
	printText.clear();
	
}
void TextWindow::resetEvent()
{
	currentEvent = -1;
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