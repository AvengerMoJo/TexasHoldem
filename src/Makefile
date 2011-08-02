
CPP = g++
CPPFLAGS = -O2
HEADERS = Card.h Deck.h Hand.h
OBJS = Card.o Deck.o Hand.o

%.o: %.cpp $(HEADERS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

all: $(OBJS)

