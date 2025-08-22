import java.util.Scanner;


public class Tut{

    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        Houses houses;

        System.out.println("Enter the number of houses");
        while (true){
            int numHouses;
            numHouses = inp.nextInt();

            if( numHouses <= 0){
                System.out.println("Enter a valid number of houses");
            }
            else{
                houses = new Houses(numHouses);
                break;
            }
        }

        for(int i = 0 ; i < houses.size; i++){
            System.out.println("Enter the number of students in house " + (i+1) + ": ");
            int students = inp.nextInt();
            houses.createHouse(students);
            for(int j = 0; j < students ; j++){
                System.out.println("Enter the score of student " + (j + 1) +" in house " + (i + 1) + ": ");
                int score = inp.nextInt();

                while(score < 0 || score > 10){
                    System.out.println("score should be higher than 0 and less than 10");
                    score = inp.nextInt();
                }

                houses.setScoreStudent(i , j , score);

            }
        }
        inp.close();

        houses.displayHighestScore();
    }


}



class Houses {
    Integer[][] array;
    int size;
    int pointer;

    Houses(int size) {
        array = new Integer[size][];
        this.size = size;
        this.pointer = 0;
    }

    public void createHouse(int rowLength) {
        if (pointer < size) {
            array[pointer] = new Integer[rowLength];
            pointer++;

        } else {
            System.out.println("you have reached max length of available rows in the array ");
        }
    }
    public void setScoreStudent(int row , int col , int value){

        if(this.array.length <= row){
            System.out.println("Element out of range");
        }
        else{
            if(this.array[row].length <= col){
                System.out.println("Element out of range");

            }
            else{

                this.array[row][col] = value;
            }
        }
    }

    public void displayScores(){
        for (int i = 0; i < size; i++){
            for(int j = 0; j < this.array[i].length ; j++){
                System.out.printf("%d\t" , this.array[i][j]);
            }
            System.out.println();
        }
    }

    public void  displayHighestScore(){
        int highest = -1;
        int highestHouse = 0;
        for (int i = 0; i < size; i++){
            int temp = 0;
            for(int j = 0; j < this.array[i].length ; j++){
                temp += this.array[i][j];
            }
            if(temp > highest){
                highest = temp;
                highestHouse = i;
            }

        }
        System.out.println("The house with the highest score is " +( highestHouse + 1) + " with score: " + highest);

    }

}


