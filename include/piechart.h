#ifndef PIECHART_H
#define PIECHART_H

#include <QOpenGLWidget>
#include <QMap>
#include <QString>

class PieChartOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit PieChartOpenGLWidget(QWidget* parent = nullptr);
    void setDepartmentData(const QMap<QString, int>& data);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QMap<QString, int> departmentCounts;
};

#endif // PIECHART_OPENGL_H
