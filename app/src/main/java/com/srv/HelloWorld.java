package com.srv;

/**
 * Created by cloud on 2016/7/1 11:04.
 * mail：1032863320@qq.com
 */
public class HelloWorld {
    static {
        System.loadLibrary("JUshenziao");   //defaultConfig.ndk.moduleName
    }
    public native String getJNIString();
}
