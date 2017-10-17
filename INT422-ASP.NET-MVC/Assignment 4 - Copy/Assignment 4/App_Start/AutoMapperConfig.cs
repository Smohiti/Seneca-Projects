using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment_4
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                // TODO e.g. cfg.CreateMap< FROM , TO >();
                cfg.CreateMap<Models.Invoice, Controllers.InvoiceBase>();
                cfg.CreateMap<Models.Invoice, Controllers.InvoiceWithDetail>();
                cfg.CreateMap<Models.InvoiceLine, Controllers.InvoiceLineBase>();
                cfg.CreateMap<Models.InvoiceLine, Controllers.InvoiceLineWithDetail>();

            });
        }
    }
}