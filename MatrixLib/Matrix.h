﻿#ifndef _MATRIX_
#define _MATRIX_
#include "MyVector.h"

const int MAX_MATRIX_SIZE = 100000;


template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
private:
	int mSize;
public:
	TMatrix(int s);
	TMatrix(const TMatrix& mt);                   
	TMatrix(const TVector<TVector<ValType> >& mt); 
	~TMatrix();

	int GetSize() { return mSize; }; 
	bool operator==(const TMatrix& mt) const;     
	TMatrix& operator= (const TMatrix& mt);       
	TMatrix  operator+ (const TMatrix& mt);       
	TMatrix  operator- (const TMatrix& mt);       
	TMatrix  operator* (const TMatrix& mt);        

	
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			in >> mt.pVector[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			out << mt.pVector[i] << endl;
		}
		return out;
	}
};

template<class ValType>
inline TMatrix<ValType>::TMatrix(int s) : TVector<TVector <ValType> >(s)
{
	if (s < 0 || s > MAX_MATRIX_SIZE)
	{
		throw "Error";
	}
	mSize = s;
}

template <class ValType> 
inline TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt)
{
	mSize = mt.mSize;
}

template <class ValType> 
inline TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{
}

template<class ValType>
inline TMatrix<ValType>::~TMatrix()
{
}

template <class ValType> 
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	bool res = true;
	int S = this->Size;
	if (S != mt.Size)
	{
		res = false;
	}
	for (int i = 0; i < S; i++)
	{
		if (this->pVector[i] == mt.pVector[i])
		{
			res = true;
		}
		else res = false;
	}
	return res;
}

template <class ValType> 
inline TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this != &mt)
	{
		if (this->Size != mt.Size)
		{
			if (this->pVector != NULL)
			{
				delete[] this->pVector;
			}
			this->pVector = new TVector<ValType>[mt.Size];
		}
		this->Size = mt.Size;
		for (int i = 0; i < this->Size; i++)
		{
			this->pVector[i] = mt.pVector[i];
		}
	}
	return *this;
}

template <class ValType> 
inline TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	if (this->GetSize() != mt.Size)
	{
		throw "Error";
	}

	TMatrix<ValType> tmp(*this);
	for (int i = 0; i < this->Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] + mt.pVector[i];
	}
	return tmp;
}

template <class ValType> 
inline TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	if (this->GetSize() != mt.Size)
	{
		throw "Error";
	}

	TMatrix<ValType> tmp(*this);
	for (int i = 0; i < this->Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] - mt.pVector[i];
	}
	return tmp;
}

template<class ValType>
inline TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt)
{
	if (this->GetSize() != mt.Size)
	{
		throw "Error";
	}
	TMatrix<ValType> tmp(*this);
	for (int i = 0; i < this->Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] * mt.pVector[i];
	}
	return tmp;
}

#endif 