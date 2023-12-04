abstract class Animal{
    abstract void walk();
}  

class dog extends Animal{
    void walk(){
        System.out.println("Dogs walk on 4 legs");
    }
}  

class cat extends Animal{
    void walk(){
        System.out.println("cats walk on 2 legs");
    }
}

public class ex{
  public static void main(String[] args) {
    dog a=new dog();
    a.walk();
  }
}