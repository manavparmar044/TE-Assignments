package connect;

import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

import java.util.Scanner;

public class Connect{
    private static MongoClient mongoClient;
    private static MongoCollection<Document> collection;
    private static Scanner scanner;

    public static void main(String[] args){
        mongoClient = new MongoClient(new MongoClientURI("mongodb://localhost:27017"));
        MongoDatabase database = mongoClient.getDatabase("mydatabase");
        collection = database.getCollection("mycollection");
        scanner = new Scanner(System.in);

        while(true){
            displayMenu();
            int choice = scanner.nextInt();
            scanner.nextLine();
            switch(choice){
                case 1: insertDocument();
                break;
                case 2: deleteDocument(); break;
                case 3: findDocument(); break;
                case 4: updateDocument(); break;
                case 5: displayAllDocuments(); break;
                case 6: mongoClient.close();
                scanner.close();
                return;
                default: System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void displayMenu(){
        System.out.println("\nMenu:");
        System.out.println("1. Insert Document");
        System.out.println("2. Delete Document");
        System.out.println("3. Find Document");
        System.out.println("4. Update Document");
        System.out.println("5. Display All Documents");
        System.out.println("6. Exit");
        System.out.print("Choose an option: ");
    }

    private static void insertDocument(){
        System.out.print("Enter name: ");
        String name = scanner.nextLine();
        System.out.print("Enter age: ");
        int age = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter city: ");
        String city = scanner.nextLine();

        Document doc = new Document("name", name).append("age",age).append("city",city);
        collection.insertOne(doc);
        System.out.println("Document inserted: " + doc.toJson());
    }

    private static void findDocument(){
        System.out.print("Enter the name of the document to find: ");
        string name = scanner.nextLine()
        Document doc = collection.find("name",name).first();
        System.out.println(doc!=null ? "Document found: "+ doc.toJson(): "Document not found");
    }

    private static void updateDocument(){
        System.out.print("Enter the name of the document to update: ");
        String name = scanner.nextLine();
        Document doc = collection.find(new Document("name", name)).first();

        if(doc!=null){
            System.out.print("Enter new age (current: " + doc.getInteger("age") + "): ");
            int newAge = scanner.nextInt();
            scanner.nextLine();
            System.out.print("Enter new city (current: " + doc.getString("city") + "): ");
            String newCity = scanner.nextLine();

            Document updatedDoc = new Document("name", name)
                    .append("age", newAge)
                    .append("city", newCity);
            collection.replaceOne(new Document("name",name),updatedDoc);
            System.out.println("Document updated: " + updatedDoc.toJson());
        }
        else {
            System.out.println("Document not found.");
        }
    }

    private static void displayAllDocuments(){
        System.out.println("\nDisplaying all documents:");
        collection.find().forEach(doc->System.out.println(doc.toJson()));
    }
};
