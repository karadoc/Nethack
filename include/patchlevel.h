/*	SCCS Id: @(#)patchlevel.h	3.4	2003/12/06	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */



/* K-Mod 0.6.0 */
#define VERSION_MAJOR	0
#define VERSION_MINOR	7
/*
 * PATCHLEVEL is updated for each release.
 */
#define PATCHLEVEL	0
/*
 * Incrementing EDITLEVEL can be used to force invalidation of old bones
 * and save files.
 */
#define EDITLEVEL	0


#define COPYRIGHT_BANNER_A \
"Nethack, K-Mod edtion" 

#define COPYRIGHT_BANNER_B \
"         by Stichting Mathematisch Centrum and M. Stephenson, 1985-2003"

#define COPYRIGHT_BANNER_C \
"         K-Mod by karadoc, 2011."
 

/*
 * If two or more successive releases have compatible data files, define
 * this with the version number of the oldest such release so that the
 * new release will accept old save and bones files.  The format is
 *	0xMMmmPPeeL
 * 0x = literal prefix "0x", MM = major version, mm = minor version,
 * PP = patch level, ee = edit level, L = literal suffix "L",
 * with all four numbers specified as two hexadecimal digits.
 */
#define VERSION_COMPATIBILITY 0x00060000L	/* 0.6.0-0 */

// v0.6, initial K-Mod release.

/*****************************************************************************/

/*patchlevel.h*/
