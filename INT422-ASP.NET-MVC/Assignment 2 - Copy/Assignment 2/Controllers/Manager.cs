using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_2.Models;

namespace Assignment_2.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        // AutoMapper instance
        public IMapper Mapper;

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

                // Attention 07 - Add a mapping from CustomerAdd to Customer
                // Handles incoming data from the browser user
                cfg.CreateMap<Controllers.EmployeeAdd, Models.Employee>();

            });

            Mapper = config.CreateMapper();

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
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

        // ############################################################
        // Employee
        // ############################################################

        // Attention 11 - Get all customers
        public IEnumerable<EmployeeBase> EmployeeGetAll()
        {
            // The ds object is the data store
            // It has a collection for each entity it manages

            return Mapper.Map<IEnumerable<Employee>, IEnumerable<EmployeeBase>>(ds.Employees);
        }

        // Attention 12 - Get one customer by its identifier
        public EmployeeBase EmployeeGetById(int id)
        {
            // Attempt to fetch the object
            var o = ds.Employees.Find(id);

            // Return the result, or null if not found
            return (o == null) ? null : Mapper.Map<Employee, EmployeeBase>(o);
        }

        // Attention 13 - Add new customer
        public EmployeeBase EmployeeAdd(EmployeeAdd newItem)
        {
            // Attempt to add the new item
            // Notice how we map the incoming data to the design model object
            var addedItem = ds.Employees.Add(Mapper.Map<EmployeeAdd, Employee>(newItem));
            ds.SaveChanges();

            // If successful, return the added item, mapped to a view model object
            return (addedItem == null) ? null : Mapper.Map<Employee, EmployeeBase>(addedItem);
        }
    }
}