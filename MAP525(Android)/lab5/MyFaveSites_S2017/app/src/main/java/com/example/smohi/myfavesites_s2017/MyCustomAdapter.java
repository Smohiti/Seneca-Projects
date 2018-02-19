package com.example.smohi.myfavesites_s2017;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

/**
 * This class is a custom adaptor to work with our custom list items and data.
 */

public class MyCustomAdapter extends BaseAdapter {
    //instance variables to store essential data
    String[] descriptions;
    int[] icons;
    Context context;

    //let's write a constructor to set up our instance variables!
    public MyCustomAdapter(MainActivity c, String[] d, int[] i){
        descriptions = d;
        icons = i;
        context = c;
    }

    /*
    called by the framework when it needs to know how many list items there are
     */
    @Override
    public int getCount() {
        return descriptions.length;
    }

    /*
    we don't need this for anything
     */
    @Override
    public Object getItem(int position) {
        return null; //TODO: if you need this for some reason, think of an implementation..
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    /*
    the android framework will call getView every time it needs to draw your custom list item
    int position indicates which row the framework is trying to draw
     */
    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        //create a new View
        View row = null; // a reference that will refer to the current row being drawn

        //we're going to use the LayoutInflater class to instantiate a Java object from the xml layout
        //we get a reference to LayoutInflater through the getSystemService method
        //recall: "context" is our reference to MainActivity which is a context
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        //use the LayoutInflater instance to instantiate a new View of the correct type (custom_list)
        row = inflater.inflate(R.layout.custom_list, null); //note: the second argument is the root view (in this case none)
        //we need to set up the child views that will go into our layout
        //get the TextView and set its text.
        TextView textView = (TextView) row.findViewById(R.id.textView);
        textView.setText(descriptions[position]);
        //get the ImageView and set its image icon
        ImageView imageView = (ImageView) row.findViewById(R.id.imageView);
        imageView.setImageResource(icons[position]);

        //add an oncliscklistener to respond to clicks
        row.setOnClickListener( new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                //TODO: you will broadcast an Intent with a URI to open up the website...
                //URIs will be stored in strings.xml
                Toast.makeText(context, descriptions[position], Toast.LENGTH_LONG).show();
                String[] links = context.getResources().getStringArray(R.array.url_array);
                Uri uri = Uri.parse(links[position]);
                Intent intent;
                intent = new Intent(Intent.ACTION_VIEW, uri);
                context.startActivity(intent);
            }


        });
        return row;

    }


}