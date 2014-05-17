#include "mbed.h"
#include "Serial.h"
#include <string.h>
#include <stdlib.h>
#include <string>

Ticker colCycle;
int next_col = 1;
int next_row = 1;
int coord[8][8] = {{0}};
int array_changed = 1;

Serial pc(USBTX, USBRX);
Serial pi(p9, p10);

// Read ports for each quadrant
AnalogIn quad0(p15);
AnalogIn quad1(p16);
AnalogIn quad2(p17);
AnalogIn quad3(p18);
DigitalOut row4(p19);
DigitalOut row5(p20);

//Column Selects
DigitalOut col0(p21);
DigitalOut col1(p22);
DigitalOut col2(p23);
DigitalOut col3(p24);

// Row/Mux selects
DigitalOut sel0(p27);
DigitalOut sel1(p28);
DigitalOut sel2(p29);
DigitalOut sel3(p30);

void cycleCol() {
                  // printf("quad0 = %f, sel = %d, col = %d\r\n", quad0.read(), next_row, next_col);

    if (next_col == 0){
        col0 = 0;
        col1 = 1;
        col2 = 1;
        col3 = 1;
    } else if (next_col == 1) {
        col0 = 1;
        col1 = 0;
        col2 = 1;
        col3 = 1;
    } else if (next_col == 2) {
        col0 = 1;
        col1 = 1;
        col2 = 0;
        col3 = 1;
    } else if (next_col == 3) {
        col0 = 1;
        col1 = 1;
        col2 = 1;
        col3 = 0;
    }
    next_col++;
    
    if (next_col > 3) {
        next_col = 0;
        if (next_row == 0){
            sel0 = 1;
            sel1 = 0;
            sel2 = 0;
            sel3 = 0;
        } else if (next_row == 1) {
            sel0 = 0;
            sel1 = 1;
            sel2 = 0;
            sel3 = 0;
        } else if (next_row == 2) {
            sel0 = 0;
            sel1 = 0;
            sel2 = 1;
            sel3 = 0;
        } else if (next_row == 3) {
            sel0 = 0;
            sel1 = 0;
            sel2 = 0;
            sel3 = 1;
        }
        next_row++;
        if (next_row > 3) {
            next_row = 0;
        }
    }
        
        if (!col0) {      
            //printf("row3 = %f\r\n", row3.read());
            //------------------------------------------------------
            if (sel0 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[0][0] != 6) {
                        array_changed = 1;
                    }
                    coord[0][0] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[0][0] != 5) {
                        array_changed = 1;
                    }
                    coord[0][0] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[0][0] != 4) {
                        array_changed = 1;
                    }
                    coord[0][0] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[0][0] != 3) {
                        array_changed = 1;
                    }
                    coord[0][0] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[0][0] != 2) {
                        array_changed = 1;
                    }
                    coord[0][0] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[0][0] != 1) {
                        array_changed = 1;
                    }
                    coord[0][0] = 1;
                } else {
                    if (coord[0][0] != 0) {
                        array_changed = 1;
                    }
                    coord[0][0] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[4][0] != 6) {
                        array_changed = 1;
                    }
                    coord[4][0] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[4][0] != 5) {
                        array_changed = 1;
                    }
                    coord[4][0] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[4][0] != 4) {
                        array_changed = 1;
                    }
                    coord[4][0] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[4][0] != 3) {
                        array_changed = 1;
                    }
                    coord[4][0] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[4][0] != 2) {
                        array_changed = 1;
                    }
                    coord[4][0] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[4][0] != 1) {
                        array_changed = 1;
                    }
                    coord[4][0] = 1;
                } else {
                    if (coord[4][0] != 0) {
                        array_changed = 1;
                    }
                    coord[4][0] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[0][4] != 6) {
                        array_changed = 1;
                    }
                    coord[0][4] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[0][4] != 5) {
                        array_changed = 1;
                    }
                    coord[0][4] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[0][4] != 4) {
                        array_changed = 1;
                    }
                    coord[0][4] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[0][4] != 3) {
                        array_changed = 1;
                    }
                    coord[0][4] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[0][4] != 2) {
                        array_changed = 1;
                    }
                    coord[0][4] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[0][4] != 1) {
                        array_changed = 1;
                    }
                    coord[0][4] = 1;
                } else {
                    if (coord[0][4] != 0) {
                        array_changed = 1;
                    }
                    coord[0][4] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[4][4] != 6) {
                        array_changed = 1;
                    }
                    coord[4][4] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[4][4] != 5) {
                        array_changed = 1;
                    }
                    coord[4][4] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[4][4] != 4) {
                        array_changed = 1;
                    }
                    coord[4][4] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[4][4] != 3) {
                        array_changed = 1;
                    }
                    coord[4][4] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[4][4] != 2) {
                        array_changed = 1;
                    }
                    coord[4][4] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[4][4] != 1) {
                        array_changed = 1;
                    }
                    coord[4][4] = 1;
                } else {
                    if (coord[4][4] != 0) {
                        array_changed = 1;
                    }
                    coord[4][4] = 0;
                }
            }
            
        //------------------------------------------------------
           else if (sel1 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[0][1] != 6) {
                        array_changed = 1;
                    }
                    coord[0][1] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[0][1] != 5) {
                        array_changed = 1;
                    }
                    coord[0][1] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[0][1] != 4) {
                        array_changed = 1;
                    }
                    coord[0][1] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[0][1] != 3) {
                        array_changed = 1;
                    }
                    coord[0][1] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[0][1] != 2) {
                        array_changed = 1;
                    }
                    coord[0][1] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[0][1] != 1) {
                        array_changed = 1;
                    }
                    coord[0][1] = 1;
                } else {
                    if (coord[0][1] != 0) {
                        array_changed = 1;
                    }
                    coord[0][1] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[4][1] != 6) {
                        array_changed = 1;
                    }
                    coord[4][1] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[4][1] != 5) {
                        array_changed = 1;
                    }
                    coord[4][1] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[4][1] != 4) {
                        array_changed = 1;
                    }
                    coord[4][1] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[4][1] != 3) {
                        array_changed = 1;
                    }
                    coord[4][1] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[4][1] != 2) {
                        array_changed = 1;
                    }
                    coord[4][1] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[4][1] != 1) {
                        array_changed = 1;
                    }
                    coord[4][1] = 1;
                } else {
                    if (coord[4][1] != 0) {
                        array_changed = 1;
                    }
                    coord[4][1] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[0][5] != 6) {
                        array_changed = 1;
                    }
                    coord[0][5] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[0][5] != 5) {
                        array_changed = 1;
                    }
                    coord[0][5] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[0][5] != 4) {
                        array_changed = 1;
                    }
                    coord[0][5] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[0][5] != 3) {
                        array_changed = 1;
                    }
                    coord[0][5] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[0][5] != 2) {
                        array_changed = 1;
                    }
                    coord[0][5] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[0][5] != 1) {
                        array_changed = 1;
                    }
                    coord[0][5] = 1;
                } else {
                    if (coord[0][5] != 0) {
                        array_changed = 1;
                    }
                    coord[0][5] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[4][5] != 6) {
                        array_changed = 1;
                    }
                    coord[4][5] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[4][5] != 5) {
                        array_changed = 1;
                    }
                    coord[4][5] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[4][5] != 4) {
                        array_changed = 1;
                    }
                    coord[4][5] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[4][5] != 3) {
                        array_changed = 1;
                    }
                    coord[4][5] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[4][5] != 2) {
                        array_changed = 1;
                    }
                    coord[4][5] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[4][5] != 1) {
                        array_changed = 1;
                    }
                    coord[4][5] = 1;
                } else {
                    if (coord[4][5] != 0) {
                        array_changed = 1;
                    }
                    coord[4][5] = 0;
                }
            }
        
            
            //------------------------------------------------------
           else if (sel2 == 1) {
               if (quad0 > .43 && quad0 < .45)  {
                    if (coord[0][2] != 6) {
                        array_changed = 1;
                    }
                    coord[0][2] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[0][2] != 5) {
                        array_changed = 1;
                    }
                    coord[0][2] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[0][2] != 4) {
                        array_changed = 1;
                    }
                    coord[0][2] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[0][2] != 3) {
                        array_changed = 1;
                    }
                    coord[0][2] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[0][2] != 2) {
                        array_changed = 1;
                    }
                    coord[0][2] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[0][2] != 1) {
                        array_changed = 1;
                    }
                    coord[0][2] = 1;
                } else {
                    if (coord[0][2] != 0) {
                        array_changed = 1;
                    }
                    coord[0][2] = 0;
                }
                
                                //printf("%f\r\n", quad1.read());

                 if (quad1 > .43 && quad1 < .45)  {
                    if (coord[4][2] != 6) {
                        array_changed = 1;
                    }
                    coord[4][2] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[4][2] != 5) {
                        array_changed = 1;
                    }
                    coord[4][2] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[4][2] != 4) {
                        array_changed = 1;
                    }
                    coord[4][2] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[4][2] != 3) {
                        array_changed = 1;
                    }
                    coord[4][2] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[4][2] != 2) {
                        array_changed = 1;
                    }
                    coord[4][2] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[4][2] != 1) {
                        array_changed = 1;
                    }
                    coord[4][2] = 1;
                } else {
                    if (coord[4][2] != 0) {
                        array_changed = 1;
                    }
                    coord[4][2] = 0;
                }
                
                
                 if (quad2 > .43 && quad2 < .45)  {
                    if (coord[0][6] != 6) {
                        array_changed = 1;
                    }
                    coord[0][6] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[0][6] != 5) {
                        array_changed = 1;
                    }
                    coord[0][6] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[0][6] != 4) {
                        array_changed = 1;
                    }
                    coord[0][6] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[0][6] != 3) {
                        array_changed = 1;
                    }
                    coord[0][6] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[0][6] != 2) {
                        array_changed = 1;
                    }
                    coord[0][6] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[0][6] != 1) {
                        array_changed = 1;
                    }
                    coord[0][6] = 1;
                } else {
                    if (coord[0][6] != 0) {
                        array_changed = 1;
                    }
                    coord[0][6] = 0;
                }
                
                
                 if (quad3 > .43 && quad3 < .45)  {
                    if (coord[4][6] != 6) {
                        array_changed = 1;
                    }
                    coord[4][6] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[4][6] != 5) {
                        array_changed = 1;
                    }
                    coord[4][6] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[4][6] != 4) {
                        array_changed = 1;
                    }
                    coord[4][6] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[4][6] != 3) {
                        array_changed = 1;
                    }
                    coord[4][6] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[4][6] != 2) {
                        array_changed = 1;
                    }
                    coord[4][6] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[4][6] != 1) {
                        array_changed = 1;
                    }
                    coord[4][6] = 1;
                } else {
                    if (coord[4][6] != 0) {
                        array_changed = 1;
                    }
                    coord[4][6] = 0;
                }
            
        }
            
           //------------------------------------------------------
           else if (sel3 ==  1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[0][3] != 6) {
                        array_changed = 1;
                    }
                    coord[0][3] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[0][3] != 5) {
                        array_changed = 1;
                    }
                    coord[0][3] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[0][3] != 4) {
                        array_changed = 1;
                    }
                    coord[0][3] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[0][3] != 3) {
                        array_changed = 1;
                    }
                    coord[0][3] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[0][3] != 2) {
                        array_changed = 1;
                    }
                    coord[0][3] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[0][3] != 1) {
                        array_changed = 1;
                    }
                    coord[0][3] = 1;
                } else {
                    if (coord[0][3] != 0) {
                        array_changed = 1;
                    }
                    coord[0][3] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[4][3] != 6) {
                        array_changed = 1;
                    }
                    coord[4][3] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[4][3] != 5) {
                        array_changed = 1;
                    }
                    coord[4][3] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[4][3] != 4) {
                        array_changed = 1;
                    }
                    coord[4][3] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[4][3] != 3) {
                        array_changed = 1;
                    }
                    coord[4][3] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[4][3] != 2) {
                        array_changed = 1;
                    }
                    coord[4][3] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[4][3] != 1) {
                        array_changed = 1;
                    }
                    coord[4][3] = 1;
                } else {
                    if (coord[4][3] != 0) {
                        array_changed = 1;
                    }
                    coord[4][3] = 0;
                }
                
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[0][7] != 6) {
                        array_changed = 1;
                    }
                    coord[0][7] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[0][7] != 5) {
                        array_changed = 1;
                    }
                    coord[0][7] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[0][7] != 4) {
                        array_changed = 1;
                    }
                    coord[0][7] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[0][7] != 3) {
                        array_changed = 1;
                    }
                    coord[0][7] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[0][7] != 2) {
                        array_changed = 1;
                    }
                    coord[0][7] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[0][7] != 1) {
                        array_changed = 1;
                    }
                    coord[0][7] = 1;
                } else {
                    if (coord[0][7] != 0) {
                        array_changed = 1;
                    }
                    coord[0][7] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[4][7] != 6) {
                        array_changed = 1;
                    }
                    coord[4][7] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[4][7] != 5) {
                        array_changed = 1;
                    }
                    coord[4][7] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[4][7] != 4) {
                        array_changed = 1;
                    }
                    coord[4][7] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[4][7] != 3) {
                        array_changed = 1;
                    }
                    coord[4][7] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[4][7] != 2) {
                        array_changed = 1;
                    }
                    coord[4][7] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[4][7] != 1) {
                        array_changed = 1;
                    }
                    coord[4][7] = 1;
                } else {
                    if (coord[4][7] != 0) {
                        array_changed = 1;
                    }
                    coord[4][7] = 0;
                }
            }
           
        }
        //-----------------------------------------------------------
        if (!col1) {      
            //printf("row3 = %f\r\n", row3.read());
            //------------------------------------------------------
            if (sel0 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[1][0] != 6) {
                        array_changed = 1;
                    }
                    coord[1][0] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[1][0] != 5) {
                        array_changed = 1;
                    }
                    coord[1][0] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[1][0] != 4) {
                        array_changed = 1;
                    }
                    coord[1][0] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[1][0] != 3) {
                        array_changed = 1;
                    }
                    coord[1][0] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[1][0] != 2) {
                        array_changed = 1;
                    }
                    coord[1][0] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[1][0] != 1) {
                        array_changed = 1;
                    }
                    coord[1][0] = 1;
                } else {
                    if (coord[1][0] != 0) {
                        array_changed = 1;
                    }
                    coord[1][0] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[5][0] != 6) {
                        array_changed = 1;
                    }
                    coord[5][0] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[5][0] != 5) {
                        array_changed = 1;
                    }
                    coord[5][0] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[5][0] != 4) {
                        array_changed = 1;
                    }
                    coord[5][0] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[5][0] != 3) {
                        array_changed = 1;
                    }
                    coord[5][0] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[5][0] != 2) {
                        array_changed = 1;
                    }
                    coord[5][0] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[5][0] != 1) {
                        array_changed = 1;
                    }
                    coord[5][0] = 1;
                } else {
                    if (coord[5][0] != 0) {
                        array_changed = 1;
                    }
                    coord[5][0] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[1][4] != 6) {
                        array_changed = 1;
                    }
                    coord[1][4] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[1][4] != 5) {
                        array_changed = 1;
                    }
                    coord[1][4] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[1][4] != 4) {
                        array_changed = 1;
                    }
                    coord[1][4] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[1][4] != 3) {
                        array_changed = 1;
                    }
                    coord[1][4] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[1][4] != 2) {
                        array_changed = 1;
                    }
                    coord[1][4] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[1][4] != 1) {
                        array_changed = 1;
                    }
                    coord[1][4] = 1;
                } else {
                    if (coord[1][4] != 0) {
                        array_changed = 1;
                    }
                    coord[1][4] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[5][4] != 6) {
                        array_changed = 1;
                    }
                    coord[5][4] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[5][4] != 5) {
                        array_changed = 1;
                    }
                    coord[5][4] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[5][4] != 4) {
                        array_changed = 1;
                    }
                    coord[5][4] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[5][4] != 3) {
                        array_changed = 1;
                    }
                    coord[5][4] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[5][4] != 2) {
                        array_changed = 1;
                    }
                    coord[5][4] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[5][4] != 1) {
                        array_changed = 1;
                    }
                    coord[5][4] = 1;
                } else {
                    if (coord[5][4] != 0) {
                        array_changed = 1;
                    }
                    coord[5][4] = 0;
                }
            }
            
        //------------------------------------------------------
           else if (sel1 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[1][1] != 6) {
                        array_changed = 1;
                    }
                    coord[1][1] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[1][1] != 5) {
                        array_changed = 1;
                    }
                    coord[1][1] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[1][1] != 4) {
                        array_changed = 1;
                    }
                    coord[1][1] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[1][1] != 3) {
                        array_changed = 1;
                    }
                    coord[1][1] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[1][1] != 2) {
                        array_changed = 1;
                    }
                    coord[1][1] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[1][1] != 1) {
                        array_changed = 1;
                    }
                    coord[1][1] = 1;
                } else {
                    if (coord[1][1] != 0) {
                        array_changed = 1;
                    }
                    coord[1][1] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[5][1] != 6) {
                        array_changed = 1;
                    }
                    coord[5][1] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[5][1] != 5) {
                        array_changed = 1;
                    }
                    coord[5][1] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[5][1] != 4) {
                        array_changed = 1;
                    }
                    coord[5][1] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[5][1] != 3) {
                        array_changed = 1;
                    }
                    coord[5][1] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[5][1] != 2) {
                        array_changed = 1;
                    }
                    coord[5][1] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[5][1] != 1) {
                        array_changed = 1;
                    }
                    coord[5][1] = 1;
                } else {
                    if (coord[5][1] != 0) {
                        array_changed = 1;
                    }
                    coord[5][1] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[1][5] != 6) {
                        array_changed = 1;
                    }
                    coord[1][5] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[1][5] != 5) {
                        array_changed = 1;
                    }
                    coord[1][5] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[1][5] != 4) {
                        array_changed = 1;
                    }
                    coord[1][5] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[1][5] != 3) {
                        array_changed = 1;
                    }
                    coord[1][5] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[1][5] != 2) {
                        array_changed = 1;
                    }
                    coord[1][5] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[1][5] != 1) {
                        array_changed = 1;
                    }
                    coord[1][5] = 1;
                } else {
                    if (coord[1][5] != 0) {
                        array_changed = 1;
                    }
                    coord[1][5] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[5][5] != 6) {
                        array_changed = 1;
                    }
                    coord[5][5] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[5][5] != 5) {
                        array_changed = 1;
                    }
                    coord[5][5] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[5][5] != 4) {
                        array_changed = 1;
                    }
                    coord[5][5] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[5][5] != 3) {
                        array_changed = 1;
                    }
                    coord[5][5] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[5][5] != 2) {
                        array_changed = 1;
                    }
                    coord[5][5] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[5][5] != 1) {
                        array_changed = 1;
                    }
                    coord[5][5] = 1;
                } else {
                    if (coord[5][5] != 0) {
                        array_changed = 1;
                    }
                    coord[5][5] = 0;
                }
            }
        
            
            //------------------------------------------------------
           else if (sel2 == 1) {
               if (quad0 > .43 && quad0 < .45)  {
                    if (coord[1][2] != 6) {
                        array_changed = 1;
                    }
                    coord[1][2] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[1][2] != 5) {
                        array_changed = 1;
                    }
                    coord[1][2] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[1][2] != 4) {
                        array_changed = 1;
                    }
                    coord[1][2] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[1][2] != 3) {
                        array_changed = 1;
                    }
                    coord[1][2] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[1][2] != 2) {
                        array_changed = 1;
                    }
                    coord[1][2] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[1][2] != 1) {
                        array_changed = 1;
                    }
                    coord[1][2] = 1;
                } else {
                    if (coord[1][2] != 0) {
                        array_changed = 1;
                    }
                    coord[1][2] = 0;
                }
                                //printf("%f\r\n", quad1.read());

                
                 if (quad1 > .43 && quad1 < .45)  {
                    if (coord[5][2] != 6) {
                        array_changed = 1;
                    }
                    coord[5][2] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[5][2] != 5) {
                        array_changed = 1;
                    }
                    coord[5][2] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[5][2] != 4) {
                        array_changed = 1;
                    }
                    coord[5][2] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[5][2] != 3) {
                        array_changed = 1;
                    }
                    coord[5][2] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[5][2] != 2) {
                        array_changed = 1;
                    }
                    coord[5][2] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[5][2] != 1) {
                        array_changed = 1;
                    }
                    coord[5][2] = 1;
                } else {
                    if (coord[5][2] != 0) {
                        array_changed = 1;
                    }
                    coord[5][2] = 0;
                }
                
                
                 if (quad2 > .43 && quad2 < .45)  {
                    if (coord[1][6] != 6) {
                        array_changed = 1;
                    }
                    coord[1][6] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[1][6] != 5) {
                        array_changed = 1;
                    }
                    coord[1][6] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[1][6] != 4) {
                        array_changed = 1;
                    }
                    coord[1][6] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[1][6] != 3) {
                        array_changed = 1;
                    }
                    coord[1][6] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[1][6] != 2) {
                        array_changed = 1;
                    }
                    coord[1][6] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[1][6] != 1) {
                        array_changed = 1;
                    }
                    coord[1][6] = 1;
                } else {
                    if (coord[1][6] != 0) {
                        array_changed = 1;
                    }
                    coord[1][6] = 0;
                }
                
                
                 if (quad3 > .43 && quad3 < .45)  {
                    if (coord[5][6] != 6) {
                        array_changed = 1;
                    }
                    coord[5][6] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[5][6] != 5) {
                        array_changed = 1;
                    }
                    coord[5][6] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[5][6] != 4) {
                        array_changed = 1;
                    }
                    coord[5][6] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[5][6] != 3) {
                        array_changed = 1;
                    }
                    coord[5][6] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[5][6] != 2) {
                        array_changed = 1;
                    }
                    coord[5][6] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[5][6] != 1) {
                        array_changed = 1;
                    }
                    coord[5][6] = 1;
                } else {
                    if (coord[5][6] != 0) {
                        array_changed = 1;
                    }
                    coord[5][6] = 0;
                }
            
        }
            
           //------------------------------------------------------
           else if (sel3 ==  1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[1][3] != 6) {
                        array_changed = 1;
                    }
                    coord[1][3] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[1][3] != 5) {
                        array_changed = 1;
                    }
                    coord[1][3] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[1][3] != 4) {
                        array_changed = 1;
                    }
                    coord[1][3] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[1][3] != 3) {
                        array_changed = 1;
                    }
                    coord[1][3] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[1][3] != 2) {
                        array_changed = 1;
                    }
                    coord[1][3] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[1][3] != 1) {
                        array_changed = 1;
                    }
                    coord[1][3] = 1;
                } else {
                    if (coord[1][3] != 0) {
                        array_changed = 1;
                    }
                    coord[1][3] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[5][3] != 6) {
                        array_changed = 1;
                    }
                    coord[5][3] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[5][3] != 5) {
                        array_changed = 1;
                    }
                    coord[5][3] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[5][3] != 4) {
                        array_changed = 1;
                    }
                    coord[5][3] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[5][3] != 3) {
                        array_changed = 1;
                    }
                    coord[5][3] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[5][3] != 2) {
                        array_changed = 1;
                    }
                    coord[5][3] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[5][3] != 1) {
                        array_changed = 1;
                    }
                    coord[5][3] = 1;
                } else {
                    if (coord[5][3] != 0) {
                        array_changed = 1;
                    }
                    coord[5][3] = 0;
                }
                
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[1][7] != 6) {
                        array_changed = 1;
                    }
                    coord[1][7] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[1][7] != 5) {
                        array_changed = 1;
                    }
                    coord[1][7] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[1][7] != 4) {
                        array_changed = 1;
                    }
                    coord[1][7] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[1][7] != 3) {
                        array_changed = 1;
                    }
                    coord[1][7] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[1][7] != 2) {
                        array_changed = 1;
                    }
                    coord[1][7] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[1][7] != 1) {
                        array_changed = 1;
                    }
                    coord[1][7] = 1;
                } else {
                    if (coord[1][7] != 0) {
                        array_changed = 1;
                    }
                    coord[1][7] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[5][7] != 6) {
                        array_changed = 1;
                    }
                    coord[5][7] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[5][7] != 5) {
                        array_changed = 1;
                    }
                    coord[5][7] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[5][7] != 4) {
                        array_changed = 1;
                    }
                    coord[5][7] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[5][7] != 3) {
                        array_changed = 1;
                    }
                    coord[5][7] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[5][7] != 2) {
                        array_changed = 1;
                    }
                    coord[5][7] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[5][7] != 1) {
                        array_changed = 1;
                    }
                    coord[5][7] = 1;
                } else {
                    if (coord[5][7] != 0) {
                        array_changed = 1;
                    }
                    coord[5][7] = 0;
                }
            }
        }
        if (!col2) {      
            //printf("row3 = %f\r\n", row3.read());
            //------------------------------------------------------
            if (sel0 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[2][0] != 6) {
                        array_changed = 1;
                    }
                    coord[2][0] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[2][0] != 5) {
                        array_changed = 1;
                    }
                    coord[2][0] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[2][0] != 4) {
                        array_changed = 1;
                    }
                    coord[2][0] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[2][0] != 3) {
                        array_changed = 1;
                    }
                    coord[2][0] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[2][0] != 2) {
                        array_changed = 1;
                    }
                    coord[2][0] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[2][0] != 1) {
                        array_changed = 1;
                    }
                    coord[2][0] = 1;
                } else {
                    if (coord[2][0] != 0) {
                        array_changed = 1;
                    }
                    coord[2][0] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[6][0] != 6) {
                        array_changed = 1;
                    }
                    coord[6][0] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[6][0] != 5) {
                        array_changed = 1;
                    }
                    coord[6][0] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[6][0] != 4) {
                        array_changed = 1;
                    }
                    coord[6][0] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[6][0] != 3) {
                        array_changed = 1;
                    }
                    coord[6][0] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[6][0] != 2) {
                        array_changed = 1;
                    }
                    coord[6][0] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[6][0] != 1) {
                        array_changed = 1;
                    }
                    coord[6][0] = 1;
                } else {
                    if (coord[6][0] != 0) {
                        array_changed = 1;
                    }
                    coord[6][0] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[2][4] != 6) {
                        array_changed = 1;
                    }
                    coord[2][4] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[2][4] != 5) {
                        array_changed = 1;
                    }
                    coord[2][4] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[2][4] != 4) {
                        array_changed = 1;
                    }
                    coord[2][4] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[2][4] != 3) {
                        array_changed = 1;
                    }
                    coord[2][4] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[2][4] != 2) {
                        array_changed = 1;
                    }
                    coord[2][4] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[2][4] != 1) {
                        array_changed = 1;
                    }
                    coord[2][4] = 1;
                } else {
                    if (coord[2][4] != 0) {
                        array_changed = 1;
                    }
                    coord[2][4] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[6][4] != 6) {
                        array_changed = 1;
                    }
                    coord[6][4] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[6][4] != 5) {
                        array_changed = 1;
                    }
                    coord[6][4] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[6][4] != 4) {
                        array_changed = 1;
                    }
                    coord[6][4] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[6][4] != 3) {
                        array_changed = 1;
                    }
                    coord[6][4] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[6][4] != 2) {
                        array_changed = 1;
                    }
                    coord[6][4] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[6][4] != 1) {
                        array_changed = 1;
                    }
                    coord[6][4] = 1;
                } else {
                    if (coord[6][4] != 0) {
                        array_changed = 1;
                    }
                    coord[6][4] = 0;
                }
            }
            
        //------------------------------------------------------
           else if (sel1 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[2][1] != 6) {
                        array_changed = 1;
                    }
                    coord[2][1] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[2][1] != 5) {
                        array_changed = 1;
                    }
                    coord[2][1] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[2][1] != 4) {
                        array_changed = 1;
                    }
                    coord[2][1] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[2][1] != 3) {
                        array_changed = 1;
                    }
                    coord[2][1] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[2][1] != 2) {
                        array_changed = 1;
                    }
                    coord[2][1] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[2][1] != 1) {
                        array_changed = 1;
                    }
                    coord[2][1] = 1;
                } else {
                    if (coord[2][1] != 0) {
                        array_changed = 1;
                    }
                    coord[2][1] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[6][1] != 6) {
                        array_changed = 1;
                    }
                    coord[6][1] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[6][1] != 5) {
                        array_changed = 1;
                    }
                    coord[6][1] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[6][1] != 4) {
                        array_changed = 1;
                    }
                    coord[6][1] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[6][1] != 3) {
                        array_changed = 1;
                    }
                    coord[6][1] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[6][1] != 2) {
                        array_changed = 1;
                    }
                    coord[6][1] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[6][1] != 1) {
                        array_changed = 1;
                    }
                    coord[6][1] = 1;
                } else {
                    if (coord[6][1] != 0) {
                        array_changed = 1;
                    }
                    coord[6][1] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[2][5] != 6) {
                        array_changed = 1;
                    }
                    coord[2][5] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[2][5] != 5) {
                        array_changed = 1;
                    }
                    coord[2][5] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[2][5] != 4) {
                        array_changed = 1;
                    }
                    coord[2][5] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[2][5] != 3) {
                        array_changed = 1;
                    }
                    coord[2][5] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[2][5] != 2) {
                        array_changed = 1;
                    }
                    coord[2][5] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[2][5] != 1) {
                        array_changed = 1;
                    }
                    coord[2][5] = 1;
                } else {
                    if (coord[2][5] != 0) {
                        array_changed = 1;
                    }
                    coord[2][5] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[6][5] != 6) {
                        array_changed = 1;
                    }
                    coord[6][5] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[6][5] != 5) {
                        array_changed = 1;
                    }
                    coord[6][5] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[6][5] != 4) {
                        array_changed = 1;
                    }
                    coord[6][5] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[6][5] != 3) {
                        array_changed = 1;
                    }
                    coord[6][5] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[6][5] != 2) {
                        array_changed = 1;
                    }
                    coord[6][5] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[6][5] != 1) {
                        array_changed = 1;
                    }
                    coord[6][5] = 1;
                } else {
                    if (coord[6][5] != 0) {
                        array_changed = 1;
                    }
                    coord[6][5] = 0;
                }
            }
        
            
            //------------------------------------------------------
           else if (sel2 == 1) {
               if (quad0 > .43 && quad0 < .45)  {
                    if (coord[2][2] != 6) {
                        array_changed = 1;
                    }
                    coord[2][2] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[2][2] != 5) {
                        array_changed = 1;
                    }
                    coord[2][2] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[2][2] != 4) {
                        array_changed = 1;
                    }
                    coord[2][2] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[2][2] != 3) {
                        array_changed = 1;
                    }
                    coord[2][2] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[2][2] != 2) {
                        array_changed = 1;
                    }
                    coord[2][2] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[2][2] != 1) {
                        array_changed = 1;
                    }
                    coord[2][2] = 1;
                } else {
                    if (coord[2][2] != 0) {
                        array_changed = 1;
                    }
                    coord[2][2] = 0;
                }
                
                                //printf("%f\r\n", quad1.read());

                 if (quad1 > .43 && quad1 < .45)  {
                    if (coord[6][2] != 6) {
                        array_changed = 1;
                    }
                    coord[6][2] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[6][2] != 5) {
                        array_changed = 1;
                    }
                    coord[6][2] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[6][2] != 4) {
                        array_changed = 1;
                    }
                    coord[6][2] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[6][2] != 3) {
                        array_changed = 1;
                    }
                    coord[6][2] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[6][2] != 2) {
                        array_changed = 1;
                    }
                    coord[6][2] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[6][2] != 1) {
                        array_changed = 1;
                    }
                    coord[6][2] = 1;
                } else {
                    if (coord[6][2] != 0) {
                        array_changed = 1;
                    }
                    coord[6][2] = 0;
                }
                
                
                 if (quad2 > .43 && quad2 < .45)  {
                    if (coord[2][6] != 6) {
                        array_changed = 1;
                    }
                    coord[2][6] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[2][6] != 5) {
                        array_changed = 1;
                    }
                    coord[2][6] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[2][6] != 4) {
                        array_changed = 1;
                    }
                    coord[2][6] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[2][6] != 3) {
                        array_changed = 1;
                    }
                    coord[2][6] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[2][6] != 2) {
                        array_changed = 1;
                    }
                    coord[2][6] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[2][6] != 1) {
                        array_changed = 1;
                    }
                    coord[2][6] = 1;
                } else {
                    if (coord[2][6] != 0) {
                        array_changed = 1;
                    }
                    coord[2][6] = 0;
                }
                
                
                 if (quad3 > .43 && quad3 < .45)  {
                    if (coord[6][6] != 6) {
                        array_changed = 1;
                    }
                    coord[6][6] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[6][6] != 5) {
                        array_changed = 1;
                    }
                    coord[6][6] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[6][6] != 4) {
                        array_changed = 1;
                    }
                    coord[6][6] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[6][6] != 3) {
                        array_changed = 1;
                    }
                    coord[6][6] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[6][6] != 2) {
                        array_changed = 1;
                    }
                    coord[6][6] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[6][6] != 1) {
                        array_changed = 1;
                    }
                    coord[6][6] = 1;
                } else {
                    if (coord[6][6] != 0) {
                        array_changed = 1;
                    }
                    coord[6][6] = 0;
                }
            
        }
            
           //------------------------------------------------------
           else if (sel3 ==  1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[2][3] != 6) {
                        array_changed = 1;
                    }
                    coord[2][3] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[2][3] != 5) {
                        array_changed = 1;
                    }
                    coord[2][3] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[2][3] != 4) {
                        array_changed = 1;
                    }
                    coord[2][3] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[2][3] != 3) {
                        array_changed = 1;
                    }
                    coord[2][3] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[2][3] != 2) {
                        array_changed = 1;
                    }
                    coord[2][3] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[2][3] != 1) {
                        array_changed = 1;
                    }
                    coord[2][3] = 1;
                } else {
                    if (coord[2][3] != 0) {
                        array_changed = 1;
                    }
                    coord[2][3] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[6][3] != 6) {
                        array_changed = 1;
                    }
                    coord[6][3] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[6][3] != 5) {
                        array_changed = 1;
                    }
                    coord[6][3] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[6][3] != 4) {
                        array_changed = 1;
                    }
                    coord[6][3] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[6][3] != 3) {
                        array_changed = 1;
                    }
                    coord[6][3] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[6][3] != 2) {
                        array_changed = 1;
                    }
                    coord[6][3] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[6][3] != 1) {
                        array_changed = 1;
                    }
                    coord[6][3] = 1;
                } else {
                    if (coord[6][3] != 0) {
                        array_changed = 1;
                    }
                    coord[6][3] = 0;
                }
                
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[2][7] != 6) {
                        array_changed = 1;
                    }
                    coord[2][7] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[2][7] != 5) {
                        array_changed = 1;
                    }
                    coord[2][7] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[2][7] != 4) {
                        array_changed = 1;
                    }
                    coord[2][7] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[2][7] != 3) {
                        array_changed = 1;
                    }
                    coord[2][7] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[2][7] != 2) {
                        array_changed = 1;
                    }
                    coord[2][7] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[2][7] != 1) {
                        array_changed = 1;
                    }
                    coord[2][7] = 1;
                } else {
                    if (coord[2][7] != 0) {
                        array_changed = 1;
                    }
                    coord[2][7] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[6][7] != 6) {
                        array_changed = 1;
                    }
                    coord[6][7] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[6][7] != 5) {
                        array_changed = 1;
                    }
                    coord[6][7] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[6][7] != 4) {
                        array_changed = 1;
                    }
                    coord[6][7] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[6][7] != 3) {
                        array_changed = 1;
                    }
                    coord[6][7] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[6][7] != 2) {
                        array_changed = 1;
                    }
                    coord[6][7] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[6][7] != 1) {
                        array_changed = 1;
                    }
                    coord[6][7] = 1;
                } else {
                    if (coord[6][7] != 0) {
                        array_changed = 1;
                    }
                    coord[6][7] = 0;
                }
            }
           
        }
        if (!col3) {      
            //printf("row3 = %f\r\n", row3.read());
            //------------------------------------------------------
            if (sel0 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[3][0] != 6) {
                        array_changed = 1;
                    }
                    coord[3][0] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[3][0] != 5) {
                        array_changed = 1;
                    }
                    coord[3][0] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[3][0] != 4) {
                        array_changed = 1;
                    }
                    coord[3][0] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[3][0] != 3) {
                        array_changed = 1;
                    }
                    coord[3][0] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[3][0] != 2) {
                        array_changed = 1;
                    }
                    coord[3][0] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[3][0] != 1) {
                        array_changed = 1;
                    }
                    coord[3][0] = 1;
                } else {
                    if (coord[3][0] != 0) {
                        array_changed = 1;
                    }
                    coord[3][0] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[7][0] != 6) {
                        array_changed = 1;
                    }
                    coord[7][0] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[7][0] != 5) {
                        array_changed = 1;
                    }
                    coord[7][0] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[7][0] != 4) {
                        array_changed = 1;
                    }
                    coord[7][0] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[7][0] != 3) {
                        array_changed = 1;
                    }
                    coord[7][0] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[7][0] != 2) {
                        array_changed = 1;
                    }
                    coord[7][0] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[7][0] != 1) {
                        array_changed = 1;
                    }
                    coord[7][0] = 1;
                } else {
                    if (coord[7][0] != 0) {
                        array_changed = 1;
                    }
                    coord[7][0] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[3][4] != 6) {
                        array_changed = 1;
                    }
                    coord[3][4] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[3][4] != 5) {
                        array_changed = 1;
                    }
                    coord[3][4] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[3][4] != 4) {
                        array_changed = 1;
                    }
                    coord[3][4] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[3][4] != 3) {
                        array_changed = 1;
                    }
                    coord[3][4] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[3][4] != 2) {
                        array_changed = 1;
                    }
                    coord[3][4] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[3][4] != 1) {
                        array_changed = 1;
                    }
                    coord[3][4] = 1;
                } else {
                    if (coord[3][4] != 0) {
                        array_changed = 1;
                    }
                    coord[3][4] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[7][4] != 6) {
                        array_changed = 1;
                    }
                    coord[7][4] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[7][4] != 5) {
                        array_changed = 1;
                    }
                    coord[7][4] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[7][4] != 4) {
                        array_changed = 1;
                    }
                    coord[7][4] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[7][4] != 3) {
                        array_changed = 1;
                    }
                    coord[7][4] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[7][4] != 2) {
                        array_changed = 1;
                    }
                    coord[7][4] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[7][4] != 1) {
                        array_changed = 1;
                    }
                    coord[7][4] = 1;
                } else {
                    if (coord[7][4] != 0) {
                        array_changed = 1;
                    }
                    coord[7][4] = 0;
                }
            }
            
        //------------------------------------------------------
           else if (sel1 == 1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[3][1] != 6) {
                        array_changed = 1;
                    }
                    coord[3][1] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[3][1] != 5) {
                        array_changed = 1;
                    }
                    coord[3][1] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[3][1] != 4) {
                        array_changed = 1;
                    }
                    coord[3][1] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[3][1] != 3) {
                        array_changed = 1;
                    }
                    coord[3][1] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[3][1] != 2) {
                        array_changed = 1;
                    }
                    coord[3][1] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[3][1] != 1) {
                        array_changed = 1;
                    }
                    coord[3][1] = 1;
                } else {
                    if (coord[3][1] != 0) {
                        array_changed = 1;
                    }
                    coord[3][1] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[7][1] != 6) {
                        array_changed = 1;
                    }
                    coord[7][1] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[7][1] != 5) {
                        array_changed = 1;
                    }
                    coord[7][1] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[7][1] != 4) {
                        array_changed = 1;
                    }
                    coord[7][1] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[7][1] != 3) {
                        array_changed = 1;
                    }
                    coord[7][1] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[7][1] != 2) {
                        array_changed = 1;
                    }
                    coord[7][1] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[7][1] != 1) {
                        array_changed = 1;
                    }
                    coord[7][1] = 1;
                } else {
                    if (coord[7][1] != 0) {
                        array_changed = 1;
                    }
                    coord[7][1] = 0;
                }
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[3][5] != 6) {
                        array_changed = 1;
                    }
                    coord[3][5] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[3][5] != 5) {
                        array_changed = 1;
                    }
                    coord[3][5] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[3][5] != 4) {
                        array_changed = 1;
                    }
                    coord[3][5] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[3][5] != 3) {
                        array_changed = 1;
                    }
                    coord[3][5] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[3][5] != 2) {
                        array_changed = 1;
                    }
                    coord[3][5] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[3][5] != 1) {
                        array_changed = 1;
                    }
                    coord[3][5] = 1;
                } else {
                    if (coord[3][5] != 0) {
                        array_changed = 1;
                    }
                    coord[3][5] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[7][5] != 6) {
                        array_changed = 1;
                    }
                    coord[7][5] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[7][5] != 5) {
                        array_changed = 1;
                    }
                    coord[7][5] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[7][5] != 4) {
                        array_changed = 1;
                    }
                    coord[7][5] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[7][5] != 3) {
                        array_changed = 1;
                    }
                    coord[7][5] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[7][5] != 2) {
                        array_changed = 1;
                    }
                    coord[7][5] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[7][5] != 1) {
                        array_changed = 1;
                    }
                    coord[7][5] = 1;
                } else {
                    if (coord[7][5] != 0) {
                        array_changed = 1;
                    }
                    coord[7][5] = 0;
                }
            }
        
            
            //------------------------------------------------------
           else if (sel2 == 1) {
               if (quad0 > .43 && quad0 < .45)  {
                    if (coord[3][2] != 6) {
                        array_changed = 1;
                    }
                    coord[3][2] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[3][2] != 5) {
                        array_changed = 1;
                    }
                    coord[3][2] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[3][2] != 4) {
                        array_changed = 1;
                    }
                    coord[3][2] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[3][2] != 3) {
                        array_changed = 1;
                    }
                    coord[3][2] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[3][2] != 2) {
                        array_changed = 1;
                    }
                    coord[3][2] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[3][2] != 1) {
                        array_changed = 1;
                    }
                    coord[3][2] = 1;
                } else {
                    if (coord[3][2] != 0) {
                        array_changed = 1;
                    }
                    coord[3][2] = 0;
                }
                //printf("%f\r\n", quad1.read());
                
                 if (quad1 > .43 && quad1 < .45)  {
                    if (coord[7][2] != 6) {
                        array_changed = 1;
                    }
                    coord[7][2] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[7][2] != 5) {
                        array_changed = 1;
                    }
                    coord[7][2] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[7][2] != 4) {
                        array_changed = 1;
                    }
                    coord[7][2] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[7][2] != 3) {
                        array_changed = 1;
                    }
                    coord[7][2] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[7][2] != 2) {
                        array_changed = 1;
                    }
                    coord[7][2] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[7][2] != 1) {
                        array_changed = 1;
                    }
                    coord[7][2] = 1;
                } else {
                    if (coord[7][2] != 0) {
                        array_changed = 1;
                    }
                    coord[7][2] = 0;
                }
                
                
                 if (quad2 > .43 && quad2 < .45)  {
                    if (coord[3][6] != 6) {
                        array_changed = 1;
                    }
                    coord[3][6] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[3][6] != 5) {
                        array_changed = 1;
                    }
                    coord[3][6] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[3][6] != 4) {
                        array_changed = 1;
                    }
                    coord[3][6] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[3][6] != 3) {
                        array_changed = 1;
                    }
                    coord[3][6] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[3][6] != 2) {
                        array_changed = 1;
                    }
                    coord[3][6] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[3][6] != 1) {
                        array_changed = 1;
                    }
                    coord[3][6] = 1;
                } else {
                    if (coord[3][6] != 0) {
                        array_changed = 1;
                    }
                    coord[3][6] = 0;
                }
                
                
                 if (quad3 > .43 && quad3 < .45)  {
                    if (coord[7][6] != 6) {
                        array_changed = 1;
                    }
                    coord[7][6] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[7][6] != 5) {
                        array_changed = 1;
                    }
                    coord[7][6] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[7][6] != 4) {
                        array_changed = 1;
                    }
                    coord[7][6] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[7][6] != 3) {
                        array_changed = 1;
                    }
                    coord[7][6] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[7][6] != 2) {
                        array_changed = 1;
                    }
                    coord[7][6] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[7][6] != 1) {
                        array_changed = 1;
                    }
                    coord[7][6] = 1;
                } else {
                    if (coord[7][6] != 0) {
                        array_changed = 1;
                    }
                    coord[7][6] = 0;
                }
            
        }
            
           //------------------------------------------------------
           else if (sel3 ==  1) {
                if (quad0 > .43 && quad0 < .45) {
                    if (coord[3][3] != 6) {
                        array_changed = 1;
                    }
                    coord[3][3] = 6;
                } else if (quad0 > .47 && quad0 < .49) {
                    if (coord[3][3] != 5) {
                        array_changed = 1;
                    }
                    coord[3][3] = 5;
                } else if (quad0 > .525 && quad0 < .545) {
                    if (coord[3][3] != 4) {
                        array_changed = 1;
                    }
                    coord[3][3] = 4;
                } else if (quad0 > .60 && quad0 < .63) {
                    if (coord[3][3] != 3) {
                        array_changed = 1;
                    }
                    coord[3][3] = 3;
                } else if (quad0 > .73 && quad0 < .75) {
                    if (coord[3][3] != 2) {
                        array_changed = 1;
                    }
                    coord[3][3] = 2;
                }  else if(quad0 > .955 && quad0 < .975) {
                    if (coord[3][3] != 1) {
                        array_changed = 1;
                    }
                    coord[3][3] = 1;
                } else {
                    if (coord[3][3] != 0) {
                        array_changed = 1;
                    }
                    coord[3][3] = 0;
                }
                
                
                if (quad1 > .43 && quad1 < .45) {
                    if (coord[7][3] != 6) {
                        array_changed = 1;
                    }
                    coord[7][3] = 6;
                } else if (quad1 > .47 && quad1 < .49) {
                    if (coord[7][3] != 5) {
                        array_changed = 1;
                    }
                    coord[7][3] = 5;
                } else if (quad1 > .525 && quad1 < .545) {
                    if (coord[7][3] != 4) {
                        array_changed = 1;
                    }
                    coord[7][3] = 4;
                } else if (quad1 > .60 && quad1 < .63) {
                    if (coord[7][3] != 3) {
                        array_changed = 1;
                    }
                    coord[7][3] = 3;
                } else if (quad1 > .73 && quad1 < .75) {
                    if (coord[7][3] != 2) {
                        array_changed = 1;
                    }
                    coord[7][3] = 2;
                }  else if(quad1 > .955 && quad1 < .975) {
                    if (coord[7][3] != 1) {
                        array_changed = 1;
                    }
                    coord[7][3] = 1;
                } else {
                    if (coord[7][3] != 0) {
                        array_changed = 1;
                    }
                    coord[7][3] = 0;
                }
                
                
                if (quad2 > .43 && quad2 < .45) {
                    if (coord[3][7] != 6) {
                        array_changed = 1;
                    }
                    coord[3][7] = 6;
                } else if (quad2 > .47 && quad2 < .49) {
                    if (coord[3][7] != 5) {
                        array_changed = 1;
                    }
                    coord[3][7] = 5;
                } else if (quad2 > .525 && quad2 < .545) {
                    if (coord[3][7] != 4) {
                        array_changed = 1;
                    }
                    coord[3][7] = 4;
                } else if (quad2 > .60 && quad2 < .63) {
                    if (coord[3][7] != 3) {
                        array_changed = 1;
                    }
                    coord[3][7] = 3;
                } else if (quad2 > .73 && quad2 < .75) {
                    if (coord[3][7] != 2) {
                        array_changed = 1;
                    }
                    coord[3][7] = 2;
                }  else if(quad2 > .955 && quad2 < .975) {
                    if (coord[3][7] != 1) {
                        array_changed = 1;
                    }
                    coord[3][7] = 1;
                } else {
                    if (coord[3][7] != 0) {
                        array_changed = 1;
                    }
                    coord[3][7] = 0;
                }
                
                
                if (quad3 > .43 && quad3 < .45) {
                    if (coord[7][7] != 6) {
                        array_changed = 1;
                    }
                    coord[7][7] = 6;
                } else if (quad3 > .47 && quad3 < .49) {
                    if (coord[7][7] != 5) {
                        array_changed = 1;
                    }
                    coord[7][7] = 5;
                } else if (quad3 > .525 && quad3 < .545) {
                    if (coord[7][7] != 4) {
                        array_changed = 1;
                    }
                    coord[7][7] = 4;
                } else if (quad3 > .60 && quad3 < .63) {
                    if (coord[7][7] != 3) {
                        array_changed = 1;
                    }
                    coord[7][7] = 3;
                } else if (quad3 > .73 && quad3 < .75) {
                    if (coord[7][7] != 2) {
                        array_changed = 1;
                    }
                    coord[7][7] = 2;
                }  else if(quad3 > .955 && quad3 < .975) {
                    if (coord[7][7] != 1) {
                        array_changed = 1;
                    }
                    coord[7][7] = 1;
                } else {
                    if (coord[7][7] != 0) {
                        array_changed = 1;
                    }
                    coord[7][7] = 0;
                }
            }
           
           
        }
        

}

