package com.example.smohi.myfavesites_s2017;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.ListView;
import android.widget.Toast;

/*
URL url = new URL("http://www.android.com/");
   HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
   try {
     InputStream in = new BufferedInputStream(urlConnection.getInputStream());
     readStream(in);
   } finally {
     urlConnection.disconnect();
   }
 */

public class MainActivity extends AppCompatActivity {
// declare an array to store refrences to the icons that match up in order with descriptions
    public static int[] icons = {R.drawable.youtube, R.drawable.google, R.drawable.twitter};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // let retrieve the array of description
        String[] description = getResources().getStringArray(R.array.description_array);
// get a refrence to our list view
        ListView listView = (ListView) findViewById(R.id.listView);
        //in rder to set up listview to work properly, we also need t provide
        // a custom arrayadaptor that will use a custom listItem layout
       // instantiate  a myCustomListAadapter
        MyCustomAdapter myCustomAdapter = new MyCustomAdapter(this, description, icons);
        // connect the listview with mycustomarapter
        listView.setAdapter(myCustomAdapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        String data = getResources().getString(R.string.menuHelp);
        // Handle item selection
        switch (item.getItemId()) {
            case R.id.help:

                Toast.makeText(MainActivity.this, data, Toast.LENGTH_LONG).show();
                return true;
            case R.id.about:
                Intent intAbout = new Intent(MainActivity.this,About.class);
                startActivity(intAbout);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }
}
