CXXFILES := $(shell ls *.cpp *.h)
OBJECTS := $(CXXFILES:.cpp=.o)
PROGNAME := test

all: $(PROGNAME)


%.d:%.cpp
	g++ -MM $(CXXFLAGS) $< | sed 's/\(.*\).o:/\1.o \1.d:/' > $@
	
$(PROGNAME):  $(OBJECTS)
	set -e; g++ -g -o $(PROGNAME) $(OBJECTS); set +e; 
	
-include $(DEPENDENCIES)

clean:
	rm -f *.o *.d;
	
