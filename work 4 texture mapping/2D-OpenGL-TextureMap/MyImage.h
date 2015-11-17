
#ifndef MYIMAGE_H_
#define MYIMAGE_H_

#include <QImage>
#include <QString>
#include <QLabel>
#include <QPixmap>

#include <QStringList>
#include <QLabel>

class MyImage: public QObject //need this for using signals
{
	Q_OBJECT

private:
	QLabel *imgLabel;

public:
	QImage image;
	MyImage();
	virtual ~MyImage();
	bool openImageFile(const QString fname, QLabel * imgLabel);
};

#endif /* MYIMAGE_H_ */
