/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.StrategyPattern;

import com.xiajun.test.DesignPatternTest.CashAcceptEnum;

/**
 * 
 * @author xiajun.xj
 * @version $Id: CashAceptTest.java, v 0.1 2014年10月20日 下午10:52:59 xiajun.xj Exp $
 */
public class CashAceptTest {
    public static void main(String[] args) {

        CashAcceptEnum type1 = CashAcceptEnum.CASH_ACCPET_TYPE_NORMAL;
        CashAcceptEnum type2 = CashAcceptEnum.CASH_ACCPET_TYPE_REBATE;
        CashAcceptEnum type3 = CashAcceptEnum.CASH_ACCPET_TYPE_RETURN;

        CashSpuer cashSpuer1 = CashFactory.createCashAccept(type1.getType());
        CashSpuer cashSpuer2 = CashFactory.createCashAccept(type2.getType());
        CashSpuer cashSpuer3 = CashFactory.createCashAccept(type3.getType());

        double money = 300;
        double result1 = cashSpuer1.acceptCash(money);
        double result2 = cashSpuer2.acceptCash(money);
        double result3 = cashSpuer3.acceptCash(money);

        System.out.println(result1);
        System.out.println(result2);
        System.out.println(result3);

    }
}
