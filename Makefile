OBJDIR = obj
NAME = md

SRCS = main.cpp vector.cpp molecule.cpp operation.cpp mdfunctions.cpp 


CXX =g++

CXXFLAGS = -Wall -O2 -march=native -pipe -I. -std=c++11
CXXFLAGS = -Wall -O1 -march=native -pipe -I. -std=c++11 -g -fsanitize=address\ -fno-omit-frame-pointer
CXXFLAGS = -Wall -O0 -pipe -I. -g
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

clean:
	rm -rf $(OBJDIR)
	rm -f $(NAME)
