using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_5.Controllers
{
    public class AlbumsController : Controller
    {
        Manager m = new Manager();
        // GET: Albums
        public ActionResult Index()
        {
            return View(m.AlbumGetAll());
        }

        // GET: Albums/Details/5

        /**
         public ActionResult Details(int id)
         {
             return View();
         }
         

         // GET: Albums/Create
         public ActionResult Create()
         {
             return View();
         }

         // POST: Albums/Create
         [HttpPost]
         public ActionResult Create(FormCollection collection)
         {
             try
             {
                 // TODO: Add insert logic here

                 return RedirectToAction("Index");
             }
             catch
             {
                 return View();
             }
         }

         // GET: Albums/Edit/5
         public ActionResult Edit(int id)
         {
             return View();
         }

         // POST: Albums/Edit/5
         [HttpPost]
         public ActionResult Edit(int id, FormCollection collection)
         {
             try
             {
                 // TODO: Add update logic here

                 return RedirectToAction("Index");
             }
             catch
             {
                 return View();
             }
         }

         // GET: Albums/Delete/5
         public ActionResult Delete(int id)
         {
             return View();
         }

         // POST: Albums/Delete/5
         [HttpPost]
         public ActionResult Delete(int id, FormCollection collection)
         {
             try
             {
                 // TODO: Add delete logic here

                 return RedirectToAction("Index");
             }
             catch
             {
                 return View();
             }
         }
     */
    }
}
