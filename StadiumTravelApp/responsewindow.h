#ifndef RESPONSEWINDOW_H
#define RESPONSEWINDOW_H

#include <QWidget>

enum responseType {
    LEAGUE_SELECT,
    COUNTRY_SELECT,
    LOGIN_FAILED,
    LOGIN_SUCCESSFUL,
    STATE_SELECT,
    PURCHASE,
    PURCHASE_FAILED,
    GRASS_SELECT,
    ADD_CUSTOMER,
    REMOVE_CUSTOMER,
    EDIT_CUSTOMER,
    REMOVE_CUSTOMER_FAIL,
    EDIT_CUSTOMER_FAIL,
    APPROVE_TESTIMONIAL,
    TESTIMONIAL_FAILED,
    DENY_ACCOUNT,
    NO_ITEM_SELECTED,
    ACCOUNT_APPROVED,
    ACCOUNT_APPROVE_FAILED,
    DENY_TESTIMONIAL,
    TESTI_PENDING,
    DELETE_MESSAGE,
    DELETE_FAILED,
    CONTACT_US,
    LINE_BLANK,
    ADD_SUCCESS,
    HELP_ADMIN,
    HELP_USER,
    NON_EXISTING_ACCOUNT,
    ALREADY_EXISTING_ACCOUNT,
    INCOMPLETE_FORM,
    IN_PROGRESS,
};

namespace Ui {
class responseWindow;
}

class responseWindow : public QWidget
{
    Q_OBJECT

public:
    // Default constructor
    explicit responseWindow(QWidget *parent = 0);
    // Non-default constructor
    // Takes in INT to determine the response given to the user
    responseWindow(QWidget *parent, int requestType);
    // Destructor
    ~responseWindow();

private slots:
    // Function triggered when okay button is pressed
    void on_okay_clicked();

private:
    Ui::responseWindow *ui;
};

#endif // RESPONSEWINDOW_H
