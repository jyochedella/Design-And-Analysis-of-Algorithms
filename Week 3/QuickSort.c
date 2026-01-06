//CH.SC.U4CSE24107
#include <stdio.h>


void swap (int *a,int *b){
int temp = *b;
*b = *a;
*a = temp;
}


int partition (int arr[],int low,int high){
int i = low - 1;
int j = low;
int pivot = arr[high];

while (j < high){
if(arr[j] < pivot){
i++;
swap(&arr[i],&arr[j]);

}
j++;
}

swap(&arr[i+1],&arr[high]);
return i + 1;
}
void quicksort(int arr[],int low,int high){
if (low < high){

int p = partition (arr,low,high);
quicksort(arr,low,p-1);
quicksort(arr,p+1,high);
}
}

int main() {
int arr[] = {157,110,147,122,111,149,151,141,123,112,117,133};
int length = sizeof (arr) / sizeof (arr[0]);

quicksort(arr,0,length-1);

for(int i=0;i<length;i++){
printf("%d ",arr[i]);
}
return 0;
}