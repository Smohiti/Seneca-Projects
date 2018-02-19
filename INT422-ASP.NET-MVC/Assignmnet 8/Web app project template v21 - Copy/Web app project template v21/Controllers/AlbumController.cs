using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class AlbumController : Controller
    {
        Manager m = new Manager();

        [AllowAnonymous]
        // GET: Album
        public ActionResult Index()
        {
            return View(m.AlbumGetAll());
        }

        [Authorize(Roles = "Clerk")]
        [Route("album/{id}/addtrack")]
        // GET: Track/Create
        public ActionResult AddTrack()
        {
            var form = new TrackAddForm();
            form.GenreList = new SelectList(m.GenreGetAll(), "Id", "Name");

            return View(form);
        }

        [Authorize(Roles = "Clerk")]
        [Route("album/{id}/addtrack")]
        [HttpPost]
        public ActionResult AddTrack(TrackAdd newItem)
        {
            newItem.Clerk = HttpContext.User.Identity.Name;

            // Validate Input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process Input
            var addedItem = m.TrackAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("../Track/details", new { id = addedItem.Id });
            }
        }

        // GET: Album/Details/5
        public ActionResult Details(int? id)
        {

            var o = m.AlbumGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }
        //Edit and Remove is not necessary
    }
}
