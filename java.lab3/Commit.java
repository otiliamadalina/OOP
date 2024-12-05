import java.util.Date;
import java.util.List;

public class Commit {
    private final Date commitTime;
    private final List<FileInterface> committedFiles;
    private final String commitName;

    public Commit(Date commitTime, List<FileInterface> committedFiles, String commitName) {
        this.commitTime = commitTime;
        this.committedFiles = committedFiles;
        this.commitName = commitName;
    }

    public Date getCommitTime() {
        return commitTime;
    }

    public List<FileInterface> getCommittedFiles() {
        return committedFiles;
    }

    public String getCommitName() {
        return commitName;
    }
}