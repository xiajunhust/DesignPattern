/**
 * Alipay.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 
 * @author xiajun.xj
 * @version $Id: ConcreteDecoratorTshirt.java, v 0.1 2014年10月26日 下午5:10:53 xiajun.xj Exp $
 */
public class ConcreteDecoratorTshirt extends AbstractDecorator {
    @Override
    public void show() {
        System.out.println("大T恤");
        super.show();
    }
}
