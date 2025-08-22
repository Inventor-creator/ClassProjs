public class Library {


    static class Book {

        String title;
        String author;
        String isbn;
        int publicationYear;
        double price;


        public Book() {
            this.title = "Unknown Title";
            this.author = "Unknown Author";
            this.isbn = "000-0000000000";
            System.out.println("Book initialized with default values.");
        }


        public Book(int publicationYear, double price) {

            this.publicationYear = publicationYear;
            this.price = price;
        }


        public void displayDetails() {
            System.out.println("\nBook Details:");
            System.out.println("Title           : " + title);
            System.out.println("Author          : " + author);
            System.out.println("ISBN            : " + isbn);
            System.out.println("Publication Year: " + publicationYear);
            System.out.println("Price           : ₹" + price);
        }
    }


    public Library() {
        System.out.println("Welcome to the Simple Library System!");
    }

    public static void main(String[] args) {


        Library myLibrary = new Library();


        Book myBook = new Book(2023, 599.50);


        myBook.title = "The Java Journey";
        myBook.author = "Arya Patil";
        myBook.isbn = "978-1234567890";

        Book book2 = new Book();
        myBook.displayDetails();
    }
}