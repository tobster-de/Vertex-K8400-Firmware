

#ifndef VELLEMANMENUS_INC
#define VELLEMANMENUS_INC

#define MSG_LOAD_FILAMENT "Load filament"
#define MSG_UNLOAD_FILAMENT "Unload filament"
#define MSG_LOAD_ABS_EX1 "Load ABS right"
#define MSG_UNLOAD_ABS_EX1 "Unload ABS right"
#define MSG_LOAD_ABS_EX2 "Load ABS left"
#define MSG_UNLOAD_ABS_EX2 "Unload ABS left"
#define MSG_LOAD_PLA_EX1 "Load PLA right"
#define MSG_UNLOAD_PLA_EX1 "Unload PLA right"
#define MSG_LOAD_PLA_EX2 "Load PLA left"
#define MSG_UNLOAD_PLA_EX2 "Unload PLA left"
#define MSG_EXTRUDER_1 "Right (EXT.1)"
#define MSG_EXTRUDER_2 "Left (EXT.2)"
#define MSG_LOAD_TEXT0 "  Insert filament"
#define MSG_LOAD_TEXT1 "until 1.5cm filament"
#define MSG_LOAD_TEXT2 "  visible in tube."
#define MSG_LOAD_TEXT3 " Then press button."
//#define MSG_FIRMWARE "Firmware version"


#if ENABLED(ULTRA_LCD)

