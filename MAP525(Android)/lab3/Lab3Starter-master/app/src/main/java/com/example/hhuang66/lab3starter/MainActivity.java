package com.example.hhuang66.lab3starter;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final AutoCompleteTextView ViewText = (AutoCompleteTextView) findViewById(R.id.autoCompleteTextView);
        final ArrayList<String> data = new ArrayList<String>();

        TextView textView = new TextView(this);
        textView.setText("hello world");
        Button button = (Button)findViewById(R.id.button);

        LinearLayout linearLayout = (LinearLayout) findViewById(R.id.activity_main);
        //LayoutParams is a class to specify layout properties when adding a view to a layout
        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT);
        linearLayout.addView(textView, layoutParams);

        //TODO: change things so that TextViews are added in response to button clicks
        //TODO: populate the AutoCompleteTextView using an ArrayAdapter for String arrays
        //declare an array to provide data through the array adaptor to our ListView
        final ArrayAdapter<String> sAdapter = new ArrayAdapter<String>(getApplicationContext(), R.layout.list_item, data);

        String[] vocabulary = {"activity","AVD","ART","Dalvik","intent","intnent filter"
                ,"explicit intent","implicit intent","LogCat","bundle","Gradle",
                "Android Device Monitor","SDK manager","minSdkVersion"};
        /*
        create an ArrayAdapter for an array of Strings
        the constructor for ArrayAdapter requires a "sample list item" layout
        make sure you have one created in res/layout
        (Context, sample_layout_id, array)
         */
         ArrayAdapter<String> adapter =
                new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, vocabulary);
        ViewText.setAdapter(adapter);

        button.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                String Message = ViewText.getText().toString();
                data.add(Message);
                sAdapter.notifyDataSetChanged();
                //get a reference to the ListView
                ListView listView = (ListView) findViewById(R.id.listView);
                //set the adapter for listView to use our ArrayAdpter "sAdpater"
                listView.setAdapter(sAdapter);

        //assoiciate the listener we create above with our listView
       // listView.setOnItemClickListener(myMessageClickHandler);
            }
        });
    }
}
