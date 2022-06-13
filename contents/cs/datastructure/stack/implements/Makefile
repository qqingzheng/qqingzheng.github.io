includePath = "../../list/implements/"
headerFiles = $(wildcard *.h)
cppFiles = $(wildcard *.cpp)
outputDir = run
outFiles = $(addprefix $(outputDir)/, $(cppFiles:.cpp=.out))
all: $(outputDir) $(outFiles)
$(outputDir)/%.out: %.cpp
	g++ $^ -o $@ -I$(includePath)
	$@
$(outputDir): 
	mkdir $@
clean:
	rm -rf $(outputDir)
	rm core*
test:
	$(outFiles:\ =\ \ )