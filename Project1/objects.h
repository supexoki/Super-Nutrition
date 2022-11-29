
enum IDS { PLAYER, BULLET, ENEMY };

typedef struct
{
	int ID;
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;

	int maxframe;
	int curframe;
	int framecount;
	int framedelay;
	int framewidth;
	int frameheight;
	int animationcolumns;
	int animationdirection;

	int animationrow;

	ALLEGRO_BITMAP* image;

}SpaceShip;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
}Bullet;

typedef struct 
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage;	
}Comet;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage;
}CometB;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage;
}CometC;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage2;
}Comet2;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage2;
}Comet2B;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage2;
}Comet2C;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage3;
}Comet3;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage3;
}Comet3B;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP* cometimage3;
}Comet3C;





