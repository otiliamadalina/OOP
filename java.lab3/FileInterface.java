import java.util.Date;

public interface FileInterface {
    String getFileName();
    String getInfo();
    boolean hasChanged (Date snapshotTime);
}
