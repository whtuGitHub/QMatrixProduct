#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QPushButton>
#include <QSpacerItem>
#include <QHeaderView>
#include <QFileDialog>
#include <QDir>
#include <memory>
#include "matrixmodel.h"

class MatrixWidget : public QWidget
{
    /**
     * @brief Widget w/ QTableView and two buttons for matrices
     */
    Q_OBJECT
public:
    explicit MatrixWidget(QWidget *parent = 0);

    /**
     * @brief Return shared pointer to the MatrixModel object
     * @return
     */
    std::shared_ptr<MatrixModel> model();
public slots:
    /**
     * @brief Slot connected with "Size: " QSpinBox in the MainWindow
     * @param new_size New matrix size
     */
    void changeSize(int new_size);

    /**
     * @brief Slot connected with "Randomize" button
     */
    void randomize();

    /**
     * @brief Slot connected with "Import..." button.
     * Opens a QFileDialog
     */
    void import();
private:
    void setupUi();

    std::shared_ptr<MatrixModel> m_matrixModel;
    QTableView *m_tableView;
    QPushButton *m_randomizeButton;
    QPushButton *m_importButton;
};

#endif // MATRIXWIDGET_H
