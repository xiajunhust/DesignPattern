/**
 * XXX.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 
 * @author xiajun.xj
 * @version $Id: Person.java, v 0.1 2014年10月26日 下午5:03:38 xiajun.xj Exp $
 */
public class Person {
    public Person() {

    }

    private String name;

    public Person(String name) {
        this.name = name;
    }

    public void show() {
        System.out.println("装扮的人是：" + name);

    }
}
