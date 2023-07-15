#include <display.hpp>
#include <gfx.hpp>
#ifdef HAS_DISPLAY

using color_t = gfx::color<typename screen_t::pixel_type>;
using color32_t = gfx::color<gfx::rgba_pixel<32>>;

using push_button_t = uix::push_button<typename screen_t::control_surface_type>;

extern screen_t main_screen;
extern push_button_t hello_button;


extern void main_screen_initialize();
#endif
