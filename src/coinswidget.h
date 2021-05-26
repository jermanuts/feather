// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2020-2021, The Monero Project.

#ifndef FEATHER_COINSWIDGET_H
#define FEATHER_COINSWIDGET_H

#include "appcontext.h"
#include "model/CoinsModel.h"
#include "model/CoinsProxyModel.h"
#include "libwalletqt/Coins.h"

#include <QMenu>
#include <QWidget>
#include <QtSvg/QSvgWidget>

namespace Ui {
    class CoinsWidget;
}

class CoinsWidget : public QWidget
{
Q_OBJECT

public:
    explicit CoinsWidget(QSharedPointer<AppContext> ctx, QWidget *parent = nullptr);
    void setModel(CoinsModel * model, Coins * coins);
    ~CoinsWidget() override;

private slots:
    void showHeaderMenu(const QPoint& position);
    void setShowSpent(bool show);
    void freezeOutput();
    void freezeAllSelected();
    void thawOutput();
    void thawAllSelected();
    void viewOutput();
    void onSweepOutput();

private:
    void freezeCoins(const QVector<int>& indexes);
    void thawCoins(const QVector<int>& indexes);

    enum copyField {
        PubKey = 0,
        KeyImage,
        TxID,
        Address,
        Label,
        Height,
        Amount
    };

    Ui::CoinsWidget *ui;
    QSharedPointer<AppContext> m_ctx;

    QMenu *m_contextMenu;
    QMenu *m_headerMenu;
    QMenu *m_copyMenu;
    QAction *m_showSpentAction;
    QAction *m_freezeOutputAction;
    QAction *m_freezeAllSelectedAction;
    QAction *m_thawOutputAction;
    QAction *m_thawAllSelectedAction;
    QAction *m_viewOutputAction;
    QAction *m_sweepOutputAction;
    Coins *m_coins;
    CoinsModel * m_model;
    CoinsProxyModel * m_proxyModel;

    void showContextMenu(const QPoint & point);
    void copy(copyField field);
    CoinsInfo* currentEntry();
};


#endif //FEATHER_COINSWIDGET_H
