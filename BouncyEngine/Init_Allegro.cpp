#include "Init_Allegro.h"

 bool Init_Allegro::isInitialized;
 ALLEGRO_DISPLAY* Init_Allegro::DISPLAY;
 ALLEGRO_EVENT_QUEUE*  Init_Allegro::EVENTQUEUE;
 ALLEGRO_TIMER* Init_Allegro::TIMER;
 ALLEGRO_TIMER* Init_Allegro::FRAMETIMER;
 ALLEGRO_KEYBOARD_STATE Init_Allegro::KEYSTATE;
 ALLEGRO_FONT* Init_Allegro::FONT;
 int Init_Allegro::width;
 int Init_Allegro::height;

Init_Allegro::Init_Allegro()
{
	
}


Init_Allegro::~Init_Allegro()
{
}

void Init_Allegro::initialize(int xWidth, int yHeight) 
{
	width = xWidth;
	height= yHeight;
	if (!al_init())
		return;

	DISPLAY = al_create_display(width, height);
	if (!DISPLAY)
	{
		fprintf(stderr, "failed to create display!\n");
		return;
	}

	al_install_keyboard();
	al_install_mouse();
	if (!al_init_image_addon()) {
		al_show_native_message_box(DISPLAY, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon
	al_init_primitives_addon();

	ALLEGRO_COLOR testColor = al_map_rgb(50, 50, 50);
	al_init_image_addon();
	al_hide_mouse_cursor(DISPLAY);
	FONT = al_load_ttf_font(MANAFONT, 18, NULL);

	EVENTQUEUE = al_create_event_queue();

	TIMER = al_create_timer(1.0 / FPS);
	FRAMETIMER = al_create_timer(1.0 / frameFPS);

	al_register_event_source(EVENTQUEUE, al_get_timer_event_source(TIMER));
	al_register_event_source(EVENTQUEUE, al_get_timer_event_source(FRAMETIMER));
	al_register_event_source(EVENTQUEUE, al_get_keyboard_event_source());
	al_register_event_source(EVENTQUEUE, al_get_display_event_source(DISPLAY));
	al_register_event_source(EVENTQUEUE, al_get_mouse_event_source());
}
void Init_Allegro::startTimers(void)
{
	al_start_timer(TIMER);
	al_start_timer(FRAMETIMER);
}