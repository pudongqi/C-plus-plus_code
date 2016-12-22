重载流运算符



ostream& operator<< (ostream& os, const 类类型 &obj)
{
	os<<…………//obj数据成员逐个输出

	return os;//必须返回ostream对象
}

istream& operator>> (istream& is, const 类类型 &obj)
{
	is>>…………//逐个输入obj数据成员

	return is;
}

要返回流对象的引用类型，是因为无论流插入或是流提取都需要连续输入或输出。
流插入和流提取重载函数不能是类的成员函数，只能是友元函数。
