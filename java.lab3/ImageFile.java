import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Date;

class ImageFile extends BaseFile {
    private int width;
    private int height;

    public ImageFile(String fileName) throws IOException {
        super(fileName);
        BufferedImage img = ImageIO.read(new java.io.File(fileName));
        this.width = img.getWidth();
        this.height = img.getHeight();

    }

    @Override
    public String getInfo() {
        return "Image File - " + fileName + " Extension: " + extension + "\n"
                + "Created: " + createdDate + " Updated: " + updatedDate + "\n"
                + "Image Size: " + width + "x" + height;
    }

}
