#ifndef bit_calculation_h

#define bit_calculation_h

#define SET_BIT(reg,bitno)    reg |=  (1 << (bitno))

#define CLR_BIT(reg,bitno)    reg &= ~(1 << (bitno))

#define GET_BIT(reg,bitno)    ((reg>>bitno)&1)

#define R_SHIFT(reg,no)         reg=(reg>>no)

#define L_SHIFT(reg,no)         reg=(reg<<no)

#define ASSIGN_REG(reg,value)         reg=value

#define SET_REG (reg)                      reg=~(0)

#define CLR_REG (reg)                      reg=(0)

#define TGL_BIT(reg,bitno)                reg^=(1<<bitno)

#define TGL_REG(reg)                reg^=~(0)














#endif
