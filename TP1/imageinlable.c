void MainWindow::on_btn_cvImageQt_clicked()
{
    Mat cv_image = imread(m_fileName.toStdString(), CV_LOAD_IMAGE_COLOR);
    blur(cv_image, cv_image, Size(9,9), Point(-1,-1));
    circle(cv_image, Point(400,200), 100, Scalar(0,255,255), 4);
    cvtColor(cv_image, cv_image, CV_BGR2RGB);

    ui->label_image->setPixmap(QPixmap::fromImage(QImage(cv_image.data, cv_image.cols, cv_image.rows, cv_image.step, QImage::Format_RGB888)));

}