EXE = c3pe
SOURCES = main.c tpeapp.c tpeappwin.c
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

CPPFLAGS = `pkg-config --cflags gtk4`
CFLAGS = -std=c23 -g -Wall -Werror
LDFLAGS = `pkg-config --libs gtk4`

%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo $(EXE) build complete

$(EXE): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(EXE) $(OBJS)
