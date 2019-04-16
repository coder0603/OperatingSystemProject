#include<stdio.h>
#include<conio.h>
int main()
{
	int table_page,size_page, x, y, z, addr,ft,ad,i;
	float page_dist;
	char M[10],K[10];

	printf("\nEnter the size of page table and exponential power in(MB/KB/GB/TB): ");
	scanf("%d %s",&table_page,&M );
	if(M =="mB" || M =="MB" || M =="Mb" || M =="mb")
	x=20;
	else if(M=="kB" || M=="KB" || M=="Kb" || M=="kb")
	x=10;
	else if(M=="gB" || M=="GB" || M=="Gb" || M=="gb")
	x=30;
	else if(M=="tB" || M=="TB" || M=="Tb" || M=="tb")
	x=40;
	
	printf("\nEnter the page size and exponential power in(MB/KB/GB/TB): ");
	scanf("%d %s",&size_page,&K);
	if(K=="mB" || K=="MB" || K=="Mb" || K=="mb")
	y=20;
	else if(K=="kB" || K=="KB" || K=="Kb" || K=="kb")
	y=10;
	else if(K=="gB" || K=="GB" || K=="Gb" || K=="gb")
	y=30;
	else if(K=="tB" || K=="TB" || K=="Tb" || K=="tb")
	y=40;
	
	page_dist = table_page/size_page;
	int page[z];
	z=x-y;
	printf("\nNumber of pages: %d *2^(%d)",page_dist,z);
	printf("\n\nFirst address of page: %d",page);
	printf("\nLast address of page: %d",page[z-1]);
	printf("\n\nEnter number of frame Address for page table : ");
	scanf("%d %d",&ft,&ad);
	
	for(int i=ft; i<=ad ; i++)
	printf("\nAddress Of Page %d : %d",i,page[i]);
	
	return 0;
}

