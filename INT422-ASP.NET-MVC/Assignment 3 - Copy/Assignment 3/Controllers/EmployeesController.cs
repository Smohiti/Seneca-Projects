using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_3.Controllers
{
    public class EmployeesController : Controller
    {
        private Manager m = new Manager();
        // GET: Employee
        public ActionResult Index()
        {
            var c = m.EmployeeGetAll();
            return View(c);
        }

        // GET: Employee/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.EmployeeGetById(id.GetValueOrDefault());
            if (o == null)
            {
                return HttpNotFound();

            }
            else
            {
                return View(o);
            }

        }

        // GET: Employee/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Employee/Create
        [HttpPost]
        public ActionResult Create(EmployeeAdd newItem)
        {
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

        // GET: Employee/Edit/5
        public ActionResult Edit(int? id)
        {
            var o = m.EmployeeGetById(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Create and configure an "edit form"

                // Notice that o is a CustomerBase object
                // We must map it to a CustomerEditContactInfoForm object
                // Notice that the AutoMapper maps were defined in the Manager class
                var editForm = m.mapper.Map<EmployeeBase, EmployeeEditContactInfoForm>(o);

                return View(editForm);
            }
        }

        // POST: Employee/Edit/5
        [HttpPost]
        public ActionResult Edit(int? id, EmployeeEditContactInfo newItem)
        {
            if (!ModelState.IsValid)
            {
                // Our "version 1" approach is to display the "edit form" again
                return RedirectToAction("edit", new { id = newItem.EmployeeId });
            }

            if (id.GetValueOrDefault() != newItem.EmployeeId)
            {
                // This appears to be data tampering, so redirect the user away
                return RedirectToAction("index");
            }

            // Attempt to do the update
            var editedItem = m.EmployeeEditContactInfo(newItem);

            if (editedItem == null)
            {
                // There was a problem updating the object
                // Our "version 1" approach is to display the "edit form" again
                return RedirectToAction("edit", new { id = newItem.EmployeeId });
            }
            else
            {
                // Show the details view, which will have the updated data
                return RedirectToAction("details", new { id = newItem.EmployeeId });
            }
        }

        // GET: Customers/Delete/5
        // Attention 14 - Delete customer, show the confirmation HTML Form
        public ActionResult Delete(int? id)
        {
            var itemToDelete = m.EmployeeGetById(id.GetValueOrDefault());

            if (itemToDelete == null)
            {
                // Don't leak info about the delete attempt
                // Simply redirect
                return RedirectToAction("index");
            }
            else
            {
                return View(itemToDelete);
            }
        }


        // POST: Employee/Delete/5
        [HttpPost]
        public ActionResult Delete(int? id, EmployeeEditContactInfo newItem)
        {
            var result = m.EmployeeDelete(id.GetValueOrDefault());

            // "result" will be true or false
            // We probably won't do much with the result, because 
            // we don't want to leak info about the delete attempt

            // In the end, we should just redirect to the list view
            return RedirectToAction("index");
        }

    }
}

