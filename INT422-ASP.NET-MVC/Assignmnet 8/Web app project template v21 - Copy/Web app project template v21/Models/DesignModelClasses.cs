using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using System.ComponentModel.DataAnnotations;

namespace Web_app_project_template_v21.Models

    // Add your design model classes below

    // Follow these rules or conventions:

    // To ease other coding tasks, the name of the 
    //   integer identifier property should be "Id"
    // Collection properties (including navigation properties) 
    //   must be of type ICollection<T>
    // Valid data annotations are pretty much limited to [Required] and [StringLength(n)]
    // Required to-one navigation properties must include the [Required] attribute
    // Do NOT configure scalar properties (e.g. int, double) with the [Required] attribute
    // Initialize DateTime and collection properties in a default constructor

{
    public partial class Album
    {
        public Album()
        {
            Tracks = new HashSet<Track>();
            Artists = new HashSet<Artist>();
        }

        public string Coordinator { get; set; }

        public string Genre { get; set; }

        public int Id { get; set; }

        [Required]
        public string Name { get; set; }

        public DateTime ReleaseDate { get; set; }

        public string UrlAlbum { get; set; }

        public virtual ICollection<Track> Tracks { get; set; }

        public virtual ICollection<Artist> Artists { get; set; }
    }

    public class Artist
    {
        public Artist()
        {
            Albums = new HashSet<Album>();
        }

        public string BirthName { get; set; }

        public DateTime BirthOrStartDate { get; set; }

        public string Executive { get; set; }


        public string Genre { get; set; }

        public int Id { get; set; }

        [Required]
        public string Name { get; set; }

        public string UrlArtist { get; set; }

        public virtual ICollection<Album> Albums { get; set; }
    }

    public class Track
    {
        public Track()
        {
            Albums = new HashSet<Album>();
        }

        public string Clerk { get; set; }

        public string Composers { get; set; }

        public string Genre { get; set; }


        public int Id { get; set; }

        [Required]
        public string Name { get; set; }

        public virtual ICollection<Album> Albums { get; set; }
    }

    public class Genre
    {
        public int Id { get; set; }

        public string Name { get; set; }
    }

    public class RoleClaim
    {
        public int Id { get; set; }

        [Required, StringLength(100)]
        public string Name { get; set; }
    }

}
