/*
 * sort.c
 *
 *  Created on: Jul 31, 2025
 *      Author: administrator
 */


int sort(int *fa,int fn)
{
	for(int i=0;i<fn-1;i++)
	{
		for(int j=0;j<fn-1-i;j++)
		{
			if(fa[j]>fa[j+1])
			{
				int temp=fa[j];
				fa[j]=fa[j+1];
				fa[j+1]=temp;
			}
		}
	}
	return 0;
}
