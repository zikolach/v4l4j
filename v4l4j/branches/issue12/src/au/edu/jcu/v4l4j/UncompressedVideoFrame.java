package au.edu.jcu.v4l4j;

import java.awt.Point;
import java.awt.Transparency;
import java.awt.color.ColorSpace;
import java.awt.image.BufferedImage;
import java.awt.image.ComponentColorModel;
import java.awt.image.DataBuffer;
import java.awt.image.Raster;
import java.awt.image.SampleModel;

/**
 * This class of object encapsulate data for a video frame in an uncompressed image format.
 * Image using a format that can be stored in a {@link Raster} must pass a {@link SampleModel} to
 * the constructor. Image using a format that can be encapsulated in a {@link BufferedImage}
 * must pass a {@link ColorSpace} to the constructor.
 * @author gilles
 *
 */
class UncompressedVideoFrame extends BaseVideoFrame {
	
	/**
	 * This method builds a video frame object.
	 * @param grabber the {@link FrameGrabber} to which this frame must be returned to when recycled
	 * @param bufferSize the size in bytes of the byte array to be created
	 * @param sm the SampleModel used to build a WritableRaster or null if
	 * no raster should be created.
	 * @param cs the ColorSpace used to create a BuffereddImage, or null if no
	 * BufferedImage should be created
	 */
	UncompressedVideoFrame(AbstractGrabber grabber, int bufferSize,
			SampleModel sm,	ColorSpace cs) {
		super(grabber, bufferSize);
			
		// create raster if a sample model was given
		if (sm != null) {
			raster = new V4L4JRaster(sm, dataBuffer, new Point(0,0));
			
			//  create buffered image if a colorspace was given
			if (cs != null)
				bufferedImage = new BufferedImage(
								new ComponentColorModel(cs,
									false,
									false,
									Transparency.OPAQUE,
									DataBuffer.TYPE_BYTE),
								raster,false,null
							);
			else
				bufferedImage = null;
			
		} else
			raster = null;
	}
}
