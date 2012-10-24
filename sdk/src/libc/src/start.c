/**
 *	Koala Operating System
 *	Copyright (C) 2010 - 2011 Samy Pess�
 *	
 *	This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundatn 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
 

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <os.h>

#define MAX_ENV_COUNT 256


int main(int argc, char *argv []);

int errno;

char** environ={
	"PATH","/bin/",
	NULL,NULL	
};

int __environ_allocated;


void _start(int argc, char** argv) {
	stdout=fdopen(0,"rw");
	stdin=fdopen(1,"rw");
	stderr=fdopen(2,"rw");
	int error;
    environ = 0;
    __environ_allocated = 0;

    /* Call the main function of the application */

    error = main( argc, argv);

    /* Exit the process */

    exit( error );
}