import java.util.Scanner;

public class arrayThingy{

	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the columns of the array");
		int cols = scanner.nextInt();
		System.out.println("Enter the rows of the array");
		int rows = scanner.nextInt();
		ArrayClass array = new ArrayClass(rows , cols);

		array.addElements2d();
		array.displayElements2d();
		//array.addElements();
		//array.displayArr();
		//System.out.println("The largest element is: " +array.findLargest());
		//System.out.println("The largest element is: " +array.findSmallest());
	scanner.close();
}



}
class ArrayClass{
	int size;
	Integer[] intArr;
	Integer[][] intArr2;
	int pointer = 0;
	int rows;
	int cols;
	public  ArrayClass(int sizearr){
		this.size = sizearr;
		intArr = new Integer[sizearr];

	}
	public ArrayClass(int rows, int cols){
	
		intArr2 = new Integer[rows][cols];
		this.rows = rows;
		this.cols = cols;
	}

	public void addElements2d(){
		 Scanner eleScanner = new Scanner(System.in);
		for(int i = 0 ; i < this.rows ; i++){
		
			for(int j = 0 ; j < this.cols ; j++){
				System.out.println("Enter element " + i+ " " + j );
				this.intArr2[i][j] = eleScanner.nextInt();
			}
		}
	
	}
	public void displayElements2d(){
		System.out.println("Displaying 2d array: ");
		for(int i = 0 ; i < this.rows ; i++){

                        for(int j = 0 ; j < this.cols ; j++){
                                System.out.print(intArr2[i][j] + "\t");
                                
                        }
			System.out.println();
                }	
	}

	public void addElements(){
		Scanner eleScanner = new Scanner(System.in);	
	
		for(int i = 0 ; i < this.size ; i++){
			System.out.println("Enter element " + (i + 1));
			this.intArr[i] = eleScanner.nextInt();
		}

		eleScanner.close();
		
	}
	
	public void displayArr(){

		System.out.println("Printing array");
                for(int i = 0 ; i < this.size ; i++){
                        System.out.println(intArr[i]);
          
                }
	
	}
	public int findLargest(){
		int largest = this.intArr[0];
		for(int i = 1 ; i < this.size ; i++){
			
			if( largest < this.intArr[i]){
				largest = this.intArr[i];
			}
	
		}
		return largest;

	}

	public int findSmallest(){
                int smallest = this.intArr[0];
                for(int i = 1 ; i < this.size ; i++){

                        if( smallest > this.intArr[i]){
                                smallest = this.intArr[i];
                        }

                }
                return smallest;
	}
}
