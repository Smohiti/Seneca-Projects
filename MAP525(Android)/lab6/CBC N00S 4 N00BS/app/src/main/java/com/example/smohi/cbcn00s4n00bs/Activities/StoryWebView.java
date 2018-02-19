package com.example.smohi.cbcn00s4n00bs.Activities;

import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Toast;

import com.example.smohi.cbcn00s4n00bs.R;

import butterknife.BindView;
import butterknife.ButterKnife;

public class StoryWebView extends AppCompatActivity {

    private static final String TAG = StoryWebView.class.getSimpleName();
    String url;
    AlertDialog.Builder noNetworkDialog;
    @BindView(R.id.story_detail) WebView detailStoryWebview;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.story_webview);
        //initialising butterknife
        ButterKnife.bind(StoryWebView.this);

        //setting actionbar title and back button.
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setTitle(getIntent().getStringExtra("title"));

        //set progressbar
        final ProgressDialog progressDialog = new ProgressDialog(StoryWebView.this);
        progressDialog.setMessage("Loading your story...");
        progressDialog.show();

        url = getIntent().getStringExtra("url");
        WebSettings settings = detailStoryWebview.getSettings();
        settings.setJavaScriptEnabled(true);
        detailStoryWebview.setScrollBarStyle(WebView.SCROLLBARS_OUTSIDE_OVERLAY);

        final AlertDialog alertDialog = new AlertDialog.Builder(this).create();

        if(MainActivity.isNetworkAvailable(StoryWebView.this)) {
            detailStoryWebview.setWebViewClient(new WebViewClient() {
                public boolean shouldOverrideUrlLoading(WebView view, String url) {
                    view.loadUrl(url);
                    return true;
                }

                public void onPageFinished(WebView view, String url) {
                    super.onPageFinished(view, url);
                    if (url.equals("about:blank") || url == null)
                        Toast.makeText(getApplicationContext(), "result not found", Toast.LENGTH_SHORT).show();
                    progressDialog.dismiss();

                }

                public void onReceivedError(WebView view, int errorCode, String description, String failingUrl) {
                    Log.e(TAG, "Error: " + description);
                    Toast.makeText(getApplicationContext(), "Oh no! " + description, Toast.LENGTH_SHORT).show();
                    alertDialog.setTitle("Error");
                    alertDialog.setMessage(description);
                    alertDialog.setButton("OK", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            return;
                        }
                    });
                    alertDialog.show();
                }
            });
            detailStoryWebview.loadUrl(url);
        }

        else {
            noNetworkDialog = new AlertDialog.Builder(this);
            noNetworkDialog.setTitle("No network");
            noNetworkDialog.setMessage("No internet connection please turn on the internet and come back again");
            noNetworkDialog.setNeutralButton("Ok", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {
                    noNetworkDialog.setCancelable(true);
                    finish();
                }
            });
            noNetworkDialog.show();
        }

    }
}

