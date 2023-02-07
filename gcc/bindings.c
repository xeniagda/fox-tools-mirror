#pragma once

#include "call.h"

// fox32rom definitions

// system jump table

static inline void get_rom_version(void) {
    call(0xF0040000);
}

static inline void system_vsync_handler(void) {
    call(0xF0040004);
}

static inline void get_mouse_position(void) {
    call(0xF0040008);
}

static inline void new_event(void) {
    call(0xF004000C);
}

static inline void wait_for_event(void) {
    call(0xF0040010);
}

static inline void get_next_event(void) {
    call(0xF0040014);
}

static inline void panic(void) {
    call(0xF0040018);
}

static inline void get_mouse_button(void) {
    call(0xF004001C);
}

static inline void scancode_to_ascii(void) {
    call(0xF0040020);
}

static inline void shift_pressed(void) {
    call(0xF0040024);
}

static inline void shift_released(void) {
    call(0xF0040028);
}

static inline void caps_pressed(void) {
    call(0xF004002C);
}

static inline void poweroff(void) {
    call(0xF0040030);
}

// generic drawing jump table

static inline void draw_str_generic(void) {
    call(0xF0041000);
}

static inline void draw_format_str_generic(void) {
    call(0xF0041004);
}

static inline void draw_decimal_generic(void) {
    call(0xF0041008);
}

static inline void draw_hex_generic(void) {
    call(0xF004100C);
}

static inline void draw_font_tile_generic(void) {
    call(0xF0041010);
}

static inline void draw_tile_generic(void) {
    call(0xF0041014);
}

static inline void set_tilemap(void) {
    call(0xF0041018);
}

static inline void draw_pixel_generic(void) {
    call(0xF004101C);
}

static inline void draw_filled_rectangle_generic(void) {
    call(0xF0041020);
}

static inline void get_tilemap(void) {
    call(0xF0041024);
}

// background jump table

static inline void fill_background(
    unsigned int color
) {
    parameter(0, color);
    call(0xF0042000);
}

static inline unsigned int draw_str_to_background(
    unsigned char* str,
    unsigned int x,
    unsigned int y,
    unsigned int foreground_color,
    unsigned int background_color
) {
    unsigned int result_1;
    parameter(0, str);
    parameter(1, x);
    parameter(2, y);
    parameter(3, foreground_color);
    parameter(4, background_color);
    call(0xF0042004);
    ret(1, result_1);
    return result_1;
}

static inline unsigned int draw_format_str_to_background(
    unsigned char* str,
    unsigned int x,
    unsigned int y,
    unsigned int foreground_color,
    unsigned int background_color,
    unsigned int format_value_0,
    unsigned int format_value_1,
    unsigned int format_value_2,
    unsigned int format_value_3,
    unsigned int format_value_4,
    unsigned int format_value_5
) {
    unsigned int result_1;
    parameter(0, str);
    parameter(1, x);
    parameter(2, y);
    parameter(3, foreground_color);
    parameter(4, background_color);
    parameter(10, format_value_0);
    parameter(11, format_value_1);
    parameter(12, format_value_2);
    parameter(13, format_value_3);
    parameter(14, format_value_4);
    parameter(15, format_value_5);
    call(0xF0042008);
    ret(1, result_1);
    return result_1;
}

static inline unsigned int draw_decimal_to_background(
    unsigned int value,
    unsigned int x,
    unsigned int y,
    unsigned int foreground_color,
    unsigned int background_color
) {
    unsigned int result_1;
    parameter(0, value);
    parameter(1, x);
    parameter(2, y);
    parameter(3, foreground_color);
    parameter(4, background_color);
    call(0xF004200C);
    ret(1, result_1);
    return result_1;
}

static inline unsigned int draw_hex_to_background(
    unsigned int value,
    unsigned int x,
    unsigned int y,
    unsigned int foreground_color,
    unsigned int background_color
) {
    unsigned int result_1;
    parameter(0, value);
    parameter(1, x);
    parameter(2, y);
    parameter(3, foreground_color);
    parameter(4, background_color);
    call(0xF0042010);
    ret(1, result_1);
    return result_1;
}

