*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
    MOVE.B #0, D1       ;D1 will be my X
    MOVE.B #1, D2       ;D2 will be my Y
    BRA WHILE
    
ifmul
    MULS D1,D2 
    ADD.B #1, D1 
    BRA WHILE 

ifadd
    ADD.B #1,D2 

WHILE    
    CMP #10, D1
    BGT END
    
IF
    MOVE.B D1, D3
    DIVU #2, D3
    SWAP D3
    CLR.W D3
    CMP #0, D3
    BEQ ifmul
    BNE ifadd
    
END
    MOVE.B #14, D0
    LEA mes1, A1
    TRAP #15
    SIMHALT             ; halt simulator

* Put variables and constants here
mes1 DC.B 'Y is: ',0
    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
