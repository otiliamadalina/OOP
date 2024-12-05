import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;

class TextFile extends BaseFile {
    private int lineCount;
    private int wordCount;
    private int charCount;

    public TextFile(String fileName) {
        super(fileName);
        String content = getTextFileContent(fileName);
        countTextFileMetrics(content);
    }

    @Override
    public String getInfo() {
        return "Text File - " + fileName + " Extension: " + extension + "\n"
                + "Created: " + createdDate + " Updated: " + updatedDate + "\n"
                + "Line Count: " + lineCount + " Word Count: " + wordCount + " Character Count: " + charCount;
    }

    private String getTextFileContent(String fileName) {
        try {
            byte[] bytes = Files.readAllBytes(Paths.get(fileName));
            return new String(bytes, StandardCharsets.UTF_8);
        } catch (IOException e) {
            e.printStackTrace();
            return "";
        }
    }

    private void countTextFileMetrics(String content) {
        String[] lines = content.split("\r\n|\r|\n");
        lineCount = lines.length;
        wordCount = content.split("\\s+").length;
        charCount = content.length();
    }
}