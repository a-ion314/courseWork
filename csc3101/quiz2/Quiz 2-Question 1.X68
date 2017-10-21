*-----------------------------------------------------------
* Title      :Quiz 2 Question 1
* Written by :Adrian Ionascu
* Date       :12/2/16
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
       
    MOVE.B #4,D7          ;size of array
    MOVE.B #0,D6          ;counter
                          ;d2 = smallest d3 = largest
    
    LEA ARRAY1, A2
    MOVE.B (A2),D2
    MOVE.B (A2),D3
    
LOOP MOVE.B (A2),D1
     MOVE.B #3,D0
     TRAP #15
     
     LEA SPACE,A1
     MOVE.B #14,D0
     TRAP #15
     
     MOVE.B (A2),D4
     
CMP  CMP D2,D4
     BLT SMALL
     CMP D3,D4
     BGT LARGE
     
     CMP D6,D7
     BEQ LASTPRINT
     
     ADD.B #0,(A2)+
     ADD.B #1,D6     
     BRA LOOP
     
SMALL MOVE.B (A2),D2
      BRA CMP
LARGE MOVE.B (A2),D3
      BRA CMP


     
LASTPRINT LEA SPACE,A1  ;space and move to next line
          MOVE.B #13,D0
          TRAP #15
          
          LEA BIG,A1    ;print big text
          MOVE.B #14,D0
          TRAP #15

          MOVE.B D3,D1
          MOVE.B #3,D0  ;print largest number
          TRAP #15

          LEA SPACE,A1  ;space and move to next line
          MOVE.B #13,D0
          TRAP #15

          LEA SM,A1    ;print small text
          MOVE.B #14,D0
          TRAP #15

          MOVE.B D2,D1
          MOVE.B #3,D0  ;print smallest number
          TRAP #15     
    
END  SIMHALT             ; halt simulator

* Put variables and constants here
BIG DC.B 'Largest number: ',0
SM DC.B 'Smallest number: ',0
SPACE DC.B ' ',0
ARRAY1 DC.B 14,7,1,17,10
    END    START        ; last line of source



*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
