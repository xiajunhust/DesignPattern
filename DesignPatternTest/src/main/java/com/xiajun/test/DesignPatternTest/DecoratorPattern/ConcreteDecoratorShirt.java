/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 
 * @author xiajun.xj
 * @version $Id: ConcreteDecoratorShirt.java, v 0.1 2014��10��26�� ����5:27:09 xiajun.xj Exp $
 */
public class ConcreteDecoratorShirt extends AbstractDecorator {
    @Override
    public void show() {
        System.out.println("����");
        super.show();
    }
}
