// SPDX-FileCopyrightText: 2022 Uniontech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include "daccountstypes.h"
#include <QDateTime>
#include <QUrl>
#include <QObject>

DACCOUNTS_BEGIN_NAMESPACE

class DAccountsUserPrivate;

class DAccountsUser : public QObject
{
    Q_OBJECT

public:
    virtual ~DAccountsUser();

    Q_PROPERTY(AccountTypes accountType READ accountType)
    Q_PROPERTY(bool automaticLogin READ automaticLogin WRITE setAutomaticLogin NOTIFY automaticLoginChanged)
    Q_PROPERTY(QString fullName READ fullName WRITE setFullName)
    Q_PROPERTY(quint64 GID READ GID)
    Q_PROPERTY(quint64 UID READ UID)
    Q_PROPERTY(QStringList groups READ groups WRITE setGroups NOTIFY groupsChanged)
    Q_PROPERTY(QList<QByteArray> layoutList READ layoutList WRITE setLayoutList NOTIFY layoutListChanged)
    Q_PROPERTY(QString homeDir READ homeDir WRITE setHomeDir)
    Q_PROPERTY(QList<QByteArray> iconFileList READ iconFileList NOTIFY iconFileListChanged)
    Q_PROPERTY(QUrl iconFile READ iconFile WRITE setIconFile NOTIFY iconFileChanged)
    Q_PROPERTY(QByteArray layout READ layout WRITE setLayout NOTIFY layoutChanged)
    Q_PROPERTY(QByteArray locale READ locale WRITE setLocale NOTIFY localeChanged)
    Q_PROPERTY(bool locked READ locked WRITE setLocked NOTIFY lockedChanged)
    Q_PROPERTY(qint32 maxPasswordAge READ maxPasswordAge WRITE setMaxPasswordAge NOTIFY maxPasswordAgeChanged)
    Q_PROPERTY(QString passwordHint READ passwordHint WRITE setPasswordHint NOTIFY passwordHintChanged)
    Q_PROPERTY(QDateTime passwordLastChange READ passwordLastChange)
    Q_PROPERTY(PasswdStatus passwordStatus READ passwordStatus)
    Q_PROPERTY(QString shell READ shell WRITE setShell)
    Q_PROPERTY(QByteArray UUID READ UUID)
    Q_PROPERTY(QByteArray userName READ userName)
    Q_PROPERTY(bool noPasswdLogin READ noPasswdLogin WRITE setNopasswdLogin NOTIFY noPasswdLoginChanged)
    Q_PROPERTY(QDateTime loginTime READ loginTime)
    Q_PROPERTY(QDateTime createdTime READ createdTime)

    AccountTypes accountType() const;
    bool automaticLogin() const;
    QString fullName() const;
    quint64 GID() const;
    quint64 UID() const;
    QStringList groups() const;
    QList<QByteArray> layoutList() const;
    QString homeDir() const;
    QList<QByteArray> iconFileList() const;
    QByteArray iconFile() const;
    QByteArray layout() const;
    QByteArray locale() const;
    bool locked() const;
    qint32 maxPasswordAge() const;
    QString passwordHint() const;
    QDateTime passwordLastChange() const;
    PasswdStatus passwordStatus() const;
    QString shell() const;
    QByteArray UUID() const;
    QByteArray userName() const;
    bool noPasswdLogin() const;
    QDateTime loginTime() const;
    QDateTime createdTime() const;

public slots:

    void setAutomaticLogin(const bool enabled);
    void setFullName(const QString &newfullname);
    void setGroups(const QStringList &newgroups);
    void setLayoutList(const QList<QByteArray> &newlayouts);
    void setHomeDir(const QString &newhomedir);
    void setIconFile(const QUrl &newiconURL);
    void setLayout(const QByteArray &newlayout);
    void setLocale(const QByteArray &newlocale);  // TODO:这个方法只能由控制中心调用
    void setLocked(const bool locked);
    void setMaxPasswordAge(const int newndays);
    void setPassword(const QByteArray &newpassword);
    void setPasswordHint(const QString &newpasswordhint);
    void setShell(const QString &newshellpath);
    void setNopasswdLogin(const bool enabled);

    void addGroup(const QString &group);
    void deleteGroup(const QString &group);
    void deleteIconFile(const QUrl &iconURL);
    bool isPasswordExpired() const;
    ReminderInfo getReminderInfo() const;
    PasswdExpirInfo passwordExpirationInfo(qint64 &dayLeft) const;

signals:
    void automaticLoginChanged(const bool enabled);
    void groupsChanged(const QStringList &list);
    void layoutListChanged(const QList<QByteArray> &list);
    void iconFileListChanged(const QList<QByteArray> &list);
    void iconFileChanged(const QUrl &url);
    void layoutChanged(const QByteArray &layout);
    void localeChanged(const QByteArray &locale);
    void lockedChanged(const bool locked);
    void maxPasswordAgeChanged(const qint32 age);
    void passwordHintChanged(const QString &hint);
    void noPasswdLoginChanged(const bool enabled);

private:
    explicit DAccountsUser(const quint64 uid, QObject *parent = nullptr);
    QScopedPointer<DAccountsUserPrivate> d_ptr;
    friend class DAccountsManager;
    Q_DECLARE_PRIVATE(DAccountsUser)
    Q_DISABLE_COPY(DAccountsUser)
};

DACCOUNTS_END_NAMESPACE
