/* Time-stamp: <2016-08-23 01:23:42 andreiw>
   Copyright (C) 2016 Andrei Evgenievich Warkentin

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main(int argc,
	 char **argv)
{
	int i = 1;
	bool do_u_h = false;
	char h[HOST_NAME_MAX] = { 0 };

	if (!strcmp(basename(strdup(argv[0])),
		    "sfp")) {
		gethostname(h, HOST_NAME_MAX);
		do_u_h =  true;
	}

	do {
		char *pr, *pb, *dr, *r, *b;

		if (argc == 1) {
			pr = strdup(".");
		} else {
			pr = strdup(argv[i++]);
		}
		pb = strdup(pr);

		b = basename(pb);
		if (!strcmp(b, "..") ||
		    !strcmp(b, ".") ||
		    !strcmp(b, "/")) {
			dr = pr;
			*b = '\0';
		} else {
			dr = dirname(pr);
		}

		r = realpath(dr, NULL);
		if (r == NULL) {
			fprintf(stderr, "%s: %s\n", pr, strerror(errno));
		} else {
			if (do_u_h) {
				printf("%s@%s:",
				       getlogin(), h);
			}

			fputs(r, stdout);
			if (strlen(b) != 0) {
				if (strlen(r) > 1 || *r != '/') {
					putchar('/');
				}

				fputs(b, stdout);
			}
			putchar('\n');
		}

		free(pr);
		free(pb);
	} while (i < argc);

	return 0;
}


