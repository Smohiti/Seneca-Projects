package com.example.mareklaskowski.workshop2_summer2017;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class SecondActivity extends AppCompatActivity {

    private void ok_button_click_handler(){
        //compose a reply to send back to MainActivity
        //use an Intent to store the reply
        Intent resultIntent = new Intent(); //empty for now

        //get the text that the user entered into the text box
        EditText editText = (EditText) findViewById(R.id.editText);
        //extract the text from the editText
        String message = editText.getText().toString();
        //add an extra data to the Intent
        resultIntent.putExtra("message", message);
        //this next line is only needed if you are returning a result to the calling activity
        setResult(Activity.RESULT_OK, resultIntent);
        //end SecondActivity
        finish();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        Button ok_button = (Button) findViewById(R.id.ok_button);
        //set an onclickhandler for the button
        ok_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ok_button_click_handler();
            }
        });
    }
}
