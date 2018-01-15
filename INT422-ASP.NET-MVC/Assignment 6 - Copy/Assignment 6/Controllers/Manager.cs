using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_6.Models;

namespace Assignment_6.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        public IEnumerable<PlaylistBase> PlaylistGetAll()
        {
            return Mapper.Map<IEnumerable<Playlist>, IEnumerable<PlaylistBase>>(ds.Playlists.OrderBy(n => n.Name));
        }

        public PlaylistBase PlaylistGetById(int id)
        {
            var o = ds.Playlists.Find(id);

            return (o == null) ? null : Mapper.Map<Playlist, PlaylistBase>(o);
        }

        public IEnumerable<PlaylistWithTracks> PlaylistWithTracksGetAll()
        {
            return Mapper.Map<IEnumerable<Playlist>, IEnumerable<PlaylistWithTracks>>(ds.Playlists.Include("Tracks").OrderBy(n => n.Name));
        }

        public PlaylistWithTracks PlaylistWithTracksGetById(int id)
        {
            var o = ds.Playlists.Include("Tracks").SingleOrDefault(p => p.PlaylistId == id);

            return (o == null) ? null : Mapper.Map<Playlist, PlaylistWithTracks>(o);
        }

        public IEnumerable<TrackBase> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.OrderBy(n => n.Name));
        }

        public PlaylistWithTracks PlaylistEditTracks(PlaylistEditTracks newItem)
        {
            var o = ds.Playlists.Include("Tracks").SingleOrDefault(p => p.PlaylistId == newItem.PlaylistId);
            if (o == null)
            {
                return null;
            }
            else
            {
                o.Tracks.Clear();

                foreach (var item in newItem.TrackIds)
                {
                    var a = ds.Tracks.Find(item);
                    o.Tracks.Add(a);
                }

                ds.SaveChanges();
            }
            return Mapper.Map<Playlist, PlaylistWithTracks>(o);
        }
    }
}