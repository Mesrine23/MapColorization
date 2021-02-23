#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "prob.h"

struct data { //struct
	char color[10];
	char cntry[33];
	char **nb;
	int snb;
};

/*
void quick(struct data *c,int up,int down){ //quicksort
  int start,end;
  start = up;
  end=down;
  struct data temp;
  while(up<down){
    while(c[down].snb >= c[up].snb && up<down){
      down--;
    }
    if(up!=down){
      temp=c[down];
      c[down]=c[up];
      c[up]=temp;
      up++;
    }
    while(c[up].snb <= c[down].snb && up<down){
      up++;
    }
    if(up!=down){
      temp=c[down];
      c[down]=c[up];
      c[up]=temp;
      down--;
    }
  }
  if(start<up-1){
    quick(c,start,up-1);
  }
  if(end>down+1){
    quick(c,down+1,end);
  }
}
*/ // quick


int main(int argc,char *argv[])
{
	int i,k,dtnumb=-1,nbnumb,f,flag[3],fcolor,j,fcolorfin,cur,n,fsemi=0;
	n=4;
	char *colorstr[] = {"nocolor","red", "green", "blue", "yellow", "orange","violet", "cyan", "pink", "brown", "grey"};
	char txt[20];
	for(i=0;i<3;i++){
		flag[i]=0;
	}
	for(i=1;i<argc;i++){ //elegxos gia -i -c -n
		if(strcmp(argv[i],"-i")==0){
			flag[0]=1;
			strcpy(txt,argv[i+1]);
		}
		if(strcmp(argv[i],"-c")==0){
			flag[1]=1;
		}
		if(strcmp(argv[i],"-n")==0){
			flag[2]=1;
			n=atoi(argv[i+1]);
		}
	}
	char str[33];
	struct data *info = malloc(sizeof(struct data));

	if(flag[0]==0) //an den dwsw -i
	{
		while(1) //diabazv pinaka me scanf
		{

			if(fscanf(stdin, "%s",str)==EOF){
				break;
			}
			fcolor=0;
			if(strcmp(str,"nocolor")==0){
				fcolor=1;
			}
			for(i=1;i<11;i++){
				if(strcmp(str,colorstr[i])==0){
					fsemi=fsemi+1;
					fcolor=1;
					break;
				}
			}
			if (fcolor==1)		// COLOR
			{
				nbnumb=0;
				dtnumb++;
				if(dtnumb>=1){
					info=realloc(info,(dtnumb+1)*sizeof(struct data));
				}
				info[dtnumb].snb=0;
				strcpy(info[dtnumb].color, str);
				f=1;
			}
			else if (f==1)		// COUNTRY
			{
				strcpy(info[dtnumb].cntry, str);
				f=0;
			}
			else
			{
				if (info[dtnumb].snb==0)
				{
					info[dtnumb].nb = malloc(sizeof(char*));
					info[dtnumb].nb[info[dtnumb].snb] = malloc(33);
					strcpy(info[dtnumb].nb[info[dtnumb].snb], str);
					(info[dtnumb].snb)+=1;
					nbnumb++;

				}
				else
				{
					info[dtnumb].nb = realloc(info[dtnumb].nb,(nbnumb+1)*sizeof(char*));
					info[dtnumb].nb[info[dtnumb].snb] = malloc(33);
					strcpy(info[dtnumb].nb[info[dtnumb].snb], str);
					(info[dtnumb].snb)+=1;
					nbnumb++;
				}
			}
		}
	}
	else if(flag[0]==1) //an dwsw -i
	{
		FILE *fil;
		fil=fopen(txt,"r");
		while(1) //diabazv pinaka me fopen
		{
			if(fscanf(fil, "%s",str)==EOF)
			{
				break;
			}
			fcolor=0;
			if(strcmp(str,"nocolor")==0)
			{
				fcolor=1;
			}
			for(i=1;i<11;i++){
				if(strcmp(str,colorstr[i])==0)
				{
					fsemi=fsemi+1;
					fcolor=1;
					break;
				}
			}

			if (fcolor==1)
			{
				nbnumb=0;
				dtnumb++;
				if(dtnumb>=1){
					info=realloc(info,(dtnumb+1)*sizeof(struct data));
				}
				info[dtnumb].snb=0;
				strcpy(info[dtnumb].color, str);
				f=1;
			}
			else if (f==1)		// COUNTRY
			{
				strcpy(info[dtnumb].cntry, str);
				f=0;
			}
			else
			{
				if (info[dtnumb].snb==0)
				{
					info[dtnumb].nb = malloc(sizeof(char*));
					info[dtnumb].nb[info[dtnumb].snb] = malloc(33);
					strcpy(info[dtnumb].nb[info[dtnumb].snb], str);
					(info[dtnumb].snb)+=1;
					nbnumb++;

				}
				else
				{
					info[dtnumb].nb = realloc(info[dtnumb].nb,(nbnumb+1)*sizeof(char*));
					info[dtnumb].nb[info[dtnumb].snb] = malloc(33);
					strcpy(info[dtnumb].nb[info[dtnumb].snb], str);
					(info[dtnumb].snb)+=1;
					nbnumb++;
				}
			}
		}

	}

	quick(info,0,dtnumb);
	printf("\n" );




	int *col_d,tempf,max;
	col_d=calloc(dtnumb+1,sizeof(int));

	cur=dtnumb+1;
	int fsc,fcont;
	if(flag[1]==0 && fsemi==0){ //an den dwsw -c, an kanw xrvmatismo
		while(1)
		{
			cur--;
			if(cur<0)
			{
				break;
			}

			for(j=col_d[cur]+1;j<=n;j++)
			{
				fcont=0;
				fcolor=0;
				for(i=0;i<info[cur].snb;i++)
				{
					for(k=dtnumb;k>cur;k--)
					{
						if(strcmp(info[cur].nb[i],info[k].cntry)==0)
						{
							if(col_d[k]==j){
								fcolor=1;
								break;
							}
							else
							{
								fcont=1;
								break;
							}
						}
					}
					if(fcolor==1){
						break;
					}
					if(fcont==1){
						continue;
					}
				}
				if(fcolor==0){
					col_d[cur]=j;
					break;
				}
			}
			if(j>n)
			{
				col_d[cur]=0;
				cur+=2;
				if(cur-1>dtnumb){
					break;
				}
			}
		}
		if(col_d[0]!=0)
		{
			printf("\n" );
			for(i=0;i<=dtnumb;i++)
			{
				printf("%s ",colorstr[col_d[i]]);
				fprintf(stdout,"%s ",info[i].cntry);
				for(k=0;k<info[i].snb;k++)
				{
					fprintf(stdout,"%s ",info[i].nb[k]);
				}
				fprintf(stdout,"\n");
			}
		}
		else
		{
			printf("Sorry, cannot color the given map\n" );
		}
	}
	else if(flag[1]==0 && fsemi>0){
		int *pos,back;
		fcolor=0;
		pos=malloc((dtnumb+1)*sizeof(int));
		k=0;
		for(i=0;i<=dtnumb;i++)
		{
			if(strcmp(info[i].color,"nocolor")!=0)
			{
				pos[i]=1;
			}
			else
			{
				pos[i]=0;
			}
		}
		k=0;
		for(i=0 ; i<=dtnumb ; ++i)
		{
			if(pos[i]==1)
			{
				for(j=1 ; j<=11 ; ++j)
				{
					if(strcmp(colorstr[j],info[i].color)==0)
					{
						col_d[i] = j;
					}
				}
			}
		}
		for(i=0;i<=dtnumb;i++)
		{
			if(pos[i]==1)
			{
				for(k=0;k<info[i].snb;k++)
				{
					for(j=0;j<=dtnumb;j++)
					{
						if(strcmp(info[i].nb[k],info[j].cntry)==0)
						{
							break;
						}
					}
					if(j>dtnumb)
					{
						continue;
					}
					if(pos[j]==1)
					{
						if(strcmp(info[i].color,info[j].color)==0)
						{
							fprintf(stdout,"Cannot color the given map because %s - %s: Should have different color\n",info[i].nb[k],info[i].cntry );
							fcolor=1;
						}
					}
					if(fcolor==1){
						break;
					}
				}
				if(fcolor==1){
					break;
				}
			}
		}
		back=0;
		while(fcolor!=1)
		{
			cur--;
			if(cur<0)
			{
				break;
			}
			if(pos[cur]==1 && back==1)
			{
				cur++;
				if(cur<=dtnumb)
				{
					if(pos[cur]==0)
					{
						back=0;
					}

				}
			}
			else if(pos[cur]==1 && back==0)
			{
				continue;
			}

			else if(pos[cur]==0)
			{

				for(j=col_d[cur]+1;j<=n;j++)
				{
					fcont=0;
					fcolor=0;
					for(i=0;i<info[cur].snb;i++)
					{
						for(k=dtnumb;k>=0;k--)
						{
							if(strcmp(info[cur].nb[i],info[k].cntry)==0)
							{
								if(col_d[k]==j){
									fcolor=1;
									break;
								}
								else
								{
									fcont=1;
									break;
								}
							}
						}
						if(fcolor==1){
							break;
						}
						if(fcont==1){
							continue;
						}
					}
					if(fcolor==0){
						col_d[cur]=j;
						break;
					}
				}
				if(j>n)
				{
					back=1;
					col_d[cur]=0;
					cur+=2;
					if(cur-1>dtnumb){
						break;
					}
				}
			}
		}
		if(col_d[0]!=0 && fcolor==0)
		{
			printf("\n" );
			for(i=0;i<=dtnumb;i++)
			{
				printf("%s ",colorstr[col_d[i]]);
				fprintf(stdout,"%s ",info[i].cntry);
				for(k=0;k<info[i].snb;k++)
				{
					fprintf(stdout,"%s ",info[i].nb[k]);
				}
				fprintf(stdout,"\n");
			}
		}
		else if(col_d[0]==0)
		{
			printf("Sorry, cannot color the given map\n" );
		}
	}



	int fnc=0;
	fcolorfin=0;
	if(flag[1]==1){
		prob(dtnumb,fsemi,&fnc);
		/* if((dtnumb+1)>fsemi)
		{
			fnc=1;
			printf("Please color the map first\n");
		}*/
	}
	if(flag[1]==1 && fnc==0) //gia -c
	{
		fcolor=0;
		for(i=0;i<=dtnumb;i++)
		{
			for(k=n+1;k<11;k++)	//gia -n
			{
				if(strcmp(info[i].color,"nocolor")==0)
				{
					fnc=1;
					break;
				}
				if(strcmp(info[i].color,colorstr[k])==0)
				{
					fcolor=1;
					break;
				}
			}
			if (fcolor==1)
			{
				fcolorfin=1;
			}
			for(k=0;k<info[i].snb;k++)
			{
				for(j=0;j<=dtnumb;j++)
				{
					if(strcmp(info[i].nb[k],info[j].cntry)==0)
					{
						break;
					}
				}
				if(j>dtnumb)
				{
					continue;
				}
				if(strcmp(info[i].color,info[j].color)==0)
				{
					fprintf(stdout,"%s - %s: Should have different color\n",info[i].nb[k],info[i].cntry );
				}
			}
		}
		if(fcolorfin==1){
			fprintf(stdout,"More than %d colors used\n", n );
		}
	}
}