static inline void draw_font_tile_to_background(
    unsigned int tile,
    unsigned int x,
    unsigned int y,
    unsigned int foreground_color,
    unsigned int background_color
) {
    parameter(0, tile);
    parameter(1, x);
    parameter(2, y);
    parameter(3, foreground_color);
    parameter(4, background_color);
    call(0xF0042014);
}

static inline void draw_tile_to_background(
    unsigned int tile,
    unsigned int x,
    unsigned int y
) {
    parameter(0, tile);
    parameter(1, x);
    parameter(2, y);
    call(0xF0042018);
}

static inline void draw_pixel_to_background(
    unsigned int x,
    unsigned int y,
    unsigned int color
) {
    parameter(0, x);
    parameter(1, y);
    parameter(2, color);
    call(0xF004201C);
}

static inline void draw_filled_rectangle_to_background(
    unsigned int x,
    unsigned int y,
    unsigned int width,
    unsigned int height,
    unsigned int color
) {
    parameter(0, x);
    parameter(1, y);
    parameter(2, width);
    parameter(3, height);
    parameter(4, color);
    call(0xF0042020);
}

// overlay jump table

static inline void fill_overlay(void) {
    call(0xF0043000);
}

static inline void draw_str_to_overlay(void) {
    call(0xF0043004);
}

static inline void draw_format_str_to_overlay(void) {
    call(0xF0043008);
}

static inline void draw_decimal_to_overlay(void) {
    call(0xF004300C);
}

static inline void draw_hex_to_overlay(void) {
    call(0xF0043010);
}

static inline void draw_font_tile_to_overlay(void) {
    call(0xF0043014);
}

static inline void draw_tile_to_overlay(void) {
    call(0xF0043018);
}

static inline void draw_pixel_to_overlay(void) {
    call(0xF004301C);
}

static inline void draw_filled_rectangle_to_overlay(void) {
    call(0xF0043020);
}

static inline void check_if_overlay_covers_position(void) {
    call(0xF0043024);
}

static inline void check_if_enabled_overlay_covers_position(void) {
    call(0xF0043028);
}

static inline void enable_overlay(void) {
    call(0xF004302C);
}

static inline void disable_overlay(void) {
    call(0xF0043030);
}

static inline void move_overlay(void) {
    call(0xF0043034);
}

static inline void resize_overlay(void) {
    call(0xF0043038);
}

static inline void set_overlay_framebuffer_pointer(void) {
    call(0xF004303C);
}

static inline void get_unused_overlay(void) {
    call(0xF0043040);
}

static inline void make_coordinates_relative_to_overlay(void) {
    call(0xF0043044);
}

// menu bar jump table

static inline void enable_menu_bar(void) {
    call(0xF0044000);
}

static inline void disable_menu_bar(void) {
    call(0xF0044004);
}

static inline void menu_bar_click_event(void) {
    call(0xF0044008);
}

static inline void clear_menu_bar(void) {
    call(0xF004400C);
}

static inline void draw_menu_bar_root_items(void) {
    call(0xF0044010);
}

static inline void draw_menu_items(void) {
    call(0xF0044014);
}

static inline void close_menu(void) {
    call(0xF0044018);
}

static inline void menu_update_event(void) {
    call(0xF004401C);
}

// disk jump table

static inline void read_sector(void) {
    call(0xF0045000);
}

static inline void write_sector(void) {
    call(0xF0045004);
}

static inline void ryfs_open(void) {
    call(0xF0045008);
}

static inline void ryfs_seek(void) {
    call(0xF004500C);
}

static inline void ryfs_read(void) {
    call(0xF0045010);
}

static inline void ryfs_read_whole_file(void) {
    call(0xF0045014);
}

static inline void ryfs_get_size(void) {
    call(0xF0045018);
}

static inline void ryfs_get_file_list(void) {
    call(0xF004501C);
}

static inline void ryfs_tell(void) {
    call(0xF0045020);
}

static inline void ryfs_write(void) {
    call(0xF0045024);
}

// memory copy/compare jump table

static inline void copy_memory_bytes(void) {
    call(0xF0046000);
}

