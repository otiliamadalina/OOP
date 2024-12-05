import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;

class ProgramFile extends BaseFile {
    private int lineCount;
    private int classCount;
    private int methodCount;

    public ProgramFile(String fileName) {
        super(fileName);
        String content = getProgramFileContent(fileName);
        countProgramFileMetrics(content);
    }

    @Override
    public String getInfo() {
        return "Program File - " + fileName + " Extension: " + extension + "\n"
                + "Created: " + createdDate + " Updated: " + updatedDate + "\n"
                + "Line Count: " + lineCount + " Class Count: " + classCount + " Method Count: " + methodCount;
    }

    private String getProgramFileContent(String fileName) {
        try {
            byte[] bytes = Files.readAllBytes(Paths.get(fileName));
            return new String(bytes, StandardCharsets.UTF_8);
        } catch (IOException e) {
            e.printStackTrace();
            return "";
        }
    }

    private void countProgramFileMetrics(String content) {
        String[] lines = content.split("\r\n|\r|\n");
        lineCount = lines.length;

        classCount = content.split("\\bclass\\s+").length - 1;
        methodCount = content.split("\\bvoid\\s+").length - 1;
    }

}