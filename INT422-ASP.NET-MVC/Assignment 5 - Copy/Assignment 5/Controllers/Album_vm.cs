using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_5.Controllers
{
    public class AlbumBase
    {
        public AlbumBase()
        {
            Title = "";
        }

        [Key]

        public int AlbumId { get; set; }

        [Display(Name = "Album Title")]
        [StringLength(160)]
        public string Title { get; set; }


    }
}