//The CMP function used by the sort() function
//sort()函数所用的cmp函数
bool cmp(tou x, tou y) {
	
	if (x.xxx == y.xxx) 
		return x.num < y.num;
	return x.xxx > y.xxx;
}
bool cmp1(tou x, tou y) {
	return x.num < y.num;
}
