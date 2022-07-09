#ifndef REF_H
#define REF_H


class Ref
{
	int mRefCounter;

public:
	Ref();
	virtual ~Ref();

	void retain();
	void release();

	int getRefCounter();

	void autorelease();

	void clear();
};


#endif
