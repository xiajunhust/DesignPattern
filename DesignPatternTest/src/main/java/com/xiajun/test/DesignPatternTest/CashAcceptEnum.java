/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest;

/**
 * 
 * @author xiajun.xj
 * @version $Id: CashAcceptEnum.java, v 0.1 2014年10月20日 下午10:38:16 xiajun.xj Exp $
 */
public enum CashAcceptEnum {
    CASH_ACCPET_TYPE_NORMAL(1, "normal cash accept mode"),

    CASH_ACCPET_TYPE_RETURN(2, "return money"),

    CASH_ACCPET_TYPE_REBATE(3, "rebate");

    private int    type;
    private String typeString;

    private CashAcceptEnum(int type, String typeString) {
        this.type = type;
        this.typeString = typeString;

    }

    public static CashAcceptEnum getEnumByCode(int type) {
        CashAcceptEnum[] types = CashAcceptEnum.values();
        for (CashAcceptEnum typeIter : types) {
            if (type == typeIter.getType()) {
                return typeIter;
            }
        }

        return null;
    }

    /**
     * Getter method for property <tt>type</tt>.
     * 
     * @return property value of type
     */
    public int getType() {
        return type;
    }

    /**
     * Getter method for property <tt>typeString</tt>.
     * 
     * @return property value of typeString
     */
    public String getTypeString() {
        return typeString;
    }
}
