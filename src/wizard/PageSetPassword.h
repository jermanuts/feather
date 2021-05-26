// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2020-2021, The Monero Project.

#ifndef FEATHER_PASSWORD_H
#define FEATHER_PASSWORD_H

#include <QWizardPage>
#include <QWidget>

#include "appcontext.h"
#include "WalletWizard.h"

namespace Ui {
    class PageSetPassword;
}

class PageSetPassword : public QWizardPage
{
Q_OBJECT

public:
    explicit PageSetPassword(WizardFields *fields, QWidget *parent = nullptr);
    void initializePage() override;
    bool validatePage() override;
    int nextId() const override;
    bool isComplete() const override;

signals:
    void createWallet();

private:
    Ui::PageSetPassword *ui;

    WizardFields *m_fields;
};


#endif //FEATHER_PASSWORD_H
