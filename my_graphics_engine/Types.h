#ifndef TYPES_H
#define TYPES_H


struct sPoint
{
	float x;
	float y;

	sPoint( float aX = 0.0f, float aY = 0.0f )
		: x( aX )
		, y( aY )
	{
	}

	sPoint( const sPoint& aPoint );

	void operator = ( const sPoint& aPoint );
	sPoint operator - ( const sPoint& aPoint ) const;
	sPoint operator + ( const sPoint& aPoint ) const;
	sPoint operator / ( float aDenominator ) const;
	sPoint operator * ( float aMultiplier ) const;

};


struct sSize
{
	float width;
	float height;

	sSize( float aWidth = 0.0f, float aHeight = 0.0f )
		: width( aWidth )
		, height( aHeight )
	{
	}

	sSize( const sSize& aSize );

	void operator = ( const sSize& aSize );
	sSize operator - ( const sSize& aSize ) const;
	sSize operator + ( const sSize& aSize ) const;
	sSize operator / ( float aDenominator ) const;
	sSize operator * ( float aMultiplier ) const;

};


struct sColor3f
{
	float red;
	float green;
	float blue;

	sColor3f( float aRed = 0.0f, float aGreen = 0.0f, float aBlue = 0.0f )
		: red( aRed )
		, green( aGreen )
		, blue( aBlue )
	{
	}

	sColor3f( const sColor3f& aColor );

	void operator = ( const sColor3f& aColor );

	static const sColor3f RED;
	static const sColor3f GREEN;
	static const sColor3f BLUE;
	static const sColor3f YELLOW;
	static const sColor3f WHITE;
	static const sColor3f GRAY;
	static const sColor3f BLACK;

};

class Rect
{
	sPoint mOrigin;
	sSize mSize;

public:
	Rect( float aX = 0.0f, float aY = 0.0f, float aWidth = 0.0f, float aHeight = 0.0f );
	~Rect();

	float getMinX();
	float getMidX();
	float getMaxX();

	float getMinY();
	float getMidY();
	float getMaxY();

	bool containsPoint( const sPoint& aPoint );
};


#endif