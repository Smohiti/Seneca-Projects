package com.example.mareklaskowski.workshop2_summer2017;

import android.graphics.Typeface;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.graphics.Color;
import android.text.Html;

public class ThirdActivity extends AppCompatActivity {

    private String getColoredSpanned(String text, String color) {
        String input = "<font color=" + color + ">" + text + "</font>";
        return input;
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);


        String Data1 = getIntent().getStringExtra("greeting");
        TextView text1 = (TextView) findViewById(R.id.textView);
        text1.setTextColor(Color.RED);
        text1.setTextSize(24);
        text1.setTypeface(null, Typeface.BOLD);

        String Data2 = getIntent().getStringExtra("number");
        String M2 = getColoredSpanned("My Pin Number is: ", "#000000");
        TextView text2 = (TextView) findViewById(R.id.textView2);
        text2.setTextColor(Color.BLUE);
        text2.setTextSize(20);
        text2.setTypeface(null, Typeface.ITALIC);

        TextView text3 = (TextView) findViewById(R.id.textView3);
        String M3 = getColoredSpanned("My Name Is: ", "#000000");
        text3.setTextColor(Color.BLUE);
        text3.setTextSize(20);
        text3.setTypeface(null, Typeface.ITALIC);

        TextView text4 = (TextView) findViewById(R.id.textView4);
        String M4 = getColoredSpanned("My Student ID is: ", "#000000");
        text4.setTextColor(Color.BLUE);
        text4.setTextSize(20);
        text4.setTypeface(null, Typeface.ITALIC);

        Bundle bundle = getIntent().getExtras();
        String Data3 = bundle.getString("MyName");
        String Data4 = bundle.getString("StudentID");

        text1.setText(Data1);
        text2.setText(Html.fromHtml(M2+" "+Data2));
        text3.setText(Html.fromHtml(M3+" "+Data3));
        text4.setText(Html.fromHtml(M4+" "+Data4));


    }
}
