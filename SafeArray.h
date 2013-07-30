//Safe Array!
//This class is ment to act as much like a normal array as possible with the added feature of bounds checking
//and knowing its size
#ifndef SAFEARRAY_H
#define SAFEARRAY_H

template <class T>
class SafeArray
{
	
	protected: //More space for inheretince
		T *sarray; //array
		int size; //size of array
	public:
		SafeArray()
		{
			size = 5; //by defualt sets size to five
			sarray = new T[size]; // creates an array of 5 indecies 
		}

		//Same as default constructor except allows for user to set size
		SafeArray(int s)
		{
			size = s;
			sarray = new T[size];
		}

		//copy constructor. It can be used to initialize one SafeArray with another
		//Also for safty since there is a precesence of pointers
		SafeArray(const SafeArray &a)
		{
			size = a.size;
			sarray = new T[size];
		}

		//returns the size of the array
		const int getSize()
		{return size;}

		//returns the array itself
		T* getArray()
		{return sarray;}

		//overloaded subscript operator for accessing the indecies of the array
		T& operator[](const unsigned int);
		
		//thrown when the subscript is too small
		class TooSmallIndex
		{};

		//thrown when the subscript is out of bounds
		class OutOfBounds
		{};

		//destructor 
		~SafeArray()
		{delete[] sarray;}
};

template <class T>
T& SafeArray<T>::operator[](const unsigned int index)
{

	if(index < 0)
		throw TooSmallIndex();
	else if(index >= size)
		throw OutOfBounds();
	else
		return sarray[index];
}

#endif SAFEARRAY_H