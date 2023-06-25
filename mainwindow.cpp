#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(DataRenderer* dataRenderer, QWidget *parent)
    : QMainWindow(parent), dataRenderer(dataRenderer)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zoomInButton = new QPushButton("Zoom In", this);
    zoomOutButton = new QPushButton("Zoom Out", this);

    connect(zoomInButton, &QPushButton::clicked, dataRenderer, &DataRenderer::ZoomIn);
    connect(zoomOutButton, &QPushButton::clicked, dataRenderer, &DataRenderer::ZoomOut);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(zoomInButton);
    buttonLayout->addWidget(zoomOutButton);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(dataRenderer);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(scrollArea);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

