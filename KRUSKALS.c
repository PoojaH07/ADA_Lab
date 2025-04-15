
Analysis and Design of Algorithms (Feb-May 2025)
4D
Upcoming
Woohoo, no work due soon!

Announce something to your class

Announcement: "Dear all, Week-4 ADA LAB-02-04-2025,…"
Namratha M
Created 10:54 AM10:54 AM
Dear all,

Week-4 ADA LAB-02-04-2025, you need to execute Lab Program-8:
(i) Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm. (5 Marks)
(ii) Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal’s algorithm. (5 Marks)

Add class comment…


Announcement: "Dear all, PFTA for ADA prescribed text…"
Namratha M
Created YesterdayYesterday
Dear all,
PFTA for ADA prescribed text book.

LEVITIN TEXT BOOK-3RD EDITION.pdf
PDF

Add class comment…


Announcement: "Dear all, Prims and Kruskal algortihm…"
Namratha M
Created YesterdayYesterday
Dear all,
Prims and Kruskal algortihm codes.

KRUSKAL (1).C
C

PRIMS (1).C
C

Add class comment…


Announcement: "Dear all, PFTA for the ADA Test-1 marks…"
Namratha M
Created YesterdayYesterday
Dear all,
PFTA for the ADA Test-1 marks along with the scheme and solutions attached.

Scheme and Solutions-Test 1-ADA- Feb to May 2025 (1).docx
Microsoft Word

QP- Test 1-ADA- Feb to May 2025-26-03-2025 (1).docx
Microsoft Word

ADA Test-1 marks-4D-31-03-2025.xlsx
Microsoft Excel

Add class comment…


Announcement: "Dear all, Previous ADA CIE QP sample…"
Namratha M
Created Mar 27Mar 27
Dear all,
Previous ADA CIE QP sample for reference.

22CS4PCADA-Test-2-ERP (1).pdf
PDF

Add class comment…


Announcement: "Dear all, PFTA for ADA notes"
Namratha M
Created Mar 27Mar 27
Dear all,
PFTA for ADA notes

ADA NOTES-Namratha M.pdf
PDF

Add class comment…


Announcement: "Dear all, Syllabus for Test-1 is:…"
Namratha M
Created Mar 23Mar 23
Dear all,
Syllabus for Test-1 is: Unit-1, Divide and Conquer technique, Greedy Technique-Prims and Kruskal algorithm.

Add class comment…


Announcement: "Dear all, Week-3 of ADA lab…"
Namratha M
Created Mar 19Mar 19
Dear all,

Week-3 of ADA lab (19-03-2025), you need to execute the following:

Lab Program-3:
Sort a given set of N integer elements using Merge Sort technique and compute its time taken. Run the program for different values of N and record the time taken to sort. (10 Marks)
Lab Program-4:
Sort a given set of N integer elements using Quick Sort technique and compute its time taken. (5 Marks)
LeetCode Program (5 Marks)
https://leetcode.com/problems/3sum/description/?envType=problem-list-v2&envId=sorting&amp;

Add class comment…


Announcement: "Dear all, Please carry a separate new…"
Namratha M
Created Mar 11Mar 11 (Edited Mar 18)
Dear all,
Please carry a separate new note book (Observation book) for ADA lab from tomorrow itself since the weekly evaluation will be starting from tomorrow. Please write down the compelte question in your observation book before coming to the lab.

Week-2 of ADA lab (12-03-2025), you need to execute the following:
Lab Program-1:
1 (a) Write program to obtain the Topological ordering of vertices in a given digraph. (5 Marks)


1 (b) LeetCode Program related to Topological sorting. (5 Marks)
Link to access: https://leetcode.com/problems/course-schedule/description/?envType=problem-list-v2&envId=topological-sort

Course Schedule: There are a total of numCourses courses you have to take,
labeled from 0 to numCourses - 1. You are given an array prerequisites where
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you
want to take course ai.


For example, the pair [0, 1], indicates that to take course
0 you have to first take course 1. Return true if you can finish all courses. Otherwise, return
false.

Add class comment…


Announcement: "Dear all, Week-1 of ADA lab…"
Namratha M
Created Mar 5Mar 5
Dear all,
Week-1 of ADA lab (05-03-2025), please execute the following:
1. https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list
2. https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=problem-list-v2&envId=queue
3. https://leetcode.com/problems/longest-absolute-file-path/description/?envType=problem-list-v2&envId=stack

Also, write the logic for each program in your observation book.

Add class comment…

Stream
#include<stdio.h>
#include<conio.h>

int find(int v,int parent[10])
{
   while(parent[v]!=v)
   {
      v=parent[v];
   }
   return v;
}

void union1(int i,int j,int parent[10])
{
   if(i<j)
      parent[j]=i;
   else
      parent[i]=j;
}

void kruskal(int n,int a[10][10])
{
   int count,k,min,sum,i,j,t[10][10],u,v,parent[10];
   count=0;
   k=0;
   sum=0;
   for(i=0;i<n;i++)
      parent[i]=i;
   while(count!=n-1)
   {
      min=999;
      for(i=0;i<n;i++)
      {
	 for(j=0;j<n;j++)
	 {

	    if(a[i][j]<min && a[i][j]!=0)
	    {
		min=a[i][j];
		u=i;
		v=j;                                          .
	     }
	  }
       }
       i=find(u,parent);
       j=find(v,parent);
       if(i!=j)
       {
	  union1(i,j,parent);
	  t[k][0]=u;
	  t[k][1]=v;
	  k++;
	  count++;
	  sum=sum+a[u][v];
       }
       a[u][v]=a[v][u]=999;
    }
    if(count==n-1)
    {
       printf("spanning tree\n");
       for(i=0;i<n-1;i++)
       {
	  printf("%d %d\n",t[i][0],t[i][1]);
       }
       printf("cost of spanning tree=%d\n",sum);
    }
    else
       printf("spanning tree does not exist\n");
  }


void main()
{
   int n,i,j,a[10][10];
   clrscr();
   printf("enter the number of nodes\n");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
   kruskal(n,a);
   getch();

}
