/*	SCCS Id: @(#)exper.c	3.4	2002/11/20	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

#include "hack.h"

STATIC_DCL long FDECL(newuexp, (int));
STATIC_DCL int FDECL(enermod, (int));

STATIC_OVL long
newuexp(lev)
int lev;
{
/*
** K-Mod, 17/march/2011, karadoc
** Decreased xp requirements for lev 12 and up
*/
	/* original code
	if (lev < 10) return (10L * (1L << lev));
	if (lev < 20) return (10000L * (1L << (lev - 10)));
	return (10000000L * ((long)(lev - 19))); */
	if (lev < 11) return (10L * (1L << lev));
	return 3400L * (lev - 9)*(lev - 8);
// K-Mod end
}

STATIC_OVL int
enermod(en)
int en;
{
	switch (Role_switch) {
	case PM_PRIEST:
	case PM_WIZARD:
	    return(2 * en);
	case PM_HEALER:
	case PM_KNIGHT:
	    return((3 * en) / 2);
	case PM_BARBARIAN:
	case PM_VALKYRIE:
	    return((3 * en) / 4);
	default:
	    return (en);
	}
}

int
experience(mtmp, mnum)	/* return # of exp points for mtmp, or monster type mnum */
	register struct	monst *mtmp;
	short mnum;
#if defined(macintosh) && (defined(__SC__) || defined(__MRC__))
# pragma unused(nk)
#endif
{
	int	i, tmp, tmp2, mlvl;
	register struct permonst *mdat;

	if (mtmp)
	{
		mnum = mtmp->mnum;
		mdat = mtmp->data;
		mlvl = mtmp->m_lev;
	}
	else
	{
		mdat = &mons[mnum];
		mlvl = mdat->mlevel;
	}

	tmp = 1 + mlvl * mlvl;

/*	For higher ac values, give extra experience */
	tmp2 = (mtmp ? find_mac(mtmp) : mdat->ac);
	if (tmp2 < 3) tmp += (7 - tmp2) * ((tmp2 < 0) ? 2 : 1);

/*	For very fast monsters, give extra experience */
	if (mdat->mmove > NORMAL_SPEED)
	    tmp += (mdat->mmove > (3*NORMAL_SPEED/2)) ? 5 : 3;

/*	For each "special" attack type give extra experience */
	for(i = 0; i < NATTK; i++) {

	    tmp2 = mdat->mattk[i].aatyp;
	    if(tmp2 > AT_BUTT) {

		if(tmp2 == AT_WEAP) tmp += 5;
		else if(tmp2 == AT_MAGC) tmp += 10;
		else tmp += 3;
	    }
	}

/*	For each "special" damage type give extra experience */
	for(i = 0; i < NATTK; i++) {
	    tmp2 = mdat->mattk[i].adtyp;
	    if(tmp2 > AD_PHYS && tmp2 < AD_BLND) tmp += 2*mlvl;
	    else if((tmp2 == AD_DRLI) || (tmp2 == AD_STON) ||
	    		(tmp2 == AD_SLIM)) tmp += 50;
	    else if(tmp != AD_PHYS) tmp += mlvl;
		/* extra heavy damage bonus */
	    if((int)(mdat->mattk[i].damd * mdat->mattk[i].damn) > 23)
		tmp += mlvl;
	    if (tmp2 == AD_WRAP && mdat->mlet == S_EEL && !Amphibious)
		tmp += 1000;
	}

/*	For certain "extra nasty" monsters, give even more */
	if (extra_nasty(mdat)) tmp += (7 * mlvl);

/*	For higher level monsters, an additional bonus is given */
	if(mlvl > 8) tmp += 50;

#ifdef MAIL
	/* Mail daemons put up no fight. */
	if(mtmp->data == &mons[PM_MAIL_DAEMON]) tmp = 1;
#endif

	return(tmp);
}

/*
 * Adds to Experience and Scoring counter
 */
void
more_experienced(exp, score)
	register int exp, score;
{
	u.uexp += exp;
	/* u.urexp += 4*exp + rexp; */
	u.urscore += score;
	if(exp
#ifdef SCORE_ON_BOTL
	   || flags.showscore
#endif
	   ) flags.botl = 1;
	/* disabled by K-Mod. (what is the purpose of flags.beginner anyway?)
	if (u.urexp >= (Role_if(PM_WIZARD) ? 1000 : 2000)) */
		flags.beginner = 0;
}

