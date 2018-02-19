package com.example.smohi.cbcn00s4n00bs.Activities;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.res.Configuration;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.RecyclerView;

import com.example.smohi.cbcn00s4n00bs.R;
import com.example.smohi.cbcn00s4n00bs.Utils.ReadRssFeeds;

import butterknife.BindView;
import butterknife.ButterKnife;

public class MainActivity extends AppCompatActivity {


    ReadRssFeeds readRssFeeds;
    AlertDialog.Builder noNetworkDialog;

    @BindView(R.id.story_recycler) RecyclerView storyRecycler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().setTitle("CBC N00S 4 N00BS");

        ButterKnife.bind(MainActivity.this);        //initialising butterknife


        if(isNetworkAvailable(MainActivity.this)) {
            readRssFeeds = new ReadRssFeeds(MainActivity.this, storyRecycler);
            readRssFeeds.execute();
        }
        else {

            noNetworkDialog = new AlertDialog.Builder(MainActivity.this);
            noNetworkDialog.setTitle("No network");
            noNetworkDialog.setMessage("No internet connection please turn on the internet and come back again");
            noNetworkDialog.setNeutralButton("Ok", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {
                    finish();
                }
            });
            noNetworkDialog.show();
        }

    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    public static boolean isNetworkAvailable(Context mContext) {
        ConnectivityManager manager = (ConnectivityManager) mContext.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = manager.getActiveNetworkInfo();

        boolean isAvailable = false;
        if (networkInfo != null && networkInfo.isConnected()){
            isAvailable=true;
        }
        return isAvailable;

    }
}
