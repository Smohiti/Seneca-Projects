using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_5.Controllers
{
    public class ArtistBase
    {
        public ArtistBase()
        {
            Name = "";
        }
        [Key]
        public int ArtistId { get; set; }

        [Display(Name = "Artist Name")]
        [StringLength(120)]
        public string Name { get; set; }
    }
}