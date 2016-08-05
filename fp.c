/* Time-stamp: <2016-08-05 02:00:16 andreiw>
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

#define _GNU_SOURCE
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main(int argc,
	 char **argv)
{
	char *cwd;
	int i = 1;
	bool do_u_h = false;
	char h[HOST_NAME_MAX] = { 0 };

	if (!strcmp(basename(strdup(argv[0])),
		    "sfp")) {
		gethostname(h, HOST_NAME_MAX);
		do_u_h =  true;
	}

	cwd = get_current_dir_name();

	do {
		if (do_u_h) {
			printf("%s@%s:",
			       getlogin(), h);
		}

		fputs(cwd, stdout);
		if (argc != 1) {
			putchar('/');
			fputs(argv[i++], stdout);
		}
		putchar('\n');
	} while (i < argc);

	return 0;
}


