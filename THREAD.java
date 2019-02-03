class MYThread extends Thread 
{
public  void run()
{
for(int i=0;i<=10;i++)
{
System.out.println("child thread");
}
}
}
class M
{
public static void main(String [] args)
{
MYThread t=new MYThread();
t.start();
for(int j=0;j<=10;j++)
{
System.out.println("main thread");
}
}
}																								