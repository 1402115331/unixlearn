#makefile的条件判断有三个 ifeq ifneq ifdef
#1.所有的判断内容必须是在方法体里的，也即，command的位置，并且tab是必须的
#2.ifeq ifneq必须是$()的形式
#3.而ifdef绝对不能是上述形式而不惜是单独的一个字符串名
eq = 1
define name
	zhy
endef

define (name)
zy
endef


testeq:
ifeq ($(eq),1)
	@echo "相等"
else 
	@echo "不相等"
endif
#--------------
testneq:
ifneq ($(eq),1)
	@echo "不相等"
else
	@echo "相等"
endif

#-------------
#无论define的结构体的内容是否带有tab，都可以正确检测
#切记ifdef后面的内容一定不能扩到括号里面，因为在里面括号会被当成变量名的一部分使用
testdef:
ifdef name
	@echo "name已经被定义了"
else
	@echo "name没有被定义"
endif

testdef2:
ifdef (name)
	@echo "(name)已经被定义了"
else
	@echo "(name)没有被定义"
endif
