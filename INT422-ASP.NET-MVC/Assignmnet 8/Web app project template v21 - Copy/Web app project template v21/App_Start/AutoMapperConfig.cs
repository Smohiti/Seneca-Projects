using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Web_app_project_template_v21
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                // TODO e.g. cfg.CreateMap< FROM, TO >();
                cfg.CreateMap<Models.RegisterViewModel, Models.RegisterViewModelForm>();

                cfg.CreateMap<Models.Album, Controllers.AlbumBase>();
                cfg.CreateMap<Models.Album, Controllers.AlbumWithDetail>();
                cfg.CreateMap<Controllers.AlbumAdd, Models.Album>();

                cfg.CreateMap<Models.Artist, Controllers.ArtistBase>();
                cfg.CreateMap<Models.Artist, Controllers.ArtistWithDetail>();
                cfg.CreateMap<Controllers.ArtistAdd, Models.Artist>();

                cfg.CreateMap<Models.Genre, Controllers.GenreBase>();

                cfg.CreateMap<Models.Track, Controllers.TrackBase>();
                cfg.CreateMap<Models.Track, Controllers.TrackWithDetail>();
                cfg.CreateMap<Controllers.TrackAdd, Models.Track>();
                cfg.CreateMap<Controllers.TrackBase, Controllers.TrackEditForm>();
                cfg.CreateMap<Controllers.TrackWithDetail, Controllers.TrackEditForm>();

            });
        }
    }
}