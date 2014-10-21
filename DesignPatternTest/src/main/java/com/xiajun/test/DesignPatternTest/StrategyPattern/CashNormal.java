/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.StrategyPattern;

/**
 * Concrete class : how to accpet cash in normal scenario
 * 
 * @author xiajun.xj
 * @version $Id: CashNormal.java, v 0.1 2014年10月20日 下午10:18:27 xiajun.xj Exp $
 */
public class CashNormal extends CashSpuer {

    /** 
     * @see com.xiajun.test.DesignPatternTest.StrategyPattern.CashSpuer#acceptCash(double)
     */
    @Override
    public double acceptCash(double money) {
        return money;
    }

}
