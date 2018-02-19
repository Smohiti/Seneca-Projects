package com.example.smohi.cbcn00s4n00bs.Utils;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.AsyncTask;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import jp.wasabeef.recyclerview.adapters.SlideInLeftAnimationAdapter;


public class ReadRssFeeds extends AsyncTask<Void, Void, Void> {

    Context context;
    ProgressDialog progressDialog;
    String rssFeedURL = "http://www.cbc.ca/cmlink/rss-topstories";
    URL url;
    public static final String TAG = ReadRssFeeds.class.getSimpleName();
    ArrayList<StoryDataItem> storyList;
    RecyclerView recyclerView;

    public ReadRssFeeds(Context context, RecyclerView recyclerView){
        this.context = context;
        progressDialog = new ProgressDialog(context);
        progressDialog.setMessage("Loading Stories...");
        this.recyclerView = recyclerView;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
        progressDialog.show();
    }

    @Override
    protected Void doInBackground(Void... voids) {

        //use both helping methods to process feed data
        processXmlDocument(getXmlDocument());

        return null;
    }

    @Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);
        progressDialog.dismiss();

        StoryAdapter storyAdapter = new StoryAdapter(context, storyList);
        recyclerView.setLayoutManager(new LinearLayoutManager(context));

        //animation using library.
        SlideInLeftAnimationAdapter slideAnimator = new SlideInLeftAnimationAdapter(storyAdapter);
        slideAnimator.setFirstOnly(false);
        slideAnimator.setDuration(500);

        recyclerView.setAdapter(slideAnimator);
    }

    //get xml document from url.
    public Document getXmlDocument(){
        try {
            url = new URL(rssFeedURL);
            HttpURLConnection httpURLConnection = (HttpURLConnection) url.openConnection();
            httpURLConnection.setRequestMethod("GET");
            InputStream inputStream = httpURLConnection.getInputStream();
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document xmlDocument = documentBuilder.parse(inputStream);
            return xmlDocument;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    //take xml document as parameter and parse xml data
    public void processXmlDocument(Document xmlDocument) {
        if(xmlDocument!=null){

            storyList = new ArrayList<StoryDataItem>();

            Element rootElement = xmlDocument.getDocumentElement();
            Node channel = rootElement.getChildNodes().item(1);
            NodeList itemTags = channel.getChildNodes();

            for(int i=0; i<itemTags.getLength(); i++){
                Node currentChild = itemTags.item(i);

                if(currentChild.getNodeName().equalsIgnoreCase("item")){
                    NodeList itemChildren = currentChild.getChildNodes();
                    StoryDataItem storyObject = new StoryDataItem();

                    for(int j=0; j<itemChildren.getLength(); j++){
                        Node current = itemChildren.item(j);
                        if(current.getNodeName().equalsIgnoreCase("title")){
                            storyObject.setTitle(current.getTextContent());
                        }

                        else if(current.getNodeName().equalsIgnoreCase("pubDate")){
                            storyObject.setPubDate(current.getTextContent());
                        }
                        else if(current.getNodeName().equalsIgnoreCase("author")){
                            storyObject.setAuthor(current.getTextContent());
                        }
                        else if(current.getNodeName().equalsIgnoreCase("link")){
                            storyObject.setWebViewLink(current.getTextContent());
                        }

                        else if(current.getNodeName().equalsIgnoreCase("description")){
                            String[] imgTag = getMatch
                                    ("<\\s*img\\s*[^>]+src\\s*=\\s*(['\"]?)(.*?)\\1\n",
                                            current.getChildNodes().item(1).getTextContent(), 2).split("  ");
                            Log.d(TAG, "img[0]:"+imgTag[0]);
                            String[] src = imgTag[0].replace("'", "").split(" ");
                            storyObject.setImageSRC(src[0]);
                        }
                    }
                    storyList.add(storyObject);
                }
            }
        }
    }

    //make pattern required
    public static String getMatch(String patternString, String text, int groupIndex){
        Pattern pattern = Pattern.compile(patternString, Pattern.CASE_INSENSITIVE | Pattern.DOTALL );
        return getMatch(pattern, text, groupIndex);
    }

    //use that pattern to extract the src value
    public static String getMatch(Pattern pattern, String text, int groupIndex){
        if(text!=null){
            Matcher matcher = pattern.matcher(text);
            String match = null;
            while(matcher.find()){
                match = matcher.group(groupIndex);
                break;
            }
            return match;
        }else{
            return null;
        }
    }

}

