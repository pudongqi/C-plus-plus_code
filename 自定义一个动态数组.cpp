/*自定义一个动态数组*/

#include<stdlib.h>
#include<iostream>
using namespace std;
enum ErrorType{ InvalidArraySize, MemoryAllocationError, IndexOutOfRange };
char *ErrorMsg[]={ "Invalid Array Size", "Memory Allocation Error" "Invalid Index" };

template < class T >
class Array
{
private:
	T *alist;//指向数组的存储空间
	int size;//数组的长度
	void Error( ErrorType error, int BadIndex=0 ) const;//BadIndex表示出错的下标
public:
	Array( int sz=50 );//构造函数,sz为长度
	Array( const Array<T>& A );//拷贝构造函数
	~Array( void );//析构函数
	Array<T>& operator=( const Array<T>& rhs );//对赋值运算符重载
	T& operator[]( int );//对[]运算符重载
	operator T*() const;
	int ListSize() const;//求数组的长度
	void Resize( int sz );//重新定义数组的长度
};
template < class T >/模板函数Error实现输出错误信息功能
void Array<T>::Error( ErrorType error, int BadIndex ) const
{
	cout<<ErrorMsg[error];//根据错误类型输出相应的错误信息
	if( error==IndexOutOfRange )
		cout<<BadIndex;//如果下标越界,输出错误下标
	cout<<endl;
	exit(1);
}

template < class T >//构造函数
Array<T>::Array( int sz )
{
	if( sz<=0 )//如果数组长度小于0则输出错误信息
		Error( InvalidArraySize );
	else
	{//如果数组长度大于0则生成数组
		size = sz;
		alist = new T[ size ];//动态生成数组
		if( alist==NULL )//如果分配内存不成功则输出错误信息
			Error( MemoryAllocationError );
	}
}

template < class T >
Array<T>::Array( const Array<T>& X )//拷贝构造函数（深拷贝）
{
	int n=X.size;
	size = n;
	alist = new T[n];
	if( alist==NULL )
		Error( MemoryAllocationError );
	T *srcptr = X.alist;//X.alist是对象X的数组首地址
	T *destptr = alist;//本对象数组首地址
	while ( n-- )//逐个复制数组
	{
		*destptr = *srcptr;
		destptr++;
		srcptr++;
	}

}

template < class T >
Array<T>::~Array( )//析构函数
{
	 delete [] alist;
}

template < class T >
Array<T>& Array<T>::operator = ( const Array<T>& rhs )//重载“=”运算符,将一个数组复制给另一个数组
{
	int n = rhs.size;
	if( size!= n )
	{
		delete [] alist;
		alist = new T[n];
		if( alist==NULL )
			Error( MemoryAllocationError );
		size = n;
	}
	//从rhs向本对象复制元素
	T* destptr = alist;
	T* srcptr = rhs.alist;
	while( n-- )
	{
		*destptr = *srcptr;
		destptr++;
		srcptr++;
	}
	return *this;//返回当前对象
}

template < class T >
T &Array<T>::operator []( int n )//重载“[]”运算符,实现通过下标访问数组元素
{
	if( n<0 || n>size-1 )//检查下标是否越界
		Error( IndexOutOfRange, n );
	return alist[n];//返回下标为n的数组元素
}

template < class T >//重载类型转换
Array<T>::operator T*()const
{
	return alist;
}

template < class T >//取当前数组的长度
int Array<T>::ListSize() const
{
	return size;
}

template < class T >
void Array<T>::Resize( int sz )//修改数组的长度sz
{
	if( sz<=0 )
		Error( InvalidArraySize );
	if( sz==size )
		return;
	T *newlist = new T[sz];
	if( newlist==NULL )
		Error( MemoryAllocationError );
	int n=( sz<=size )?sz:size;//将sz和size中较小的一个赋值给n
	T *srcptr = alist;//原数组的首地址
	T *destptr = newlist;//新数组的首地址
	while( n-- )
	{
		*destptr = *srcptr;
		destptr++;
		srcptr++;
	}
	delete [] alist;
	alist = newlist;
	size = sz;//使alist指向新数组,并更新sz
}