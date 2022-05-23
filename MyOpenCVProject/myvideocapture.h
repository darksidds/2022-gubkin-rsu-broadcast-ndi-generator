#ifndef MYVIDEOCAPTURE_H
#define MYVIDEOCAPTURE_H

// подключения
#include <QPixmap>
#include <QImage>
#include <QThread>
#include <opencv2/opencv.hpp>

#define ID_CAMERA 0

class MyVideoCapture: public QThread // наследуем от QThread
{
    // сложноватая структура для меня...
    Q_OBJECT
public:
    MyVideoCapture(QObject *parent = nullptr);

    QPixmap pixmap() const
    {
        return mPixmap;
    }

signals:
    void newPixmapCaptured(); // новое изображение было захвачено

protected:
    void run() override;

private:
    QPixmap mPixmap; // то, что захватываем в формате Qt
    cv::Mat mFrame; // то, что захватываем в формате OpenCV
    cv::VideoCapture mVideoCap; // сам захват средствами OpenCV

    //прототипы(?) по блоку кода из интернета
    QImage cvMatToQImage( const cv::Mat &inMat );
    QPixmap cvMatToQPixmap( const cv::Mat &inMat );
};

#endif // MYVIDEOCAPTURE_H
