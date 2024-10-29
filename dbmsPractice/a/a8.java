package a8;

import java.sql.*;
import java.util.Scanner;

public class JDBC{
    public static void main(String[] args){
        String url = "jdbc:mysql://127.0.0.1:3306/31352_db";
        String username = "root";
        String password = "root1234";

        try(Connection con = DriverManager.getConnection(url,username,password);Scanner sc = new Scanner(System.in)){
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Database connected!");

            int choice,id;
            double salary;
            String name,position,ans;

            do{
                System.out.println("\n1. Select\n2. Insert\n3. Update\n4. Delete\n5. Exit");
                System.out.print("Enter choice: ");
                choice = sc.nextInt();

                switch(choice){
                    case 1 -> {}
                }
            }
        }
        catch(SQLException | ClassNotFoundException e){
            System.out.println("An error occured. ");
            e.printStackTrace();
        }
    }
}