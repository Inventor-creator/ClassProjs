import java.awt.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Main{




    public static void main(String[] args){

        final String url = "jdbc:postgresql://localhost:5432/javaExp";
        final String user = "postgres";
        final String password = "postgres";

        try{
            Connection conn =  DriverManager.getConnection(url, user, password);
            System.out.println("yay");

            Statement statement = conn.createStatement();

            

        }catch (SQLException e){
            System.out.println("didnt connect");
        }

    }

}