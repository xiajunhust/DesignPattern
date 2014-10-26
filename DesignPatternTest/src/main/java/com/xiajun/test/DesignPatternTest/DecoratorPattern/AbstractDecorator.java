/**
 * XXX.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 抽象服饰类
 * 
 * @author xiajun.xj
 * @version $Id: AbstractFineryClass.java, v 0.1 2014年10月26日 下午5:07:32 xiajun.xj Exp $
 */
public class AbstractDecorator extends Person {
    private Person component;

    public void decorate(Person component) {
        this.component = component;
    }

    @Override
    public void show() {
        if (component != null) {
            component.show();
        }
    }
}
