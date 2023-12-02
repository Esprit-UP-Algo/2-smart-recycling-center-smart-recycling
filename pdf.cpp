#include "pdf.h"
#include "ui_pdf.h"
#include"commande.h"
#include"mainwindow.h"
#include<QPdfWriter>
#include<QMessageBox>
#include <QPrinter>
#include <QPainter>
#include<QDesktopServices>
#include<QUrl>
#include<QDebug>
#include <QFileDialog>

pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
}

pdf::~pdf()
{
    delete ui;
}
void pdf::on_pdf_commande_clicked() // pdf //
{
    Commande C;
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export to PDF", "", "PDF Files (*.pdf)");

       if (fileName.isEmpty()) {
           // User canceled the operation
           return;
       }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QPainter painter;
       painter.begin(&printer);

       // Set font and size
       painter.setFont(QFont("Arial", 12));

       // Print header
       painter.drawText(100, 100, "Commande Report");

       // Print table headers
       painter.drawText(100, 150, "Numéro de Commande");
       painter.drawText(250, 150, "Date de Livraison");
       painter.drawText(400, 150, "Référence");
       painter.drawText(550, 150, "Total de commande");
       painter.drawText(700, 150, "Nationalité");

       int rowHeight = 200; // Adjust this value based on your preference

       // Print data
       QSqlQueryModel *model = C.afficher(); // Assuming afficher() returns the data model
       for (int row = 0; row < model->rowCount(); ++row) {
           for (int col = 0; col < model->columnCount(); ++col) {
               QString data = model->data(model->index(row, col)).toString();
               painter.drawText(100 + col * 150, rowHeight + row * 50, data);
           }
       }

       painter.end();
}
