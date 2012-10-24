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
#ifndef __CONSOLE__
#define __CONSOLE__

#include <runtime/types.h>
#include <core/file.h>
#include <io.h>

#include <api/dev/ioctl.h>
#include <api/dev/tty.h>

class Console : public Device
{
	public:
		Console(char* n,u32 flag);
		~Console();
		
		
		u32		open(u32 flag);
		u32		close();
		u32		read(u32 pos,u8* buffer,u32 size);
		u32		write(u32 pos,u8* buffer,u32 size);
		u32		ioctl(u32 id,u8* buffer);
		u32		remove();
		void	scan();
		
		void	reset_info();
		
	private:
		tty_info_static	sinfo;
		tty_info_moving	minfo;
	
		Io*		iotty;
};

#endif