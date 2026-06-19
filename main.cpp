#include <QTreeWidgetItem>
#include <QApplication>
#include "TreeWidget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TreeWidget tree;

    // Create parent items (these span all columns)
    QTreeWidgetItem* parent1 = new QTreeWidgetItem(&tree);
    parent1->setText(0, "Parent 1");
    
    // Add child items with multiple columns
    QTreeWidgetItem* child1 = new QTreeWidgetItem(parent1);
    child1->setText(0, "Child 1");
    child1->setText(1, "Value 1");
    
    QTreeWidgetItem* child2 = new QTreeWidgetItem(parent1);
    child2->setText(0, "Child 2");
    child2->setText(1, "Value 2");

    QTreeWidgetItem* parent2 = new QTreeWidgetItem(&tree);
    parent2->setText(0, "Parent 2");
    
    QTreeWidgetItem* childA = new QTreeWidgetItem(parent2);
    childA->setText(0, "Child A");
    childA->setText(1, "Value A");

    tree.show();

    return app.exec();
}