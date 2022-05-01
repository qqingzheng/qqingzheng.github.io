CC = g++
DIRS = build
DIRS_BUILD = build
HEADERS = $(wildcard *.h)
CPP_FILES = $(wildcard *.cpp)
OBJS = $(addprefix $(DIRS_BUILD)/, $(CPP_FILES:.cpp=.o))
EXE = test
all: $(DIRS) $(EXE)
$(EXE): $(OBJS)
	$(CC) $^ -o $@
$(DIRS_BUILD)/%.o: %.cpp
	$(CC) -c $^ -o $@
$(DIRS):
	@mkdir $@
clean:
	@rm -rf $(DIRS)