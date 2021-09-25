#include "../private.h"

#ifdef APP_PLATFORM_LINUX

static struct app_t {
	app_window_driver_t window;
	app_driver_t app;
	app_id_t id;
} linux_app;

void app_window_close(app_window_t *wnd)
{
	return linux_app.window.close(wnd);
}

void app_window_set_title(app_window_t *wnd, const wchar_t *title)
{
	return linux_app.window.set_title(wnd, title);
}

void app_window_set_size(app_window_t *wnd, int width, int height)
{
	return linux_app.window.set_size(wnd, width, height);
}

void app_window_set_position(app_window_t *wnd, int x, int y)
{
	return linux_app.window.set_position(wnd, x, y);
}

void *app_window_get_handle(app_window_t *wnd)
{
	return linux_app.window.get_handle(wnd);
}

int app_window_get_width(app_window_t *wnd)
{
	return linux_app.window.get_width(wnd);
}

int app_window_get_height(app_window_t *wnd)
{
	return linux_app.window.get_height(wnd);
}

void app_window_set_min_width(app_window_t *wnd, int min_width)
{
	linux_app.window.set_max_width(wnd, min_width);
}

void app_window_set_min_height(app_window_t *wnd, int min_height)
{
	linux_app.window.set_max_width(wnd, min_height);
}

void app_window_set_max_width(app_window_t *wnd, int max_width)
{
	linux_app.window.set_max_width(wnd, max_width);
}

void app_window_set_max_height(app_window_t *wnd, int max_height)
{
	linux_app.window.set_max_height(wnd, max_height);
}

void app_window_show(app_window_t *wnd)
{
	linux_app.window.show(wnd);
}

void app_window_hide(app_window_t *wnd)
{
	linux_app.window.hide(wnd);
}

app_window_paint_t *app_window_begin_paint(app_window_t *wnd, LCUI_Rect *rect)
{
	return linux_app.window.begin_paint(wnd, rect);
}

void app_window_end_paint(app_window_t *wnd, app_window_paint_t *paint)
{
	linux_app.window.end_paint(wnd, paint);
}

void app_window_present(app_window_t *wnd)
{
	linux_app.window.present(wnd);
}

app_window_t *app_create_create(const wchar_t *title, int x, int y,
					   int width, int height,
					   app_window_t *parent)
{
	return linux_app.app.create_window(title, x, y, width, height, parent);
}

void app_present(void)
{
	linux_app.app.present();
}

app_id_t app_get_id(void)
{
	return linux_app.id;
}

int app_init(const wchar_t *name)
{
	linux_app.id = APP_ID_LINUX;
#ifdef USE_LIBX11
	x11_app_driver_init(&linux_app.app);
	x11_app_window_driver_init(&linux_app.window);
	if (linux_app.app.init(name) == 0) {
		linux_app.id = APP_ID_LINUX_X11;
		return 0;
	}
#endif
	fb_app_driver_init(&linux_app.app);
	fb_app_window_driver_init(&linux_app.window);
	return linux_app.app.init(name);
}

void app_destroy(void)
{
	linux_app.app.destroy();
}

#endif
