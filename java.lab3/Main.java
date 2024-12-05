import java.io.File;
import java.io.IOException;
import java.util.*;

public class Main {
    private static Date snapshotTime = new Date();
    private static final List<FileInterface> files = new ArrayList<>();
    private static final List<FileInterface> previousFiles = new ArrayList<>();
    private static final List<Commit> commitHistory = new ArrayList<>();
    private static final String folderLocation = "D:\\UTM\\OOP\\java.lab3";

    public static void main(String[] args) throws IOException {
        populateFileList(folderLocation);
        previousFiles.addAll(files);

        Timer timer = new Timer();
        timer.schedule(new FileUpdateTask(), 0, 60 * 1000); //odata la 60 sec

        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n\tOptions:");
            System.out.println("commit <commit_name> - Create a commit");
            System.out.println("info <filename> - Get file information");
            System.out.println("status - Show file status");
            System.out.println("checkout <commit_name> - Revert to a specific commit");
            System.out.println("log - Show all commits");
            System.out.println("exit - Exit the program");
            System.out.print("Enter command: ");

            String choice = scanner.nextLine();

            if (choice.startsWith("commit")) {
                String[] parts = choice.split(" ", 2);
                if (parts.length == 2) {
                    String commitName = parts[1];
                    snapshotTime = new Date();
                    commitHistory.add(new Commit(snapshotTime, new ArrayList<>(files), commitName));
                    System.out.println("Commit created: " + commitName + " at " + snapshotTime);
                } else {
                    System.out.println("Usage: commit <commit_name>");
                }
                
            } else if (choice.equals("log")) {
                if (commitHistory.isEmpty()) {
                    System.out.println("No commits have been made yet.");
                } else {
                    System.out.println("\nCommit History:");
                    for (int i = 0; i < commitHistory.size(); i++) {
                        Commit commit = commitHistory.get(i);
                        System.out.println((i + 1) + ": " + commit.getCommitName() + " (Time: " + commit.getCommitTime() + ")");
                    }
                }
            } else if (choice.startsWith("info")) {
                String[] parts = choice.split(" ");
                if (parts.length == 2) {
                    String filename = parts[1];
                    displayFileInfo(filename);
                }
            } else if (choice.equals("status")) {
                displayFileStatus();
            } else if (choice.equals("exit")) {
                System.out.println("Exiting the program.");
                timer.cancel();
                break;
            } else {
                System.out.println("Invalid command! Try again.");
            }
        }
        scanner.close();
    }

    private static void populateFileList(String folderLocation) throws IOException {
        File folder = new File(folderLocation);

        if (!folder.exists() || !folder.isDirectory()) {
            System.out.println("Invalid folder location: " + folderLocation);
            return;
        }

        File[] filesInFolder = folder.listFiles(); //obtinem lista de fisiere

        if (filesInFolder != null) {
            files.clear(); //pt a stoca noi fisiere

            for (File file : filesInFolder) { //parcurgem fiecare obiect din lista
                if (file.isFile()) { //fisier nu subfoleder

                    String fileName = file.getName(); //extragem numele fisierului
                    FileInterface fileObject = createFileObject(fileName);

                    if (fileObject != null) {
                        files.add(fileObject); //adaugam fisierul in lista globala
                    }
                }
            }
        }
    }

    private static void displayFileStatus() {
        System.out.println("\nFile status since snapshot time: " + snapshotTime);

        try {
            populateFileList(folderLocation);
        } catch (IOException e) {
            System.out.println("Error updating file list: " + e.getMessage());
            return;
        }

        List<String> addedFiles = files.stream()
                .map(FileInterface::getFileName)
                .filter(fileName -> previousFiles.stream()
                        .noneMatch(prevFile -> prevFile.getFileName().equals(fileName)))
                .toList();

        List<String> deletedFiles = previousFiles.stream()
                .map(FileInterface::getFileName)
                .filter(fileName -> files.stream()
                        .noneMatch(currentFile -> currentFile.getFileName().equals(fileName)))
                .toList();

//        System.out.println("Current files (files):");
//        files.forEach(file -> System.out.println(file.getFileName()));
//
//        System.out.println("\nPrevious files (previousFiles):");
//        previousFiles.forEach(file -> System.out.println(file.getFileName()));
//        System.out.println("\n");

        for (FileInterface file : files) {
            if (!addedFiles.contains(file.getFileName())) {
                String status = file.hasChanged(snapshotTime) ? "Changed" : "No Changes";
                System.out.println(file.getFileName() + " - " + status);
            }
        }

        for (String addedFile : addedFiles) {
            System.out.println(addedFile + " - New file");
        }

        for (String deletedFile : deletedFiles) {
            System.out.println(deletedFile + " - Deleted");
        }

        previousFiles.clear();
        previousFiles.addAll(files);
    }

    private static FileInterface createFileObject(String fileName) throws IOException {
        String extension = getExtension(fileName);

        return switch (extension) {
            case "txt" -> new TextFile(fileName);
            case "png", "jpg" -> new ImageFile(fileName);
            case "java" -> new ProgramFile(fileName);
            default -> null;
        };
    }

    private static String getExtension(String fileName) {
        int dotIndex = fileName.lastIndexOf('.');

        if (dotIndex != -1) {
            return fileName.substring(dotIndex + 1);
        }
        return "";
    }

    private static void displayFileInfo(String filename) {
        for (FileInterface file : files) {
            if (file.getFileName().equals(filename)) {

                System.out.println(file.getInfo());
                return;
            }
        }
        System.out.println("File not found: " + filename);
    }

    private static Commit findCommitByName(String commitName) {
        for (Commit commit : commitHistory) {
            if (commit.getCommitName().equals(commitName)) {
                return commit;
            }
        }
        return null;
    }

    static class FileUpdateTask extends TimerTask {
        public void run() {

            System.out.println("\nUpdating file timestamps...");

            previousFiles.clear();
            previousFiles.addAll(files);

            String folderLocation = "D:\\UTM\\OOP\\java.lab3";

            try {
                populateFileList(folderLocation);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            displayFileStatus();

            System.out.println("""
                    \n\tOptions:\s
                    commit <commit_name> - Create a commit
                    info <file> - Get file information
                    log - Show all commits
                    status - Show file status
                    exit - Exit the program
                    Enter a command:""");

        }
    }
}
