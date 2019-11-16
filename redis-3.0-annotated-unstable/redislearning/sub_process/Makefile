# http://www.ruanyifeng.com/blog/2015/02/make.html
# https://www.hackerearth.com/zh/practice/notes/the-make-command-and-makefiles/
OPT ?= -g2

SOURCE_CODE += $(shell find . -name '*.c')
OBJECTS += $(SOURCE_CODE:.c=.o)
EXE_OBJECTS = sub_process


# 按顺序执行，如果make后面不加参数，会执行make ALL。 如果EXE_OBJECTS没有变化，则不会执行sub_process
ALL: $(EXE_OBJECTS)
	@echo $(OBJECTS)

sub_process:$(OBJECTS)
	@echo $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

%.o:%.c
	$(CXX) -c $< -o $@

test_shell:
	@echo $$HOME
	@echo $(AR)

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
	# TARGET_OS
	@echo $(TARGET_OS)
HANDY_SOURCES += $(shell find . -name '*.c')
HANDY_OBJECTS = $(HANDY_SOURCES:.c=.o)

test:
	@echo $(HANDY_OBJECTS)
