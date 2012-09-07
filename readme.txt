This is K-Mod, version 0.7.1, a nethack mod that focuses on improving balance.

Introduction:
The main motivation for K-Mod is that I believe Nethack is a really fun game, but that it suffers from many balance problems and game-play weaknesses. I enjoy playing nethack a lot, and I also enjoy thinking of ways to improve games. So I've been making this mod for my own enjoyment. But I'm quite pleased with the work I've done and so I'm happy to share the mod for others to enjoy.

The design goals for this mod are basically the same as for "Sporkhack", http://sporkhack.com/design_concept.html, (although this mod is completely separate to sporkhack).

The version number being less than 1.0 indicates that this is an unfinished product. There are more gameplay changes that I intend to make; and I have not tested for compatibility on anything other than my own computer. (I play "NetHackW" on Windows 7.) There may be interface problems or build problems on your favourite system; I just don't know. Feel free to tell me if you have any trouble.

Unfortunately, I can't offer an online server to play K-Mod on. I'm sorry about that. So unless someone else wants to set up a K-Mod server we'll all just have to play solo.


Major changes:
+ Implemented a bones file queue, so that each level can store up to 11 bones files which will be consumed in the order that they are created.
+ Resistances now come in two flavours 'resistance' (intrinsic resistance) and 'immunity' (extrinsic resistance). This effects fire, cold, shock, and poison. Some poison resistance effects now use Luck. In-game, both types are referred to as 'resistance', but some messages will be different if you don't have extrinsic resistance. The main result of this change is that resistance from rings & armour is no longer useless in the end-game.
+ Rebalanced max lvl of random monsters to increase with time (game moves), and to depend less on your character level. This means that the early game will be slightly easier, and leveling up your character will not be such a disadvantage, but if you spent too long on the lower dungeon levels the game will get harder.
+ Implemented a skill grouping system. Related skills share their skill-points, but not their practice. Skills that will be automatically enhanced without skill points are marked with '^' on the enhance menu. The purpose of this change is to increase the viability of spending skill-points in some of the less useful weapon types.

Map changes:
+ I went to great lengths to merge the changes I've made so far with the map changes from sporkhack. (only the map changes for now) This includes some new medusa levels, gnomish mines levels, "big rooms", and different quest maps (some of which I haven't tested). Most levels can now be reflected, so that the same old maps might look a bit unfamiliar. And perhaps most significant map change is that most of the end-game maze levels have been replaced with a different kind of level, with lava etc.
+ I've implemented some new random level styles. These new styles will occasionally show up in the dungeons of doom. For example, a level might turn out to be a grid of rooms, or a ring. Sporkhack had the basic idea, but it wasn't implemented properly. I think I've done it properly.
+ Added a couple of new sokoban levels (in addition to reflections of the original levels). These are levels that I've made myself, so you won't see them in any other game. The levels are designed to require good sokoban skills, but not to be time-consuming.
+ On the topic of sokoban; in K-Mod, items won't spawn on holes! (They can still spawn on pits and trapdoors though.)

Interface changes:
+ sortloot patch
+ msgtype patch
+ pickup_thrown patch
+ dumpfile patch
+ weight of carried items is now displayed in the inventory menus
+ Added toggle for "pickup all", in addition to the usual auto-pickup toggle. The command is meta+@.
+ Added meta+x hotkey for #twoweapon
+ The enhance menu will show the max level that skills can be practised to.
+ Replaced 'sparkle' boolean option with 'sparkle_speed' integer option, so that you can still have the sparkle effect without it taking so long.

New items:
I don't intend to add a lot of items. I've just added a few things which I think fulfill a role that should be fulfilled.
+ Silver short sword
+ 'Insanity's Edge', a silver short sword artifact.
+ 'Gungnir', a silver spear artifact.
+ Helm of anti-magic; which provides magic resistance but also has some negative side effects. ("horned helmet" is added to the random magic helm pool)
.. that's all for now. But I've implemented a 'version conversion' system which allows new items to be added to K-Mod without breaking save / bones file compatibility. For example, the helm of anti-magic was added most recently, but saves and bones from before it was added will still work.

Balance changes:
I've changed many of the game-mechanics formulas, and I've tweaked the numbers associated with all manner of monsters, spells, items, weights, damage, probabilities, minor game events and so on. Generally the changes will make the game a little bit harder, (many monsters and traps do more damage), but some changes also make the game easier (early-game armour is slightly lighter and a bit more powerful). In general, my aim is to make the end-game a bit more interesting than it is vanilla (unmodded) Nethack. My main complaint about the end-game in vanilla is that the hero becomes immune to essentially everything; as the game goes on, the elements of strategy and planning and thinking and fun that exist in the early game are eliminated one by one as the hero gets stronger. Therefore, many of my balance changes are about not letting the hero get absolute immunity to all dangerous effects - but I don't necessarily want to make the game harder.

Here I'll list a few changes that I think are interesting, or worth knowing about. I have a longer changelist that I can provide upon request; and I'm happy to answer any questions about why I've made any particular change.

+ Spears and javelins gets a significant damage bonus if you thrown them and are 'skilled' or 'expert'.
+ Eating a corpse that 'tastes terrible' will abuse your constitution a little (but it isn't a big deal).
+ Made it possible to refresh knowledge of spells sooner (changed from 1000 remaining turns to 5000 remaining turns), and also, there is now a visual indicator on the spells list which shows which spells can be refreshed.
+ Engraving is a bit slower. It will usually take a couple of turns to engrave a word. And engraving doesn't exercise your wisdom.
+ Unicorn horns will not restore lost attribute points. Use a potion of restore ability instead.
+ Unicorn horns now need to rest (age, recharge) between uses to be reliable. So don't use your unicorn to cure trivial conditions!
+ Magic negation from armour (usually called mc) is less effective than before (Beware: some monsters, including vampires, are significantly more dangerous as a result of this).
+ Completely reworked the player hp regen system. Early game regen is roughly the same, but end game regen is now lower than before. Regen scales smoothly with character level. Magical regeneration is more powerful at higher levels (eg from a ring of regeneration).
+ Diluted potions of healing only increase max hp by half of their usual amount (but the still heal you just as much).
+ Orange dragon scales now give free action instead of only sleep resistance.
+ Enemies have an additional chance to resist 'conflict', based on their level, the dungeon level, and your level. Conflict will still work most of the time, but it will just be a bit less effective than before.
+ Levitation will not prevent you from drowning if you are still underwater...
+ Your fire resistance will not protect your equipment from lava (fireproof items still won't burn though!)
+ Decreased the protection that can be bought from priests or granted by your god. The probability of being granted protection decreases with each point.
+ Slightly increased the bonus damage from strength, and doubled the bonus for 2-handed weapons.
+ The bite attack of dragons now has a special effect for each dragon type. Red: fire, white: cold, blue: electric, yellow: acid, black: acid as well (disintergration might be a bit too harsh), orange: paralysis, gray: stun, green: poison, silver: no special effect. So watch out! Blue dragons and orange dragons are particularly dangerous.

 
As I said, there are many many other changes, but most of them you can find out by playing, and some are just so minor that they aren't worth mentioning. So just try it out, and have fun.

If you have any feedback, comments, questions, bug reports, suggestions, abuse, or whatever you'd like me to hear, feel free to email me:
karadoc@gmail.com
or post on http://groups.google.com/group/rec.games.roguelike.nethack/topics and just hope I see it, or contact me in some other way.

The source code for this project can be downloaded from https://github.com/karadoc/Nethack