static inline void copy_memory_words(void) {
    call(0xF0046004);
}

static inline void copy_string(void) {
    call(0xF0046008);
}

static inline void compare_memory_bytes(void) {
    call(0xF004600C);
}

static inline void compare_memory_words(void) {
    call(0xF0046010);
}

static inline void compare_string(void) {
    call(0xF0046014);
}

static inline void string_length(void) {
    call(0xF0046018);
}

// integer jump table

static inline void string_to_int(void) {
    call(0xF0047000);
}

// audio jump table

static inline void play_audio(void) {
    call(0xF0048000);
}

static inline void stop_audio(void) {
    call(0xF0048004);
}

// random number jump table

static inline unsigned int random(void) {
    unsigned int result_0;
    call(0xF0049000);
    ret(0, result_0);
    return result_0;
}

static inline unsigned int random_range(
    unsigned int minimum,
    unsigned int maximum
) {
    unsigned int result_0;
    parameter(1, minimum);
    parameter(2, maximum);
    call(0xF0049004);
    ret(0, result_0);
    return result_0;
}

// keys

#define KEY_CTRL 0x0000001D

#define KEY_LSHIFT 0x0000002A

#define KEY_RSHIFT 0x00000036

#define KEY_CAPS 0x0000003A

// fox32os definitions

// system jump table

static inline void get_os_version(void) {
    call(0x00000810);
}

// FXF jump table

static inline void parse_fxf_binary(void) {
    call(0x00000910);
}

// task jump table

static inline void new_task(void) {
    call(0x00000A10);
}

static inline void yield_task(void) {
    call(0x00000A14);
}

static inline void end_current_task(void) {
    call(0x00000A18);
}

static inline void get_current_task_id(void) {
    call(0x00000A1C);
}

static inline void get_unused_task_id(void) {
    call(0x00000A20);
}

static inline void is_task_id_used(void) {
    call(0x00000A24);
}

// memory jump table

static inline void allocate_memory(void) {
    call(0x00000B10);
}

static inline void free_memory(void) {
    call(0x00000B14);
}

// window jump table

static inline void new_window(void) {
    call(0x00000C10);
}

static inline void destroy_window(void) {
    call(0x00000C14);
}

static inline void new_window_event(void) {
    call(0x00000C18);
}

static inline void get_next_window_event(void) {
    call(0x00000C1C);
}

static inline void draw_title_bar_to_window(void) {
    call(0x00000C20);
}

static inline void move_window(void) {
    call(0x00000C24);
}

static inline void fill_window(void) {
    call(0x00000C28);
}

static inline void get_window_overlay_number(void) {
    call(0x00000C2C);
}

static inline void start_dragging_window(void) {
    call(0x00000C30);
}

static inline void new_messagebox(void) {
    call(0x00000C34);
}

static inline void get_active_window_struct(void) {
    call(0x00000C38);
}

// VFS jump table

static inline void open(void) {
    call(0x00000D10);
}

static inline void seek(void) {
    call(0x00000D14);
}

static inline void tell(void) {
    call(0x00000D18);
}

static inline void read(void) {
    call(0x00000D1C);
}

static inline void write(void) {
    call(0x00000D20);
}

// widget jump table

static inline void draw_widgets_to_window(void) {
    call(0x00000E10);
}

static inline void handle_widget_click(void) {
    call(0x00000E14);
}

// event types

#define EVENT_TYPE_MOUSE_CLICK 0x00000000

#define EVENT_TYPE_MOUSE_RELEASE 0x00000001

#define EVENT_TYPE_KEY_DOWN 0x00000002

#define EVENT_TYPE_KEY_UP 0x00000003

#define EVENT_TYPE_MENU_BAR_CLICK 0x00000004

#define EVENT_TYPE_MENU_UPDATE 0x00000005

#define EVENT_TYPE_MENU_CLICK 0x00000006

#define EVENT_TYPE_MENU_ACK 0x00000007

#define EVENT_TYPE_BUTTON_CLICK 0x80000000

#define EVENT_TYPE_EMPTY 0xFFFFFFFF

// widget types

#define WIDGET_TYPE_BUTTON 0x00000000

