.text 
    .balign 2;this is to put the locatio as an even number
    .global WDT
    ;flags a ->  allocatable
    ; x -> executable
    .section _interrupt_vector_11,"ax"
    .word WDT
    .text

    .extern redrawScreen
    .extern wdt_c_handler
    
    WDT:
      ;this is where you initialize your registers
      PUSH R15
      PUSH R14
      PUSH R13
      PUSH R12
      PUSH R11
      PUSH R10
      PUSH R9
      PUSH R8
      PUSH R7
      PUSH R6
      PUSH R5
      PUSH R4
      ; Calling directly the wdt_c_handler
      CALL #wdt_c_handler

      ;starting the end
      POP R4
      POP R5
      POP R6
      POP R7
      POP R8
      POP R9
      POP R10
      POP R11
      POP R12
      POP R13
      POP R14
      POP R15
      cmp #0,&redrawScreen
      jz dont_wake
      and #0xffef,0(r1)

      dont_wake:
        RETI
