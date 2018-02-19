package com.example.mareklaskowski.workshop2_summer2017;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    //handle the button 2 click
    private void a2_button_click_handler(){
        //display a toast for debugging - show the user...
        Toast.makeText(this, "a2 button was clicked", Toast.LENGTH_LONG).show();
        //use an intent to launch our SecondActivity
        //1. create an Intent (in this case implicit)
        Intent a2Intent = new Intent("com.seneca.lab2b.marek"); //TODO: change to your name!
        //2. use the Intent to start the SecondActivity
        //startActivityForResult expects both an Intent and a request code so that you can
        //match up the request with an eventual reply
        startActivityForResult(a2Intent, 1);
    }

    private void a3_button_click_handler(){

        //display a toast for debugging - show the user...
        Toast.makeText(this, "a3 button was clicked", Toast.LENGTH_LONG).show();
        //use an explicit intent to launch our ThirdActivity
        //1. create an Intent (in this case explicit)
        Intent a3Intent = new Intent(this, ThirdActivity.class);
        String Greet = "Good Morning Android!";
        a3Intent.putExtra("greeting", Greet);

        EditText num = (EditText) findViewById(R.id.number);
        String number = num.getText().toString();
        a3Intent.putExtra("number", number);

        EditText nam = (EditText) findViewById(R.id.MyName);
        String name = nam.getText().toString();

        EditText stid = (EditText) findViewById(R.id.StudentID);
        String studid = stid.getText().toString();


        //resultIntent.putExtra("number", number);
        //3. Creat Bundle to pass data
        Bundle bundle = new Bundle();
        bundle.putString("MyName",name);
        bundle.putString("StudentID",studid);
        a3Intent.putExtras(bundle);

        //2. use the Intent to start the ThirdActivity
        startActivity(a3Intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //add code to the button handler for a2_button
        //get a reference to the button
        Button a2_button = (Button) findViewById(R.id.a2_button);
        //set an onclickhandler for the button
        a2_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                a2_button_click_handler();
            }
        });

        //set a button handler for a3_button
        Button a3_button = (Button) findViewById(R.id.a3_button);
        //set an onclickhandler for the button
        a3_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                a3_button_click_handler();
            }
        });
    }

    /*onActivityResult will be called by the Android framework once the activity we started
    with startActivityForResult completes. We are passed the same request code that we passed to
    startActivityForResult and a resultcode that indicates whether the user completed the ACtivity
    or pressed Back to cancel
     */

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        //handler
        if (requestCode == 1){
            //check to see whether the user pressed OK or hit the back button
            if(resultCode == Activity.RESULT_OK){
                //extract the message from the Intent that was returned (data)
                String result = data.getStringExtra("message");
                //set the textView's string to display the message
                TextView text = (TextView) findViewById(R.id.textView1);
                text.setText(result);
            }
        }else{
            Log.e("lab2", "SOMETHING WENT VERY WRONG");
        }
    }
}
