#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include "objects.h"
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>






//1500 por 800
//Variáveis globais
const int WIDTH = 1920;
const int HEIGHT = 1000;
int NUM_BULLETS = 60;
int NUM_COMETS = 8;
int NUM_COMETS2 = 2;
int NUM_COMETS3 = 2;
int NUM_PROTEIN = 0;
int NUM_CARBO = 0;
int FatSpeed = 13;
int HealthyFoodsSpeed = 8;
enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };
bool keys[5] = { false, false, false, false };

//Protótipos

void InitShip(SpaceShip* ship, ALLEGRO_BITMAP* image);
void DrawShip(SpaceShip* ship);
void MoveShipUp(SpaceShip* ship);
void MoveShipDown(SpaceShip* ship);
void MoveShipLeft(SpaceShip* ship);
void MoveShipRight(SpaceShip* ship);


void InitBullet(Bullet bullet[], int size);
void DrawBullet(Bullet bullet[], int size);
void FireBullet(Bullet bullet[], int size, SpaceShip* ship);
void UpdateBullet(Bullet bullet[], int size);



void CollideBullet(Bullet bullet[], int bSize, Comet comets[], int cSize, SpaceShip *ship);
void CollideBulletB(Bullet bullet[], int bSize, CometB cometsB[], int cSize, SpaceShip* ship);
void CollideBulletC(Bullet bullet[], int bSize, CometC cometsC[], int cSize, SpaceShip* ship);

void CollideBullet2(Bullet bullet[], int bSize, Comet2 comets2[], int c2Size, SpaceShip* ship);
void CollideBullet2B(Bullet bullet[], int bSize, Comet2B comets2B[], int c2Size, SpaceShip* ship);
void CollideBullet2C(Bullet bullet[], int bSize, Comet2C comets2C[], int c2Size, SpaceShip* ship);

void CollideBullet3(Bullet bullet[], int bSize, Comet3 comets3[], int c3Size, SpaceShip* ship);
void CollideBullet3B(Bullet bullet[], int bSize, Comet3B comets3B[], int c3Size, SpaceShip* ship);
void CollideBullet3C(Bullet bullet[], int bSize, Comet3C comets3C[], int c3Size, SpaceShip* ship);




void InitComet(Comet comets[], int size, ALLEGRO_BITMAP*fat);
void InitCometB(CometB cometsB[], int size, ALLEGRO_BITMAP* fat2);
void InitCometC(CometC cometsC[], int size, ALLEGRO_BITMAP* fat3);

void InitComet2(Comet2 comets2[], int size, ALLEGRO_BITMAP*protein);
void InitComet2B(Comet2B comets2B[], int size, ALLEGRO_BITMAP* protein2);
void InitComet2C(Comet2C comets2C[], int size, ALLEGRO_BITMAP* protein3);

void InitComet3(Comet3 comets3[], int size, ALLEGRO_BITMAP* carbo);
void InitComet3B(Comet3B comets3B[], int size, ALLEGRO_BITMAP* carbo2);
void InitComet3C(Comet3C comets3C[], int size, ALLEGRO_BITMAP* carbo3);




void DrawComet(Comet comets[], int size);
void DrawCometB(CometB comets[], int size);
void DrawCometC(CometC comets[], int size);

void DrawComet2(Comet2 comets2[], int size);
void DrawComet2B(Comet2B comets2[], int size);
void DrawComet2C(Comet2C comets2[], int size);

void DrawComet3(Comet3 comets3[], int size);
void DrawComet3B(Comet3B comets3[], int size);
void DrawComet3C(Comet3C comets3[], int size);




void StartComet(Comet comets[], int size);
void StartCometB(CometB cometsB[], int size);
void StartCometC(CometC cometsC[], int size);

void StartComet2(Comet2 comets2[], int size);
void StartComet2B(Comet2B comets2B[], int size);
void StartComet2C(Comet2C comets2C[], int size);

void StartComet3(Comet3 comets3[], int size);
void StartComet3B(Comet3B comets3B[], int size);
void StartComet3C(Comet3C comets3C[], int size);




void UpdateComet(Comet comets[], int size);
void UpdateCometB(CometB cometsB[], int size);
void UpdateCometC(CometC cometsC[], int size);

void UpdateComet2(Comet2 comets2[], int size);
void UpdateComet2B(Comet2B comets2B[], int size);
void UpdateComet2C(Comet2C comets2C[], int size);

void UpdateComet3(Comet3 comets3[], int size);
void UpdateComet3B(Comet3B comets3B[], int size);
void UpdateComet3C(Comet3C comets3C[], int size);




void CollideComet(Comet comets[], int cSize, SpaceShip* ship);
void CollideCometB(CometB cometsB[], int cSize, SpaceShip* ship);
void CollideCometC(CometC cometsC[], int cSize, SpaceShip* ship);

