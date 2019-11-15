# http://www.ruanyifeng.com/blog/2015/02/make.html
test_shell:
	@echo $$HOME

arg1 := hello world
arg1 ?= hello chengqi
arg2 := $(arg1)
test2:
	@echo $(arg2)
output:
	# CC 是内置变量，指向当前的编译器
	@echo $(CC)
	@echo $(CXX)
	# MAKE指向当前使用的Make工具
	@echo $(MAKE)
