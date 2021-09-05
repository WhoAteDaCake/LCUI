#define PREVIEW_MODE
#include "./cases/test_widget_opacity.c"

static void OnOpacityPlus(ui_widget_t* w, ui_event_t* e, void *arg)
{
	wchar_t str[32];
	float opacity = self.parent->computed_style.opacity - 0.1f;

	if (opacity < 0.1f) {
		opacity = 0.1f;
	}
	swprintf(str, 32, L"%.1f", opacity);
	ui_widget_set_opacity(self.parent, opacity);
	TextView_SetTextW(self.text, str);
}

static void OnOpacityMinus(ui_widget_t* w, ui_event_t* e, void *arg)
{
	wchar_t str[32];
	float opacity = self.parent->computed_style.opacity + 0.1f;

	if (opacity > 1.0f) {
		opacity = 1.0f;
	}
	swprintf(str, 32, L"%.1f", opacity);
	ui_widget_set_opacity(self.parent, opacity);
	TextView_SetTextW(self.text, str);
}

int main(void)
{
	ui_widget_t* btn_plus, btn_minus;

	LCUI_Init();
	build();
	btn_plus = ui_get_widget("btn-plus");
	btn_minus = ui_get_widget("btn-minus");
	ui_widget_on(btn_plus, "click", OnOpacityPlus, NULL, NULL);
	ui_widget_on(btn_minus, "click", OnOpacityMinus, NULL, NULL);
	return LCUI_Main();
}
