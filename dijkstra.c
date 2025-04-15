#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
void dijkstra(int n,int cost[10][10],int src)
{
int i,j,u,dis[10],vis[10],min;
for(i=1;i&lt;=n;i++)
{
dis[i]=cost[src][i];
vis[i]=0;
}
vis[src]=1;
for(i=1;i&lt;=n;i++)
{
min=999;
for(j=1;j&lt;=n;j++)
{
if(vis[j]==0 &amp;&amp; dis[j]&lt;min)
{
min=dis[j];
u=j;
}
}
vis[u]=1;
for(j=1;j&lt;=n;j++)
{
if(vis[j]==0 &amp;&amp; dis[u]+cost[u][j]&lt;dis[j])
{
dis[j]=dis[u]+cost[u][j];
}
}
}
printf(&quot;shortest path\n&quot;);
for(i=1;i&lt;=n;i++)
printf(&quot;%d-&gt;%d=%d\n&quot;,src,i,dis[i]);
}

void main()

{
int src,j,cost[10][10],n,i;
clrscr();
printf(&quot;enter the number of vertices\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;enter the cost adjacency matrix\n&quot;);
for(i=1;i&lt;=n;i++)
for(j=1;j&lt;=n;j++)
scanf(&quot;%d&quot;,&amp;cost[i][j]);
printf(&quot;enter the source vertex\n&quot;);
scanf(&quot;%d&quot;,&amp;src);
dijkstra(n,cost,src);
getch();
}
