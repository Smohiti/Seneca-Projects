using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_5.Controllers
{
    public class TrackBase
    {
        public TrackBase()
        {
            Name = "";
            Composer = "";

        }
        [Key]
        public int TrackId { get; set; }

        [StringLength(200)]
        [Display(Name = "Track Name")]
        public string Name { get; set; }

        public string Composer { get; set; }

        [Display(Name = "Length (ms)")]
        public int Milliseconds { get; set; }

        [Column(TypeName = "numeric")]
        [Display(Name = "Unit Price")]
        public decimal UnitPrice { get; set; }

    }

    public class TrackWithDetails : TrackBase
    {
        [Required]
        public MediaTypeBase MediaType { get; set; }

        [Display(Name = "Album Title")]
        public string AlbumTitle { get; set; }

        [Display(Name = "Artist Name")]
        public string AlbumArtistName { get; set; }

    }

    public class TrackAdd
    {
        public TrackAdd()
        {
            Name = "";
            Composer = "";

        }

        [StringLength(200)]
        [Display(Name = "Track Name")]
        public string Name { get; set; }

        [Range(1, Int32.MaxValue)]
        [Display(Name = "Album Id")]
        public int? AlbumId { get; set; }


        [Range(1, Int32.MaxValue)]
        [Display(Name = "Media Type Id")]
        public int MediaTypeId { get; set; }

        [StringLength(220)]
        public string Composer { get; set; }

        [Display(Name = "Length (ms)")]
        public int Milliseconds { get; set; }


        [Column(TypeName = "numeric")]
        [Display(Name = "Unit Price")]
        public decimal UnitPrice { get; set; }


    }
    public class TrackAddForm : TrackAdd
    {

        [Display(Name = "Album")]
        public SelectList AlbumList { get; set; }

        [Display(Name = "Media Type")]
        public SelectList MediaTypeList { get; set; }


    }
}