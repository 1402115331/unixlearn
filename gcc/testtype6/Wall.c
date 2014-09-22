/***
 gcc -W   Wall.c 
 gcc -Wall  -W   Wall.c 
 gcc -Wall  -W -c  Wall.c 
默认的只是用-Wall来检查的，有些内容错误是检查不出来的，但是可以通过制定另外的检查标记来检查 -W -c就是检查哪些永远不会使用的代码的
还有如下：
-Wshadow 检查变量名和方法名重复定义问题
-Wcast-qual 这是检查,强制转换去掉const修饰问题（如果不检查其实const的常量作用可以被时间取消的）
-Wwrite-strings const的字符串进制重新赋值
默认情况下无论是-Wall还是上述单独的检查，都不会终止程序的生成，但是可以用-Werror来设置如果有Warn就停止编译
-Wall  Warn all
-Werror Warn error
-Wcast-qual Warn qual
-Wshadow Warn shadow
-Wuninitialized 是检查未初始化的数据的默认被包含在-Wall中的
发现-W就是Warn的意思

***/
int main(){
unsigned int x;
if(x<0){
return 0;
}else{
return 1;
}

} 

