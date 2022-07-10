#include "Types.h"
#include <float.h>

// Point
sPoint::sPoint( const sPoint& aPoint )
{
	x = aPoint.x;
	y = aPoint.y;
}

void sPoint::operator = ( const sPoint& aPoint )
{
	x = aPoint.x;
	y = aPoint.y;
}

sPoint sPoint::operator - ( const sPoint& aPoint ) const
{
	return sPoint( x - aPoint.x, y - aPoint.y );
}

sPoint sPoint::operator + ( const sPoint& aPoint ) const
{
	return sPoint( x + aPoint.x, y + aPoint.y );
}

sPoint sPoint::operator / ( float aDenominator ) const
{
	return sPoint( x / aDenominator, y / aDenominator );
}

sPoint sPoint::operator * ( float aMultiplier ) const
{
	return sPoint( x * aMultiplier, y * aMultiplier );
}

// Size
sSize::sSize( const sSize& aSize )
{
	width = aSize.width;
	height = aSize.height;
}

void sSize::operator = ( const sSize& aSize )
{
	width = aSize.width;
	height = aSize.height;
}

sSize sSize::operator - ( const sSize& aSize ) const
{
	return sSize( width - aSize.width, height - aSize.height );
}

sSize sSize::operator + ( const sSize& aSize ) const
{
	return sSize( width + aSize.width, height + aSize.height );
}

sSize sSize::operator / ( float aDenominator ) const
{
	return sSize( width / aDenominator, height / aDenominator );
}

sSize sSize::operator * ( float aMultiplier ) const
{
	return sSize( width * aMultiplier, height * aMultiplier );
}


// Color3f
sColor3f::sColor3f( const sColor3f& aColor )
{
	red = aColor.red;
	green = aColor.green;
	blue = aColor.blue;
}

void sColor3f::operator = ( const sColor3f& aColor )
{
	red = aColor.red;
	green = aColor.green;
	blue = aColor.blue;
}

sColor3f sColor3f::operator - ( const sColor3f& aColor ) const
{
	return sColor3f(
		red - aColor.red,
		green - aColor.green,
		blue - aColor.blue
	);
}

sColor3f sColor3f::operator + ( const sColor3f& aColor ) const
{
	return sColor3f(
		red + aColor.red,
		green + aColor.green,
		blue + aColor.blue
	);
}

sColor3f sColor3f::operator / ( const sColor3f& aColor ) const
{
	return sColor3f(
		red / aColor.red,
		green / aColor.green,
		blue / aColor.blue
	);
}

sColor3f sColor3f::operator / ( float aDenominator ) const
{
	return sColor3f(
		red / aDenominator,
		green / aDenominator,
		blue / aDenominator
	);
}

sColor3f sColor3f::operator * ( const sColor3f& aColor ) const
{
	return sColor3f(
		red * aColor.red,
		green * aColor.green,
		blue * aColor.blue
	);
}

const sColor3f sColor3f::RED( 255.0f, 0.0f, 0.0f );
const sColor3f sColor3f::GREEN( 0.0f, 255.0f, 0.0f );
const sColor3f sColor3f::BLUE( 0.0f, 0.0f, 255.0f );
const sColor3f sColor3f::YELLOW( 255.0f, 255.0f, 0.0f );
const sColor3f sColor3f::WHITE( 255.0f, 255.0f, 255.0f );
const sColor3f sColor3f::GRAY( 150.0f, 150.0f, 150.0f );
const sColor3f sColor3f::BLACK( 0.0f, 0.0f, 0.0f );
const sColor3f sColor3f::PINK( 255.0f, 120.0f, 203.0f );


// Rect
Rect::Rect( float aX, float aY, float aWidth, float aHeight )
	: mOrigin( sPoint( aX, aY ) )
	, mSize( sSize( aWidth, aHeight ) )
{
}

Rect::~Rect()
{
}

float Rect::getMinX()
{
	return mOrigin.x;
}

float Rect::getMidX()
{
	return mOrigin.x + mSize.width / 2.0f;
}

float Rect::getMaxX()
{
	return mOrigin.x + mSize.width;
}

float Rect::getMinY()
{
	return mOrigin.y;
}

float Rect::getMidY()
{
	return mOrigin.y + mSize.height / 2.0f;
}

float Rect::getMaxY()
{
	return mOrigin.y + mSize.height;
}

bool Rect::containsPoint( const sPoint& aPoint )
{
	bool result = false;

	if ( ( aPoint.x - getMinX() > FLT_EPSILON ) && ( getMaxX() - aPoint.x > FLT_EPSILON )
		&& ( aPoint.y - getMinY() > FLT_EPSILON ) && ( getMaxY() - aPoint.y > FLT_EPSILON ) )
	{
		result = true;
	}

	return result;
}
