using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_4.Models;

namespace Assignment_4.Controllers
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

            // If necessary, add more constructor code here...
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

        public IEnumerable<InvoiceBase> InvoiveGetAll()
        {
            return Mapper.Map<IEnumerable<Invoice>, IEnumerable<InvoiceBase>>(ds.Invoices.OrderByDescending(i => i.InvoiceId));
        }
        public InvoiceBase InvoiceGetOne(int id)
        {
            var i = ds.Invoices.Find(id);
            return (i == null) ? null : Mapper.Map<Invoice, InvoiceBase>(i);
        }
        public InvoiceWithDetail InvoiceGetByIdWithDetail(int id)
        {
            var o = ds.Invoices
                .Include("Customer.Employee")
                .Include("InvoiceLines")
                .Include("InvoiceLines.Track")
                .Include("InvoiceLines.Track.Album")
                .Include("InvoiceLines.Track.MediaType")
                .Include("InvoiceLines.Track.Album.Artist")
            .SingleOrDefault(i => i.InvoiceId == id);
            return (o == null) ? null : Mapper.Map<Invoice, InvoiceWithDetail>(o);
        }


    }
}