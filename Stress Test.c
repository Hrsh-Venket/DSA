#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// stress test for loops

int main() 
{
// below is the last instance in my stress test that output is as programmer may have intended
// output: 0.000010 0.000020 0.000030 
for (float i = 0.00001; i <= 0.00003; i+= 0.00001)
{
    printf("%f ", i);
}
printf("\n");

// below is the first instance in my stress test that output is only 2 integers 
// output: 0.000001 0.000002
for (float i = 0.000001; i <= 0.000003; i+= 0.000001)
{
    printf("%f ", i);
}
printf("\n");

// below is the first point where the output is all zeros
// output: 0.000000 0.000000      
for (float i = 0.0000001; i <= 0.0000003; i+= 0.0000001)
{
    printf("%f ", i);
}
printf("\n");
}
