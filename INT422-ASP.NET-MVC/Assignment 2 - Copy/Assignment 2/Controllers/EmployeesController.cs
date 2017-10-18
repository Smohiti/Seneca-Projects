using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_2.Controllers
{
    public class EmployeesController : Controller
    {
        // Reference to a manager object
        private Manager m = new Manager();

        // GET: Employees
        public ActionResult Index()
        {
            // Fetch the collection
            var c = m.EmployeeGetAll();

            // Pass the collection to the view
            return View(c);
        }

        // GET: Employees/Details/5
        // Attention 18 - Get one employee by its identifier
        public ActionResult Details(int? id)
        {
            // Attempt to get the matching object
            var o = m.EmployeeGetById(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Pass the object to the view
                return View(o);
            }
        }

        // GET: Employees/Create
        // Attention 19 - The "add new" pattern always requires two methods
        // One handles "get" (show me the HTML Form)
        // The other handles the user input ("post")
        public ActionResult Create()
        {
            // Optionally, can create and send an object to the view
            return View();
        }

        // POST: Employees/Create
        [HttpPost]
        public ActionResult Create(EmployeeAdd newItem)
        {
            // Attention 20 - Notice the pattern for handling incoming data...
            // First, ensure that the incoming data is valid
            // Next, attempt to process the incoming data (add employee etc.)
            // Finally, if successful, redirect to another view
            // This is known as the PRG pattern - Post, Redirect, Get

            // Validate the input
            if (!ModelState.IsValid)
            {
                // Uh oh, problem with the data, show the form again, with the data
                return View(newItem);
            }

            // Process the input
            var addedItem = m.EmployeeAdd(newItem);

            if (addedItem == null)
            {
                // Uh oh, some problem adding, show the empty form again
                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.EmployeeId });
            }
        }
    }
}