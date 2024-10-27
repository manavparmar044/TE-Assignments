package assignment8;

import java.sql.*;
import java.util.Scanner;

public class JDBC {
    public static void main(String[] args) {
        String url = "jdbc:mysql://127.0.0.1:3306/31380_db";
        String username = "root";
        String password = "root1234";

        try (Connection con = DriverManager.getConnection(url, username, password);
             Scanner sc = new Scanner(System.in)) {

            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Database connected!");

            int choice, id;
            double salary;
            String name, position, ans;

            do {
                System.out.println("\n1. Select\n2. Insert\n3. Update\n4. Delete\n5. Exit");
                System.out.print("Enter choice: ");
                choice = sc.nextInt();

                switch (choice) {
                    case 1 -> {  // Select
                        try (Statement st = con.createStatement();
                             ResultSet rs = st.executeQuery("SELECT * FROM emp_table")) {
                            System.out.println("| ID |      Name      |  Position  |  Salary  |");
                            while (rs.next()) {
                                System.out.printf("%d %s %s %.2f%n", rs.getInt("emp_id"),
                                        rs.getString("emp_name"), rs.getString("emp_position"), rs.getDouble("emp_salary"));
                            }
                        }
                    }
                    case 2 -> {  // Insert
                        System.out.print("Enter ID, Name, Position, Salary: ");
                        id = sc.nextInt();
                        name = sc.next();
                        position = sc.next();
                        salary = sc.nextDouble();

                        String insertQuery = "INSERT INTO emp_table VALUES (?, ?, ?, ?)";
                        try (PreparedStatement ps = con.prepareStatement(insertQuery)) {
                            ps.setInt(1, id);
                            ps.setString(2, name);
                            ps.setString(3, position);
                            ps.setDouble(4, salary);
                            ps.executeUpdate();
                            System.out.println("Record inserted successfully!");
                        }
                    }
                    case 3 -> {  // Update
                        System.out.print("Enter ID, new Name, Position, Salary: ");
                        id = sc.nextInt();
                        name = sc.next();
                        position = sc.next();
                        salary = sc.nextDouble();

                        String updateQuery = "UPDATE emp_table SET emp_name = ?, emp_position = ?, emp_salary = ? WHERE emp_id = ?";
                        try (PreparedStatement ps = con.prepareStatement(updateQuery)) {
                            ps.setString(1, name);
                            ps.setString(2, position);
                            ps.setDouble(3, salary);
                            ps.setInt(4, id);
                            ps.executeUpdate();
                            System.out.println("Record updated successfully!");
                        }
                    }
                    case 4 -> {  // Delete
                        System.out.print("Enter ID to delete: ");
                        id = sc.nextInt();

                        String deleteQuery = "DELETE FROM emp_table WHERE emp_id = ?";
                        try (PreparedStatement ps = con.prepareStatement(deleteQuery)) {
                            ps.setInt(1, id);
                            ps.executeUpdate();
                            System.out.println("Record deleted successfully!");
                        }
                    }
                    case 5 -> System.out.println("Exiting program...");
                    default -> System.out.println("Invalid choice.");
                }
                
                if (choice != 5) {
                    System.out.print("\nContinue? (y/n): ");
                    ans = sc.next();
                } else {
                    ans = "n";
                }
                
            } while (ans.equalsIgnoreCase("y"));
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
