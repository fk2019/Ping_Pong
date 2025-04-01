TARGET = ping_pong.exe
BUILD_DIR = .build
SOURCE_DIR = src
CC := x86_64-w64-mingw32-gcc #compatibility with windows os
CFLAGS_BASE = -I/usr/x86_64-w64-mingw32/include/SDL2 -Dmain=SDL_main
CFLAGS_RELEASE = -O2
LDFLAGS ?=
LDLIBS_BASE = -L/opt/local/x86_64-w64-mingw32/lib -lSDL2 -lSDL2main -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf -mwindows
SRCS = $(wildcard $(SOURCE_DIR)/*.c)
OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS ?= $(CFLAGS_BASE)
LDLIBS ?= $(LDLIBS_BASE)
$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	@echo "Compiling into object files...."
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@echo "Linking into an executable file..."
	$(CC) $^ -o $@ $(LDLIBS)
CLEAN = $(RM) -r $(TARGET) $(BUILD_DIR)

.PHONY: all clean run rebuild release

all: $(TARGET)

release: CFLAGS = $(CFLAGS_BASE)
release: LDLIBS = $(LDLIBS_BASE)
release: all
clean:
	$(CLEAN)

run: $(TARGET)
	./$<

rebuild: clean all
