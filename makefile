# ----------------------------
# Makefile Options
# ----------------------------

NAME = TERRARIA
ICON = icon.png
DESCRIPTION = "Terraria for the TI-84+ CE"
COMPRESSED = YES
COMPRESSED_MODE = zx0
ARCHIVED = YES
PREFER_OS_CRT = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)

$(OBJDIR)/fonts.src: $(SRCDIR)/andy12.inc $(SRCDIR)/andy14.inc $(SRCDIR)/andy16.inc $(SRCDIR)/andy18.inc

$(SRCDIR)/%.inc: $(SRCDIR)/%.fnt
	convfont -o carray -f $< $@