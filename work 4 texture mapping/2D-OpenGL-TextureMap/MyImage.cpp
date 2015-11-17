
#include "MyImage.h"

MyImage::MyImage() {
	// TODO Auto-generated constructor stub

	imgLabel = 0;

}

MyImage::~MyImage() {
	// TODO Auto-generated destructor stub

}

bool MyImage::openImageFile(const QString fname, QLabel *img_label){

	if (fname.isEmpty()) {
		return false;
	}
	else{
		imgLabel = img_label;
		image.load(fname);
        if (image.isNull()) {
            return false;
        }
        imgLabel->setBackgroundRole(QPalette::Base);
        imgLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        imgLabel->setScaledContents(true);
        imgLabel->setPixmap(QPixmap::fromImage(image));

     }
    return true;
}




