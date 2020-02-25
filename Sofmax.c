/*Created by Dusan Radivojevic 25.02.2020
This C code implement the Sofmax function on user array.
Softmax is a common function for output layer in Neural Networks.
It's gives the probability of possible solutions.*/

#include <stdio.h>
#include <stdlib.h>
float Niz[];
int i,j,Iter;

/*exp(90) throw error for Float size of 4 Bytes, so it must be cuted if the value is larger.*/
float expo(float y){
	if(y>80) y=80;
	return exp(y);
}
/*This is Softmax function written in C*/
float Softmax(float x){
    float Sum=0;
    for(i=0;i<Iter;i++) Sum+=expo(Niz[i]);
    return (expo(x))/Sum;
}

int main(int argc, char *argv[]) {
	/*Check if float holds 4 Bytes*/
	printf("Your float have %dB\n\n",sizeof(float));
	/*Costum array entery*/
	printf("Enter number of array elements:\n");
	scanf("%d",&Iter);
	printf("\nEnter %d float numbers:\n",Iter);
	for(i=0;i<Iter;i++) scanf("%f",&Niz[i]);
	/*Print results*/
	printf("\n\nSoftmax function of each entered values is:\nEntered:\tSoftmax:\tPercent:");
	for(j=0;j<Iter;j++){
		printf("\n%10.5f\t%10.5f\t%10.2f%%",Niz[j],Softmax(Niz[j]),Softmax(Niz[j])*100);
	}
	/*Check. Summary must be ==1*/
	float sumary=0;
	for(j=0;j<Iter;j++) sumary+=Softmax(Niz[j]);
	printf("\n\nSummary of all elements in Sofmax array is %f",sumary);

	return 0;
}
