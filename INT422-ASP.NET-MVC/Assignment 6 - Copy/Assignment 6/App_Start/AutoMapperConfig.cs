using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment_6
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                // TODO e.g. cfg.CreateMap< FROM , TO >();
                cfg.CreateMap<Models.Playlist, Controllers.PlaylistBase>();
                cfg.CreateMap<Models.Playlist, Controllers.PlaylistWithTracks>();
                cfg.CreateMap<Controllers.PlaylistBase, Controllers.PlaylistEditTracksForm>();
                cfg.CreateMap<Models.Track, Controllers.TrackBase>();

            });
        }
    }
}