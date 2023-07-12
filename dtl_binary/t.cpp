#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
#include<memory.h>
 
struct Node
{
	int state;
	int step;
};
 
bool visit[65536];
 
int change[16] =   //16?????,??4*4?????
{
	 51200,58368,29184,12544,
     35968,20032,10016,4880,
	 2248,1252,626,305,
	 140,78,39,19
};
 
int bfs(int state)
{
	int i;
	memset(visit,false,sizeof(visit));    //????????????
	queue<Node>q;
	Node cur,next;
	cur.state = state;
	cur.step = 0;
	q.push(cur);
	visit[state] = true;
 
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur.state == 0 || cur.state == 0xffff)   //65535
			return cur.step;
		for(i=0;i<16;i++)
		{
			next.state = cur.state^change[i];
			next.step = cur.step + 1;
			if(visit[next.state])
				continue;
			if(next.state == 0 || next.state == 0xffff)   //65535
				return next.step;
			visit[next.state] = true;
			q.push(next);
		}
	}
	return -1;
}
 
int main(void)
{
	int i,j,state,ans;
	char ch[5][5];
	while(scanf("%s",ch[0])!=EOF)
	{
		for(i = 1 ; i < 4 ; ++i)
			scanf("%s",ch[i]);
		state = 0;
		//???????
		for(i = 0 ; i < 4 ; ++i)
		{
			for(j = 0 ; j < 4 ; ++j)
			{
				state <<= 1;
				if(ch[i][j] == 'b')
					state += 1;
				//state ^= (1<<((3-i)*4+(3-j)));
			}
		}
		ans = bfs(state);
		if(ans == -1)
			puts("Impossible");
		else
			printf("%d\n",ans);
	}
	return 0;
}