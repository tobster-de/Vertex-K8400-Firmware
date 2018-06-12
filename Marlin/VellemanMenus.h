/**
* VellemanMenus.h
*
*
*/
#ifndef VELLEMAN_MENUS_H
#define VELLEMAN_MENUS_H

#include "MarlinConfig.h"

#if ENABLED(ULTRA_LCD)

#define enquecommand_P  enqueue_and_echo_command

extern void lcd_splashscreen();
extern void lcd_firmware_menu();

extern void lcd_load_menu();
extern void lcd_unload_menu();

#endif // ULTRA_LCD

#endif // VELLEMAN_MENUS_H