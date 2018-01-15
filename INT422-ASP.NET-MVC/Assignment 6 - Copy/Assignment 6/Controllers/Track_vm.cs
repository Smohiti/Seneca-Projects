using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment_6.Controllers
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

        public string FullName
        {
            get
            {
                var ms = Math.Round((((double)Milliseconds / 1000) / 60), 1);

                var composer = string.IsNullOrEmpty(Composer) ? "" : ", composer " + Composer;
                var trackLength = (ms > 0) ? ", " + ms.ToString() + " minutes" : "";
                var unitPrice = (UnitPrice > 0) ? ", $ " + UnitPrice.ToString() : "";

                return string.Format("{0}{1}{2}{3}", Name, composer, trackLength, unitPrice);
            }
        }

        public string Composer { get; set; }

        [Display(Name = "Length (ms)")]
        public int Milliseconds { get; set; }

        [Column(TypeName = "numeric")]
        [Display(Name = "Unit Price")]
        public decimal UnitPrice { get; set; }


    }
}