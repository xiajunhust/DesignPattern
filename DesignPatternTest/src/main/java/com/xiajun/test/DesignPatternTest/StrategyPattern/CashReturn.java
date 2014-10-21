/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.StrategyPattern;

/**
 * concrete class : how to accept cash when choose return money way for sales promotion
 * 
 * @author xiajun.xj
 * @version $Id: CashReturn.java, v 0.1 2014年10月20日 下午10:27:23 xiajun.xj Exp $
 */
public class CashReturn extends CashSpuer {

    //default value
    private final static double MONEY_CONDITION = 200;
    private final static double MONEY_RETURN    = 20;

    private final double        moneyCondition;
    private final double        moneyReturn;

    public CashReturn() {
        this.moneyCondition = MONEY_CONDITION;
        this.moneyReturn = MONEY_RETURN;
    }

    public CashReturn(double moneyCondition, double moneyReturn) {
        this.moneyCondition = moneyCondition;
        this.moneyReturn = moneyReturn;
    }

    /** 
     * @see com.xiajun.test.DesignPatternTest.StrategyPattern.CashSpuer#acceptCash(double)
     */
    @Override
    public double acceptCash(double money) {
        double result = money;

        if (money >= moneyCondition) {
            result -= Math.floor(money / moneyCondition) * moneyReturn;
        }
        return result;
    }

}