#ifdef VELLEMAN_ADDITIONAL_MENUS

    static void load_extruder_start(short extruder)
    {
      enquecommand_P(PSTR("M117 Preparing..."));
      enquecommand_P(PSTR("M106 S165"));
      enquecommand_P(PSTR("G28"));
      enquecommand_P(PSTR("G90"));
      enquecommand_P(PSTR("M82"));
      enquecommand_P(PSTR("G0 F12000 X100 Y100 Z100"));
      if (extruder == 1) {
        enquecommand_P(PSTR("T0"));
        enquecommand_P(PSTR("T1"));
        enquecommand_P(PSTR("T0"));
      }
      if (extruder == 2) {
        enquecommand_P(PSTR("T1"));
        enquecommand_P(PSTR("T0"));
        enquecommand_P(PSTR("T1"));
      }
    }

    static void load_extruder1_abs()
    {
      enquecommand_P(PSTR("M104 T0 S245"));
      enquecommand_P(PSTR("M109 T0 S245"));
    }

    static void load_extruder2_abs()
    {
      enquecommand_P(PSTR("M104 T1 S245"));
      enquecommand_P(PSTR("M109 T1 S245"));
    }

    static void load_extruder1_pla()
    {
      enquecommand_P(PSTR("M104 T0 S210"));
      enquecommand_P(PSTR("M109 T0 S210"));
    }

    static void load_extruder2_pla()
    {
      enquecommand_P(PSTR("M104 T1 S210"));
      enquecommand_P(PSTR("M109 T1 S210"));
    }

    static void load_extruder_end(short extruder)
    {
      enquecommand_P(PSTR("G92 E0"));
      enquecommand_P(PSTR("M83"));
      enquecommand_P(PSTR("G1 E300 F2000"));
      enquecommand_P(PSTR("G1 E200 F1000"));
      enquecommand_P(PSTR("M117 Feeding filament"));
      enquecommand_P(PSTR("G1 E60 F50"));
      enquecommand_P(PSTR("G28"));
      enquecommand_P(PSTR("G90"));
      enquecommand_P(PSTR("M82"));
      if (extruder == 1) {
        enquecommand_P(PSTR("M104 T0 S0"));
      }
      if (extruder == 2) {
        enquecommand_P(PSTR("M104 T1 S0"));
      }
      enquecommand_P(PSTR("T0"));
      enquecommand_P(PSTR("M84"));
      enquecommand_P(PSTR("M117 Vertex is ready     "));
    }

    static void unload_extruder_end(short extruder)
    {
      enquecommand_P(PSTR("G92 E0"));
      enquecommand_P(PSTR("M83"));
      enquecommand_P(PSTR("G1 E10 F50"));
      enquecommand_P(PSTR("M117 Unloading filament"));
      enquecommand_P(PSTR("G1 E-300 F2000"));
      enquecommand_P(PSTR("G1 E-300 F2000"));
      enquecommand_P(PSTR("G28"));
      enquecommand_P(PSTR("G90"));
      enquecommand_P(PSTR("M82"));
      if (extruder == 1) {
        enquecommand_P(PSTR("M104 T0 S0"));
      }
      if (extruder == 2) {
        enquecommand_P(PSTR("M104 T1 S0"));
      }
      enquecommand_P(PSTR("T0"));
      enquecommand_P(PSTR("M84"));
      enquecommand_P(PSTR("M117 Vertex is ready     "));
    }

    static void lcd_load_menu_EXT1_ABS_go()
    {
      lcd_return_to_status();
      load_extruder_start(1);
      load_extruder1_abs();
      load_extruder_end(1);
    }

    static void lcd_load_menu_EXT1_ABS()
    {
      START_MENU();
      MENU_ITEM(function, MSG_LOAD_TEXT0, lcd_load_menu_EXT1_ABS_go);
      MENU_ITEM(function, MSG_LOAD_TEXT1, lcd_load_menu_EXT1_ABS_go);
      MENU_ITEM(function, MSG_LOAD_TEXT2, lcd_load_menu_EXT1_ABS_go);
      MENU_ITEM(function, MSG_LOAD_TEXT3, lcd_load_menu_EXT1_ABS_go);
      END_MENU();
    }

    static void lcd_load_menu_EXT1_PLA_go()
    {
      lcd_return_to_status();
      load_extruder_start(1);
      load_extruder1_pla();
      load_extruder_end(1);
    }

    static void lcd_load_menu_EXT1_PLA()
    {
      START_MENU();
      MENU_ITEM(function, MSG_LOAD_TEXT0, lcd_load_menu_EXT1_PLA_go);
      MENU_ITEM(function, MSG_LOAD_TEXT1, lcd_load_menu_EXT1_PLA_go);
      MENU_ITEM(function, MSG_LOAD_TEXT2, lcd_load_menu_EXT1_PLA_go);
      MENU_ITEM(function, MSG_LOAD_TEXT3, lcd_load_menu_EXT1_PLA_go);
      END_MENU();
    }

    static void lcd_load_menu_EXT2_ABS_go()
    {
      lcd_return_to_status();
      load_extruder_start(2);
      load_extruder2_abs();
      load_extruder_end(2);
    }

    static void lcd_load_menu_EXT2_ABS()
    {
      START_MENU();
      MENU_ITEM(function, MSG_LOAD_TEXT0, lcd_load_menu_EXT2_ABS_go);
      MENU_ITEM(function, MSG_LOAD_TEXT1, lcd_load_menu_EXT2_ABS_go);
      MENU_ITEM(function, MSG_LOAD_TEXT2, lcd_load_menu_EXT2_ABS_go);
      MENU_ITEM(function, MSG_LOAD_TEXT3, lcd_load_menu_EXT2_ABS_go);
      END_MENU();
    }

    static void lcd_load_menu_EXT2_PLA_go()
    {
      lcd_return_to_status();
      load_extruder_start(2);
      load_extruder2_pla();
      load_extruder_end(2);
    }

    static void lcd_load_menu_EXT2_PLA()
    {
      START_MENU();
      MENU_ITEM(function, MSG_LOAD_TEXT0, lcd_load_menu_EXT2_PLA_go);
      MENU_ITEM(function, MSG_LOAD_TEXT1, lcd_load_menu_EXT2_PLA_go);
      MENU_ITEM(function, MSG_LOAD_TEXT2, lcd_load_menu_EXT2_PLA_go);
      MENU_ITEM(function, MSG_LOAD_TEXT3, lcd_load_menu_EXT2_PLA_go);
      END_MENU();
    }

    static void lcd_unload_menu_EXT1_ABS()
    {
      lcd_return_to_status();
      load_extruder_start(1);
      load_extruder1_abs();
      unload_extruder_end(1);
    }

    static void lcd_unload_menu_EXT1_PLA()
    {
      lcd_return_to_status();
      load_extruder_start(1);
      load_extruder1_pla();
      unload_extruder_end(1);
    }

    static void lcd_unload_menu_EXT2_ABS()
    {
      lcd_return_to_status();
      load_extruder_start(2);
      load_extruder2_abs();
      unload_extruder_end(2);
    }

    static void lcd_unload_menu_EXT2_PLA()
    {
      lcd_return_to_status();
      load_extruder_start(2);
      load_extruder2_pla();
      unload_extruder_end(2);
    }

    static void lcd_load_menu_EXT1()
    {
      START_MENU();
      MENU_ITEM(back, MSG_LOAD_FILAMENT, lcd_load_menu);
      MENU_ITEM(submenu, MSG_LOAD_ABS_EX1, lcd_load_menu_EXT1_ABS);
      MENU_ITEM(submenu, MSG_LOAD_PLA_EX1, lcd_load_menu_EXT1_PLA);
      END_MENU();
    }

    static void lcd_load_menu_EXT2()
    {
      START_MENU();
      MENU_ITEM(back, MSG_LOAD_FILAMENT, lcd_load_menu);
      MENU_ITEM(submenu, MSG_LOAD_ABS_EX2, lcd_load_menu_EXT2_ABS);
      MENU_ITEM(submenu, MSG_LOAD_PLA_EX2, lcd_load_menu_EXT2_PLA);
      END_MENU();
    }

    static void lcd_unload_menu_EXT1()
    {
      START_MENU();
      MENU_ITEM(back, MSG_UNLOAD_FILAMENT, lcd_unload_menu);
      MENU_ITEM(function, MSG_UNLOAD_ABS_EX1, lcd_unload_menu_EXT1_ABS);
      MENU_ITEM(function, MSG_UNLOAD_PLA_EX1, lcd_unload_menu_EXT1_PLA);
      END_MENU();
    }

    static void lcd_unload_menu_EXT2()
    {
      START_MENU();
      MENU_ITEM(back, MSG_UNLOAD_FILAMENT, lcd_unload_menu);
      MENU_ITEM(function, MSG_UNLOAD_ABS_EX2, lcd_unload_menu_EXT2_ABS);
      MENU_ITEM(function, MSG_UNLOAD_PLA_EX2, lcd_unload_menu_EXT2_PLA);
      END_MENU();
    }

    static void lcd_load_menu()
    {
      START_MENU();
      MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
      MENU_ITEM(submenu, MSG_EXTRUDER_1, lcd_load_menu_EXT1);
  #if EXTRUDERS >= 2
      MENU_ITEM(submenu, MSG_EXTRUDER_2, lcd_load_menu_EXT2);
  #endif
      END_MENU();
    }

    static void lcd_unload_menu()
    {
      START_MENU();
      MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
      MENU_ITEM(submenu, MSG_EXTRUDER_1, lcd_unload_menu_EXT1);
  #if EXTRUDERS >= 2
      MENU_ITEM(submenu, MSG_EXTRUDER_2, lcd_unload_menu_EXT2);
  #endif
      END_MENU();
    }
#endif

#endif

#endif // VELLEMANMENUS_INC
