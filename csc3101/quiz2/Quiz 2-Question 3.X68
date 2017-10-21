*-----------------------------------------------------------
* Title      :CSC 3101 Quiz 2 Question 3
* Written by :Adrian Ionascu
* Date       :12/4/16
* Description:This prints an array in ascending order by using a bubble sort
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program
    MOVE.B #0,D7       ;this will count how many correct positions we have
    MOVE.B #1,D6       ;index
    LEA ARRAY,A7
                       ;A7 = array                   
                       ;We will be using D3 and D4 to hold 2 number in the array to compare
SORT
    CMP #3,D7
    BEQ PRINT
    
    CMP #4,D6           ;compare with 4 as that is the index of array
    BEQ INC
    
    MOVE.L (A7),D3
    ADDA.L #4,A7
    MOVE.L (A7),D4
    CMP D4,D3      ;compare to see which number is greater 
    BGT SWAP
    ADD.B #1,D6
    ADD.B #1,D7
    JMP SORT

INC
    MOVE.B #1,D6
    ADD.B #1,D5
    SUBA.L #12,A7
    MOVE.B #0,D7
    JMP SORT

SWAP
    MOVE.L D3,(A7)
    SUBA.L #4,A7
    MOVE.L D4,(A7)
    ADDA.L #4,A7
    ADD.B #1,D6
    JMP SORT


PRINT
    LEA SPACE,A1
    SUBA.L #12,A7
    MOVE.B #0,D6    ;reuse D6
    
OUT
    CMP #4,D6
    BEQ END
    
    MOVE.L (A7),D1
    MOVE.B #3,D0
    TRAP #15
    
    MOVE.B #14,D0
    TRAP #15
    
    ADD.B #1,D6
    ADDA.L #4,A7
    JMP OUT
END    SIMHALT             ; halt simulator

* Put variables and constants here
ARRAY DC.L 3,-1,0,4
SPACE DC.B ' ',0
    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
