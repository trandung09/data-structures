#ifndef compare_cpp
#define compare_cpp
	
template <class T>	
class Greater
{
public:
	bool operator()(const T& x, const T& y){
		return x > y;
	}	
};
	
template <class T>
class Less
{
public:
	bool operator()(const T& x, const T& y){
		return x < y;
	}	
};
	
#endif