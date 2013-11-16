;***************************************************************
;* For Martinez 4fach ESC  V3             	                   *
;* bearbeitet von imcoref                                      *
;* https://github.com/sim-/tgy                                 *
;***************************************************************



.equ	F_CPU			= 16000000
.equ	USE_INT0		= 1
.equ	USE_I2C			= 0	
.equ	USE_UART		= 0
.equ	USE_ICP			= 0


.equ   	COMP_PWM=		1		; 1 schaltet den aktiven Freilauf EIN, eine 0 aus
.equ	DEAD_LOW_NS=	600		; diese Werte können verändert werden
.equ	DEAD_HIGH_NS=	600		; jedoch ist dies nach heutigem Stand nicht nötig!!!

.equ	MOTOR_ADVANCE=	18		; 18 ist Standardwert
.equ	TIMING_OFFSET=	0		; 0 ist Standardwert


;*********************

; PORT D definitions *

;*********************

;.equ					= 7
;.equ	sense_star 		= 6 ;	ist standardmässig PD6, deswegen auskommentiert
;.equ					= 5
.equ	statusLed		= 4 ;	gruene LED
.equ	warnLed			= 3 ;	rote LED
.equ	rcp_in			= 2 ;	PPM Eingang von FlightControl
;.equ					= 1
;.equ					= 0
.equ	INIT_PD			= 0
.equ	DIR_PD			= (1<<statusLed)+(1<<warnLed) 



.MACRO RED_on
sbi PORTD, warnLed
.ENDMACRO

.MACRO RED_off
cbi PORTD, warnLed
.ENDMACRO

.MACRO GRN_on
sbi PORTD, statusLed
.ENDMACRO

.MACRO GRN_off
cbi PORTD, statusLed
.ENDMACRO



;*********************

; PORT C definitions *

;*********************
;.equ					= 7	
;.equ					= 6	
;.equ					= 5
;.equ					= 4
.equ	mux_a			= 3 ; ADC für MUX a
.equ	mux_b			= 2 ; ADC für MUX b	 
.equ	mux_c			= 1 ; ADC für MUX c	 
;.equ					= 0	

.equ	INIT_PC			= 0
.equ	DIR_PC			= 0 ; auf PortC ist alles auf IN







;*********************

; PORT B definitions *

;*********************

;.equ					= 7
;.equ					= 6
.equ	CnFET			= 5	; SCK
.equ	CpFET			= 4	; MISO
.equ	BnFET			= 3	; MOSI
.equ	BpFET			= 2	; 
.equ	AnFET			= 1	;
.equ	ApFET			= 0
.equ	INIT_PB			= 0
.equ	DIR_PB			= (1<<CnFET)+(1<<CpFET)+(1<<BnFET)+(1<<BpFET)+(1<<AnFET)+(1<<ApFET)




.equ	AnFET_port	= PORTB
.equ	ApFET_port	= PORTB
.equ	BpFET_port	= PORTB
.equ	BnFET_port	= PORTB
.equ	CpFET_port	= PORTB
.equ	CnFET_port	= PORTB
