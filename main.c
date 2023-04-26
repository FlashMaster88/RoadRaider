#include <msp430.h>
void main(void)
{

WDTCTL = WDTPW + WDTHOLD;
BCSCTL1= CALBC1_1MHZ; //frequence d’horloge 1MHz
DCOCTL= CALDCO_1MHZ; // "

P2DIR |= BIT5; // P2.5 en sortie
P2SEL |= BIT5; // selection fonction TA1.2
P2SEL2 |= BIT5; // selection fonction TA1.2

P2DIR |= BIT1; // P2.5 en sortie
P2SEL |= BIT1; // selection fonction TA1.2
P2SEL2 &= ~BIT1; // selection fonction TA1.2

P2DIR |= BIT2; // P2.5 en sortie
P2SEL |= BIT2; // selection fonction TA1.2
P2SEL2 &= ~BIT2; // selection fonction TA1.2

P2DIR |= BIT4; // P2.5 en sortie
P2SEL |= BIT4; // selection fonction TA1.2
P2SEL2 &= ~BIT4; // selection fonction TA1.2

TA1CTL = 0 | TASSEL_2 | ID_0 | MC_1; // source SMCLK pour TimerA , mode comptage Up
TA1CCR0 = 4;

TA1CCTL1 |= OUTMOD_7; // activation mode de sortie n°7 sur TA0.2
//TA1CCR1 = 7; // determine le rapport cyclique du signal TA0.2

TA1CCTL2 |= OUTMOD_7; // activation mode de sortie n°7 sur TA0.2
//TA1CCR2 = 7; // determine le rapport cyclique du signal TA0.2

TA1CCR1 = 0;
TA1CCR2 = 0;

int i;
for(i=0; i<=TA1CCR0; i++)
{
    TA1CCR1 += 1;TA1CCR2 += 1;
    __delay_cycles(500000);
    //__delay_cycles(500000);
}
/*
TA1CCR1 = 9;
TA1CCR2 = 9;
*/

for(i=0; i<=TA1CCR0; i++)
{
    TA1CCR1 -= 1;TA1CCR2 -= 1;
    __delay_cycles(500000);
    //__delay_cycles(500000);
}
P2SEL2 |= BIT1;
P2SEL2 &= ~BIT5;

for(i=0; i<=TA1CCR0; i++)
{
    TA1CCR1 += 1;TA1CCR2 += 1;
    __delay_cycles(500000);
    //__delay_cycles(500000);
}
/*
TA1CCR1 = 9;
TA1CCR2 = 9;
*/
for(i=0; i<=TA1CCR0; i++)
{
    TA1CCR1 -= 1;TA1CCR2 -= 1;
    __delay_cycles(500000);
    //__delay_cycles(500000);
}



for(i=0; i<=TA1CCR0; i++)
       {
               TA1CCR1 = 7;
               __delay_cycles(500000);
               TA1CCR1 = 0;
               TA1CCR2 = 7;
               __delay_cycles(500000);
               TA1CCR2 = 0;
       }

}





