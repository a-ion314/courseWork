*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
    MOVE.B #14,D0
    LEA mes1,A1
    TRAP #15
    
    MOVE.B #4,D0
    TRAP #15
    
    CMP #12,D1
    BGT Greater
    
    BLE Less

Less
    MULS #2,D1
    ADD #4,D1
    BRA STOP
Greater
    SUB #13,D1
    BRA STOP
STOP
    MOVE.B #3,D0
    TRAP #15
    SIMHALT
    
* Put variables and constants here
mes1 DC.B 'Please input  X: ',0
    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