void CollideComet2(Comet2 comets2[], int c2Size, SpaceShip* ship);
void CollideComet2B(Comet2B comets2B[], int c2Size, SpaceShip* ship);
void CollideComet2C(Comet2C comets2C[], int c2Size, SpaceShip* ship);

void CollideComet3(Comet3 comets3[], int c3Size, SpaceShip* ship);
void CollideComet3B(Comet3B comets3B[], int c3Size, SpaceShip* ship);
void CollideComet3C(Comet3C comets3C[], int c3Size, SpaceShip* ship);




int main(void)
{
	//Variável primitiva
	bool done = false;
	bool redraw = true;
	const int FPS = 60;
	bool isGameOver = false;
	bool gameWon = false;
	int inicio = 0;

	//Variável de objeto
	SpaceShip ship;
	Bullet bullets[60];

	Comet comets[15];
	CometB cometsB[15];
	CometC cometsC[15];

	Comet2 comets2[5];
	Comet2B comets2B[5];
	Comet2C comets2C[5];

	Comet3 comets3[5];
	Comet3B comets3B[5];
	Comet3C comets3C[5];

	//Variáveis do Allegro
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_SAMPLE* sample = NULL;
	ALLEGRO_FONT* font18 = NULL;
	ALLEGRO_FONT* font19 = NULL;
	ALLEGRO_FONT* font20 = NULL;

	ALLEGRO_BITMAP* shipimage;

	ALLEGRO_BITMAP* fat;
	ALLEGRO_BITMAP* fat2;
	ALLEGRO_BITMAP* fat3;

	ALLEGRO_BITMAP* protein;
	ALLEGRO_BITMAP* protein2;
	ALLEGRO_BITMAP* protein3;

	ALLEGRO_BITMAP* carbo;
	ALLEGRO_BITMAP* carbo2;
	ALLEGRO_BITMAP* carbo3;

	ALLEGRO_BITMAP* entrada;
	ALLEGRO_BITMAP* apresentacao;
	ALLEGRO_BITMAP* tutorial;


	if (!al_init()) //Inicializar Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);

	if (!display)
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();

	al_reserve_samples(1);

	sample = al_load_sample("8bit.ogg");

	

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	shipimage = al_load_bitmap("shooter.bmp");

	fat = al_load_bitmap("icecream.bmp");
	fat2 = al_load_bitmap("chocolate.bmp");
	fat3 = al_load_bitmap("pancake.bmp");
	

	protein = al_load_bitmap("chicken.bmp");
	protein2 = al_load_bitmap("steak.bmp");
	protein3 = al_load_bitmap("fish.bmp");

	carbo = al_load_bitmap("bread.bmp");
	carbo2 = al_load_bitmap("maca.bmp");
	carbo3 = al_load_bitmap("banana.bmp");

	al_convert_mask_to_alpha(protein3, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(carbo2, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(carbo3, al_map_rgb(255, 255, 255));

	entrada = al_load_bitmap("entrada.bmp");
	apresentacao = al_load_bitmap("apresentacao.bmp");
	tutorial = al_load_bitmap("tutorial.bmp");

	

	srand(time(NULL));
	InitShip(&ship, shipimage);
	InitBullet(bullets, NUM_BULLETS);

	InitComet(comets, NUM_COMETS, fat);
	InitCometB(cometsB, NUM_COMETS, fat2);
	InitCometC(cometsC, NUM_COMETS, fat3);

	InitComet2(comets2, NUM_COMETS2, protein);
	InitComet2B(comets2B, NUM_COMETS2, protein2);
	InitComet2C(comets2C, NUM_COMETS2, protein3);

	InitComet3(comets3, NUM_COMETS3, carbo);
	InitComet3B(comets3B, NUM_COMETS3, carbo2);
	InitComet3C(comets3C, NUM_COMETS3, carbo3);

	font18 = al_load_font("chocolada.ttf", 30, 0);
	font19 = al_load_font("chocolada.ttf", 50, 0);
	font20 = al_load_font("Plexiglass.ttf", 60, 0);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

	al_start_timer(timer);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if (keys[UP])
				MoveShipUp(&ship);
			if (keys[DOWN])
				MoveShipDown(&ship);
			if (keys[LEFT])
				MoveShipLeft(&ship);
			if (keys[RIGHT])
				MoveShipRight(&ship);

			if (inicio >= 3) {

				if (!isGameOver)
				{
					UpdateBullet(bullets, NUM_BULLETS);

					StartComet(comets, NUM_COMETS); ////////COMEÇAR DAQUI, VER AS FUNCOES QUE ESTAO AQUI E QUE NAO FORAM ADICIONADAS LA NO BOTTOM E ADICIONAR
					StartCometB(cometsB, NUM_COMETS);
					StartCometC(cometsC, NUM_COMETS);

					StartComet2(comets2, NUM_COMETS2);
					StartComet2B(comets2B, NUM_COMETS2);
					StartComet2C(comets2C, NUM_COMETS2);

					StartComet3(comets3, NUM_COMETS3);
					StartComet3B(comets3B, NUM_COMETS3);
					StartComet3C(comets3C, NUM_COMETS3);

					UpdateComet(comets, NUM_COMETS);
					UpdateCometB(cometsB, NUM_COMETS);
					UpdateCometC(cometsC, NUM_COMETS);

					UpdateComet2(comets2, NUM_COMETS2);
					UpdateComet2B(comets2B, NUM_COMETS2);
					UpdateComet2C(comets2C, NUM_COMETS2);

					UpdateComet3(comets3, NUM_COMETS3);
					UpdateComet3B(comets3B, NUM_COMETS3);
					UpdateComet3C(comets3C, NUM_COMETS3);

					CollideBullet(bullets, NUM_BULLETS, comets, NUM_COMETS, &ship);
					CollideBulletB(bullets, NUM_BULLETS, cometsB, NUM_COMETS, &ship);
					CollideBulletC(bullets, NUM_BULLETS, cometsC, NUM_COMETS, &ship);

					CollideBullet2(bullets, NUM_BULLETS, comets2, NUM_COMETS2, &ship);
					CollideBullet2B(bullets, NUM_BULLETS, comets2B, NUM_COMETS2, &ship);
					CollideBullet2C(bullets, NUM_BULLETS, comets2C, NUM_COMETS2, &ship);

					CollideBullet3(bullets, NUM_BULLETS, comets3, NUM_COMETS3, &ship);
					CollideBullet3B(bullets, NUM_BULLETS, comets3B, NUM_COMETS3, &ship);
					CollideBullet3C(bullets, NUM_BULLETS, comets3C, NUM_COMETS3, &ship);

					CollideComet(comets, NUM_COMETS, &ship);
					CollideCometB(cometsB, NUM_COMETS, &ship);
					CollideCometC(cometsC, NUM_COMETS, &ship);

					CollideComet2(comets2, NUM_COMETS2, &ship);
					CollideComet2B(comets2B, NUM_COMETS2, &ship);
					CollideComet2C(comets2C, NUM_COMETS2, &ship);

					CollideComet3(comets3, NUM_COMETS3, &ship);
					CollideComet3B(comets3B, NUM_COMETS3, &ship);
					CollideComet3C(comets3C, NUM_COMETS3, &ship);
				}

				if (ship.lives <= 0 || ship.lives >= 15)
				{
					isGameOver = true;
				}

			}
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				FireBullet(bullets, NUM_BULLETS, &ship);
				break;
			case ALLEGRO_KEY_ENTER:
				inicio++;
				break;
			}
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			}
		}

		
		

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			if (inicio >= 3) {

				if (!isGameOver)
				{
					DrawShip(&ship);
					DrawBullet(bullets, NUM_BULLETS);

					DrawComet(comets, NUM_COMETS);
					DrawCometB(cometsB, NUM_COMETS);
					DrawCometC(cometsC, NUM_COMETS);

					DrawComet2(comets2, NUM_COMETS2);
					DrawComet2B(comets2B, NUM_COMETS2);
					DrawComet2C(comets2C, NUM_COMETS2);

					DrawComet3(comets3, NUM_COMETS3);
					DrawComet3B(comets3B, NUM_COMETS3);
					DrawComet3C(comets3C, NUM_COMETS3);

					al_draw_textf(font20, al_map_rgb(0, 0, 0), WIDTH / 2, 930, ALLEGRO_ALIGN_CENTRE, "SUPER NUTRITION");

					al_draw_textf(font18, al_map_rgb(0, 0, 255), 480, 5, 0, "PONTOS: %i      GORDURAS DESTRUIDAS: %i     PROTEINAS: %i      CARBOIDRATOS: %i", ship.lives, ship.score, NUM_PROTEIN, ship.score);
				}
				else
				{
					if (ship.lives <= 0)
					{
						al_draw_textf(font19, al_map_rgb(255, 0, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Voce Perdeu!  Pontos Totais: %i", ship.score);

					}
					if (ship.lives >= 15)
					{
						al_draw_textf(font19, al_map_rgb(0, 0, 255), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Voce Ganhou!   Pontos Totais: %i", ship.score * ship.lives);
					}



				}

			}
			else if (inicio == 0)
			{
				al_draw_bitmap(entrada, 0, 0, 0);
			}
			else if (inicio == 1)
			{
				al_draw_bitmap(apresentacao, 0, 0, 0);
			}
			else if (inicio == 2)
			{
				al_draw_bitmap(tutorial, 0, 0, 0);
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(255, 255, 255));
		}

	}
	al_destroy_sample(sample);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(font18);
	
	

	return 0;

}

