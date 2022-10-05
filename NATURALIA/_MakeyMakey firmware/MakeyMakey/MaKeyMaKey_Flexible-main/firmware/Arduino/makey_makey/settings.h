#include "Arduino.h"

/**************************
*  KEY CODES AND OPTIONS  *
***************************
  - edit the keyCodes array below to change the keys sent by the MaKey MaKey for each input.
  - the comments tell you which input sends that key (for example, by default 'w' is sent by pin D5).
  - change the keys by replacing them. for example, you can replace 'w' with any other individual letter,
    number, or symbol on your keyboard.
  - you can also use codes for other keys such as modifier and function keys (see a list of additional key
    codes at the bottom of this file).
  - you may wish to use the 'INSERT' mode of your keyboard to retype this area without changing whitespace.
  - up to three simultaneous keys can be sent per input (IE Ctrl+Shift+S) by configuring all 3 outputs for
    one input to non-zero keys.
  - use 1 for reverse (send keys when ground is broken instead of when established).
  - use 1 for capacitive (to trigger when something capacitive, IE skin, is touching the input w/o ground).
  - try not to use more than a couple capacitive touch inputs, as they get noticably slow when using many.
*/
int keyCodesAndOptions[NUM_INPUTS][OPTIONS_PER_INPUT] =
{
  // Output 1,         Output 2,         Output 3,         Reverse?   Capacitive?   Position on MM
  {  KEY_UP_ARROW,     0,                0,                0,         0,     },  // up arrow pad
  {  KEY_DOWN_ARROW,   0,                0,                0,         0,     },  // down arrow pad
  {  KEY_LEFT_ARROW,   0,                0,                0,         0,     },  // left arrow pad
  {  KEY_RIGHT_ARROW,  0,                0,                0,         0,     },  // right arrow pad
  {  ' ',              0,                0,                0,         0,     },  // space button pad
  {  KEY_LEFT_CTRL,    0,                0,                0,         0,     },  // click button pad
  {  'w',              0,                0,                0,         0,     },  // pin D5
  {  'a',              0,                0,                0,         0,     },  // pin D4
  {  's',              0,                0,                0,         0,     },  // pin D3
  {  'd',              0,                0,                0,         0,     },  // pin D2
  {  'f',              0,                0,                0,         0,     },  // pin D1
  {  'g',              0,                0,                0,         0,     },  // pin D0
  {  MOUSE_MOVE_UP,    0,                0,                0,         0,     },  // pin A5
  {  MOUSE_MOVE_DOWN,  0,                0,                0,         0,     },  // pin A4
  {  MOUSE_MOVE_LEFT,  0,                0,                0,         0,     },  // pin A3
  {  MOUSE_MOVE_RIGHT, 0,                0,                0,         0,     },  // pin A2
  {  MOUSE_LEFT,       0,                0,                0,         0,     },  // pin A1
  {  MOUSE_RIGHT,      0,                0,                0,         0,     },  // pin A0
};

///////////////////////////
// NOISE CANCELLATION /////
///////////////////////////
#define SWITCH_THRESHOLD_OFFSET_PERC  5    // number between 1 and 49
                                           // larger value protects better against noise oscillations, but makes it harder to press and release
                                           // recommended values are between 2 and 20
                                           // default value is 5

#define SWITCH_THRESHOLD_CENTER_BIAS 55  // number between 1 and 99
                                          // larger value makes it easier to "release" keys, but harder to "press"
                                          // smaller value makes it easier to "press" keys, but harder to "release"
                                          // recommended values are between 30 and 70
                                          // 50 is "middle" 2.5 volt center
                                          // default value is 55
                                          // 100 = 5V (never use this high)
                                          // 0 = 0 V (never use this low
                                          

/////////////////////////
// MOUSE MOTION /////////
/////////////////////////
#define MOUSE_MOTION_UPDATE_INTERVAL  35   // how many loops to wait between 
                                           // sending mouse motion updates
                                           
#define PIXELS_PER_MOUSE_STEP         4     // a larger number will make the mouse
                                           // move faster

#define MOUSE_RAMP_SCALE              150  // Scaling factor for mouse movement ramping
                                           // Lower = more sensitive mouse movement
                                           // Higher = slower ramping of speed
                                           // 0 = Ramping off
                                            
#define MOUSE_MAX_PIXELS              10   // Max pixels per step for mouse movement

/*
///////////////////////////
// ADDITIONAL KEY CODES ///
///////////////////////////

- you can use these codes in the keyCodes array above
- to get modifier keys, function keys, etc 

KEY_LEFT_CTRL,  KEY_RIGHT_CTRL
KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT
KEY_LEFT_ALT,   KEY_RIGHT_ALT
KEY_LEFT_GUI,   KEY_RIGHT_GUI
KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12	

KEY_PAGE_UP,
KEY_PAGE_DOWN
KEY_HOME,
KEY_END

KEY_BACKSPACE
KEY_TAB
KEY_RETURN
KEY_ESC
KEY_INSERE
KEY_DELETE
KEY_CAPS_LOCK

*/
