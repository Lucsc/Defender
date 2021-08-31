/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
} scoreboard;

typedef struct circle_s {
    sfCircleShape *shape;
    sfVector2f position;
    float radius;
    sfTexture *texture;
} circle_t;

typedef struct scene_s {
    struct object *sprite;
    struct music *music;
    struct t *time;
    struct button_s *click;
} scene_s;

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfEvent event;
    circle_t *circles;
    int i;
    int a;
    int b;
} object;

typedef struct music {
    sfMusic *music;
} music;

typedef struct t {
    sfClock* clock;
    sfTime time;
    float seconds;
} t;

typedef struct button_s {
    sfRectangleShape *shape;
    sfVector2f position;
    sfVector2f size;
    sfTexture *texture;
    int reset;
} button_s;

typedef struct structenemy {
    object *first;
    object *second;
    t *clock;
} structenemy;

void move_rect(sfIntRect *rect, int offset, int max_value);
int my_putstr(char const *str);
void my_putchar(char c);
struct t *create_clock(void);
struct music *create_music(const char *filepath);
struct object *create_sprite(const char *pathfile,
                                sfVector2f vector, sfIntRect rect);
int start_screen(sfRenderWindow *window);
void analyse_events(sfRenderWindow *window, sfEvent event,
                    button_s *button, button_s *quick_exit);
struct button_s *init_buttons(const char *pathfile, sfVector2f pos,
                                sfVector2f size);
void print_hello(void);
int button_is_clicked(button_s *button, sfVector2f click, sfRenderWindow *w);
int gamescreen(sfRenderWindow *window);
int button_leave(button_s *button, sfVector2f click, sfRenderWindow *w);
void helpwindow(void);
int button_help(button_s *button , sfVector2f click, sfRenderWindow *w);
void analyse_eventsgame(sfRenderWindow *window, object **game,
                        button_s **tow, button_s **zone);
void gohelp(sfRenderWindow *window, sfEvent event, button_s *button);
void moving_sprite(t *clock, object *bck_one, object *bck_two);
object *changeposfirst(object *enemy, int x);
object *changepossecond(object *enemy, int x);
structenemy *createenemy(structenemy *enemys);
object **tabobject(object **game);
t *moveenemys(object **game, t *clock,
                sfRenderWindow *window, button_s **zone);
void drawgamemap(object **game, sfRenderWindow *window,
                    t **clock, button_s **zone);
object **objectstart(object **bgmain);
button_s **buttonstart(button_s **info);
void drawstartscreen(button_s **info, object **bgmain, sfRenderWindow *window);
int pausescreen(sfRenderWindow *window, object **game,
                button_s **life, button_s **zone);
struct button_s *init_butt(sfVector2f pos, sfVector2f size);
int button_resume(button_s *button, sfVector2f click, sfRenderWindow *w);
int button_home(button_s *button, sfVector2f click, sfRenderWindow *w);
void drawscreen(button_s **tower, sfRenderWindow *window);
button_s **gamebutton(button_s **tower);
int towerdownright(button_s *button, sfVector2f click,
                    sfRenderWindow *w, int i);
int towerdownleft(button_s *button, sfVector2f click, sfRenderWindow *w, int i);
int towertopright(button_s *button, sfVector2f click, sfRenderWindow *w, int i);
int towertopleft(button_s *button, sfVector2f click, sfRenderWindow *w, int i);
void changecursor(sfRenderWindow *w, object **game);
void drawzones(button_s **zone, sfRenderWindow *window);
void see_zones(button_s *zone, sfVector2f mouse);
void check_zones(button_s **zone, sfRenderWindow *window);
button_s **all_zone(button_s **zone);
void checkzonesontower(button_s **zone, sfRenderWindow *window, object **game);
void printtower(sfRenderWindow *window, object **game, button_s *zone);
void printtowerbis(sfRenderWindow *window, object **game, button_s *zon, int i);
void eventsgame(sfRenderWindow *window, object **game,
                        button_s **tow, button_s **zone);
button_s **create_butt(button_s **butt);
void lostscreen(sfRenderWindow *window, music *damage);
void analyse_endevents(sfRenderWindow *window, button_s **butt, sfEvent event);
void restart_button(sfRenderWindow *window, button_s **butt, sfVector2f mouse);
void home_button(sfRenderWindow *window, button_s **button, sfVector2f mouse);
void healthbar(sfRenderWindow *window, object **game, button_s **bar);
t **createtabclock(t **clock);
struct music *create_sound(const char *filepath);
void ennemylife(sfRenderWindow *window, t **clock,
                    object **game, button_s **life);
void check_death(t *clock, object **t_enemy,
                    int i, button_s **health);
void skl_bar(sfRenderWindow* window, object **game, button_s **life, t *clock);
struct music *create_sound(const char *filepath);
circle_t *cre_circ(sfVector2f pos, float radius);
object *all_circles(object *zone, int i);
button_s **mob_health(button_s **health, object **game);
void ennemylife(sfRenderWindow *window, t **clock,
                    object **game, button_s **life);
void chose_towerbis(t *clock, object **t_enemy,
                    int i, button_s *health);
void chose_tower(object **t_enemy,  t *clock,
                    int i, button_s *health);
void go_pause(sfRenderWindow *window, object **game,
                button_s **life, button_s **zone);
void drawbar(sfRenderWindow *window, object **game, button_s **life);
void changelife(sfRenderWindow *window, object **game,
                    button_s **life, t *clock);
void converttochar(sfRenderWindow *window, int i, char *score, int r);
void converttogold(sfRenderWindow *window, int i, char *score, int r);
void create_score(sfRenderWindow *window, int i, int j);

#endif /* !DEFENDER_H_ */