void InitShip(SpaceShip* ship, ALLEGRO_BITMAP* image)
{
	ship->x = 40;
	ship->y = HEIGHT / 2;
	ship->ID = PLAYER;
	ship->lives = 3;
	ship->speed = 4;
	ship->boundx = 30;
	ship->boundy = 40;
	ship->score = 0;

	ship->maxframe = 3;
	ship->curframe = 0;
	ship->framecount = 0;
	ship->framedelay = 50;
	ship->framewidth = 50;
	ship->frameheight = 28;
	ship->animationcolumns = 3;
	ship->animationdirection = 1;

	ship->animationrow = 1;

	ship->image = image;
}

void DrawShip(SpaceShip* ship)
{
	al_draw_bitmap(ship->image, ship->x - 45, ship->y - 30, 0);
}
void MoveShipUp(SpaceShip* ship)
{
	ship->y -= ship->speed;
	if (ship->y < 0)
	{
		ship->y = 0;
	}
}
void MoveShipDown(SpaceShip* ship)
{
	ship->y += ship->speed;
	if (ship->y > HEIGHT)
	{
		ship->y = HEIGHT;
	}
}
void MoveShipLeft(SpaceShip* ship)
{
	ship->x -= ship->speed;
	if (ship->x < 0)
	{
		ship->x = 0;
	}
}
void MoveShipRight(SpaceShip* ship)
{
	ship->x += ship->speed;
	if (ship->x > 1000)
	{
		ship->x = 1000;
	}
}

void InitBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		bullet[i].ID = BULLET;
		bullet[i].speed = 10;
		bullet[i].live = false;
	}
}
void DrawBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bullet[i].live)
			al_draw_filled_circle(bullet[i].x, bullet[i].y, 4, al_map_rgb(0, 0, 255));
	}
}
void FireBullet(Bullet bullet[], int size, SpaceShip* ship)
{
	for (int i = 0; i < size; i++)
	{
		if (!bullet[i].live)
		{
			bullet[i].x = ship->x + 17;
			bullet[i].y = ship->y;
			bullet[i].live = true;
			break;
		}

	}
}
void UpdateBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bullet[i].live)
		{
			bullet[i].x += bullet[i].speed;
			if (bullet[i].x > WIDTH)
			{
				bullet[i].live = false;
			}
		}
	}
}




void CollideBullet(Bullet bullet[], int bSize, Comet comets[], int cSize, SpaceShip *ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int j = 0; j < cSize; j++)
			{
				if (comets[j].live)
				{
					if (bullet[i].x > (comets[j].x - comets[j].boundx) &&
						bullet[i].x < (comets[j].x + comets[j].boundx) &&
						bullet[i].y >(comets[j].y - comets[j].boundy) &&
						bullet[i].y < (comets[j].y + comets[j].boundy))
					{
						bullet[i].live = false;
						comets[j].live = false;
						ship->score++;
						
					}
				}
			}
			
		}
	}
}
void CollideBulletB(Bullet bullet[], int bSize, CometB cometsB[], int cSize, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int j = 0; j < cSize; j++)
			{
				if (cometsB[j].live)
				{
					if (bullet[i].x > (cometsB[j].x - cometsB[j].boundx) &&
						bullet[i].x < (cometsB[j].x + cometsB[j].boundx) &&
						bullet[i].y >(cometsB[j].y - cometsB[j].boundy) &&
						bullet[i].y < (cometsB[j].y + cometsB[j].boundy))
					{
						bullet[i].live = false;
						cometsB[j].live = false;
						ship->score++;

					}
				}
			}

		}
	}
}
void CollideBulletC(Bullet bullet[], int bSize, CometC cometsC[], int cSize, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int j = 0; j < cSize; j++)
			{
				if (cometsC[j].live)
				{
					if (bullet[i].x > (cometsC[j].x - cometsC[j].boundx) &&
						bullet[i].x < (cometsC[j].x + cometsC[j].boundx) &&
						bullet[i].y >(cometsC[j].y - cometsC[j].boundy) &&
						bullet[i].y < (cometsC[j].y + cometsC[j].boundy))
					{
						bullet[i].live = false;
						cometsC[j].live = false;
						ship->score++;

					}
				}
			}

		}
	}
}

