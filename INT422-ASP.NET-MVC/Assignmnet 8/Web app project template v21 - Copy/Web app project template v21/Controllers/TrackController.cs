using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class TrackController : Controller
    {
        Manager m = new Manager();

        [AllowAnonymous]
        // GET: Track
        public ActionResult Index()
        {
            return View(m.TrackGetAll());
        }

        // GET: Track/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.TrackGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        // GET: Track/Edit/5
        [Authorize(Roles = "Coordinator")]
        public ActionResult Edit(int? id)
        {
            var o = m.TrackGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {   //m.
                var form = Mapper.Map<TrackWithDetail, TrackEditForm>(o);

                return View(form);
            }
        }

        // POST: Track/Edit/5
        [HttpPost]
        [Authorize(Roles = "Coordinator")]
        public ActionResult Edit(int? id, TrackEdit newItem)
        {
            // Validate input
            if (!ModelState.IsValid)
            {

                return RedirectToAction("edit", new { id = newItem.Id });
            }

            if (id.GetValueOrDefault() != newItem.Id)
            {

                return RedirectToAction("index");
            }


            var editedItem = m.TrackEdit(newItem);

            if (editedItem == null)
            {

                return RedirectToAction("edit", new { id = newItem.Id });
            }
            else
            {

                return RedirectToAction("details", new { id = newItem.Id });
            }
        }

        [Authorize(Roles = "Coordinator")]
        // GET: Track/Delete/5
        public ActionResult Delete(int? id)
        {
            var itemToDelete = m.TrackGetByIdWithDetail(id.GetValueOrDefault());

            if (itemToDelete == null)
            {
                return RedirectToAction("index");
            }
            else
            {
                return View(itemToDelete);
            }
        }

        [Authorize(Roles = "Coordinator")]
        // POST: Track/Delete/5
        [HttpPost]
        public ActionResult Delete(int? id, FormCollection collection)
        {
            var result = m.TrackDelete(id.GetValueOrDefault());

            return RedirectToAction("index");
        }
    }
}
