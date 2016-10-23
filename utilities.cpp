template <typename T> int smaller(const T& v1,const T& v2)
{
	if(v1 < v2) return 1;
	if(v2 < v1) return 2; 

	return 0;

}