void CollideBullet2(Bullet bullet[], int bSize, Comet2 comets2[], int c2size, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int k = 0; k < c2size; k++)
			{
				if (comets2[k].live)
				{
					if (bullet[i].x > (comets2[k].x - comets2[k].boundx) &&
						bullet[i].x < (comets2[k].x + comets2[k].boundx) &&
						bullet[i].y >(comets2[k].y - comets2[k].boundy) &&
						bullet[i].y < (comets2[k].y + comets2[k].boundy))
					{
						bullet[i].live = false;
						comets2[k].live = false;
						ship->lives--;
						

					}
				}
			}
		}
	}
}
void CollideBullet2B(Bullet bullet[], int bSize, Comet2B comets2B[], int c2size, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int k = 0; k < c2size; k++)
			{
				if (comets2B[k].live)
				{
					if (bullet[i].x > (comets2B[k].x - comets2B[k].boundx) &&
						bullet[i].x < (comets2B[k].x + comets2B[k].boundx) &&
						bullet[i].y >(comets2B[k].y - comets2B[k].boundy) &&
						bullet[i].y < (comets2B[k].y + comets2B[k].boundy))
					{
						bullet[i].live = false;
						comets2B[k].live = false;
						ship->lives--;


					}
				}
			}
		}
	}
}
void CollideBullet2C(Bullet bullet[], int bSize, Comet2C comets2C[], int c2size, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int k = 0; k < c2size; k++)
			{
				if (comets2C[k].live)
				{
					if (bullet[i].x > (comets2C[k].x - comets2C[k].boundx) &&
						bullet[i].x < (comets2C[k].x + comets2C[k].boundx) &&
						bullet[i].y >(comets2C[k].y - comets2C[k].boundy) &&
						bullet[i].y < (comets2C[k].y + comets2C[k].boundy))
					{
						bullet[i].live = false;
						comets2C[k].live = false;
						ship->lives--;


					}
				}
			}
		}
	}
}

void CollideBullet3(Bullet bullet[], int bSize, Comet3 comets3[], int c3Size, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int k = 0; k < c3Size; k++)
			{
				if (comets3[k].live)
				{
					if (bullet[i].x > (comets3[k].x - comets3[k].boundx) &&
						bullet[i].x < (comets3[k].x + comets3[k].boundx) &&
						bullet[i].y >(comets3[k].y - comets3[k].boundy) &&
						bullet[i].y < (comets3[k].y + comets3[k].boundy))
					{
						bullet[i].live = false;
						comets3[k].live = false;
						ship->lives--;


					}
				}
			}
		}
	}
}
void CollideBullet3B(Bullet bullet[], int bSize, Comet3B comets3B[], int c3Size, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int k = 0; k < c3Size; k++)
			{
				if (comets3B[k].live)
				{
					if (bullet[i].x > (comets3B[k].x - comets3B[k].boundx) &&
						bullet[i].x < (comets3B[k].x + comets3B[k].boundx) &&
						bullet[i].y >(comets3B[k].y - comets3B[k].boundy) &&
						bullet[i].y < (comets3B[k].y + comets3B[k].boundy))
					{
						bullet[i].live = false;
						comets3B[k].live = false;
						ship->lives--;


					}
				}
			}
		}
	}
}
void CollideBullet3C(Bullet bullet[], int bSize, Comet3C comets3C[], int c3Size, SpaceShip* ship)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int k = 0; k < c3Size; k++)
			{
				if (comets3C[k].live)
				{
					if (bullet[i].x > (comets3C[k].x - comets3C[k].boundx) &&
						bullet[i].x < (comets3C[k].x + comets3C[k].boundx) &&
						bullet[i].y >(comets3C[k].y - comets3C[k].boundy) &&
						bullet[i].y < (comets3C[k].y + comets3C[k].boundy))
					{
						bullet[i].live = false;
						comets3C[k].live = false;
						ship->lives--;


					}
				}
			}
		}
	}
}




void InitComet(Comet comets[], int size, ALLEGRO_BITMAP*fat)
{
	for (int i = 0; i < size; i++)
	{
		comets[i].ID = ENEMY;
		comets[i].live = false;
		comets[i].speed = (rand() % 2) + 3;
		comets[i].boundx = 24;
		comets[i].boundy = 25;

		comets[i].cometimage = fat;
	}
}
void InitCometB(CometB cometsB[], int size, ALLEGRO_BITMAP* fat2)
{
	for (int i = 0; i < size; i++)
	{
		cometsB[i].ID = ENEMY;
		cometsB[i].live = false;
		cometsB[i].speed = (rand() % 2) + 3;
		cometsB[i].boundx = 24;
		cometsB[i].boundy = 25;

		cometsB[i].cometimage = fat2;
	}
}
void InitCometC(CometC cometsC[], int size, ALLEGRO_BITMAP* fat3)
{
	for (int i = 0; i < size; i++)
	{
		cometsC[i].ID = ENEMY;
		cometsC[i].live = false;
		cometsC[i].speed = (rand() % 2) + 3;
		cometsC[i].boundx = 24;
		cometsC[i].boundy = 25;

		cometsC[i].cometimage = fat3;
	}
}

