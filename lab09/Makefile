%: %.c rss.c rss.h
	gcc `xml2-config --cflags` -Wall -Wextra -Wno-unused-result -Wno-sign-compare -O2 -g $< rss.c `xml2-config --libs` -lm -o $@
