CC = g++
DIRS = run
DIR_RUN = run
HEADERS = $(wildcard *.h)
CPP_FILES = $(wildcard *.cpp)
EXES = $(addprefix $(DIR_RUN)/, $(CPP_FILES:.cpp=.out))
all: $(DIRS) $(EXES)
$(DIR_RUN)/%.out: %.o
	@$(CC) $^ -o $@
%.o: %.cpp
	@$(CC) -c $^ -o $@
$(DIRS):
	@mkdir $@
clean:
	@rm -rf $(DIRS) $(EXES)