using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class Track_vm
    {
    }
    public class TrackBase : TrackAdd
    {
        public int Id { get; set; }
    }

    public class TrackAdd
    {
        [Display(Name = "Clerk with Album Privileges")]
        public string Clerk { get; set; }

        [Display(Name = "Composer Name(s)")]
        public string Composers { get; set; }

        [Display(Name = "Track Genre")]
        public string Genre { get; set; }

        public int GenreId { get; set; }

        [Required]
        [Display(Name = "Track Name")]
        public string Name { get; set; }

        [Display(Name = "Album Name")]
        public string AlbumName { get; set; }

    }

    public class TrackAddForm : TrackAdd
    {
        public SelectList GenreList { get; set; }
    }

    public class TrackWithDetail : TrackBase
    {

        public TrackWithDetail()
        {
            Albums = new List<AlbumBase>();
        }

        [Display(Name = "Albums within this track")]
        public IEnumerable<AlbumBase> Albums { get; set; }
    }

    public class TrackEditForm
    {
        public int Id { get; set; }

        public string Composers { get; set; }

        public string Name { get; set; }
    }

    public class TrackEdit
    {
        public int Id { get; set; }

        public string Composers { get; set; }

        [Required]
        public string Name { get; set; }

    }
}