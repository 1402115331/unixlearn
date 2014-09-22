/**
 gcc pedantic.c -ansi -pedantic  -o pedantic
 gcc pedantic.c -ansi  -o pedantic
 gcc pedantic.c -o pedantic
默认的gnu和ansi都是可以编译通过变量数组的，这只是gcc这样实现的，而根据ansi的文档标准是不允许变量数组的，如果你一定要完全按照文档（尽可能）编译，gcc也是允许的-padantic就是这个作用设置的，另外可以注意到，gcc给这个功能一个padantic关键字 意思是学究的 卖弄学问的 迂腐的，可以看出gcc开发者对这种检查的态度


**/
int main(int argc,char **argv){
	int i,n=argc;
	double x[n];
	for(i=0;i<n;i++){
		x[i]=i;
	}
	return 0;
}
