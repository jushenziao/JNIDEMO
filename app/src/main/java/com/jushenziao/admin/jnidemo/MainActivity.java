package com.jushenziao.admin.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.srv.HelloWorld;

public class MainActivity extends AppCompatActivity {


    private TextView mTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTextView = (TextView) this.findViewById(R.id.test);

        HelloWorld helloWorld = new HelloWorld();
        String cLanguageString = helloWorld.getJNIString();
        mTextView.setText(cLanguageString);
    }

}