int main() {
    pc.baud(9600);
    
    col0 = 0;
    col1 = 1;
    col2 = 1;
    col3 = 1;
    sel0 = 1;
    sel1 = 0;
    sel2 = 0;
    sel3 = 0;
    
    colCycle.attach(&cycleCol, .1);
    while(1) {
        //printf("quad0 = %f, sel = %d, col = %d\r\n", quad0.read(), next_row, next_col);
        //printf("sel0 = %d, sel1 = %d, sel2 = %d, sel3 = %d\r\n", sel0.read(), sel1.read(), sel2.read(), sel3.read());
        //printf("row0 = %f\r\n", row0.read());
        //printf("row1 = %f\r\n", row1.read());
       /* if (!col0) {
            printf("row3 = %f\r\n", row3.read());
        }*/
        //printf("%d %d %d %d\r\n", quad0, quad1, quad2, quad3);
        /*while (pi.readable()) {
            pc.putc(pi.getc());
        }*/
        //printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][2], coord[1][2], coord[2][2], coord[3][2], coord[4][2], coord[5][2], coord[6][2], coord[7][2]);


        if (array_changed == 1) {
            pc.putc('b'); // beginning signal
            for (int i = 0; i < 8; i++) {
                       for (int j = 0; j < 8; j++) {
                           pc.putc(coord[j][i] + 48);
                        }
                    }
            
            
            //pc.putc(coord[2][3] + 48);
            //pc.putc(coord[3][3] + 48);
            
           
            
              printf("quad1 = %f, sel = %d, col = %d\r\n", quad1.read(), next_row, next_col);
               ///printf("quad0 = %f\r\n, sel0", quad0.read());
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][0], coord[1][0], coord[2][0], coord[3][0], coord[4][0], coord[5][0], coord[6][0], coord[7][0]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][1], coord[1][1], coord[2][1], coord[3][1], coord[4][1], coord[5][1], coord[6][1], coord[7][1]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][0], coord[1][0], coord[2][2], coord[3][2], coord[4][2], coord[5][2], coord[6][2], coord[7][2]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][3], coord[1][3], coord[2][3], coord[3][3], coord[4][3], coord[5][3], coord[6][3], coord[7][3]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][4], coord[1][4], coord[2][4], coord[3][4], coord[4][4], coord[5][4], coord[6][4], coord[7][4]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][5], coord[1][5], coord[2][5], coord[3][5], coord[4][5], coord[5][5], coord[6][5], coord[7][5]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][6], coord[1][6], coord[2][6], coord[3][6], coord[4][6], coord[5][6], coord[6][6], coord[7][6]);
                printf("[ %d %d %d %d %d %d %d %d ]\r\n", coord[0][7], coord[1][7], coord[2][7], coord[3][7], coord[4][7], coord[5][7], coord[6][7], coord[7][7]);
                
                array_changed = 0;
        }     
        //printf("row3 = %d %d %d %d\r\n", coord[0][3], coord[1][3], coord[2][3], coord[3][3] ); 
    }
}
