void delay (unsigned int millis)
{
    millis = millis * 12000000 / 1000;
    while(millis--);
}
