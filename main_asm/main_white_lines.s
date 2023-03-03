; main_white_lines.s
;
; Created: 2023-03-03 
; Author: Group 02
;
; Follow a white line on black background. 
; A bit faster then main_black_lines.s
;
; +---------------------------- DOCS -----------------------------------------------------------------------------------------------------------+
; | ATMEGA328p datasheet:    https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf   |                                        |
; | AVR ASM instruction set: http://www.avr-asm-tutorial.net/avr_en/beginner/COMMANDS.html                                                      |
; +---------------------------- TIME -----------------------------------------------------------------------------------------------------------+
; | init:      3 cycles                                                                                                                         |
; | main_loop: 7 cycles (16 MHz / 7 ≈ 2 285 714 updates / sec)                                                                                  |
; +---------------------------------------------------------------------------------------------------------------------------------------------+
;
init:
  ldi r24,  0b00110000  ; Clk (1)   (Possible to re-write as one instruction?)
  sts 0x2A, r24         ; Clk (2)   Set input / outputs of port D data direction register
main_loop:
  lds r15, 0x29         ; Clk (2)   Set r15 from port D 
  lsr r15               ; Clk (1)   Logic right shift 2x
  lsr r15               ; Clk (1)
  sts 0x2B, r15         ; Clk (2)   Set port D data register as the new value r15
  jmp main_loop         ; Clk (1?)      