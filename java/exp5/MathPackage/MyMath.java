package  MathPackage;

public class MyMath {

    public double power(int x , int y){
        int power = x;
        for(int i = (y - 1 ) ; i > 0 ; i--){
            power *= x;
        }

        return power;
    }

    public double getSum(int x,int n){
        double temp = 1;
        boolean negFlag = true;
        int number = 2;
        for (int i = 1 ; i < n ; i++){

            if(negFlag){
                temp -= power(x , number) / (factorial(number));
            }
            else{
                temp += power(x , number) / (factorial(number));
            }
            negFlag = !negFlag;
            number += 2;
        }
        return temp;
    }

    public int factorial(int n){
        int temp = 1;
        while(n > 0){
            temp *= n--;
        }
        return temp;
    }


}
