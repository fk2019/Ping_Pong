TARGET = pong
BUILD_DIR = .build
SOURCE_DIR = src
CC ?= gcc
CFLAGS_BASE =  -std=c99 $(shell pkg-config --cflags sdl2)
CFLAGS_RELEASE = -O2
LDFLAGS ?=
LDLIBS_BASE = $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf SDL2_mixer) -lm
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
