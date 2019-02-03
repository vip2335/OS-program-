class Test implements Runnable
{
public void run()
{
for(int i=1;i<=10;i++)
{
try
{
Thread.sleep(1000);
}
catch(Exception e)
{
}
System.out.println("Running thread is : " +Thread .currentThread().getName());
}
}
}
class Tm
{
public static void main(String[]args)
{
Test t=new Test();
Thread t1=new Thread (t);
Test p=new Test();
Thread t2=new Thread (p);
t1.setName("roshni");

t2.setName("vishal");
t1.run();
t2.run();
}
}


















