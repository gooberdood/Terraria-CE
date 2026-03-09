# ----------------------------
# Makefile Options
# ----------------------------

NAME = Terraria
ICON = icon.png
DESCRIPTION = "Terraria CE Edition"
COMPRESSED = YES
COMPRESSED_MODE = zx0
ARCHIVED = YES
PREFER_OS_CRT = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
