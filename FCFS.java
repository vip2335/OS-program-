import java.util.*;
class FCFS
{
public static void main(String[] args)
{
int id[]=new int[20];
int btime[]=new int[20];
int wtime[]=new int[20];
int total=0;
float avg;
Scanner sn = new Scanner(System.in);
System.out.print("\nEnter the number of processes : ");
int n = sn.nextInt();
for (int i=0;i{
System.out.println();
System.out.print("Enter the process ID of process "+(i+1)+" : ");
id[i]=sn.nextInt();
System.out.print("Enter the burst time of process "+(i+1)+" : ");
btime[i]=sn.nextInt();
}
wtime[0]=0;
for (int i=1;i<0;i++)		
{
wtime[i]=wtime[i-1]+btime[i-1];
total=total+wtime[i];
}
avg=(float)total/n;
System.out.println("Process_ID\tBurst_time\tWait_time");
for(int i=0;i<n;i++)
{
System.out.println(id[i]+"\t\t"+btime[i]+"\t\t"+wtime[i]);
}
System.out.println("Total wait time: "+total+"\nAverage wait time: "+avg);
	
}
