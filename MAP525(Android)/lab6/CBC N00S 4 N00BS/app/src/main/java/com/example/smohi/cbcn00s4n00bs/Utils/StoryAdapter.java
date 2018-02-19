package com.example.smohi.cbcn00s4n00bs.Utils;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.smohi.cbcn00s4n00bs.Activities.StoryWebView;
import com.example.smohi.cbcn00s4n00bs.R;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class StoryAdapter extends RecyclerView.Adapter<StoryAdapter.StoryViewHolder> {

    private static final String TAG = StoryAdapter.class.getSimpleName();
    ArrayList<StoryDataItem> stories;
    Context context;

    public StoryAdapter(Context context, ArrayList<StoryDataItem> stories){
        this.stories = stories;
        this.context = context;
    }

    @Override
    public StoryAdapter.StoryViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.story_items_list, parent, false);
        return new StoryViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(StoryViewHolder holder, int position) {

        String authorName = stories.get(position).getAuthor();
        String title = stories.get(position).getTitle();
        String pubDate = stories.get(position).getPubDate();
        String imgSrc = stories.get(position).getImageSRC();

        holder.author.setText(authorName);
        holder.pubDate.setText(pubDate);
        holder.title.setText(title);

        if(imgSrc!=null)
        Picasso.with(holder.storyImage.getContext())
                .load(imgSrc).into(holder.storyImage);

        else
            Picasso.with(holder.storyImage.getContext()).load(R.mipmap.ic_launcher).into(holder.storyImage);
    }

    @Override
    public int getItemCount() {
        return stories.size();
    }

    class StoryViewHolder extends RecyclerView.ViewHolder{
        @BindView(R.id.title) TextView title;
        @BindView(R.id.pub_date) TextView pubDate;
        @BindView(R.id.author) TextView author;
        @BindView(R.id.story_image) ImageView storyImage;
        @BindView(R.id.list_item) ViewGroup listItem;


        public StoryViewHolder(View itemView) {
            super(itemView);
            ButterKnife.bind(this, itemView);
        }

        @OnClick (R.id.list_item) void goToWebView(View view){
            Intent intent = new Intent(new Intent(itemView.getContext(), StoryWebView.class));
            intent.putExtra("url", stories.get(getAdapterPosition()).getWebViewLink());
            intent.putExtra("author", stories.get(getAdapterPosition()).getAuthor());
            itemView.getContext().startActivity(intent);
        }
    }
}

