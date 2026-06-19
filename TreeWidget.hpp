#pragma once

#include <QTreeWidget>

class TreeWidget: public QTreeWidget {
    Q_OBJECT
        
public:
    explicit inline TreeWidget(QWidget* parent = nullptr)
        : QTreeWidget(parent)
    {
        this->setColumnCount(2); // Set number of columns
        this->setHeaderLabels({"Name", "Value"});

        this->setDragEnabled(true);
        this->setAcceptDrops(true);
        this->setDropIndicatorShown(true);
        this->setDragDropMode(QAbstractItemView::InternalMove);
        this->setDefaultDropAction(Qt::MoveAction);
        this->setSelectionMode(QAbstractItemView::SingleSelection);
        this->setDragDropOverwriteMode(false); // Important: prevents cell overwrite
    }
};
