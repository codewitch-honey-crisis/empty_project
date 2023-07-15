#include <ui.hpp>
#ifdef HAS_DISPLAY

#define OPENSANS_REGULAR_IMPLEMENTATION
#include <assets/OpenSans_Regular.hpp>
static const gfx::open_font& text_font = OpenSans_Regular;

using namespace uix;
using namespace gfx;

constexpr static const rgba_pixel<32> transparent(0,0,0,0);

screen_t main_screen(display_buffer_size,display_buffer1,display_buffer2);

push_button_t hello_button(main_screen);

void main_screen_initialize() {
    main_screen.background_color(color_t::purple);
    hello_button.bounds(main_screen.bounds());
    hello_button.background_color(transparent);
    hello_button.pressed_background_color(transparent);
    hello_button.border_color(transparent);
    hello_button.pressed_border_color(transparent);
    hello_button.text_color(color32_t::white);
    hello_button.text_justify(uix_justify::center);
    hello_button.text_open_font(&text_font);
    hello_button.text_line_height(main_screen.dimensions().height/2);
    hello_button.text("hello!");
    hello_button.pressed_text_color(color32_t::black);
    main_screen.register_control(hello_button);
}
#endif
