/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.StrategyPattern;

/**
 * Factory class for accept cash
 * 
 * @author xiajun.xj
 * @version $Id: CashFactory.java, v 0.1 2014年10月20日 下午10:33:21 xiajun.xj Exp $
 */
public class CashFactory {
    public static CashSpuer createCashAccept(int type) {
        CashSpuer cs = null;

        switch (type) {
            case 1:
                cs = new CashNormal();
                break;

            case 2:
                cs = new CashReturn();
                break;

            case 3:
                cs = new CashRebate();
                break;

            default:
                break;
        }
        return cs;
    }
}
