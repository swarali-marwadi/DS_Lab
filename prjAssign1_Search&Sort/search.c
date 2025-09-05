/*
 * search.c
 *
 *  Created on: Jul 31, 2025
 *      Author: administrator
 */

int linearSearch(int *fa,int fn,int fkey)
{
	int flag=1;
	for(int i=0;i<fn;i++)
	{
		if(fkey==fa[i])
		{
			flag=0;
		}
	}
	return flag;
}

int binarySearch(int *fa, int fn, int fkey)
{

	int low=0;
	int high=fn-1;
	int mid=0;
	int ans=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(fkey==fa[mid])
		{
			ans=1;
			low=high+1;
		}
		else if(fkey<fa[mid])
		{
			high = mid-1 ;
		}
		else
		{
			low = mid+1 ;
		}
	}
	return ans;
}
