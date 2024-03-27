#include<stdio.h>
int binary_search(int a[], int n, int item, int lb, int ub);
int main()
{
	int a[50],i,lb=0,ub,item,n,pos;
	printf("Enter the size of the array: ");
    scanf("%d", &n);
    ub=n;
    printf("Enter elements into array as per size: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter item to search: ");
    scanf("%d", &item);
    pos = binary_search(a, n, item,lb,ub);
    if(pos==-1)
    printf("Item not present");
    else
    printf("Present at %d ",pos);
    return 0;
}
int binary_search(int a[], int n, int item, int lb, int ub)
{
		int i,pos=-1,mid;
	
    	while (lb <= ub) 
		{
        	mid = lb + (ub - lb) / 2;
        	if (a[mid] == item)
            	return mid;
        	else if (a[mid] < item)
            	lb = mid + 1;
        	else
            	ub = mid - 1;
    	}
   		return -1; 
}
		
		
		
