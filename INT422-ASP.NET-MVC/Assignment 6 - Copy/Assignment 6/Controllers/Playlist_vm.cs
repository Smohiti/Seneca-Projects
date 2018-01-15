using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_6.Controllers
{
    public class PlaylistBase
    {
        public PlaylistBase()
        {
            Name = "";
        }
        [Key]
        public int PlaylistId { get; set; }

        [Display(Name = "Playlist name")]
        [StringLength(120)]
        public string Name { get; set; }

        [Display(Name = "Number of tracks on this playlist")]
        public int TracksCount { get; set; }
    }

    public class PlaylistWithTracks : PlaylistBase
    {
        public PlaylistWithTracks()
        {
            Tracks = new List<TrackBase>();
        }
        [Display(Name = "Tracks now on the Playlist")]
        public IEnumerable<TrackBase> Tracks { get; set; }
    }

    public class PlaylistEditTracksForm
    {
        public PlaylistEditTracksForm()
        {
            Tracks = new List<TrackBase>();
            Name = "";
        }
        [Key]
        public int PlaylistId { get; set; }

        [StringLength(120)]
        public string Name { get; set; }
        public int TracksCount { get; set; }

        public IEnumerable<TrackBase> Tracks { get; set; }

        public MultiSelectList TrackList { get; set; }
    }

    public class PlaylistEditTracks
    {
        public PlaylistEditTracks()
        {
            TrackIds = new List<int>();
        }
        [Key]
        public int PlaylistId { get; set; }

        public IEnumerable<int> TrackIds { get; set; }

    }
}