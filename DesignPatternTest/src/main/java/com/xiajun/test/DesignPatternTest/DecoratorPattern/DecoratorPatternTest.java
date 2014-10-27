/**
 * XXX.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 
 * @author xiajun.xj
 * @version $Id: DecoratorPatternTest.java, v 0.1 2014年10月26日 下午5:13:40 xiajun.xj Exp $
 */
public class DecoratorPatternTest {
    public static void main(String[] args) {
        Person person = new Person("小科");

        System.out.println("第一种穿法：");
        AbstractDecorator decorator1 = new AbstractDecorator();

        ConcreteDecoratorTshirt concreteDecoratorTshirt = new ConcreteDecoratorTshirt();
        ConcreteDecoratorBigTrouser concreteDecoratorBigTrouser = new ConcreteDecoratorBigTrouser();
        ConcreteDecoratorShirt concreteDecoratorShirt = new ConcreteDecoratorShirt();

        decorator1.decorate(person);
        concreteDecoratorTshirt.decorate(decorator1);
        concreteDecoratorShirt.decorate(concreteDecoratorTshirt);
        concreteDecoratorBigTrouser.decorate(concreteDecoratorShirt);
        concreteDecoratorBigTrouser.show();
    }
}