void InitComet2(Comet2 comets2[], int size, ALLEGRO_BITMAP*protein)
{
	for (int i = 0; i < size; i++)
	{
		comets2[i].ID = ENEMY;
		comets2[i].live = false;
		comets2[i].speed = (rand() % 2) + 2;
		comets2[i].boundx = 19;
		comets2[i].boundy = 25;

		comets2[i].cometimage2 = protein;
	}
}
void InitComet2B(Comet2B comets2B[], int size, ALLEGRO_BITMAP* protein2)
{
	for (int i = 0; i < size; i++)
	{
		comets2B[i].ID = ENEMY;
		comets2B[i].live = false;
		comets2B[i].speed = (rand() % 2) + 2;
		comets2B[i].boundx = 19;
		comets2B[i].boundy = 25;

		comets2B[i].cometimage2 = protein2;
	}
}
void InitComet2C(Comet2C comets2C[], int size, ALLEGRO_BITMAP* protein3)
{
	for (int i = 0; i < size; i++)
	{
		comets2C[i].ID = ENEMY;
		comets2C[i].live = false;
		comets2C[i].speed = (rand() % 2) + 2;
		comets2C[i].boundx = 19;
		comets2C[i].boundy = 25;

		comets2C[i].cometimage2 = protein3;
	}
}

void InitComet3(Comet3 comets3[], int size, ALLEGRO_BITMAP* carbo)
{
	for (int i = 0; i < size; i++)
	{
		comets3[i].ID = ENEMY;
		comets3[i].live = false;
		comets3[i].speed = (rand() % 2) + 2;
		comets3[i].boundx = 22;
		comets3[i].boundy = 25;

		comets3[i].cometimage3 = carbo;
	}
}
void InitComet3B(Comet3B comets3B[], int size, ALLEGRO_BITMAP* carbo2)
{
	for (int i = 0; i < size; i++)
	{
		comets3B[i].ID = ENEMY;
		comets3B[i].live = false;
		comets3B[i].speed = (rand() % 2) + 2;
		comets3B[i].boundx = 22;
		comets3B[i].boundy = 25;

		comets3B[i].cometimage3 = carbo2;
	}
}
void InitComet3C(Comet3C comets3C[], int size, ALLEGRO_BITMAP* carbo3)
{
	for (int i = 0; i < size; i++)
	{
		comets3C[i].ID = ENEMY;
		comets3C[i].live = false;
		comets3C[i].speed = (rand() % 2) + 2;
		comets3C[i].boundx = 22;
		comets3C[i].boundy = 25;

		comets3C[i].cometimage3 = carbo3;
	}
}



