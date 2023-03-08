//
// Created by Arnav on 3/2/2023.
//
#include <math.h>
#include <stdio.h>


float DistanceToCatch(float *XShrekCaught,float *YShrekCaught,float XShrek, float YShrek, char DirectionShrek, int AShrek,int BShrek, int CShrek,float XDonkey, float YDonkey, char DirectionDonkey, int ADonkey,int BDonkey,int CDonkey);

float small(float A, float B);



void main(int argc,char **argv)
{
    char NameDonkey[10];
    char CodeDonkey[10];
    int ADonkey = 0;
    int BDonkey = 0;
    int CDonkey = 0;
    float XDonkey = 0.0;
    float YDonkey = 0.0;
    char DirectionDonkey = 0;

    char NameShrek[10];
    char CodeShrek1[10];
    int AShrek1 = 0;
    int BShrek1 = 0;
    int CShrek1 = 0;
    float XShrek1 = 0;
    float YShrek1 = 0;
    char DirectionShrek1 = 0;

    char CodeShrek2[10];
    int AShrek2 = 0;
    int BShrek2 = 0;
    int CShrek2 = 0;
    float XShrek2 = 0;
    float YShrek2 = 0;
    char DirectionShrek2 = 0;

    char CodeShrek3[10];
    int AShrek3 = 0;
    int BShrek3 = 0;
    int CShrek3 = 0;
    float XShrek3 = 0;
    float YShrek3 = 0;
    char DirectionShrek3 = 0;

    float DistanceIntersectionShrek1 = -1.0;
    float DistanceIntersectionShrek2 = -1.0;
    float DistanceIntersectionShrek3 = -1.0;
    float XShrek1Caught = 0.0;
    float YShrek1Caught = 0.0;
    float XShrek2Caught = 0.0;
    float YShrek2Caught = 0.0;
    float XShrek3Caught = 0.0;
    float YShrek3Caught = 0.0;
    float smallValue = -1.0;


    scanf("%s",NameDonkey);
    scanf("%s %d %d %d",CodeDonkey,&ADonkey,&BDonkey,&CDonkey);
    scanf("%f %f %c",&XDonkey,&YDonkey,&DirectionDonkey);
    scanf("%s",NameShrek);
    scanf("%s %i %i %i",CodeShrek1,&AShrek1,&BShrek1,&CShrek1);
    scanf("%f %f %c",&XShrek1,&YShrek1,&DirectionShrek1);
    scanf("%s %i %i %i",CodeShrek2,&AShrek2,&BShrek2,&CShrek2);
    scanf("%f %f %c",&XShrek2,&YShrek2,&DirectionShrek2);
    scanf("%s %i %i %i",CodeShrek3,&AShrek3,&BShrek3,&CShrek3);
    scanf("%f %f %c",&XShrek3,&YShrek3,&DirectionShrek3);


    DistanceIntersectionShrek1 = DistanceToCatch(&XShrek1Caught,&YShrek1Caught, XShrek1,  YShrek1, DirectionShrek1, AShrek1, BShrek1,  CShrek1, XDonkey,YDonkey,DirectionDonkey, ADonkey, BDonkey, CDonkey);
    DistanceIntersectionShrek2 = DistanceToCatch(&XShrek2Caught,&YShrek2Caught, XShrek2,  YShrek2, DirectionShrek2, AShrek2, BShrek2,  CShrek2, XDonkey,YDonkey,DirectionDonkey, ADonkey, BDonkey, CDonkey);
    DistanceIntersectionShrek3 = DistanceToCatch(&XShrek3Caught,&YShrek3Caught, XShrek3,  YShrek3, DirectionShrek3, AShrek3, BShrek3,  CShrek3, XDonkey,YDonkey,DirectionDonkey, ADonkey, BDonkey, CDonkey);

    if(DistanceIntersectionShrek1 >= 0)printf("%s (%.3f,%.3f)\n",CodeShrek1,XShrek1Caught,YShrek1Caught);
    else printf("%s MISS!\n",CodeShrek1);
    if(DistanceIntersectionShrek2 >= 0)printf("%s (%.3f,%.3f)\n",CodeShrek2,XShrek2Caught,YShrek2Caught);
    else printf("%s MISS!\n",CodeShrek2);
    if(DistanceIntersectionShrek3 >= 0)printf("%s (%.3f,%.3f)\n",CodeShrek3,XShrek3Caught,YShrek3Caught);
    else printf("%s MISS!\n",CodeShrek3);


    smallValue = small(small(DistanceIntersectionShrek1,DistanceIntersectionShrek2),DistanceIntersectionShrek3);
    if(smallValue != -1.0){
        if(DistanceIntersectionShrek1 == smallValue){
            printf("%s CATCHES %.3f METERS AWAY\n",CodeShrek1,DistanceIntersectionShrek1);
        }
        else if(DistanceIntersectionShrek2 == smallValue){
            printf("%s CATCHES %.3f METERS AWAY\n",CodeShrek2,DistanceIntersectionShrek2);
        }
        else if(DistanceIntersectionShrek3 == smallValue){
            printf("%s CATCHES %.3f METERS AWAY\n",CodeShrek3,DistanceIntersectionShrek3);
        }
    }
    else{
        printf("DONKEY GETS AWAY!\n");
    }
}
float DistanceToCatch(float *XShrekCaught,float *YShrekCaught,float XShrek, float YShrek, char DirectionShrek, int AShrek,int BShrek, int CShrek,float XDonkey, float YDonkey, char DirectionDonkey, int ADonkey,int BDonkey,int CDonkey)
{
    int A,B,C;
    int ResultCount = 0;
    float X1,X2,Y1,Y2,D1 = -1.0,D2 = -1.0;
    float fDistance = -1.0;
    char isTwoSolution = 1;

    A = ADonkey - AShrek;
    B = BDonkey - BShrek;
    C = CDonkey - CShrek;

    if(A != 0 && (B*B - 4*A*C) >=0){
        X1 = (-B + sqrt((B * B) - (4*A*C)))/(2*A);
        Y1 = X1 * X1 * ADonkey + X1 * BDonkey + CDonkey;
        X2 = (-B - sqrt((B * B) - (4*A*C)))/(2*A);
        Y2 = X2 * X2 * ADonkey + X2 * BDonkey + CDonkey;
    }
    else if(A == 0 && B != 0.0){
        isTwoSolution = 0;
        X1 = -1.0 * (C / B);;
        Y1 = X1 * X1 * ADonkey + X1 * BDonkey + CDonkey;
    }
    else{
        return fDistance;
    }

    if (DirectionDonkey == '+' && DirectionShrek == '+'){
        if(X1 >= XDonkey && X1 >= XShrek  ){
            D1 = sqrt((XShrek - X1) * (XShrek - X1) + (YShrek - Y1) * (YShrek - Y1));
            ResultCount++;
        }
        if(isTwoSolution && (X2 >= XDonkey && X2 >= XShrek)){
            D2 = sqrt((XShrek - X2) * (XShrek - X2) + (YShrek - Y2) * (YShrek - Y2));
            ResultCount++;
        }
    }
    else if (DirectionDonkey == '+' && DirectionShrek == '-'){
        if(X1 >= XDonkey && X1 <= XShrek  ){
            D1 = sqrt((XShrek - X1) * (XShrek - X1) + (YShrek - Y1) * (YShrek - Y1));
            ResultCount++;
        }
        if(isTwoSolution && (X2 >= XDonkey && X2 <= XShrek)){
            D2 = sqrt((XShrek - X2) * (XShrek - X2) + (YShrek - Y2) * (YShrek - Y2));
            ResultCount++;
        }
    }
    else if (DirectionDonkey == '-' && DirectionShrek == '+'){
        if(X1 <= XDonkey && X1 >= XShrek  ){
            D1 = sqrt((XShrek - X1) * (XShrek - X1) + (YShrek - Y1) * (YShrek - Y1));
            ResultCount++;
        }
        if(isTwoSolution && (X2 <= XDonkey && X2 >= XShrek)){
            D2 = sqrt((XShrek - X2) * (XShrek - X2) + (YShrek - Y2) * (YShrek - Y2));
            ResultCount++;
        }
    }
    else if (DirectionDonkey == '-' && DirectionShrek == '-'){
        if(X1 <= XDonkey && X1 <= XShrek  ){
            D1 = sqrt((XShrek - X1) * (XShrek - X1) + (YShrek - Y1) * (YShrek - Y1));
            ResultCount++;
        }
        if(isTwoSolution && (X2 <= XDonkey && X2 <= XShrek)){
            D2 = sqrt((XShrek - X2) * (XShrek - X2) + (YShrek - Y2) * (YShrek - Y2));
            ResultCount++;
        }
    }


    if(ResultCount == 1){
        fDistance = (D1 > D2) ? D1 : D2;
    }
    else if(ResultCount == 2){
        fDistance =  (D1 > D2) ? D2 : D1;
    }

    if(ResultCount == 1){
        if(D1 > D2){
            *XShrekCaught = X1;
            *YShrekCaught = Y1;
        }
        else{
            *XShrekCaught = X2;
            *YShrekCaught = Y2;
        }
    }
    else if(ResultCount == 2){
        if(D1 > D2){
            *XShrekCaught = X2;
            *YShrekCaught = Y2;
        }
        else{
            *XShrekCaught = X1;
            *YShrekCaught = Y1;
        }
    }
    return fDistance;
}

float small(float A, float B)
{
    float ret=0.0;

    if((A < B) && (A != -1.0))ret =  A;
    else ret  = (B != -1.0) ? B : A;

    return ret;
}



