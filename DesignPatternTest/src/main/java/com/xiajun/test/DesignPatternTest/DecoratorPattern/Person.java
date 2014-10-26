/**
 * XXX.com Inc.
 * Copyright (c) 2004-2014 All Rights Reserved.
 */
package com.xiajun.test.DesignPatternTest.DecoratorPattern;

/**
 * 
 * @author xiajun.xj
 * @version $Id: Person.java, v 0.1 2014��10��26�� ����5:03:38 xiajun.xj Exp $
 */
public class Person {
    public Person() {

    }

    private String name;

    public Person(String name) {
        this.name = name;
    }

    public void show() {
        System.out.println("װ������ǣ�" + name);

    }
}
