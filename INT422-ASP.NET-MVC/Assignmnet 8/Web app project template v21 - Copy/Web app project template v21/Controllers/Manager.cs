using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Web_app_project_template_v21.Models;
using System.Security.Claims;

namespace Web_app_project_template_v21.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private ApplicationDbContext ds = new ApplicationDbContext();

        // Request user property...

        // Backing field for the property
        private RequestUser _user;

        // Getter only, no setter
        public RequestUser User
        {
            get
            {
                // On first use, it will be null, so set its value
                if (_user == null)
                {
                    _user = new RequestUser(HttpContext.Current.User as ClaimsPrincipal);
                }
                return _user;
            }
        }

        // Default constructor...
        public Manager()
        {
            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;

            // If necessary, add constructor code here


        }

        // RoleClaim

        public List<string> RoleClaimGetAllStrings()
        {
            return ds.RoleClaims.OrderBy(r => r.Name).Select(r => r.Name).ToList();
        }

        //Load Data

        public bool LoadData()
        {
            // User name
            var user = HttpContext.Current.User.Identity.Name;

            // Monitor the progress
            bool done = false;

            // ############################################################
            // Role claims

            if (ds.RoleClaims.Count() == 0)
            {
                // Add role claims here

                ds.RoleClaims.Add(new RoleClaim { Name = "Executive" });
                ds.RoleClaims.Add(new RoleClaim { Name = "Coordinator" });
                ds.RoleClaims.Add(new RoleClaim { Name = "Clerk" });
                ds.RoleClaims.Add(new RoleClaim { Name = "Staff" });

                ds.SaveChanges();
                done = true;
            }

            //Genres

            if (ds.Genres.Count() == 0)
            {

                ds.Genres.Add(new Genre { Name = "Classical" });
                ds.Genres.Add(new Genre { Name = "Jazz" });
                ds.Genres.Add(new Genre { Name = "Hip Hop" });
                ds.Genres.Add(new Genre { Name = "Romance" });
                ds.Genres.Add(new Genre { Name = "Punk" });
                ds.Genres.Add(new Genre { Name = "Country" });
                ds.Genres.Add(new Genre { Name = "Reggae" });
                ds.Genres.Add(new Genre { Name = "Pop" });
                ds.Genres.Add(new Genre { Name = "Electronic" });
                ds.Genres.Add(new Genre { Name = "Blues" });

                ds.SaveChanges();
                done = true;
            }

            //Artists

            if (ds.Artists.Count() == 0)
            {

                ds.Artists.Add(new Artist
                {
                    Name = "Ed Sheeran",
                    BirthName = "Edward Christopher Sheeran",
                    Genre = "Romantic",
                    UrlArtist = "https://upload.wikimedia.org/wikipedia/commons/5/55/Ed_Sheeran_2013.jpg",
                    BirthOrStartDate = new DateTime(1991, 2, 17),
                    Executive = "exec@example.com"
                });

                ds.Artists.Add(new Artist
                {
                    Name = "The Chainsmokers",
                    BirthName = "Andrew Taggart and Alex Pall",
                    Genre = "Electronic",
                    UrlArtist = "https://upload.wikimedia.org/wikipedia/commons/e/ea/The_Chainsmokers_VELD_2016.jpg",
                    BirthOrStartDate = new DateTime(1985, 1, 1),
                    Executive = "exec@example.com"
                });

                ds.Artists.Add(new Artist
                {
                    Name = "Bruno Mars",
                    BirthName = "Peter Gene Hernande",
                    Genre = "Pop",
                    UrlArtist = "https://upload.wikimedia.org/wikipedia/commons/f/fa/Bruno_Mars%2C_Las_Vegas_2010.jpg",
                    BirthOrStartDate = new DateTime(1985, 8, 10),
                    Executive = "exec@example.com"
                });

                ds.SaveChanges();
                done = true;
            }

            //Albums

            if (ds.Albums.Count() == 0)
            {

                var chainsmokers = ds.Artists.SingleOrDefault(a => a.Name == "The Chainsmokers");
                var sheeran = ds.Artists.SingleOrDefault(a => a.Name == "Ed Sheeran");
                var bruno = ds.Artists.SingleOrDefault(a => a.Name == "Bruno Mars");

                ds.Albums.Add(new Album
                {
                    Name = "Bouquet",
                    Genre = "Electronic",
                    Coordinator = "coord@example.com",
                    ReleaseDate = new DateTime(2015, 10, 23),
                    UrlAlbum = "https://upload.wikimedia.org/wikipedia/en/c/c4/Bouquet_EP_cover_art.jpg",
                    Artists = new List<Artist> { chainsmokers }
                });

                ds.Albums.Add(new Album
                {
                    Name = "Memories...Do Not Open",
                    Genre = "Electronic",
                    Coordinator = "coord@example.com",
                    ReleaseDate = new DateTime(2017, 4, 7),
                    UrlAlbum = "https://upload.wikimedia.org/wikipedia/en/5/51/Memories...Do_Not_Open.jpg",
                    Artists = new List<Artist> { chainsmokers }
                });

                ds.Albums.Add(new Album
                {
                    Name = "÷",
                    Genre = "Romantic",
                    Coordinator = "coord@example.com",
                    ReleaseDate = new DateTime(2017, 3, 3),
                    UrlAlbum = "https://upload.wikimedia.org/wikipedia/en/4/45/Divide_cover.png",
                    Artists = new List<Artist> { sheeran }
                });

                ds.SaveChanges();
                done = true;
            }

            if (ds.Tracks.Count() == 0)
            {
                var BOU = ds.Albums.SingleOrDefault(a => a.Name == "Bouquet");
                var MDNO = ds.Albums.SingleOrDefault(a => a.Name == "Memories...Do Not Open");
                var DIV = ds.Albums.SingleOrDefault(a => a.Name == "÷");

                ds.Tracks.Add(new Track
                {
                    Name = "Roses",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { BOU }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "New York City",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { BOU }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Until You Were Gone",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { BOU }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Waterbed",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { BOU }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Good Intentions",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { BOU }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "The One",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { MDNO }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Break Up Every Night",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { MDNO }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Bloodstream",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { MDNO }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Don't Say",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { MDNO }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Something Just Like This",
                    Genre = "Electronic",
                    Clerk = "clerk@example.com",
                    Composers = "The Chainsmokers",
                    Albums = new List<Album> { MDNO }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Castle on the Hill",
                    Genre = "Romantic",
                    Clerk = "clerk@example.com",
                    Composers = "Ed Sheeran",
                    Albums = new List<Album> { DIV }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Shape of You",
                    Genre = "Romantic",
                    Clerk = "clerk@example.com",
                    Composers = "Ed Sheeran",
                    Albums = new List<Album> { DIV }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Galway Girl",
                    Genre = "Romantic",
                    Clerk = "clerk@example.com",
                    Composers = "Ed Sheeran",
                    Albums = new List<Album> { DIV }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "How Would You Feel (Paean)",
                    Genre = "Romantic",
                    Clerk = "clerk@example.com",
                    Composers = "Ed Sheeran",
                    Albums = new List<Album> { DIV }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Supermarket Flowers",
                    Genre = "Romantic",
                    Clerk = "clerk@example.com",
                    Composers = "Ed Sheeran",
                    Albums = new List<Album> { DIV }
                });

                ds.SaveChanges();
                done = true;
            }
            return done;
        }

        //Remove Data

        public bool RemoveData()
        {
            try
            {
                foreach (var e in ds.RoleClaims)
                {
                    ds.Entry(e).State = System.Data.Entity.EntityState.Deleted;
                }
                ds.SaveChanges();

                //Remove the whole table

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        //Remove Database

        public bool RemoveDatabase()
        {
            try
            {
                return ds.Database.Delete();
            }
            catch (Exception)
            {
                return false;
            }
        }

        //Rest of the Methods

        /*Genre*/

        public IEnumerable<GenreBase> GenreGetAll()
        {
            return Mapper.Map<IEnumerable<Genre>, IEnumerable<GenreBase>>(ds.Genres.OrderBy(g => g.Name));
        }

        /*Album*/

        public IEnumerable<AlbumBase> AlbumGetAll()
        {
            return Mapper.Map<IEnumerable<Album>, IEnumerable<AlbumBase>>(ds.Albums.OrderBy(a => a.Name));
        }

        public AlbumWithDetail AlbumGetByIdWithDetail(int id)
        {
            var o = ds.Albums.Include("Artists").Include("Tracks").SingleOrDefault(a => a.Id == id);
            if (o == null)
            {
                return null;
            }
            else
            {


                var result = Mapper.Map<Album, AlbumWithDetail>(o);


                result.ArtistNames = o.Artists.Select(a => a.Name);
                return result;
            }
        }

        public AlbumBase AlbumAdd(AlbumAdd newItem)
        {


            var addedItem = ds.Albums.Add(Mapper.Map<AlbumAdd, Album>(newItem));
            var findGenre = ds.Genres.Find(newItem.GenreId);

            foreach (var item in newItem.TrackIds)
            {
                var a = ds.Tracks.Find(item);
                addedItem.Tracks.Add(a);
            }

            foreach (var item in newItem.ArtistIds)
            {
                var a = ds.Artists.Find(item);
                addedItem.Artists.Add(a);
            }


            addedItem.Genre = findGenre.Name;
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<Album, AlbumBase>(addedItem);
        }

        /*Artist*/

        public IEnumerable<ArtistBase> ArtistGetAll()
        {
            return Mapper.Map<IEnumerable<Artist>, IEnumerable<ArtistBase>>(ds.Artists.OrderBy(a => a.Name));
        }

        public ArtistWithDetail ArtistGetByIdWithDetail(int id)
        {
            var obj = ds.Artists.Include("Albums")
                .SingleOrDefault(a => a.Id == id);

            return Mapper.Map<Artist, ArtistWithDetail>(obj);
        }

        public ArtistBase ArtistAdd(ArtistAdd newItem)
        {


            var addedItem = ds.Artists.Add(Mapper.Map<ArtistAdd, Artist>(newItem));
            var findGenre = ds.Genres.Find(newItem.GenreId);


            addedItem.Genre = findGenre.Name;
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<Artist, ArtistBase>(addedItem);
        }

        /*Track*/

        public IEnumerable<TrackBase> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.OrderBy(a => a.Name));
        }

        public TrackWithDetail TrackGetByIdWithDetail(int id)
        {
            var o = ds.Tracks.Include("Albums.Artists").SingleOrDefault(t => t.Id == id);

            return (o == null) ? null : Mapper.Map<Track, TrackWithDetail>(o);

        }

        public TrackBase TrackAdd(TrackAdd newItem)
        {

            var addedItem = ds.Tracks.Add(Mapper.Map<TrackAdd, Track>(newItem));
            var findGenre = ds.Genres.Find(newItem.GenreId);

            addedItem.Genre = findGenre.Name;
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<Track, TrackBase>(addedItem);
        }

        public TrackWithDetail TrackEdit(TrackEdit newItem)
        {
            var o = ds.Tracks.Include("Albums")
                .SingleOrDefault(v => v.Id == newItem.Id);

            if (o == null)
            {
                return null;
            }
            else
            {
                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();

                return Mapper.Map<Track, TrackWithDetail>(o);
            }
        }

        public bool TrackDelete(int id)
        {
            var itemToDelete = ds.Tracks.Find(id);

            if (itemToDelete == null)
            {
                return false;
            }
            else
            {
                // Remove the object
                ds.Tracks.Remove(itemToDelete);
                ds.SaveChanges();

                return true;
            }
        }


    }



    // Request User

    public class RequestUser
    {
        // Constructor, pass in the security principal
        public RequestUser(ClaimsPrincipal user)
        {
            if (HttpContext.Current.Request.IsAuthenticated)
            {
                Principal = user;

                // Extract the role claims
                RoleClaims = user.Claims.Where(c => c.Type == ClaimTypes.Role).Select(c => c.Value);

                // User name
                Name = user.Identity.Name;

                // Extract the given name(s); if null or empty, then set an initial value
                string gn = user.Claims.SingleOrDefault(c => c.Type == ClaimTypes.GivenName).Value;
                if (string.IsNullOrEmpty(gn)) { gn = "(empty given name)"; }
                GivenName = gn;

                // Extract the surname; if null or empty, then set an initial value
                string sn = user.Claims.SingleOrDefault(c => c.Type == ClaimTypes.Surname).Value;
                if (string.IsNullOrEmpty(sn)) { sn = "(empty surname)"; }
                Surname = sn;

                IsAuthenticated = true;
                // You can change the string value in your app to match your app domain logic
                IsAdmin = user.HasClaim(ClaimTypes.Role, "Admin") ? true : false;
            }
            else
            {
                RoleClaims = new List<string>();
                Name = "anonymous";
                GivenName = "Unauthenticated";
                Surname = "Anonymous";
                IsAuthenticated = false;
                IsAdmin = false;
            }

            // Compose the nicely-formatted full names
            NamesFirstLast = $"{GivenName} {Surname}";
            NamesLastFirst = $"{Surname}, {GivenName}";
        }

        // Public properties
        public ClaimsPrincipal Principal { get; private set; }
        public IEnumerable<string> RoleClaims { get; private set; }

        public string Name { get; set; }

        public string GivenName { get; private set; }
        public string Surname { get; private set; }

        public string NamesFirstLast { get; private set; }
        public string NamesLastFirst { get; private set; }

        public bool IsAuthenticated { get; private set; }

        public bool IsAdmin { get; private set; }

        public bool HasRoleClaim(string value)
        {
            if (!IsAuthenticated) { return false; }
            return Principal.HasClaim(ClaimTypes.Role, value) ? true : false;
        }

        public bool HasClaim(string type, string value)
        {
            if (!IsAuthenticated) { return false; }
            return Principal.HasClaim(type, value) ? true : false;
        }
    }

}