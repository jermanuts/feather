// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2020-2021, The Monero Project.

#ifndef FEATHER_TRANSACTIONINFODIALOG_H
#define FEATHER_TRANSACTIONINFODIALOG_H

#include <QDialog>
#include <QTextCharFormat>
#include <QtSvg/QSvgWidget>
#include "appcontext.h"
#include "dialog/TxProofDialog.h"

namespace Ui {
    class TransactionInfoDialog;
}

class TransactionInfoDialog : public QDialog
{
Q_OBJECT

public:
    explicit TransactionInfoDialog(QSharedPointer<AppContext> ctx, TransactionInfo *txInfo, QWidget *parent = nullptr);
    ~TransactionInfoDialog() override;

signals:
    void resendTranscation(const QString &txid);

private:
    void copyTxKey();
    void createTxProof();
    void setData(TransactionInfo* tx);
    void updateData();

    Ui::TransactionInfoDialog *ui;

    QSharedPointer<AppContext> m_ctx;
    TransactionInfo *m_txInfo;
    TxProofDialog *m_txProofDialog;
    QString m_txKey;
    QString m_txid;
    QTimer m_updateTimer;
};

#endif //FEATHER_TRANSACTIONINFODIALOG_H
