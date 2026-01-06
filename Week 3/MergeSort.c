//CH.SC.U4CSE24107
#include <stdio.h>

void merge(int arr[],int left,int mid,int right){
int i,j,k;
int n1 = mid - left + 1;
int n2 = right - mid;

int l1[n1],l2[n2];

for(j = 0; j < n1;j++){
l1[j] = arr[left + j];
}
for(j = 0;j < n2;j++){
l2[j] = arr[mid + 1 + j];
}
i = 0;
j = 0;
k = left;
while ( i < n1 && j < n2 ){
if (l1[i] < l2 [j]){
arr[k++] = l1[i++];
}
else {
arr[k++] = l2[j++];
}
}

while(i < n1){
arr[k++] = l1[i++];
}

while(j < n2){
arr[k++] = l2[j++];
}
}

void mergeSort(int arr[],int left,int right){
if(left < right){
int mid = left + (right - left)/2;
mergeSort(arr,left,mid);
mergeSort(arr,mid+1,right);
merge(arr,left,mid,right);

}
}

int main () {

int arr[] = {157,110,147,122,111,149,151,141,123,112,117,133};
int length = sizeof (arr) / sizeof (arr[0]);
mergeSort(arr,0,length-1);
for(int i=0;i<length;i++){
printf("%d ",arr[i]);
}
return 0;
}