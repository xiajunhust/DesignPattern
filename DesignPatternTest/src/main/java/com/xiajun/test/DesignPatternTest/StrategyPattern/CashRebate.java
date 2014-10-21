/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.StrategyPattern;

/**
 * concrete class : how to accept cash when needs to rebate
 * 
 * @author xiajun.xj
 * @version $Id: CashRebate.java, v 0.1 2014年10月20日 下午10:21:16 xiajun.xj Exp $
 */
public class CashRebate extends CashSpuer {

    //rebate ratio default value
    private final static double MONEY_REATE_RATIO_DEFAULT = 0.8;

    //rebate ratio 
    private final double        moneyRebateRatio;

    public CashRebate() {
        this.moneyRebateRatio = MONEY_REATE_RATIO_DEFAULT;
    }

    public CashRebate(double moneyRebateRatio) {
        this.moneyRebateRatio = moneyRebateRatio;
    }

    /** 
     * @see com.xiajun.test.DesignPatternTest.StrategyPattern.CashSpuer#acceptCash(double)
     */
    @Override
    public double acceptCash(double money) {
        return money * this.moneyRebateRatio;
    }

}
