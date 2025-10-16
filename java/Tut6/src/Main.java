

class TicketCounter {
    public int availableTickets = 10;


    public void bookTicket(String user, int numberOfTickets) {
        System.out.println(user + " is trying to book " + numberOfTickets + " ticket(s)...");

        if (numberOfTickets <= availableTickets && availableTickets > 0) {
            System.out.println("Booking successful for " + user);
            availableTickets -= numberOfTickets;
            System.out.println("Tickets left: " + availableTickets);
        } else {
            System.out.println("Booking failed for " + user + ". Not enough tickets available.");
            System.out.println("Tickets left: " + availableTickets);
        }

    }
}

class TicketBookingThread extends Thread {
    public TicketCounter counter;
    public String user;
    public int ticketsToBook;

    public TicketBookingThread(TicketCounter counter, String user, int ticketsToBook) {
        this.counter = counter;
        this.user = user;
        this.ticketsToBook = ticketsToBook;
    }

    @Override
    public void run() {
        counter.bookTicket(user, ticketsToBook);
    }
}

public class Main {
    public static void main(String[] args) {
        TicketCounter counter = new TicketCounter();


        TicketBookingThread user1 = new TicketBookingThread(counter, "User1", 3);
        TicketBookingThread user2 = new TicketBookingThread(counter, "User2", 5);
        TicketBookingThread user3 = new TicketBookingThread(counter, "User3", 4);
        TicketBookingThread user4 = new TicketBookingThread(counter, "User4", 2);


        user1.start();
        user2.start();
        user3.start();
        user4.start();
    }
}
