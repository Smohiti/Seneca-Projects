using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_5.Models;

namespace Assignment_5.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // If necessary, add constructor code here
        }

        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()

        public IEnumerable<AlbumBase> AlbumGetAll()
        {
            return Mapper.Map<IEnumerable<Album>, IEnumerable<AlbumBase>>(ds.Albums.OrderBy(a => a.ArtistId).ThenBy(t => t.Title));
        }
        public AlbumBase AlbumGetById(int id)
        {
            var o = ds.Albums.Find(id);

            return (o == null) ? null : Mapper.Map<Album, AlbumBase>(o);

        }

        public IEnumerable<ArtistBase> ArtistGetAll()
        {
            return Mapper.Map<IEnumerable<Artist>, IEnumerable<ArtistBase>>(ds.Artists.OrderBy(a => a.Name));
        }

        public IEnumerable<MediaTypeBase> MediaTypeGetAll()
        {
            return Mapper.Map<IEnumerable<MediaType>, IEnumerable<MediaTypeBase>>(ds.MediaTypes.OrderBy(m => m.Name));
        }

        public MediaTypeBase MediaTypeGetById(int id)
        {
            var o = ds.MediaTypes.Find(id);

            return (o == null) ? null : Mapper.Map<MediaType, MediaTypeBase>(o);
        }

        public IEnumerable<TrackWithDetails> TrackGetAllWithDetail()
        {
            var o = ds.Tracks.Include("MediaType").Include("Album.Artist");
            return (o == null) ? null : Mapper.Map<IEnumerable<Track>, IEnumerable<TrackWithDetails>>(o);
        }

        public TrackWithDetails TrackGetByIDWithDetail(int id)
        {
            var o = ds.Tracks.Include("MediaType").Include("Album.Artist").OrderBy(a => a.Album.Title).ThenBy(t => t.Name).SingleOrDefault(i => i.TrackId == id);
            return (o == null) ? null : Mapper.Map<Track, TrackWithDetails>(o);
        }

        public TrackWithDetails TrackAdd(TrackAdd newItem)
        {
            var album = ds.Albums.Find(newItem.AlbumId);
            var mediaType = ds.MediaTypes.Find(newItem.MediaTypeId);

            if (album == null || mediaType == null)
            {
                return null;

            }
            else
            {
                var addedItem = ds.Tracks.Add(Mapper.Map<TrackAdd, Track>(newItem));
                addedItem.Album = album;
                addedItem.MediaType = mediaType;
                ds.SaveChanges();
                return (addedItem == null) ? null : Mapper.Map<Track, TrackWithDetails>(addedItem);
            }


        }


    }
}