import java.util.Date;
import java.io.IOException;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileTime;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;

abstract class BaseFile implements FileInterface {
    protected String fileName;
    protected String extension;
    protected Date createdDate;
    protected Date updatedDate;

    public BaseFile(String fileName) {
        this.fileName = fileName;
        this.extension = getExtension(fileName);
        this.createdDate = getCreationDate(fileName);
        this.updatedDate = getModificationDate(fileName);
    }

    public abstract String getInfo();

    public boolean hasChanged(Date snapshotTime) {
        this.updatedDate = getModificationDate(this.fileName);

        return updatedDate != null && updatedDate.after(snapshotTime);
    }


    public String getFileName() {
        return fileName;
    }

    private String getExtension(String fileName) {
        int dotIndex = fileName.lastIndexOf('.');

        if (dotIndex != -1) {
            return fileName.substring(dotIndex + 1);
        }
        return "";
    }

    private Date getCreationDate(String fileName) {
        Path path = FileSystems.getDefault().getPath(fileName);

        try {
            BasicFileAttributes attributes = Files.readAttributes(path, BasicFileAttributes.class);
            FileTime creationTime = attributes.creationTime();
            return new Date(creationTime.toMillis());

        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    private Date getModificationDate(String fileName) {
        Path path = FileSystems.getDefault().getPath(fileName);

        if (!Files.exists(path)) {
            return null;
        }

        try {
            BasicFileAttributes attributes = Files.readAttributes(path, BasicFileAttributes.class);
            FileTime modificationTime = attributes.lastModifiedTime();
            return new Date(modificationTime.toMillis());
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }
}





