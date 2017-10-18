using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_3.Models;

namespace Assignment_3.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        // AutoMapper instance
        public IMapper mapper;

        public Manager()
        {
            // If necessary, add more constructor code here...

            // Configure the AutoMapper components
            var config = new MapperConfiguration(cfg =>
            {
                // Define the mappings below, for example...
                // cfg.CreateMap<SourceType, DestinationType>();
                // cfg.CreateMap<Employee, EmployeeBase>();
                cfg.CreateMap<Models.Employee, Controllers.EmployeeBase>();
                cfg.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeEditContactInfoForm>();
                cfg.CreateMap<Controllers.EmployeeAdd, Models.Employee>();
                cfg.CreateMap<Models.Track, Controllers.TrackBase>();
            });

            mapper = config.CreateMapper();

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;

        }  // Add methods below
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

        public IEnumerable<EmployeeBase> EmployeeGetAll()
        {
            // The ds object is the data store
            // It has a collection for each entity it manages

            return mapper.Map<IEnumerable<Employee>, IEnumerable<EmployeeBase>>(ds.Employees);
        }

        // Get one customer by its identifier
        public EmployeeBase EmployeeGetById(int id)
        {
            // Attempt to fetch the object
            var o = ds.Employees.Find(id);

            // Return the result, or null if not found
            return (o == null) ? null : mapper.Map<Employee, EmployeeBase>(o);
        }

        // Add new Employee
        public EmployeeBase EmployeeAdd(EmployeeAdd newItem)
        {
            // Attempt to add the new item
            // Notice how we map the incoming data to the design model object
            var addedItem = ds.Employees.Add(mapper.Map<EmployeeAdd, Employee>(newItem));
            ds.SaveChanges();

            // If successful, return the added item, mapped to a view model object
            return (addedItem == null) ? null : mapper.Map<Employee, EmployeeBase>(addedItem);
        }

        // Attention 06 - Edit Employee, contact info
        public EmployeeBase EmployeeEditContactInfo(EmployeeEditContactInfo newItem)
        {
            // Attempt to fetch the object
            var o = ds.Employees.Find(newItem.EmployeeId);

            if (o == null)
            {
                // Problem - item was not found, so return
                return null;
            }
            else
            {
                // Update the object with the incoming values
                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();

                // Prepare and return the object
                return mapper.Map<Employee, EmployeeBase>(o);
            }
        }

        // Attention 07 - Delete Employee
        // Notice the return type, which works for us in learning (getting started) situations
        public bool EmployeeDelete(int id)
        {
            // Attempt to fetch the object to be deleted
            var itemToDelete = ds.Employees.Find(id);

            if (itemToDelete == null)
            {
                return false;
            }
            else
            {
                // Remove the object
                ds.Employees.Remove(itemToDelete);
                ds.SaveChanges();

                return true;
            }
        }

        public IEnumerable<TrackBase> TrackGetAll()
        {


            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks);
        }

        public IEnumerable<TrackBase> TrackGetAllPop()
        {

            var o = ds.Tracks;

            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.Where(f => f.GenreId == 9).OrderBy(g => g.Name));

        }

        public IEnumerable<TrackBase> TrackGetAllDeepPurple()
        {
            //var x = "Jon Lord";
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.Where(f => f.Composer.Contains("Jon Lord")).OrderBy(g => g.TrackId));
        }


        public IEnumerable<TrackBase> TrackGetAllTop100Longest()
        {
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.OrderByDescending(f => f.Milliseconds).Take(100));
        }




    }
}




