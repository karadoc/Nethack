#define CHAR 257
#define INTEGER 258
#define BOOLEAN 259
#define PERCENT 260
#define SPERCENT 261
#define MINUS_INTEGER 262
#define PLUS_INTEGER 263
#define MAZE_GRID_ID 264
#define SOLID_FILL_ID 265
#define MINES_ID 266
#define MESSAGE_ID 267
#define LEVEL_ID 268
#define LEV_INIT_ID 269
#define GEOMETRY_ID 270
#define NOMAP_ID 271
#define OBJECT_ID 272
#define COBJECT_ID 273
#define MONSTER_ID 274
#define TRAP_ID 275
#define DOOR_ID 276
#define DRAWBRIDGE_ID 277
#define MAZEWALK_ID 278
#define WALLIFY_ID 279
#define REGION_ID 280
#define FILLING 281
#define ALTAR_ID 282
#define LADDER_ID 283
#define STAIR_ID 284
#define NON_DIGGABLE_ID 285
#define NON_PASSWALL_ID 286
#define ROOM_ID 287
#define PORTAL_ID 288
#define TELEPRT_ID 289
#define BRANCH_ID 290
#define LEV 291
#define CHANCE_ID 292
#define CORRIDOR_ID 293
#define GOLD_ID 294
#define ENGRAVING_ID 295
#define FOUNTAIN_ID 296
#define POOL_ID 297
#define SINK_ID 298
#define NONE 299
#define RAND_CORRIDOR_ID 300
#define DOOR_STATE 301
#define LIGHT_STATE 302
#define CURSE_TYPE 303
#define ENGRAVING_TYPE 304
#define DIRECTION 305
#define RANDOM_TYPE 306
#define A_REGISTER 307
#define ALIGNMENT 308
#define LEFT_OR_RIGHT 309
#define CENTER 310
#define TOP_OR_BOT 311
#define ALTAR_TYPE 312
#define UP_OR_DOWN 313
#define SUBROOM_ID 314
#define NAME_ID 315
#define FLAGS_ID 316
#define FLAG_TYPE 317
#define MON_ATTITUDE 318
#define MON_ALERTNESS 319
#define MON_APPEARANCE 320
#define ROOMDOOR_ID 321
#define IF_ID 322
#define ELSE_ID 323
#define SPILL_ID 324
#define TERRAIN_ID 325
#define HORIZ_OR_VERT 326
#define REPLACE_TERRAIN_ID 327
#define EXIT_ID 328
#define SHUFFLE_ID 329
#define QUANTITY_ID 330
#define BURIED_ID 331
#define LOOP_ID 332
#define SWITCH_ID 333
#define CASE_ID 334
#define BREAK_ID 335
#define DEFAULT_ID 336
#define ERODED_ID 337
#define TRAPPED_ID 338
#define RECHARGED_ID 339
#define INVIS_ID 340
#define GREASED_ID 341
#define FEMALE_ID 342
#define CANCELLED_ID 343
#define REVIVED_ID 344
#define AVENGE_ID 345
#define FLEEING_ID 346
#define BLINDED_ID 347
#define PARALYZED_ID 348
#define STUNNED_ID 349
#define CONFUSED_ID 350
#define SEENTRAPS_ID 351
#define ALL_ID 352
#define MON_GENERATION_ID 353
#define MONTYPE_ID 354
#define GRAVE_ID 355
#define ERODEPROOF_ID 356
#define FUNCTION_ID 357
#define INCLUDE_ID 358
#define SOUNDS_ID 359
#define MSG_OUTPUT_TYPE 360
#define WALLWALK_ID 361
#define COMPARE_TYPE 362
#define rect_ID 363
#define fillrect_ID 364
#define line_ID 365
#define randline_ID 366
#define grow_ID 367
#define selection_ID 368
#define flood_ID 369
#define rndcoord_ID 370
#define circle_ID 371
#define ellipse_ID 372
#define filter_ID 373
#define STRING 374
#define MAP_ID 375
#define NQSTRING 376
#define VARSTRING 377
#define VARSTRING_INT 378
#define VARSTRING_INT_ARRAY 379
#define VARSTRING_STRING 380
#define VARSTRING_STRING_ARRAY 381
#define VARSTRING_VAR 382
#define VARSTRING_VAR_ARRAY 383
#define VARSTRING_COORD 384
#define VARSTRING_COORD_ARRAY 385
#define VARSTRING_REGION 386
#define VARSTRING_REGION_ARRAY 387
#define VARSTRING_MAPCHAR 388
#define VARSTRING_MAPCHAR_ARRAY 389
#define VARSTRING_MONST 390
#define VARSTRING_MONST_ARRAY 391
#define VARSTRING_OBJ 392
#define VARSTRING_OBJ_ARRAY 393
#define VARSTRING_SEL 394
#define VARSTRING_SEL_ARRAY 395
#define DICE 396
typedef union
{
	long	i;
	char*	map;
	struct {
		long room;
		long wall;
		long door;
	} corpos;
    struct {
	long area;
	long x1;
	long y1;
	long x2;
	long y2;
    } lregn;
    struct {
	long x;
	long y;
    } crd;
    struct {
	long ter;
	long lit;
    } terr;
    struct {
	long height;
	long width;
    } sze;
    struct {
	long die;
	long num;
    } dice;
} YYSTYPE;
extern YYSTYPE yylval;