void StartComet(Comet comets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets[i].live)
		{
			if (rand() % 500 == 0)
			{
				comets[i].live = true;
				comets[i].x = WIDTH ;
				comets[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}
void StartCometB(CometB cometsB[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!cometsB[i].live)
		{
			if (rand() % 500 == 0)
			{
				cometsB[i].live = true;
				cometsB[i].x = WIDTH;
				cometsB[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}
void StartCometC(CometC cometsC[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!cometsC[i].live)
		{
			if (rand() % 500 == 0)
			{
				cometsC[i].live = true;
				cometsC[i].x = WIDTH;
				cometsC[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}

void StartComet2(Comet2 comets2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets2[i].live)
		{
			if ((rand() % 500 == 0))
			{
				comets2[i].live = true;
				comets2[i].x = WIDTH;
				comets2[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}
void StartComet2B(Comet2B comets2B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets2B[i].live)
		{
			if ((rand() % 500 == 0))
			{
				comets2B[i].live = true;
				comets2B[i].x = WIDTH;
				comets2B[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}
void StartComet2C(Comet2C comets2C[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets2C[i].live)
		{
			if ((rand() % 500 == 0))
			{
				comets2C[i].live = true;
				comets2C[i].x = WIDTH;
				comets2C[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}

void StartComet3(Comet3 comets3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets3[i].live)
		{
			if ((rand() % 500 == 0))
			{
				comets3[i].live = true;
				comets3[i].x = WIDTH;
				comets3[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}
void StartComet3B(Comet3B comets3B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets3B[i].live)
		{
			if ((rand() % 500 == 0))
			{
				comets3B[i].live = true;
				comets3B[i].x = WIDTH;
				comets3B[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}
void StartComet3C(Comet3C comets3C[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets3C[i].live)
		{
			if ((rand() % 500 == 0))
			{
				comets3C[i].live = true;
				comets3C[i].x = WIDTH;
				comets3C[i].y = 30 + rand() % (HEIGHT - 60);
			}
		}
	}
}




void UpdateComet(Comet comets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets[i].live)
		{
			comets[i].x -= comets[i].speed;


		}
	}
}
void UpdateCometB(CometB cometsB[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (cometsB[i].live)
		{
			cometsB[i].x -= cometsB[i].speed;


		}
	}
}
void UpdateCometC(CometC cometsC[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (cometsC[i].live)
		{
			cometsC[i].x -= cometsC[i].speed;


		}
	}
}

void UpdateComet2(Comet2 comets2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets2[i].live)
		{
			comets2[i].x -= comets2[i].speed;


		}
	}
}
void UpdateComet2B(Comet2B comets2B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets2B[i].live)
		{
			comets2B[i].x -= comets2B[i].speed;


		}
	}
}
void UpdateComet2C(Comet2C comets2C[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets2C[i].live)
		{
			comets2C[i].x -= comets2C[i].speed;


		}
	}
}

void UpdateComet3(Comet3 comets3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets3[i].live)
		{
			comets3[i].x -= comets3[i].speed;


		}
	}
}
void UpdateComet3B(Comet3B comets3B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets3B[i].live)
		{
			comets3B[i].x -= comets3B[i].speed;


		}
	}
}
void UpdateComet3C(Comet3C comets3C[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets3C[i].live)
		{
			comets3C[i].x -= comets3C[i].speed;


		}
	}
}




void CollideComet(Comet comets[], int cSize, SpaceShip* ship)
{
	for (int i = 0; i < cSize; i++)
	{
		if (comets[i].live)
		{
			if (comets[i].x - comets[i].boundx < ship->x + ship->boundx &&
				comets[i].x + comets[i].boundx > ship->x - ship->boundx &&
				comets[i].y - comets[i].boundy < ship->y + ship->boundy &&
				comets[i].y + comets[i].boundy > ship->y - ship->boundy)
			{
				ship->lives--;
				comets[i].live = false;
			}
			else if (comets[i].x < 0)
			{
				comets[i].live = false;
				//
				
			}
		}

	}
}
void CollideCometB(CometB cometsB[], int cSize, SpaceShip* ship)
{
	for (int i = 0; i < cSize; i++)
	{
		if (cometsB[i].live)
		{
			if (cometsB[i].x - cometsB[i].boundx < ship->x + ship->boundx &&
				cometsB[i].x + cometsB[i].boundx > ship->x - ship->boundx &&
				cometsB[i].y - cometsB[i].boundy < ship->y + ship->boundy &&
				cometsB[i].y + cometsB[i].boundy > ship->y - ship->boundy)
			{
				ship->lives--;
				cometsB[i].live = false;
			}
			else if (cometsB[i].x < 0)
			{
				cometsB[i].live = false;
				//

			}
		}

	}
}
void CollideCometC(CometC cometsC[], int cSize, SpaceShip* ship)
{
	for (int i = 0; i < cSize; i++)
	{
		if (cometsC[i].live)
		{
			if (cometsC[i].x - cometsC[i].boundx < ship->x + ship->boundx &&
				cometsC[i].x + cometsC[i].boundx > ship->x - ship->boundx &&
				cometsC[i].y - cometsC[i].boundy < ship->y + ship->boundy &&
				cometsC[i].y + cometsC[i].boundy > ship->y - ship->boundy)
			{
				ship->lives--;
				cometsC[i].live = false;
			}
			else if (cometsC[i].x < 0)
			{
				cometsC[i].live = false;
				//

			}
		}

	}
}

void CollideComet2(Comet2 comets2[], int c2Size, SpaceShip* ship)
{
	for (int i = 0; i < c2Size; i++)
	{
		if (comets2[i].live)
		{
			if (comets2[i].x - comets2[i].boundx < ship->x + ship->boundx &&
				comets2[i].x + comets2[i].boundx > ship->x - ship->boundx &&
				comets2[i].y - comets2[i].boundy < ship->y + ship->boundy &&
				comets2[i].y + comets2[i].boundy > ship->y - ship->boundy)
			{
				ship->lives++;
				NUM_PROTEIN++;
				comets2[i].live = false;
			}
			else if (comets2[i].x < 0)
			{
				comets2[i].live = false;
				//

			}
		}

	}
}
void CollideComet2B(Comet2B comets2B[], int c2Size, SpaceShip* ship)
{
	for (int i = 0; i < c2Size; i++)
	{
		if (comets2B[i].live)
		{
			if (comets2B[i].x - comets2B[i].boundx < ship->x + ship->boundx &&
				comets2B[i].x + comets2B[i].boundx > ship->x - ship->boundx &&
				comets2B[i].y - comets2B[i].boundy < ship->y + ship->boundy &&
				comets2B[i].y + comets2B[i].boundy > ship->y - ship->boundy)
			{
				ship->lives++;
				NUM_PROTEIN++;
				comets2B[i].live = false;
			}
			else if (comets2B[i].x < 0)
			{
				comets2B[i].live = false;
				//

			}
		}

	}
}
void CollideComet2C(Comet2C comets2C[], int c2Size, SpaceShip* ship)
{
	for (int i = 0; i < c2Size; i++)
	{
		if (comets2C[i].live)
		{
			if (comets2C[i].x - comets2C[i].boundx < ship->x + ship->boundx &&
				comets2C[i].x + comets2C[i].boundx > ship->x - ship->boundx &&
				comets2C[i].y - comets2C[i].boundy < ship->y + ship->boundy &&
				comets2C[i].y + comets2C[i].boundy > ship->y - ship->boundy)
			{
				ship->lives++;
				NUM_PROTEIN++;
				comets2C[i].live = false;
			}
			else if (comets2C[i].x < 0)
			{
				comets2C[i].live = false;
				//

			}
		}

	}
}

void CollideComet3(Comet3 comets3[], int c3Size, SpaceShip* ship)
{
	for (int i = 0; i < c3Size; i++)
	{
		if (comets3[i].live)
		{
			if (comets3[i].x - comets3[i].boundx < ship->x + ship->boundx &&
				comets3[i].x + comets3[i].boundx > ship->x - ship->boundx &&
				comets3[i].y - comets3[i].boundy < ship->y + ship->boundy &&
				comets3[i].y + comets3[i].boundy > ship->y - ship->boundy)
			{
				ship->lives++;
				NUM_CARBO++;
				comets3[i].live = false;
			}
			else if (comets3[i].x < 0)
			{
				comets3[i].live = false;
				//

			}
		}

	}
}
void CollideComet3B(Comet3B comets3B[], int c3Size, SpaceShip* ship)
{
	for (int i = 0; i < c3Size; i++)
	{
		if (comets3B[i].live)
		{
			if (comets3B[i].x - comets3B[i].boundx < ship->x + ship->boundx &&
				comets3B[i].x + comets3B[i].boundx > ship->x - ship->boundx &&
				comets3B[i].y - comets3B[i].boundy < ship->y + ship->boundy &&
				comets3B[i].y + comets3B[i].boundy > ship->y - ship->boundy)
			{
				ship->lives++;
				NUM_CARBO++;
				comets3B[i].live = false;
			}
			else if (comets3B[i].x < 0)
			{
				comets3B[i].live = false;
				//

			}
		}

	}
}
void CollideComet3C(Comet3C comets3C[], int c3Size, SpaceShip* ship)
{
	for (int i = 0; i < c3Size; i++)
	{
		if (comets3C[i].live)
		{
			if (comets3C[i].x - comets3C[i].boundx < ship->x + ship->boundx &&
				comets3C[i].x + comets3C[i].boundx > ship->x - ship->boundx &&
				comets3C[i].y - comets3C[i].boundy < ship->y + ship->boundy &&
				comets3C[i].y + comets3C[i].boundy > ship->y - ship->boundy)
			{
				ship->lives++;
				NUM_CARBO++;
				comets3C[i].live = false;
			}
			else if (comets3C[i].x < 0)
			{
				comets3C[i].live = false;
				//

			}
		}

	}
}




void DrawComet(Comet comets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets[i].live)
		{
			al_draw_bitmap(comets->cometimage, comets[i].x - 30, comets[i].y - 30, 0);
		}
	}
}
void DrawCometB(CometB cometsB[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (cometsB[i].live)
		{
			al_draw_bitmap(cometsB->cometimage, cometsB[i].x - 30, cometsB[i].y - 30, 0);
		}
	}
}
void DrawCometC(CometC cometsC[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (cometsC[i].live)
		{
			al_draw_bitmap(cometsC->cometimage, cometsC[i].x - 30, cometsC[i].y - 30, 0);
		}
	}
}

void DrawComet2(Comet2 comets2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets2[i].live)
		{
			al_draw_bitmap(comets2->cometimage2, comets2[i].x - 30, comets2[i].y - 30, 0);
		}
	}
}
void DrawComet2B(Comet2B comets2B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets2B[i].live)
		{
			al_draw_bitmap(comets2B->cometimage2, comets2B[i].x - 30, comets2B[i].y - 30, 0);
		}
	}
}
void DrawComet2C(Comet2C comets2C[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets2C[i].live)
		{
			al_draw_bitmap(comets2C->cometimage2, comets2C[i].x - 30, comets2C[i].y - 30, 0);
		}
	}
}

void DrawComet3(Comet3 comets3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets3[i].live)
		{
			al_draw_bitmap(comets3->cometimage3, comets3[i].x - 30, comets3[i].y - 30, 0);
		}
	}
}
void DrawComet3B(Comet3B comets3B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets3B[i].live)
		{
			al_draw_bitmap(comets3B->cometimage3, comets3B[i].x - 30, comets3B[i].y - 30, 0);
		}
	}
}
void DrawComet3C(Comet3C comets3C[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets3C[i].live)
		{
			al_draw_bitmap(comets3C->cometimage3, comets3C[i].x - 30, comets3C[i].y - 30, 0);
		}
	}
}