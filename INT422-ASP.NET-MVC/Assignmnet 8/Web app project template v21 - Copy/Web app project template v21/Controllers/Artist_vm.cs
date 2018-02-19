using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class Artist_vm
    {
    }

    public class ArtistBase : ArtistAdd
    {
        public int Id { get; set; }
    }

    public class ArtistAdd
    {

        public ArtistAdd()
        {
            BirthOrStartDate = DateTime.Now;
        }

        [Display(Name = "Artist's birth name (if applicable)")]
        public string BirthName { get; set; }

        [Display(Name = "Birth/Start Date")]
        public DateTime BirthOrStartDate { get; set; }

        public string Executive { get; set; }

        [Display(Name = "Artist Genre")]
        public string Genre { get; set; }

        public int GenreId { get; set; }

        [Required]
        [Display(Name = "Artist Name")]
        public string Name { get; set; }

        [Display(Name = "Artist Picture")]
        public string UrlArtist { get; set; }


        public int AlbumsCount { get; set; }
    }

    public class ArtistAddForm : ArtistAdd
    {
        public SelectList GenreList { get; set; }
    }

    public class ArtistWithDetail : ArtistBase
    {

        public ArtistWithDetail()
        {
            Albums = new List<AlbumBase>();
        }
        public IEnumerable<AlbumBase> Albums { get; set; }
    }
}