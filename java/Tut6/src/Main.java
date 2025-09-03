abstract class shape{
    public abstract double area();
}

class circle extends shape{
    public double radius;
    public circle(double radius){
        this.radius=radius;
    }

    public double area(){
        return Math.PI*radius*radius;
    }
}
class rectangle extends shape{
    public double length;
    public double breadth;
    public rectangle(double length, double breadth){
        this.length=length;
        this.breadth=breadth;
    }

    public double area(){
        return length*breadth;
    }
}
public class Main{
    public static void main(String[] args){
        shape s1=new circle(5);
        shape s2=new rectangle(3,5);
        System.out.println("Circle area: "+s1.area());
        System.out.println("Rectangle area: "+s2.area());
    }
}