#pragma once

class Window
{
protected:
	
	int startingXCoordinate;
	int startingYCoordinate;
	int endingXCoordinate;
	int endingYCoordinate;
	
public:
	virtual void  setWindowCoordinate(int startingXCoordinate, int startingYCoordinate,
		int endingXCoordinate, int endingYCoordinate);
	

};
