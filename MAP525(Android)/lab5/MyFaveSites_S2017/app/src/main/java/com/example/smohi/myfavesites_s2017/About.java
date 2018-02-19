package com.example.smohi.myfavesites_s2017;

import android.graphics.Color;
import android.graphics.Typeface;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Html;
import android.widget.ImageView;
import android.widget.TextView;

public class About extends AppCompatActivity {

    private String getColoredSpanned(String text, String color) {
        String input = "<font color=" + color + ">" + text + "</font>";
        return input;
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_about);


        TextView text2 = (TextView) findViewById(R.id.textView2);
        String M4 = getColoredSpanned("M.Saeed Mohiti ", "#FF0000");
        text2.setTextSize(20);
        text2.setTypeface(null, Typeface.ITALIC);
        text2.setText(Html.fromHtml(M4));

        ImageView imageView = (ImageView) findViewById(R.id.imageView2);
        imageView.setImageResource(R.drawable.saeed);
    }
}
