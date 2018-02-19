using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class Album_vm
    {
    }
    public class AlbumBase : AlbumAdd
    {
        public int Id { get; set; }
    }

    public class AlbumAdd
    {
        public AlbumAdd()
        {
            ReleaseDate = DateTime.Now;
        }

        [Display(Name = "Album Coordinator")]
        public string Coordinator { get; set; }

        [Display(Name = "Album's Genre")]
        public string Genre { get; set; }

        public int GenreId { get; set; }

        [Required]
        [Display(Name = "Album Name")]
        public string Name { get; set; }

        [Display(Name = "Release Date")]
        public DateTime ReleaseDate { get; set; }

        [Display(Name = "Cover Image")]
        public string UrlAlbum { get; set; }

        public IEnumerable<int> TrackIds { get; set; }

        public IEnumerable<int> ArtistIds { get; set; }
    }

    public class AlbumAddForm : AlbumAdd
    {
        public string ArtistName { get; set; }

        public SelectList GenreList { get; set; }

        public MultiSelectList TrackList { get; set; }

        public MultiSelectList ArtistList { get; set; }
    }

    public class AlbumWithDetail : AlbumBase
    {
        public AlbumWithDetail()
        {
            Tracks = new List<TrackBase>();
            Artists = new List<ArtistBase>();
        }

        public IEnumerable<String> ArtistNames { get; set; }

        public IEnumerable<ArtistBase> Artists { get; set; }

        public IEnumerable<TrackBase> Tracks { get; set; }
    }
}