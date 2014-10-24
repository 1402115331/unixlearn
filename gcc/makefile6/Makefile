flag=true
Hobby=Reading
Pc=windows
#用模式定义法，给所有的局部变量定义Age为10，查看结果
%.a:modo=100

all.a : Age = 20
all.a : gender = 男
all.a : home = sd
all.a :
	@echo "年龄:$(Age),性别:$(gender),住址$(home),模式$(modo)"

test.a:Hobby=Computer
test.a:
	@echo "Hobby:$(Hobby),Pc:$(Pc),flag:$(flag),Age:$(Age),模式:$(modo)"

#通过以上实验可以发现，makefile的三段式，本质上和一个方法是非常相似的，target代表的是方法名，依赖代表的是参数列表，command代表的是方法执行主体，同样的在三段式的内部可以声明局部变量(如上)，在最外部可以申请全局变量，可以用export把全局变量导出。。。和c如此相似
#需要说明的一点是\放在最后的时候不允许后面还有空格，否则就表示另起一行啦，这个在shell中也能很好的验证这一点
#
