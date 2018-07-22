#pragma once

#include <iostream>
#include <Windows.h>
#include "my_OGL_functions.h"
#include "OGL_LIBRARY/GL/gl.h"

TLine::TLine(TPoint* asPt, TPoint* aePt)
{
	sPt = asPt;
	ePt = aePt;
}

TLine::~TLine()
{
}

void TLine::draw()
{
	glBegin(GL_LINES);
	glVertex3d(sPt->x, sPt->y, sPt->z);
	glVertex3d(ePt->x, ePt->y, ePt->z);

	glEnd();
}

TGroup::TGroup()
{
	//
}

TGroup::~TGroup()
{
	//
}

void TGroup::addObject(TObject * Object)
{
	Objects.push_back(Object);
}

void TGroup::draw()
{
	for (int i = 0; i < Objects.size(); i++)
	{
		Objects.at(i)->draw();
	}
}
