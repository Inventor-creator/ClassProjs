import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


abstract class Vehicle {
    public String vehicleNumber;
    public String brand;
    public double rentalPrice;
    
    
    public Vehicle(String vehicleNumber, String brand, double rentalPrice) {
        this.vehicleNumber = vehicleNumber;
        this.brand = brand;
        this.rentalPrice = rentalPrice;
    }
    
    
    public abstract double calculateRent(int days);
    
    
    public void displayDetails() {
        System.out.println("Vehicle Number: " + vehicleNumber);
        System.out.println("Brand: " + brand);
        System.out.println("Daily Rental Price: $" + rentalPrice);
    }
}


class Car extends Vehicle {
    public int seatingCapacity;
    
    public Car(String vehicleNumber, String brand, double rentalPrice, int seatingCapacity) {
        super(vehicleNumber, brand, rentalPrice);
        this.seatingCapacity = seatingCapacity;
    }
    
    @Override
    public double calculateRent(int days) {
        return (rentalPrice * days) + 100; 
    }
    
    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Type: Car");
        System.out.println("Seating Capacity: " + seatingCapacity);
    }
}


class Bike extends Vehicle {
    public boolean helmetAvailable;
    
    public Bike(String vehicleNumber, String brand, double rentalPrice, boolean helmetAvailable) {
        super(vehicleNumber, brand, rentalPrice);
        this.helmetAvailable = helmetAvailable;
    }
    
    @Override
    public double calculateRent(int days) {
        return rentalPrice * days;
    }
    
    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Type: Bike");
        System.out.println("Helmet Available: " + (helmetAvailable ? "Yes" : "No"));
    }
}


class Truck extends Vehicle {
    public double loadCapacity;
    
    public Truck(String vehicleNumber, String brand, double rentalPrice, double loadCapacity) {
        super(vehicleNumber, brand, rentalPrice);
        this.loadCapacity = loadCapacity;
    }
    
    @Override
    public double calculateRent(int days) {
        return (rentalPrice * days) + (50 * loadCapacity);
    }
    
    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Type: Truck");
        System.out.println("Load Capacity: " + loadCapacity + " tons");
    }
}


public class Tut5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        
        List<Vehicle> vehicles = new ArrayList<>();
        
        
        vehicles.add(new Car("CAR001", "Toyota", 50.0, 5));
        vehicles.add(new Car("CAR002", "Honda", 45.0, 4));
        vehicles.add(new Bike("BIKE001", "Yamaha", 20.0, true));
        vehicles.add(new Bike("BIKE002", "Hero", 15.0, false));
        vehicles.add(new Truck("TRUCK001", "Tata", 100.0, 5.0));
        vehicles.add(new Truck("TRUCK002", "Ashok Leyland", 120.0, 8.0));
        
        System.out.println("=== Vehicle Rental System ===");
        System.out.println();
        
        
        for (int i = 0; i < vehicles.size(); i++) {
            Vehicle vehicle = vehicles.get(i);
            
            System.out.println("Vehicle " + (i + 1) + ":");
            vehicle.displayDetails();
            
            
            System.out.print("Enter number of rental days for this vehicle: ");
            int days = scanner.nextInt();
            
            
            double totalRent = vehicle.calculateRent(days);
            System.out.println("Total Rent for " + days + " days: Rs: " + totalRent);
            System.out.println("-----------------------------------");
            System.out.println();
        }
        
        scanner.close();
    }
}
