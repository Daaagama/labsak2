CPP	:= g++

RM	:= rm -rf

CPPFLAGS	+= -Wall -g

FILES        := $(wildcard *.cpp)

OBJS	:= $(FILES:.cpp=.o)

NAME	:= main

all:        $(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
