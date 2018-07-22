#pragma once

#include <vector>


public struct TPoint
{
	double x, y, z;
	TPoint() {};
	TPoint(double ax, double ay, double az)
	{
		x = ax;
		y = ay;
		z = az;
	}

};


public class TObject
{
private:
	int color;
public:
	TObject() {};
	~TObject() {};
	virtual void draw() = 0;

};

 public class TLine : public TObject
{
private:
	TPoint * sPt;
	TPoint * ePt;
public:
	 TLine(TPoint* asPt,TPoint* aePt);
	 ~TLine();
	 void draw() override;

};

 public class TGroup
 {
 private:
	 std::vector<TObject*> Objects;
 public:
	 TGroup();
	 ~TGroup();
	 void addObject(TObject* Object);
	 void draw();

 };
