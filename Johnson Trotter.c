#include &lt;bits/stdc++.h&gt;
using namespace std;
bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;
int searchArr(int a[], int n, int mobile)
{
for (int i = 0; i &lt; n; i++)
if (a[i] == mobile)
return i + 1;
}
.
int getMobile(int a[], bool dir[], int n)
{
int mobile_prev = 0, mobile = 0;
for (int i = 0; i &lt; n; i++)
{
.
if (dir[a[i]-1] == RIGHT_TO_LEFT &amp;&amp; i!=0)
{
if (a[i] &gt; a[i-1] &amp;&amp; a[i] &gt; mobile_prev)
{
mobile = a[i];
mobile_prev = mobile;
}
}
if (dir[a[i]-1] == LEFT_TO_RIGHT &amp;&amp; i!=n-1)
{
if (a[i] &gt; a[i+1] &amp;&amp; a[i] &gt; mobile_prev)
{
mobile = a[i];
mobile_prev = mobile;
}
}
}
if (mobile == 0 &amp;&amp; mobile_prev == 0)
return 0;
else
return mobile;
}
int printOnePerm(int a[], bool dir[], int n)
{
int mobile = getMobile(a, dir, n);
int pos = searchArr(a, n, mobile);

if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)
swap(a[pos-1], a[pos-2]);
else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
swap(a[pos], a[pos-1]);
for (int i = 0; i &lt; n; i++)
{
if (a[i] &gt; mobile)
{
if (dir[a[i] - 1] == LEFT_TO_RIGHT)
dir[a[i] - 1] = RIGHT_TO_LEFT;
else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
dir[a[i] - 1] = LEFT_TO_RIGHT;
}
}
for (int i = 0; i &lt; n; i++)
cout &lt;&lt; a[i];
cout &lt;&lt; &quot; &quot;;
}
int fact(int n)
{
int res = 1;
for (int i = 1; i &lt;= n; i++)
res = res * i;
return res;
}
void printPermutation(int n)
{
int a[n];
bool dir[n];
for (int i = 0; i &lt; n; i++)
{
a[i] = i + 1;
cout &lt;&lt; a[i];
}
cout &lt;&lt; endl;

for (int i = 0; i &lt; n; i++)
dir[i] = RIGHT_TO_LEFT;

for (int i = 1; i &lt; fact(n); i++)
printOnePerm(a, dir, n);
}
int main()
{
int n = 4;
printPermutation(n);
return 0;
}
