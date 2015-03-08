/***********************************************************************
 * BasicOS Operating System
 * 
 * File: kernel/kernel.c
 * 
 * Description:
 * 	This is the entry point for the main kernel.
 * 
 * License:
 * BasicOS Operating System - An experimental operating system.
 * Copyright (C) 2015 Aun-Ali Zaidi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 ***********************************************************************/

#include <bos/k/common.h>
#include <bos/k/vga.h>
#include <bos/k/defs.h>

#ifdef _x86
	#include <bos/k/arch/x86/x86.h>
#else
#endif

#include <hw/cpuid.h>

#include <libk/stdio.h>

void _k_early()
{
	#ifdef _x86
		init_x86();
	#else
	#endif
}

// The Kernel's Main Entrypoint : kmain
void _k_main()
{
	tty_init();
	serial_init();

	// Print logo
        vga_write(ASCII_LOGO);

        // Display build an authoring info
        vga_write("BasicOS ver. "BAS_VER_FUL"\n");
        vga_write(AUTHOR_NOTE"\n");
        vga_write(COMPILE_NOTE"\n\n");

	// Display CPU info
	cpu_info();

	// Print a warm welcome!
        vga_write("Hello, User!");

	// Fake kernel Panic
	//_k_panic("[LOLZ] Just A test! ;)", __FILE__, __LINE__);

        // Hang up the computer
        for (;;);
}
