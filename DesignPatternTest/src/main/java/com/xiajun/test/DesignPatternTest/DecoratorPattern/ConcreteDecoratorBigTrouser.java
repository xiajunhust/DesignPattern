/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 
 * @author xiajun.xj
 * @version $Id: ConcreteDecoratorBigTrouser.java, v 0.1 2014��10��26�� ����5:12:43 xiajun.xj Exp $
 */
public class ConcreteDecoratorBigTrouser extends AbstractDecorator {
    @Override
    public void show() {
        System.out.println("���");
        super.show();
    }
}
