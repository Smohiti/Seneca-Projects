using Assignment_3.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_3.Controllers
{

    public class TrackBase
    {
        public int TrackId { get; set; }

        [Required]
        [StringLength(250)]
        [Display(Name = "Track name")]
        public string Name { get; set; }
        [Display(Name = "Album identifier")]
        public int? AlbumId { get; set; }
        [Display(Name = "Media type Id")]
        public int MediaTypeId { get; set; }
        [Display(Name = "Gener identifier")]
        public int? GenreId { get; set; }
        [Display(Name = "Composer name(s)")]
        [StringLength(250)]
        public string Composer { get; set; }
        [Display(Name = "Track length in milliseconds")]
        public int Milliseconds { get; set; }

        public int? Bytes { get; set; }
        [Display(Name = "Selling price")]
        public decimal UnitPrice { get; set; }






    }
}