void
losexp(drainer)		/* e.g., hit by drain life attack */
const char *drainer;	/* cause of death, if drain should be fatal */
{
	register int num;

#ifdef WIZARD
	/* override life-drain resistance when handling an explicit
	   wizard mode request to reduce level; never fatal though */
	if (drainer && !strcmp(drainer, "#levelchange"))
	    drainer = 0;
	else
#endif
	    if (resists_drli(&youmonst)) return;

	if (u.ulevel > 1) {
		pline("%s level %d.", Goodbye(), u.ulevel--);
		/* remove intrinsic abilities */
		adjabil(u.ulevel + 1, u.ulevel);
		reset_rndmonst(NON_PM);	/* new monster selection */
	} else {
		if (drainer) {
			killer_format = KILLED_BY;
			killer = drainer;
			done(DIED);
		}
		/* no drainer or lifesaved */
		u.uexp = 0;
	}
	num = newhp();
	u.uhpmax -= num;
	if (u.uhpmax < 1) u.uhpmax = 1;
	u.uhp -= num;
	if (u.uhp < 1) u.uhp = 1;
	else if (u.uhp > u.uhpmax) u.uhp = u.uhpmax;

	if (u.ulevel < urole.xlev)
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.lornd + urace.enadv.lornd,
			urole.enadv.lofix + urace.enadv.lofix);
	else
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.hirnd + urace.enadv.hirnd,
			urole.enadv.hifix + urace.enadv.hifix);
	num = enermod(num);		/* M. Stephenson */
	u.uenmax -= num;
	if (u.uenmax < 0) u.uenmax = 0;
	u.uen -= num;
	if (u.uen < 0) u.uen = 0;
	else if (u.uen > u.uenmax) u.uen = u.uenmax;

	if (u.uexp > 0)
		u.uexp = newuexp(u.ulevel) - 1;
	flags.botl = 1;
}

/*
 * Make experience gaining similar to AD&D(tm), whereby you can at most go
 * up by one level at a time, extra expr possibly helping you along.
 * After all, how much real experience does one get shooting a wand of death
 * at a dragon created with a wand of polymorph??
 */
void
newexplevel()
{
	if (u.ulevel < MAXULEV && u.uexp >= newuexp(u.ulevel))
	    pluslvl(TRUE);
}

void
pluslvl(incr)
boolean incr;	/* true iff via incremental experience growth */
{		/*	(false for potion of gain level)      */
	register int num;

	if (!incr) You_feel("more experienced.");
	num = newhp();
	u.uhpmax += num;
	u.uhp += num;
	if (Upolyd) {
	    num = rnd(8);
	    u.mhmax += num;
	    u.mh += num;
	}
	if (u.ulevel < urole.xlev)
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.lornd + urace.enadv.lornd,
			urole.enadv.lofix + urace.enadv.lofix);
	else
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.hirnd + urace.enadv.hirnd,
			urole.enadv.hifix + urace.enadv.hifix);
	num = enermod(num);	/* M. Stephenson */
	u.uenmax += num;
	u.uen += num;
	if (u.ulevel < MAXULEV) {
	    if (incr) {
		long tmp = newuexp(u.ulevel + 1);
		if (u.uexp >= tmp) u.uexp = tmp - 1;
	    } else {
		u.uexp = newuexp(u.ulevel);
	    }
	    ++u.ulevel;
	    if (u.ulevelmax < u.ulevel) u.ulevelmax = u.ulevel;
	    pline("Welcome to experience level %d.", u.ulevel);
	    adjabil(u.ulevel - 1, u.ulevel);	/* give new intrinsics */
	    reset_rndmonst(NON_PM);		/* new monster selection */
	}
	flags.botl = 1;
}

/* compute a random amount of experience points suitable for the hero's
   experience level:  base number of points needed to reach the current
   level plus a random portion of what it takes to get to the next level */
long
rndexp(gaining)
boolean gaining;	/* gaining XP via potion vs setting XP for polyself */
{
	long minexp, maxexp, diff, factor, result;

	minexp = (u.ulevel == 1) ? 0L : newuexp(u.ulevel - 1);
	maxexp = newuexp(u.ulevel);
	diff = maxexp - minexp,  factor = 1L;
	/* make sure that `diff' is an argument which rn2() can handle */
	while (diff >= (long)LARGEST_INT)
	    diff /= 2L,  factor *= 2L;
	result = minexp + factor * (long)rn2((int)diff);
	/* 3.4.1:  if already at level 30, add to current experience
	   points rather than to threshold needed to reach the current
	   level; otherwise blessed potions of gain level can result
	   in lowering the experience points instead of raising them */
	if (u.ulevel == MAXULEV && gaining) {
	    result += (u.uexp - minexp);
	    /* avoid wrapping (over 400 blessed potions needed for that...) */
	    if (result < u.uexp) result = u.uexp;
	}
	return result;
}

/*exper.c*/
