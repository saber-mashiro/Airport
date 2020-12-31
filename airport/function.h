#ifndef FUNCTION_H
#define FUNCTION_H

   #include <QTextStream>
class function
{
public:
    function();
    //passenger
    void bookTicket();//订票
    void refundTicket();//退票
    void checkTicket();//查询自己的订票
    void checkFinalstation();//订票查询目的地
    //planes
    void showPlanes();//显示所有航班信息
    void upData();//修改某航班信息
    void showPassenger();//显示所有乘客信息
};

#endif // FUNCTION_H
